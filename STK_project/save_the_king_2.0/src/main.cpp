#pragma once

//-------------------------------include section------------------------------

#include "Controller.h"
#include "LoadResources.h"

//--------------------------------using section-------------------------------

using namespace std;

//---------------------------------func section-------------------------------

int main()
{
	LoadResources resource;
	Controller ctrlr(resource);
	ctrlr.runGame();

	return EXIT_SUCCESS;
}