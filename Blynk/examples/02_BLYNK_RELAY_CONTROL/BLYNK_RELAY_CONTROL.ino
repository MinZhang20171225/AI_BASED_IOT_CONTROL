 /*************************************************************
 Author : Prasad Raspaile
 Website : www.prasadraspaile.com
 Project level : Intermidiate
 *************************************************************
  
  AIM : This example shows how you can control the relay from the Blynk App
  
  Hardware Requirements :
  1. NodeMCU 1.0 Board - 1no.
  2. MicroUSB Cable for Power Supply and Programming
  3. A full size breadboard
  4. LED as an indicator
  5. 5V Dual Channel Relay Board
  6. Connecting wires
  7. Tools - (if required) - Nose plier, wire-stripper, 

  App project setup:
  using Blynk Virtual Variables :
  LED is attched to V0
  Relay 1 is attached to V1
  Relay 2 is attached to V2

*************************************************************/

/* Comment this out to disable prints and save space */
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "PASTE YOUR BLYNK TOKEN HERE";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YOUR WIFI-SSID";
char pass[] = "WIFI PASSWORD";

// This function writes the value of Virtual variable V0 to the Digital pin D0 of NodeMCU
BLYNK_WRITE(V0)
{
  digitalWrite(D0,param.asInt());
}
// This function writes the value of Virtual variable V1 to the Digital pin D1 of NodeMCU
BLYNK_WRITE(V1)
{
  digitalWrite(D1,param.asInt());
}
// This function writes the value of Virtual variable V2 to the Digital pin D2 of NodeMCU
BLYNK_WRITE(V2)
{
  digitalWrite(D2,param.asInt());
}

void setup()
{
  //Declaring D0, D1 & D2 as OUTPUT
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);

// Keeping all the pins at LOW
  digitalWrite(D0,LOW);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

}

void loop()
{
  Blynk.run();
}

