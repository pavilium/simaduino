/*  Autor: José Polanco
    https://github.com/urayi
 *DISTRIBUCIÓN DE VARIABLES EN EL CUERPO
 *               CABEZA 
 *       R4-D5  -HOMBROS  - D10-L4 
 *R5-D6         -CODOS    -        D11-L5
 *       R3-D4  -CADERAS  - D9 -L3
 *       R2-D3  -RODILLAS - D8 -L2
 *       R1-D2  -TALONES  - D7 -L1
 */
#include <SIMA.h>
//#include <Servo.h>
//condiciones iniciales de las articulaciones
int _init[10]={100,90,110,90,90,90,90,70,90,90};
int ang[10];
//Variables de Servos
//Servo L1, L2, L3, L4, L5; //Izquierda: Tobillo, Rodilla, Cadera, Hombro, Codo. 
//Servo R1, R2, R3, R4, R5; //Derecha: Tobillo, Rodilla, Cadera, Hombro, Codo.
Servo articulacion[10];//Izquierda: Tobillo, Rodilla, Cadera, Hombro, Codo.
SIMA sima;
int comando;

void setup()
{

  //Inicialización de servos
  for (int i = 0;i < 10; i++)
  {
    ang[i]=_init[i];
    articulacion[i].attach(4+i);
    articulacion[i].write(_init[i]);
  }
  delay(100);
  //Inicio del puerto Serial
  Serial.begin(9600);
  //A espera del primer comando
  //Serial.print("Ingrese un comando\n");
  while(Serial.available()<=0){
    Serial.print(".");
    delay(1000);
  }
}

void loop() {
  if(Serial.available()>0)
  {
    comando = Serial.read();
    sima.Simatest(comando, articulacion, ang);
    sima.control(comando, articulacion, ang);
  }
  delay(10);
}
