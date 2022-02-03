// C++ code
//
int echoPin=3;
int trigPin=4;
float dist;
float frac;
int dur;
void setup()
{
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  dur=pulseIn(echoPin, HIGH);
  dist=dur*0.034/2;// calculating distance with speed =dist/time formula.
  frac=dist/335;//to get the fraction as per the task.
  Serial.println(frac,2);//to ensure the fraction value for crosschecking.
  //comparision of the fraction.
  if (frac<(0.166)){
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW); 
  }
  if (frac<(0.333) && frac>(0.166)){
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW); 
  }
  if (frac<(0.5) && frac>(0.333)){
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW); 
  }
  if (frac<(0.666) && frac>(0.5)){
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW); 
  }
  if (frac<(0.833) && frac>(0.666)){
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW); 
  }
  if (frac<=(1) && frac>(0.833)){
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH); 
  }
  
  
}