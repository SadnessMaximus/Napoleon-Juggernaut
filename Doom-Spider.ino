// Input pins:
const int rside = A0; // right side sensor input
const int rfront = A1; // right front sensor input
const int lfront = A2; // left front sensor input
const int lside = A3; // left side sensor input
const int fourwayswitch = A6; // input from function switch
const int battery = A7; // input for battery measurement
const int Receive = 0; //Receive pin
const int Transmit = 1; //Transmit pin
const int m1encoder1 = 2; // motor 1 encoder 1 input interrupt pin
const int m1encoder2 = 4; // motor 1 encoder 2 input
const int m2encoder1 = 3; // motor 2 encoder 1 input interrupt pin
const int m2encoder2 = 5; // motor 2 encoder 2 input
// Output pins:
const int unused = 6; // 
const int lmotorDIR = 7; //Left motor dirn input 1
const int rmotorDIR = 8; //Right motor dirn input 3
const int lmotorPWM = 9; //Left motor PWN pin
const int rmotorPWM = 10; //Right motor PWN pin
const int sensorLED1 = A4; // 1st diagnostic LED on sensor board
const int sensorLED2 = A5; // 2nd diagnostic LED on sensor board
const int trigger1 = 11; // trigger for 2 front sensor LEDs
const int trigger2 = 12; // trigger for 2 side sensor LEDs
const int LED13 = 13; // ext LED Red
//Inputs
int volts = 0; //battery voltage 
int switchvalue = 0; // value back from 4 way switch
int rfrontsensoff = 0; // Right front sensor value
int lfrontsensoff = 0; // Left front sensor value
int rsidesensoff = 0; //Right side sensor value
int lsidesensoff = 0; //Left side sensor value
int rfrontsens = 0; //Right front sensor value
int lfrontsens = 0; //Left front sensor value
int rsidesens = 0; //Right side sensor value
int lsidesens = 0; //Left side sensor value
int rfrontsensdiff = 0; //Right front sensor value
int lfrontsensdiff = 0; //Left front sensor value
int rsidesensdiff = 0; //Right side sensor value
int lsidesensdiff = 0; //Left side sensor value
int sensdiff = 0; //Difference between front sensors
int batteryvolts = 0; // battery voltage reading
int batterycalc = 0; // working field
int switchvoltage = 0; // analogue value coming back from reading function or 4 way switch
int fnswvalue = 0; // value (in range 0 to 16) of 4 way function switch
int posn = 0; // if on line or off it and which side
int numb;
//Motor variables
int basespeed = 35; //Base speed (constant)
int rightspeed = 35; //Right motor speed
int leftspeed = 35; //Left motor speed
int spinspeed = 35; // motor speed when doing a spin turn
int i=0; // loop counter
int adjustamount = 0; // amount to adjut the motors by
int lstarget;
int lostwall = 10; //value when left wall not seen
int lwallseen = 10;
int rightpresent = 15;
int rwallseen = 15;
int fwallseen = 30;
int threshold = 35; // wall seen at front sensor
int speedvalue = 10; //
void setup() { // this code will run once on startup
 pinMode(lmotorDIR, OUTPUT);
 pinMode(rmotorDIR, OUTPUT);
 pinMode(lmotorPWM, OUTPUT);
 pinMode(rmotorPWM, OUTPUT);
 pinMode(sensorLED1, OUTPUT);
 pinMode(sensorLED2, OUTPUT);
 pinMode(trigger1, OUTPUT);
 pinMode(trigger2, OUTPUT);
 pinMode(LED13, OUTPUT);
 pinMode(m1encoder1, INPUT);
 pinMode(m1encoder2, INPUT);
 pinMode(m2encoder1, INPUT);
 pinMode(m2encoder2, INPUT);
 Serial.begin(9600); // set up serial monitor comms on USB
 digitalWrite (trigger1, LOW); // switch off sensor LEDS
 digitalWrite (trigger2, LOW); // switch off sensor LEDS
 digitalWrite (LED13, LOW); // switch off onboard LED
 digitalWrite (sensorLED1, LOW); // switch off LED1
 digitalWrite (sensorLED2, LOW); // switch off LED2
}
