#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Talon.h"

class Drivetrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<Talon> FrontLeftMotor;
	std::shared_ptr<Talon> RearLeftMotor;
	std::shared_ptr<Talon> FrontRightMotor;
	std::shared_ptr<Talon> RearRightMotor;

	//creating two master references
	std::shared_ptr<Talon> Right;
	std::shared_ptr<Talon> Left;
	std::shared_ptr<RobotDrive> Chassis;

public:

	struct Speeds {
		double leftSpeed;
		double rightSpeed;
	};

	enum class Direction {
		clockwise,
		counterClockwise,
		straight
	};

	Drivetrain();
	void InitDefaultCommand();
	void DriveRobotArcade(double move, double turn);
	void DriveRobotTank(double leftSide, double rightSide);
	void Shifter (frc::DoubleSolenoid::Value dir);
	double GetEncoders();
	Speeds AutoCalcSpeeds(double radius, double outerSpeed, Direction direction);
	void AutoSetSpeeds(Speeds theSpeeds);
	bool IsWithinThreshold(double obj1X, double obj2X, int threshold);

};

#endif
