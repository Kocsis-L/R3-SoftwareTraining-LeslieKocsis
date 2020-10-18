//Code by Kocsis L. 
//L293D inputs
const int mout1 = 5;
const int mout2 = 6;
const int mout3 = 9;
const int mout4 = 10; 
//DIP switch inputs
int dip[3];
//potentiometer
double pot;
int pwm;

void setup()
{
  	//DIP Pull-Ups
  	pinMode(2, INPUT_PULLUP); //dip1
  	pinMode(4, INPUT_PULLUP); //dip2
  	pinMode(7, INPUT_PULLUP); //dip3
  	pinMode(8, INPUT_PULLUP); //dip4
  	//A2D converter pot pin
  	pinMode(A0, INPUT); 
    pinMode(mout1, OUTPUT); //pin2
    pinMode(mout2, OUTPUT);	//pin7
 	pinMode(mout3, OUTPUT);	//pin15
  	pinMode(mout4, OUTPUT);	//pin10
  	Serial.begin(9600);
}

void forward(int pwm)
{
  	//right motor
	analogWrite(mout1, pwm);
    digitalWrite(mout2, LOW);
  	//left motor
  	analogWrite(mout3, pwm);
  	digitalWrite(mout4, LOW);
}

void reverse(int pwm)
{
  	//right motor
	analogWrite(mout2, pwm);
    digitalWrite(mout1, LOW);
  	//left motor
  	analogWrite(mout4, pwm);
  	digitalWrite(mout3, LOW);
}

void left(int pwm)
{
  	//right motor reverse
	analogWrite(mout2, pwm);
    digitalWrite(mout1, LOW);
  	//left motor forward
  	analogWrite(mout3, pwm);
  	digitalWrite(mout4, LOW);
}

void right(int pwm)
{
	//right motor foward
  	analogWrite(mout1, pwm);
    digitalWrite(mout2, LOW);
  	//left motor reverse
  	analogWrite(mout4, pwm);
  	digitalWrite(mout3, LOW);
}

void stop(int pwm)
{
  digitalWrite(mout1, LOW);
  digitalWrite(mout2, LOW);
  digitalWrite(mout3, LOW);
  digitalWrite(mout4, LOW);
}
   
void loop()
{
  	pot = analogRead(A0);
	pwm = map(pot, 1023, 0, 1, 255);
  	Serial.println(pwm);
  	dip[0] = digitalRead(2);
  	dip[1] = digitalRead(4);
  	dip[2] = digitalRead(7);
  	dip[3] = digitalRead(8);
  	//Dip Switch logics
  	if(dip[0] == LOW && dip[1] == HIGH 
      && dip[2] == HIGH && dip[3] == HIGH)
    	forward(pwm);
  	else if(dip[0] == HIGH && dip[1] == LOW 
      && dip[2] == HIGH && dip[3] == HIGH)
  		reverse(pwm);
    else if(dip[0] == HIGH && dip[1] == HIGH 
      && dip[2] == LOW && dip[3] == HIGH)
  		left(pwm);
    else if(dip[0] == HIGH && dip[1] == HIGH 
      && dip[2] == HIGH && dip[3] == LOW)
  		right(pwm);    
      else
      	stop(pwm);    	
}


