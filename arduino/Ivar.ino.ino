
#include "AlphaBot.h"

int LSensorPin = 7;
int RSensorPin = 8;

int LSensor;              //Left Infrared Proximity Sensor signal value
int RSensor;              //Right Infrared Proximity Sensor signal value



AlphaBot Car1 = AlphaBot();

void ProximityConfig()
{
  pinMode(RSensorPin, INPUT);   //Define the input pin of Right Infrared Proximity Sensor
  pinMode(LSensorPin, INPUT);   //Define the input pin of Left Infrared Proximity Sensor

  Serial.begin(9600);
}


int command[3];


void setup()
{
  ProximityConfig();
  Car1.SetSpeed(100);
//  Serial.begin(9600);
}

void loop()
{ 
if (Serial.available()>=3){
  for (int k=0;k>=3;k++){
    command[k]=Serial.read();
  }
switch (command[0]) {
  case 0:
  Car1.Forward();
  Car1.SetSpeed(command[1],command[2]+10);
  break;
  case 1:
  Car1.Backward();
  Car1.SetSpeed(command[1],command[2]);
  break;
  case 2:
  Car1.HardLeft();
  Car1.SetSpeed(command[1],command[2]);
  break;
  case 3:
  Car1.HardRight();
  Car1.SetSpeed(command[1],command[2]);
  break;
  case 4:
  Car1.Right();
  Car1.SetSpeed(command[1],command[2]);
  break;
  case 5:
  Car1.Left();
  Car1.SetSpeed(command[1],command[2]);
  break;
  case 6:
  Car1.Brake();
  break;
}




  
}
else {

  
  while(1)
  {
    RSensor = digitalRead(RSensorPin);            //LOW means signal, HIGH means no signal 
    LSensor = digitalRead(LSensorPin);            //LOW means signal, HIGH means no signal 
    

    if (RSensor==HIGH)
      Car1.Right(1500);
    else if (RSensor==LOW && LSensor==LOW)
      Car1.Left(1500);
    else if(RSensor==LOW && LSensor==HIGH)
      Car1.Forward();
      Car1.SetSpeed(100,110);
    
    
  }
}
  
}


