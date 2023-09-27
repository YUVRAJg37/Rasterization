#include "Grid/Grid.h"

constexpr int width = 600;
constexpr int height = 600;

sf::Color bgColor(18, 33, 43);

int main()
{
	sf::RenderWindow window(sf::VideoMode(width, height), "Rasterization");

	Grid grid(height, width, 20, 20, &window);

	while(window.isOpen())
	{
		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(bgColor);
		grid.DrawGrid();
		window.display();
	}

	return 0;
}