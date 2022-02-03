#include <Servo.h>

Servo myservo;
int pot_inp;
int mode=0;
int dcm=0;
int val;
int s1=0;

void setup()
{
  myservo.attach(4);
  pinMode(A0, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  myservo.write(0);
  
}

void loop()
{
  
  pot_inp=analogRead(A0);
  int value=map(pot_inp,0,1023,0,100);
  switch(mode){
    case 0: while(mode==0){
            digitalWrite(13,LOW);
            digitalWrite(12,LOW);
            while(value<=15 && mode!=1){
              while(s1<180 && mode!=1){
                s1+=10;
                myservo.write(s1);
                delay(900);
                mode=checkmode();
                if(mode==1){break;}
                pot_inp=analogRead(A0);
                value=map(pot_inp,0,1023,0,100);
              }
              while(s1>0 && mode!=1){
                s1-=10;
                myservo.write(s1);
                delay(900);
                mode=checkmode();
                if(mode==1){break;}
                pot_inp=analogRead(A0);
                value=map(pot_inp,0,1023,0,100);
              }
            //  mode=checkmode();
            }
            while(value>15 && value<=30 && mode!=1){
              while(s1<180 && mode!=1){
                s1+=10;
                myservo.write(s1);
                delay(700);
                mode=checkmode();
                if(mode==1){break;}
                pot_inp=analogRead(A0);
                value=map(pot_inp,0,1023,0,100);
              }
              while(s1>0 && mode!=1){
                s1-=10;
                myservo.write(s1);
                delay(700);
                mode=checkmode();
                if(mode==1){break;}
                pot_inp=analogRead(A0);
                value=map(pot_inp,0,1023,0,100);
              }
            //  mode=checkmode();
            }
            while(value>30 && value<=50 && mode!=1){
              while(s1<180 && mode!=1){
                s1+=10;
                myservo.write(s1);
                delay(500);
                mode=checkmode();
                if(mode==1){break;}
                pot_inp=analogRead(A0);
                value=map(pot_inp,0,1023,0,100);
              }
              while(s1>0 && mode!=1){
                s1-=10;
                myservo.write(s1);
                delay(500);
                mode=checkmode();
                if(mode==1){break;}
                pot_inp=analogRead(A0);
                value=map(pot_inp,0,1023,0,100);
              }
             // mode=checkmode();
            }
            while(value>50 && value<=70 && mode!=1){
              while(s1<180 && mode!=1){
                s1+=20;
                myservo.write(s1);
                delay(500);
                mode=checkmode();
                if(mode==1){break;}
                pot_inp=analogRead(A0);
                value=map(pot_inp,0,1023,0,100);
              }
              while(s1>0 && mode!=1){
                s1-=20;
                myservo.write(s1);
                delay(500);
                mode=checkmode();
                if(mode==1){break;}
                pot_inp=analogRead(A0);
                value=map(pot_inp,0,1023,0,100);
              }
             // mode=checkmode();
            }
            while(value>70 && value<=85 && mode!=1){
              while(s1<180 && mode!=1){
                s1+=20;
                myservo.write(s1);
                delay(300);
                mode=checkmode();
                if(mode==1){break;}
                pot_inp=analogRead(A0);
                value=map(pot_inp,0,1023,0,100);
              }
              while(s1>0 && mode!=1){
                s1-=20;
                myservo.write(s1);
                delay(300);
                mode=checkmode();
                if(mode==1){break;}
                pot_inp=analogRead(A0);
                value=map(pot_inp,0,1023,0,100);
              }
             // mode=checkmode();
            }
            while(value>85 && value<=100 && mode!=1){
              while(s1<180 && mode!=1){
                s1+=30;
                myservo.write(s1);
                delay(300);
                mode=checkmode();
                if(mode==1){break;}
                pot_inp=analogRead(A0);
                value=map(pot_inp,0,1023,0,100);
              }
              while(s1>0 && mode!=1){
                s1-=30;
                myservo.write(s1);
                delay(300);
                mode=checkmode();
                if(mode==1){break;}
                pot_inp=analogRead(A0);
                value=map(pot_inp,0,1023,0,100);
              }
             // mode=checkmode();
            }}
    case 1: while(mode==1 && dcm==0){
            digitalWrite(12,HIGH);
            digitalWrite(13,LOW);
            mode=checkmode();
            if(mode==0){
              digitalWrite(12,LOW);
              digitalWrite(13,LOW);
              break;
            }
            if(digitalRead(2)==HIGH){
              while(digitalRead(2)!=LOW){
               delay(500);
              }
              dcm+=1;
              if(dcm==2){dcm=0;}
            }
            }
            while(mode==1 && dcm==1){
            digitalWrite(12,LOW);
            digitalWrite(13,HIGH);
            mode=checkmode();
            if(mode==0){
              digitalWrite(12,LOW);
              digitalWrite(13,LOW);
              break;
            }
            if(digitalRead(2)==HIGH){
              while(digitalRead(2)!=LOW){
               delay(500);
              }
              dcm+=1;
              if(dcm==2){dcm=0;}
            }
            }
            
  }
  
}
void modechange(){
  if(mode==1){
    if(dcm==0){
     digitalWrite(13,LOW);
     digitalWrite(12,HIGH);
    }
    else{
     digitalWrite(13,HIGH);
     digitalWrite(12,LOW);
    }
  }
}
int checkmode(){
 
  if(digitalRead(3)==HIGH){ 
    while(digitalRead(3)!=LOW){delay(5);}
    mode+=1;
    if (mode==2){
      mode=0;
    }}
  return mode;
}