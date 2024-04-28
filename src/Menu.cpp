#pragma once

//-------------------------------include section------------------------------

#include "Menu.h"

//---------------------------------func section-------------------------------
//this function initiates the menu by building and displaying it
void Menu::startMenu()
{
	//create the background
	m_menuWindow.create(VideoMode(), "Save The King", sf::Style::Fullscreen);//open new window
	m_menuBackground.setSize(Vector2f((float)m_menuWindow.getSize().x, (float)m_menuWindow.getSize().y));
	m_menuBackground.setTexture(&m_menuTxr[0]);

	m_playButton = (make_unique<MenuButton>(m_menuTxr[1], m_menuWindow.getView().getCenter(), BUTTON_SIZE, "PLAY"));
	m_instButton = (make_unique<MenuButton>(m_menuTxr[1], Vector2f(m_playButton->getPosition().x, m_playButton->getPosition().y + 150), BUTTON_SIZE, "HELP"));
	m_exitButton = (make_unique<MenuButton>(m_menuTxr[1], Vector2f(m_instButton->getPosition().x, m_instButton->getPosition().y + 150), BUTTON_SIZE, "EXIT"));
	//create menu buttons 

	m_helpBackground.setSize(Vector2f((float)m_menuWindow.getSize().x, (float)m_menuWindow.getSize().y));
	m_helpBackground.setTexture(&m_menuTxr[2]);

	while (m_menuWindow.isOpen())
	{
		draw();
		handleEvents();
	}
}

//----------------------------------------------------------------------------

void Menu::setMenuTxr(const vector<Texture>txr)
{
	m_menuTxr = txr;
}

//----------------------------------------------------------------------------

void Menu::loadingScreen(std::string text)
{
		m_status.setString(text);
		m_status.setOrigin(m_status.getLocalBounds().width / 2.0f, m_status.getLocalBounds().height / 2.0f);
}

//----------------------------------------------------------------------------
//this function draws the menu window and buttons
void Menu::draw()
{
	m_menuWindow.clear();	

	m_menuWindow.draw(m_menuBackground);
	m_playButton->draw(m_menuWindow);
	m_exitButton->draw(m_menuWindow);
	m_instButton->draw(m_menuWindow);

	m_menuWindow.display();
}

//----------------------------------------------------------------------------
//this functions handles the input of the user in the menu 
void Menu::handleEvents()
{
	Event event;
	while (m_menuWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			m_menuWindow.close();
			break;

		case Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Button::Left)
			{
				
				const Vector2f mousePos = m_menuWindow.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				
				if (m_playButton->contains(mousePos))//start game
				{
					m_startGame = true;
					m_menuWindow.close();
				}
				else if (m_exitButton->contains(mousePos))//exit game
				{
					m_menuWindow.close();
					exit(EXIT_SUCCESS);
				}
				else if (m_instButton->contains(mousePos))//open instructions
				{
					m_menuWindow.close();
					bool opened = true;

					m_helpWindow.create(VideoMode(), "Help", sf::Style::Fullscreen);
					while (opened)
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
						{
							opened = false;
							m_helpWindow.close();
							startMenu();
						}
						else
						{
							m_helpWindow.clear();
							m_helpWindow.draw(m_helpBackground);
							m_helpWindow.display();
						}
					}
					opened = false;
					break;
				}
			}
			break;

		case Event::MouseMoved://highlight buttons handling

			const Vector2f mousePos = m_menuWindow.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });

			if (m_playButton->contains(mousePos)) 	
				m_playButton->highlight();		
			else
				m_playButton->unhighlight(); 

			if (m_exitButton->contains(mousePos))	
				m_exitButton->highlight();  
			else
				m_exitButton->unhighlight(); 

			if (m_instButton->contains(mousePos))
				m_instButton->highlight();
			else
				m_instButton->unhighlight(); 
			break;
		}
	}
}