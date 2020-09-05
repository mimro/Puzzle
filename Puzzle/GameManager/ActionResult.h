#ifndef ACTIONRESULT_H
#define ACTIONRESULT_H
#include "GameStates.h"

struct ActionResult {
	int X;
	int Y;
	bool isActionPerformed;
	gameStates gameState;
};
#endif     