#pragma once

//--------------------------------include section-----------------------------

#include "Editor.h"

//---------------------------------func section-------------------------------

//default c-tor
Editor::Editor() :
	m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Level Editor") {}

//----------------------------------------------------------------------------
//this func initiates everything needed in order to make a lever editor
void Editor::run() 
{
	//set textures
	initTxrArray();
	
	//set the Panel
	m_panel.initPanel(m_txrArray);

	//if there is a file open and read it
	fs::path p = "C:Board.txt";
	std::ifstream inpFile(fs::absolute(p));

	if (inpFile)
		m_board.readExistingBoard(inpFile, m_txrArray);
	
	//if not ask user for height and width of the new board
	else
		initBoard();

	inpFile.close();

	//make a figure hover over mouse when on board
	sf::Sprite hover;
	bool putHover = false;
	while (m_window.isOpen()) 
	{
		m_window.clear();
		m_board.draw(m_window);
		m_panel.drawButton(m_window);
		
		if (putHover)
			m_window.draw(hover);
		
		m_window.display();
		
		//check for events
		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				m_window.close();
				break;
			}

			case sf::Event::MouseButtonReleased:
			{
				auto location = m_window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });

				if (location.y < BOARD_SIZE)
					handleClick(location);

				else if (m_clickMode < ActionType::SaveBoard)
					m_board.setFigure(FigureType(m_clickMode), location, m_txrArray);
				break;
			}

			case sf::Event::MouseMoved:
			{
				auto location = sf::Mouse::getPosition(m_window);
				int newCol = int(location.x) / TILE_SIZE;
				int newRow = int(location.y - BOARD_SIZE) / TILE_SIZE;
				
				//make an object hover if clicked
				if (m_clickMode < ActionType::SaveBoard && location.y > BOARD_SIZE &&
					newRow < m_board.getHeight() && newCol < m_board.getWidth())
				{
					hover = sf::Sprite(*m_txrArray[int(m_clickMode)]);
					int xPos = (int(location.x) / TILE_SIZE) * TILE_SIZE;
					int yPos = ((int(location.y) - BOARD_SIZE) / TILE_SIZE) * TILE_SIZE + BOARD_SIZE;
					hover.setPosition(sf::Vector2f(xPos, yPos));
					putHover = true;
				}
				
				else
					putHover = false;
				}
			}
		}
	}
}

//----------------------------------------------------------------------------
void Editor::handleClick(const sf::Vector2f& location) 
{
	ActionType act = m_panel.handleClick(location);
	if (act == ActionType::SaveBoard)
		m_board.save();
	if (act == ActionType::ClearBoard) 
	{
		initBoard();
	}
	//add a figure when needed
	if (act != ActionType::NoAction && act < ClearBoard) 
	{
		m_clickMode = ActionType(int(act));
	}
}

//----------------------------------------------------------------------------
//this func initiates a new board
void Editor::initBoard() 
{
	sf::Font font;
	font.loadFromFile(FONT_PATH);
	auto text = sf::Text("Please enter the height and the width\nof the new board in the the terminal...",
		font,
		50);
	
	m_window.clear();
	m_window.draw(text);
	m_window.display();

	int height, width;
	std::cout << "Enter the height:\n";
	std::cin >> height;
	std::cout << "Enter the width:\n";
	std::cin >> width;

	m_board.setNewBoard(height, width, m_txrArray);
}

//----------------------------------------------------------------------------
//this func is used to load textures from files
void Editor::initTxrArray() 
{
	for (int i = 0; i < NUM_OF_TYPES; i++)
		m_txrArray[i] = new sf::Texture();

	(*m_txrArray[FigureType::Save]).loadFromFile("Save.png");
	(*m_txrArray[FigureType::Clear]).loadFromFile("Clear.png");
	(*m_txrArray[FigureType::King]).loadFromFile("King.png");
	(*m_txrArray[FigureType::Mage]).loadFromFile("Mage.png");
	(*m_txrArray[FigureType::Thief]).loadFromFile("Thief.png");
	(*m_txrArray[FigureType::Warrior]).loadFromFile("Warrior.png");
	(*m_txrArray[FigureType::Empty]).loadFromFile("Empty.png");
	(*m_txrArray[FigureType::Wall]).loadFromFile("Wall.png");
	(*m_txrArray[FigureType::Fire]).loadFromFile("Fire.png");
	(*m_txrArray[FigureType::Throne]).loadFromFile("Throne.png");
	(*m_txrArray[FigureType::Orc]).loadFromFile("Orc.png");
	(*m_txrArray[FigureType::Key]).loadFromFile("Key.png");
	(*m_txrArray[FigureType::Gate]).loadFromFile("Gate.png");
	(*m_txrArray[FigureType::Portal]).loadFromFile("Portal.png");
}