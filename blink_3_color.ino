
#define   LED_RED   9
#define   LED_GREEN 10
#define   LED_BLUE  11

#define   MAIN_DELAY    2000

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
}

uint8_t   i = 0;
uint8_t   state = LOW;

void loop() {
  state ^= HIGH;
  digitalWrite( LED_BUILTIN, state );
  if ( i == 0 ) {
    for ( uint8_t j = 0; ( j + LED_RED ) <= LED_BLUE; j++ ) {
      digitalWrite( ( j + LED_RED ), state );
    }
  } else {
    digitalWrite( ( i + LED_RED - 1 ), state );
  }
  if ( state == LOW ) {
    i++;
    if ( i > 3 ) {
      i = 0;
    }
  }
  delay(MAIN_DELAY);
}
