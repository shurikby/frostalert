void setup() {
  Serial.begin(115200);
  Serial.println("\nSetting up...");
  
  pinMode(BTN_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  digitalWrite(LED_PIN, HIGH);
  
  attachInterrupt(digitalPinToInterrupt(BTN_PIN), config, RISING);
  
  //connect to network
  Serial.print("\nConnecting to AP...");
  while (WiFi.status() != WL_CONNECTED & setup_mode != 1) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Ip adress: ");
  Serial.println(WiFi.localIP());

  sensors.begin();
  Serial.println("\n\n");
  }
