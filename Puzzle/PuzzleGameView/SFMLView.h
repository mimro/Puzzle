#include "GameBase\Board.h"
#include "GameBase\MakeMoveVector.h"
#include <SFML\Graphics.hpp>
#include "IView.h"
#include "GameManager\ActionResult.h"

using namespace sf;
class SFMLView : public IView
{
public:
	SFMLView();
	~SFMLView();
	void RenderBoard(Board board) override;
	void Setup(int boardSize, string TexturePath) override;
	void MakeMove(Board* board, int x, int y) override;
	ActionResult GetAction() override;
	  
private:
	Sprite sprite[48] ;
	RenderWindow* window;
	Texture puzzleTexture;
	int windowSize;
	int boardSize;
	int tileSize;
	int emptyTileIndex;
	void AnimateMove(MoveVector moveVector);
};

