/*
  timer : Set the sample timing
    timerFlag : Enable or disable the timer
  TimerSample : Total sampling sample
  
  data : The data is the command from the mobile phone 
  counter : Count the sample nnumber

*/

#include <SimpleTimer.h>

SimpleTimer Timer;

int timer[3] = {0};
int timerFlag = 0;
int TimerSample = 0;

void setup() {
  // Open the serial port and set the baud
  Serial.begin(9600);

  // Clear the serial buffer data
  while(Serial.available())
    int a = Serial.read();
  
  // Set the timer that triggered every 20 ms, Fs = 50Hz
  timer[0] = Timer.setInterval(20,GetSignal);
  
  // Set the timer that triggered every 10 ms, Fs = 100Hz
  timer[1] = Timer.setInterval(10,GetSignal);
  
  // Set the timer that triggered every 5 ms, Fs = 200Hz
  timer[2] = Timer.setInterval(5,GetSignal);
  
  // Set the check system that triggered every 5ms
  Timer.setInterval(5,CounterCheck);
  
  // Disable the timer
  Timer.disable(timer[0]);
  Timer.disable(timer[1]);
  Timer.disable(timer[2]);
}

int data = 0;
int counter = 0;

void loop() {
  
  // Wait the command data from mobile phone
  if(Serial.available()){
    data = Serial.read();
    if(data == '0'){
        Timer.enable(timer[0]); // Enable the timer
        TimerSample = 50;       // Set sample point to 50 
        timerFlag = 0;          // Set the timerFlag to 0
    }
    else if(data == '1'){
        Timer.enable(timer[1]); // Enable the timer
        TimerSample = 100;      // Set sample point to 100 
        timerFlag = 1;          // Set the timerFlag to 1
    }
    else if(data == '2'){
      Timer.enable(timer[2]);  // Enable the timer
      TimerSample = 200;       // Set sample point to 100
      timerFlag = 2;           // Set the timerFlag to 2
    }
  }
  Timer.run();
}
// Send the data to mobile phone
void GetSignal()
{
  int data = analogRead(A0);
  Serial.write(data >> 8);
  Serial.write((byte)data);
  counter++;
}
// Check the sample point
void CounterCheck()
{
  if(counter == TimerSample){
    Timer.disable(timerFlag);
    counter = 0;
  }
}
