#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <Arduino.h>

#define MYBUTTON_NO_CLICK 0
#define MYBUTTON_SHORT_CLICK 2
#define MYBUTTON_LONG_CLICK 3
#define MYBUTTON_DOUBLE_CLICK 4

// Paramètres personnalisés pour le bouton
const int DEBOUNCE_DELAY = 30;         // ms (plus rapide que la valeur par défaut)
const int LONG_PRESS_DURATION = 800;   // ms (plus court que la valeur par défaut)
const int DOUBLE_CLICK_DELAY = 300;    // ms (plus court que la valeur par défaut)

// Constantes pour les valeurs par défaut
const bool DEFAULT_IS_PRESSED = false;
const bool DEFAULT_LAST_RAW_STATE = false;
const unsigned long DEFAULT_LAST_DEBOUNCE_TIME = 0;
const unsigned long DEFAULT_PRESS_START = 0;
const unsigned long DEFAULT_LAST_RELEASE_TIME = 0;
const bool DEFAULT_WAITING_SECOND_CLICK = false;
const bool DEFAULT_PENDING_SINGLE_CLICK = false;
const int DEFAULT_BUTTON_DEBOUNCE_DELAY = 50;        // ms
const int DEFAULT_BUTTON_LONG_PRESS_DURATION = 1000; // ms
const int DEFAULT_BUTTON_DOUBLE_CLICK_MAX_DELAY = 400; // ms

// Classe pour gérer un bouton avec debounce, appui long et double-clic
class MyButton {
private:
    int buttonGPIO;                   
    int buttonDebounceDelay;           
    int buttonLongPressDuration;       
    int buttonDoubleClickMaxDelay;     
    bool isPressed;                  
    bool lastRawState;                 
    unsigned long lastDebounceTime;   
    unsigned long pressStart;          
    unsigned long lastReleaseTime;     
    bool waitingSecondClick;           
    bool pendingSingleClick;          

public:
    //Constructeur de la classe MyButton
    MyButton(int gpioNumber, int typeButton);

    //Configure le délai anti-rebond
    void setButtonDebounceDelay(int delay);

    //Configure la durée minimale pour un appui long
    void setButtonLongPressDuration(int duration);

    //Configure le délai maximum pour détecter un double-clic
    void setButtonDoubleClickMaxDelay(int delay);

    //Vérifie l'état du bouton et gère les différents types d'appuis
    int checkMyButton();
};
#endif
