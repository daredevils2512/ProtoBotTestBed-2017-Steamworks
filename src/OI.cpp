#include "OI.h"
#include "Commands/AutoDrive.h"
#include "Subsystems/Drivetrain.h"
#include "Commands/Drive.h"
#include "Commands/GearVisionTurn.h"

#include <WPILib.h>

OI::OI() {
	std::cout << "OI Init" << std::endl;
	//driverController.reset(new Joystick(0));

	// Process operator interface input here.
	DR_button7.WhileHeld(new AutoDrive(1.0, 1.0, Drivetrain::Direction::clockwise));
	DR_button8.WhileHeld(new AutoDrive(1.0, 1.0, Drivetrain::Direction::counterClockwise));
	DR_button9.WhileHeld(new AutoDrive(1.0, 1.0, Drivetrain::Direction::straight));
	DR_thumbButton.WhileHeld(new GearVisionTurn(159));
}

double OI::GetX() {
	//gets forward/backward values
	return driverController.GetRawAxis(1);

}

double OI::GetY() {
	//gets turning values
	return driverController.GetRawAxis(0);
}

