/******************************************************************************
* SIMA Project - Manual Test
* 
* @version 2016
* @author José Polanco
* https://github.com/urayi
******************************************************************************/

#include "SIMA_V3.h"
#include "Servo.h"
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

	//Servo articulacion[10];
	//int angulo[10];

///////////////////////////////////////
//- FUNCIONES BASICAS DE MOVIMIENTO -//
///////////////////////////////////////
int SIMA::Simatest(int cmd, Servo articulacion[], int angulo[]){	
	if(cmd=='1'||cmd=='2'||cmd=='3'||cmd=='4'){
		if(cmd=='1'){cmd=0;}
		if(cmd=='2'){cmd=1;}
		if(cmd=='3'){cmd=2;}
		if(cmd=='4'){cmd=3;}
		if(cmd=='t'){cmd=4;}
		if(cmd=='y'){cmd=5;}
		if(cmd=='u'){cmd=6;}
		if(cmd=='i'){cmd=7;}
		angulo[cmd]=constrain(angulo[cmd]+1,0,180);
		Serial.println("articulacion\t"+String(cmd)+":\t"+String(angulo[cmd]));
		articulacion[cmd].write(angulo[cmd]);
	}
	if(cmd=='5'||cmd=='6'||cmd=='7'||cmd=='8'){
		if(cmd=='q'){cmd=0;}
		if(cmd=='w'){cmd=1;}
		if(cmd=='e'){cmd=2;}
		if(cmd=='r'){cmd=3;}
		if(cmd=='5'){cmd=4;}
		if(cmd=='6'){cmd=5;}
		if(cmd=='7'){cmd=6;}
		if(cmd=='8'){cmd=7;}
		angulo[cmd]=constrain(angulo[cmd]-1,0,180);
		Serial.println("articulacion\t"+String(cmd)+":\t"+String(angulo[cmd]));
		articulacion[cmd].write(angulo[cmd]);
	}
	if(cmd=='t'||cmd=='y'||cmd=='u'||cmd=='i'){
		if(cmd=='1'){cmd=0;}
		if(cmd=='2'){cmd=1;}
		if(cmd=='3'){cmd=2;}
		if(cmd=='4'){cmd=3;}
		if(cmd=='t'){cmd=4;}
		if(cmd=='y'){cmd=5;}
		if(cmd=='u'){cmd=6;}
		if(cmd=='i'){cmd=7;}
		angulo[cmd]=constrain(angulo[cmd]+1,0,180);
		Serial.println("articulacion\t"+String(cmd)+":\t"+String(angulo[cmd]));
		articulacion[cmd].write(angulo[cmd]);
	}
	if(cmd=='q'||cmd=='w'||cmd=='e'||cmd=='r'){
		if(cmd=='q'){cmd=0;}
		if(cmd=='w'){cmd=1;}
		if(cmd=='e'){cmd=2;}
		if(cmd=='r'){cmd=3;}
		if(cmd=='5'){cmd=4;}
		if(cmd=='6'){cmd=5;}
		if(cmd=='7'){cmd=6;}
		if(cmd=='8'){cmd=7;}
		angulo[cmd]=constrain(angulo[cmd]-1,0,180);
		Serial.println("articulacion\t"+String(cmd)+":\t"+String(angulo[cmd]));
		articulacion[cmd].write(angulo[cmd]);
	}
	return angulo[cmd];
}
/*2---> Funciones de Movimiento*/
int* SIMA::mover(int cmd, Servo articulacion[], int angulo[], int orden[], int movimiento[][8],int filas){
	if(cmd=='c')
	{
	int comparacion = 1;
	//Serial.println(filas);///sizeof(movimiento[0]);
	//int filas = sizeof(movimiento);
	int columnas = 8;
	for(int i = 0; i < filas; i++){	
		tarea:
		for(int j = 0; j < columnas; j++){
			if(angulo[orden[j]] < movimiento[i][orden[j]]){
				angulo[orden[j]] = constrain(angulo[orden[j]]+1, 10, movimiento[i][orden[j]]);
				articulacion[orden[j]].write(angulo[orden[j]]);
//				Serial.println(String(orden[j]) + ":" + String(angulo[orden[j]]));
			}
			if(angulo[orden[j]] > movimiento[i][orden[j]]){
				angulo[orden[j]] = constrain(angulo[orden[j]]-1, movimiento[i][orden[j]], 170);
				articulacion[orden[j]].write(angulo[orden[j]]);
//				Serial.println(String(orden[j]) + ":" + String(angulo[orden[j]]));
			}
		}delay(15);
		for(int k = 0; k < columnas; k++){
			comparacion = angulo[k]-movimiento[i][k];
			if(comparacion != 0){
				goto tarea;
			}
		}
	}
	return angulo;
	}
}
	
