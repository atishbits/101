#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

static const int empty = -1;

struct coordinate {
	int r;
	int c;
};
typedef struct coordinate Coordinate;

class Player {
private:
	int _symbol;
	bool _isHuman;
	Player(){};
public:
	Player(const int symbol, const bool ishuman):_symbol(symbol), _isHuman(ishuman){
		srand(time(NULL));	//initialize seed for computer random play
	};
	int getSymbol() const {return _symbol;}
	bool isHuman() const {return _isHuman;}
	const Coordinate getMove(const int gridSize) {
		Coordinate loc;
		if(_isHuman) {
			cout << "Please enter your move - "							<< endl;
			cout << "Row:";
			cin >> loc.r;
			cout << "Column:";
			cin >> loc.c;
		}
		else {
			loc.r = rand() % gridSize; 
			loc.c = rand() % gridSize;
		}
		return loc;
	}	
};

class Cell {
private:
	int _value;
	bool _blocked;
	bool _empty;

public:
	Cell(int val=-1, bool blocked=false) {
		_value = val; 
		_blocked = blocked;
		if(val < 0)
			_empty = true;
		else
			_empty = false;
	}
	void setBlocked() {
		_blocked = true;
	}
	int getVal() {
		return _value;
	}
	bool empty() { return _empty;}
	bool setVal(int val) {
		if(_blocked)
			return false;

		_empty = false;
		_value = val;
		return true;
	}
};

class TicTacToe {
private:
	bool _gameUp;
	vector<vector<Cell>> _grid;
	vector<Player> _vplayers;
	int64_t _emptyCells;
	TicTacToe(){};	//prevent access to def constructor

	bool setCell(int r, int c, Player& p);
	bool isGameOver(int r, int c, Player& p);
	bool isRDiag(int sym);
	bool isFDiag(int sym);
	bool isRow(int r, int sym);
	bool isCol(int r, int sym);
	void printGrid();

public:
	TicTacToe(int N, int numP);
	void startPlay();

};
