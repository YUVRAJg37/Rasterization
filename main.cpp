#include <iostream>
#include "imgui.h"
#include "imgui-SFML.h"
#include "Grid/Grid.h"

constexpr int width = 600;
constexpr int height = 600;
constexpr int gridRows = 50;
constexpr int gridColumn = 50;

sf::Color bgColor(18, 33, 43);

void HandlePaint(sf::RenderWindow* window, Grid* grid);
sf::Vector2f GetMouseLocalPosition(sf::RenderWindow* window);

enum MouseState
{
	MS_Idle,
	MS_RightHold,
	MS_LeftHold
} mouseState(MS_Idle);

float currentCol[3];

int main()
{
	sf::RenderWindow window(sf::VideoMode(width, height), "Rasterization");
	ImGui::SFML::Init(window);
	Grid grid(height, width, gridColumn, gridRows, &window);

	grid.SetDrawGridLines(true);
	grid.SetGridCellsColor(sf::Color::White);
	grid.SetGridLinesColor(sf::Color::Black);

	sf::Clock deltaClock;

	while(window.isOpen())
	{
		sf::Event event;

		while(window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);

			if(event.type == sf::Event::Closed)
			{
				window.close();
			}

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				grid.ResetGrid();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				mouseState = MS_LeftHold;
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
				mouseState = MS_RightHold;
			else
				mouseState = MS_Idle;
		}

		ImGui::SFML::Update(window, deltaClock.restart());

		HandlePaint(&window, &grid);

		ImGui::Begin("Menu");
		ImGui::ColorPicker3("Pixel Color", currentCol);
		ImGui::End();

		window.clear(bgColor);
		grid.DrawGrid();
		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();

	return 0;
}

void HandlePaint(sf::RenderWindow* window, Grid* grid)
{
	if (mouseState == MS_LeftHold)
	{
		int row = (int)GetMouseLocalPosition(window).y / (height / gridColumn);
		int col = (int)GetMouseLocalPosition(window).x / (width / gridRows);
		int index = (row * gridColumn) + col;
		grid->SetGridCellColor(index, sf::Color(currentCol[0]*255, currentCol[1]*255, currentCol[2]*255));
	}

	if(mouseState == MS_RightHold)
	{
		int row = (int)GetMouseLocalPosition(window).y / (height / gridColumn);
		int col = (int)GetMouseLocalPosition(window).x / (width / gridRows);
		int index = (row * gridColumn) + col;
		grid->SetGridCellColor(index, grid->GetGridCellsColor());
	}
}

sf::Vector2f GetMouseLocalPosition(sf::RenderWindow* window)
{
	sf::Vector2i mouseGlobalPos = sf::Mouse::getPosition(*window);
	sf::Vector2f mouseLocalPos = window->mapPixelToCoords(mouseGlobalPos);

	if (mouseLocalPos.x < 0)
		mouseLocalPos.x = 0;
	if (mouseLocalPos.x > width)
		mouseLocalPos.x = width;

	if (mouseLocalPos.y < 0)
		mouseLocalPos.y = 0;
	if (mouseLocalPos.y > height)
		mouseLocalPos.y = height;

	return mouseLocalPos;
}
