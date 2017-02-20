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
	JoystickButton DR_button1{&driverController, 1};
	JoystickButton DR_button6{&driverController, 6};
	JoystickButton DR_button7{&driverController, 7};
	JoystickButton DR_button8{&driverController, 8};
	JoystickButton DR_button9{&driverController, 9};
	JoystickButton DR_button10{&driverController, 10};
	JoystickButton DR_button11{&driverController, 11};
	JoystickButton DR_button12{&driverController, 12};
	JoystickButton DR_thumbButton{&driverController, 2};

public:
	OI();
	double GetX();
	double GetY();
};

#endif  // OI_H
