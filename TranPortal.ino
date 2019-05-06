2int potpin = 0;
int Terminal = 4;
int Stop1 = 3;
int Stop2 = 2;
int Stop3 = 6;
int Stop4 = 5;
int buzzer = 8;
int Finalstop = 7;

void setup() {
  pinMode(Terminal, OUTPUT);
  pinMode(Stop1, OUTPUT);
  pinMode(Stop2, OUTPUT);
  pinMode(Stop3, OUTPUT);
  pinMode(Stop4, OUTPUT);
  pinMode(Finalstop, OUTPUT);
  Serial.begin(9600);
}

int val = 0;
int getStop() {
  val = analogRead(potpin);
  if (val < 135 && val > 0) {
    return 0;
  }
  else if (val < 270 && val > 135) {
    return 1;
  }
  else if (val < 405 && val > 270) {
    return 2;

  }

  else if (val < 540 && val > 405) {
    return 3;
  }
  else if (val < 675 && val > 540) {
    return 4;
  }

  else if (val < 810 && val > 675) {
    return 5;
  }
}

void updatelights(int stop) {
  digitalWrite(Terminal, HIGH);
  digitalWrite(Stop1, stop > 0 ? HIGH : LOW);
  digitalWrite(Stop2, stop > 1 ? HIGH : LOW);
  digitalWrite(Stop3, stop > 2 ? HIGH : LOW);
  digitalWrite(Stop4, stop > 3 ? HIGH : LOW);
  digitalWrite(Finalstop, stop > 4 ? HIGH : LOW);
}
void updatebuzzer(int stop) {
  tone(buzzer, 5000, 500);
  tone(buzzer, 3000, 500);
}

void flashlight(int pin) {
  for (int x = 0; x < 10; x++) {
    digitalWrite(pin, LOW);
    delay(100);
    digitalWrite(pin, HIGH);
    delay(100);
  }
}
  int currentStop;
  void loop() {
    int nextStop = getStop();
    updatelights(nextStop);
    if (currentStop != nextStop) {
      updatebuzzer(currentStop);
if (nextStop == 1){
  flashlight (Stop1);
    }
    if (nextStop == 2){
  flashlight (Stop2);
    }
    if (nextStop == 3){
  flashlight (Stop3);
    }
    if (nextStop == 4){
  flashlight (Stop4);
    }
    currentStop = nextStop;
  }

  delay(100);
}
