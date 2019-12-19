#include "GameObject.h"

void GameObject::Update(const float& time, const Vector3D& gravity)
{
	if (this->GetIsAffectedByGravity())
	{
		this->SetSpeed(Vector3D(this->GetSpeed() + gravity * time));
	}
	this->SetPosition(Vector3D(this->GetPosition() + this->GetSpeed() * time));
	this->SetOrientation(
		Vector3D(
			this->GetOrientation().GetX() + time * this->GetOrientationSpeed().GetX(), 
			this->GetOrientation().GetY() + time * this->GetOrientationSpeed().GetY(), 
			this->GetOrientation().GetZ() + time * this->GetOrientationSpeed().GetZ()
		)
	);
}
