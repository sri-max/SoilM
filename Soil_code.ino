int LED1=3;
int LED2=5;
int LED3=6;
int timesTosend=1;
int count=0;
char phonenumber[]="8197989903";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
digitalWrite(LED1,1);
digitalWrite(LED2,2);
digitalWrite(LED3,3);
Serial.begin(9600);
delay(2000);
Serial.println("AT+CMGF=1");
delay(200);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorValue=analogRead(A0);
Serial.println(sensorValue);
if(sensorValue>=1000)
{
digitalWrite(LED1,HIGH);
digitalWrite(LED2,LOW);
digitalWrite(LED3,LOW);
while(count<timesTosend)
{
  delay(1500);
  Serial.print("AT+CMGS=\"");
  Serial.print(phonenumber);
  Serial.println("\"");
  while(Serial.read()!='>');
  {
    Serial.print("I AM THIRSTY PLZ WATER ME");
    delay(500);
    Serial.write(0x1A);
    Serial.write(0x0D);
    Serial.write(0x0A);
    delay(5000);
  
  }
  count++;
}
}
else if(sensorValue>=350&&sensorValue<950)
{
  digitalWrite(LED2,HIGH);
  digitalWrite(LED1,LOW);
  digitalWrite(LED3,LOW);
  while(count<timesTosend)
{
  delay(1500);
  Serial.print("AT+CMGS=\"");
  Serial.print(phonenumber);
  Serial.println("\"");
  while(Serial.read()!='>');
  {
    Serial.print("ITS SUFFICIENT");
    delay(500);
    Serial.write(0x1A);
    Serial.write(0x0D);
    Serial.write(0x0A);
    delay(5000);
  
  }
  count++;
}
}
else if(sensorValue>=0&&sensorValue<350)
{
  digitalWrite(LED3,HIGH);
  digitalWrite(LED2,LOW);
  digitalWrite(LED1,LOW);
  while(count<timesTosend)
{
  delay(1500);
  Serial.print("AT+CMGS=\"");
  Serial.print(phonenumber);
  Serial.println("\"");
  while(Serial.read()!='>');
  {
    Serial.print("THANK YOU I AM FULL");
    delay(500);
    Serial.write(0x1A);
    Serial.write(0x0D);
    Serial.write(0x0A);
    delay(5000);
  
  }
  count++;
}
}
}
