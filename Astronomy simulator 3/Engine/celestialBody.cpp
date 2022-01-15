#include "celestialBody.h"
#include "constants.h"

vec2d celestialBody::getDistance(celestialBody celBody)
{
	vec2d deltaPos = pos - celBody.pos;
	return deltaPos;
}

void celestialBody::updateVelocity(float dt, celestialBody celBody)
{
	vel += this->getGravity(celBody) * dt;
}

void celestialBody::updatePos(float dt)
{
	pos += vel * dt;
}

void celestialBody::draw(Graphics & gfx)
{
	int x_int = (int)pos.x;
	int y_int = (int)pos.y;
	int R_int = (int)R;

	for (int i = -R_int; i < R_int; i++) {
		for (int j = -R_int; j < R_int; j++) {
			int pix_x = x_int + i;
			int pix_y = y_int + j;
			if (i * i + j * j <= R * R) {
				if (0 < pix_x && pix_x < Graphics::ScreenWidth && 0 < pix_y && pix_y < Graphics::ScreenHeight) gfx.PutPixel(x_int + i, y_int + j, 255, 255, 255);
			}
		}
	}
}

celestialBody::celestialBody(const vec2d& pos_in, const vec2d& vel_in, float mass_in, float R_in)
	:
	pos (pos_in),
	vel (vel_in),
	mass (mass_in),
	R (R_in)
	{}

vec2d celestialBody::getGravity(celestialBody celBody)
{
	vec2d dr = this->getDistance(celBody);
	vec2d drNormalized = dr.normalize();
	float drMod = dr.moduleVector();

	vec2d g = drNormalized * ((-1) * G * mass * celBody.mass / (drMod * drMod));
	
	return g;
}

void celestialBody::update(float dt, celestialBody celBody)
{
	updateVelocity(dt, celBody);
	updatePos(dt);
}
