
#include "Free_Fonts.h" // Include the header file attached to this sketch
#include "SPI.h"
#include "TFT_eSPI.h"
#include "lcd_backlight.hpp"
#include <cstdint>

// Use hardware SPI
TFT_eSPI tft = TFT_eSPI();
bool stringComplete =false;
bool numberComplete =false;
String str1 = "";
String oldStr1="";

static LCDBackLight backLight;

void setup(void) {
    Serial.begin(115200);
    tft.begin();
    tft.setRotation(1);
    tft.setTextDatum(MC_DATUM);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.fillScreen(TFT_BLACK);            
    tft.setFreeFont(FSS24);                 
    tft.setTextSize(2);
    backLight.initialize();  
}
int brightness=10;
void loop() {
    std::uint8_t maxBrightness = backLight.getMaxBrightness();
    serialevent();
    if(stringComplete==true){
      //Serial.println(str1);
      if(str1.startsWith("B="))
      {
        brightness =str1.substring(2).toInt();
        //Serial.println(brightness);
        if((brightness>0)&&(brightness<102))
        {
          //Serial.println(brightness);
          backLight.setBrightness((brightness-1));
          Serial.println("OK");
        }
        else{
          Serial.println("ERROR");
        }
      }
      else if(str1.startsWith("S="))
      {
        tft.fillScreen(TFT_BLACK);
        tft.drawString(str1.substring(2), 160, 100, GFXFF);
        Serial.println("OK");
      }
      else if(str1=="whoami"){
        Serial.println("WIO");
      }
      else
      {
        Serial.println("ERROR");
      }
      str1="";
      stringComplete=false;
    }    
}

void serialevent(){
  while (Serial.available()){
    //Serial.println("I am here");
    char inChar =(char)Serial.read();
    if(inChar=='{'){
     str1="";
    }
    else if(inChar == '}'){
      stringComplete =true;
      while(Serial.available())
      {
       char garbage =(char)Serial.read(); 
      }
    }
    else
    str1 +=inChar;    
  }
}


#ifndef LOAD_GLCD
    //ERROR_Please_enable_LOAD_GLCD_in_User_Setup
#endif

#ifndef LOAD_GFXFF
    ERROR_Please_enable_LOAD_GFXFF_in_User_Setup!
#endif
