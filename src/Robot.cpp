#include "Robot.h"

//access pointer objects declared in Robot.h
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	std::cout << "Robot Init" << std::endl;
	RobotMap::init();
	//starts subsystems and creates new instances of them
    drivetrain.reset(new Drivetrain());
    //starts operator interface
    std::cout << "Robot OI Init" << std::endl;
    oi.reset(new OI());
  }

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	//starts autonomous
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
