// my channel https://www.youtube.com/channel/UCu3tB56Iho4kh9OmMYL498Q


#include <Wire.h>        //i2c library
#include <Adafruit_GFX.h>     //display library
#include <Adafruit_SH1106.h>  //display library

#include <DHT.h>   //DHT library
#define Type DHT11 //type DHT sensor you can also use the DHT with #define Type DHT22

#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET); 

const int senspin = 2; //sensor pin

DHT HT (senspin,Type);

float humidity;
float temperatureC;

void setup() {
  
  HT.begin(); //DHT sensor begin
  
  display.begin(SH1106_SWITCHCAPVCC, 0x3C); //display setup
  display.clearDisplay(); 
  display.setTextColor(WHITE); 
  display.clearDisplay(); 
}

void loop() {
  
humidity=HT.readHumidity();
temperatureC=HT.readTemperature();

  display.setCursor(15,0);
  display.setTextSize(1);
  display.print("DIY bot computers");

  display.setTextSize(2); 
  display.setCursor(20,20);
  display.print(temperatureC);
  display.print(" C");
  
  display.setCursor(20,45);
  display.setTextSize(2);
  display.print(humidity);
  display.print(" %");
  
  delay(100);
  display.display();
  display.clearDisplay();
}
