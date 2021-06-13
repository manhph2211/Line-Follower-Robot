#include <LiquidCrystal.h>
#define selectorA A1
#define selectorB A2
#define selectorC A3
#define motorin1 3
#define motorin2 5
#define motorin3 6
#define motorin4 9

LiquidCrystal lcd(2, 4, 7, 8, 12, 13);
int nilai[6];
 void setup()
{
  pinMode(selectorA,OUTPUT);
  pinMode(selectorB,OUTPUT);
  pinMode(selectorC,OUTPUT);
  pinMode(motorin1,OUTPUT);
  pinMode(motorin2,OUTPUT);
  pinMode(motorin3,OUTPUT);
  pinMode(motorin4,OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
} 

void selector(int c,int b,int a)
{
  digitalWrite (selectorA,a);
  digitalWrite (selectorB,b);
  digitalWrite (selectorC,c);
  }
  
  void sensor()
  {
    selector(0,0,0);
    nilai[1]=analogRead(A0);
    
    if(nilai[1]>=512)
    {
      nilai[1]=1;
    }
    else if(nilai[1]<=512)
    {
      nilai[1]=0;
      }
      
    selector(0,0,1);
    nilai[2]=analogRead(A0);
    
    if(nilai[2]>=512)
    {
      nilai[2]=1;
    }
    else if(nilai[2]<=512)
    {
      nilai[2]=0;
      }
    selector(0,1,0);
    nilai[3]=analogRead(A0);
    
    if(nilai[3]>=512)
    {
      nilai[3]=1;
    }
    else if(nilai[3]<=512)
    {
      nilai[3]=0;
      }
    selector(0,1,1);
    nilai[4]=analogRead(A0);
    
    if(nilai[4]>=512)
    {
      nilai[4]=1;
    }
    else if(nilai[4]<=512)
    {
      nilai[4]=0;
      }
    selector(1,0,0);
    nilai[5]=analogRead(A0);
   
    if(nilai[5]>=512)
    {
      nilai[5]=1;
    }
    else if(nilai[5]<=512)
    {
      nilai[5]=0;
      }
    selector(1,0,1);
    nilai[6]=analogRead(A0);
    if(nilai[6]>=512)
    {
      nilai[6]=1;
    }
    else if(nilai[6]<=512)
    {
      nilai[6]=0;
      }
      
  }
 void tampil_lcd()
{
  sensor();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sensor:");
  lcd.setCursor(8,0);
  lcd.print(nilai[1]);
  lcd.setCursor(9,0);
  lcd.print(nilai[2]);
  lcd.setCursor(10,0);
  lcd.print(nilai[3]);
  lcd.setCursor(11,0);
  lcd.print(nilai[4]);
  lcd.setCursor(12,0);
  lcd.print(nilai[5]);
  lcd.setCursor(13,0);
  lcd.print(nilai[6]);
  delay(100);
  }
 
void loop()
{
    logika_robot();
    }
  void motor (int kir, int kan){
if (kir < 0){
digitalWrite(motorin3, 1);
analogWrite(motorin4, kir+255);
}
else if (kir>=0){
digitalWrite(motorin3, 0);
analogWrite(motorin4, kir);
}

if (kan < 0){
digitalWrite(motorin1, 1);
analogWrite(motorin2, kan+255);
}
else if (kan>=0){
digitalWrite(motorin1, 0);
analogWrite(motorin2, kan);
}
  }
  void maju (){
    motor(255,255);
  }
  void mundur (){
    motor(-255,-255);
  }
void belok_kiri_lambat(){
motor(200,255);
}
void belok_kiri_cepat (){
  motor(100,255);
}
void hadap_kiri (){
  motor(0,255);
}
void belok_kanan_lambat(){
motor(255,200);
}
void belok_kanan_cepat (){
  motor(255,100);
}
void hadap_kanan (){
motor(255,0);
}

void logika_robot(){
sensor();
tampil_lcd();

if ((nilai[1]==0) && (nilai[2]== 0) && (nilai[3]==1) && (nilai[4]==1) && (nilai[5]==0) && (nilai[6]==0)){
  maju(); 
  lcd.setCursor(0,1);
  lcd.print("maju");
  delay(1000);
}

else if ((nilai[1]==0) && (nilai[2]== 1) && (nilai[3]==1) && (nilai[4]==0) && (nilai[5]==0) && (nilai[6]==0)){
  belok_kiri_lambat();
  lcd.setCursor(0,1);
  lcd.print("kiri lambat");
  delay(1000); 
}
else if ((nilai[1]==1) && (nilai[2]== 1) && (nilai[3]==0) && (nilai[4]==0) && (nilai[5]==0) && (nilai[6]==0)){
  belok_kiri_cepat(); 
  lcd.setCursor(0,1);
  lcd.print("kiri cepat");
  delay(1000);
}
else if ((nilai[1]==1) && (nilai[2]== 0) && (nilai[3]==0) && (nilai[4]==0) && (nilai[5]==0) && (nilai[6]==0)){
  hadap_kiri(); 
  lcd.setCursor(0,1);
  lcd.print("hadap kiri");
  delay(1000);
}
else if ((nilai[1]==0) && (nilai[2]== 0) && (nilai[3]==0) && (nilai[4]==1) && (nilai[5]==1) && (nilai[6]==0)){
  belok_kanan_lambat(); 
  lcd.setCursor(0,1);
  lcd.print("kanan lambat");
  delay(1000);
}
else if ((nilai[1]==0) && (nilai[2]== 0) && (nilai[3]==0) && (nilai[4]==0) && (nilai[5]==1) && (nilai[6]==1)){
  belok_kanan_cepat();
  lcd.setCursor(0,1);
  lcd.print("kanan cepat");
  delay(1000); 
}
else if ((nilai[1]==0) && (nilai[2]== 0) && (nilai[3]==0) && (nilai[4]==0) && (nilai[5]==0) && (nilai[6]==1)){
  hadap_kanan();
  lcd.setCursor(0,1);
  lcd.print("hadap kanan");
  delay(1000); 
}
else if ((nilai[1]==0) && (nilai[2]== 0) && (nilai[3]==0) && (nilai[4]==0) && (nilai[5]==0) && (nilai[6]==0)){
  mundur();
  lcd.setCursor(0,1);
  lcd.print("mundur"); 
  delay(1000);
} 
}





  




