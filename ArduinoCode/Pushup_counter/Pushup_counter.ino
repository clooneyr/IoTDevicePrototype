
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
boolean trigUp = false;
boolean trigDown = false;
float counterPushUp = 0;
float currentAmount = 0;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  delay(500);
  Serial.println("Pushup Counter"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  if (distance  > 15 && distance <=40){
    trigUp = true;
  }
  else if (distance < 10){
    trigDown = true;
  }
  else if (distance > 45) {
  }

  if (trigUp==true && trigDown==true){
    counterPushUp=counterPushUp+0.5;
    trigUp=false;
    delay(500);
    trigDown=false;
  }
  
  // Displays the distance on the Serial Monitor
  //Serial.print("Distance: ");
  //Serial.print(distance);
  //Serial.println(" cm");
  //Serial.print("Number of pushups");
 
  if(counterPushUp > currentAmount){
    Serial.print(counterPushUp);
    Serial.print(",");
  }
  //Serial.print(counterPushUp);
  //Serial.print(",");
   currentAmount = counterPushUp;
  
  delay(500);
  
}
