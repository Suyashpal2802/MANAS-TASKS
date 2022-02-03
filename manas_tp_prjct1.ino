// C++ code
//


void setup()
{
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
}

void loop()
{
  digitalWrite(13, LOW);
  if (digitalRead(7)==1) {
    while(digitalRead(7)==1){digitalWrite(13,HIGH);}
    
  }
}  
  

  