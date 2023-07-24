#pragma once

#include "raylib-cpp.hpp"

class Ball {
private:
	raylib::Vector2 _position;
	raylib::Vector2 _speed;
	float _radius;

public:
	Ball();
	Ball(float xPos, float yPos, float xSpeed, float ySpeed, float radius);
	Ball(float xPos, float yPos, const raylib::Vector2& speed, float radius);
	Ball(const raylib::Vector2& position, float xSpeed, float ySpeed, float radius);
	Ball(const raylib::Vector2& position, const raylib::Vector2& speed, float radius);

	raylib::Vector2 getPosition();
	raylib::Vector2 getSpeed();
	float getRadius();

	void setPosition(const raylib::Vector2& position);
	void setPosition(float xPos, float yPos);
	void setSpeed(const raylib::Vector2& speed);
	void setSpeed(float xSpeed, float ySpeed);
	void setRadius(float radius);

	void checkCollisionWithRect(Rectangle hitBox);
	void resetPosition();

	void Update();
	void Draw();
};