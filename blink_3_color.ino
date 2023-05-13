
#define		LED_RED		9
#define		LED_GREEN	10
#define		LED_BLUE	11

#define		MAIN_DELAY		2000

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
}

uint8_t		i = 0;

void loop()
{
  digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ HIGH);
  if ( i == 0 ) {
		digitalWrite( LED_RED, HIGH );
		digitalWrite( LED_GREEN, HIGH );
		digitalWrite( LED_BLUE, HIGH );
		delay(MAIN_DELAY);
		digitalWrite( LED_RED, HIGH );
		digitalWrite( LED_GREEN, HIGH );
		digitalWrite( LED_BLUE, HIGH );
	} else {
		delay(MAIN_DELAY);
	}
	if ( ++i > 3 ) i = 0;
	delay(MAIN_DELAY);
}
