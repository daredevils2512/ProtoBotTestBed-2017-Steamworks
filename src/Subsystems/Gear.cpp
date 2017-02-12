#include "Gear.h"
#include "../RobotMap.h"

Gear::Gear() : Subsystem("Gear") {
	pixyCamera = RobotMap::gearPixy;
}

void Gear::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Gear::UpdateObjectData() {
	pixyCamera->CollectFrameData();
}

bool Gear::ObjectExists(Nullable<Pixy::ObjectValues> object) {
	return (object.HasValue() && !pixyCamera->IsFrameEmpty());
}

Nullable<Pixy::ObjectValues> Gear::GetObjectData(int objectIndex) {
	targetObject = pixyCamera->GetObjectData(objectIndex);
	if(ObjectExists(targetObject)) {
		return Nullable<Pixy::ObjectValues>(targetObject.GetValue());
	}else{
		return Nullable<Pixy::ObjectValues>();
	}
}
