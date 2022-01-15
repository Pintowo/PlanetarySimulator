#pragma once
#include "vec2d.h"
#include "Graphics.h"


class celestialBody
{
private:
	//Variables
	float mass;
	float R;
	vec2d pos;
	vec2d vel;

	//Functions
	vec2d getDistance(celestialBody celBody);
	void updateVelocity(float dt, celestialBody celBody);
	void updatePos(float dt);

public:
	//Initializers
	celestialBody() = default;
	celestialBody(const vec2d& pos_in, const vec2d& vel_in, float mass_in, float R);

	//Functions
	vec2d getGravity(celestialBody celBody);
	void update(float dt, celestialBody celBody); //make it so you can update the object not regarding just one celBody. Maybe introduce an array(?

	//Graphics
	void draw(Graphics& gfx);
};

