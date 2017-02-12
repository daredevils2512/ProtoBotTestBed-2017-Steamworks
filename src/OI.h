#ifndef OI_H
#define OI_H

#include "WPILib.h"


//creates all of the inputs on the controllers
class OI
{
private:
	//declares controllers
	Joystick driverController{0};
	//Joystick driverController{0};

	JoystickButton DR_button7{&driverController, 7};
	JoystickButton DR_button8{&driverController, 8};
	JoystickButton DR_button9{&driverController, 9};
	JoystickButton DR_thumbButton{&driverController, 2};

public:
	OI();
	double GetX();
	double GetY();
};

#endif  // OI_H
