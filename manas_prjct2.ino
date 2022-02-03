// C++ code
//
int pot_inp;
int value;
int x;
int mode=0;
void setup()
{
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  
}

void loop()
{
  if(digitalRead(7)==1){
    while(digitalRead(7)!=0){delay(5);}
    mode+=1;
    if(mode==2){mode=0;}
  }
  
  pot_inp=analogRead(A0);
  value=map(pot_inp,0,1023,0,5);
  switch(value){
    case 0: x=2000;
            break;
    case 1: x=1600;
            break;
    case 2: x=1200;
            break;
    case 3: x=800;
            break;
    case 4: x=400;
            break;
    case 5: x=100;
            break;
  }
  if(mode==1){
  digitalWrite(6, HIGH);
  delay(x); // Wait for 1000 millisecond(s)
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  delay(x); // Wait for 1000 millisecond(s)
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  delay(x);
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  delay(x);
  digitalWrite(3, LOW);
  delay(x);
  if(digitalRead(7)==1){
    while(digitalRead(7)!=0){delay(5);}
    mode+=1;
    if(mode==2){mode=0;}
  }
  }
}