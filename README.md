# Arduino Access Control System

This repository contains two languages:

English
Español

---

# English

## Project Overview

This project was originally developed as a high school electronics project.

The goal of the system was to simulate a secure access control mechanism using an Arduino board.

The system allows a user to enter a password through a keypad, verify the password, and then control physical components such as LEDs and a servo motor.

If the password is correct, the system grants access.
If the password is incorrect, the system denies access and signals an error.

---

## Hardware Used

The prototype was built using the following components:

* Arduino board
* 4x4 Keypad
* LCD display (16x2)
* Servo motor
* LEDs (green and red)
* Breadboard
* Jumper wires

---

## System Behavior

The program works as follows:

1. The LCD prompts the user to enter a password.
2. The user types the password using the keypad.
3. The user confirms the input.
4. The system compares the entered password with the stored password.

If the password is correct:

* The LCD displays Access granted
* The green LED turns on
* The servo motor opens
* After a few seconds the system resets

If the password is incorrect:

* The LCD displays Incorrect password
* The red LED flashes
* The system resets for another attempt

---

## Project Structure

```
assets/
    pantalla lcd and arduino ONE.jpeg
    simulador contraseña c++.jpeg

code/
    access_control_system.ino

README.md
```

assets contains images of the project prototype and circuit simulation.

code contains the Arduino source code used in the system.

---

## Project Photos

### Hardware Prototype

<p align="center">
<img src="assets/pantalla lcd and arduino ONE.jpeg" width="550">
</p>

This image shows the physical prototype with the Arduino board and LCD display running.

---

### Circuit Simulation

<p align="center">
<img src="assets/simulador contraseña c++.jpeg" width="550">
</p>

This image shows the circuit design simulation used to plan the wiring before assembling the hardware.

---

## Credits

This project was originally developed as a high school electronics project.

Contributors:

* Zefrik
* Rymon

---

# == ESPAÑOL ==

## Descripción del proyecto

Este proyecto fue desarrollado originalmente como un proyecto de electrónica en la preparatoria.

El objetivo del sistema era simular un mecanismo de control de acceso utilizando una placa Arduino.

El sistema permite que un usuario ingrese una contraseña mediante un teclado, verifique la contraseña y controle componentes físicos como LEDs y un servomotor.

Si la contraseña es correcta, el sistema concede acceso.
Si la contraseña es incorrecta, el sistema deniega el acceso y muestra un error.

---

## Hardware utilizado

El prototipo fue construido utilizando los siguientes componentes:

* Placa Arduino
* Teclado 4x4
* Pantalla LCD 16x2
* Servomotor
* LEDs (verde y rojo)
* Protoboard
* Cables jumper

---

## Funcionamiento del sistema

El programa funciona de la siguiente manera:

1. La pantalla LCD solicita al usuario ingresar una contraseña.
2. El usuario escribe la contraseña usando el teclado.
3. El usuario confirma la entrada.
4. El sistema compara la contraseña ingresada con la contraseña almacenada.

Si la contraseña es correcta:

* La LCD muestra Acceso concedido
* Se enciende el LED verde
* El servomotor se abre
* Después de unos segundos el sistema se reinicia

Si la contraseña es incorrecta:

* La LCD muestra Clave incorrecta
* El LED rojo parpadea
* El sistema se reinicia para otro intento

---

## Fotos del proyecto

### Prototipo físico

<p align="center">
<img src="assets/pantalla lcd and arduino ONE.jpeg" width="550">
</p>

Esta imagen muestra el prototipo físico del sistema con la placa Arduino y la pantalla LCD funcionando.

---

### Simulación del circuito

<p align="center">
<img src="assets/simulador contraseña c++.jpeg" width="550">
</p>

Esta imagen muestra la simulación del circuito utilizada para planear el cableado antes de construir el prototipo.

---

## Créditos

Este proyecto fue desarrollado originalmente como un proyecto de electrónica en la preparatoria.

Contribuyentes:

* Zefrik
* Rymon
