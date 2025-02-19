#include "polargraph.h"

polargraph::polargraph() {
	speed = 1; // speed unit?
	height = 1; // unit?
	width = 1;
}

vec2 polargraph::singlePointC2P(vec2 point, float height, float width) 
{
	float A = sqrt(pow(point.x, 2) + pow((height - point.y), 2));
	float B = sqrt(pow((width - point.x), 2) + pow((point.y), 2));
	return { A,B };
}

float polargraph::linearSpeed4Motor(float initialAorB, float AorB, float dt) 
{
	float velocity = (AorB - initialAorB) / dt;
	return velocity;
}

Parametric2D polargraph::straightLine(float h, float k, float i, float j)
{
	return {
		[=](float t) { return sqrt(pow((t * (i - h) + h), 2) + pow((h - t * (j - k) - k), 2)); },
		[=](float t) { return sqrt(pow((width - t * (i - h) - h), 2) + pow((h - t * (j - k) - k), 2)); }
	};
}
