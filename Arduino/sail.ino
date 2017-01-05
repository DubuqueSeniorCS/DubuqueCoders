#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 6
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 3
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

int buttonA = A0; 
int buttonB = A1; 
int buttonC = A2; 
int buttonD = A3; 
int valA = 0;
int valB = 0;
int valC = 0;
int valD = 0;
int BUTTON_OFF = 30;
bool prev_Unpressed = false;
bool on = true;
int array_spot = 0;
int OFF = 1;
int RED = 2;
int BLUE = 3;
int PURPLE = 4;
int GREEN = 5;
int YELLOW = 6;
int colors[] = {OFF, // Me, You will be my mom...
                RED, // A red one
                RED, // A blue one
                OFF, // The red one came back
                OFF, // The blue one came back
                RED, // I want to change the world,instead I sleep...
                OFF, // Now
                RED, // Red
                OFF, // I hear
                BLUE, // Blue
                OFF, // I feel 
                PURPLE,// Purple
                OFF, // I taste
                GREEN, // Green 
                YELLOW,// I choose yellow
                OFF, // Land ho!
                RED, // The storm is coming but i don't mind...
                OFF,// Now
                255};
int colors2[] = {OFF, // Me, You will be my mom...
                OFF, // A red one
                BLUE, // A blue one
                BLUE, 
                OFF,
                BLUE,
                OFF,
                RED,
                OFF,
                BLUE,
                OFF,
                PURPLE,
                OFF,
                GREEN,
                OFF,
                YELLOW,
                OFF,
                BLUE,
                OFF,
                 255};
int colors3[] = {OFF, // Me, You will be my mom...
                RED, // A red one
                RED, // A blue one
                OFF, 
                1, 2, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 2, 1,255};

/*#if defined(ARDUINO_SAMD_ZERO) && defined(SERIAL_PORT_USBVIRTUAL)+
  // Required for Serial on Zero based boards
  #define Serial SERIAL_PORT_USBVIRTUAL
#endif*/



// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(buttonA, INPUT);
  Serial.begin(9600);
  Serial.println("Loaded");
  pixels.begin(); // This initializes the NeoPixel library.
}

void getColor(int n)
{
	for(int pixelNumber=0;pixelNumber<NUMPIXELS;pixelNumber++)
	{
		if (n==1)
        {
			pixels.setPixelColor(pixelNumber, 0,0,0);
          	digitalWrite(led, LOW);
    		on = false;
            Serial.println("setPixelColor = Off");
    	}
 		else if (n==2)
   		{
			pixels.setPixelColor(pixelNumber, 255,0,0);
            Serial.println("setPixelColor = RED");
    	}
		else if (n==3)
    	{
			pixels.setPixelColor(pixelNumber, 0,0,255);
            Serial.println("setPixelColor = BLUE");
    	}
		else if (n==4)
    	{
			pixels.setPixelColor(pixelNumber, 160,32,240);
            Serial.println("setPixelColor = PURPLE");
    	}
      else if (n==5)
    	{
			pixels.setPixelColor(pixelNumber, 0,255,0);
            Serial.println("setPixelColor = GREEN");
    	}
      else if (n==6)
    	{
			pixels.setPixelColor(pixelNumber, 255,255,0);
            Serial.println("setPixelColor = YELLOW");
    	}
	}
}
  
/*void handleButtonEvent()  {
     // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for(int pixelNumber=0;pixelNumber<NUMPIXELS;pixelNumber++){
    if(on){
      digitalWrite(led,HIGH);
      //pixels.setPixelColor(pixelNumber, 255,0,0);
    }
    else{
      digitalWrite(led,LOW);
     // pixels.setPixelColor(pixelNumber, 0,0,255);
    }
  }
}

*/

// the loop routine runs over and over again forever:
void loop() 
{
  
/*digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second*/
  valA = analogRead(buttonA);
  //Serial.print(valA,3);
  valB = analogRead(buttonB);
//  valC = analogRead(buttonC);
//  valD = analogRead(buttonD);
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
//  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
//  //  if (valA <= BUTTON_OFF){
//    //  pixels.setPixelColor(i, pixels.Color(255,0,0)); // off
//      digitalWrite(led, HIGH);
//      Serial.println(" button off");
//    }
//    /*else if (valB <= BUTTON_OFF){
//      pixels.setPixelColor(i, pixels.Color(0,0,255)); // off
//    }
//    else if (valC <= BUTTON_OFF){
//      pixels.setPixelColor(i, pixels.Color(0,255,0)); // off
//    }
//    else if (valD <= BUTTON_OFF){
//      pixels.setPixelColor(i, pixels.Color(255,255,0)); // off
//    }*/
//    else{
//      pixels.setPixelColor(i, pixels.Color(0,255,0)); // Moderately bright green color.
//      digitalWrite(led, LOW);
//      Serial.println("button on");
   // }
    
   // pixels.show(); // This sends the updated pixel color to the hardware.
 if (valB > BUTTON_OFF)
    {
		if(prev_Unpressed)
        {
          if (array_spot == 0)
          {
            array_spot = 0;
          }
          if(array_spot>0)
          {  
            array_spot--;
           	getColor(colors[array_spot]);
            Serial.print("Next array_spot=");
          	Serial.println(array_spot);
          	Serial.print("Next colors[array_spot]=");
          	Serial.println(colors[array_spot]);
       	
          }
        }
		else
        {
          prev_Unpressed = true;
        }
          	
       
    } 
	
    
    if (valA > BUTTON_OFF)
    {
		if(prev_Unpressed)
        {			         
        	getColor(colors[array_spot]);
          
          
        	prev_Unpressed = false;
          if(array_spot != 255) array_spot++;
          	Serial.print("Next array_spot=");
          	Serial.println(array_spot);
          	Serial.print("Next colors[array_spot]=");
          	Serial.println(colors[array_spot]);
       	} 
       
    } 
	else
    {
      prev_Unpressed = true;
    }
pixels.show();
}
