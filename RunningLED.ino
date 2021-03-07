byte HIJAU [5] = {PB12, PB14, PA8, PA10, PB3};
byte MERAH [5] = {PB13, PB15, PA9, PA15, PB4};

#define TOMBOL PB9
#define POTENSIO PA0
#define LED PC13

#define JEDA map(analogRead(POTENSIO),0,4095,10,1000)
byte MODE = 0;
boolean PB = true;

void setup() {
  for (byte i=0; i<5;i++){
    pinMode(HIJAU[i],OUTPUT);
    pinMode(MERAH[i],OUTPUT);
    digitalWrite(HIJAU[i],HIGH);
    digitalWrite(MERAH[i],HIGH);
  }
  pinMode(TOMBOL, INPUT_PULLUP);
  pinMode(POTENSIO, INPUT_ANALOG);
  pinMode(LED,OUTPUT);
  digitalWrite(LED,HIGH);
  
  attachInterrupt(digitalPinToInterrupt(TOMBOL), MODE_CHANGE, CHANGE);

}
void MODE_CHANGE(){
  if (digitalRead(TOMBOL)==HIGH && PB == false){
    PB=true;
    digitalWrite(LED,HIGH);
  }
  if (digitalRead(TOMBOL)==LOW  && PB == true) {
    PB=false;
    MODE++;
    if (MODE>7)MODE=0;
    digitalWrite(LED,LOW);  
  }
}
void loop() {
  
  switch (MODE){
    case 0:                                                       //HIJAU KE KIRI
      for (byte i=0; i<5;i++){
        digitalWrite(HIJAU[i],LOW);
        if (i>0){digitalWrite(HIJAU[i-1],HIGH);}
        else{digitalWrite(HIJAU[4],HIGH);}
        delay(JEDA);
      }
      digitalWrite(HIJAU[4],HIGH);
      break;
    case 1:                                                     // HIJAU KE KANAN
      for (byte i=5; i>0;i--){
        digitalWrite(HIJAU[i-1],LOW);
        if (i<5){digitalWrite(HIJAU[i],HIGH);}
        else{digitalWrite(HIJAU[0],HIGH);}
        delay(JEDA);
      }
      digitalWrite(HIJAU[0],HIGH);
      break;
    case 2:                                                     //MERAH KE KIRI
      for (byte i=0; i<5;i++){
        digitalWrite(MERAH[i],LOW);
        if (i>0){digitalWrite(MERAH[i-1],HIGH);}
        else{digitalWrite(MERAH[4],HIGH);}
        delay(JEDA);
      }
      digitalWrite(MERAH[4],HIGH);
      break;
    case 3:                                                   // MERAH KE KANAN
      for (byte i=5; i>0;i--){
        digitalWrite(MERAH[i-1],LOW);
        if (i<5){digitalWrite(MERAH[i],HIGH);}
        else{digitalWrite(MERAH[0],HIGH);}
        delay(JEDA);
      }
      digitalWrite(MERAH[0],HIGH);
      break;
    case 4:                                                     //MERAH DAN HIJAU KE KIRI BERGANTIAN
      for (byte i=0; i<5;i++){
        digitalWrite(HIJAU[i],LOW);
        if (i>0){digitalWrite(HIJAU[i-1],HIGH);}
        else{digitalWrite(HIJAU[4],HIGH);}
        delay(JEDA);
      }
      digitalWrite(HIJAU[4],HIGH);
      for (byte i=0; i<5;i++){
        digitalWrite(MERAH[i],LOW);
        if (i>0){digitalWrite(MERAH[i-1],HIGH);}
        else{digitalWrite(MERAH[4],HIGH);}
        delay(JEDA);
      }
      digitalWrite(MERAH[4],HIGH);
      break;
    case 5:                                           //MERAH DAN HIJAU KE KANAN BERGANTIAN
      for (byte i=5; i>0;i--){
        digitalWrite(MERAH[i-1],LOW);
        if (i<5){digitalWrite(MERAH[i],HIGH);}
        else{digitalWrite(MERAH[0],HIGH);}
        delay(JEDA);
      }
      digitalWrite(MERAH[0],HIGH);
      for (byte i=5; i>0;i--){
        digitalWrite(HIJAU[i-1],LOW);
        if (i<5){digitalWrite(HIJAU[i],HIGH);}
        else{digitalWrite(HIJAU[0],HIGH);}
        delay(JEDA);
      }
      digitalWrite(HIJAU[0],HIGH);
      break;
    case 6:                                         //HIJAU KE KIRI DAN MERAH KE KANAN BERGANTIAN
      for (byte i=0; i<5;i++){
        digitalWrite(HIJAU[i],LOW);
        if (i>0){digitalWrite(HIJAU[i-1],HIGH);}
        else{digitalWrite(HIJAU[4],HIGH);}
        delay(JEDA);
      }
      digitalWrite(HIJAU[4],HIGH);
      for (byte i=5; i>0;i--){
        digitalWrite(MERAH[i-1],LOW);
        if (i<5){digitalWrite(MERAH[i],HIGH);}
        else{digitalWrite(MERAH[0],HIGH);}
        delay(JEDA);
      }
      digitalWrite(MERAH[0],HIGH);
      break;
    case 7:                                         //MERAH KE KIRI DAN HIJAU KE KANAN BERGANTIAN
      for (byte i=0; i<5;i++){
        digitalWrite(MERAH[i],LOW);
        if (i>0){digitalWrite(MERAH[i-1],HIGH);}
        else{digitalWrite(MERAH[4],HIGH);}
        delay(JEDA);
      }
      digitalWrite(MERAH[4],HIGH);
      for (byte i=5; i>0;i--){
        digitalWrite(HIJAU[i-1],LOW);
        if (i<5){digitalWrite(HIJAU[i],HIGH);}
        else{digitalWrite(HIJAU[0],HIGH);}
        delay(JEDA);
      }
      digitalWrite(HIJAU[0],HIGH);
      break;
  }
}
