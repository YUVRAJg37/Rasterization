#pragma once
#include <SFML/Graphics.hpp>

class Grid
{
public:

	Grid();
	Grid(const int viewportHeight, const int viewportWidth, int gridColumns, int gridRows, sf::RenderWindow* window);

	~Grid();
	void ResetGrid();

private:

	void init();

	int m_TotalCells;
	int m_TotalLines;

	int m_GridColumns;
	int m_GridRows;

	int m_ViewportHeight;
	int m_ViewportWidth;

	bool m_DrawGridLines = true;

	sf::RenderWindow* m_Window;

	sf::RectangleShape* m_GridCells;
	sf::RectangleShape* m_GridLines;

	sf::Color m_GridCellsColor = sf::Color::Black;
	sf::Color m_GridLinesColor = sf::Color::White;

public:

	void SetGridCellsColor(sf::Color color);
	void SetGridCellColor(int cell, sf::Color color);
	void SetGridLinesColor(sf::Color color);
	void SetGridLineColor(int line, sf::Color color);

	sf::Color GetGridCellsColor() const { return m_GridCellsColor; }

	void SetDrawGridLines(bool value) { m_DrawGridLines = value; }

	sf::RectangleShape* GetCells() const { return m_GridCells; }

	void DrawGrid();
};

