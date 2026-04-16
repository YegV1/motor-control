int x,y = 0;
 int readX() 
{
  int xr=0;
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  digitalWrite(A1, LOW);  
  digitalWrite(A3, HIGH); 
  delay(5);
  xr=analogRead(0);       
  return xr;
}

 int readY() 
{
  int yr=0;
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT); 
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT); 
  digitalWrite(14, LOW);  
  digitalWrite(16, HIGH);
  delay(5);
  yr=analogRead(1);
  return yr; 
}

void setup()
{
  Serial.begin(9600);
  pinMode(11,OUTPUT);
}

void loop()
{
 Serial.print(readX());
 Serial.print(" ");
 Serial.println(readY());
 delay(200);
 if(readX()>=180&readX()<950){
  analogWrite(3,map(readX(),180,950,0,255));
 }
 if(readX()<180&readX()>80){
  digitalWrite(3,0);
 }
}