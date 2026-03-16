#include "bar.h"

Bar::Bar(int value, sf::Color color) {
	this->value = value;
	this->color = color;
}


void Bar::draw(sf::RenderWindow& window, float x, float y, float width, float height) {
	sf::RectangleShape shape(sf::Vector2f(width - 1.f, height));
	shape.setPosition(x, y);
	shape.setFillColor(color);
	window.draw(shape);
}