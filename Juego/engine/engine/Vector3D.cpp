#include "Vector3D.h"

Vector3D Vector3D::Add(const Vector3D& b) {
	Vector3D result(x + b.x, y + b.y, z + b.z);
	return result;
}

Vector3D Vector3D::operator+(const Vector3D& b) {
	Vector3D result(x + b.x, y + b.y, z + b.z);
	return result;
}

Vector3D Vector3D::Substract(const Vector3D& b) {
	Vector3D result;
	result.x = x - b.x;
	result.y = y - b.y;
	result.z = z - b.z;
	return result;
}

Vector3D Vector3D::operator-(const Vector3D& b) {
	Vector3D result;
	result.x = x - b.x;
	result.y = y - b.y;
	result.z = z - b.z;
	return result;
}

Vector3D Vector3D::Product(const float& b) {
	Vector3D result;
	result.x = x * b;
	result.y = y * b;
	result.z = z * b;
	return result;
}

Vector3D Vector3D::operator*(const float& b) {
	Vector3D result;
	result.x = x * b;
	result.y = y * b;
	result.z = z * b;
	return result;
}

Vector3D Vector3D::operator*(const float& b) const {
	Vector3D result;
	result.x = x * b;
	result.y = y * b;
	result.z = z * b;
	return result;
}

Vector3D Vector3D::operator/(const float& m) {
	Vector3D result;
	result.x = x / m;
	result.y = y / m;
	result.z = z / m;
	return result;
}

float Vector3D::DotProduct(const Vector3D& v) {
	float result;
	result = x * v.x + y * v.y + z * v.z;
	return result;
}

float Vector3D::operator*(const Vector3D& v) {
	float result;
	result = x * v.x + y * v.y + z * v.z;
	return result;
}
