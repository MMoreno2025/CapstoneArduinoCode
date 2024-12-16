//Malia Moreno | 10 December 2024//
//Liquid crystal library is the name of the LCD screen library//
#include <LiquidCrystal.h>

//define all LCD screen exports aligned with Arduino import//
const int rs=12, e=11, d4=5, d5=4, d6=3,d7=2;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);   //standardise LCD screen//

double volts;
double price;

void setup() {
  lcd.begin(16,2);  //my LCD screen size is 16x2 squres//
  lcd.print("Volts ---- Price");    //stationary print//
}

void loop() {
  //make sensor for time//


  //display changing value of volts/amps (need figure out what ot measure)//
  lcd.setCursor(1,1);
  volts = random(0, 42);
  volts = volts*0.1;
  lcd.print(volts);

  //displays price at a certain point in time//
  lcd.setCursor(12,1);
  price = volts*0.57;
  lcd.print(price);

  delay(1000);
}
