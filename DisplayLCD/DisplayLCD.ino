/*CODIGOS DEL DISPLAY LCD*/


//LIBRERIAS NECESARIAS PARA EL PROYECTO
#include <Wire.h>  
#include <LiquidCrystal.h>

//Creacion de objeto display (RS,E,D3,D2,D1,D0)
LiquidCrystal lcd(8,9,4,5,6,7);


void setup() {
  //INICIO COMUNICACION CON EL DISPLAY
  lcd.begin(16,2);

  //INICIO INTERFAZ I2C COMO ESCLAVO CON DIRECCION 1
  Wire.begin(1);

  //FUNCION A EJECUTAR CUANDO EL MAESTRO ENVIE INSTRUCCIONES
  Wire.onReceive(datoEntrante);
  
  //LIMPIAMOS LA PANTALLA DEL DISPLAY LCD
  lcd.clear();

  //LE DAMOS LA BIENBENIDA AL USUARIO
  lcd.setCursor(4,0);
  lcd.print("Bienvenido");
  lcd.setCursor(5,1);
  lcd.print("usuario");
  delay(2000);

}

void loop() {
  //VACIO  
}


void datoEntrante(){

  int dato = 0;
  
  if(Wire.available() == 1){
    
    dato = Wire.read();
    delay(5);

    if(dato == 0){
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("Modo:");
      lcd.setCursor(3,1);
      lcd.print("Automatico");
    }
    if(dato == 1){
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("Modo:");
      lcd.setCursor(4,1);
      lcd.print("Manual");
    }
  }
}
