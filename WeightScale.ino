#include "HX711.h"

const int dout = 2; const int sck = 3;

HX711 bilancia(2, 3);

int peso = 0; // zona di memorizzazione del peso corrente int pesoprec = 0; // zona di memorizzazione dell'ultimo peso esposto void setup() { Serial.begin(9600);

Serial.println("calcolo della tara"); Serial.println("non porre alcun oggetto sulla bilancia....."); delay (100); bilancia.set_scale(-224.16); // <---- valore di scala, scale value --------

bilancia.tare(30); // il peso attuale e' considerato tara Serial.println("sistema pronto"); } void loop() { peso = bilancia.get_units(20); if (!(peso == pesoprec)) // se e' variato il peso { pesoprec = peso; // memorizza il peso corrente Serial.print("peso: "); Serial.print(peso); Serial.println("g"); } delay(200); }
