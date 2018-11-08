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

//initialize the pin used for LDR
int ldrPin = A0;
int sensorVal = 0;

void setup() {  
  //declare the function of each initialized
  pinMode(ldrPin,INPUT);
  
  //burn command to be display on serial monitor
  Serial.begin(9600);
}

void loop() {
  //command to read the analog pin for LDR sensor
  int sensorVal = analogRead(ldrPin);

  //the code to be displayed in serial monitor
  Serial.print("Analog Read= ");
  Serial.println(sensorVal);
  delay(500);
}
