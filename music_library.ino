#include <SoftwareSerial.h>
#include "themes.h"
#include "pitches.h"
const int rxPin = 4;
const int txPin = 2;  
int a;             

SoftwareSerial mySerial(rxPin, txPin);

const int Loads[] = {9, 10};

int state = 0;
int flag = 0;


void setup() 
{
   for (int i=0;i<2;i++)
    {
      pinMode(Loads[i], OUTPUT);
    }
   mySerial.begin(9600);
   for (int i=0;i<2;i++)
    {
      digitalWrite(Loads[i], LOW);
    }
   
}

void loop() 
{
    
    if(mySerial.available() > 0)
    {
      state = mySerial.read();
      flag=0;
    }
    
    switch(state)
    {
      case '0':digitalWrite(Loads[0], HIGH);
               flag=1;
               break;
      case '1':digitalWrite(Loads[0], LOW);
               flag=1;
               break;
      case '2':digitalWrite(Loads[1], HIGH);
               flag=1;
               break;
      case '3':digitalWrite(Loads[1], LOW);
               flag=1;
               break;
      case '4':digitalWrite(Loads[0], LOW);
               digitalWrite(Loads[1], LOW);
               flag = 1;
               break;
      case '5':digitalWrite(Loads[0], HIGH);
               digitalWrite(Loads[1], HIGH);
               flag=1;
               break;
     case '6': for (int thisNote = 0; thisNote < 89; thisNote++) 
                  {
                     int noteDuration = 1000/Pirates_duration[thisNote];
                     tone(9,Pirates_note[thisNote],noteDuration);                                                    
                     delay(noteDuration +30);
                  }
                  flag=1;
                  break;
      case '7': for (int thisNote = 0; thisNote < 56; thisNote++) 
                  {
                     int noteDuration = 1000/MarioUW_duration[thisNote];
                     tone(9,MarioUW_note[thisNote],noteDuration);                                                    
                     delay(noteDuration +30);
                  }
                  flag=1;
                  break;
      case '8': for (int thisNote = 0; thisNote < 74; thisNote++) 
                  {
                     int noteDuration = 1000/Titanic_duration[thisNote];
                     tone(9,Titanic_note[thisNote],noteDuration);                                                    
                     delay(noteDuration +30);
                  }
                  flag=1;
                  break;
      case '9': for (int thisNote = 0; thisNote < 31; thisNote++) 
                  {
                     int noteDuration = 1000/CrazyFrog_duration[thisNote];
                     tone(9,CrazyFrog_note[thisNote],noteDuration);                                                    
                     delay(noteDuration +30);
                  }
                  flag=1;
                  break;
}
}
