
  #define BYTESIZE 1000
  #define tap1 (BYTESIZE-BYTESIZE/5)
  #define tap2 (BYTESIZE-1)    //and the other is the longest value stored in the array.int dialPin = A3; //potentiometer pin

int val = 0;//potentiometer value 
//defines LED PINS
int dialPin=A3 ; 
int red_light_pin= 9;
int green_light_pin = 10;
int blue_light_pin = 11;
int analogPin=A0;//defines pin used for the ADC
int loopct=0;
int delaybuffer[1000]; 
int Asig,tap,oldtap1,oldtap2,Aout;
byte shfreg;
void RGB_color(int red_light_value, int green_light_value, int blue_light_value);
void setup() {
 digitalWrite(2,LOW);
 digitalWrite(2,HIGH);
  Serial.begin(115200);  
  for (int i=0;i<=1000;i++){
    delaybuffer[i]=0;
            
  }
pinMode(A2,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}


void loop() {
  while(1){
 //sets the index of the array
  if (loopct>1000){
    loopct=0;
  }
  else {
   loopct++;}
  
 Asig=analogRead(analogPin)-450; 

  delayMicroseconds(20);
  tap=loopct-tap1;
  if (tap<0)
    tap+=BYTESIZE;
    
 oldtap1=delaybuffer[tap];
  
  tap=loopct-tap2;
  if (tap<0)
    tap+=BYTESIZE;
    
 oldtap2=delaybuffer[tap];

  oldtap1/=3;
  oldtap2/=4;

Aout=Asig+oldtap1+oldtap2;
delaybuffer[loopct]=Aout;
shfreg=map(Aout+450,0,1023,0,255);//digital to analog converter is only 8bits so we have to scale the output down to 8bits by mapping the solution
  digitalWrite(6,LOW);
  shiftOut(3,5,MSBFIRST,shfreg);
  digitalWrite(6,HIGH);
  delay(5);
  Serial.println(shfreg);
  }


 
    val = analogRead(dialPin); 
int red=map(val,0,1023,50,255);
Serial.println(red);
RGB_color(red,10,5);
if (red>245){
  RGB_color(255,5,0);}
}

//a function that writes the rgb values into the LED
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}



//The following funtion is extracted from:
//http://forum.arduino.cc/index.php?topic=16612#msg121031

void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
