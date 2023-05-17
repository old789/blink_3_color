
#define   LED_RED   9
#define   LED_GREEN 10
#define   LED_BLUE  11

#define   MAIN_DELAY    2000

uint8_t   mode = 1;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  if ( mode == 3) randomSeed(analogRead(0));
}

uint8_t   i = 0;
uint8_t   state = LOW;
uint8_t   color = LED_RED;

void loop() {
  switch (mode) {
    case 1:
      all_colors_in_turn();
      break;
    case 2:
      fade_3_colors_in_turn();
      break;
    case 3:
      random_base_colors();
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
  PORTB = ( state << 1 ) & B1110;

  state++;
  state &= 7;

  for ( uint8_t j = 0; j < 2 ; j++ ) {
    digitalWrite( LED_BUILTIN, digitalRead(LED_BUILTIN) ^ HIGH );
    delay(MAIN_DELAY / 2);
  }
}

void fade_3_colors_in_turn(){
  if ( ( color < LED_RED ) || ( color > LED_BLUE ) ) {
    color = LED_RED;
    state = 0;
    i = 0;
  }
  if ( state == 0 ) {
    i += 0xf;
  } else {
    i -= 0xf;
  }
  analogWrite( color, i );
  digitalWrite( LED_BUILTIN, ~state & HIGH );
  if ( state == 0 ) {
    if ( i > 0xf0 ) state = 1;
  } else {
    if ( i < 0xf ) {
      state = 0;
      color++;
      if ( color  > LED_BLUE ) {
        color = LED_RED;
      }
    }
  }
  delay( 300 );
 }
 
void random_base_colors() {
  color = (uint8_t)random(0,3) + LED_RED;
  digitalWrite( color, HIGH );
  delay( 1000 );
  digitalWrite( color, LOW );
}