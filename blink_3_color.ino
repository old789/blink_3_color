
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

uint8_t   mode = 1;

uint8_t   i = 0;
uint8_t   state = LOW;

void loop() {
  switch (mode) {
    case 1:
      all_colors_in_turn();
      break;
    default:
      blink_4_color();
  }
}

void blink_4_color() {
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

void all_colors_in_turn() {
  uint8_t kl = 0;
  
  for ( uint8_t j = 0; j < 3 ; j++ ) {
    kl = ( state >> j ) & 1;
    digitalWrite( ( j + LED_RED ), kl );
  }

  state++;
  state &= 7;

  for ( uint8_t j = 0; j < 2 ; j++ ) {
    digitalWrite( LED_BUILTIN, digitalRead(LED_BUILTIN) ^ HIGH );
    delay(MAIN_DELAY / 2);
  }
}
