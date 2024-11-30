#define S0 8
#define S1 9
#define S2 12
#define S3 11
#define Out 10

//Pinos dos LEDs
#define LedVerm 2
#define LedVerd 3
#define LedAzul 4

unsigned int valorvermelho = 0;
unsigned int valorverde = 0;
unsigned int valorazul = 0;
unsigned int valorbranco = 0;

void detectaCor();

void setup()
{
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(Out, INPUT);

  pinMode(LedVerm, OUTPUT);
  pinMode(LedVerd, OUTPUT);
  pinMode(LedAzul, OUTPUT);

  Serial.begin(9600);
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  delay(2000);


}

void loop()
{

  detectaCor();

  //serial monitor
  Serial.print("Vermelho :");
  Serial.print(valorvermelho);

  Serial.print(" Verde : ");
  Serial.print(valorverde);

  Serial.print(" Azul : ");
  Serial.print(valorazul);

  Serial.print(" Branco : ");
  Serial.println(valorbranco);


//*****Código do aluno para detectar a cor*********
if(valorvermelho<50){
   digitalWrite(LedVerm, HIGH);
  digitalWrite(LedVerd, LOW);
  digitalWrite(LedAzul, LOW);
  }

  if(valorverde<80){
   digitalWrite(LedVerm, LOW);
  digitalWrite(LedVerd, HIGH);
  digitalWrite(LedAzul, LOW);
  }

 if(valorazul<60){
   digitalWrite(LedVerm, LOW);
  digitalWrite(LedVerd, LOW);
  digitalWrite(LedAzul, HIGH);
  
  }


//****************** fim ****************************


  // apagar os leds
  delay(50);
  digitalWrite(LedVerm, LOW);
  digitalWrite(LedVerd, LOW);
  digitalWrite(LedAzul, LOW);
}


// leitura do sensor
void detectaCor() {
  //Vermelho
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  valorvermelho = pulseIn(Out, digitalRead(Out) == HIGH ? LOW : HIGH);
  
  //branco
  digitalWrite(S2, HIGH);
  digitalWrite(S3, LOW);
  valorbranco = pulseIn(Out, digitalRead(Out) == HIGH ? LOW : HIGH);

  //Azul
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  valorazul = pulseIn(Out, digitalRead(Out) == HIGH ? LOW : HIGH);

  //Verde
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  valorverde = pulseIn(Out, digitalRead(Out) == HIGH ? LOW : HIGH);
}
