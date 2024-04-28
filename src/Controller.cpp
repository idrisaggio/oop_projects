#pragma once

//-------------------------------include section------------------------------

#include <iostream>
#include "Controller.h"

//--------------------------------using section-------------------------------

using sf::Keyboard;
using sf::VideoMode;
using std::make_unique;

//---------------------------------func section-------------------------------
//controller constructor
Controller::Controller(LoadResources& resources)
	: m_resources(resources), m_file(resources.getFile()), m_turn(false)
{
	setMenuTextures();
}

//----------------------------------------------------------------------------
//this function calls out all the necessary functions in order to run the game
void Controller::runGame()
{
	m_menuMusic.openFromFile("menu_music.wav");
	m_menuMusic.setLoop(true);
	m_menuMusic.play();//play menu music

	m_menu.startMenu();

	m_menuMusic.stop();//stop music when starting the game

	initGameWindow();//build and initiate game board and music

	while (readLevel())
	{
		m_levelPassed = false;
		while (m_window.isOpen())//main loop for the game
		{
			drawObject(); 
			handleEvents(); 
			moveObject(); 

			collision();

			checkObjectStatus();
			checkGameTimer();

			if (isPassed())
			{
				m_ingameMusic.stop();
				
				sf::Sound s(m_resources.getPassedSound());
				s.play();//add sound effects when a level is passed

				m_board.gameMessage(LEVEL_PASSED_MSG, m_window.getView().getCenter(), m_window, false, m_resources.getFont());

				m_ingameMusic.setLoop(true);//continue in game music
				m_ingameMusic.play();

				break;
			}
		}
	}
}

//----------------------------------------------------------------------------
//this function checks if the king has reached the throne thus level is passed
bool Controller::isPassed()
{
	for(auto& player : m_player)
		if (player->isReachedThrone())
		{
			m_levelPassed = true;
			drawObject();
			m_statusBar.updateLevel(); 
			return true;
		}
	return false;
}
 
//----------------------------------------------------------------------------
//this function draws the game objects, board and status bar
void Controller::drawObject()
{
	m_window.clear(sf::Color(70, 70, 70));//grey background  

	m_statusBar.clearBoard();
	m_statusBar.draw(); 
	updateKeyStatus();

	m_statusBar.display(m_window);

	m_board.clearBoard();
	m_board.draw();

	for (auto& portal : m_portalSystem)
		portal->draw(m_board.getWindowSpace());

	for (auto& staticObject : m_staticObject)
		staticObject->draw(m_board.getWindowSpace());

	for (auto& player : m_player)
		player->draw(m_board.getWindowSpace());

	for (auto& gnome : m_gnome)
		gnome->draw(m_board.getWindowSpace());

	m_board.display(m_window);
	m_ingameExitButton->draw(m_window);

	if (!m_levelPassed)
		m_window.display();
}

//----------------------------------------------------------------------------
//this function handles each dynamic objects movement
void Controller::moveObject()
{
	float dt = m_gameClock.restart().asSeconds();

	if (m_turn)//if its the player turn move
		m_player[m_myTurn]->move(m_turn, dt, m_board.getWindowSpace());

	else if (!m_turn)//if p is pressed change character
	{
		m_myTurn++;
		if (m_myTurn > m_player.size() - 1)
			m_myTurn = 0;

		auto& p = typeid(*m_player[m_myTurn]);

		if (p == typeid(King))
			m_statusBar.loadCurrPlayer(m_resources.getKingTxr(), m_resources.getFont(), "KING");
		else if (p == typeid(Mage))
			m_statusBar.loadCurrPlayer(m_resources.getMageTxr(), m_resources.getFont(), "MAGE");
		else if (p == typeid(Warrior))
			m_statusBar.loadCurrPlayer(m_resources.getWarriorTxr(), m_resources.getFont(), "WARRIOR");
		else if (p == typeid(Thief))
			m_statusBar.loadCurrPlayer(m_resources.getThiefTxr(), m_resources.getFont(), "THIEF");

		m_turn = true;
	}

	for (auto& Gnome : m_gnome)
		Gnome->move(m_turn, dt, m_board.getWindowSpace());
}

