#include "PuzzleGameView\ViewFactory.h"
#include "PuzzleGameView\SFMLView.h"
#include "PuzzleGameView\ConsoleView.h"

ViewFactory::ViewFactory()
{
}


ViewFactory::~ViewFactory()
{
}

IView* ViewFactory::GetViewInstance(int selection)
{
	switch(selection)
	{
	case 1:
		view = new SFMLView();
		break;
	case 2:
		view = new ConsoleView();
		break;

	}

	return view;
}
