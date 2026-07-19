int smokePin = A2;
int tempPin = A1;
int greenLED = 13;
int redLED = 12;
int buttonPin = 8;
int piezoPin = 11;
int degreesCelsius = 0;

void setup(){
  pinMode(piezoPin, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop(){
  int tempValue = analogRead(tempPin);
  int smokeValue = analogRead(smokePin);
  Serial.print("Temp = ");
  Serial.println(tempValue);
  //degreesC = ((sensorValue * 0.00488) - 0.5) * 100;
  //Serial.print("degrees C = ");
  //Serial.println(degreesC);
  Serial.print("Smoke = ");
  Serial.println(smokeValue);
  delay(1000);

  if (tempValue > 205 && smokeValue > 80){
    digitalWrite(greenLED, LOW);
    while (true){
      Serial.print("Temp = ");
      Serial.println(tempValue);
      //degreesC = ((sensorValue * 0.00488) - 0.5) * 100;
      //Serial.print("degrees C = ");
      //Serial.println(degreesC);
      Serial.print("Smoke = ");
      Serial.println(smokeValue);
      if (digitalRead(buttonPin) == HIGH &&(analogRead(tempPin) <= 200 || analogRead(smokePin) <= 80)) break;
      digitalWrite(redLED, HIGH);
      tone(piezoPin, 2000, 500);
      delay(500);
      digitalWrite(redLED, LOW);
      delay(250);
    }
  	
  } else {
   	digitalWrite(greenLED, HIGH); 
  }
}
