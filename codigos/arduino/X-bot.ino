
#include <SoftwareSerial.h>
SoftwareSerial SerialBT(2, 3); //estos son RX, TX


int motor1 = 4;
int motor2 = 5;
int motor4 = 6;
int motor3 = 7;


void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("----");
  Serial.println("READY");
  Serial.println("----");
  delay(200);
  SerialBT.begin(9600);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
}

void loop() {
  // se lee la letra enviada via bt
  SerialBT.listen(); 
  if (SerialBT.available() > 0) {
    char state = SerialBT.read();
    Serial.println(state);
    // dependiendo de la letra, realiza la funcion de movimiento correspondiente
    // W: avanzar ; A: izquierda ; S: retroceder ; D: derecha ; p: stop (Basado en las teclas del teclado WASD) 
    if(state=='W') {
      avanzar();
    }
    else if(state=='A') {
      izquierda();
    }
    else if(state=='S') {
      retroceder();
    }
    else if(state=='D') {
      derecha();
    }
    else if(state=='p') {
      stop();
  }
    }
  
}

// FUNCION ENTREGADA EN MATERIAL DOCENTE
void leerSerial() {
  SerialBT.listen(); 
  if (SerialBT.available() > 0) {
    char state = SerialBT.read();
    Serial.println(state);
  }

}

// funcion que detiene el bot
void stop() {
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, HIGH);
}

// funcion que hace que todas las ruedas giren en la misma direccion (hacia adelante)
void avanzar() {
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
}

// funcion que hace que todas las ruedas giren en la misma direccion (hacia atras)
void retroceder() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
}

// funcion que hace que el bot gire a la izquierda
void izquierda() {
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
}

// funcion que hace que el bot gire a la derecha
void derecha() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
}


