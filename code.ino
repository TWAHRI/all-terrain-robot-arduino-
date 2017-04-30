int pin1Moteur1=12; //pin de commande moteur 1
int pin2Moteur1=10; // pin de commande moteur 1
int pinPMoteur1=11;// pin PWM moteur 1
int pin1Moteur2=8; // pin de commande moteur 2
int pin2Moteur2=7; // pin de commande moteur 2
int pinPMoteur2=5; // pin PWM moteur 2

char str[2],i;
void forward()
{  analogWrite(pinPMoteur1,245); 
   digitalWrite(pin1Moteur1, 0);
   digitalWrite(pin2Moteur1, 1);
   analogWrite(pinPMoteur2,245); 
   digitalWrite(pin1Moteur2, 0);
   digitalWrite(pin2Moteur2,1);
}
void backward()
{
   analogWrite(pinPMoteur1,225); 
   digitalWrite(pin1Moteur1, 1);
   digitalWrite(pin2Moteur1, 0);
   analogWrite(pinPMoteur2,225); 
   digitalWrite(pin1Moteur2, 1);
   digitalWrite(pin2Moteur2,0);
}
void left()
{
   analogWrite(pinPMoteur1,225); 
  digitalWrite(pin1Moteur1, 0);
   digitalWrite(pin2Moteur1, 1);
   analogWrite(pinPMoteur2,225); 
   digitalWrite(pin1Moteur2, 1);
   digitalWrite(pin2Moteur2,0);
}
void right()
{
  analogWrite(pinPMoteur1,225); 
  digitalWrite(pin1Moteur1, 1);
   digitalWrite(pin2Moteur1, 0);
   analogWrite(pinPMoteur2,225); 
   digitalWrite(pin1Moteur2, 0);
   digitalWrite(pin2Moteur2,1);
}
void Stop()
{
   analogWrite(pinPMoteur1,0); 
  digitalWrite(pin1Moteur1, 0);
   digitalWrite(pin2Moteur1, 0);
   analogWrite(pinPMoteur2,0); 
   digitalWrite(pin1Moteur2, 0);
   digitalWrite(pin2Moteur2,0);
}
void setup() 
{
  Serial.begin(9600);
  pinMode(pin1Moteur1, OUTPUT);
  pinMode(pin2Moteur1, OUTPUT);
  pinMode(pinPMoteur1, OUTPUT);
  pinMode(pin1Moteur2, OUTPUT);
   pinMode(pin2Moteur2, OUTPUT);
    pinMode(pinPMoteur2, OUTPUT);
  
}
void loop() 
{
  while(Serial.available())
  {
    char ch=Serial.read();
    str[i++]=ch;
    
    if(str[i-1]=='1')
    {
     Serial.println("Forward");
     forward();
     i=0;
    }
    else if(str[i-1]=='2')
    {
     Serial.println("Left");
     right();
     i=0;
    }
    else if(str[i-1]=='3')
    {
      Serial.println("Right");
      left();
      i=0;
    }
    
    else if(str[i-1]=='4')
    {
      Serial.println("Backward");
      backward();
      i=0;
    }
    else if(str[i-1]=='5')
    {
      Serial.println("Stop");
      Stop();
      i=0;
    }
    delay(100);
  }
}
