const int pinR = 10;
const int pinG = 9;
const int pinB = 8;
const int pinSensorIR = 7;
bool IsEscolhido = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);

  pinMode(pinSensorIR, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  int isSensorActive = digitalRead(pinSensorIR);
  Serial.println(isSensorActive);
  
  if (isSensorActive != true && IsEscolhido == false) {
    int numberResult = random(0, 384);
    Serial.println(numberResult);

    if(numberResult <= 128){
        // Verde
        digitalWrite(pinR, 255);
        digitalWrite(pinG, 0);
        digitalWrite(pinB, 255);

      } else if(numberResult <= 256){
        // Vermelho
        digitalWrite(pinR, 0);
        digitalWrite(pinG, 255);
        digitalWrite(pinB, 255);

      } else if(numberResult <= 384){
        // Azul
        digitalWrite(pinR, 255);
        digitalWrite(pinG, 255);
        digitalWrite(pinB, 0);

      }

      IsEscolhido = true;

  }else if(isSensorActive == true){
    IsEscolhido = false;
    //delay(1000);
    ApagarLED();
  }
  // }else{
  //   ApagarLED();
    
  // }

  //delay(250);
  

  // if(isSensorActive == 0){
  //   digitalWrite(pinR, 255);
  //   digitalWrite(pinG, 0);
  //   digitalWrite(pinB, 255);

  // }else{
  //   digitalWrite(pinR, 0);
  //   digitalWrite(pinG, 0);
  //   digitalWrite(pinB, 0);
  // }
  // delay(1000);
}

void ApagarLED(){
  digitalWrite(pinR, 255);
  digitalWrite(pinG, 255);
  digitalWrite(pinB, 255);
}
