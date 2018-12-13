/*---------------------KRENOVATOR---------------------
  Blynk apps + LED

  Demonstrates the Blynk apps. How to code the Blynk using
  nodeMCU to control the LED as part of Internet of Things.
  The user needs to install the Blynk apps first in order
  to demonstrate this codes. The user can control the LED
  with the Blynk apps.

  Get the code at github
  http://bit.ly/SmartLightAssistant

  by M.Zulsyahmi @krenovator
  October 2018
 */

/*the library for Blynk apps*/
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int ledPinG = 14;   //D5
int ledPinY = 12;   //D6
int ledPinR = 13;   //D7

WidgetLED ledG(V1);
WidgetLED ledY(V2);
WidgetLED ledR(V3);

int ldrPin = A0;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Your Auth";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Your SSID";
char pass[] = "SSID Password";

int ldrVal = 0;

void setup() {
  // Debug console
  Serial.begin(9600);

  //to check the requirement is correct
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  int ldrVal = analogRead(ldrPin);    //the code to read the LDR sensor value
  Blynk.virtualWrite(V4, ldrVal);

  //the condition to be met for the sensor to trigger the LED and display in serial monitor
  if (ldrVal<= 125){
    digitalWrite(ledPinG, HIGH);
    digitalWrite(ledPinY, HIGH);
    digitalWrite(ledPinR, LOW);

    ledG.on();
    ledY.on();
    ledR.off();
  }

  else if (ldrVal>125 && ldrVal<=250){
    digitalWrite(ledPinG, LOW);
    digitalWrite(ledPinY, HIGH);
    digitalWrite(ledPinR, LOW);
    
    ledG.off();
    ledY.on();
    ledR.off();
  }

  else if (ldrVal>250){
    digitalWrite(ledPinG, LOW);
    digitalWrite(ledPinY, LOW);
    digitalWrite(ledPinR, HIGH);

    ledG.off();
    ledY.off();
    ledR.on();
  }
  delay(500);
 //run the code to be pushed to Blynk apps
  Blynk.run();
}
