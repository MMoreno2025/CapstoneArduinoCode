//Malia Moreno | 10 December 2024//
//Liquid crystal library is the name of the LCD screen library//
#include <LiquidCrystal.h>

//define all LCD screen exports aligned with Arduino import//
const int rs=12, e=11, d4=5, d5=4, d6=3,d7=2;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);   //standardise LCD screen//

//weekend//
String weekdays[] = {"Mon", "Tue", "Wed", "Thu", "Fri"};

//weekday hour check//
String supOff01[] = {0, 1, 2, 3, 4, 5, 10, 11, 12, 13};
String off01[] = {6, 7, 8, 9, 14, 15, 21, 22, 23};
String peak01[] = {16, 17, 18, 19, 20};

//weekend hour check//
String supOff02[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
String off02[] = {14, 15, 21, 22, 23};
String peak02[] = {16, 17, 18, 19, 20};

//pricing -- using winter weeday&weekend TOU-DR1 pricing Tier 1 | measured in cents//
int supOff = 37.6;
int off = 39.4;
int peak = 45.6;


void setup() {
  lcd.begin(16,2);  //my LCD screen size is 16x2 squres//
  lcd.print("Volts ---- Price");    //stationary print//

  Serial.begin(9600);
}

void loop() {
  //set values of day & time - might need to put this in the loop for constant update, check after adding that one part//
  String day="Fri";
  double hour = 13;    //out of 24 hours//
  bool dayCheck = false;


  for(int place = 5; place>0; place--){
    if(weekdays[place] == day){
      dayCheck = true;
      break;    //break once true//
    }else{
      dayCheck = false;
    }
  }

  //make sensor for time//
  if(dayCheck==true){
    String pricePeriod;

    //check type of pricing period based on the present hour//
    for(int hours=sizeof(supOff01); hours>0; hours--){
      if(supOff02[hours] == hour){
        pricePeriod = "supOff";
        break;
      }
    }
    for(int hours=sizeof(off01); hours>0; hours--){
      if(off01[hours] == hours){
        pricePeriod = "off";
        break;
      }
    }
    for(int hours=sizeof(peak01); hours>0; hours--){
      if(peak01[hours] == hours){
        pricePeriod="peak";
        break;
      }
    }

    //change display on screen --> position 1, 8//
    lcd.setCursor(1,8);
    lcd.print("y");

    Serial.prinln(pricePeriod);
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
