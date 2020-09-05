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

void loop()
{ //while con energía

  //////////// lectura de sensores

  // leer los pulsadores

  // leer potenciometro ( 0 -4095) 5

  /////////// condiciones

  // De 0 a 819 >> AND
  if (valor_ponteciometro >= 0 && valor_ponteciometro <= 819)
  {

    // encender el color que corresponda

    // se generan 4 casos

    // 00
    // 01
    // 10
    // 11
  }
}