//----------------------------------------------------------------------------
//this function handles exiting the game events 
void Controller::handleEvents()
{
	Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			m_window.close();
			break;

		case Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Button::Left)
			{
				const Vector2f mousePos = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

				if (m_ingameExitButton->contains(mousePos))
				{
					m_board.gameMessage("YOU ARE LEAVING THE GAME...", m_window.getView().getCenter(), m_window, false, m_resources.getFont());
					m_window.close();
				}
			}

			break;
		default:
			break;
		}
	}
}

//----------------------------------------------------------------------------
//this function handles collison of each game object
void Controller::collision()
{
	for (auto& staticObject : m_staticObject)
	{
		for (auto& player : m_player)
			if (staticObject->getRect().intersects(player->getRect()))
				player->collision(*staticObject);

		for (auto& gnome : m_gnome)
			if (staticObject->getRect().intersects(gnome->getRect()))
				staticObject->collision(*gnome);
	}//between static objects and gnomes or players

	for (auto& player : m_player)
	{
		for (auto& player2 : m_player)
			if (player->getRect().intersects(player2->getRect()))
				player->collision(*player2);

		for (auto& gnome : m_gnome)
			if (player->getRect().intersects(gnome->getRect()))
				player->collision(*gnome);


		updatePlayerCollision(false);
		
		for (int i = 0; i < m_portalSystem.size(); i++)
		{
			if (player->getRect().intersects(m_portalSystem[i]->getRect()))
			{
				updatePlayerCollision(true);
				if (!player->checkInPortal())
				{
					sf::Sound s(m_resources.getPortalSound());
					s.play();
				}

				if (i % 2 == 0)
					(m_portalSystem[i + 1])->collision(*player);
				else
					(m_portalSystem[i - 1])->collision(*player);
			}
		}
		if (!checkPlayerCollision() && player->checkInPortal())
			player->updateInPortal();

		updatePlayerCollision(false);
	}//between players and other players, gnomes or portals


	for (auto& portal : m_portalSystem)
		for (auto& gnome : m_gnome)
			if (gnome->getRect().intersects(portal->getRect()))
				portal->collision(*gnome);
				//between portals and gnomes
}

//----------------------------------------------------------------------------
//this function is called when the timer had reached 0 in order to reset the level
void Controller::resetGame()
{
	m_staticObject.clear();
	m_player.clear();
	m_portalSystem.clear();
	m_gnome.clear();

	getGameElements();

	m_statusBar.updateTimer(m_timer);
	m_gameClock.restart();
}

//----------------------------------------------------------------------------
//this function checks if theres an object that must be removed
void Controller::checkObjectStatus()
{
	for (auto item = m_staticObject.begin(); item != m_staticObject.end();)
	{
		if ((*item)->checkIsRemoved())
		{
			Vector2f itemPos = (*item)->getPosition();
			auto& p = typeid(**item);
			item = m_staticObject.erase(item);

			if (p == typeid(Orc))//remove orc and drop a key 
			{
				itemPos = { itemPos.x + 20, itemPos.y +  32/2};
				m_staticObject.push_back(make_unique<Key>(m_resources.getKeyTxr(), itemPos, 23, 32));
				
				sf::Sound a(m_resources.getOrcSound());
				a.play();
			}
			else if (p == typeid(Key))//remove key 
			{
				sf::Sound a(m_resources.getKeySound());
				a.play();
			}
			else if (p == typeid(Gate))//remove gate
			{
				sf::Sound a(m_resources.getGateSound());
				a.play();
			}	
			else if (p == typeid(Fire))//remove fire
			{
				sf::Sound a(m_resources.getFireSound());
				a.play();
			}

			activateConsumable();//remove consumables
		}
		else
			item++;
	}
}

