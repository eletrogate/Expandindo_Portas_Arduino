//Inclui a biblioteca Whire
#include <Wire.h>

/*definindo os endereços dos PCFs no BUS
de acordo com a montagem do circuito

Criei nas 3 bases apenas para exemplificar.
No seu código, use apenas um, o de sua preferência
*/

#define pcf_1_addressDec 32       // em decimal
#define pcf_1_addressBin 0b100000 // em binário
#define pcf_1_addressHex 0x20     // em hexadecimal

#define pcf_2_address2Dec 36       // em decimal
#define pcf_2_address2Bin 0b100100 // em binário
#define pcf_2_address1Hex 0x24     // em hexadecimal

//Criando o mapa de caracteres de acordo com o mapeamento
//como o display é anodo comum, as portas são acionadas em nível
//logico baixo (zero) e desligadas em nível lógico alto (1)

                  // b a f g e d c pt
#define n0 = 0x11 // 0 0 0 1 0 0 0 1 
#define n1 = 0x7D // 0 1 1 1 1 1 0 1 
#define n2 = 0x21 // 0 0 1 0 0 0 0 1 
#define n3 = 0x29 // 0 0 1 0 1 0 0 1 
#define n4 = 0x4D // 0 1 0 0 1 1 0 1 
#define n5 = 0x89 // 1 0 0 0 1 0 0 1 
#define n6 = 0x81 // 1 0 0 0 0 0 0 1 
#define n7 = 0x3D // 0 0 1 1 1 1 0 1 
#define n8 = 0x1  // 0 0 0 0 0 0 0 1 
#define n9 = 0x9  // 0 0 0 0 1 0 0 1     

//cria uma array com a sequencia dos caracteres
//para serem mostrados nos displays
int seqArr = {n0, n1, n2, n3, n4, n5, n6, n6, n7, n8, n8}

// varivel de contagem
int cont= 0;
  
void setup(){
  //inicia a Serial
  Serial.begin(9600);
  //inicia a comunicação i2c
  Wire.begin();
}

//o loop mostra uam contagem progressiva (de 0 a 9)no diplay 1
//e uam contagem regressiva (de 9 a 0) no display 2

void loop(){
  
  //inicia uma trasmissão passando o endereço do PCF1
  Wire.beginTransmission(pcf_1_addressHex); 
  //escreve e envia o hexa contido noarray pelo indice cont
  Wire.write(seqArr[cont]);
  //finaliza a transmissão
  Wire.endTransmission();
  
  //inicia uma trasmissão passando o endereço do PCF1
  Wire.beginTransmission(pcf_2_addressHex); 
  //escreve e envia o hexa contido noarray pelo indice (10 - cont)
  Wire.write(seqArr[10-cont]);
  //finaliza a transmissão
  Wire.endTransmission();
  
  //incrementa o contador
  cont++;
  
  //delay de 250ms
  delay(250);
}