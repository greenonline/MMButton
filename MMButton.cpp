/*

Put this file in your libraries folder along with mmButton.h

Written by Mark Fickett
Modified by Julian Loiacono December '14
Further Modification by Greenonline 2017
*/

#include "MMButton.h"


#if defined __Used_MomentaryButton__ 
MMButton::MMButton(int inputPin)
	: MomentaryButton(inputPin)
#elif defined __Use_MButton__
MMButton::MMButton(int inputPin)
	: MButton(inputPin)
#else
MMButton::MMButton(int inputPin)
	: MButton(inputPin)
#endif
{ 
        const int MMpin = inputPin;  // there isn't any need for this, since we can use getPin(), 
                                     // however, it may be quicker to use this const, instead of a function call
}
/*
void MMButton::setHoldThreshold(unsigned long newThreshold)
{
//	super.setThreshold(newThreshold;  // not required, we can just call setThreshold() as below
//Temporary comment for testing with MomentaryButton
#if !defined (__Use_MomentaryButton__)
	setThreshold(newThreshold);
#endif
//Temporary comment for testing with MomentaryButton
}

void MMButton::setBounceThreshold(unsigned long newThreshold)
{
#if !defined (__Use_MomentaryButton__)
	setBounceThreshold(newThreshold);
#endif
}
*/
//void MMButton::setup()
//{
//	pinMode(pin, INPUT);
//	digitalWrite(pin, HIGH);
//	holdThreshold = 250;
//	bounceThreshold = 50;
//}

void MMButton::setPullUpDown(boolean isUp)
{
	isPulledUp = isUp;
        digitalWrite(getPin(), isPulledUp);
}
/* commented out to reduce compile errors
void MMButton::check()
{
	unsigned long currentTimeMillis = millis();
        boolean isClosed = (digitalRead(MMpin) == !isPulledUp);

//	if (isPulledUp)
//          boolean isClosed = (digitalRead(MMpin) == LOW);
//        else
//          boolean isClosed = (digitalRead(MMpin) == HIGH);


	if (isClosed & !wasClosed)
	{
		closeTimeMillis = currentTimeMillis;
	}
	else if (!isClosed & wasClosed)
	{
		held = (currentTimeMillis - closeTimeMillis) >= holdThreshold;
		clicked = (!held && (currentTimeMillis - closeTimeMillis) >= bounceThreshold);
	}

	wasClosed = isClosed;
}
*/ // commented out to reduce compile errors

void MMButton::check()  // Using getters and setters
{
	unsigned long currentTimeMillis = millis();
        boolean isClosed = (digitalRead(getPin()) == !isPulledUp);

//	if (isPulledUp)
//          boolean isClosed = (digitalRead(MMpin) == LOW);
//        else
//          boolean isClosed = (digitalRead(MMpin) == HIGH);


	if (isClosed & !getWasClosed())
	{
		setCloseTimeMillis(currentTimeMillis);
	}
	else if (!isClosed & getWasClosed())
	{
		setHeld((currentTimeMillis - getCloseTimeMillis()) >= getHoldThreshold());
		setClicked((!getHeld() && (currentTimeMillis - getCloseTimeMillis()) >= getBounceThreshold()));
	}

	setWasClosed(isClosed);
}

/*
boolean MomentaryButton::wasClicked() {
	if (clicked){
		clicked = false;
		return true;
	}
	else{
		return false;
	}
}

boolean MomentaryButton::wasHeld() {
	if (held){
		held = false;
		return true;
	}
	else{
		return false;
	}
}
*/