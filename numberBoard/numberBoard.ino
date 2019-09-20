int pinSer = 2;
int pinOE = 3;
int pinRCLK = 4;
int pinSRCLK = 5;
int pinSRCLR = 6;

void setup() {


	pinMode(pinSer, OUTPUT);
	pinMode(pinOE, OUTPUT);
	pinMode(pinRCLK, OUTPUT);
	pinMode(pinSRCLK, OUTPUT);
	pinMode(pinSRCLR, OUTPUT);

	// disable output
	digitalWrite(pinOE, HIGH);

	// Register not cleared
	digitalWrite(pinSRCLR, HIGH);
}


void loop() {
	clearRegister();
}


void clearRegister() {
	// clearing the register
	digitalWrite(pinSRCLR, LOW);
	digitalWrite(pinSRCLR, HIGH);
}


void writeByte(Byte data){

	digitalWrite(pinSRCLR, HIGH);
	for(Byte mask = 00000001; mask > 0; mask <<= 1){

	}
}


