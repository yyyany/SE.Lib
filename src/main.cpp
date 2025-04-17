#include <Arduino.h>
#include "MyButton.h"

const int GPIO_BUTTON_TO_USE = 15;

#define MYBUTTON_NO_CLICK 0
#define MYBUTTON_SHORT_CLICK 2
#define MYBUTTON_LONG_CLICK 3
#define MYBUTTON_DOUBLE_CLICK 4

// Création d'une instance de MyButtonn
MyButton myButton(GPIO_BUTTON_TO_USE, INPUT_PULLDOWN);

void setup()
{
    Serial.begin(9600);
    Serial.println(F("\nExemple d'utilisation d'un bouton avec la classe MyButton"));    
}

void loop()
{
    int buttonAction = myButton.checkMyButton();
    switch (buttonAction)
    {
    case MYBUTTON_SHORT_CLICK:
        Serial.println("Relâché (court)");
        break;
    case MYBUTTON_LONG_CLICK:
        Serial.println("Appui long");
        break;
    case MYBUTTON_DOUBLE_CLICK:
        Serial.println("Double clic");
        break;
    default:
        break;
    }
}