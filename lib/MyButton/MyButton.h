#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <Arduino.h>

#define MYBUTTON_NO_CLICK 0
#define MYBUTTON_SHORT_CLICK 2
#define MYBUTTON_LONG_CLICK 3
#define MYBUTTON_DOUBLE_CLICK 4

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
