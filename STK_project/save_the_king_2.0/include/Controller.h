#pragma once

//-------------------------------include section------------------------------

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "StaticObject.h"
#include "DynamicObject.h"
#include "LoadResources.h"
#include "StatusBar.h"
#include "Menu.h"
#include "increaseTime.h"
#include "DecreaseTime.h"
#include "DisposeGnomes.h"
#include "Wall.h"
#include "Fire.h"
#include "Gate.h"
#include "Orc.h"
#include "Key.h"
#include "Throne.h"
#include "Gnome.h" 
#include "Portal.h"

//--------------------------------using section-------------------------------

using sf::RenderWindow;
using std::unique_ptr;
using sf::Event;
using sf::Clock;
using sf::View;
using sf::Keyboard;

//--------------------------------class section-------------------------------

class Controller
{
public:

	Controller(LoadResources&); 
	~Controller() {};
	
	void runGame();
	void drawObject(); 
	 
	void moveObject();
	void handleEvents();
	void collision();
	void resetGame();
	void checkObjectStatus();
	void updateKeyStatus();
	void activateConsumable();
	void setMenuTextures();
	void updatePlayerCollision(bool);
	bool checkPlayerCollision() const;

private:
	void initGameWindow();
	void checkGameTimer(); 
	void createConsumables(const Vector2f&); 
	void getGameElements(); 
	bool isPassed(); 
	bool readLevel(); 
	
	vector<Texture> m_menuTxr;

	vector<unique_ptr<Player>> m_player;
	vector<unique_ptr<Gnome>> m_gnome;
	vector<unique_ptr<StaticObject>> m_staticObject;
	vector<unique_ptr<Portal>> m_portalSystem;

	unique_ptr<MenuButton> m_ingameExitButton;

	RenderWindow m_window;
	Menu m_menu; 
	StatusBar m_statusBar; 
	Board m_board; 
	
	ifstream& m_file; 
	LoadResources& m_resources;
	Clock m_gameClock;
	
	vector<string> m_map;
	
	bool m_levelPassed;
	bool m_turn;
	bool m_playerCollision = false;
	
	int m_myTurn = 0;
	int m_rows = 0; 
	int m_cols = 0;

	float m_elapsedTime; 
	float m_timer; 

	sf::Music m_menuMusic;
	sf::Music m_ingameMusic;
	sf::Music m_endMusic;
};