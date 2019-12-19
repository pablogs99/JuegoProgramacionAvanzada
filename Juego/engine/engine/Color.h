#pragma once
class Color
{
private:
	float red;
	float green;
	float blue;
public:
	Color(float redToSet = 0.0, float greenToSet = 0.0, float blueToSet = 0.0) :red(redToSet), green(greenToSet), blue(blueToSet) {}

	inline float GetRed() const { return this->red; }
	inline float GetGreen() const { return this->green; }
	inline float GetBlue() const { return this->blue; }
	inline void SetRed(const float& redToSet) { this->red = (redToSet >= 0.0 && redToSet <= 1.0 ? redToSet : this->red); }
	inline void SetGreen(const float& greenToSet) { this->red = (greenToSet >= 0.0 && greenToSet <= 1.0 ? greenToSet : this->green); }
	inline void SetBlue(const float& blueToSet) { this->red = (blueToSet >= 0.0 && blueToSet <= 1.0 ? blueToSet : this->blue); }
};

