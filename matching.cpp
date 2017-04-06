#include <iostream>
#include <string>
#include <queue>
#include <vector>

/* ===== Pseudo Code =====
 * function stableMatching {
 *  Initialize all m  M and w  W to free
 *  while  free man m who still has a woman w to propose to {
 *     w = first woman on ms list to whom m has not yet proposed
 *     if w is free
 *       (m, w) become engaged
 *     else some pair (m', w) already exists
 *       if w prefers m to m'
 *          m' becomes free
 *         (m, w) become engaged 
 *       else
 *         (m', w) remain engaged
 *   }
 * }
 */

using namespace std;

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
		void engage(Person, Person);
	private:
		Position p;		
		Status s;
		queue<string> preferences;
		string match;
};

int main(int argc, char **argv) {
	return 0;
}


