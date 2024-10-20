#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define output A0
/*#define SCK 13
#define MISO 12
#define MOSI 11
#define CNS 9 */
#define CE 8
#define CNS 7

RF24 radio(CE, CNS);  //Define radio object
const byte address[6] = "001100";
int recievedParameter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pinMode(output, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(analogRead(output));
  recievedParameter = 0;
  if (radio.available()){
    radio.read(&recievedParameter, sizeof(recievedParameter));
  }
  Serial.println(recievedParameter);
  analogWrite(output, recievedParameter/4);
}
