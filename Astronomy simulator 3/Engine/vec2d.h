#pragma once
class vec2d
{
public:
	vec2d () = default;
	vec2d(float x, float y);
	vec2d operator+ (const vec2d& rhs) const;
	vec2d& operator+= (const vec2d& rhs);
	vec2d operator* (const float rhs) const;
	vec2d& operator*= (const float rhs);
	vec2d operator- (const vec2d& rhs) const;
	float moduleVector();
	vec2d normalize();
	//include dot product and cross product

public:
	float x;
	float y;
};

