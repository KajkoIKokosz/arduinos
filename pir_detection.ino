int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;
int sensor_pin = 2;
int state = LOW;
int val = 0;

void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(sensor_pin, INPUT);
  Serial.begin(9600);
}


void loop(){
  val = digitalRead(sensor_pin);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(red_light_pin, HIGH);
    digitalWrite(green_light_pin, HIGH);
    digitalWrite(blue_light_pin, HIGH);   // turn LED ON
    delay(10000);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {    
    digitalWrite(red_light_pin, LOW);
    digitalWrite(green_light_pin, LOW);
    digitalWrite(blue_light_pin, LOW); // turn LED OFF
    delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}

