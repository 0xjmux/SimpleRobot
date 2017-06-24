#include <Servo.h>


int inputD = 2;
int inputC = 3;
int inputB = 4;
int inputA = 5;

int servoDelay = 500;
int turnDelay = 300;

Servo leftServo;
Servo rightServo;


void setup() {
  Serial.begin(9600);
  
  pinMode(inputA, INPUT);
  pinMode(inputB, INPUT);
  pinMode(inputC, INPUT);
  pinMode(inputD, INPUT);

  leftServo.attach(6);
  rightServo.attach(9);
  
}

void loop() {
  // read the input pin:
  int Astate = digitalRead(inputA);
  int Bstate = digitalRead(inputB);
  int Cstate = digitalRead(inputC);
  int Dstate = digitalRead(inputD);
  
  Serial.print(Astate);
  Serial.print(" ");
  Serial.print(Bstate);
  Serial.print(" ");
  Serial.print(Cstate);
  Serial.print(" ");
  Serial.println(Dstate);



  if(Astate == 1) {
  forward();
  }

  else if(Bstate == 1) {
  left();
  }

  else if(Cstate == 1) {
    backward();
  }
  else if(Dstate == 1) {
    right();
  }
  
  

  
  delay(10);        // delay in between reads for stability
}



  void forward() {

  rightServo.write(0);
  leftServo.write(180);

  delay(servoDelay);
  rightServo.write(90);
  leftServo.write(90);

}

  void backward() {

  rightServo.write(180);
  leftServo.write(0);

  delay(servoDelay);
  rightServo.write(90);
  leftServo.write(90);
}
    void left() {
    rightServo.write(0);
    leftServo.write(0);

    delay(turnDelay);
  rightServo.write(90);
  leftServo.write(90);
  }


  void right() {
    rightServo.write(180);
    leftServo.write(180);

    delay(turnDelay);
  rightServo.write(90);
  leftServo.write(90);
  
  }





