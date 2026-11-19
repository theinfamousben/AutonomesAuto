class Motor {
  public: // Alles darunter darf von außen (setup, loop, SetMotor) benutzt werden
    int attachedA;
    int attachedB;
    void speed(int speed) {
      speed = constrain(speed, -255, 255);

      if (speed > 0) {
        analogWrite(attachedA, speed);
        analogWrite(attachedB, 0);
      }
      else if (speed < 0) {
        analogWrite(attachedA, 0);
        analogWrite(attachedB, -speed);
      }
      else {
        analogWrite(attachedA, 0);
        analogWrite(attachedB, 0);
      }
    }

    Motor(int attachedA, int attachedB) {
      this->attachedA = attachedA;
      this->attachedB = attachedB;
    }
};

const int rechtsA = 0;
const int rechtsB = 1;
const int linksA = 2;
const int linksB = 3;

Motor links(linksA, linksB);
Motor rechts(rechtsA, rechtsB);

void setup() {
  // Pins für Motor 1 als Ausgang setzen
  links.speed(100);
  rechts.speed(100);

  // Pins für Motor 2 als Ausgang setzen (hatten noch gefehlt)
  pinMode(rechtsA, OUTPUT);
  pinMode(rechtsB, OUTPUT);

  Serial.begin(9600);  
}

void loop() {
  //SetMotor(links, 255);
  //SetMotor(rechts, 245); // Kleines "r", passend zur Variable oben

  Serial.print("Notenpunkte: ");
  Serial.println(NotenPunkte()); 
}

int NotenPunkte() {
  return 15;
}

bool HindernisVorne() {  // todo
  return true;
}
