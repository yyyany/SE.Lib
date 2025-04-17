#include "MyButton.h"

// Définition des broches
const int BUTTON_PIN = 0;    // Bouton sur GPIO 0
const int LED1_PIN = 2;      // LED 1 sur GPIO 2
const int LED2_PIN = 4;      // LED 2 sur GPIO 4

// Création de l'objet bouton
MyButton monBouton(BUTTON_PIN, INPUT_PULLUP);

void setup() {
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    int etatBouton = monBouton.checkMyButton();
    
    switch(etatBouton) {
        case MYBUTTON_SHORT_CLICK:
            digitalWrite(LED1_PIN, HIGH);
            digitalWrite(LED2_PIN, LOW);
            break;
            
        case MYBUTTON_DOUBLE_CLICK:
            digitalWrite(LED1_PIN, LOW);
            digitalWrite(LED2_PIN, HIGH);
            break;
            
        case MYBUTTON_LONG_CLICK:
            digitalWrite(LED1_PIN, HIGH);
            digitalWrite(LED2_PIN, HIGH);
            break;
            
        default:
            digitalWrite(LED1_PIN, LOW);
            digitalWrite(LED2_PIN, LOW);
            break;
    }
    
    delay(10);
}
