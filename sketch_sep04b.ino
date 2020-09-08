// definir pines y variables de entradas y salidas

//Input o Entrada
int potenciometro_pin = 36; // se define el a utilizar en la esp32 es que un ADC (potenciometro)
int pulsador_1_pin = 22;    //Pulsador 1
int pulsador_2_pin = 23;    // Pulsador 2

//Output o Salida
int led_rojo = 13;
int led_azul = 17;
int led_verde = 12;

//Valores de inicialización
int potenciometro_valor = 2; // variable donde se guardara el valor del entregado por el ADC
int pulsador_1_valor = 0;
int pulsador_2_valor = 0;

int frecuencia = 5000;  //frecuencia de 5000 Hz
int canal_led_rojo = 0; //van de 0 a 115
int canal_led_azul = 1;
int canal_led_verde = 2;
int resolucion = 8; //va de 1 a 16

void setup()
{ //inicio principio del programa

  // habilitar comunicación serial
  Serial.begin(115200);                  //115200 sería los baudios
  pinMode(pulsador_1_pin, INPUT_PULLUP); // se configuran los pines de los pulsadores como entradas,ademas se habilita un resistencia PULL-UP interna
  pinMode(pulsador_2_pin, INPUT_PULLUP); // se configuran los pines de los pulsadores como entradas,ademas se habilita un resistencia PULL-UP interna
}

