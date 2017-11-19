//Stepper2Laser
// Developed by Scott Ziv, and released under GPLv3. 

//Converts step/direction/enable pins to the TTL input of a diode laser for use with homebrew Laser sintering machines
//Use at your own risk!

//Configuration Variables

double powerModifier = 1.00; //

//End of Configuration Variables


#define stp 2
#define dir 3
#define ttl 6
#define en 7

int stepspd = 255; //speed of steps. Eventually, this should be based off of steps and step speed, but as of now, its just constant full on.

void setup() 
{
  pinMode(stp, INPUT);
  pinMode(en, INPUT);
  pinMode(dir, INPUT);
  pinMode(ttl, OUTPUT);
}

void loop() 
{
  if((digitalRead(en)==0)&&(digitalRead(dir)==1))
  {
    digitalWrite(ttl, (stepspd*powerModifier));
  }
  else
  {
    digitalWrite(ttl, 0); //shut off the laser
  }
}
