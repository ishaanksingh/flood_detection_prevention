#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Servo.h>

Servo m;
int value;

void setup() {
   lcd.begin();
  lcd.backlight();
  
  pinMode(A0,INPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
  m.attach(A1);
}

void loop() {
  
  value= analogRead(A0); 
  if(value<200)
  {
   lcd.setCursor(0, 1);
  lcd.print("LOW");
    digitalWrite(9,LOW);
  sense();
 

  }
  
  if ((value > 200 ) && (value <300))
  {
    lcd.setCursor(0, 1);

  lcd.print("MEDIUM");
    digitalWrite(9,LOW);

  beep();
 sense();
  pe();
 }
  
  if(value>300)
  {
    lcd.setCursor(0, 1);
  lcd.print("FILL");
  beep();
      sense();
  motor();
  pe();
  }
  

 
}

void motor()
{
     m.write(0);
  delay(500);
  m.write(180);

  delay(500);
}

void pe()
{
    int per=1;
  per=value/4;
  lcd.setCursor(0, 1);
  lcd.print("filled :");
  lcd.print(per);
  lcd.print("%");
}

void sense()
{
    
  lcd.setCursor(0, 0);
  lcd.print("Value :");
  lcd.print(value);
  lcd.print("   ");
  Serial.println(value);
}




                                                                                     // initializing pin 11 as buzzer pin


void beep ()                                                                                         // Code written in it will run repeatedly
{
 
   unsigned char i, j ;                                                                          // Declaring variables

     for (i = 0; i <80; i++){                                                                     // 100 cycles of sound
       digitalWrite (9, HIGH);                                                         // This will turn the buzzer ON
       delay (1) ;                                                                                      // Giving a Delay of 1ms will set frequency 1
       digitalWrite (9, LOW);                                                          // This will turn the buzzer OFF
       delay (1) ;                                                                                      // Giving a delay ms
     }
     for (i = 0; i <100; i++){                                                                 // 100 cycles of sound
       digitalWrite (9, HIGH);                                                         // This will turn the buzzer ON
       delay (2) ;                                                                                      // Giving a delay of 2ms will set frequency 2
       digitalWrite (9, LOW);                                                          // This will turn the buzzer OFF
       delay (2) ;                                                                                      // Giving a delay of 2ms
     }
   

   }
