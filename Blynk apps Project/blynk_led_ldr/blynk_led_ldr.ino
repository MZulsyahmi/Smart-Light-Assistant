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

SimpleTimer timer;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "The Auth Token";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Your SSID";
char pass[] = "Your Password";

int ldrVal = 0;

void setup() {
  // Debug console
  Serial.begin(9600);

  //to check the requirement is correct
  Blynk.begin(auth, ssid, pass);

  timer.setInterval(1000L, sendSensor);
}

void loop() {
  //run the code to be pushed to Blynk apps
  Blynk.run();
}

//subroutine of the project to be sent to the Blynk apps
void sendSensor() {
  //to initialize the pin used to be detected in Blynk apps
  int ledG = 14;
  int ledY = 12;
  int ledR = 13;

  int ldrPin = A0;
  int ldrVal = analogRead(ldrPin);    //the code to read the LDR sensor value

  //condition to be met. will resend to the apps if one is fails
  if(isnan(ledG) || isnan(ledY) || isnan(ledR) || isnan(ldrVal)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
}
