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
