
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
 pinMode(PB9, OUTPUT);
 pinMode(PB8, OUTPUT);
 pinMode(PB7, OUTPUT);
 pinMode(PB6, OUTPUT);
 pinMode(PB0,INPUT);//Right IF
 pinMode(PB1,INPUT);//Left IF
 pinMode(PA7,INPUT);//Right G
 pinMode(PA6,INPUT);//Left G

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
  digitalWrite(PB9,LOW);
 digitalWrite(PB8,LOW );
 digitalWrite(PB7,HIGH);
 digitalWrite(PB6 ,HIGH);
}
void motorB()
{
  digitalWrite(PB9,HIGH);
 digitalWrite(PB8,HIGH );
 digitalWrite(PB7,LOW);
 digitalWrite(PB6 ,LOW);
}
void motorL()
{
 digitalWrite(PB9,LOW);
 digitalWrite(PB8,HIGH );
 digitalWrite(PB7,LOW);
 digitalWrite(PB6 ,HIGH);
}
void motorR()
{
 digitalWrite(PB9, HIGH);
 digitalWrite(PB8,LOW );
 digitalWrite(PB7,HIGH);
 digitalWrite(PB6 ,LOW);

}

void loop(){
  L = digitalRead(PA7);
  R = digitalRead(PA6);
//  Serial.println(L);
//   Serial.println(R);
 //   digitalWrite(PB9,LOW);
// digitalWrite(PB8,HIGH );
// digitalWrite(PB7,HIGH);
// digitalWrite(PB6 ,LOW);
if(L==1 && R==1)  
motorF();
else if(L==0 && R==1)
motorL(); 
else if(L==1 && R==0)
motorR();
else if(L==0 && R==0)
Stop();



}
