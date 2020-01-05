// Define the notes you want to play
int C = 2; //261.63 HZ
int D = 3; //293.66 Hz
int E = 4; //329.63 Hz
int F = 5; //349.23 Hz
int G = 6; //392.00 Hz
int A = 7; //440.00 Hz

int speaker = 8;

volatile int period[6] = {3822,3405,3034,2863,2551,2273};
int debounceTime[6] = {0,0,0,0,0,0};
int debounceDelay = 15;

void setup() {
  // This starts the serial monitor. Not strictly necessary, nice to debug.
  // Serial.begin(9600);
  
  for (int i = 2; i <= 7; i++) {
    pinMode(i, INPUT);
  }

  // We want to output to the speaker
  pinMode(speaker, OUTPUT);
}

void playNote(int note, int inputLine) {
  long elasped_time = 0;
  bool last = true;
  while (last) {
    // This is debouncing.
    if ((millis() - debounceTime[inputLine-2]) > debounceDelay) {
      // whatever the reading is at, it's been there for longer than the debounce delay, so take it as the actual current state:
      // if the button state has changed:
      if (digitalRead(inputLine) != last) {
        last = !last;
      }
    }
    //UP: FIrst half of the square wave cycle
    digitalWrite(speaker, HIGH);
    delayMicroseconds(note / 2);

    //DOWN: Second half of the square wave cycle
    digitalWrite(speaker, LOW);
    delayMicroseconds(note /2 );

    //Keep track of how long we pulsed (this also isn't really necessary)
    elasped_time += (note);
  }
}

void loop() {
  for (int i = 2; i <= 7; i++){
    if (digitalRead(i)) {
      debounceTime[i - 2] = millis();
      playNote(period[i - 2], i);
    }
  }
}
