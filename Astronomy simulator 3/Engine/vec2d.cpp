#include "vec2d.h"
#include <math.h>

vec2d::vec2d(float x_in, float y_in)
{
	x = x_in;
	y = y_in;
}

vec2d vec2d::operator+ (const vec2d & rhs) const
{
	return vec2d (x + rhs.x, y + rhs.y);
}

vec2d & vec2d::operator+=(const vec2d & rhs)
{
	return *this = *this + rhs;
}

vec2d vec2d::operator*(const float rhs) const
{
	return vec2d (x * rhs, y * rhs);
}

vec2d& vec2d::operator*=(const float rhs)
{
	return *this = *this * rhs;
}

vec2d vec2d::operator-(const vec2d & rhs) const
{
	return vec2d(x - rhs.x, y - rhs.y);
}

float vec2d::moduleVector()
{
	return (float) sqrt(x * x + y * y);
}

vec2d vec2d::normalize()
{
	float mod = this->moduleVector();
	return vec2d (x / mod, y / mod);
}
