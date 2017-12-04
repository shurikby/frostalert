void loop() {
unsigned long now = millis();
  
//setup mode
if ( setup_mode == 1 ) {
  WiFiManager wifiManager;
  wifiManager.setConfigPortalTimeout(300);
  if (!wifiManager.startConfigPortal("IoT")) {
      Serial.println("failed to connect and hit timeout");
      delay(3000);
      //reset and try again, or maybe put it to deep sleep
      ESP.reset();
      delay(5000);
  }
  setup_mode = 0;
  Serial.print("Ip adress: ");
  Serial.println(WiFi.localIP());
}
if(now - send_time >= send_interval or send_time == 0){
  sensors.requestTemperatures();
  Serial.print("Temperature:");
  Serial.println(sensors.getTempCByIndex(0)); 
  Serial.print("Light level:");
  Serial.println(analogRead(LIGHT_PIN));
  
  Serial.println("Sending data...");  
  request = "http://frostalert.iot.shurik.by/get.php?sn="+ String(DEVICE) + "&t=" + String(sensors.getTempCByIndex(0)) + "&l=" + String(analogRead(LIGHT_PIN));
  http.begin(request);
  int httpCode = http.GET();
  http.end();
  send_time = now;
}
}
