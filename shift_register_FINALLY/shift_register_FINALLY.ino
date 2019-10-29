
int DS_pin = 8;
int STCP_pin = 9;
int SHCP_pin = 10;


void setup() {
  pinMode(DS_pin, OUTPUT);
  pinMode(STCP_pin, OUTPUT);
  pinMode(SHCP_pin, OUTPUT);
  reg();
}
boolean registerz[8];

void reg() {
  digitalWrite(SHCP_pin, HIGH);
  for (int i = 7; i > 0; i--) {
    digitalWrite(STCP_pin, HIGH);
    digitalWrite(DS_pin, registerz[i]);
    digitalWrite(STCP_pin, LOW);

  }
  digitalWrite(SHCP_pin, LOW);
}
void loop() {
  for (int i = 0; i < 9; i++) {
    registerz[i] = LOW;
    delay(100);
    reg();
  }
  for (int i = 0; i < 9; i++) {
    registerz[i] = HIGH;
    delay(100);
    reg();
  }
}
