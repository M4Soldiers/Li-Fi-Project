#include <LiquidCrystal.h>
int sensorPin = 13; // select the input pin for LDR
int sensorValue = 0; // variable to store the value coming from the sensor
int threshold = 500; // adjust this threshold value based on your LDR and lighting conditions
unsigned long startTime = 0; // variable to store the start time
unsigned long elapsedTime = 0; // variable to store the elapsed time


LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const int buttonPin = 9;
const int buzzerPin = 8;

int buttonState = 0;
int lastButtonState = 0;
bool isMuted = false;
bool justPressed = false; // Flag to indicate if the button was just pressed
unsigned long buttonPressedTime = 0;


void setup() {
  Serial.begin(9600); // sets serial port for communication
  Serial.println("LDR Sensor");
  lcd.begin(16, 2);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  sensorValue = digitalRead(sensorPin); // read the value from the sensor
  buttonState = digitalRead(buttonPin);
  Serial.println(sensorValue);
  if (sensorValue==0) {
    // LDR is in a high state
    if (startTime == 0) {
      buttonState = 1;
      // Start counting time
      startTime = millis();
    }
  } else {
    // LDR is in a low state
    if (startTime > 0) {
      // Stop counting time
      elapsedTime = millis() - startTime;
      startTime = 0; // reset start time for the next cycle

      // Display different messages based on the elapsed time
      Serial.print(elapsedTime);
      if (elapsedTime >= 500 && elapsedTime < 1500) {
        Serial.println("Magnetic Sensor Detected");
      
      // if(justPressed != true)
        // {
            digitalWrite(buzzerPin, HIGH);
        // }
        // else
        // {
        //   justPressed = true;
        // }
        lcd.setCursor(0, 0);
        lcd.print("Magnetic sensor detected");
        delay(4000);
        lcd.clear();
        //digitalWrite(buzzerPin, LOW);
      } else if (elapsedTime >= 2500 && elapsedTime<3500) {
        Serial.println("Smoke Sensor Detected");
        // if(justPressed != true)
          // {
              digitalWrite(buzzerPin, HIGH);
          // }
        // else
        // {
        //  / justPressed = true;
        // }
        lcd.setCursor(0, 0);
        lcd.print("Smoke sensor detected");
        delay(4000);
        lcd.clear();
      } else if (elapsedTime>= 4500 && elapsedTime<5500) {
        Serial.println("Ultrasonic Sensor Detected");
        // if(justPressed != true)
          // {
              digitalWrite(buzzerPin, HIGH);
          // }
        // else
        // {
          // justPressed = true;
        // }
        lcd.setCursor(0, 0);
        lcd.print("ultrasonic detected");
        delay(4000);
        lcd.clear();

      }
      else{
        Serial.println("Normal");
      }
    }
  }

  if (buttonState == 0) {
    //   // Record when the button was pressed
    //   buttonPressedTime = millis();
    delay(5000);
    digitalWrite(buzzerPin, LOW);
    lcd.clear();
    isMuted = false;
    justPressed = true; // Set the flag to true
  }


  // delay(100);
}
