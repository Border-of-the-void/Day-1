#include <Servo.h>
String n;
Servo s[5];
int p[5] = {3, 5, 6, 9 ,10};                    //пины для сервомоторов
int KA[5] = {0, 180, 180, 118, 70};             //Углы при кулаке
int LA[5] = {179, 0, 0, 166, 169};              //Углы при ладони
int OA[5] = {178, 0, 117, 92, 118};             //Углы при окее
long int Time;


void K(){ //функция жеста кулак
  for (int i = 0; i < 5; i ++){s[i].write(KA[i]);}
  if (Time % 1000 < 500){digitalWrite(2, 1);}     //Мигание светодиода
  else{digitalWrite(2, 0);}
  digitalWrite(4, 0);
  }

  
  void L(){ //Функция жеста ладонь
    for (int i = 0; i < 5; i ++){s[i].write(LA[i]);}
  digitalWrite(2, 0);
  digitalWrite(4, 0);
  }

  
void O(){ //Функция жеста Окей
  for (int i = 0; i < 5; i ++){s[i].write(OA[i]);}
  if (Time % 500 < 250){digitalWrite(2, 1);}     //Мигание светодиода
  else{digitalWrite(2, 0);}
  digitalWrite(4, 0);
  }

  
void P(){ //Функция ручного управления
    for ( int i = 0; i < 5; i++){
       s[i].write(map(analogRead(i), 0, 1023, 0, 180));
    }
  }


void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++){s[i].attach(p[i]);} //Назначение сервомоторам соответсвтующих пинов
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  for (int i = 0; i < 5; i ++){s[i].write(LA[i]);}
}

void loop() {
  Time = millis();
  if (Serial.available() ){ //Проверка изменений в сериал порте
  n = Serial.readString();  //Получение значения
  }
  if (n == "K"){K();}       //Вызов функции в зависимости от пришедшего значения
  else if (n == "O"){O();}
  else if (n == "L"){L();}
  else if (n == "P"){P();}
}
