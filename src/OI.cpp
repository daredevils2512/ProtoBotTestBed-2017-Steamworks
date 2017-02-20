#include "OI.h"
#include "Commands/AutoCircleDrive.h"
#include "Commands/AutoStraightDrive.h"
#include "Subsystems/Drivetrain.h"
#include "Commands/Drive.h"
#include "Commands/GearVisionTurn.h"

#include <WPILib.h>

OI::OI() {
	std::cout << "OI Init" << std::endl;
	//driverController.reset(new Joystick(0));

	// Process operator interface input here.
	DR_button1.WhileHeld(new AutoCircleDrive(1.0 , 1.0 , Drivetrain::Direction::counterClockwise, 0.0)); //spins on a dime
	DR_button6.WhileHeld(new AutoStraightDrive(9.4, 0.75)); //center peg
	DR_button7.WhileHeld(new AutoCircleDrive(64.0, 0.5, Drivetrain::Direction::counterClockwise, 0.0));
	DR_button8.WhileHeld(new AutoCircleDrive(70.0, 0.75, Drivetrain::Direction::counterClockwise, 0.0));
	DR_button9.WhileHeld(new AutoCircleDrive(160.0, 1.0, Drivetrain::Direction::counterClockwise, 0.0));//right peg fast
	DR_button10.WhileHeld(new AutoCircleDrive(129.5, 0.75, Drivetrain::Direction::counterClockwise, 0.0)); //right peg(works)
	DR_button11.WhileHeld(new AutoCircleDrive(91.0, 0.75, Drivetrain::Direction::clockwise, 0.0)); //left peg(works)
	DR_button12.WhileHeld(new AutoCircleDrive(158.0, 1.0, Drivetrain::Direction::clockwise, 0.0));
	//DR_thumbButton.WhileHeld(new GearVisionTurn(159));
}

double OI::GetX() {
	//gets forward/backward values
	return driverController.GetRawAxis(1);

}

double OI::GetY() {
	//gets turning values
	return driverController.GetRawAxis(0);
}

