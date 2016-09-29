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
#include <Servo.h>
//condiciones iniciales de las articulaciones
int _init[]={100,90,110,90,90,90,90,70,90,90};
//Variables de Servos
//Servo L1, L2, L3, L4, L5; //Izquierda: Tobillo, Rodilla, Cadera, Hombro, Codo. 
//Servo R1, R2, R3, R4, R5; //Derecha: Tobillo, Rodilla, Cadera, Hombro, Codo.
Servo Servos[10];//Izquierda: Tobillo, Rodilla, Cadera, Hombro, Codo.

int estado=0;
int l[]={100,90,110,90,90,90,90,70,90,90};
//Animaciones
//Saludo
//paso 1: Levantar el brazo
//paso 2: Mover la mano 
int s[10][10]={{100,90,110,90,90,90,90,70,170,90},
              {100,90,110,90,90,90,90,70,170,10},
              {100,90,110,90,90,90,90,70,170,170},
              {100,90,110,90,90,90,90,70,170,10},
              {100,90,110,90,90,90,90,70,170,170},
              {100,90,110,90,90,90,90,70,170,10},
              {100,90,110,90,90,90,90,70,170,170},
              {100,90,110,90,90,90,90,70,170,10},
              {100,90,110,90,90,90,90,70,170,90},
              {100,90,110,90,90,90,90,70,90,90}};
//Balanceo
int b[8][10]={{100,90,110,90,90,90,90,70,90,90},
              {80,90,110,90,90,70,90,70,90,90},
              {90,90,110,90,90,100,90,70,90,90},
              {80,90,110,90,90,70,90,70,90,90},
              {110,90,110,90,90,100,90,70,90,90},
              {80,90,110,90,90,70,90,70,90,90},
              {110,90,110,90,90,100,90,70,90,90},              
              {100,90,110,90,90,90,90,70,90,90}};
//Caminar
int c[4][10]={//{90,90,120,90,90,90,90,60,90,90},
              {90,90,120,90,90,80,80,70,90,90},
              {90,95,105,90,90,80,105,55,90,90},
              {105,90,105,90,90,90,90,55,90,90},
              {105,80,120,90,90,90,75,80,90,90},
              //{90,90,120,90,90,90,90,60,90,90}
              };

//Patear


//Bailar

//Malabares


void setup()
{
  //Inicialización de servos
  for (int i = 0;i < 10; i++)
  {
    Servos[i].attach(4+i);
    Servos[i].write(_init[i]);
  }
  delay(2000);
  //Inicio del puerto Serial
  Serial.begin(9600);
  //A espera del primer comando
  Serial.print("Ingrese un comando\n");
  while(!Serial.available()){
    Serial.print(".");
    delay(1000);
  }
}

