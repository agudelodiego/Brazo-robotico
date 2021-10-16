/*****************************BRAZO ROBPTICO*********************************
  Descripcion:
    El brazo robotico tiene la capacidad de operar tanto de manera automatica
    ejecutando una serie de instrucciones previamente determinadas, como de
    manera manual mediante un centro de mando conformado por una serie de
    pulsadores y joysticks

  El presente proyecto fue desarrollado por:
    - Juan Fernando Echeverri  -->
    - Juan Esteban Moreno Restrepo  -->
    - Diego Alexander Agudelo Garcia  --> agudelodiego22@gmail.com*/




//Librerias necesarias
#include <Servo.h>


/*DECLARACION DE OBJETOS DE TIPO SERVO*/
Servo base;
Servo hombro;
Servo codo;
Servo manoX;
Servo manoY;
Servo pinza;


/*VARIAEBLES ENCARGADAS DE CONTROLAR LOS SERVOS*/
byte p_base = 90;
byte p_hombro = 90;
byte p_codo = 90;
byte p_manoX = 90;
byte p_manoY = 90;
byte p_pinza = 90;


/*VARIABLES ENCARGADAS DE CONTROLAR EL MODO DE OPERACION*/
byte operacion = 3;


/*PULSADORES*/
byte suma_manoY = 30;
byte resta_manoY = 31;
byte suma_pinza = 5;
byte resta_pinza = 4;


void setup() {

  /*INICIALIZACION DE SERVOMOTORES*/
  hombro.attach(6, 1000, 2000);
  base.attach(7, 1000, 2000);
  codo.attach(8, 1000, 2000);
  manoX.attach(9, 1000, 2000);
  manoY.attach(10, 1000, 2000);
  pinza.attach(11, 1000, 2000);


  /*DECLARACION DE PULSADORES*/
  pinMode(suma_manoY, INPUT);
  pinMode(resta_manoY, INPUT);
  pinMode(suma_pinza, INPUT);
  pinMode(resta_pinza, INPUT);
  pinMode(operacion, INPUT);

}

void loop() {

  /*-----ENTRAR CONTROLAR EL BRAZO DE MANERA MANUAL------*/
  if (digitalRead(operacion) == 1){
    manual();    
  }
  /*-----------------------------------------------------*/


  /*-------ENTRAR A RUTINA PREPROGRAMA DEL BRAZO--------*/
  if(digitalRead(operacion) == 0){
    inicial();
  }

}


/*------------------------------------MODO MANUAL-------------------------------------*/
void manual(){

  while (true){

    /*--------------------SERVO BASE----------------------*/
    if (analogRead(0) < 200 && p_base < 180) {
      p_base++;
      base.write(p_base);
      delay(2);
    }
    if (analogRead(0) > 700 && p_base > 0) {
      p_base--;
      base.write(p_base);
      delay(2);
    }
    /*----------------------------------------------------*/


    /*--------------------SERVO HOMBRO--------------------*/
    if (analogRead(1) < 200 && p_hombro < 180) {
      p_hombro++;
      hombro.write(p_hombro);
      delay(2);
    }
    if (analogRead(1) > 700 && p_hombro > 0) {
      p_hombro--;
      hombro.write(p_hombro);
      delay(2);
    }
    /*----------------------------------------------------*/


    /*--------------------SERVO CODO----------------------*/
    if (analogRead(15) < 200 && p_codo < 180) {
      p_codo++;
      codo.write(p_codo);
      delay(2);
    }
    if (analogRead(15) > 700 && p_codo > 0) {
      p_codo--;
      codo.write(p_codo);
      delay(2);
    }
    /*----------------------------------------------------*/


    /*--------------------SERVO MANO X--------------------*/
    if (analogRead(14) < 200 && p_manoX < 180) {
      p_manoX++;
      manoX.write(p_manoX);
      delay(2);
    }
    if (analogRead(14) > 700 && p_manoX > 0) {
      p_manoX--;
      manoX.write(p_manoX);
      delay(2);
    }
    /*----------------------------------------------------*/



    /*---------------------SERVO MANO Y-------------------*/
    if (digitalRead(suma_manoY) == LOW){
      p_manoY++;
      delay(2);
      if (p_manoY >= 180){
        p_manoY = 180;
      }
    }
    if (digitalRead(resta_manoY) == LOW){
      p_manoY--;
      delay(2);
      if (p_manoY <= 0){
        p_manoY = 0;
      }
    }
    manoY.write(p_manoY);
    /*----------------------------------------------------*/


    /*------------------SERVO PINZA-----------------------*/
    if (digitalRead(suma_pinza) == LOW){
      p_pinza++;
      delay(2);
      if (p_pinza >= 90){
        p_pinza = 90;
      }
    }
    if (digitalRead(resta_pinza) == LOW){
      p_pinza--;
      delay(2);
      if (p_pinza <= 0){
        p_pinza = 0;
      }
    }
    pinza.write(p_pinza);
    /*----------------------------------------------------*/

    /*----------------IR AL MODO AUTO---------------------*/
    if(digitalRead(operacion) == 0){
       break;  
    }
    /*----------------------------------------------------*/
    
  }

}
/*------------------------------------------------------------------------------------------------*/






