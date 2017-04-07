#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

extern const int PAIRS;

enum Position{
	One,
	Ten
};

enum Status{
	Available,
	Taken
};


class Person {
	public:
		Person(Position, string);
		~Person();
		void insertMatch(Person*);
		string getSelf();
		Status getStatus();
		void updateStatus(Status);
		Person * getNext();
		Person * getMatch();
		void updateMatch(Person*);
		int prefers(Person*, Person*);
		void print();
	private:
		string self;
		Position p;		
		Status s;
		std::vector<Person*> preferences;
		Person * match;
		int index;
};

