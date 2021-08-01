uint8_t buf[8] = { 0 };

int len = 4;
int inputs[] = {7, 6, 5, 4};
int keys[] = {80, 81, 82, 79};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < len; i++) {
    pinMode(inputs[i], INPUT);
    digitalWrite(inputs[i], 1);
  }
  delay(200);
}

void loop() {
  for (int i = 0; i < len; i++) {
    if (digitalRead(inputs[i]) != 1) {
      buf[2+i] = keys[i];
    } else {
      buf[2+i] = 0;
    }
  }
  buf[0] = 0;
  Serial.write(buf, 8);
}
