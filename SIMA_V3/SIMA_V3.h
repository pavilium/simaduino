/******************************************************************************
* SIMA Project - Manual Test
* 
* @version 2016
* @author José Polanco
* https://github.com/urayi
******************************************************************************/
#ifndef Simatest_H
#define Simatest_H

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <Servo.h>
////////////////////////////
// Definitions            //
////////////////////////////
//#define L1_PIN 9	//Tobillo Izquierdo
//#define L2_PIN 10	//Rodilla Izquierda
//#define L3_PIN 11	//Cadera Izquierda
//#define L4_PIN 12	//Hombro Izquierdo
//#define L5_PIN 13	//Codo Izquierdo
//#define R1_PIN 4	//Tobillo Derecho
//#define R2_PIN 5	//Rodilla Derecha
//#define R3_PIN 6	//Cadera Derecha
//#define R4_PIN 7	//Hombro Derecho
//#define R5_PIN 8	//Codo Derecho
//define BAT_PIN A0	//Sensor de nivel de la batería
//#define FORWARD     1
//#define BACKWARD    -1
//#define LEFT        1
//#define RIGHT       -1

class SIMA
{
public:
	////////////////////////////
	// Enumerations           //
	////////////////////////////

	////////////////////////////
	// Variables              //
	////////////////////////////

	////////////////////////////
	// Functions              //
	////////////////////////////
	/*Las variables de las funciones se defines y se le asignan valores predeterminados*/
	//-- Zowi initialization
    //void init(byte L1_PIN, byte L2_PIN, byte L3_PIN, byte L4_PIN, byte L5_PIN, byte R1_PIN, byte R2_PIN, byte R3_PIN, byte R4_PIN, byte R5_PIN, bool load_calibration=true);
	/*1---> Simatest - Control individual de articulaciones*/
	int Simatest(int cmd, Servo articulacion[], int angulo[]);//Retornará el angulo final
	/*2---> Funciones de Movimiento*/
	//Recibe los datos de la secuencia de movimiento 
	int* mover(int cmd, Servo articulacion[], int angulo[], int orden[], int movimiento[][8], int filas);
	//camina, giro, curva, saludo, balanceo - Controles basicos para desplazamiento
	int control(int cmd, Servo articulacion[], int angulo[]);
	
	
    //void shakeLeg (int steps=1, int T = 2000, int dir=RIGHT); Sacudir la Pierna
    //void jump(float steps=1, int T = 2000);
    //void updown(float steps=1, int T=1000, int h = 20);//Agacharse y estirarse
    //void swing(float steps=1, int T=1000, int h=20);
    //void tiptoeSwing(float steps=1, int T=900, int h=20);
    //void jitter(float steps=1, int T=500, int h=20);//nervioso
    //void ascendingTurn(float steps=1, int T=900, int h=20);

    //void moonwalker(float steps=1, int T=900, int h=20, int dir=LEFT);
    //void crusaito(float steps=1, int T=900, int h=20, int dir=FORWARD);
    //void flapping(float steps=1, int T=1000, int h=20, int dir=FORWARD);Aleteo
	
	//-- Battery
    float niveldeBateria();
    float voltajeBateria();

private:
	////////////////////////////
	// Enumerations           //
	////////////////////////////
	
	
	////////////////////////////
	// Variables              //
	////////////////////////////

	
	////////////////////////////
	// Functions              //
	////////////////////////////
	
};

#endif // Simatest_H //
