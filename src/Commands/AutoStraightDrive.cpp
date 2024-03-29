#include "AutoStraightDrive.h"
#include "../Robot.h"
#include "../Subsystems/Drivetrain.h"

AutoStraightDrive::AutoStraightDrive(double targetFeet, double speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::drivetrain.get());
	m_targetFeet = targetFeet;
	m_speed = speed;
}

// Called just before this Command runs the first time
void AutoStraightDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoStraightDrive::Execute() {
	Robot::drivetrain->DriveRobotTank(m_speed, m_speed);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoStraightDrive::IsFinished() {
//	double leftDistance = abs(Robot::drivetrain->GetLeftEncoder());
//	double rightDistance = abs(Robot::drivetrain->GetRightEncoder());
//	if(abs(leftDistance - rightDistance) > 2) {
//		//set lagging encoder to value of other encoder
//		if(leftDistance > rightDistance) {
//			rightDistance = leftDistance;
//		}else{
//			leftDistance = rightDistance;
//		}
//	}
//	return (leftDistance + rightDistance) / 2 > m_targetFeet;
	return false;
}

// Called once after isFinished returns true
void AutoStraightDrive::End() {
	Robot::drivetrain->DriveRobotTank(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoStraightDrive::Interrupted() {

}
