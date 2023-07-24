#include "Ball.h"

#include "raylib-cpp.hpp"

Ball::Ball()
{
	_position = _position.Zero();
	_speed = _speed.Zero();
	_radius = 1;
}

Ball::Ball(float xPos, float yPos, float xSpeed, float ySpeed, float radius)
{
	this->_position = raylib::Vector2(xPos, yPos);
	this->_speed = raylib::Vector2(xSpeed, ySpeed);
	this->_radius = radius;
}

Ball::Ball(float xPos, float yPos, const raylib::Vector2& speed, float radius)
{
	this->_position = raylib::Vector2(xPos, yPos);
	this->_speed = speed;
	this->_radius = radius;
}

Ball::Ball(const raylib::Vector2& position, float xSpeed, float ySpeed, float radius)
{
	this->_position = position;
	this->_speed = raylib::Vector2(xSpeed, ySpeed);
	this->_radius = radius;
}

Ball::Ball(const raylib::Vector2& position, const raylib::Vector2& speed, float radius)
{
	this->_position = position;
	this->_speed = speed;
	this->_radius = radius;
}

raylib::Vector2 Ball::getPosition()
{
	return this->_position;
}

raylib::Vector2 Ball::getSpeed()
{
	return this->_speed;
}

float Ball::getRadius()
{
	return this->_radius;
}

void Ball::setPosition(const raylib::Vector2& position)
{
	this->_position = position;
}

void Ball::setPosition(float xPos, float yPos)
{
	this->_position = raylib::Vector2(xPos, yPos);
}

void Ball::setSpeed(const raylib::Vector2& speed)
{
	this->_speed = speed;
}

void Ball::setSpeed(float xSpeed, float ySpeed)
{
	this->_speed = raylib::Vector2(xSpeed, ySpeed);
}

void Ball::setRadius(float radius)
{
	this->_radius = radius;
}

void Ball::checkCollisionWithRect(Rectangle hitBox)
{
	if (CheckCollisionCircleRec(_position, _radius, hitBox)) {
		_speed.x *= -1;

		// Fix
		if (_position.x < GetScreenWidth() / 2.0f) {
			if (_position.x - _radius < hitBox.x) {
				_position.x = hitBox.x + _radius + 1;
			}
		}
		else if (_position.x + _radius > hitBox.x) {
			_position.x = hitBox.x - _radius - 1;
		}
	}
}

void Ball::resetPosition()
{
	_position.x = GetScreenWidth() / 2.0f;
	_position.y = GetScreenHeight() / 2.0f;
}

void Ball::Update()
{
	// Check if next pos is outside screen
	Vector2 newPos = _position + _speed;
	if (newPos.y + _radius >= GetScreenHeight() || newPos.y - _radius <= 0) { _speed.y *= -1; }
	if (newPos.x + _radius >= GetScreenWidth() || newPos.x - _radius <= 0) { _speed.x *= -1; }

	// Move
	_position += _speed;
}

void Ball::Draw()
{
	DrawCircle((int)_position.x, (int)_position.y, _radius, WHITE);
}