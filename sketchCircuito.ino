//DESAFIO DE PROJETO - DIO IOT SPECIALIST
//AUTOR: VITOR MELO

//DECLARAÇÃO DAS VARIÁVEIS E DOS PINOS

int Vout = A0;
int Buzzer = 11;
int led = 5;
int motor = 6;
int temperatura;

void setup()
{
  pinMode(Vout,INPUT);
  Serial.begin(9600);
}

void loop()
{
  
//LEITURA DA TEMPERATURA  
 temperatura = map(((analogRead(Vout) - 20) * 3.04), 0, 1023, -40, 125);
 Serial.print("Temperatura: ");
 Serial.println(temperatura);
 
//ACIONAMENTO DO VENTILADOR
  if(temperatura >= 30){
   Serial.println("Ventilador Acionado");
   digitalWrite(motor,HIGH);
  }else{
    digitalWrite(motor,LOW);
  }
  
//ACIONAMENTO DO LED E DO BUZZER
  if(temperatura > 50){
   Serial.println("Led e Buzzer Acionados");
   digitalWrite(led,HIGH);
   digitalWrite(Buzzer,HIGH); 
  }else{
   digitalWrite(led,LOW);
   digitalWrite(Buzzer,LOW);
  }
  
}
