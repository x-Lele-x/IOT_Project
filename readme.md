<p><strong>IT:</strong></p>
<h3 align="center">Simulazione monitoraggio di un operatore in un tunnel sotterraneo</h3>

<p><strong>Spiegazione Progetto:</strong></p>

<p>Nel problema presentato, vi è un tunnel sotterraneo attraverso il quale non è presente alcuna connessione alla rete internet, pertanto sono installati al suo interno dei dispositivi anchor per un eventuale scambio di dati. All'entrata e all'uscita è presente rispettivamente un gateway che si occupa di ricevere i dati dagli anchor e inoltrarli ad un server.</p>

<p>Il seguente progetto, dunque, prevede di monitorare in tempo reale un operatore che lavora all'interno del tunnel sotterraneo. Il progetto prevede l'uso di un dispositivo BLE Smartband che simula dei valori come battito cardiaco, temperatura e pressione sanguigna. Questo dispositivo si connetterà al dispositivo Anchor.</p>

<p>È necessario eseguire il codice di più dispositivi Anchor se si vuole verificare l'inoltro del messaggio ai vari nodi, tramite protocollo LoRa.
Il codice del Gateway si comporterà come un "bridge" che si occuperà di ricevere i messaggi dai nodi anchor ed inoltrarli al server.
Per vedere i dati dell'operatore su una dashboard, eseguire il login con le credenziali: id -> "PROVA" 
Password -> "Password". Una volta effettuato l'accesso alla pagina sulla rete locale "dashboard.php", sarà possibile vedere l'aggiornamento.</p>

<p><strong>Cosa installare:</strong></p>
<ul>
    <li>Installare XAMPP dal link -> <a href="https://www.apachefriends.org">https://www.apachefriends.org</a></li>
    <li>Aggiungere come variabile d'ambiente del sistema il path "C:\xampp\php"</li>
    <li>Scaricare l'editor Visual Studio Code al link -> <a href="https://code.visualstudio.com">https://code.visualstudio.com</a>. Al suo interno bisogna importare i codici per i dispositivi ESP.</li>
    <li>Tra le opzioni sulla sinistra, selezionare "Estensioni" ed installare PlatformIO IDE da <a href="https://platformio.org">platformio.org</a>.</li>
    <li>Nella pagina "PIO Home", importare i vari progetti per i dispositivi ESP32, selezionando come board TTGO LoRa32-OLED v2.1.6</li>
    <li>Verificare nel file "platformio.ini", la corretta installazione delle librerie in "lib_deps".</li>
</ul>

<p><strong>Come eseguire correttamente il progetto:</strong></p>
<ol>
    <li>Aprire il pannello di controllo di XAMPP e avviare il servizio MySQL e Apache, poi avviare il server usando l'indirizzo IP della rete a cui si è connessi.</li>
    <li>Aprire più finestre di Visual Studio con i vari codici dei dispositivi IoT.</li>
    <li>Collegare i dispositivi ESP32 e assegnare porte (es. COM4, COM5) diverse ai vari progetti.</li>
    <li>Flashare il codice del Gateway ed il codice "Smartband". Successivamente eseguire il codice di almeno 2 Anchor.</li>
    <li>Flashare il codice di almeno 2 Anchor.</li>
    <li>Controllare nel monitor seriale se Smartband e Anchor comunicano ed il Gateway riceve il messaggio.</li>
    <li>Visualizzare i risultati nella pagina Web all'apposito indirizzo IP.</li>
</ol>




<p><strong>ENG:</strong></p>

<h3 align="center">Simulation Monitoring of an Operator in an Underground Tunnel</h3>

<p><strong>Project Explanation:</strong></p>

<p>In the presented problem, there is an underground tunnel through which there is no internet connection. Therefore, anchor devices are installed inside it for potential data exchange. There is a gateway at the entrance and exit respectively, responsible for receiving data from the anchors and forwarding it to a server.</p>

<p>The following project aims to monitor a worker in real-time within the underground tunnel. The project involves the use of a BLE Smartband device that simulates values such as heart rate, temperature, and blood pressure. This device will connect to the Anchor device.</p>

<p>Multiple Anchor devices need to execute the code to verify the message forwarding to various nodes via the LoRa protocol.
The Gateway code will act as a bridge, receiving messages from the anchor nodes and forwarding them to the server.</p>

<p>To view the operator's data on a dashboard, log in with the credentials: id -> "PROVA" Password -> "Password". Once logged in to the page on the local network "dashboard.php," it will be possible to see the updates.</p>

<p><strong>What to Install:</strong></p>
<ul>
    <li>Install XAMPP from the link -> <a href="https://www.apachefriends.org">https://www.apachefriends.org</a></li>
    <li>Add the "C:\xampp\php" path as a system environment variable.</li>
    <li>Download Visual Studio Code editor from the link -> <a href="https://code.visualstudio.com">https://code.visualstudio.com</a>. Inside it, import the codes for ESP devices.</li>
    <li>Among the options on the left, select "Extensions" and install PlatformIO IDE from <a href="https://platformio.org">platformio.org</a>.</li>
    <li>On the "PIO Home" page, import the various projects for ESP32 devices, selecting TTGO LoRa32-OLED v2.1.6 as the board.</li>
    <li>Check in the "platformio.ini" file for the correct installation of libraries under "lib_deps."</li>
</ul>

<p><strong>How to Execute the Project Correctly:</strong></p>
<ol>
    <li>Open the XAMPP control panel and start the MySQL and Apache services, then start the server using the IP address of the connected network.</li>
    <li>Open multiple Visual Studio windows with the various IoT device codes.</li>
    <li>Connect the ESP32 devices and assign different ports (e.g., COM4, COM5) to the various projects.</li>
    <li>Flash the Gateway code and the "Smartband" code, then execute the code for at least 2 Anchors.</li>
    <li>Flash the code for at least 2 Anchors.</li>
    <li>Check in the serial monitor if the Smartband and Anchors communicate and the Gateway receives the message.</li>
    <li>View the results on the webpage at the specified IP address.</li>
</ol>
