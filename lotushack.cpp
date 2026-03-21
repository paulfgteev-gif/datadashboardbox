#include <Arduino.h>


const int RED_LED = 10;
const int GREEN_LED = 11;
const int YELLOW_LED = 12;

void allOff() {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
}

void setup() {
    Serial.begin(115200);
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    
    // Test blink so you know it's powered on
    allOff();
}

void loop() {
    if (Serial.available() > 0) {
        char command = Serial.read();
        
        // Mutual Exclusion: Turn others off first
        allOff();

        if (command == 'R') {
            digitalWrite(RED_LED, HIGH);
        } else if (command == 'G') {
            digitalWrite(GREEN_LED, HIGH);
        } else if (command == 'Y') {
            digitalWrite(YELLOW_LED, HIGH);
        }
    }
}