/*-------------------------------------VOLVER A POSICION INICAL------------------------------------*/
void inicial(){

  /*----------------SERO DE LA BASE------------------*/
  if(p_base < 90){
    for(p_base; p_base <= 90; p_base++){
      base.write(p_base);
      delay(2);
    }
  }
  if(p_base > 90){
    for(p_base; p_base >= 90; p_base--){
      base.write(p_base);
      delay(2);
    }
  }
  /*------------------------------------------------*/


  /*---------------SER DEL HOMBRO--------------------*/
  if(p_hombro < 90){
    for(p_hombro; p_hombro <= 90; p_hombro++){
      hombro.write(p_hombro);
      delay(2);
    }
  }
  if(p_hombro > 90){
    for(p_hombro; p_hombro >= 90; p_hombro--){
      hombro.write(p_hombro);
      delay(2);
    }
  }
  /*--------------------------------------------------*/


  /*-----------------SERVO DEL CODO--------------------*/
  if(p_codo < 90){
    for(p_codo; p_codo <= 90; p_codo++){
      codo.write(p_codo);
      delay(2);
    }
  }
  if(p_codo > 90){
    for(p_codo; p_codo >= 90; p_codo--){
      codo.write(p_codo);
      delay(2);
    }
  }
  /*---------------------------------------------------*/


  /*-------------------SERVO MANO X-------------------*/
  if(p_manoX < 90){
    for(p_manoX; p_manoX <= 90; p_manoX++){
      manoX.write(p_manoX);
      delay(2);
    }
  }
  if(p_manoX > 90){
    for(p_manoX; p_manoX >= 90; p_manoX--){
      manoX.write(p_manoX);
      delay(2);
    }
  }
  /*--------------------------------------------------*/


  /*------------------SERVO MANO Y--------------------*/
  if(p_manoY < 90){
    for(p_manoY; p_manoY <= 90; p_manoY++){
      manoY.write(p_manoY);
      delay(2);
    }
  }
  if(p_manoY > 90){
    for(p_manoY; p_manoY >= 90; p_manoY--){
      manoY.write(p_manoY);
      delay(2);
    }
  }
  /*--------------------------------------------------*/


  /*-----------------SERVO DE LA PINZA-----------------*/
  if(p_pinza < 90){
    for(p_pinza; p_pinza <= 90; p_pinza++){
      pinza.write(p_pinza);
      delay(2);
    }
  }
  if(p_pinza > 90){
    for(p_pinza; p_pinza >= 90; p_pinza--){
      pinza.write(p_pinza);
      delay(2);
    }
  }
  /*---------------------------------------------------*/
}
/*------------------------------------------------------------------------------*/