void loop() {  
  if(Serial.available())
    estado = Serial.read();
    
  if(estado=='1'){
    l[0]=constrain(l[0]+1,10,170);
    Serial.println("Tob_L: "+String(l[0]));
    Servos[0].write(l[0]);
  }
  if(estado=='2'){
    l[1]=constrain(l[1]+1,10,170);
    Serial.println("Rod_L: "+String(l[1]));
    Servos[1].write(l[1]);
  }
  if(estado=='3'){
    l[2]=constrain(l[2]+1,10,170);
    Serial.println("Cad_L: "+String(l[2]));
    Servos[2].write(l[2]);
  }
  if(estado=='4'){
    l[3]=constrain(l[3]+1,10,170);
    Serial.println("Hom_L: "+String(l[3]));
    Servos[3].write(l[3]);
  }
  if(estado=='5'){
    l[4]=constrain(l[4]+1,10,170);
    Serial.println("Cod_L: "+String(l[4]));
    Servos[4].write(l[4]);
  }
  if(estado=='6'){
    l[5]=constrain(l[5]+1,10,170);
    Serial.println("Tob_R: "+String(l[5]));
    Servos[5].write(l[5]);
  }
  if(estado=='7'){
    l[6]=constrain(l[6]+1,10,170);
    Serial.println("Rod_R: "+String(l[6]));
    Servos[6].write(l[6]);
  }
  if(estado=='8'){
    l[7]=constrain(l[7]+1,10,170);
    Serial.println("Cad_R: "+String(l[7]));
    Servos[7].write(l[7]);
  }
  if(estado=='9'){
    l[8]=constrain(l[8]+1,10,170);
    Serial.println("Hom_R: "+String(l[8]));
    Servos[8].write(l[8]);
  }
  if(estado=='0'){
    l[9]=constrain(l[9]+1,10,170);
    Serial.println("Cod_R: "+String(l[9]));
    Servos[9].write(l[9]);
  }
    if(estado=='q'){
    l[0]=constrain(l[0]-1,10,170);
    Serial.println("Tob_L: "+String(l[0]));
    Servos[0].write(l[0]);
  }
  if(estado=='w'){
    l[1]=constrain(l[1]-1,10,170);
    Serial.println("Rod_L: "+String(l[1]));
    Servos[1].write(l[1]);
  }
  if(estado=='e'){
    l[2]=constrain(l[2]-1,10,170);
    Serial.println("Cad_L: "+String(l[2]));
    Servos[2].write(l[2]);
  }
  if(estado=='r'){
    l[3]=constrain(l[3]-1,10,170);
    Serial.println("Hom_L: "+String(l[3]));
    Servos[3].write(l[3]);
  }
  if(estado=='t'){
    l[4]=constrain(l[4]-1,10,170);
    Serial.println("Cod_L: "+String(l[4]));
    Servos[4].write(l[4]);
  }
  if(estado=='y'){
    l[5]=constrain(l[5]-1,10,170);
    Serial.println("Tob_R: "+String(l[5]));
    Servos[5].write(l[5]);
  }
  if(estado=='u'){
    l[6]=constrain(l[6]-1,10,170);
    Serial.println("Rod_R: "+String(l[6]));
    Servos[6].write(l[6]);
  }
  if(estado=='i'){
    l[7]=constrain(l[7]-1,10,170);
    Serial.println("Cad_R: "+String(l[7]));
    Servos[7].write(l[7]);
  }
  if(estado=='o'){
    l[8]=constrain(l[8]-1,10,170);
    Serial.println("Hom_R: "+String(l[8]));
    Servos[8].write(l[8]);
  }
  if(estado=='p'){
    l[9]=constrain(l[9]-1,10,170);
    Serial.println("Cod_R: "+String(l[9]));
    Servos[9].write(l[9]);
  }
  //Reinicio
  if(estado=='z'){
    Serial.println("Reiniciando");
    for (int i = 0;i < 10; i++)
    {
      while(l[i]!=_init[i])
      {
        if(l[i]<_init[i])
        {
          l[i]=constrain(l[i]+1,10,_init[i]);
          Servos[i].write(l[i]);
          Serial.println(String(i)+":"+String(l[i]));
          delay(100);
        }
        if(l[i]>_init[i])
        {
          l[i]=constrain(l[i]-1,_init[i],170);
          Servos[i].write(l[i]);
          Serial.println(String(i)+":"+String(l[i]));
          delay(100);
        }
      }
    }
  }
  //Saludo
  if(estado=='s'){
    Serial.println("Saludas");
    for (int j = 0;j < 10; j++)
    {  
      for (int i = 0;i < 10; i++)
      {
        while(l[i]!=s[j][i])
        {
          if(l[i]<s[j][i])
          {
            l[i]=constrain(l[i]+3,10,s[j][i]);
            Servos[i].write(l[i]);
            Serial.println(String(i)+":"+String(l[i]));
            delay(10);
          }
          if(l[i]>s[j][i])
          {
            l[i]=constrain(l[i]-3,s[j][i],170);
            Servos[i].write(l[i]);
            Serial.println(String(i)+":"+String(l[i]));
            delay(10);
          }
        }
      }
    }
  }
  //Camina
  if(estado=='c'){
    int ord[6]={0,5,1,6,2,7};
    Serial.println("Camina");
    for (int j = 0;j < 4; j++)
    {  
        while(l[ord[0]]!=c[j][ord[0]] || l[ord[1]]!=c[j][ord[1]] || l[ord[2]]!=c[j][ord[2]] || l[ord[3]]!=c[j][ord[3]] || l[ord[4]]!=c[j][ord[4]] || l[ord[5]]!=c[j][ord[5]])
        {
          if(l[ord[0]]<c[j][ord[0]])
          {
            l[ord[0]]=constrain(l[ord[0]]+1,10,c[j][ord[0]]);
            Servos[ord[0]].write(l[ord[0]]);
            Serial.println(String(ord[0])+":"+String(l[ord[0]]));
          }
          if(l[ord[1]]<c[j][ord[1]])
          {
            l[ord[1]]=constrain(l[ord[1]]+1,10,c[j][ord[1]]);
            Servos[ord[1]].write(l[ord[1]]);            
            Serial.println(String(ord[1])+":"+String(l[ord[1]]));
          }
          if(l[ord[2]]<c[j][ord[2]])
          {
            l[ord[2]]=constrain(l[ord[2]]+1,10,c[j][ord[2]]);
            Servos[ord[2]].write(l[ord[2]]);            
            Serial.println(String(ord[2])+":"+String(l[ord[2]]));
          }
          if(l[ord[3]]<c[j][ord[3]])
          {
            l[ord[3]]=constrain(l[ord[3]]+1,10,c[j][ord[3]]);
            Servos[ord[3]].write(l[ord[3]]);            
            Serial.println(String(ord[3])+":"+String(l[ord[3]]));
          }
          if(l[ord[4]]<c[j][ord[4]])
          {
            l[ord[4]]=constrain(l[ord[4]]+1,10,c[j][ord[4]]);
            Servos[ord[4]].write(l[ord[4]]);            
            Serial.println(String(ord[4])+":"+String(l[ord[4]]));
          }
          if(l[ord[5]]<c[j][ord[5]])
          {
            l[ord[5]]=constrain(l[ord[5]]+1,10,c[j][ord[5]]);
            Servos[ord[5]].write(l[ord[5]]);            
            Serial.println(String(ord[5])+":"+String(l[ord[5]]));
          }
          if(l[ord[0]]>c[j][ord[0]])
          {
            l[ord[0]]=constrain(l[ord[0]]-1,c[j][ord[0]],170);
            Servos[ord[0]].write(l[ord[0]]);
            Serial.println(String(ord[0])+":"+String(l[ord[0]]));
          }
          if(l[ord[1]]>c[j][ord[1]])
          {
            l[ord[1]]=constrain(l[ord[1]]-1,c[j][ord[1]],170);
            Servos[ord[1]].write(l[ord[1]]);            
            Serial.println(String(ord[1])+":"+String(l[ord[1]]));
          }
          if(l[ord[2]]>c[j][ord[2]])
          {
            l[ord[2]]=constrain(l[ord[2]]-1,c[j][ord[2]],170);
            Servos[ord[2]].write(l[ord[2]]);            
            Serial.println(String(ord[2])+":"+String(l[ord[2]]));
          }
          if(l[ord[3]]>c[j][ord[3]])
          {
            l[ord[3]]=constrain(l[ord[3]]-1,c[j][ord[3]],170);
            Servos[ord[3]].write(l[ord[3]]);            
            Serial.println(String(ord[3])+":"+String(l[ord[3]]));
          }
          if(l[ord[4]]>c[j][ord[4]])
          {
            l[ord[4]]=constrain(l[ord[4]]-1,c[j][ord[4]],170);
            Servos[ord[4]].write(l[ord[4]]);            
            Serial.println(String(ord[4])+":"+String(l[ord[4]]));
          }
          if(l[ord[5]]>c[j][ord[5]])
          {
            l[ord[5]]=constrain(l[ord[5]]-1,c[j][ord[5]],170);
            Servos[ord[5]].write(l[ord[5]]);            
            Serial.println(String(ord[5])+":"+String(l[ord[5]]));
          }
          delay(20);
        }
    }
  }
  //Balanceo
  if(estado=='b'){
    int ord[10]={0,5};
    Serial.println("Balanceo");
    for (int j = 0;j < 8; j++)
    {  
        while(l[ord[0]]!=b[j][ord[0]])
        {
          if(l[ord[0]]<b[j][ord[0]])
          {
            l[ord[0]]=constrain(l[ord[0]]+2,10,b[j][ord[0]]);
            l[ord[1]]=constrain(l[ord[1]]+2,10,b[j][ord[1]]);
            Servos[ord[0]].write(l[ord[0]]);
            Servos[ord[1]].write(l[ord[1]]);
            Serial.println(String(ord[0])+":"+String(l[ord[0]]));
            Serial.println(String(ord[1])+":"+String(l[ord[1]]));
            delay(50);
          }
          if(l[ord[0]]>b[j][ord[0]])
          {
            l[ord[0]]=constrain(l[ord[0]]-2,b[j][ord[0]],170);
            l[ord[1]]=constrain(l[ord[1]]-2,b[j][ord[1]],170);
            Servos[ord[0]].write(l[ord[0]]);
            Servos[ord[1]].write(l[ord[1]]);
            Serial.println(String(ord[0])+":"+String(l[ord[0]]));
            Serial.println(String(ord[1])+":"+String(l[ord[1]]));
            delay(50);
          }
        }
    }
  }
  delay(100);
}
