#ifndef GearVisionTurn_H
#define GearVisionTurn_H

#include <CMATH>

#include "../CommandBase.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "../Pixy.h"
#include "../Subsystems/Gear.h"
#include "../Subsystems/Drivetrain.h"

class GearVisionTurn : public CommandBase {
public:
	GearVisionTurn(double targetX);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	int CenterXFinder(double obj1, double obj2);
	int CenterYFinder(double obj1, double obj2);
	bool IsHeightSame(double obj1, double obj2, double threshold);
	bool IsYSame(double obj1, double obj2, double threshold);
	void TurnDirection(double m_targetX , double centerX);

private:
	double m_targetX;
};

#endif  // GearVisionTurn_H