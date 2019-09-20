/*
	Example project to control a segment display with the SN74HC595 shift register
*/

int pinSer = 2;
int pinOE = 3;
int pinRCLK = 4;
int pinSRCLK = 5;
int pinSRCLR = 6;

byte numbers[] = {0b11111100, 0b01100000, 0b11011010, 0b11110010, 0b01100110, 0b10110110, 0b10111110, 0b11100000, 0b11111110, 0b11110110};

void setup() {

	Serial.begin(9600);

	pinMode(pinSer, OUTPUT);
	pinMode(pinOE, OUTPUT);
	pinMode(pinRCLK, OUTPUT);
	pinMode(pinSRCLK, OUTPUT);
	pinMode(pinSRCLR, OUTPUT);

	// disable output
	digitalWrite(pinOE, LOW);

	// Register not cleared
	digitalWrite(pinSRCLR, HIGH);
}


void loop() {
  
	clearRegister();
  
  //countDown();
  countUp();
	
}


void clearRegister() {
	// clearing the register
	digitalWrite(pinSRCLR, LOW);
	delay(100);
	digitalWrite(pinSRCLR, HIGH);
 delay(100);
}


void writeByte(byte data){
  
	digitalWrite(pinSRCLR, HIGH);
	delay(30);
  
	for(byte mask = 00000001; mask > 0; mask <<= 1){
		if(data & mask){
		    digitalWrite(pinSer, HIGH);
		}else{
			digitalWrite(pinSer, LOW);
		}
		delay(30);

		digitalWrite(pinSRCLK, HIGH);
		delay(30);
		digitalWrite(pinSRCLK, LOW);
		digitalWrite(pinSer, LOW);
	}

	digitalWrite(pinRCLK, HIGH);
	delay(30);
	digitalWrite(pinRCLK, LOW);
}



void countDown(){

  for(int i = sizeof(numbers) - 1; i >= 0 ; i--){
    writeByte(numbers[i]);
    delay(500);
    clearRegister();
  }
}

void countUp(){
  for(int i = 0; i < sizeof(numbers); i++){
    writeByte(numbers[i]);
    delay(500);
    writeByte(numbers[i] + 1);
    delay(500);
    clearRegister();
  }
}
