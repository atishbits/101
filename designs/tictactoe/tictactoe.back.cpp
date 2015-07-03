#include "tictactoe.hpp"

TicTacToe::TicTacToe(int N, int numP) {
	_playAuto = true;
	//initialize NxN grid with blanks (-1)
	for(int i=0; i<N; i++) {
		_grid.push_back(vector<Cell>());
		for(int j=0; j<N; j++)
			_grid[i].push_back(Cell());
	}
	for(int i=0; i<numP; i++) {
		string input;
		cout << "Is player" << i << " human? (true/false):";
		cin >> input; 
		if(!input.compare("true")) {
			_vplayers.push_back(Player(i, true));
			_playAuto = false;
		}
		else {
			_vplayers.push_back(Player(i, false));
		}
	}
	_emptyCells = N*N;
	_gameUp = false;

	//_grid[0][0].setBlocked();
		
}	

bool TicTacToe::isFDiag(int sym) {
	for(size_t i=0; i<_grid.size(); i++) {
		if(_grid[i][i].getVal() != sym)
			return false;
	}
	cout << __func__ << " matched" << endl;
	return true;
}

bool TicTacToe::isRDiag(int sym) {
	size_t i=0, j=0;
	for(i=0; i<_grid.size(); i++) {
		for(j=_grid.size(); j!=0; j--) {
			if(_grid[i][j-1].getVal() != sym)
				return false;
		}
	}
	cout << __func__ << " matched" << endl;
	return true;
}

bool TicTacToe::isRow(int r, int sym) {
	//check if all symbols in this row are sym
	for(size_t i=0; i<_grid.size(); i++) {
		if(_grid[r][i].getVal() != sym)
			return false;
	}
	cout << __func__ << " matched" << endl;
	return true;
}

bool TicTacToe::isCol(int c, int sym) {
	//check if all symbols in this column are sym
	for(size_t i=0; i<_grid.size(); i++) {
		if(_grid[i][c].getVal() != sym)
			return false;
	}
	cout << __func__ << " matched" << endl;
	return true;
}

bool TicTacToe::isGameOver(int r, int c, Player& p) {
	int s = p.getSymbol();
	if(isFDiag(s) || isRDiag(s) || isRow(r, s) || isCol(c, s)) {
		cout << "Winner is Player:" << p.getSymbol() << endl;
		return true;
	}
	else
		return false;
}

void TicTacToe::printGrid() {
	for(size_t r=0; r<_grid.size(); r++) {
		for(size_t c=0; c<_grid.size(); c++) {
			cout << _grid[r][c].getVal() << "  ";
		}
		cout << endl;
	}

}

bool TicTacToe::setCell(int r, int c, Player& p) {
	if(r < 0 || c < 0 || r > int(_grid.size())-1 
		|| c > int(_grid.size())-1) {
		//if(!_playAuto)
			cout << "Invalid move, please re-try" << endl;
		return false;
	}

	if(!_grid[r][c].empty()) {
		if(!_playAuto)
			cout << "Invalid move, please re-try" << endl;
		return false;
	}
	
	if(_grid[r][c].setVal(p.getSymbol()))
		return true;
	
	return false;
}

void TicTacToe::autoPlay() {
	if(_gameUp) {
		cout << "Game is already over " << endl;
	}
	
	int playerId, r, c;
	while(_gameUp==false && _emptyCells!=0 ) {
		playerId = 0;
		for(Player& player:_vplayers) {
			do {
				//get a random row and col for this player
				r = rand() % _grid.size();
				c = rand() % _grid.size();
			}while(!setCell(r, c, player));
			_emptyCells--;
			if(_emptyCells == 0)
				break;
			cout << "Player :" << playerId << " selected "
				<< r << ", " << c << endl;
			//check if game over
			if((_gameUp = isGameOver(r, c, player))) {
				printGrid();
				break;
			}
			playerId++;
		}
		cout << _emptyCells << endl;
	}
	if(!_gameUp) {
		printGrid();
		cout << "Game Over - No winner" << endl;
		_gameUp = true;
	}
}

void TicTacToe::startPlay() {
	if(_playAuto) {
		autoPlay();
		return;
	}

	if(_gameUp) {
		cout << "Game is already over " << endl;
	}
	
	int playerId, r, c;
	while(_gameUp==false && _emptyCells!=0 ) {
		playerId = 0;
		for(Player& player:_vplayers) {
			do {
				Coordinate loc = player.getMove(_grid.size());
				r = loc.r;
				c = loc.c;
			}while(!setCell(r, c, player));
			printGrid();
			_emptyCells--;
			if(_emptyCells == 0)
				break;
			cout << "Player :" << playerId << " selected "
				<< r << ", " << c << endl;
			//check if game over
			if((_gameUp = isGameOver(r, c, player))) {
				printGrid();
				break;
			}
			playerId++;
		}
	}
	if(!_gameUp) {
		printGrid();
		cout << "Game Over - No winner" << endl;
		_gameUp = true;
	}
}

int main() {
	int gridSize = 3;
	int players = 2;
	TicTacToe game(gridSize, players);
	game.startPlay();
}
