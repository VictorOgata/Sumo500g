
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
int L=0,R=0;


void setup()
{
  Serial.begin(9600);
 // set all the motor control pins to outputs
 pinMode(9, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(7, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(5,INPUT);//Right G
 pinMode(4,INPUT);//Left G

}
void Stop()
{
  digitalWrite(9, LOW);
 digitalWrite(8,LOW );
 digitalWrite(7,LOW);
 digitalWrite(6 ,LOW);
  } 
void motorF()
{
  digitalWrite(9,LOW);
 digitalWrite(8,LOW );
 digitalWrite(7,HIGH);
 digitalWrite(6 ,HIGH);
}
void motorB()
{
  digitalWrite(9,HIGH);
 digitalWrite(8,HIGH );
 digitalWrite(7,LOW);
 digitalWrite(6 ,LOW);
}
void motorL()
{
 digitalWrite(9,LOW);
 digitalWrite(8,HIGH );
 digitalWrite(7,LOW);
 digitalWrite(6 ,HIGH);
}
void motorR()
{
 digitalWrite(9, HIGH);
 digitalWrite(8,LOW );
 digitalWrite(7,HIGH);
 digitalWrite(6 ,LOW);

}

void loop(){
  L = digitalRead(5);
  R = digitalRead(4);
//  Serial.println(L);
//   Serial.println(R);
if(L==1 && R==1)  
motorF();
else if(L==0 && R==1)
motorL(); 
else if(L==1 && R==0)
motorR();
else if(L==0 && R==0)
Stop();



}
