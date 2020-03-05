
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
//  Victor O. Ogata     14/03/2019    Motor Control
//  Victor O. Ogata     27/03/2019    IF sensors
//
//                                
//=============================================================================
int L=0,R=0,i=0;
#include <SharpIR.h>
#define ir PA5
#define model 1080
SharpIR SharpIR(ir, model); 
void setup()
{
  Serial.begin(9600);
 // set all the motor control pins to outputs
 pinMode(PB9, OUTPUT);
 pinMode(PB8, OUTPUT);
 pinMode(PB7, OUTPUT);
 pinMode(PB6, OUTPUT);
 pinMode(PB0,INPUT);//Right IF
 pinMode(PB1,INPUT);//Left IF
 pinMode(PA7,INPUT);//Right G
 pinMode(PA6,INPUT);//Left G
 pinMode(ir,INPUT);//IF 
 delay(3000);
}
void Stop()
{
  digitalWrite(PB9, LOW);
 digitalWrite(PB8,LOW );
 digitalWrite(PB7,LOW);
 digitalWrite(PB6 ,LOW);
  }
void motorF()
{
  digitalWrite(PB9, HIGH);
 digitalWrite(PB8,LOW );
 digitalWrite(PB7, LOW);
 digitalWrite(PB6 ,HIGH);
}
void motorB()
{
   digitalWrite(PB9, LOW);
 digitalWrite(PB8,HIGH );
 digitalWrite(PB7,HIGH);
 digitalWrite(PB6 ,LOW);
}
void motorL()
{
 digitalWrite(PB9,HIGH);
 digitalWrite(PB8,LOW );
 digitalWrite(PB7,HIGH);
 digitalWrite(PB6 ,LOW);
}
void motorR()
{
 digitalWrite(PB9, LOW);
 digitalWrite(PB8,HIGH );
 digitalWrite(PB7,LOW);
 digitalWrite(PB6 ,HIGH);

}

void loop(){
  
  L = digitalRead(PA6);
  R = digitalRead(PA7);
  //int distancia = SharpIR.distance();
  if(R==1&& L==1) { 
  Stop();  
motorF();}
else if(R!=1&& L==1){
 Stop();
 motorL();
 }
else if(R==1&& L!=1){
 Stop();
 motorR();
 }
 else if(R==0&& L==0){
 Stop();
 motorB();
 delay(500);
  Stop();
 motorL();
 delay(500);
 }
 else  Stop();



}
