#pragma once

//-------------------------------include section------------------------------

#include "Board.h"
#include "Controller.h"

//---------------------------------func section-------------------------------
//this function loads the board by giving it a size and a rectangular texture
void Board::loadBoard(const Texture& texture)
{
	m_board.setSize({ (float)m_windowSpace.getSize().x, (float)m_windowSpace.getSize().y });
	m_board.setTexture(&texture);
}

//----------------------------------------------------------------------------
//this function draws the rectangular texture of the board
void Board::draw() 
{
	m_windowSpace.draw(m_board);
}

//----------------------------------------------------------------------------

RenderTexture& Board::getWindowSpace()
{
	return m_windowSpace;
}

//----------------------------------------------------------------------------
//this function creates either the game board or the status bar board 
void Board::create(const Vector2f& pos, unsigned width, unsigned height)
{
	m_windowSpace.create(width, height);
	m_sprite.setPosition(pos);	
	m_sprite.setTexture(m_windowSpace.getTexture(), true);
}

//----------------------------------------------------------------------------
//this function displays the rectangular board onto the window
void Board::display(RenderWindow& window) 
{
	window.draw(m_sprite);
	m_windowSpace.display();
}

//----------------------------------------------------------------------------

void Board::clearBoard()
{
	m_windowSpace.clear(Color::Black);
}

//----------------------------------------------------------------------------
//this function sets all the features for a wanted message to be displayed
RectangleShape Board::createWindowMsg(const Vector2f& pos)
{
	RectangleShape windowMsg;
	windowMsg.setSize(sf::Vector2f(800, 700));
	windowMsg.setOutlineColor(sf::Color::Red);
	windowMsg.setOutlineThickness(1.5);
	
	windowMsg.setPosition(pos);
	windowMsg.setOrigin(windowMsg.getGlobalBounds().width / 2, windowMsg.getGlobalBounds().height / 2);

	return windowMsg;
}

//----------------------------------------------------------------------------
//this function creates a loading screen before, after the game and between levels
void Board::loadingScreen(std::string text,  RenderWindow &window, const Font& font)
{
	std::string getReady;
	float time = 0;
	sf::Clock clock;
	clock.restart();
	for (int i = 0; i < 5;)
	{
		getReady = text + " " + std::to_string(5 - i);//wait 5 seconds
		time += clock.getElapsedTime().asSeconds();
		Text message(getReady, font, 40);
		message.setPosition(window.getView().getCenter());
		message.setOutlineColor(Color::Black);
		message.setOutlineThickness(4);
		message.setOrigin(message.getGlobalBounds().width / 2, message.getGlobalBounds().height / 2);

		window.draw(message);
		window.display();
		window.clear(sf::Color(70, 70, 70));//give a grey coloured background 
		if (time >= 100)
		{
			i++;
			time = 0;
			clock.restart();
		}

	}
}

//----------------------------------------------------------------------------
//this function displays wanted messages to the board 
void Board::gameMessage(string m, Vector2f pos, RenderWindow& window, bool val, const Font& font)
{
	Text msg;	
	string s = m;
	s.append("\nPRESS ENTER TO CONTINUE...");//add this msg to the recieved string
	m = s;
	msg = setMsg(m, pos, val, font);
	window.draw(msg);
	window.display();

	waitEventGame(window);
}

//----------------------------------------------------------------------------
//this function sets all features for wanted string
sf::Text Board::setMsg(string m, Vector2f pos, bool val, const Font& font)
{
	Text msg(m, font, 35.0f);
	msg.setPosition(pos);
	msg.setFillColor(sf::Color::Yellow);
	msg.setOutlineThickness(2);
	msg.setOutlineColor(sf::Color::Red);

	if (val)//check if level passed or failed
	{ 
		msg.setCharacterSize(TEXT_SIZE - 10);
		msg.setFillColor(sf::Color::White);
		msg.setOutlineThickness(1);
	}
	msg.setOrigin(msg.getGlobalBounds().width / 2, msg.getGlobalBounds().height / 2);
	return msg;
}

//----------------------------------------------------------------------------
//this funtion waits for the user to give an input
void Board::waitEventGame(RenderWindow& window)
{
	Event event;

	while (window.waitEvent(event))
		if (event.type == Event::KeyReleased) 
		{
			if (event.key.code == Keyboard::Enter)
				break;//if enter continue
			if (event.key.code == Keyboard::Escape) 
			{
				window.close();
				break;//if esc exit the game
			}
		}
}

//----------------------------------------------------------------------------
//this function sets all the features needed for the end message
void Board::endMsg(RenderWindow& window, const Texture& endBackground, const Font& font)
{
	RectangleShape background;
	background.setSize(Vector2f((float)window.getSize().x, (float)window.getSize().y));

	background.setTexture(&endBackground);
	window.clear();
	window.draw(background);

	Text exitStr = setMsg("\npress enter to exit......", { 900.f , 1200.f }, true, font);
	exitStr.setOrigin(410.f,500.f);

	window.draw(exitStr);
	window.display();
	waitEventGame(window);
}