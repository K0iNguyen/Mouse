#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define signal A2
/*#define SCK 13
#define MISO 12
#define MOSI 11
#define CNS 9 */
#define CE 6
#define CNS 5

RF24 radio(CE, CNS);  //Define radio object
const byte address[6] = "001100";
int transmittedParameter;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  pinMode(signal, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    //Serial.println("Hi\n");
  transmittedParameter = 3;
  radio.write(&transmittedParameter, sizeof(transmittedParameter));
  Serial.println(transmittedParameter);
}
