#include <PubSubClient.h>
#include <SoftwareSerial.h>
#include <WiFi.h>

/*----wifi stuff----*/
#define ssid      " "          //wifi name
#define password  " "       //wifi password
/*----thingspeak stuff----*/
#define broker     "mqtt.thingspeak.com"
#define port       1883              //MQTT port
SoftwareSerial esp(9, 10);         //RX, TX
char mqttUserName[] = "TSArduinoMQTTDemo";  // Can be any name.
char mqttPass[] = "384PKBRH5DHOMTQF";  // Change this your MQTT API Key from Account > MyProfile.
char writeAPIKey[] = "UOOY646AWMVO4U1L";    // Change to your channel Write API Key.



void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}
WiFiClient espClient;
PubSubClient client(broker, port, callback, espClient);
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
void send_command(String cmd) {
  Serial.println(cmd);
  //cmd += "\r\n";
  //  esp.print(Serial.read());
  esp.println(cmd);
  if (esp.available()) {
    delay(100);
    Serial.write(esp.read());
  }
  //   delay(10);
}
boolean connect_wifi() {
  unsigned int status = 0;
  while(status!=1){
  esp.println("AT+CWMODE=1");
  String cmd = "AT+CWJAP=\"";
  cmd += ssid;
  cmd += "\",\"";
  cmd += password;
  cmd += "\"";
  send_command(cmd);
  delay(5000);
  if (esp.find("OK")) {
    Serial.println("Connected");
    status = 1;
    return true;
  }
  else
  {
    Serial.println("Could not connect");
    status = 0;
    return false;
  }
}
}
