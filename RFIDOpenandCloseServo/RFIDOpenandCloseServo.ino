#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define RST_PIN D1
#define SDA_PIN D2

Servo myServo;
MFRC522 mfrc522(SDA_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  myServo.attach(0);
  Serial.println("Put your card to the reader...");
}

void close(){
  myServo.write(180);
}

void open(){
  myServo.write(0);
  delay(3000);
  myServo.write(180);
}

void loop() {
  if(!mfrc522.PICC_IsNewCardPresent()){
    return;
  }

  if(!mfrc522.PICC_ReadCardSerial()){
    return;
  }

  Serial.print("UID tag :");
  String content = "";
  byte letter;

  for(byte i = 0; i < mfrc522.uid.size; i++){
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  Serial.println();
  Serial.print("Pesan : ");
  content.toUpperCase();

  if(content.substring(1) == "5E B8 E1 2B"){
    Serial.println("Kartu cocok");
    Serial.println();
    delay(1000);
    open();
  }

  else if(content.substring(1) == "56 67 7B AC"){
    Serial.println("Kartu Tidak Cocok");
    Serial.println();
    delay(1000);
  }

  else{
    Serial.println("Kartu Tidak cocok");
    delay(1000);
  }

}
