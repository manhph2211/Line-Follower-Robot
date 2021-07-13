#define AIN1 18
#define AIN2 5

#define BIN1 16
#define BIN2 17

#define enA 19
#define enB 4

#define clp 35
#define near 34

#define L1 27 //S1
#define L2 26 // S2
#define R1 33 //S4
#define R2 32 // S5
#define C 25 // S3

const int freq = 1000;
const int ledChannel = 0;
const int resolution = 8;

byte state = 0;// 0 la dung , 1 la di thang, 2 la ben phai, 3 la ben trai

int dutyCycle = 150;
int count = 0;

void processor(){
    if(!digitalRead(C))
        state = 1;
      else  if(!digitalRead(L1)|!digitalRead(L2)) 
                state = 2;
              else  if(!digitalRead(R1)|!digitalRead(R2)) 
                        state = 3;
                      else {
                        if(count <100){
                            count++;
                            delay(100);
                        }
                          else  {
                            count = 0;
                            state = 0;
                          }
                        }
    Serial.println(state);
    switch(state){
      case 0:
         ledcWrite(ledChannel, dutyCycle);
         digitalWrite(AIN1,LOW);
         digitalWrite(AIN2,LOW);
         digitalWrite(BIN1,LOW);
         digitalWrite(BIN2,LOW);
         break;
      case 1:
         ledcWrite(ledChannel, dutyCycle);
         digitalWrite(AIN1,HIGH);
         digitalWrite(AIN2,LOW);
         digitalWrite(BIN1,HIGH);
         digitalWrite(BIN2,LOW);
         break;
      case 2:
         ledcWrite(ledChannel, dutyCycle);
         digitalWrite(AIN1,HIGH);
         digitalWrite(AIN2,LOW);
         digitalWrite(BIN1,LOW);
         digitalWrite(BIN2,LOW);
         break;
      case 3:
         ledcWrite(ledChannel, dutyCycle);
         digitalWrite(AIN1,LOW);
         digitalWrite(AIN2,LOW);
         digitalWrite(BIN1,HIGH);
         digitalWrite(BIN2,LOW);
         break; 
      default: break;     
    }
    delay(500);
}

void setup() {
  pinMode(L1, INPUT);
  pinMode(L2, INPUT);
  pinMode(C,  INPUT);
  pinMode(R1, INPUT);
  pinMode(R2, INPUT);
  pinMode(near,INPUT);
  pinMode(clp,INPUT);

  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  Serial.begin(9600);

  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(enA, ledChannel);
  ledcAttachPin(enB, ledChannel);
}

void loop() {
  processor();
  //delay(200);
}
