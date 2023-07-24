#pragma once

#include "raylib-cpp.hpp"

class Paddle
{
private:
	raylib::Vector2 _position;
	int _width;
	int _height;
	float _speed;
	KeyboardKey _keyUp;
	KeyboardKey _keyDown;

public:
	Paddle();
	Paddle(float xPos, float yPos, int width, int height, float speed);
	Paddle(const raylib::Vector2& position, int width, int height, float speed);

	raylib::Vector2 getPosition();
	int getWidth();
	int getHeight();
	float getSpeed();
	Rectangle getHitBox();

	void setPosition(const raylib::Vector2& position);
	void setPosition(float xPos, float yPos);
	void setWidth(int width);
	void setHeight(int height);
	void setSpeed(float speed);
	void setKeys(KeyboardKey upKey, KeyboardKey downKey);

	void Update();
	void Draw();
};