#include <iostream>
#include <vector>
#include <ctime>
#include <map>
using namespace std;

static const unsigned int diceMaxNum = 6;

class Dice {
public:
	Dice() {
		srand(time(NULL));
	};
	static int rollDice() {
		return rand()%diceMaxNum;
	}
};

class Player {
private:
	int _pId;
	int _currLoc;
	Player(){};
	//need to know which Board player is playing on so that correct location
	//can be set during playChance.
	
public:
	Player(int id):_pId(id), _currLoc(1){}
	int getPlayerId() {return _pId;}
	int getCurrLoc() {return _currLoc;}
	int playChance() {_currLoc += Dice::rollDice(); return _currLoc;}
	//void setLoc(const int loc) {_currLoc = loc;}
};

enum ObstacleType 
{
	SNAKE = 0,
	LADDER = 1
};

class Obstacles {
public:
	virtual ~Obstacles(){};
	virtual int getDest(
		const unsigned int source)=0;
    static Obstacles* create(ObstacleType, 
		map<unsigned int, unsigned int>);
};

class Snakes : public Obstacles {
private:
	//source to destination map
	map<unsigned int, unsigned int> _mapSnakes;
	Snakes() {};

public:
	Snakes(map<unsigned int, unsigned int> mSnakes) {
		_mapSnakes = mSnakes;
	}
	int getDest(const unsigned int source);
};

class Ladders : public Obstacles {
private:
	//source to destination map
	map<unsigned int, unsigned int> _mapLadders;
	Ladders() {};

public:
	Ladders(map<unsigned int, unsigned int> mLadders) {
		_mapLadders = mLadders;
	}
	int getDest(const unsigned int source);

};

class Board {
private:
	unsigned int _size;
	Obstacles* _snakes;
	Obstacles* _ladders;
	vector<int> _board; 

public:
	Board();

};
