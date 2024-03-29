#include <Commands/_CMG_AutonomousGearClosePeg.h>
#include <Commands/AutoCircleDrive.h>
#include "../Subsystems/Drivetrain.h"
#include "AutoStraightDrive.h"
#include "AutoDimeSpin.h"
#include "../Robot.h"
#include "PauseCommand.h"
#include "GearVisionTurn.h"

_CMG_AutonomousGearClosePeg::_CMG_AutonomousGearClosePeg(bool gotoHopper) {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
//	AddSequential(new AutoCircleDrive(160.0, 1.0, Drivetrain::Direction::counterClockwise, 80.0));
	if(Robot::robotAlliance == frc::DriverStation::kBlue) {
		AddSequential(new AutoStraightDrive(46.0, 0.7));
		AddSequential(new PauseCommand(0.2));
		AddSequential(new AutoDimeSpin(0.9, 16.25, Robot::drivetrain->Direction::clockwise));
		AddSequential(new PauseCommand(0.2));
		AddSequential(new AutoStraightDrive(30.0, 0.7));//44
//		AddSequential(new PauseCommand(0.2));
//		AddSequential(new GearVisionTurn(216));
//		AddSequential(new PauseCommand(0.2));
//		AddSequential(new GearVisionTurn(216));
//		AddSequential(new PauseCommand(0.2));
//		AddSequential(new GearVisionTurn(216));
		AddSequential(new PauseCommand(0.2));
		AddSequential(new AutoStraightDrive(13.0, 0.5));
		if(gotoHopper) {
			AddSequential(new PauseCommand(0.5));
			AddSequential(new PauseCommand(1.0));
			AddSequential(new AutoStraightDrive(25.0, -0.7));
			AddSequential(new PauseCommand(0.2));
			AddSequential(new AutoDimeSpin(0.9, 30.0, Robot::drivetrain->Direction::counterClockwise));
			AddSequential(new PauseCommand(0.2));
			AddSequential(new AutoStraightDrive(44.0, 0.7));
			AddSequential(new PauseCommand(0.5));
		}
	}else{
		AddSequential(new AutoStraightDrive(45.0, 0.7));
		AddSequential(new PauseCommand(0.2));
		AddSequential(new AutoDimeSpin(0.9, 19.0, Robot::drivetrain->Direction::counterClockwise));
		AddSequential(new PauseCommand(0.2));
		AddSequential(new AutoStraightDrive(30.0, 0.7));//44
		AddSequential(new PauseCommand(0.2));
		AddSequential(new GearVisionTurn(216));
		AddSequential(new PauseCommand(0.2));
		AddSequential(new GearVisionTurn(216));
		AddSequential(new PauseCommand(0.2));
		AddSequential(new GearVisionTurn(216));
		AddSequential(new PauseCommand(0.2));
		AddSequential(new AutoStraightDrive(12.0, 0.7));
		if(gotoHopper) {
			AddSequential(new PauseCommand(0.5));
			AddSequential(new PauseCommand(1.0));
			AddSequential(new AutoStraightDrive(25.0, -0.7));
			AddSequential(new PauseCommand(0.2));
			AddSequential(new AutoDimeSpin(0.9, 38.0, Robot::drivetrain->Direction::clockwise));
			AddSequential(new PauseCommand(0.2));
			AddSequential(new AutoStraightDrive(42.0, 0.7));
			AddSequential(new PauseCommand(0.5));
		}
	}
}
