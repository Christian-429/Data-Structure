#include "Visualizer.h"


void Visualizer::render(sf::RenderWindow& window) {
	window.clear(BACKGROUND_COLOR);
	barGraph.draw(window);
	window.display();
}
void Visualizer::handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();
}

Visualizer::Visualizer() : barGraph(BAR_AREA_TOP, BAR_AREA_BOTTOM, WIN_W) {
    srand(time(0));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array.push_back(rand() % (20 - 1 + 1) + 1);
        std::cout << array[i] << std::endl;
    }
    barGraph.setBars(array, BAR_DEFAULT_COLOR);
}
void Visualizer::run() {
    sf::VideoMode vm(WIN_W, WIN_H);
    sf::RenderWindow window(vm, "Sort Visualizer", sf::Style::Default);

    sf::Clock clock;
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        handleEvents(window);
        render(window);
    }
}