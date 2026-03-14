#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Configuración del Keypad (ajusta pines según tu conexión)
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Configuración LCD I2C (dirección común: 0x27 o 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Contraseña correcta 
String password = "1231";
String inputPassword;

// Servomotor en pin 13
Servo servoMotor;
const int servoPin = 13;

// Pines para los LEDs
const int ledVerde = 11;  // LED verde para acceso concedido
const int ledRojo = 12;   // LED rojo para acceso denegado

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("Ingrese clave:");
  
  // Configurar servo
  servoMotor.attach(servoPin);
  servoMotor.write(180); // Posición inicial cerrada (180°)
  
  // Configurar pines de salida para LEDs
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  
  // Estado inicial LEDs (rojo siempre encendido)
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledRojo, HIGH);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '#') { // Tecla para borrar
      inputPassword = "";
      lcd.clear();
      lcd.print("Ingrese clave:");
      // Mantener rojo encendido y apagar verde
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledRojo, HIGH);
    } else if (key == '*') { // Tecla para validar
      if (inputPassword == password) {
        lcd.clear();
        lcd.print("Acceso concedido");
        // Mover servo a posición abierta (90°)
        servoMotor.write(90);
        // Encender LED verde y apagar rojo
        digitalWrite(ledVerde, HIGH);
        digitalWrite(ledRojo, LOW);
        delay(4000); // 4 segundos de acceso
        
        // Reiniciar todo el sistema
        servoMotor.write(180); // Cerrar servo
        digitalWrite(ledVerde, LOW); // Apagar verde
        digitalWrite(ledRojo, HIGH); // Encender rojo de nuevo
        inputPassword = "";
        lcd.clear();
        lcd.print("Ingrese clave:");
      } else {
        lcd.clear();
        lcd.print("Clave incorrecta");
        // Parpadear LED rojo (3 veces)
        for(int i = 0; i < 3; i++) {
          digitalWrite(ledRojo, LOW);
          delay(200);
          digitalWrite(ledRojo, HIGH);
          delay(200);
        }
        inputPassword = "";
        lcd.clear();
        lcd.print("Ingrese clave:");
      }
    } else {
      inputPassword += key;
      lcd.clear();
      lcd.print("Ingrese clave:");
      lcd.setCursor(0, 1);
      lcd.print(inputPassword); // Muestra lo digitado
      // Mantener rojo encendido y apagar verde
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledRojo, HIGH);
    }
  }
}