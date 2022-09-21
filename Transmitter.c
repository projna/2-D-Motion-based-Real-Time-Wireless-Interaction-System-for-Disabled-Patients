//Arduino IDE Lib
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

 //Receiver side
#include <LiquidCrystal.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
RF24 radio(7, 8);

char text[12] = {};
char text2[12] = {};
int flag1=-3;
int flag2=-3;
LiquidCrystal lcd(9, 6, 5 ,4, 3, 2);

const int xPin = A1;
const int yPin = A2; // axis coordinates of accelerators
const int zPin = A3; //input from accelerators to Arduino
int x,y,z;

void setup() {
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(0xF0F0F0F0AA);
  radio.stopListening();
}

void loop() {
  analogReference(EXTERNAL);

x=analogRead(xPin)-507;
 y=analogRead(yPin)-512;
 z=analogRead(zPin)-615;

 const char text1[] = "cONLINE    ";
 const char text2[] = "cEMERGENCY ";
 const char text3[] = "cWASHROOM  ";
 const char text4[] = "cHUNGRY    ";
 const char text5[] = "cHELP      ";
 const char text6[] = "cWATER     ";
 const char text7[] = "cCUSTOM1   ";
 const char text8[] = "cCUSTOM2   ";

 if(abs(x)<20 && abs(y)<20 && abs(z)<20)  radio.write(&text1, sizeof(text1));
 else if(abs(z)>150)  radio.write(&text2, sizeof(text2));
 else if(x>80 && abs(y)<20 && z<-80)  radio.write(&text3, sizeof(text3));
 else if(x<-80 && abs(y)<20 && z<-80)  radio.write(&text4, sizeof(text4));
 else if(x>30 && abs(y)<20 && z<-20)  radio.write(&text5, sizeof(text5));
 else if(x<-30 && abs(y)<20 && z<-20)  radio.write(&text6, sizeof(text6));
 else if(abs(x)<20 && y<-50 && z<-80)  radio.write(&text7, sizeof(text7));
 else if(abs(x)<20 && y>50 && z<-50)  radio.write(&text8, sizeof(text8));
 }


void setup() {

lcd.begin(16,2);
radio.begin();
radio.openReadingPipe(1,0xF0F0F0F0AA);
radio.openReadingPipe(2,0xF0F0F0F066);
radio.startListening();
}

void loop() {
if (radio.available())
  {
    int i=0;
    while(1)
    {
      radio.read(&text, sizeof(text));
      if (text[0]=='a' || i==30) break;
      i=i+1;
      delay(20);
    }
    if(i==30)
        {
      text[1]='O';
      text[2]='F';
      text[3]='F';
      text[4]='L';
      text[5]='I';
      text[6]='N';
      text[7]='E';
      text[8]=' ';
      text[9]=' ';
      text[10]=' ';
      text[11]=' ';
      }
    text[0]=':';
        flag1=flag1+1;
    if (text[1]=='O') flag1=0;
    i=0;
        while(1)
    {
      radio.read(&text2, sizeof(text2));
      if (text2[0]=='c' || i==30) break;
      i=i+1;
      delay(20);
    }
    if(i==30)
        {
      text2[1]='O';
      text2[2]='F';
      text2[3]='F';
      text2[4]='L';
      text2[5]='I';
      text2[6]='N';
      text2[7]='E';
      text2[8]=' ';
      text2[9]=' ';
      text2[10]=' ';
      text2[11]=' ';
      }
    text2[0]=':';
       flag2=flag2+1;
    if (text2[1]=='O') flag2=0;

    lcd.setCursor(0,0);
    lcd.print("PT1");
    lcd.setCursor(3,0);
    lcd.print(text);
    lcd.setCursor(15,0);
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print("PT2");
    lcd.setCursor(3,1);
    lcd.print(text2);
    lcd.setCursor(15,1);
    lcd.print(" ");

    if (analogRead(A1)>800)
    {
     flag1=-30;
     flag2=-30;
     analogWrite(A0,0);
     }
   if (flag1>0 || flag2>0 )
   {
    analogWrite(A0,600);
    }
    delay(2000);
  }
delay(1000);
lcd.display();
lcd.clear();
}
