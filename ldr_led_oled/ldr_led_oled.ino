/*---------------------KRENOVATOR---------------------
  LDR + LED + OLED Display

  Demonstrates the LDR diode to understand its functions
  and how to code it to control the LED as a real life
  lamp. The condition of LED wether it is ON or OFF will
  be displayed in OLED display.

  Get the code at github
  http://bit.ly/SmartLightAssistant

  by M.Zulsyahmi @krenovator
  October 2018
 */
 
/*the library for OLED display*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET LED_BUILTIN
Adafruit_SSD1306 display(OLED_RESET);

//initialize the pin used for LDR and LED
int ldrPin = A0;
int ldrVal = 0;

int ledG = 14;
int ledY = 12;
int ledR = 13;


void setup() {  
  //declare the function of each initialized
  pinMode(ldrPin,INPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledR, OUTPUT);
  
  display.clearDisplay();

  //burn command to be display on OLED
  Serial.begin(115200);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)

  // Clear the buffer/display
  display.clearDisplay();
}

void loop() {
  //command to read the analog pin for LDR sensor
  int ldrVal = analogRead(ldrPin);

  //the condition to be met for the sensor to trigger the LED and display in OLED
  if (ldrVal<= 125){
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, LOW);

    //display command and codes
    display.setTextColor(WHITE);
    display.setCursor(0, 21);
    display.setTextSize(1);
    display.print("Yellow LED ON");

    display.setTextColor(WHITE);
    display.setCursor(0, 45);
    display.setTextSize(1);
    display.print("Green LED ON");
    display.display();
  }

  else if (ldrVal>125 && ldrVal<=250){
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, LOW);

    //display command and codes
    display.setTextColor(WHITE);
    display.setCursor(0, 22);
    display.setTextSize(1);
    display.print("Yellow LED ON");
    display.display();
  }

  else if (ldrVal>250){
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, HIGH);

    //display command and codes
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.print("No LED ON");
    display.display();
  }
  delay(1000);
  display.clearDisplay();
}
