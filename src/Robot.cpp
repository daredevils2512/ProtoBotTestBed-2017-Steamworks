#include "Robot.h"

#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <ios>
#include <stdlib.h>

#include "Commands/_CMG_AutonomousGearFarPeg.h"
#include "Commands/_CMG_AutonomousGearCenterPeg.h"
#include "Commands/_CMG_AutonomousGearClosePeg.h"
#include "Commands/_CMG_AutonomousHopper.h"

//access pointer objects declared in Robot.h
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::unique_ptr<OI> Robot::oi;
frc::DriverStation::Alliance Robot::robotAlliance;
std::shared_ptr<PixySubsystem> Robot::pixySubsystem;

void Robot::RobotInit() {
	std::cout << "Robot Init" << std::endl;
	RobotMap::init();
	//starts subsystems and creates new instances of them
    drivetrain.reset(new Drivetrain());
    //starts operator interface
    std::cout << "Robot OI Init" << std::endl;
    oi.reset(new OI());
    pixySubsystem.reset(new PixySubsystem());
  }

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	//starts autonomous
	std::ifstream ifs("/ProtoAuton.txt");
	std::string autonomous = "";
	while (!ifs.eof()) {
			std::string firstPart;
			std::string lastPart;
			std::getline(ifs, firstPart, ':');
			std::getline(ifs, lastPart);
			while(lastPart[0] == ' '){
				lastPart = lastPart.substr(1);
			}
			if(!ifs.eof()){
				lastPart = lastPart.substr(0,lastPart.size()-1);
			}
			if (firstPart == "Autonomous") {
				if (lastPart == "Far") {
					autonomousCommand.reset(new _CMG_AutonomousGearFarPeg());
				} else if (lastPart == "Close") {
					autonomousCommand.reset(new _CMG_AutonomousGearClosePeg(false));
				} else if (lastPart == "Center") {
					autonomousCommand.reset(new _CMG_AutonomousGearCenterPeg());
				} else if (lastPart == "Hopper") {
					autonomousCommand.reset(new _CMG_AutonomousHopper());
				}
			} else if (firstPart == "DoHopper") {
				if (lastPart == "Yes") {
					autonomousCommand.reset(new _CMG_AutonomousGearClosePeg(true));
				} else if (lastPart == "No") {
					autonomousCommand.reset(new _CMG_AutonomousGearClosePeg(false));
				}

			}
		}
		ifs.close();
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();

//	Robot::drivetrain->ResetEncoders();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	//stops autonomous command
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	//prints information to the smart dashboard
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);
