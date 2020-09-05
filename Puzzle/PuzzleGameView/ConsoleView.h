#pragma once
#include "IView.h"
#include "GameManager\ActionResult.h"

class ConsoleView : public IView
{
private:
	int boardSize;
public:
	ConsoleView();
	~ConsoleView();
	void Setup(int boardSize, string TexturePath) override;
	bool CanMove(int x, int y, int size);
	ActionResult GetAction() override;
	void MakeMove(Board* board, int x, int y) override;
	void RenderBoard(Board board) override;
};

