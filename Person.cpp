#include "Headers.hpp"

Person::Person(Position p, string self) {
	this->self = self;
	this->p = p;
	this->s = Available;
	this->preferences = vector<Person*>(PAIRS);
	this->match = nullptr;
	this->index = 0;
}

Person::~Person() {

}

void Person::insertMatch(Person * p) {
	this->preferences[this->index++] = p;
	if(this->index == PAIRS)
		this->index = 0;
}

string Person::getSelf() {
	return this->self;
}

Status Person::getStatus() {
	return this->s;
}

void Person::updateStatus(Status s) {
	this->s = s;
}

Person * Person::getNext() {
	return this->preferences[this->index++];
	if(this->index == PAIRS)
		this->index = 0;
}

Person * Person::getMatch() {
	return this->match;
}

void Person::updateMatch(Person * p) {
	this->match = p;
}

int Person::prefers(Person * p1, Person * p2) {
	int i = 0, j = 0;
	for(int k = 0; k < PAIRS; k++) {
		if(this->preferences[k] == p1)
			i = k;
		if(this->preferences[k] == p2)
			j = k;
	}
	return (i < j)?1:0;
}

void Person::print() {
	cout << this->getSelf() << endl;
	for(int i = 0; i < PAIRS; i++)
		cout << "\t" << this->preferences[i]->getSelf() << endl;
}
