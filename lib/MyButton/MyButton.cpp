#include "MyButton.h"

// Initialise le bouton avec son GPIO et son type (pull-up/pull-down)
MyButton::MyButton(int gpioNumber, int typeButton) {
    buttonGPIO = gpioNumber;
    pinMode(buttonGPIO, typeButton); // INPUT, INPUT_PULLDOWN ou INPUT_PULLUP
         
    // Configuration personnalisée du bouton
    setButtonDebounceDelay(DEBOUNCE_DELAY);
    setButtonLongPressDuration(LONG_PRESS_DURATION);
    setButtonDoubleClickMaxDelay(DOUBLE_CLICK_DELAY);

    // Initialisation des variables d'état
    isPressed = DEFAULT_IS_PRESSED;
    lastRawState = DEFAULT_LAST_RAW_STATE;
    lastDebounceTime = DEFAULT_LAST_DEBOUNCE_TIME;
    pressStart = DEFAULT_PRESS_START;
    lastReleaseTime = DEFAULT_LAST_RELEASE_TIME;
    waitingSecondClick = DEFAULT_WAITING_SECOND_CLICK;
    pendingSingleClick = DEFAULT_PENDING_SINGLE_CLICK;
    
    // Valeurs par défaut
    buttonDebounceDelay = DEFAULT_BUTTON_DEBOUNCE_DELAY;
    buttonLongPressDuration = DEFAULT_BUTTON_LONG_PRESS_DURATION;
    buttonDoubleClickMaxDelay = DEFAULT_BUTTON_DOUBLE_CLICK_MAX_DELAY;
}

// Configure le délai anti-rebond en ms
void MyButton::setButtonDebounceDelay(int delay) {
    buttonDebounceDelay = delay;
}

// Configure la durée minimale pour un appui long
void MyButton::setButtonLongPressDuration(int duration) {
    buttonLongPressDuration = duration;
}

// Configure le délai maximum pour un double-clic
void MyButton::setButtonDoubleClickMaxDelay(int delay) {
    buttonDoubleClickMaxDelay = delay;
}

// Vérifie et met à jour l'état du bouton
int MyButton::checkMyButton() {
    bool rawState = digitalRead(buttonGPIO);
    unsigned long now = millis();
    
    // Debounce
    if (rawState != lastRawState) {
        lastDebounceTime = now;
        lastRawState = rawState;
    }
    
    if ((now - lastDebounceTime) > buttonDebounceDelay) {
        if (rawState == HIGH && !isPressed) {
            isPressed = true;
            pressStart = now;
        }
        if (rawState == LOW && isPressed) {
            isPressed = false;
            unsigned long pressDuration = now - pressStart;
            if (pressDuration >= buttonLongPressDuration) {
                waitingSecondClick = false;
                pendingSingleClick = false;
                return MYBUTTON_LONG_CLICK; // Long press
            }
            if (waitingSecondClick) {
                waitingSecondClick = false;
                pendingSingleClick = false;
                return MYBUTTON_DOUBLE_CLICK; // Double click
            }
            else {
                waitingSecondClick = true;
                pendingSingleClick = true;
                lastReleaseTime = now;
            }
        }
    }
    
    // Si on attend un second clic mais que le temps est dépassé
    if (pendingSingleClick && (now - lastReleaseTime > buttonDoubleClickMaxDelay)) {
        pendingSingleClick = false;
        waitingSecondClick = false;
        return MYBUTTON_SHORT_CLICK; // Single click confirmé
    }
    
    return MYBUTTON_NO_CLICK;
}
