/**
 * --------------------------------------------------------------------------------------------------------------------
 * Example sketch/program showing how to read data from more than one PICC to serial.
 * --------------------------------------------------------------------------------------------------------------------
 * This is a MFRC522 library example; for further details and other examples see: https://github.com/miguelbalboa/rfid
 *
 * Example sketch/program showing how to read data from more than one PICC (that is: a RFID Tag or Card) using a
 * MFRC522 based RFID Reader on the Arduino SPI interface.
 *
 * Warning: This may not work! Multiple devices at one SPI are difficult and cause many trouble!! Engineering skill
 *          and knowledge are required!
 *
 * @license Released into the public domain.
 *
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS 1    SDA(SS)      ** custom, take a unused pin, only HIGH/LOW required **
 * SPI SS 2    SDA(SS)      ** custom, take a unused pin, only HIGH/LOW required **
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 *
 * More pin layouts for other boards can be found here: https://github.com/miguelbalboa/rfid#pin-layout
 *
 */

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, take a unused pin, only HIGH/LOW required, must be different to SS 2


#define NR_OF_READERS   1

MFRC522 mfrc522(SS_PIN, RST_PIN);    // Create MFRC522 instance.

/**
 * Initialize.
 */
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Put your card to the reader...");
  Serial.println();
  pinMode(7,OUTPUT);
  digitalWrite(7, LOW);
  pinMode(2,OUTPUT);
  digitalWrite(2, LOW);
  pinMode(3,OUTPUT);
  digitalWrite(3, LOW);
  pinMode(4,OUTPUT);
  digitalWrite(4, LOW);
  pinMode(5,OUTPUT);
  digitalWrite(5, LOW);
}

/**
 * Main loop.
 */
void loop() {
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "") {  // example: if (content.substring(1) == "04 A5 B0 92 AF 61 81") {
        Serial.println("Playing 1");
        digitalWrite(7, HIGH);
        delay(500);
        digitalWrite(7, LOW);
      }
      else {
        digitalWrite(7, LOW);
      }
  if (content.substring(1) == "") {  // RFID 2
        Serial.println("Playing 2");
        digitalWrite(2, HIGH);
        delay(500);
        digitalWrite(2, LOW);
      }
      else {
        digitalWrite(2, LOW);
      }
  if (content.substring(1) == "") {  // RFID 3
        Serial.println("Playing 3");
        digitalWrite(3, HIGH);
        delay(500);
        digitalWrite(3, LOW);
      }
      else {
        digitalWrite(3, LOW);
      }
  if (content.substring(1) == "") {  // RFID 4
        Serial.println("Playing 4");
        digitalWrite(4, HIGH);
        delay(500);
        digitalWrite(4, LOW);
      }
      else {
        digitalWrite(4, LOW);
      }
  if (content.substring(1) == "") {  // RFID 5
        Serial.println("Playing 5");
        digitalWrite(5, HIGH);
        delay(500);
        digitalWrite(5, LOW);
      }
      else {
        digitalWrite(5, LOW);
      }


     // Halt PICC
      mfrc522.PICC_HaltA();
      // Stop encryption on PCD
      mfrc522.PCD_StopCrypto1();
     //if (mfrc522[reader].PICC_IsNewC
   //for(uint8_t reader
}

/**
 * Helper routine to dump a byte array as hex values to Serial.
 */
void dump_byte_array(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}
