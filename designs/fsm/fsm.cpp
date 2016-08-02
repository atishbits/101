#include <iostream>
#include <map>
using namespace std;

static const int START_STATE = -1;

class FSM {
private:
	map<int, map<char, int>> _mStateMachine;
	int _currentState;
	int _numStates;
	vector<char> _vTriggers;

public:
	FSM() {};

	bool addState(const int state, map<char, int>& transitions, bool endState);
	bool removeState(const int state);
	bool input(const char trigger);

	bool addTrigger(const char trigger,	
		vector<tuple<int, char, int>>& transitions) 
};

FSM::FSM() {
	_vTriggers = {'a', 'b', 'c'};	//default triggers
	_numStates = 0;
	_currentState = START_STATE;
}
