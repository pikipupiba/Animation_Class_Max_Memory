// LEDObject.h

#include <FastLED.h>

#ifndef _LEDOBJECT_h
#define _LEDOBJECT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

// An LED Object is the interface that the program uses to talk to all the possible animation
// objects. Not all animations use all the variables but this class is meant for controllers
// with a little more memory anyway and it makes things easier.

class LEDObjectClass
{
 protected:
	// A seperate array to store all the LED values for each animation.
	CRGBArray<NUM_LEDS> leds;

	// The index position helps layer different animation together in the final step.
	float indexPosition;

	// This gives you the ability to reflect an animation any number of times to properly display
	// on different strip arrangements. Ex: a rectangular panel, a triangle, etc
	int numberOfReflections;

	// These store information about where an animation starts and ends.
	// Floats allow for fine control and slow movement.
	float rangeStart;
	float rangeEnd;
	float rangeSize;

	// Certain attributes will be chosen from a list of possible choices.
	enum Texture {Solid, Gradient, Bumpy, Rainbow, Transparent};
	enum Overlay {Strobe, Twinkle};
	enum EndOfRange {Continue, Bounce, Fade};

	// Floats allow for fine control and slow movement.
	float brightness;
	float hue;
	float hueSpeed;
	float hueAcceleration;

	// Position can either be where an object is in it's range or what step in a sequence it is on.
	// Floats allow for fine control and slow movement.
	float position;
	float speed;
	float acceleration;

	// Used by some animations that only take up a small portion of the total range
	// alotted to them at any one time.
	// Floats allow for fine control and slow movement.
	float featureSize;
	float end1;
	float end2;

	// Used to copy an animation in space with an offset color and position.
	// Floats allow for fine control and slow movement.
	int numRepeats;
	float repeatPositionOffset;
	float repeatHueOffset;
	
 public:
	void init();
};

extern LEDObjectClass LEDObject;

#endif

