#include <Adafruit_TCS34725.h>


/*******************************************************************************/  
/***************** FORGERS SUMO 500G CONTROLLER ********************************/                               
/*******************************************************************************/
//=============================================================================
//  Technical Manager:    Victor O. Ogata
//  Members:     Victor O. Ogata   
//              
//  Creation Date:      13/05/2018
//  Revision History 
//  Name:               Date:         Description
//  Victor O. Ogata     13/05/2018    Motor Control and RGB sensor programming
//  Victor O. Ogata     15/05/2018    Ultrasonic sensor and bug fixes
//  Victor O. Ogata     26/06/2018    Push button 
//
//                                
//=============================================================================



#include <Wire.h>
#include <Ultrasonic.h>
 int Sensorval=LOW;
 int buttonState = 0;
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(0,1);
Ultrasonic ultrasonic1(2,3);
 int i =0;
   // r = red shades , g = green shades , b = blue shades 
   uint16_t r, g, b, c, colorTemp, lux;
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_60X);

void setup()
{
 // set all the motor control pins to outputs
 pinMode(A1, OUTPUT);
 pinMode(A2, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(11, OUTPUT);
 pinMode(12, INPUT);
 
}


void rgb()
{
  
      // raw data read
   tcs.getRawData(&r, &g, &b, &c);
   
   // color levels calculation
   colorTemp = tcs.calculateColorTemperature(r, g, b);
 
   // luminosity calculation
   lux = tcs.calculateLux(r, g, b);
   Serial.print(r);
   Serial.print(",");
   Serial.print(g);
   Serial.print(",");
    Serial.print(b);
   Serial.print(",");
    Serial.print(c);
   Serial.print(",");
   Serial.println(lux);
   delay(500);
}

void motorF()
{
  digitalWrite(8, HIGH);
 digitalWrite(9,LOW );
 digitalWrite(10, HIGH);
 digitalWrite(11 ,LOW);
 //while( c>3000){
 //tcs.getRawData(&r, &g, &b, &c);
 // Serial.println(c);
  //Serial.println(i);
 if(i<256){ 
 analogWrite(6, i);
 analogWrite(7, i);
 i = i+ 10;}
// }
 //if(c<3000){
  i=0;

// }
}


void loop(){
   
}


