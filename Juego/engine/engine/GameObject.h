#pragma once
#include <GL/glut.h>
#include "Color.h"
#include "Vector3D.h"

class GameObject
{
private:
	Vector3D position;
	Color color;
	Vector3D speed;
	Vector3D orientation;
	Vector3D orientationSpeed;
	bool isAffectedByGravity;
public:
	GameObject() : position(Vector3D()), color(Color()), speed(Vector3D()), orientation(Vector3D()), orientationSpeed(Vector3D()), isAffectedByGravity(true) {}

	GameObject(Vector3D position, Color color, Vector3D speed, Vector3D orientation, Vector3D orientationSpeed, bool isAffectedByGravity) :
		position(position), color(color), speed(speed), orientation(orientation), orientationSpeed(orientationSpeed), isAffectedByGravity(isAffectedByGravity) {}

	inline Vector3D GetPosition() const { return this->position; }
	inline Color GetColor() const { return this->color; }
	inline Vector3D GetSpeed() const { return this->speed; }
	inline Vector3D GetOrientation() const { return this->orientation; }
	inline Vector3D GetOrientationSpeed() const { return this->orientationSpeed; }
	inline bool GetIsAffectedByGravity() const { return this->isAffectedByGravity; }
	inline void SetPosition(const Vector3D& vector) { this->position = vector; }
	inline void SetColor(const Color& colorToSet) { this->color = colorToSet; }
	inline void SetSpeed(const Vector3D& vector) { this->speed = vector; }
	inline void SetOrientation(const Vector3D& vector) { this->orientation = vector; }
	inline void SetOrientationSpeed(const Vector3D& vector) { this->orientationSpeed = vector; }
	inline void SetIsAffectedByGravity(const bool& isAffectedByGravity) { this->isAffectedByGravity = isAffectedByGravity; }

	virtual void Render() = 0;
	virtual void Update(const float& time, const Vector3D& gravity);
};

