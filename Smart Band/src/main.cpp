#include <Wire.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <Arduino.h>
#include <EloquentTinyML.h>
#include "model.h"

#define TENSOR_SIZE color_model_tflite_len

Eloquent::TinyML::TfLite<3, 1, TENSOR_SIZE> ml;




BLEServer* pServer = NULL;
BLECharacteristic* pHeartCharacteristic = NULL;
BLECharacteristic* pTemperatureCharacteristic = NULL;
BLECharacteristic* pBloodPressureCharacteristic = NULL;
BLECharacteristic* pHighValuesCharacteristic = NULL;
BLEService *pService = NULL;

bool deviceConnected = false;
bool oldDeviceConnected = false; //la usiamo per tracciare lo stato del device precedente
uint8_t value = 0;

//definizioni UUID
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define TEMPERATURE_UUID    "2A6E"
#define BLOOD_PRESSURE_UUID "2A35"
#define HIGH_VALUES_UUID "4845e9f7-c0f2-475c-a2cb-2d2859ed6f39"

//gestione connessione - disconnessione
class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
	  Serial.println("Device connected");
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
      Serial.println("Device disconnected");
    }
};

void setup() {
  Serial.begin(115200);
  BLEDevice::init("Smartband ESP32");

  if (!ml.begin(color_model_tflite))
    {
        Serial.println("Failed to initialize model!");
        while (true){ }
    }

  // creazione BLE server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // creazione servizi BLE 
  pService = pServer->createService(SERVICE_UUID);

  // creazione Caratteristiche BLE per il cuore
  pHeartCharacteristic = pService->createCharacteristic(
                     CHARACTERISTIC_UUID,
                     BLECharacteristic::PROPERTY_READ   |
                     BLECharacteristic::PROPERTY_WRITE  |
                     BLECharacteristic::PROPERTY_NOTIFY |
                     BLECharacteristic::PROPERTY_INDICATE
                   );
  BLEDescriptor *pHeartDescriptor = new BLEDescriptor(BLEUUID((uint16_t)0x2901));
  pHeartDescriptor->setValue("Heart");
  pHeartCharacteristic->addDescriptor(pHeartDescriptor);
  // creazione Caratteristiche BLE per la temperatura
  pTemperatureCharacteristic = pService->createCharacteristic(
                     TEMPERATURE_UUID,
                     BLECharacteristic::PROPERTY_READ   |
                     BLECharacteristic::PROPERTY_WRITE  |
                     BLECharacteristic::PROPERTY_NOTIFY |
                     BLECharacteristic::PROPERTY_INDICATE
                   );
  BLEDescriptor *pTemperatureDescriptor = new BLEDescriptor(BLEUUID((uint16_t)0x2901));
  pTemperatureDescriptor->setValue("Temperature");
  pTemperatureCharacteristic->addDescriptor(pTemperatureDescriptor);
  //  creazione Caratteristiche BLE per la pressione sanguigna
  pBloodPressureCharacteristic = pService->createCharacteristic(
                     BLOOD_PRESSURE_UUID,
                     BLECharacteristic::PROPERTY_READ   |
                     BLECharacteristic::PROPERTY_WRITE  |
                     BLECharacteristic::PROPERTY_NOTIFY |
                     BLECharacteristic::PROPERTY_INDICATE
                   );
  BLEDescriptor *pPressureDescriptor = new BLEDescriptor(BLEUUID((uint16_t)0x2901));
  pPressureDescriptor->setValue("Pressure");
  pBloodPressureCharacteristic->addDescriptor(pPressureDescriptor);
  pHighValuesCharacteristic = pService->createCharacteristic(
                     HIGH_VALUES_UUID,
                     BLECharacteristic::PROPERTY_READ   |
                     BLECharacteristic::PROPERTY_WRITE  |
                     BLECharacteristic::PROPERTY_NOTIFY |
                     BLECharacteristic::PROPERTY_INDICATE
                   );
  BLEDescriptor *pHighValuesDescriptor = new BLEDescriptor(BLEUUID((uint16_t)0x2901));
  pHighValuesDescriptor->setValue("HighValues");
  pHighValuesCharacteristic->addDescriptor(pHighValuesDescriptor);
  
}

//ricordare di implementare una funzione che monitora quanto tempo la persona sta
//lì e ricordarle di uscire dopo la fine di un timer
bool stamale = 0;

float inputs[3];
float outputs[2] = {0,0};

void loop() {
  if(!deviceConnected){
    pService->start();

    pServer->getAdvertising()->start();
    Serial.println("Waiting a client connection to notify...");
  }
  if (deviceConnected) {
    //gestione cuore

    //sta male con >120 eventualmente con temperatura alta >38.0
    uint8_t heartRate = random(60, 161); // Generazione di un battito cardiaco casuale tra 60 e 140
    String heartRatestr = String(heartRate);
    pHeartCharacteristic->setValue(heartRatestr.c_str()); // assegno alla caratteristica il valore di heart rate
    pHeartCharacteristic->notify(); // notifica il device connesso del cambio di valore
    //ricordarsi di implementare un if per testare con frequenze cardiache alte
    Serial.printf("HeartRate: %d \n", heartRate);
    inputs[0] = heartRate;


    //gestione temperatura
    float bodyTemperature = random(360, 400) / 10.0; // genera random temperature tra 36.0 e 37.0
    uint8_t temp[4];
    String temperatureStr = String(bodyTemperature, 1); // 1 cifra decimale
    // temp[0] = 0xFF; // flags
    // temp[1] = (int)(bodyTemperature * 10); // per misurare la temp in gradi Celsius
    // temp[2] = temp[1] >> 8; //viene impostato con gli 8 bit più significativi di temp[1]
    // temp[3] = 0x01; // tipo di dato per rappresentare la temperatura
    pTemperatureCharacteristic->setValue(temperatureStr.c_str()); // setta il valore della caratteristica
    pTemperatureCharacteristic->notify();
    //ricordare di fare un if dove si testa la notify per una temperatura sotto i 35.0
    Serial.printf("BodyTemperature: %.1f \n", bodyTemperature);
    inputs[1] = bodyTemperature;

    // problematico se c'è un battito >120 con pressione <55 e >160
    uint8_t bloodPressure = random(80, 160); 
    String bloodPressurestr = String(bloodPressure);
    pBloodPressureCharacteristic->setValue(bloodPressurestr.c_str());
    pBloodPressureCharacteristic->notify();
    Serial.printf("BloodPressure: %d \n", bloodPressure);
    inputs[2] = bloodPressure;
    
    ml.predict(inputs,outputs);
    Serial.println(outputs[0]);
    Serial.println(outputs[1]);


    if(outputs[0] > 0.8){
      stamale = 1;
    }
    else{
      stamale = 0;
    }

    pHighValuesCharacteristic->setValue(std::to_string(stamale));
    pHighValuesCharacteristic->notify();


    Serial.printf("Sta male: %d \n", stamale);
    delay(10000); // ricordarsi di cambiarlo per i vari test
  }

  // da qui viene gestita la transizione da un device all'altro
  if (!deviceConnected && oldDeviceConnected) {
    delay(500); // per la preparazione della stack bluetooth
    pServer->startAdvertising(); // server di nuovo visibile e via di nuovo
    Serial.println("start advertising");
    oldDeviceConnected = deviceConnected;
  }
  
  //prende il nuovo device che non era ancora connesso 
  if (deviceConnected && !oldDeviceConnected) {
    oldDeviceConnected = deviceConnected;
  }
}
