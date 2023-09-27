#include "Grid.h"

Grid::Grid() :
m_ViewportHeight(600),
m_ViewportWidth(600),
m_GridColumns(5),
m_GridRows(5)
{
	init();
}

Grid::Grid(const int viewportHeight, const int viewportWidth, int gridColumns, int gridRows, sf::RenderWindow* window)
{
	m_ViewportHeight = viewportHeight;
	m_ViewportWidth = viewportWidth;
	m_GridColumns = gridColumns;
	m_GridRows = gridRows;
	m_Window = window;

	init();
}

void Grid::init()
{
	m_TotalCells = m_GridColumns * m_GridRows;
	m_TotalLines = m_GridColumns + m_GridRows - 2;

	m_GridCells = new sf::RectangleShape[m_TotalCells];
	m_GridLines = new sf::RectangleShape[m_TotalLines];

	int cellHeight = m_ViewportHeight / m_GridColumns;
	int cellWidth = m_ViewportWidth / m_GridRows;

	for(int i=0; i<m_GridRows; i++)
	{
		for(int j=0; j<m_GridColumns; j++)
		{
			int it = i * m_GridColumns + j;
			int posY = i * cellHeight;
			int posX = j * cellWidth;

			m_GridCells[it].setSize({ (float)cellWidth, (float)cellHeight });
			m_GridCells[it].setPosition(posX, posY);
			m_GridCells[it].setFillColor(m_GridCellsColor);
		}
	}

	for(int i=1; i<m_GridRows; i++)
	{
		int pos = i * cellWidth;
		m_GridLines[i - 1].setSize({ 1.0f, (float)m_ViewportHeight });
		m_GridLines[i - 1].setPosition(pos, 0);
		m_GridLines[i - 1].setFillColor(m_GridLineColor);
	}

	for (int i = 1; i < m_GridColumns; i++)
	{
		int it = m_GridRows + i - 2;
		int pos = i * cellHeight;
		m_GridLines[it].setSize({(float)m_ViewportWidth, 1.0f });
		m_GridLines[it].setPosition(0, pos);
		m_GridLines[it].setFillColor(m_GridLineColor);
	}
}

void Grid::DrawGrid()
{
	for(int i=0; i<m_TotalCells; i++)
	{
		m_Window->draw(m_GridCells[i]);
	}

	for(int i=0; i< m_GridColumns + m_GridRows - 2; i++)
	{
		m_Window->draw(m_GridLines[i]);
	}
}

void Grid::SetGridCellsColor(sf::Color color)
{
	m_GridCellsColor = color;
}

void Grid::SetGridCellColor(int cell, sf::Color color)
{
	if(cell < m_TotalCells)
		return;
	m_GridCells[cell].setFillColor(color);
}

void Grid::SetGridLinesColor(sf::Color color)
{
	m_GridLineColor = color;
}

void Grid::SetGridLineColor(int line, sf::Color color)
{
	if (line < m_TotalLines)
		return;
	m_GridLines[line].setFillColor(color);
}