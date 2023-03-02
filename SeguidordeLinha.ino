#define sensorMEI A1
#define sensorESQ A0
#define sensorDIR A2
#define ponte34 7
#define ponte12 6
#define entrada4 12
#define entrada3 11
#define entrada2 9
#define entrada1 10
#define botao 4
#define led 5
bool estadoBotao = LOW;
bool estadoAntBotao = LOW;
bool ledLigado = LOW;

void setup(){
  pinMode(sensorDIR, INPUT);
  pinMode(sensorMEI, INPUT);
  pinMode(sensorESQ, INPUT);
  pinMode(ponte34, OUTPUT);
  pinMode(ponte12, OUTPUT);
  pinMode(entrada4, OUTPUT);
  pinMode(entrada3, OUTPUT);
  pinMode(entrada2, OUTPUT);
  pinMode(entrada1, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

bool Botao(){
  estadoBotao = digitalRead(botao);  
  if (estadoBotao != estadoAntBotao){
    if(estadoBotao){
      ledLigado = !ledLigado;
      digitalWrite(led,ledLigado);
  	}
  }
  estadoAntBotao = estadoBotao;
  return !ledLigado;
}

void seguirESQ(int forca){
  Serial.println("ESQ");
}

void seguirDIR(int forca){
  Serial.println("DIR");
}

void seguirFRE(){
  Serial.println("Fre");
}

void parar(){
  Serial.println("Parou");
}

void loop(){
  if(Botao()){
    if((analogRead(sensorESQ)) && (analogRead(sensorDIR)) && (analogRead(sensorMEI))){
      seguirFRE();
    }
  	else if((analogRead(sensorESQ)) && (analogRead(sensorDIR)) && !(analogRead(sensorMEI))){
      seguirFRE();
    }
    else if((analogRead(sensorMEI)) && (analogRead(sensorDIR))){
      seguirDIR(0);
    }
    else if((analogRead(sensorMEI)) && (analogRead(sensorESQ))){
      seguirESQ(0);
    }
    
    else if(analogRead(sensorMEI)){
      seguirFRE();
    }
    else if(analogRead(sensorDIR)){
      seguirDIR(1);
    }
    else if(analogRead(sensorESQ)){
      seguirESQ(1);
    }
    else{
      parar();
    };
  }
  else{
    parar();
  };
  
  delay(100); // Delay a little bit to improve simulation performance
}
