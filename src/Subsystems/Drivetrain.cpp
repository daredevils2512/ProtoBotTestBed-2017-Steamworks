#include "Drivetrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {

    Chassis = RobotMap::drivetrainChassis;
    Right = RobotMap::drivetrainRearRightMotor;
    Left = RobotMap::drivetrainRearLeftMotor;

    leftEncoder = RobotMap::drivetrainLeftEncoder;
    rightEncoder = RobotMap::drivetrainRightEncoder;
}

void Drivetrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());

	SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drivetrain::DriveRobotTank(double leftSpeed, double rightSpeed) {
	//drives robot in tank mode from specified values
	Chassis->TankDrive(leftSpeed, rightSpeed);
	std::cout << "Tank Drive: " << leftSpeed << std::endl;
	std::cout << "Tank Drive: " << rightSpeed << std::endl;
}

void Drivetrain::DriveRobotArcade(double move, double turn) {
	//drives robot in arcade mode from specified values (TELEOP)
	Chassis->ArcadeDrive(move, turn, false); //remove the boolean

}

double distancePerPulse = 0.0981747704246;

double Drivetrain::GetEncoders() {
	//gets distance moved since last reset scaled by distance per pulse
	return ((leftEncoder->Get() + rightEncoder->Get()) / 2) * distancePerPulse;
}

void Drivetrain::ResetEncoders() {
	//resets the drivetrain encoder values
	leftEncoder->Reset();
	rightEncoder->Reset();
}

double Drivetrain::GetLeftEncoder() {
	return leftEncoder->Get() * distancePerPulse;
};

double Drivetrain::GetRightEncoder() {
	return rightEncoder->Get() * distancePerPulse;
};

Drivetrain::Speeds Drivetrain::AutoCalcSpeeds(double radius/*in inches*/, double outerSpeed, Direction direction){
	Speeds theSpeeds;
	int width = 25;
	double innerSpeed = ((radius - width / 2) / (radius + width/2) * outerSpeed);
	if(direction == Direction::clockwise){
		theSpeeds.leftSpeed = outerSpeed;
		theSpeeds.rightSpeed = innerSpeed;
		std::cout << "Direction: Clockwise" << std::endl;
		std::cout << "Drivetrain: Outer speed " << outerSpeed << std::endl;
		std::cout << "Drivetrain: Inner speed " << innerSpeed << std::endl;
		std::cout << "Drivetrain: Radius " << radius << std::endl;
	}else if(direction == Direction::counterClockwise){
		std::cout << "Direction: Counter-Clockwise" << std::endl;
		std::cout << "Drivetrain: Outer speed " << outerSpeed << std::endl;
		std::cout << "Drivetrain: Inner speed " << innerSpeed << std::endl;
		std::cout << "Drivetrain: Radius " << radius << std::endl;
		theSpeeds.leftSpeed = innerSpeed;
		theSpeeds.rightSpeed = outerSpeed;
	}else if (direction == Direction::straight){
		std::cout << "Direction: Straight" << std::endl;
		std::cout << "Drivetrain: Outer speed " << outerSpeed << std::endl;
		std::cout << "Drivetrain: Inner speed " << innerSpeed << std::endl;
		std::cout << "Drivetrain: Radius " << radius << std::endl;
		theSpeeds.leftSpeed = outerSpeed;
		theSpeeds.rightSpeed = outerSpeed;
	}
	return theSpeeds;
}

bool Drivetrain::IsWithinThreshold(double obj1X, double obj2X, int threshold) {
	int tol = threshold / 2;
	return (obj1X - tol <= obj2X && obj1X + tol >= obj2X) && (obj2X - tol <= obj1X && obj2X + tol >= obj1X);
}
