IT: 

		Simulazione monitoraggio di un operatore in un tunnel sotterraneo

Spiegazione Progetto:

Nel problema presentato, vi è un tunnel sotterraneo attraverso il quale non è presente alcuna connessione alla rete internet, pertanto sono installati al suo interno dei dispositivi anchor per un eventuale scambio di dati. All'entrata e all'uscita è presente rispettivamente un gateway che si occupa di ricevere i dati dagli anchor e inoltrarli ad un server.

Il seguente progetto, dunque, prevede di monitorare in tempo reale un operatore che lavora all'interno del tunnel sotterraneo. Il progetto prevede l'uso di un dispositivo BLE Smartband che simula dei valori come battito cardiaco, temperatura e pressione sanguigna. Questo dispostivo si connetterà al dispositivo Anchor.
E' necessario eseguire il codice di più dispositivi Anchor se si vuole verificare l'inoltro del messaggio ai vari nodi, tramite procollo LoRa.
Il codice del Gateway si comporterà come un "bridge" che si occuperà di ricevere i messaggi dai nodi anchor ed inoltrarli al server.
Per vedere i dati dell'operatore su una dashboard, eseguire il login con le credenziali: id -> "PROVA" 
Password -> "Password"
Una volta effettuato l'accesso alla pagina sulla rete locale "dashboard.php", sarà possibile vedere l'aggiornamento 


Cosa installare:
-Installare XAMPP dal link-> https://www.apachefriends.org
-Aggiungere come variabile d'ambiente del sistema il path "C:\xampp\php"
-Scaricare l'editor Visual Studio Code al link -> https://code.visualstudio.com
Al suo interno bisogna importare i codici per i dispositivi ESP.
-Tra le opzioni sulla sinistra, selezionare "Estensioni" ed installare PlatformIO IDE da platformio.org.
-Nella pagina "PIO Home", importare i vari progetti per i dispositivi ESP32, selezionando come board TTGO LoRa32-OLED v2.1.6
-Verificare nel file "platformio.ini", la corretta installazione delle librerie in "lib_deps".


Come eseguire correttamente il progetto:

Step 1: aprire il pannello di controllo di xampp per e avviare il servizio MYSQL e Apache, dopo di che avviare il server usando l'indirizzo ip della rete a cui si è connessi.
Step 2: aprire più finestre di visual studio con i vari codici dei dispositivi iot.
Step 3: collegare i dispostivi ESP32 e assegnare porte (es. COM4, COM5) diverse ai vari progetti.
Step 4: flashare il codice del Gateway ed il codice "Smarband". successivamente eseguire il codice di almeno 2 Anchor.
Step 5: flashare il codice di almeno 2 Anchor.
Step 6: controllare nel monitor seriale se Smartband e Anchor comunicano ed il Gateway riceve il messaggio.
Step 7: visualizzare i risultati nella pagina Web all'apposito indirizzo ip.


EN:

		Simulation monitoring of an operator in an underground tunnel


Project Explanation:

In the presented problem, there is an underground tunnel through which there is no internet connection. Therefore, anchor devices are installed inside it for potential data exchange. There is a gateway at the entrance and exit respectively, responsible for receiving data from the anchors and forwarding it to a server.

The following project aims to monitor a worker in real-time within the underground tunnel. The project involves the use of a BLE Smartband device that simulates values such as heart rate, temperature, and blood pressure. This device will connect to the Anchor device.
Multiple Anchor devices need to execute the code to verify the message forwarding to various nodes via the LoRa protocol.
The Gateway code will act as a bridge, receiving messages from the anchor nodes and forwarding them to the server.
To view the operator's data on a dashboard, log in with the credentials: id -> "PROVA"
Password -> "Password"
Once logged in to the page on the local network "dashboard.php," it will be possible to see the updates.


What to Install:

-Install XAMPP from the link -> https://www.apachefriends.org
-Add the "C:\xampp\php" path as a system environment variable.
-Download Visual Studio Code editor from the link -> https://code.visualstudio.com
Inside it, import the codes for ESP devices.
-Among the options on the left, select "Extensions" and install PlatformIO IDE from platformio.org.
-On the "PIO Home" page, import the various projects for ESP32 devices, selecting TTGO LoRa32-OLED v2.1.6 as the board.
-Check in the "platformio.ini" file for the correct installation of libraries under "lib_deps."


How to Execute the Project Correctly:

Step 1: Open the XAMPP control panel and start the MYSQL and Apache services, then start the server using the IP address of the connected network.
Step 2: Open multiple Visual Studio windows with the various IoT device codes.
Step 3: Connect the ESP32 devices and assign different ports (e.g., COM4, COM5) to the various projects.
Step 4: Flash the Gateway code and the "Smartband" code, then execute the code for at least 2 Anchors.
Step 5: Flash the code for at least 2 Anchors.
Step 6: Check in the serial monitor if the Smartband and Anchors communicate and the Gateway receives the message.
Step 7: View the results on the webpage at the specified IP address.
