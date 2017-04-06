#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

enum Position{
	One,
	Ten
};

enum Status{
	Available,
	Taken
};


const int PAIRS = 6;

class Person {
	public:
		Person(Position, std::vector<Person*>);
		~Person();
		Status getStatus();
		void updateStatus(Status);
		Person * getNext();
		Person * getMatch();
		void updateMatch(Person*);
		int prefers(Person*, Person*);
	private:
		Position p;		
		Status s;
		std::vector<Person*> preferences;
		Person * match;
		int index;
};

Person::Person(Position p, std::vector<Person*> pref) {
	this->p = p;
	this->preferences = pref;
	this->s = Available;
	this->match = nullptr;
	this->index = 0;
}

Person::~Person() {

}

Status Person::getStatus() {
	return this->s;
}

void Person::updateStatus(Status s) {
	this->s = s;
}

Person * Person::getNext() {
	return this->preferences[index++];
}

Person * Person::getMatch() {
	return this->match;
}

void Person::updateMatch(Person * p) {
	this->match = p;
}

int Person::prefers(Person * p1, Person * p2) {
	//TODO: double check this
	int i = 0, j = 0;
	for(int k = 0; k < PAIRS; k++) {
		if(this->preferences[k] == p1)
			i = k;
		if(this->preferences[k] == p2)
			i = j;
	}
	return (i < j)?1:0;
	
}
