#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

const sf::Color BACKGROUND_COLOR = sf::Color(43, 43, 41); // grey
const sf::Color BAR_DEFAULT_COLOR = sf::Color(49, 164, 80); // green ish
const sf::Color BAR_COMPARE_COLOR = sf::Color(164, 49, 80); // red
const sf::Color BAR_SORTED_COLOR = sf::Color(111, 237, 255); // light blue

class Bar {
public:
	int value;
	sf::Color color;
	Bar(int value, sf::Color color);
	void draw(sf::RenderWindow& window, float x, float y, float width, float height);
};