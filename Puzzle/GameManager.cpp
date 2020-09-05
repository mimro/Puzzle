#include "GameManager\GameManager.h"
#include <iostream>
#include <stack>
#include "PuzzleGameView\ViewFactory.h"
#include "Solver\Solver.h"
#include "Solver\SolverFactory.h"
#include "GameManager\ActionResult.h"
#include "Solver\SolverResolver.h"
#include <conio.h>


GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

void GameManager::Setup()
{
	state = SETUP;
	board = new Board(boardSize);
	board->GenerateRandomBoard();
	ViewFactory viewFactory;
	 view = viewFactory.GetViewInstance(selectView);
	 view->Setup(boardSize, texturePath);
	 state = PLAYING;

}


ActionResult GameManager::GetAction()
{
	return ActionResult();
}

void GameManager::WriteMenuText()
{
	cout << "Podaj œcie¿kê do pliku z tekstur¹: ", cin>>texturePath;
	

	cin.clear();
	cout << "Podaj rozmiar planszy " << endl;
	int size;
	do {
		cin >> size;
		if (cin.fail())
		{
			cout << "Podaj poprawny rozmiar " << endl;
			cin.clear();
		}
	} while (cin.fail());
	cout << "Rozmiar planszy wynosi " << size << endl;
	boardSize = size;
	cout << "Czy chcesz rozpocz¹æ grê w œrodowisku graficznym?" << endl;
	cout << "[1] Tak" << endl;
	cout << "[2] Nie, rozpocznij gre w konsoli" << endl;
	int select = 0;
	do {
		cin >> select;
		if (cin.fail() || (select>2 && select<1))
		{
			cout << "Podaj poprawny numer " << endl;
			cin.clear();
		}
	} while (cin.fail());
	selectView = select;
}



void GameManager::Run()
{
	cout << endl << "Aby przejœæ do automatycznego rozwi¹zania puzli wciœnij s: "<<endl;
	while (state == PLAYING) {
		view->RenderBoard(*board);


		ActionResult action = view->GetAction();

		if (action.gameState == SOLVING)
		{
			state = SOLVING;
		}

		if (action.isActionPerformed == true)
		{
			view->MakeMove(board, action.X, action.Y);
		}
	}
	
	if (state == SOLVING) {
		InitializeSolver();
		Node* node = solver->Solve(board->GetBoardAsInt());
						
		SolverResolver solverResolver;
		stack<coordinates> coords = solverResolver.Solve(solver, *board, boardSize);
		if (coords.size() == 1 && coords.top().X == -1 && coords.top().Y == -1)
		{
			solver->~Solver();
			this->Setup();
			this->Run();
		}
		coordinates* c;
		view->RenderBoard(*board);
		while (coords.empty()!=true)
		{
			 c = &coords.top();
			 view->MakeMove(board, c->X, c->Y);
			 view->RenderBoard(*board);
			 coords.pop();
		}
		
		state = FINNISHED;
	}

	if (state == FINNISHED) 
	{
		int finishGameSelect;
		view->RenderBoard(*board);
		cout << "Koniec gry"<<endl;
		do {
			cout << "Wciœnij 0 aby zakoñczyæ lub 1 aby zacz¹æ od nowa: " ,cin>> finishGameSelect;
			if (cin.fail() || (finishGameSelect>3 && finishGameSelect<1))
			{
				cout << "Podaj poprawny numer " << endl;
				cin.clear();
			}
		} while (cin.fail());
		if (finishGameSelect == 0)
		{
			exit(EXIT_SUCCESS);
		}
		if (finishGameSelect == 1)
		{
			Setup();
			Run();
		}

	}
}

void GameManager::InitializeSolver()
{
	SolverFactory solverFactory;

	cout << "Jakiego algorytmu rozwi¹zywania chcesz u¿yæ?" << endl;
	cout << "[1] Depth First Search " << endl;
	cout << "[2] A*" << endl;
	cout << "[3] Greedy best first" << endl;

	int select = 0;
	do {
		cin >> select;
		if (cin.fail() || (select>3 && select<1))
		{
			cout << "Podaj poprawny numer " << endl;
			cin.clear();
		}
	} while (cin.fail());
	 solver = solverFactory.GetSolverAlgorithm(select);
}
