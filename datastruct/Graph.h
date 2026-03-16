#pragma once
#include "Bar.h"
#include <vector>



class Graph {
private:
	std::vector<Bar> bars;
	int areaTop;
	int areaBottom;
	int winW;
	float margin;
public:
	Graph(int areaTop, int areaBottom, int winW, float margin = 40.f);

	void setBars(const std::vector<int>& values, sf::Color color);
	void setColor(int index, sf::Color color);
	void draw(sf::RenderWindow& window);

};