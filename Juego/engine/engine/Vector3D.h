#pragma once
class Vector3D
{
private:
	float x;
	float y;
	float z;
public:
	Vector3D(float x=0, float y=0, float z=0) : x(x), y(y), z(z) {}
	
	Vector3D(const Vector3D& vector)
	{
		this->x = vector.x;
		this->y = vector.y;
		this->z = vector.z;
	}

	inline float GetX() const { return this->x; }
	inline float GetY() const { return this->y; }
	inline float GetZ() const { return this->z; }
	inline void SetX(const float& d) { this->x = d; }
	inline void SetY(const float& d) { this->y = d; }
	inline void SetZ(const float& d) { this->z = d; }

	Vector3D Add(const Vector3D& b);
	Vector3D Substract(const Vector3D& b);
	Vector3D Product(const float& b);
	float DotProduct(const Vector3D& v);

	Vector3D operator+(const Vector3D& b);
	Vector3D operator-(const Vector3D& b);
	Vector3D operator*(const float& b);
	Vector3D operator*(const float& b) const;
	Vector3D operator/(const float& b);
	float operator*(const Vector3D& v);
};

