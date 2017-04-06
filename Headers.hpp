#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>

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
		Person();
		~Person();
		Status getStatus();
		void updateStatus(Status);
		Person getNext();
		void updateMatch(Person);
	private:
		Position p;		
		Status s;
		std::queue<Person> preferences;
		Person match;
};

Person::Person() {

}

Person::~Person() {

}

Status Person::getStatus() {
	return this->s;
}

void Person::updateStatus(Status s) {

}

Person Person::getNext() {
	return this->preferences.pop();
}

void Person::updateMatch(Person p) {
	this->match = p;
}
