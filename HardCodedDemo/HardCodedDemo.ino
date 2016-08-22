// Demo sketch for Sparkfun EL Sequencer
// Various example patterns
// Future: sync patterns to detected song's bpm


void setup() {
  // The EL channels are on pins 2 through 9
  // Initialize the pins as outputs
  pinMode(2, OUTPUT);  // channel A  
  pinMode(3, OUTPUT);  // channel B   
  pinMode(4, OUTPUT);  // channel C
  pinMode(5, OUTPUT);  // channel D    
  pinMode(6, OUTPUT);  // channel E
  pinMode(7, OUTPUT);  // channel F
  pinMode(8, OUTPUT);  // channel G
  pinMode(9, OUTPUT);  // channel H
  // We also have two status LEDs, pin 10 on the Escudo, 
  // and pin 13 on the Arduino itself
  pinMode(10, OUTPUT);     
  pinMode(13, OUTPUT);    
}

void loop() 
{
  float bpm = 200;
  unsigned long waitTime = getWaitTime(bpm);
  
  line(waitTime);
  zigzag(waitTime);
}

/* Other Helper Functions */
void flashEL(int pin, unsigned long waitTime)
{
  digitalWrite(pin, HIGH);  // turn on EL channel
  delay(waitTime);
  digitalWrite(pin, LOW);   // turn off EL channel
}

/* BPM Analysis Funcitons */

// Get the wait time from bpm
unsigned long getWaitTime(float bpm)
{
  // note: temporary function. currently uses a makeshift equation
  return bpm;
}

/* Pattern Functions */
void line(float waitTime)
{
  int x,status;
  
  // Step through all eight EL channels (pins 2 through 9)
  for (x=2; x<=9; x++)
  {
    flashEL(x, waitTime);


    // Note: Currently using prints to understand exactly how status
    //       is being used in this code (is it a keyword? how does it
    //       get initialized? etc.
    // Note: Once figured out, will eventually factor out and distribute
    //       amongst all of the pattern functions.
    Serial.println("Loop");     // DEBUG
    Serial.println(status);     // DEBUG
    digitalWrite(10, status);   // blink both status LEDs
    digitalWrite(13, status);
    status = !status;
    Serial.println(status);     // DEBUG
  }
}

// note: will wait time be different for each pattern based on bpm?
//       basically, should we pass in bpm or pass in waitTime?
//       if we pass in bpm, each pattern will have to calculate its own
//       waittime.
//       I think in the long run we'll want to pass in bpm, but for now
//       we'll use waitTime until it's time to refactor
void zigzag(float waitTime)
{
  int x; // pin number
  
  // Step through all eight EL channels forward then backward
  // Spend double time on each end channel
  for (x=2; x<=9; x++)
  {
    flashEL(x, waitTime);
  }
  for (x=9; x>=2; x++)
  {
    flashEL(x, waitTime);
  }
}
