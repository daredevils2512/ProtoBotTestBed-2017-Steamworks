#include "RobotMap.h"
#include "WPILib.h"

std::shared_ptr<Talon> RobotMap::drivetrainFrontLeftMotor;
std::shared_ptr<Talon> RobotMap::drivetrainRearLeftMotor;
std::shared_ptr<Talon> RobotMap::drivetrainFrontRightMotor;
std::shared_ptr<Talon> RobotMap::drivetrainRearRightMotor;
std::shared_ptr<frc::RobotDrive> RobotMap::drivetrainChassis;
std::shared_ptr<frc::SPI> RobotMap::gearRealPixy;
std::shared_ptr<frc::SPI> RobotMap::gearFakePixy;
std::shared_ptr<Pixy> RobotMap::gearPixy;
std::shared_ptr<frc::Encoder> RobotMap::drivetrainLeftEncoder;
std::shared_ptr<frc::Encoder> RobotMap::drivetrainRightEncoder;

void RobotMap::init() {
	//assigns ports and settings to pointer objects declared in RobotMap.h
	//Creating new instances of the subsystems
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

	//drivetrainFrontLeftMotor.reset (new Talon(5));
	//lw->AddActuator("Drivetrain" , "FrontLeftMotor" , drivetrainFrontLeftMotor);

	drivetrainRearLeftMotor.reset (new Talon(0));
	lw->AddActuator("Drivetrain" , "RearLeftMotor" , drivetrainRearLeftMotor);

	//drivetrainFrontRightMotor.reset (new Talon(3));
	//lw->AddActuator("Drivetrain" , "FrontRightMotor" , drivetrainFrontRightMotor);

	drivetrainRearRightMotor.reset (new Talon(1));
	drivetrainRearRightMotor->SetInverted(true);
	lw->AddActuator("Drivetrain" , "RearRightMotor" , drivetrainRearRightMotor);

	drivetrainChassis.reset (new frc::RobotDrive(drivetrainRearLeftMotor,drivetrainRearRightMotor));
	drivetrainChassis->SetSafetyEnabled(true);
	drivetrainChassis->SetExpiration(0.5 );
	drivetrainChassis->SetSensitivity(0.3);
	drivetrainChassis->SetMaxOutput(1.0);

	gearRealPixy.reset (new frc::SPI(frc::SPI::kOnboardCS0));
	gearFakePixy.reset (new frc::SPI(frc::SPI::kOnboardCS3));

	gearPixy.reset (new Pixy(gearRealPixy, gearFakePixy));

    drivetrainLeftEncoder.reset(new frc::Encoder(0, 1, false, frc::Encoder::k4X));
    lw->AddSensor("Drivetrain", "LeftEncoder", drivetrainLeftEncoder);
    drivetrainLeftEncoder->SetDistancePerPulse(0.0153846154);
    drivetrainLeftEncoder->SetPIDSourceType(frc::PIDSourceType::kRate);

    drivetrainRightEncoder.reset(new frc::Encoder(2, 3, false, frc::Encoder::k4X));
    lw->AddSensor("Drivetrain", "RightEncoder", drivetrainRightEncoder);
    drivetrainRightEncoder->SetDistancePerPulse(0.0153846154);
    drivetrainRightEncoder->SetPIDSourceType(frc::PIDSourceType::kRate);
}
