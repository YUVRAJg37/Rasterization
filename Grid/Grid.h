#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Grid
{
public:

	Grid();
	Grid(const int viewportHeight, const int viewportWidth, int gridColumns, int gridRows, sf::RenderWindow* window);

private:

	void init();

	int m_TotalCells;
	int m_TotalLines;

	int m_GridColumns;
	int m_GridRows;

	int m_ViewportHeight;
	int m_ViewportWidth;

	sf::RenderWindow* m_Window;

	sf::RectangleShape* m_GridCells;
	sf::RectangleShape* m_GridLines;

	sf::Color m_GridCellsColor = sf::Color::Black;
	sf::Color m_GridLineColor = sf::Color::White;

public:

	void SetGridCellsColor(sf::Color color);
	void SetGridCellColor(int cell, sf::Color color);
	void SetGridLinesColor(sf::Color color);
	void SetGridLineColor(int line, sf::Color color);

	sf::RectangleShape* GetCells() const { return m_GridCells; }

	void DrawGrid();
};

