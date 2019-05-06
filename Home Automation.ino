#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h> 

#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_SERIAL_RX 0
#define REMOTEXY_SERIAL_TX 1 
#define REMOTEXY_SERIAL_SPEED 9600 


// RemoteXY configurate   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,8,0,0,0,180,0,8,24,1,
  4,128,5,43,50,8,36,26,2,0,
  31,53,22,11,190,26,31,31,79,78,
  0,79,70,70,0,1,1,13,85,13,
  12,119,31,79,112,101,110,0,1,1,
  33,85,13,12,36,31,67,108,111,115,
  101,0,6,0,5,9,32,32,2,26,
  4,128,15,67,49,8,95,26,129,0,
  20,78,21,6,31,71,97,114,97,103,
  101,0,129,0,1,68,13,7,31,70,
  97,110,0,129,0,6,56,20,6,31,
  76,105,103,104,116,32,50,0,129,0,
  39,37,20,6,31,76,105,103,104,116,
  32,49,0,129,0,1,2,61,5,31,
  72,111,109,101,32,65,117,116,111,109,
  97,116,105,111,110,32,83,121,115,116,
  101,109,0,129,0,41,15,13,6,31,
  82,71,66,0,129,0,41,22,15,6,
  31,76,105,103,104,116,0 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  int8_t slider_1; // =0..100 slider position 
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t button_1; // =1 if button pressed, else =0 
  uint8_t button_2; // =1 if button pressed, else =0 
  uint8_t rgb_1_r; // =0..255 Red color value 
  uint8_t rgb_1_g; // =0..255 Green color value 
  uint8_t rgb_1_b; // =0..255 Blue color value 
  int8_t slider_2; // =0..100 slider position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 
#include <Servo.h>   

Servo myservo;
#define PIN_SWITCH_1 8
int led2 = 11;
int redPin= 10;
int greenPin = 5;
int bluePin = 6;
int motor = 3;

void setup()  
{ 
  RemoteXY_Init ();  
    
pinMode (PIN_SWITCH_1, OUTPUT);
       pinMode (led2, OUTPUT);

    
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  // TODO you setup code    
  // TODO you setup code 
   
  // TODO you setup code 
   
} 

void loop()  
{  
  RemoteXY_Handler (); 
   
 
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
   int led2value = (RemoteXY.slider_1*2.55);

  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
    analogWrite(led2, led2value);
  // TODO you loop code 
  // use the RemoteXY structure for data transfer 
   int redValue = RemoteXY.rgb_1_r;
  int greenValue = RemoteXY.rgb_1_g;
  int blueValue = RemoteXY.rgb_1_b;
  int motorvalue= (RemoteXY.slider_2*2.55);
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
  analogWrite(motor , motorvalue);
   if(RemoteXY.button_1==1){
    
    myservo.attach(9);
   
    myservo.write(0);
delay(20);
myservo.detach();
 

  }
   if(RemoteXY.button_2==1){
    
    myservo.attach(9);
   
    myservo.write(180);
delay(20);
myservo.detach();
 

  } 
   
   
  // TODO you loop code 
  // use the RemoteXY structure for data transfer 


}
