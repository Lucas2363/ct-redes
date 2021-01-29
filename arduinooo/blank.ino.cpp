/* Atividade Aula 90
Aluno: Rafael Costa Coelho Honesto.
O objetivo da atividade e determinar qual led deve ser aceso de acordo com a temperatura e trabalhar junto com a chave. 
*/

//Colocando o pino dentro de uma variavel
int chave = 13;
int verde = 2;
int amarelo = 3;
int vermelho = 4;

//NÃO ALTERAR------------------------------------------------------------------------------------------------
float temperatura; //Variável que vai amarmazenar a informações sobre a temperatura do sensor
int pinoAnalogico0 = 0;
//NÃO ALTERAR------------------------------------------------------------------------------------------------

void setup()
{
  //NÃO ALTERAR------------------------------------------------------------------------------------------------
  Serial.begin(9600); //Inicia o monitor Serial
  pinMode(A0, INPUT); //Define o pino A0 como entrada
  //NÃO ALTERAR------------------------------------------------------------------------------------------------

  pinMode(verde, OUTPUT); //Declarando o estado dos pinos como saida ou ligado/desligado
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(chave, INPUT_PULLUP);
}

void loop()
{

  int estado = digitalRead(chave); //lendo o estado da chave

  while (estado == HIGH) //Enquanto a chave estiver ligada o codigo vai executar
  {
    int estado = digitalRead(chave);

    if (estado == LOW) //Se estiver desligada todos os leds desligam e o codigo para de executar
    {
      digitalWrite(verde, LOW);
      digitalWrite(amarelo, LOW);
      digitalWrite(vermelho, LOW);
      break;
    }

    //NÃO ALTERAR------------------------------------------------------------------------------------------------
    temperatura = ((analogRead(pinoAnalogico0) * (5.0 / 1024)) - 0.5) / 0.01; //Executa a leitura da temperatura e armazena na variável 'temperatura'

    //Exibe no Monitor Serial a temperatura do Rack
    Serial.print("A temperatura do Rack esta em: ");
    Serial.print(temperatura);
    Serial.print(char(176));
    Serial.println("C");
    delay(1000); //Aguarde 1 segundo
    //NÃO ALTERAR------------------------------------------------------------------------------------------------

    if (temperatura <= 25)
    { //Se a temperatura for menor ou igual a 25 o led verde acende
      digitalWrite(verde, HIGH);
      digitalWrite(amarelo, LOW);
      digitalWrite(vermelho, LOW);
    }

    if (temperatura > 25 and temperatura <= 70)
    { //Se a temperatura for maior que 25 e menor ou igual a 70 o led amarelo acende
      digitalWrite(verde, LOW);
      digitalWrite(amarelo, HIGH);
      digitalWrite(vermelho, LOW);
    }

    if (temperatura > 70)
    { //Se a temperatura for maior que 70 o led vermelho acende
      digitalWrite(verde, LOW);
      digitalWrite(amarelo, LOW);
      digitalWrite(vermelho, HIGH);
    }
  }
}
