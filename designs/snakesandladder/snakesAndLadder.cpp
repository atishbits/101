#include "snakesAndLadder.hpp"

Obstacles* Obstacles::create(ObstacleType ot, 
		map<unsigned int, unsigned int> mObst) {

	switch(ot) {
		case SNAKE: return new Snakes(mObst);	
				break;

		case LADDER: return new Ladders(mObst);
				break; 

		default:
			throw std::invalid_argument(
			"unknown obstable");
	}

}

int Snakes::getDest(const unsigned int source) {
	if(_mapSnakes.count(source))
		return _mapSnakes[source];
	else
		return -1;
}

int Ladders::getDest(const unsigned int source) {
	if(_mapLadders.count(source))
		return _mapLadders[source];
	else
		return 0;
}


Board::Board() {
	_size = 100;
	map<unsigned int, unsigned int> mSnakes = 
		{{15, 10},
		{25, 5},
		{33, 11},
		{49, 21},
		{77, 18},
		{90, 23}
		};
	map<unsigned int, unsigned int> mLadders = 
		{{5, 15},
		{9, 23},
		{15, 55},
		{33, 44},
		{77, 81},
		};

	_snakes = Obstacles::create(SNAKE, mSnakes);
	_ladders = Obstacles::create(LADDER, mLadders);

}

int main() {

}
