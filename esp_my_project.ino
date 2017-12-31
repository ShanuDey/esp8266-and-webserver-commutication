#include<ESP8266WiFi.h>

char *ssid=" Enter ssid";
char *pass=" Enter passward";
char *host=" enter host name";

int led=D0;

void setup() {
Serial.begin(115200);
delay(10);
Serial.println();
Serial.println();
WiFi.begin(ssid,pass);
Serial.print("Connecting to ");
Serial.print(ssid);
while(WiFi.status()!=WL_CONNECTED)
{
  Serial.print(".");
  delay(500);
}
Serial.println();
Serial.println("Connection Successfull");
/*
Serial.print("Time taken ");
Serial.print(millis()/1000);
Serial.println(" second");
*/
Serial.print(" Local IP : ");
Serial.println(WiFi.localIP());

pinMode(A0,INPUT);
pinMode(led,OUTPUT);
}

void loop() {
 // delay(5000);
  Serial.print("connecting to ");
  Serial.println(host);
WiFiClient client;
const char port=80;
if(!client.connect(host,port))
{
  Serial.println("Connection Failed");
  return;
}
/*
else
{
Serial.print("Connected and the time taken ");
Serial.println(millis()/1000);
//delay(1000);
}
*/
String url="/esp.php?pot=";
url+=analogRead(A0);
//Serial.println(url);
//Serial.print("Trying ");
client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
               
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }


while(client.available()==0)
{
  delay(10);
  Serial.print(".");
}
//Serial.println("Got it");
while(client.available())
{
  String line = client.readStringUntil('\r');  
  Serial.print(line);
  Serial.println();
  String data;
  for(int i=4;i<9;i++)
  {
    data+=line[i];
  }
  //Serial.println(data);
  int value=data.toInt();
  Serial.println(value);
  //value=value*255/1023;
  analogWrite(led,value);
  Serial.println(value);
  delay(5000);
}

//delay(5000);
}
