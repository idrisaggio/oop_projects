#pragma once

//-------------------------------include section------------------------------

#include "LoadResources.h"
#include <Windows.h>
#include <iostream>

//---------------------------------func section-------------------------------

LoadResources::LoadResources()
{
	openFile(FILE_NAME);
	m_textures.resize(NUM_OF_TEXTURES);
	m_sounds.resize(NUM_OF_SOUNDS);

	loadTexture(m_textures[T_KING], "king.png");
	loadTexture(m_textures[T_MAGE], "mage.png");
	loadTexture(m_textures[T_WARRIOR], "warrior.png");
	loadTexture(m_textures[T_THIEF], "thief.png");
	loadTexture(m_textures[T_GNOME], "gnome.png");
	loadTexture(m_textures[T_TILE], "tile.png");
	loadTexture(m_textures[T_WALL], "wall.png");
	loadTexture(m_textures[T_GATE], "gate.png");
	loadTexture(m_textures[T_FIRE], "fire.png");
	loadTexture(m_textures[T_ORC], "orc.png");
	loadTexture(m_textures[T_KEY], "key.png");
	loadTexture(m_textures[T_PORTAL], "portal.png");
	loadTexture(m_textures[T_THRONE], "throne.png");
	loadTexture(m_textures[T_CONSUMABLE], "consumable.png");
	loadTexture(m_textures[T_BUTTON], "button.png");
	loadTexture(m_textures[T_MENU_BACKGROUND], "menu_background.png");
	loadTexture(m_textures[T_HELP_BACKGROUND], "help_background.png");
	loadTexture(m_textures[T_STATUS_BAR], "status_bar.png");
	loadTexture(m_textures[T_NO_KEY], "no_key.png");
	loadTexture(m_textures[T_END_BACKGROUND], "end_background.png");
	loadTexture(m_textures[T_QUIT], "quit.png");
	
	loadSoundBuffer(m_sounds[S_ORC_KILLED], "orc_killed.wav");
	loadSoundBuffer(m_sounds[S_KEY_TAKEN], "key_taken.wav");
	loadSoundBuffer(m_sounds[S_GATE_OPENED], "gate_opened.wav");
	loadSoundBuffer(m_sounds[S_FIRE_EXTINGUISHED], "fire_extinguished.wav");
	loadSoundBuffer(m_sounds[S_PORTAL_ENTERDED], "portal_entered.wav");
	loadSoundBuffer(m_sounds[S_INC_TIME], "inc_time.wav");
	loadSoundBuffer(m_sounds[S_DEC_TIME], "dec_time.wav");
	loadSoundBuffer(m_sounds[S_DIS_GNOMES], "dis_gnomes.wav");
	loadSoundBuffer(m_sounds[S_LEVEL_PASSED], "level_passed.wav");
	loadSoundBuffer(m_sounds[S_TIMES_UP], "times_up.wav");

	loadFont(m_font, "pixel.ttf");
}

//----------------------------------------------------------------------------

ifstream& LoadResources::getFile()
{
	return m_boardDesc;
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getMenuBackgroundTxr() const
{
	return m_textures[T_MENU_BACKGROUND];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getButtonTxr() const
{
	return m_textures[T_BUTTON];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getKingTxr() const
{
	return m_textures[T_KING];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getMageTxr() const
{
	return m_textures[T_MAGE];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getWarriorTxr() const
{
	return m_textures[T_WARRIOR];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getThiefTxr() const
{
	return m_textures[T_THIEF];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getGnomeTxr() const
{
	return m_textures[T_GNOME];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getWallTxr() const
{
	return m_textures[T_WALL];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getThroneTxr() const
{
	return m_textures[T_THRONE];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getFireTxr() const
{
	return m_textures[T_FIRE];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getPortalTxr() const
{
	return m_textures[T_PORTAL];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getGateTxr() const
{
	return m_textures[T_GATE];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getOrcTxr() const
{
	return m_textures[T_ORC];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getKeyTxr() const
{
	return m_textures[T_KEY];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getConsumableTxr() const
{
	return m_textures[T_CONSUMABLE];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getNoKeyTxr() const
{
	return m_textures[T_NO_KEY];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getTileTxr() const
{
	return m_textures[T_TILE];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getEndBackgroundTxr() const
{
	return m_textures[T_END_BACKGROUND];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getHelpBackgroundTxr() const
{
	return m_textures[T_HELP_BACKGROUND];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getStatusBarTxr() const
{
	return m_textures[T_STATUS_BAR];
}

//----------------------------------------------------------------------------

const Texture& LoadResources::getQuitTxr() const
{
	return m_textures[T_QUIT];
}

//----------------------------------------------------------------------------

const SoundBuffer& LoadResources::getOrcSound() const
{
	return m_sounds[S_ORC_KILLED];
}

//----------------------------------------------------------------------------

const SoundBuffer& LoadResources::getKeySound() const
{
	return m_sounds[S_KEY_TAKEN];
}

//----------------------------------------------------------------------------

const SoundBuffer& LoadResources::getGateSound() const
{
	return m_sounds[S_GATE_OPENED];
}

//----------------------------------------------------------------------------

const SoundBuffer& LoadResources::getFireSound() const
{
	return m_sounds[S_FIRE_EXTINGUISHED];
}

//----------------------------------------------------------------------------

const SoundBuffer& LoadResources::getIncTimeSound() const
{
	return m_sounds[S_INC_TIME];
}

//----------------------------------------------------------------------------

const SoundBuffer& LoadResources::getDecTimeSound() const
{
	return m_sounds[S_DEC_TIME];
}

//----------------------------------------------------------------------------

const SoundBuffer& LoadResources::getDisGnomeSound() const
{
	return m_sounds[S_DIS_GNOMES];
}

//----------------------------------------------------------------------------

const SoundBuffer& LoadResources::getPortalSound() const
{
	return m_sounds[S_PORTAL_ENTERDED];
}

//----------------------------------------------------------------------------

const SoundBuffer& LoadResources::getPassedSound() const
{
	return m_sounds[S_LEVEL_PASSED];
}

//----------------------------------------------------------------------------

const SoundBuffer& LoadResources::getLostSound() const
{
	return m_sounds[S_TIMES_UP];
}

//----------------------------------------------------------------------------

const Font& LoadResources::getFont() const
{
	return m_font;
}

//----------------------------------------------------------------------------

//this function opens the board.txt file
void LoadResources::openFile(string path)
{
	m_boardDesc.open(path);
	if (!m_boardDesc.is_open())
	{
		std::cerr << "cannot open file!";
		exit(EXIT_FAILURE);
	}
}

//----------------------------------------------------------------------------

void LoadResources::loadTexture(Texture& texture, string path)
{
	if (!texture.loadFromFile(path))
	{
		std::cout << "cannot load texture!";
		exit(EXIT_FAILURE);
	}
}

//----------------------------------------------------------------------------

void LoadResources::loadSoundBuffer(SoundBuffer& soundBuffer, string path)
{
	if (!soundBuffer.loadFromFile(path))
	{
		std::cerr << "cannot load sound file!";
		exit(EXIT_FAILURE);
	}
}

//----------------------------------------------------------------------------

void LoadResources::loadFont(Font& font, string path)
{
	if (!font.loadFromFile(path))
	{
		std::cerr << "cannot load font!";
		exit(EXIT_FAILURE);
	}
}