//----------------------------------------------------------------------------
//this function checks if the thief has a key or not
void Controller::updateKeyStatus()
{
	for (auto& player : m_player)
		if(typeid(*player) == typeid(Thief))
			if (player->checkHasKey())
				m_statusBar.updateKeyStatus(m_resources.getKeyTxr());
			else
				m_statusBar.updateKeyStatus(m_resources.getNoKeyTxr());
}

//----------------------------------------------------------------------------
//this function checks if the player collides with the portal after teleporting
void Controller::updatePlayerCollision(bool val)
{
	m_playerCollision = val;
}

//----------------------------------------------------------------------------

bool Controller::checkPlayerCollision() const
{
	return m_playerCollision;
}

//----------------------------------------------------------------------------
//this function initiates the consumables
void Controller::activateConsumable()
{
	for (auto& player : m_player)
		if (player->getConsumable() != -1)
		{
			switch (player->getConsumable())
			{
			case INC: 
			{
				if (m_timer != DEFAULT_CASE) 
				{
					m_statusBar.updateTimer(m_statusBar.getTimer() + 10);
					sf::Sound s(m_resources.getIncTimeSound());
					s.play();
				}//plus ten seconds consumable
				break;
			}	
			case DEC:
			{
				if (m_timer != DEFAULT_CASE)
				{
					m_statusBar.updateTimer(m_statusBar.getTimer() - 10);
					sf::Sound s(m_resources.getDecTimeSound());
					s.play();
				}//minus ten seconds consumable
				break;
			}
			case DIS:
			{
				m_gnome.clear();
				sf::Sound s(m_resources.getDisGnomeSound());
				s.play();
				break;
			}//dispose all the gnomes consumable
			default:
			{
				break;
			}
			}
			player->resetConsumable();
		}//the consumables are decided randomly 
}

//----------------------------------------------------------------------------

void Controller::setMenuTextures()
{
	m_menu.setMenuTxr({ m_resources.getMenuBackgroundTxr(), m_resources.getButtonTxr(), m_resources.getHelpBackgroundTxr() });
}

//----------------------------------------------------------------------------
//this function starts the game when pressed play in menu 
void Controller::initGameWindow()
{		
	m_ingameMusic.openFromFile("ingame_music.wav");
	m_ingameMusic.setLoop(true);
	m_ingameMusic.play();//play in game music

	m_window.create(sf::VideoMode(), "Save The King", sf::Style::Fullscreen);
	//create a new window for game

	m_board.loadingScreen(LEVEL_START, m_window, m_resources.getFont());
}

//----------------------------------------------------------------------------
//this function checks if the timer has reached 0, prints lost msg and resets level
void Controller::checkGameTimer()
{
	if (m_statusBar.getTimer() <= 0 && m_statusBar.getTimer() != NO_TIME_LIMIT)
	{
		m_ingameMusic.stop();
		sf::Sound s(m_resources.getLostSound());
		s.play();

		m_board.gameMessage("TIME'S UP!", m_window.getView().getCenter(), m_window, false, m_resources.getFont());
		resetGame(); 

		m_ingameMusic.play();
	}
}

//----------------------------------------------------------------------------
//this function randomly generates a consumable and initiates it
void Controller::createConsumables(const Vector2f& currPos)
{
	switch (rand() % 3) 
	{
	case INC:
		m_staticObject.push_back(make_unique<IncreaseTime>(m_resources.getConsumableTxr(), currPos, CONSUMABLE_SIZE, CONSUMABLE_SIZE));
		break;
	case DEC:
		m_staticObject.push_back(make_unique<DecreaseTime>(m_resources.getConsumableTxr(), currPos, CONSUMABLE_SIZE, CONSUMABLE_SIZE));
		break;
	case DIS:
		m_staticObject.push_back(make_unique<DisposeGnomes>(m_resources.getConsumableTxr(), currPos, CONSUMABLE_SIZE, CONSUMABLE_SIZE));
		break;
	}
}

