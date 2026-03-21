#include <Arduino.h>


const int RED_LED1 = 11;
const int RED_LED2 = 10;
const int RED_LED3 = 9;
const int GREEN_LED1 = 8;
const int GREEN_LED2 = 7;
const int GREEN_LED3 = 6;
const int YELLOW_LED1 = 5;
const int YELLOW_LED2 = 4;
const int YELLOW_LED3 = 3;

void allOff() {
    digitalWrite(RED_LED1, LOW);
    digitalWrite(RED_LED2, LOW);
    digitalWrite(RED_LED3, LOW);
    digitalWrite(GREEN_LED1, LOW);
    digitalWrite(GREEN_LED2, LOW);
    digitalWrite(GREEN_LED3, LOW);
    digitalWrite(YELLOW_LED1, LOW);
    digitalWrite(YELLOW_LED2, LOW);
    digitalWrite(YELLOW_LED3, LOW);
}

void setup() {
    Serial.begin(9600);
    pinMode(RED_LED1, OUTPUT);
    pinMode(RED_LED2, OUTPUT);
    pinMode(RED_LED3, OUTPUT);
    pinMode(GREEN_LED1, OUTPUT);
    pinMode(GREEN_LED2, OUTPUT);
    pinMode(GREEN_LED3, OUTPUT);
    pinMode(YELLOW_LED1, OUTPUT);
    pinMode(YELLOW_LED2, OUTPUT);
    pinMode(YELLOW_LED3, OUTPUT);
}

    

void loop() {
    if (Serial.available() > 0) {
        char command = Serial.read();

        // Mutual Exclusion: Turn others off first
        allOff();

        if (command == 'R') {
            digitalWrite(RED_LED1, HIGH);
            digitalWrite(RED_LED2, HIGH);
            digitalWrite(RED_LED3, HIGH);
        } else if (command == 'G') {
            digitalWrite(GREEN_LED1, HIGH);
            digitalWrite(GREEN_LED2, HIGH);
            digitalWrite(GREEN_LED3, HIGH);
        } else if (command == 'Y') {
            digitalWrite(YELLOW_LED1, HIGH);
            digitalWrite(YELLOW_LED2, HIGH);
            digitalWrite(YELLOW_LED3, HIGH);
        } else if (command == 'N') {
            allOff();
        } else if (command == 'A') {
            digitalWrite(RED_LED1, HIGH);
            digitalWrite(RED_LED2, HIGH);
            digitalWrite(RED_LED3, HIGH);
            digitalWrite(GREEN_LED1, HIGH);
            digitalWrite(GREEN_LED2, HIGH);
            digitalWrite(GREEN_LED3, HIGH);
            digitalWrite(YELLOW_LED1, HIGH);
            digitalWrite(YELLOW_LED2, HIGH);
            digitalWrite(YELLOW_LED3, HIGH);
        }
        
    }
}