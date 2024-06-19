/* 
Projeto: Bengala para cegos 
Autor: André Silveira
Data: 02/04/2019 
*/

int PINO_TRIG = 6;
int PINO_ECHO = 5;
int PINO_BUZZER = 3; 
int LED_RED = 11;
int LED_BLUE = 10;
int LED_GREEN = 9;
float distancia;

void setup() {
    Serial.begin(9600);  
    pinMode(PINO_TRIG , OUTPUT);
    pinMode(PINO_ECHO , INPUT);
    pinMode(PINO_BUZZER,OUTPUT);   
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);  
    ligaled(0, 0, 0);
}

void loop() {

    distancia = Ultrasonic(PINO_TRIG, PINO_ECHO);      
  
    Serial.print("Distancia em cm: ");
    Serial.println (distancia);   
  
    // -- Distância menor que 1 metro

    if (distancia <= 100) {    
        tone(PINO_BUZZER,330,300);  
        ligaled(255, 0, 0);      
        delay(10);      
    } else {
 
          // -- Distância maior que 1 metro e menor que 2 metros

           if (distancia <= 200 ) {    
               tone(PINO_BUZZER,330,300);   
               ligaled(255, 255, 0);
               delay(250);      
           } else { 

                  // -- Distância maior que 2 metros e menor que 3 metros

                  if (distancia <= 300 ) {    
                      tone(PINO_BUZZER,330,300); 
                      ligaled(0, 0, 255);
                      delay(500);      
                  } else{
                          ligaled(0, 0, 0);
                          }
           	  }
           }            
}

float Ultrasonic (int PINO_TRIG, int PINO_ECHO) {

      int distancia=0;
      while(distancia == 0) {
            digitalWrite(PINO_TRIG, 0);
            delayMicroseconds (5);          
            digitalWrite(PINO_TRIG, 1);
            delayMicroseconds(10); 
            float tempo = pulseIn (PINO_ECHO, 1);               
            distancia = (tempo/2/29.15);
      }
      return distancia;
}

int ligaled(int r, int g, int b) {   
 
    analogWrite(LED_RED, r);  
    analogWrite(LED_GREEN, g);  
    analogWrite(LED_BLUE, b);  

}
