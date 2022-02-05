#pragma once

//-------------------------------include section------------------------------

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <memory>
#include "Macros.h"

//--------------------------------using section-------------------------------

using std::ifstream;
using std::vector;
using std::string;
using sf::Texture;
using sf::SoundBuffer;
using sf::Font;

//--------------------------------class section-------------------------------

class LoadResources
{
public:
	
	LoadResources();
	~LoadResources() {};
	
	ifstream& getFile();

	const Texture& getMenuBackgroundTxr() const;	
	const Texture& getButtonTxr() const;
	const Texture& getKingTxr() const;
	const Texture& getMageTxr() const;
	const Texture& getWarriorTxr() const;
	const Texture& getThiefTxr() const;
	const Texture& getGnomeTxr() const;
	const Texture& getWallTxr() const;		
	const Texture& getThroneTxr() const;		
	const Texture& getFireTxr() const;			
	const Texture& getPortalTxr() const;			
	const Texture& getGateTxr() const;
	const Texture& getOrcTxr() const;
	const Texture& getKeyTxr() const;
	const Texture& getConsumableTxr() const;
	const Texture& getNoKeyTxr() const;
	const Texture& getTileTxr() const; 
	const Texture& getEndBackgroundTxr() const;
	const Texture& getHelpBackgroundTxr() const;
	const Texture& getStatusBarTxr() const;
	const Texture& getQuitTxr() const;

	const SoundBuffer& getOrcSound() const;
	const SoundBuffer& getKeySound() const;
	const SoundBuffer& getGateSound() const;
	const SoundBuffer& getFireSound() const;
	const SoundBuffer& getPortalSound() const;
	const SoundBuffer& getIncTimeSound() const;
	const SoundBuffer& getDecTimeSound() const;
	const SoundBuffer& getDisGnomeSound() const;
	const SoundBuffer& getPassedSound() const;
	const SoundBuffer& getLostSound() const;
	
	const Font& getFont() const;		

private:
	
	void openFile(string);
	void loadTexture(Texture&, string);
	void loadSoundBuffer(SoundBuffer&, string);
	void loadFont(Font&, string);

	ifstream m_boardDesc; 		
	vector<Texture> m_textures;
	vector<SoundBuffer> m_sounds;
	Font m_font; 
};

