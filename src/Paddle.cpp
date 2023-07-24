#include "Paddle.h"

#include "raylib-cpp.hpp"

Paddle::Paddle()
{
	this->_position = _position.Zero();
	this->_width = 0;
	this->_height = 0;
	this->_speed = 0.0f;
	this->_keyUp = KEY_UP;
	this->_keyDown = KEY_DOWN;
}

Paddle::Paddle(float xPos, float yPos, int width, int height, float speed) : Paddle()
{
	this->_position = raylib::Vector2(xPos, yPos);
	this->_width = width;
	this->_height = height;
	this->_speed = speed;
}

Paddle::Paddle(const raylib::Vector2& position, int width, int height, float speed) : Paddle()
{
	this->_position = position;
	this->_width = width;
	this->_height = height;
	this->_speed = speed;
}

raylib::Vector2 Paddle::getPosition()
{
	return this->_position;
}

int Paddle::getWidth()
{
	return this->_width;
}

int Paddle::getHeight()
{
	return this->_height;
}

float Paddle::getSpeed()
{
	return this->_speed;
}

Rectangle Paddle::getHitBox()
{
	float xOrigin = _position.x > GetScreenWidth() / 2.0f ? _position.x : _position.x + _width;
	return Rectangle{ xOrigin, _position.y, 2, (float)_height };
}

void Paddle::setPosition(const raylib::Vector2& position)
{
	this->_position = position;
}

void Paddle::setPosition(float xPos, float yPos)
{
	this->_position = raylib::Vector2(xPos, yPos);
}

void Paddle::setWidth(int width)
{
	this->_width = width;
}

void Paddle::setHeight(int height)
{
	this->_height = height;
}

void Paddle::setSpeed(float speed)
{
	this->_speed = speed;
}

void Paddle::setKeys(KeyboardKey upKey, KeyboardKey downKey)
{
	this->_keyUp = upKey;
	this->_keyDown = downKey;
}

void Paddle::Update()
{
	if (IsKeyDown(_keyUp) && IsKeyUp(_keyDown) && _position.y - _speed >= 0) {
		_position.y -= _speed;
	}

	if (IsKeyDown(_keyDown) && IsKeyUp(_keyUp) && _position.y + _height + _speed <= GetScreenHeight()) {
		_position.y += _speed;
	}
}

void Paddle::Draw()
{
	DrawRectangleRounded(Rectangle{ _position.x, _position.y, (float)_width, (float)_height }, 0.5, 0, WHITE);
}