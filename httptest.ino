#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "Your SSID";
const char* password = "Your Password";
 
void setup () {
 
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 Serial.println("Connecting : ");
  while (WiFi.status() != WL_CONNECTED) {

    delay(1000);
    Serial.print(".");
 
  }
  Serial.println("Connection successful");
 pinMode(A0,INPUT);
 pinMode(D0,OUTPUT);
}
 
void loop() {
 
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    HTTPClient http;  //Declare an object of class HTTPClient
    String link="http://shanu.comli.com/esp.php?pot=";
    link+=analogRead(A0);
    Serial.println(link);
    http.begin(link);  //Specify request destination
    int httpCode = http.GET();                                                                  //Send the request
    Serial.println(httpCode);
    if (httpCode > 0) { //Check the returning code
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);  //Print the response payload
     // Serial.println(payload.length());
     analogWrite(D0,payload.toInt());
    }
    http.end();//Close connection
     
  }
  delay(1000);    //Send a request every 30 seconds
}
