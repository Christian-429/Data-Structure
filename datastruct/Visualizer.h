#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graph.h"



class Visualizer {
private:
	const int WIN_W = sf::VideoMode::getDesktopMode().width;
	const int WIN_H = sf::VideoMode::getDesktopMode().height;
	const int BAR_AREA_TOP = 120;
	const int BAR_AREA_BOTTOM = 640;
	const int ARRAY_SIZE = 10;


	Graph barGraph;
	std::vector<int> array;
	

	void render(sf::RenderWindow& window);
	void handleEvents(sf::RenderWindow& window);

public:
	Visualizer();
	void run();
};