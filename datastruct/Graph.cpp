#include "Graph.h"


Graph::Graph(int areaTop, int areaBottom, int winW, float margin) {
	this->areaTop = areaTop;
	this->areaBottom = areaBottom;
	this->winW = winW;
	this->margin = margin;
}

void Graph::setBars(const std::vector<int>& values, sf::Color color) {
	bars.clear();
	for (int v : values) {
		bars.emplace_back(v, color);
	}
}


void Graph::setColor(int index, sf::Color color) {
	bars[index].color = color;
}

void Graph::draw(sf::RenderWindow& window) {
	int n = bars.size();
	if (n == 0) return;

	int maxValue = 0;
	for (auto& b : bars) {
		if (b.value > maxValue) maxValue = b.value;
	}
	int barAreaHeight = areaBottom - areaTop;
	float barWidth = static_cast<float>(winW - margin * 2) / n;

	for (int i = 0; i < n; i++) {
		float barHeight = (static_cast<float>(bars[i].value) / maxValue) * barAreaHeight;
		float x = margin + i * barWidth;
		float y = areaBottom - barHeight;
		bars[i].draw(window, x, y, barWidth, barHeight);
	}
}


