#include "Visualizer.h"


const sf::Color BACKGROUND_COLOR = sf::Color(43, 43, 41); // grey
const sf::Color BAR_DEFAULT_COLOR = sf::Color(49, 164, 80); // green ish
const sf::Color BAR_COMPARE_COLOR = sf::Color(164, 49, 80); // red
const sf::Color BAR_SORTED_COLOR = sf::Color(111, 237, 255); // light blue


Visualizer::Visualizer() {
	setAlgorithm(0);
	resetArray();
	for (int i = 0; i < ARRAY_SIZE; i++) {
		array.push_back(rand() % (20 - 1 + 1) + 1);
		std::cout << array[i] << std::endl;
	}
}
void Visualizer::resetArray() {
	timer = 0;
}
void Visualizer::run() {
	sf::VideoMode vm(WIN_W, WIN_H);
	sf::RenderWindow window(vm, "sort Visualizer", sf::Style::Default);

	sf::Clock clock;
	while (window.isOpen()) {
		float dt = clock.restart().asSeconds();
		handleEvents(window);
		render(window);
	}

}
void Visualizer::render(sf::RenderWindow& window) {
	window.clear(BACKGROUND_COLOR);
	int n = ARRAY_SIZE;
	if (n == 0) { window.display(); return; }
	int maxValue = 0;
	for (int k = 0; k < ARRAY_SIZE; k++) {
		if (array[k] > maxValue) {
			maxValue = array[k];
		}
	}
	float margin = 40.f;
	int barAreaHeight = BAR_AREA_BOTTOM - BAR_AREA_TOP;
	float barWidth = static_cast<float>(WIN_W - margin * 2) / n;
	//draw bars
	for (int i = 0; i < n; i++) {
		float barHeight = (static_cast<float>(array[i]) / maxValue) * barAreaHeight;
		float x = margin + i * barWidth;
		float y = BAR_AREA_BOTTOM - barHeight;

		sf::Color color = BAR_DEFAULT_COLOR;
		sf::RectangleShape bar(sf::Vector2f(barWidth - 1.f,barHeight));
		bar.setPosition(x, y);
		bar.setFillColor(color);
		window.draw(bar);
	}
	window.display();
}
void Visualizer::handleEvents(sf::RenderWindow& window) {
	sf::Event event;

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) { window.close(); }

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		window.close();
	}
}
void Visualizer::setAlgorithm(int index) {
	currAlgorithm = index;
}