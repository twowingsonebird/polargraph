#pragma once
#include <cmath>
#include <functional>

struct vec2 {
	float x, y;
};

struct Parametric2D {
 	std::function<float(float)> y;  // function for y(t)
	std::function<float(float)> x;
	vec2 evaluate(float t) const {
		return { x(t), y(t) };
	}
};

class polargraph 
{
public:
	polargraph();
	vec2 singlePointC2P(vec2 point, float height, float width);
	float linearSpeed4Motor(float initalAorB, float AorB, float dt);
	Parametric2D straightLine(float h, float k, float i, float j);

private:
	float speed;
	float height;
	float width;
};