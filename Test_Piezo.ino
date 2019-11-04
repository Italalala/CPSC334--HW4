
int vib=0;
int val =0;
int piezo = 12 ;
int prevVib = 0;

void setup() {
  Serial.begin(115200);
  pinMode(piezo, INPUT);
}

void loop() {
  prevVib=vib;
  vib= analogRead(piezo);
  if(vib - prevVib > 100){
    val = vib;
    Serial.println("new reading: " + String(val));
  }
  else{
    val=0;
    Serial.println("reset to zero. Vib reading is: "+ String(val));
  }
  
 delay(200);
}