//----------------------------------------------------------------------------
//this function reads the level from the board.txt file 
bool Controller::readLevel()
{
	m_staticObject.clear();
	m_player.clear();
	m_portalSystem.clear();
	m_gnome.clear();
	m_map.clear();

	m_file >> m_rows >> m_cols >> m_timer;//read input needed 

	if (m_file.eof())
	{
		m_ingameMusic.stop();
		m_endMusic.openFromFile("end_music.wav");
		m_endMusic.setLoop(true);
		m_endMusic.play();
		m_board.endMsg(m_window, m_resources.getEndBackgroundTxr(), m_resources.getFont());
		return false;
	}

	m_file.get();
	for (unsigned i = 0; i < m_rows; i++)
	{
		string line;
		getline(m_file, line);
		m_map.push_back(line);
	}
	
	m_statusBar.create(Vector2f{ 0.f , 0.f }, m_window.getSize().x, HEIGHT);
	m_statusBar.loadStatusBar(CELL, m_resources);
	m_ingameExitButton = (make_unique<MenuButton>(m_resources.getQuitTxr(), Vector2f(1800, 80), 0, ""));
	//create status bar board 

	m_board.create(Vector2f(0.f, HEIGHT), (m_cols * (unsigned)CELL), (m_rows * (unsigned)CELL));
	m_board.loadBoard(m_resources.getTileTxr());
	//creat game board

	m_statusBar.updateTimer((float)m_timer);

	getGameElements();//read and initiate all game objects

	return true;
}

//----------------------------------------------------------------------------
//this function reads and initiates each game object from the board.txt file
void Controller::getGameElements()
{
	for (unsigned i = 0; i < m_rows; i++)
	{
		for (unsigned j = 0; j < m_cols; j++)
		{
			ObjectType_t c = (ObjectType_t)m_map[i][j];
			const Vector2f currPos = Vector2f((float)j * CELL, (float)i * CELL);
				//calculate the current position
			switch (c)
			{

			case O_KING:
				m_player.push_back(make_unique<King>(m_resources.getKingTxr(), currPos, 34, 50));
				break;

			case O_MAGE:
				m_player.push_back(make_unique<Mage>(m_resources.getMageTxr(), currPos, 34, 50));
				break;

			case O_WARRIOR:
				m_player.push_back(make_unique<Warrior>(m_resources.getWarriorTxr(), currPos, 34, 50));
				break;

			case O_THIEF:
				m_player.push_back(make_unique<Thief>(m_resources.getThiefTxr(), currPos, 34, 50));
				break;

			case O_GNOME:
				m_gnome.push_back(make_unique<Gnome>(m_resources.getGnomeTxr(), currPos, 48, 46));
				break;

			case O_WALL:
				m_staticObject.push_back(make_unique<Wall>(m_resources.getWallTxr(), currPos, CELL, CELL));
				break;

			case O_GATE:
				m_staticObject.push_back(make_unique<Gate>(m_resources.getGateTxr(), currPos, CELL, CELL));
				break;

			case O_FIRE:
				m_staticObject.push_back(make_unique<Fire>(m_resources.getFireTxr(), currPos, 50, 50));
				break;

			case O_ORC:
				m_staticObject.push_back(make_unique<Orc>(m_resources.getOrcTxr(), currPos, CELL, CELL));
				break;

			case O_THRONE:
				m_staticObject.push_back(make_unique<Throne>(m_resources.getThroneTxr(), currPos, CELL, CELL));
				break;

			case O_PORTAL:
				m_portalSystem.push_back(make_unique<Portal>(m_resources.getPortalTxr(), currPos, CELL, CELL));
				break;

			case O_CONSUMABLE:
				createConsumables(currPos);
				break;

			default:
				break;
			}
		}
	}
}