//camina, giro y curva - Controles basicos para desplazamiento
int SIMA::control(int cmd, Servo articulacion[], int angulo[]){
	if(cmd=='a')//Adelante
	{
		int movimiento[10][8] = {
			{ 90, 90, 90, 90, 90, 90, 90, 90},//inicio
			{100, 85, 95, 90, 85, 85, 95, 90},//inclino pie izquierdo
			{100, 80,100, 90, 85, 80,100, 90},//adelanto pie derecho
			{ 85, 80,100, 90, 85, 85, 95, 90},//inclino pie derecho
			{ 85, 85, 95, 90, 80, 90, 90, 90},//retroceso pie derecho y adelanto pie izquierdo
			{ 85, 90, 90, 90, 80, 95, 85, 90},//pie izquierdo a posicion cero y adelanto pie derecho
			{ 90, 95, 85, 90, 90,100, 80, 90},//
			{ 90,100, 80, 90, 90,100, 80, 90},//
			{ 90, 95, 85, 90, 90, 95, 85, 90},//
			{ 90, 90, 90, 90, 90, 90, 90, 90} //final
		};
		int orden[8] = {0, 4, 1, 5, 2, 6, 3, 7};
		int filas = sizeof(movimiento)/sizeof(movimiento[0]);
		//Serial.println(filas);
		mover('c', articulacion, angulo, orden, movimiento, filas);
	}
	if(cmd=='s')//Atrás
	{
		int movimiento[6][8] = {
			{ 90, 90, 90, 90, 95, 90, 95, 90},
			{ 85, 95, 80, 90, 90, 95, 85, 90},
			{ 95, 80,100, 90,100, 80,105, 90},
			{ 85, 95, 80, 90, 90, 95, 85, 90},
			{ 95, 80,100, 90,100, 80,105, 90},
			{ 90, 90, 90, 90, 95, 90, 95, 90}
		};
		int orden[8] = {0, 4, 1, 5, 2, 6, 3, 7};
		int filas = sizeof(movimiento)/sizeof(movimiento[0]);
		mover('c', articulacion, angulo, orden, movimiento, filas);
	}
	if(cmd=='d')//Derecha
	{
		int movimiento[6][8] = {
			{ 90, 90, 90, 90, 95, 90, 95, 90},
			{ 90, 90, 90, 90, 90, 95, 85, 90},
			{ 90, 90, 90, 90,100, 80,105, 90},
			{ 90, 90, 90, 90, 90, 95, 85, 90},
			{ 90, 90, 90, 90,100, 80,105, 90},
			{ 90, 90, 90, 90, 95, 90, 95, 90}
		};
		int orden[8] = {0, 4, 1, 5, 2, 6, 3, 7};
		int filas = sizeof(movimiento)/sizeof(movimiento[0]);
		mover('c', articulacion, angulo, orden, movimiento, filas);
	}
	if(cmd=='f')//Izquierda
	{
		int movimiento[6][8] = {
			{ 90, 90, 90, 90, 95, 90, 95, 90},
			{ 85, 95, 85, 90, 95, 90, 95, 90},
			{ 95, 80, 95, 90, 95, 90, 95, 90},
			{ 85, 95, 85, 90, 95, 90, 95, 90},
			{ 95, 80, 95, 90, 95, 90, 95, 90},
			{ 90, 90, 90, 90, 95, 90, 95, 90}
		};
		int orden[8] = {0, 4, 1, 5, 2, 6, 3, 7};
		int filas = sizeof(movimiento)/sizeof(movimiento[0]);
		mover('c', articulacion, angulo, orden, movimiento, filas);
	}
	if(cmd=='g')//Giro Derecha
	{
		int movimiento[6][8] = {
			{ 90, 90, 90, 90, 95, 90, 95, 90},
			{ 90, 90, 90, 90, 95, 95, 85, 90},
			{ 90, 90, 90, 90,105, 80,105, 90},
			{ 90, 90, 90, 90, 95, 95, 85, 90},
			{ 90, 90, 90, 90,105, 80,105, 90},
			{ 90, 90, 90, 90, 95, 90, 95, 90}
		};
		int orden[8] = {0, 4, 1, 5, 2, 6, 3, 7};
		int filas = sizeof(movimiento)/sizeof(movimiento[0]);
		mover('c', articulacion, angulo, orden, movimiento, filas);
	}
	if(cmd=='h')//Giro Izquierda
	{
		int movimiento[6][8] = {
			{ 90, 90, 90, 90, 95, 90, 95, 90},
			{ 85, 95, 80, 90, 95, 90, 95, 90},
			{ 95, 80,100, 90, 95, 90, 95, 90},
			{ 85, 95, 80, 90, 95, 90, 95, 90},
			{ 95, 80,100, 90, 95, 90, 95, 90},
			{ 90, 90, 90, 90, 95, 90, 95, 90}
		};
		int orden[8] = {0, 4, 1, 5, 2, 6, 3, 7};
		int filas = sizeof(movimiento)/sizeof(movimiento[0]);
		mover('c', articulacion, angulo, orden, movimiento, filas);
	}
	if(cmd=='j')//Parar
	{
		int movimiento[1][8] = {
			{90,90,90,90,90,90,90,90}
		};
		int orden[8] = {0, 5, 1, 6, 2, 7, 3, 4};
		int filas = sizeof(movimiento)/sizeof(movimiento[0]);
		mover('c', articulacion, angulo, orden, movimiento, filas);
	}
	if(cmd=='k')//Saludar
	{
		int movimiento[10][8] = {
			{ 90, 90, 90, 90, 95, 90, 95, 90},
			{ 90, 90, 90, 90, 95, 90, 95,130},
			{ 90, 90, 90, 90, 95, 90, 95,170},
			{ 90, 90, 90, 90, 95, 90, 95,130},
			{ 90, 90, 90, 90, 95, 90, 95,170},
			{ 90, 90, 90, 90, 95, 90, 95,130},
			{ 90, 90, 90, 90, 95, 90, 95,170},
			{ 90, 90, 90, 90, 95, 90, 95,130},
			{ 90, 90, 90, 90, 95, 90, 95,170},
			{ 90, 90, 90, 90, 95, 90, 95, 90}
		};
		int orden[8] = {0, 4, 1, 5, 2, 6, 3, 7};
		int filas = sizeof(movimiento)/sizeof(movimiento[0]);
		mover('c', articulacion, angulo, orden, movimiento, filas);
	}
	if(cmd=='z')//Balancear
	{
		int movimiento[10][8] = {
			{ 90, 90, 90, 90, 95, 90, 95, 90},
			{ 90, 90, 90, 90, 95, 90, 95, 90},
			{ 90, 90, 90, 90, 95, 90, 95, 90},
			{ 90, 90, 90, 90, 95, 90, 95, 90},
			{ 90, 90, 90, 90, 95, 90, 95, 90},
			{ 90, 90, 90, 90, 95, 90, 95, 90},
			{ 90, 90, 90, 90, 95, 90, 95, 90},
			{ 90, 90, 90, 90, 95, 90, 95, 90},
			{ 90, 90, 90, 90, 95, 90, 95, 90},
			{ 90, 90, 90, 90, 95, 90, 95, 90}
		};
		int orden[8] = {0, 4, 1, 5, 2, 6, 3, 7};
		int filas = sizeof(movimiento)/sizeof(movimiento[0]);
		mover('c', articulacion, angulo, orden, movimiento, filas);
	}
	if(cmd=='l')//Bailar
	{
		int movimiento[10][8] = {
			{ 90, 90, 90, 90, 95, 90, 95, 90},
			{ 95, 92, 90, 90,100, 92, 95,170},
			{ 85, 88, 90, 10, 90, 88, 95, 90},
			{ 95, 92, 90, 90,100, 92, 95,170},
			{ 85, 88, 90, 10, 90, 88, 95, 90},
			{ 95, 92, 90, 90,100, 92, 95,170},
			{ 85, 88, 90, 10, 90, 88, 95, 90},
			{ 95, 92, 90, 90,100, 92, 95,170},
			{ 85, 88, 90, 10, 90, 88, 95, 90},
			{ 90, 90, 90, 90, 90, 90, 95, 90}
		};
		int orden[8] = {0, 4, 1, 5, 2, 6, 3, 7};
		int filas = sizeof(movimiento)/sizeof(movimiento[0]);
		//Serial.println(filas);
		mover('c', articulacion, angulo, orden, movimiento, filas);
	}
}
/*void SIMA::restaurar(){
	
	
}
*/
////////////////////////////
//- MONITOREO DE BATERIA -//
////////////////////////////
float SIMA::voltajeBateria(){
	//lectura analogica en el pin A0
	float bat=2.0*analogRead(A0);
	if(bat >= 3.3)
	{
		digitalWrite(A1, LOW);//R
		digitalWrite(A2, HIGH);//G
		digitalWrite(A3, LOW);//B
	}
	if(bat >= 1.7 && bat <= 3.3)
	{
		digitalWrite(A1, HIGH);//R
		digitalWrite(A2, HIGH);//G
		digitalWrite(A3, LOW);//B
	}
	if(bat <= 1.7)
	{
		digitalWrite(A1, HIGH);//R
		digitalWrite(A2, LOW);//G
		digitalWrite(A3, LOW);
		digitalWrite(A3, LOW);//B
	}
	return bat;
}
float SIMA::niveldeBateria(){
	
}