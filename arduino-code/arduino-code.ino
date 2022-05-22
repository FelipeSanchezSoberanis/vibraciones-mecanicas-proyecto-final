int pin_pot = A0;
int pin_motor = 6;
int pin_echo = 2;
int pin_trig = 3;

int val_pot;
int val_motor;

int ciclo_trabajo;
long duracion;
int distancia;

void setup() {
    pinMode(pin_trig, OUTPUT);
    pinMode(pin_echo, INPUT);
    pinMode(pin_motor, OUTPUT);
    pinMode(pin_pot, INPUT);

    Serial.begin(9600);
}

void loop() {
    val_pot = 1023 - analogRead(pin_pot);
    val_motor = map(val_pot, 0, 1023, 0, 255);

    analogWrite(pin_motor, val_motor);

    ciclo_trabajo = map(val_pot, 0, 1023, 0, 100);

    digitalWrite(pin_trig, LOW);
    digitalWrite(pin_trig, HIGH);
    digitalWrite(pin_trig, LOW);
    duracion = pulseIn(pin_echo, HIGH);
    distancia = duracion * 0.034 / 2;

    Serial.println(distancia);

    delay(100);
}
