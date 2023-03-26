 
int m11 = 2; // motor 1 direction
int m12 = 3; // motor 1 speed 

int m21 = 4; // motor 2 direction
int m22 = 5; // motor 2 speed

int state = 0;

void setup() {
  
 // sets the pins as outputs:
    pinMode(m11, OUTPUT);
    pinMode(m12, OUTPUT);
    
    pinMode(m21, OUTPUT);
    pinMode(m22, OUTPUT);
   
    
    Serial.begin(115200); // Default communication rate of the Bluetooth module
}
void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
 state = Serial.read(); // Reads the data from the serial port
  Serial.println(state);
 }
 
 int motor_speed = 255; // this set the motors' speed which varies between (0-255) 
 
 if (state == 'F') {   
  
 digitalWrite(m11, HIGH);   // HIGH moves the motor forward while LOW moves it backward 
 analogWrite(m12, motor_speed);

 digitalWrite(m21, HIGH);
 analogWrite(m22, motor_speed);
 
 Serial.println("MOVE FORWARD"); 
 state = 0;
 }
 else if (state == 'B') { 
 digitalWrite(m11,LOW ); 
 analogWrite(m12, motor_speed);

 digitalWrite(m21, LOW);
 analogWrite(m22, motor_speed);
 
 Serial.println("MOVE BACKWARD"); 
 state = 0;
 } 
 else if (state == 'R') { 
 digitalWrite(m11, HIGH ); 
 analogWrite(m12, motor_speed);
 
 digitalWrite(m21, LOW);
 analogWrite(m22, motor_speed);
 
 Serial.println("TURN RIGHT"); 
 state = 0;
 } 
  else if (state == 'L') { 
 digitalWrite(m11, LOW ); 
 analogWrite(m12, motor_speed);

 digitalWrite(m21, HIGH);
 analogWrite(m22, motor_speed);
 
 Serial.println("TURN LEFT"); 
 state = 0;
 } 
  else if (state == 'S') { 
 digitalWrite(m11,LOW ); 
 analogWrite(m12, 0);

 digitalWrite(m21, LOW);
 analogWrite(m22, 0);
 
 Serial.println("STOP"); 
 state = 0;
 } 
}