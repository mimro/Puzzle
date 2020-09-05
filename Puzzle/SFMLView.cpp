#include "PuzzleGameView\SFMLView.h"
#include "GameBase\Board.h"
#include "Solver\Solver.h"
#include "PuzzleGameView\ViewFactory.h"
#include "Solver\DFSSolver.h"
#include "Solver\AStarSolver.h"
#include "GameManager\ActionResult.h"
#include "GameManager\GameStates.h"

using namespace sf;

SFMLView::SFMLView()
{

}

SFMLView::~SFMLView()
{
}
void SFMLView::RenderBoard(Board board)
{
	window->clear(Color::White);
	for (int i = 0; i < boardSize; i++)
		for (int j = 0; j < boardSize; j++)
		{
			int n = board.GetValueAt(i, j);
			sprite[n].setPosition(i*tileSize, j*tileSize);

			window->draw(sprite[n]);
		}

	window->display();
}

void SFMLView::Setup(int _boardSize, string texturePath)
{
	puzzleTexture.loadFromFile(texturePath);
	emptyTileIndex = 0;
	 windowSize = 512;
	 boardSize = _boardSize;
	 tileSize = windowSize / boardSize;
	window = new RenderWindow(VideoMode(windowSize, windowSize), "Puzzle");
	window->setFramerateLimit(60);
	int iter = 0;
	for (int i = 0; i < boardSize; i++)
		for (int j = 0; j < boardSize; j++)
		{
			iter++;
			sprite[iter].setTexture(puzzleTexture);
			sprite[iter].setTextureRect(IntRect(i * tileSize, j * tileSize, tileSize, tileSize));

		}
	sprite[emptyTileIndex] = sprite[boardSize*boardSize];
	//sprite[emptyTileIndex].setColor(Color(255, 255, 255, 80));
	sprite[emptyTileIndex].setTexture(*new Texture());
}

void SFMLView::AnimateMove(MoveVector moveVector)
{
	sprite[emptyTileIndex].move(-moveVector.OffsetX * tileSize, -moveVector.OffsetY * tileSize);
	float speed = 10;

	for (int i = 0; i < tileSize; i += speed)
	{
		sprite[moveVector.TileValue].move(speed*moveVector.OffsetX, speed*moveVector.OffsetY);
		window->draw(sprite[emptyTileIndex]);
		window->draw(sprite[moveVector.TileValue]);
		window->display();
	}
}

void SFMLView::MakeMove(Board* board, int x, int y)
{
	window->requestFocus();
	window->setActive(true);
	MoveVector moveVector = board->MakeMove(x, y);
	AnimateMove(moveVector);
}

ActionResult SFMLView::GetAction()
{
	Event e;
	while (window->pollEvent(e))
	{
		if (e.type == Event::Closed)
			window->close();

		if (e.type == Event::MouseButtonPressed)
			if (e.key.code == Mouse::Left)
			{
				Vector2i pos = Mouse::getPosition(*window);
				int x = pos.x / tileSize;
				int y = pos.y / tileSize;
				return{ x,y, true };
			}
		if(e.type == Event::KeyReleased)
		if (e.key.code == Keyboard::S )
		{
			return {0,0,false,SOLVING };
		}
	}
	return{ false };
}