void loop() //while con energía
{ 

  //////////// lectura de pulsadores

  pulsador_1_valor = digitalRead(pulsador_1_pin);
  pulsador_2_valor = digitalRead(pulsador_1_pin);

  ///Ver por Pantallaaa

  Serial.print("Pulsador_1: ");
  Serial.print(pulsador_1_valor);
  Serial.print(" Pulsador_2: ");
  Serial.print(pulsador_2_valor);

    //potenciometro
  
  potenciometro_valor = analogRead(potenciometro_pin);

  ///// Ver en Pantallaaaa
  Serial.print(" Potenciometro: ");
  Serial.print(potenciometro_valor);
  
  /////////// condiciones

  // AND (va de 0 a 819) 
  if (potenciometro_valor >= 0 && potenciometro_valor <= 819)
  {


     //Puerta AND
    Serial.print(" Puerta AND ");
    if ((pulsador_1_valor == 0) && (pulsador_2_valor == 0))
    {
      color(0, 0, 0); //Apagado ya que ni valor 1 ni valor dos son = 1
      Serial.println(" [Apagado pulsador 1(0) pulsador 2(0)=(0)] ");
      delay(1000);
    }
    else if ((pulsador_1_valor == 0) && (pulsador_2_valor == 1))
    {
      color(0, 0, 0); //Apagado
      Serial.println(" [Apagado pulsador 1(0) pulsador 2(1)=(0)] ");
      delay(1000);
    }
    else if ((pulsador_1_valor == 1) && (pulsador_2_valor == 0))
    {
      color(0, 0, 0); //Apagado
      Serial.println(" [Apagado pulsador 1(1) pulsador 2(0)=(0)] ");
      delay(1000);
    }
    else if ((pulsador_1_valor == 1) && (pulsador_2_valor == 1))
    {                   
      color(255, 0, 0); //Rojo
      Serial.println("  [Led Encendido pulsador 1(1) pulsador 2(1)=(1) ");
      delay(1000);
    }
  }
  else if ((potenciometro_valor > 819) && (potenciometro_valor <= 1638))
  { //puerta OR (o uno o el otro debe ser 1)
    Serial.print("  Puerta OR ");
    if ((pulsador_1_valor == 0) && (pulsador_2_valor == 0))
    {
      color(0, 0, 0); //Apagado
      Serial.println(" [Apagado pulsador 1(0) pulsador 2(0)=(0)] ");
      delay(1000);
    }
    else if ((pulsador_1_valor == 0) && (pulsador_2_valor == 1))
    {
      color(64, 0, 128); //Violeta
      Serial.println(" [Led Encendido pulsador 1(0) pulsador 2(1)=(1)] ");
      delay(1000);
    }
    else if ((pulsador_1_valor == 1) && (pulsador_2_valor == 0))
    {
      color(64, 0, 128); //Violeta
      Serial.println(" [Led Encendido Apagado pulsador 1(1) pulsador 2(0)=(1)] ");
      delay(1000);
    }
    else if ((pulsador_1_valor == 1) && (pulsador_2_valor == 1))
    {                   
      color(64, 0, 128); //Violeta
      Serial.println(" [Led Encendido pulsador 1(1) pulsador 2(1)=(1)] ");
      delay(1000);
    }
  }
  else if ((potenciometro_valor > 1638) && (potenciometro_valor <= 2457))
  { //puerta NAND
    Serial.print("  Puerta NAND ");
    if ((pulsador_1_valor == 0) && (pulsador_2_valor == 0))
    {
      color(255, 255, 0); //Amarillo
      Serial.println(" [Led Encendido pulsador 1(0) pulsador 2(0)=(1)] ");
      delay(1000);
    }
    else if ((pulsador_1_valor == 0) && (pulsador_2_valor == 1))
    {
      color(255, 255, 0); //Amarillo
      Serial.println(" [Led Encendido Apagado pulsador 1(0) pulsador 2(1)=(1)] ");
      delay(1000);
    }
    else if ((pulsador_1_valor == 1) && (pulsador_2_valor == 0))
    {
      color(255, 255, 0); //Amarillo
      Serial.println(" [Led Encendido pulsador 1(1) pulsador 2(0)=(1))] ");
      delay(1000);
    }
    else if ((pulsador_1_valor == 1) && (pulsador_2_valor == 1))
    {                 
      color(0, 0, 0); //Apagado
      Serial.println(" [Apagado pulsador 1(1) pulsador 2(1)=(0)] ");
      delay(1000);
    }
  }
  else if ((potenciometro_valor > 2457) && (potenciometro_valor <= 3276))
  { //puerta NOR
    Serial.print("  Puerta NOR ");
    if ((pulsador_1_valor == 0) && (pulsador_2_valor == 0))
    {
      color(0, 0, 255); //Azul
      Serial.println(" [Led Encendido pulsador 1(0) pulsador 2(0)=(0)] ");
      delay(1000);
    }
    else if ((pulsador_1_valor == 0) && (pulsador_2_valor == 1))
    {
      color(0, 0, 0); //Apagado
      Serial.println(" [Apagado pulsador 1(1) pulsador 2(0)=(0)] ");
      delay(1000);
    }
    else if ((pulsador_1_valor == 1) && (pulsador_2_valor == 0))
    {
      color(0, 0, 0); //Apagado
      Serial.println(" [Apagado pulsador 1(1) pulsador 2(0)=(0)] ");
      delay(1000);
    }
    else if ((pulsador_1_valor == 1) && (pulsador_2_valor == 1))
    {                 
      color(0, 0, 0); //Apagado
      Serial.println(" [Apagado pulsador 1(1) pulsador 2(1)=(0)] ");
      delay(1000);
    }
  }
  else if ((potenciometro_valor > 3276) && (potenciometro_valor <= 4095))
  { 
    Serial.print("  Puerta XOR ");
    if ((pulsador_1_valor == 0) && (pulsador_2_valor == 0))
    {
      color(0, 0, 0); //Apagado
      Serial.println(" [Apagado pulsador 1(0) pulsador 2(0)=(0)] ");
      delay(1000);
    }
    else if ((pulsador_1_valor == 0) && (pulsador_2_valor == 1))
    {
      color(0, 255, 0); //Verde
      Serial.println(" [Led Encendido Apagado pulsador 1(0) pulsador 2(1)=(1)] ");
      delay(1000);
    }
    else if ((pulsador_1_valor == 1) && (pulsador_2_valor == 0))
    {
      color(0, 255, 0); //Verde
      Serial.println(" [Led Encendido pulsador 1(1) pulsador 2(0)=(1)] ");
      delay(1000);
    }
    else if ((pulsador_1_valor == 1) && (pulsador_2_valor == 1))
    {                 
      color(0, 0, 0); //Apagado
      Serial.println(" [Led Encendido Apagado pulsador 1(1) pulsador 2(1)=(1)] ");
      delay(1000);
    }
  }
}
void color(int red, int green, int blue)
{

  //Escritura de PWM rojo
  ledcWrite(canal_led_rojo, red);

  //Escritura de PWM verde
  ledcWrite(canal_led_verde, green);

  //Escritura de PWM azul
  ledcWrite(canal_led_azul, blue);
}
