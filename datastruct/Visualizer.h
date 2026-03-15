#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Visualizer {
public:
	Visualizer();
	void run();
private:
	void handleEvents(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
	void setAlgorithm(int index);
	void update();
	int currAlgorithm = 0;
	float stepDelay = 0.0f;
	const int ARRAY_SIZE = 20;
	const int BAR_AREA_TOP = 120; // where the blocks are on screen
	const int BAR_AREA_BOTTOM = 340;
	const int WIN_W = sf::VideoMode::getDesktopMode().width;
	const int WIN_H = sf::VideoMode::getDesktopMode().height;
	std::vector<int> array;
};