# MyButton

Une bibliothèque simple pour gérer les boutons sur Arduino/ESP32.

## Fonctionnalités

- Anti-rebond intégré
- Détection de clic simple
- Détection de double-clic
- Détection d'appui long

## Exemple avec 2 LEDs

L'exemple montre comment utiliser la bibliothèque avec 2 LEDs :

- Clic simple : LED1 s'allume
- Double clic : LED2 s'allume
- Appui long : Les deux LEDs s'allument
- Aucun clic : Les deux LEDs sont éteintes

## Configuration

Vous pouvez ajuster :
- Le délai anti-rebond (50ms par défaut)
- La durée pour l'appui long (1000ms par défaut)
- Le délai maximum pour le double-clic (400ms par défaut)
