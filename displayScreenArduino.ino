//Malia Moreno | 10 December 2024//
//Liquid crystal library is the name of the LCD screen library//
#include <LiquidCrystal.h>

//define all LCD screen exports aligned with Arduino import//
const int rs=12, e=11, d4=5, d5=4, d6=3,d7=2;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);   //standardise LCD screen//

//weekend//
String weekdays[] = {"Mon", "Tue", "Wed", "Thu", "Fri"};
String weekend[] = {"Sat", "Sun"};

void setup() {
  lcd.begin(16,2);  //my LCD screen size is 16x2 squres//
  lcd.print("Volts ---- Price");    //stationary print//

  Serial.begin(9600);
}

void loop() {
  //set values of day & time - might need to put this in the loop for constant update, check after adding that one part//
  String day="Sat";
  double hour = 13;    //out of 24 hours//
  bool dayCheck = false;


  for(int place = 4; place>=0; place--){
    if(weekdays[place] == day){
      dayCheck = true;
    }else{
      dayCheck = false;
    }
  }

  //make sensor for time//
  if(dayCheck==true){
    

    //change display on screen --> position 1, 8//
    lcd.setCursor(1,8);
    lcd.print("y");
  }else{

    //change display on screen --> position 1, 8//
    lcd.setCursor(1,8);
    lcd.print("n");
  }


/*
  //display changing value of volts/amps (need figure out what ot measure)//
  lcd.setCursor(1,1);
  lcd.print(0.0);

  //displays price at a certain point in time//
  lcd.setCursor(12,1);
  lcd.print(millis()/1000);
*/
}
