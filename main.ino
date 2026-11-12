int GSMOne = 0;
int inOne = 0;
int inTwo = 0;

int GSMTwo = 0;
int inThree = 0;
int inFour = 0;

Motor links;
Motor rechts;

// TODO: INIT VALUES
void setup() {
  links = new Motor(GSMOne, inOne, inTwo);
  rechts = new Motor(GSMTwo, inThree, inFour);

  pinMode(GSMOne, OUPUT);
  pinMode(in1, OUPUT);
  pinMode(in2, OUTPUT);
}

void SetMotor(Motor motor, int speed) {
  speed = constrain(speed, -255, 255);

  if (speed > 0) {
    motor.Vor();
    analogWrite(motor.attachedMotor, speed);
  }
  else if (speed < 0) {
    motor.Rue();
    analogWrite(motor.attachedMotor, speed * -1);
  }
  else if (speed == 0) {
    motor.Aus();
  }
}

class Motor {
  Motor(int attachedMotor, int attachedOne, int attachedTwo) {
    this.attachedMotor = attachedMotor;
    this.attachedOne = attachedOne;
    this.attachedTwo = attachedTwo;
  }

  int attachedMotor;
  int attachedOne;
  int attachedTwo;

  void Vor() {
    digitalWrite(attachedOne, HIGH);
    digitalWrite(attachedTwo, LOW);
  }

  void Rue() {
    digitalWrite(attachedOne, LOW);
    digitalWrite(attachedTwo, HIGH);
  }

  void Aus() {
    digitalWrite(attachedOne, LOW);
    digitalWrite(attachedTwo, LOW);
  }
}

bool HindernisVorne() {
  return true;
}