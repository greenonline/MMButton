#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif


/*

Put this file in your libraries folder along with mmButton.cpp

Written by Mark Fickett
Modified by Julian Loiacono December '14
Further Modification by Greenonline 2017
*/

// These two defines are mutually exclusive
// Inherit/Derive from MomentaryButton
//#define __Use_MomentaryButton__
// Inherit/Derive from MButton
#define __Use_MButton__
//default is MButton
#if defined (__Use_MomentaryButton__) && defined(__Use_MButton__)
#error Oops!  You have defined both __Use_MomentaryButton__ and __Use_MButton__. You can only define one… From which object do you want to derive this object? MButton or MomentaryButton?
#endif

#if defined __Use_MomentaryButton__ 
#include "MomentaryButton.h"
#elif defined __Use_MButton__
#include "MButton.h"
#else
#include "MButton.h"
#endif

/**
 * Encapsulate tracking pushes on a normally-open momentary button.
 *
 * After a call to check(), the button may report that it:
 *  - wasClicked(): tapped briefly
 *  - wasHeld(): pressed for a longer period of time (and perhaps still closed)
 * The next call to check() will not report on that previous event.
 */
#if defined __Use_MomentaryButton__ 
class MMButton: public MomentaryButton {
#elif defined __Use_MButton__
class MMButton: public MButton {
#else
class MMButton: public MButton {
#endif
private:
/*	// Any button press >= HOLD_THRESHOLD milliseconds is considered a hold,
	//	not a click.
//	unsigned long holdThreshold;  // inherited from mButton
//	unsigned long bounceThreshold;// inherited from mButton
	// Was this button pushed (closed) when last checked?
	boolean wasClosed;
	// When was this button pushed (closed)?
	unsigned long closeTimeMillis;
	const int pin;
	boolean clicked, held; // At last check, was this button clicked (held)?
*/
        boolean isPulledUp=HIGH;  // set default here?
public:
	MMButton(int inputPin);
//	void setHoldThreshold(unsigned long newThreshold);
//	void setBounceThreshold(unsigned long newThreshold);
	void setPullUpDown(boolean isUp);
//	void setup();
	void check(); //commented out to reduce compile errors
//	boolean wasClicked();
//	boolean wasHeld();
};
