#define TONGUE 13
int i=0;
void setup() {
  Serial.begin(115200);
  pinMode(TONGUE, OUTPUT);
  digitalWrite(TONGUE, HIGH);

}

void loop() {
  Serial.println(String(i));
  if(i>100){
    digitalWrite(TONGUE, LOW);
  }
  i++;
  delay(100);
}
