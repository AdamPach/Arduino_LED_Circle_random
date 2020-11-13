#include <Adafruit_NeoPixel.h>

#define pinDIN 3
#define pocetLED 16

Adafruit_NeoPixel rgbWS = Adafruit_NeoPixel(pocetLED, pinDIN, NEO_GRB + NEO_KHZ800);

boolean opakovat = true;
boolean opakovat_r = true;
boolean opakovat_g = true;
boolean opakovat_b = true;

byte con_r = 0;
byte con_g = 0;
byte con_b = 0;


void setup()
{
  rgbWS.begin();
  Serial.begin(9600);
  setRGB(255, 0  , 0  , 1);
  delay(500);
  setRGB(0  , 255, 0  , 2);
  delay(500);
  setRGB(0  , 0  , 255, 3);
  delay(500);
  setRGB(0  , 0  , 0  , 1);
  setRGB(0  , 0  , 0  , 2);
  setRGB(0  , 0  , 0  , 3);
  delay(500);

}

void loop()
{
  int i;
  int r;
  int g;
  int b;
  r = random(256);
  g = random(256);
  b = random(256);
  Serial.print("Cervena: ");
  Serial.println(r);
  Serial.print("Zelena: ");
  Serial.println(g);
  Serial.print("Modra: ");
  Serial.println(b);
  //delay(5000);
  do{
    if(con_r != r){
      if (con_r < r){
        while(opakovat_r){
          con_r = con_r + 1;
            for(i = 0;i <= pocetLED;i++){
            setRGB(con_r,con_g,con_b,i);
          }
            Serial.print("Red+:");
            Serial.println(con_r);
          i = 0;
           if (con_r == r)opakovat_r = false;
        }
      }
    else if (con_r > r){
        while(opakovat_r){
          con_r = con_r - 1;
            for(i = 0;i <= pocetLED;i++){
            setRGB(con_r,con_g,con_b,i);
          }
          Serial.print("Red-:");
          Serial.println(con_r);
          i = 0;
          if (con_r == r)opakovat_r = false;
        }
      }
    }
  else if(con_g != g){
       if (con_g < g){
        while(opakovat_g){
          con_g = con_g + 1;
            for(i = 0;i <= pocetLED;i++){
            setRGB(con_r,con_g,con_b,i);
          }
          Serial.print("Green+:");
          Serial.println(con_g);
          i = 0;
          if (con_g == g)opakovat_g = false;
        }
      }
    else if (con_g > g){
        while(opakovat_g){
          con_g = con_g - 1;
            for(i = 0;i <= pocetLED;i++){
            setRGB(con_r,con_g,con_b,i);
          }
          Serial.print("Green-:");
          Serial.println(con_g);
          i = 0;
          if (con_g == g)opakovat_g = false;
        }
      }
    }
    else if(con_b != b){
      if (con_b < b){
        while(opakovat_b){
          con_b = con_b + 1;
            for(i = 0;i <= pocetLED;i++){
            setRGB(con_r,con_g,con_b,i);
          }
          Serial.print("Blue+:");
          Serial.println(con_b);
          i = 0;
          if (con_b == b)opakovat_b = false;
        }
      }
    else if (con_b > b){
        while(opakovat_b){
          con_b = con_b - 1;
            for(i = 0;i <= pocetLED;i++){
            setRGB(con_r,con_g,con_b,i);
          }
          Serial.print("Blue-:");
          Serial.println(con_b);
          i = 0;
          if (con_b == b)opakovat_b = false;
        }
      }
    }
    else{
    opakovat = false;
    } 
  }while(opakovat);
  opakovat = true;
  opakovat_r = true;
  opakovat_g = true;
  opakovat_b = true;
  //delay(2000);
  
}

void setRGB (byte r, byte g, byte b, int cislo) {
  uint32_t barva;
  barva = rgbWS.Color(r, g, b);
  rgbWS.setPixelColor(cislo - 1, barva);
  rgbWS.show();
}
