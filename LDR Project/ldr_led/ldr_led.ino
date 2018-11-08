/*---------------------KRENOVATOR---------------------
  LDR + LED + OLED Display

  Demonstrates the LDR diode to understand its functions
  and how to code it to control the LED as a real life
  lamp. The condition of LED wether it is ON or OFF will
  be displayed in serial monitor

  Get the code at github
  http://bit.ly/SmartLightAssistant

  by M.Zulsyahmi @krenovator
  October 2018
 */
 
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

  //burn command to be display on serial monitor
  Serial.begin(9600);
}

void loop() {
  //command to read the analog pin for LDR sensor
  int ldrVal = analogRead(ldrPin);

  Serial.print("Analog Read= ");
  Serial.print(ldrVal);         //recall the ldr value

  //the condition to be met for the sensor to trigger the LED and display in serial monitor
  if (ldrVal<= 125){
    digitalWrite(ledG, HIGH);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, LOW);

    Serial.print("  Red LED OFF");
    Serial.print("  Yellow LED ON");
    Serial.println("  Green LED ON");
  }

  else if (ldrVal>125 && ldrVal<=250){
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, LOW);

    Serial.print("  Red LED OFF");
    Serial.print("  Yellow LED ON");
    Serial.println("  Green LED OFF");
  }

  else if (ldrVal>250){
    digitalWrite(ledG, LOW);
    digitalWrite(ledY, LOW);
    digitalWrite(ledR, HIGH);

    Serial.print("  Red LED ON");
    Serial.print("  Yellow LED OFF");
    Serial.println("  Green LED OFF");
  }
  delay(500);
}
