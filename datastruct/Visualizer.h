#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
class Visualizer {
public:
	Visualizer();
	void run();
private:
	void handleEvents(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
	void update();

	void resetArray();

	void setAlgorithm(int index);
	int currAlgorithm = 0;

	float stepDelay = 0.05f;
	float timer = 0.f;

	const int ARRAY_SIZE = 5;
	const int BAR_AREA_TOP = 120; // where the blocks are on screen
	const int BAR_AREA_BOTTOM = 640;
	const int WIN_W = sf::VideoMode::getDesktopMode().width;
	const int WIN_H = sf::VideoMode::getDesktopMode().height;
	std::vector<int> array;
};