#include <WiFi.h>
#include <ThingESP.h>

#define WIFI_SSID           "Wokwi-GUEST"
#define WIFI_PASSWORD       ""

ThingESP32 thing("starduststr", "ESP32", "Whatsapp Control");

#define led1 12
#define led2 14
#define led3 27

unsigned long previousMillis = 0;
const long INTERVAL = 6000;  

void setup()
{
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  thing.SetWiFi(WIFI_SSID, WIFI_PASSWORD);

  thing.initDevice();

}


String HandleResponse(String query)
{

  if (query == "led1 on") {
    digitalWrite(led1, 1);
    return "Done: LED Turned ON";
  }

  else if (query == "led1 off") {
    digitalWrite(led1, 0);
    return "Done: LED Turned OFF";
  }
  else if (query == "led2 on") {
    digitalWrite(led2, 1);
    return "Done: LED Turned ON";
  }
  else if (query == "led2 off") {
    digitalWrite(led2, 0);
    return "Done: LED Turned OFF";
  }
  else if (query == "led3 on") {
    digitalWrite(led3, 1);
    return "Done: LED Turned ON";
  }
  else if (query == "led3 off") {
    digitalWrite(led3, 0);
    return "Done: LED Turned OFF";
  }


  else return "Your query was invalid..\nlen on = lamp on \nlen off = lamp off \nled status = lamp status";

}


void loop()
{  
  thing.Handle();

}