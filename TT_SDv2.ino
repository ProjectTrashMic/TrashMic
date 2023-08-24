#include "SD.h"
#define SD_ChipSelectPin 8 // check to make sure this works
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

const int rfid_1 = 7;
const int rfid_2 = 2;
const int rfid_3 = 3;
const int rfid_4 = 4;
const int rfid_5 = 5;
const int LED = 6;
int rfidpulseState_1 = 0;
int rfidpulseState_2 = 0;
int rfidpulseState_3 = 0;
int rfidpulseState_4 = 0;
int rfidpulseState_5 = 0;
int ranNum1 = 0;
int ranNum2 = 0;
int ranNum3 = 0;
int ranNum4 = 0;
int ranNum5 = 0;

void setup(){

pinMode(7,INPUT);
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);

pinMode(6,OUTPUT);
digitalWrite(LED, LOW);
  
tmrpcm.speakerPin = 9;
Serial.begin(9600);
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
return;
}
Serial.begin(9600);
tmrpcm.stopPlayback();
tmrpcm.setVolume(6);
//randomSeed(analogRead(0));
tmrpcm.loop(0);
}

void loop(){  

  rfidpulseState_1 = digitalRead(rfid_1);
  rfidpulseState_2 = digitalRead(rfid_2);
  rfidpulseState_3 = digitalRead(rfid_3);
  rfidpulseState_4 = digitalRead(rfid_4);
  rfidpulseState_5 = digitalRead(rfid_5);

  if (rfidpulseState_1 == HIGH)
     {
      ranNum1 = random(1,11);
     }
  if (rfidpulseState_2 == HIGH)
     {
      ranNum2 = random(1,11);
     }
  if (rfidpulseState_3 == HIGH)
     {
      ranNum3 = random(1,11);
     }
  if (rfidpulseState_4 == HIGH)
     {
      ranNum4 = random(1,11);
     }
  if (rfidpulseState_5 == HIGH)
     {
      ranNum5 = random(1,11);
     }
     
  if (ranNum1 != 0)
    { if (ranNum1 == 1)
      {
      tmrpcm.play("j1.wav");
      }
      else if (ranNum1 == 2)
      {
      tmrpcm.play("j2.wav");
      }
      else if (ranNum1 == 3)
      {
      tmrpcm.play("j3.wav");
      }
      else if (ranNum1 == 4)
      {
      tmrpcm.play("j4.wav");
      }
      else if (ranNum1 == 5)
      {
      tmrpcm.play("j5.wav");
      }
      else if (ranNum1 == 6)
      {
      tmrpcm.play("j6.wav");
      }
      else if (ranNum1 == 7)
      {
      tmrpcm.play("j7.wav");
      }
      else if (ranNum1 == 8)
      {
      tmrpcm.play("j8.wav");
      }
      else if (ranNum1 == 9)
      {
      tmrpcm.play("j9.wav");
      }
      else if (ranNum1 == 10)
      {
      tmrpcm.play("j10.wav");
      }
      while (tmrpcm.isPlaying() && ranNum1 != 0)
      {
        digitalWrite(LED, HIGH);
        
        if (digitalRead(rfid_1) == HIGH)
        {
        ranNum1 = random(1,11); break;
        }
        if (digitalRead(rfid_2) == HIGH)
        {
        ranNum2 = random(1,11); 
        ranNum1 = 0; break;
        }
        if (digitalRead(rfid_3) == HIGH)
        {
        ranNum3 = random(1,11); 
        ranNum1 = 0; break;
        }
        if (digitalRead(rfid_4) == HIGH)
        {
        ranNum4 = random(1,11); 
        ranNum1 = 0; break;
        }
        if (digitalRead(rfid_5) == HIGH)
        {
        ranNum5 = random(1,11); 
        ranNum1 = 0; break;
        }
      }
    }

  else if (ranNum2 != 0)
  
    { 
      if (ranNum2 == 1)
      {
      tmrpcm.play("c1.wav");
      }
      else if (ranNum2 == 2)
      {
      tmrpcm.play("c2.wav");
      }
      else if (ranNum2 == 3)
      {
      tmrpcm.play("c3.wav");
      }
      else if (ranNum2 == 4)
      {
      tmrpcm.play("c4.wav");
      }
      else if (ranNum2 == 5)
      {
      tmrpcm.play("c5.wav");
      }
      else if (ranNum2 == 6)
      {
      tmrpcm.play("c6.wav");
      }
      else if (ranNum2 == 7)
      {
      tmrpcm.play("c7.wav");
      }
      else if (ranNum2 == 8)
      {
      tmrpcm.play("c8.wav");
      }
      else if (ranNum2 == 9)
      {
      tmrpcm.play("c9.wav");
      }
      else if (ranNum2 == 10)
      {
      tmrpcm.play("c10.wav");
      }
      while (tmrpcm.isPlaying() && ranNum2 != 0)
      {
        digitalWrite(LED, HIGH);
        
        if (digitalRead(rfid_1) == HIGH)
        {
        ranNum1 = random(1,11); 
        ranNum2 = 0; break;
        }
        if (digitalRead(rfid_2) == HIGH)
        {
        ranNum2 = random(1,11); break;
        }
        if (digitalRead(rfid_3) == HIGH)
        {
        ranNum3 = random(1,11); 
        ranNum2 = 0; break;
        }
        if (digitalRead(rfid_4) == HIGH)
        {
        ranNum4 = random(1,11); 
        ranNum2 = 0; break;
        }
        if (digitalRead(rfid_5) == HIGH)
        {
        ranNum5 = random(1,11); 
        ranNum2 = 0; break;
        }
      }
    }

    
  else if (ranNum3 != 0)
  
    { 
      if (ranNum3 == 1)
      {
      tmrpcm.play("g1.wav");
      }
      else if (ranNum3 == 2)
      {
      tmrpcm.play("g2.wav");
      }
      else if (ranNum3 == 3)
      {
      tmrpcm.play("g3.wav");
      }
      else if (ranNum3 == 4)
      {
      tmrpcm.play("g4.wav");
      }
      else if (ranNum3 == 5)
      {
      tmrpcm.play("g5.wav");
      }
      else if (ranNum3 == 6)
      {
      tmrpcm.play("g6.wav");
      }
      else if (ranNum3 == 7)
      {
      tmrpcm.play("g7.wav");
      }
      else if (ranNum3 == 8)
      {
      tmrpcm.play("g8.wav");
      }
      else if (ranNum3 == 9)
      {
      tmrpcm.play("g9.wav");
      }
      else if (ranNum3 == 10)
      {
      tmrpcm.play("g10.wav");
      }
      while (tmrpcm.isPlaying() && ranNum3 != 0)
      {
        digitalWrite(LED, HIGH);
        
        if (digitalRead(rfid_1) == HIGH)
        {
        ranNum1 = random(1,11); 
        ranNum3 = 0; break;
        }
        if (digitalRead(rfid_2) == HIGH)
        {
        ranNum2 = random(1,11); 
        ranNum3 = 0; break;
        }
        if (digitalRead(rfid_3) == HIGH)
        {
        ranNum3 = random(1,11); break;
        }
        if (digitalRead(rfid_4) == HIGH)
        {
        ranNum4 = random(1,11); 
        ranNum3 = 0; break;
        }
        if (digitalRead(rfid_5) == HIGH)
        {
        ranNum5 = random(1,11); 
        ranNum3 = 0; break;
        }
      }
    }

  else if (ranNum4 != 0)
  
    { 
      if (ranNum4 == 1)
      {
      tmrpcm.play("m1.wav");
      }
      else if (ranNum4 == 2)
      {
      tmrpcm.play("m2.wav");
      }
      else if (ranNum4 == 3)
      {
      tmrpcm.play("m3.wav");
      }
      else if (ranNum4 == 4)
      {
      tmrpcm.play("m4.wav");
      }
      else if (ranNum4 == 5)
      {
      tmrpcm.play("m5.wav");
      }
      else if (ranNum4 == 6)
      {
      tmrpcm.play("m6.wav");
      }
      else if (ranNum4 == 7)
      {
      tmrpcm.play("m7.wav");
      }
      else if (ranNum4 == 8)
      {
      tmrpcm.play("m8.wav");
      }
      else if (ranNum4 == 9)
      {
      tmrpcm.play("m9.wav");
      }
      else if (ranNum4 == 10)
      {
      tmrpcm.play("m10.wav");
      }
      while (tmrpcm.isPlaying() && ranNum4 != 0)
      {
        digitalWrite(LED, HIGH);
        
        if (digitalRead(rfid_1) == HIGH)
        {
        ranNum1 = random(1,11); 
        ranNum4 = 0; break;
        }
        if (digitalRead(rfid_2) == HIGH)
        {
        ranNum2 = random(1,11); 
        ranNum4 = 0; break;
        }
        if (digitalRead(rfid_3) == HIGH)
        {
        ranNum3 = random(1,11); 
        ranNum4 = 0; break;
        }
        if (digitalRead(rfid_4) == HIGH)
        {
        ranNum4 = random(1,11); break;
        }
        if (digitalRead(rfid_5) == HIGH)
        {
        ranNum5 = random(1,11); 
        ranNum4 = 0; break;
        }
      }
    }

  else if (ranNum5 != 0)
  
    { 
      if (ranNum5 == 1)
      {
      tmrpcm.play("ch1.wav");
      }
      else if (ranNum5 == 2)
      {
      tmrpcm.play("ch2.wav");
      }
      else if (ranNum5 == 3)
      {
      tmrpcm.play("ch3.wav");
      }
      else if (ranNum5 == 4)
      {
      tmrpcm.play("ch4.wav");
      }
      else if (ranNum5 == 5)
      {
      tmrpcm.play("ch5.wav");
      }
      else if (ranNum5 == 6)
      {
      tmrpcm.play("ch6.wav");
      }
      else if (ranNum5 == 7)
      {
      tmrpcm.play("ch7.wav");
      }
      else if (ranNum5 == 8)
      {
      tmrpcm.play("ch8.wav");
      }
      else if (ranNum5 == 9)
      {
      tmrpcm.play("ch9.wav");
      }
      else if (ranNum5 == 10)
      {
      tmrpcm.play("ch10.wav");
      }
      while (tmrpcm.isPlaying() && ranNum5 != 0)
      {
        digitalWrite(LED, HIGH);
        
        if (digitalRead(rfid_1) == HIGH)
        {
        ranNum1 = random(1,11); 
        ranNum5 = 0; break;
        }
        if (digitalRead(rfid_2) == HIGH)
        {
        ranNum2 = random(1,11); 
        ranNum5 = 0; break;
        }
        if (digitalRead(rfid_3) == HIGH)
        {
        ranNum3 = random(1,11); 
        ranNum5 = 0; break;
        }
        if (digitalRead(rfid_4) == HIGH)
        {
        ranNum4 = random(1,11); 
        ranNum5 = 0; break;
        }
        if (digitalRead(rfid_5) == HIGH)
        {
        ranNum5 = random(1,11); break;
        }
      }
    }
    
  Serial.print(digitalRead(rfid_1));
  Serial.print(digitalRead(rfid_2));  
  Serial.print(digitalRead(rfid_3));  
  Serial.print(digitalRead(rfid_4));  
  Serial.println(digitalRead(rfid_5));

  
  ranNum1 = 0;
  ranNum2 = 0;
  ranNum3 = 0;
  ranNum4 = 0;
  ranNum5 = 0;
  digitalWrite(LED, LOW);
  }
