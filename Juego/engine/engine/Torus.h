#pragma once
#include "GameObject.h"
class Torus : public GameObject
{
private:
	float innerRadius;										// Inner radius of the torus.
	float outerRadius;										// Outer radius of the torus.
	int sides;												// Number of sides for each radial section.
	int rings;												// Number of radial divisions for the torus.
public:
	Torus() :GameObject(), innerRadius(0.3f), outerRadius(1.0f), sides(20), rings(20) {}
	inline float GetInnerRadius() { return innerRadius; }
	inline void SetInnerRadius(float ir) { innerRadius = ir; }
	inline float GetOuterRadius() { return outerRadius; }
	inline void SetOuterRadius(float r) { outerRadius = r; }
	inline int GetSides() { return sides; }
	inline void SetSides(int s) { sides = s; }
	inline int GetRings() { return rings; }
	inline void SetRings(int r) { rings = r; }

	void Render();
};

