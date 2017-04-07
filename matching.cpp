#include "Headers.hpp"

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

const int PAIRS = 4;

void init(char * filename, vector<Person*> &ones, vector<Person*> &tens) {
	int count = 0;
	string line;
	vector<string> file;
	ifstream fd;
	
	//open file
	fd.open(filename);
	
	//put each line of the file into vector<string> list
	if(fd.is_open()) {
		while(getline(fd, line)) {
			file.push_back(line);
			count++;
		}
	} else {
		cout << "Invalid filename." << endl;
		exit(1);
	}
	if(count % 2 != 0) {
		cout << "Must be an even number of people in the list" << endl;
		exit(1);
	}
	
	fd.close();
	char split_char = ',';

	unordered_map<string, Person*> map;
	int one = 0;
	int ten = 0;
	//create an object for each line of the file and store in this->people
	for(int i = 0; i < count; i++) {
		vector<string> b;
		//split each value of commas into vector<string> b
		istringstream split(file[i]);
		for(string each; getline(split, each, split_char); b.push_back(each));

		//create new Person object and add to hashmap
		Position p = (stoi(b[0]) == 1)?One:Ten;
		if(stoi(b[0]) == 1) {
			ones[one] = new Person(p, b[1]);
			map.insert({b[1], ones[one]});
			one++;
		} else {
			tens[ten] = new Person(p, b[1]);
			map.insert({b[1], tens[ten]});
			ten++;
		}
	}

	one = 0;
	ten = 0;
	for(int i = 0; i < count; i++) {
		vector<string> b;
		//split each value of commas into vector<string> b
		istringstream split(file[i]);
		for(string each; getline(split, each, split_char); b.push_back(each));
		
		for(int j = 2; j < PAIRS+2; j++) {
			unordered_map<string, Person*>::const_iterator it = map.find(b[j]);
			if(it == map.end()) {
				cout << "Error in Hashmap" << endl;
				exit(1);
			}

			if(stoi(b[0]) == 1)
				ones[one]->insertMatch(it->second);
			else
				tens[ten]->insertMatch(it->second);

			if(stoi(b[0]) == 1 && j == PAIRS+1)
				one++;
			if(stoi(b[0]) == 10 && j == PAIRS+1)
				ten++;
		}
	}
}

int freeMan(vector<Person*> &ones) {
	//if there is an available man who doesn't have a match, return their index
	for(int i = 0; i < PAIRS; i++) {
		if(ones[i]->getMatch() == nullptr)
			return i;
	}
	return -1;
}

void engage(Person * p1, Person * p2) {
	p1->updateStatus(Taken);
	p1->updateMatch(p2);
	p2->updateStatus(Taken);
	p2->updateMatch(p1);
}

void freeMan(Person * p1) {
	p1->updateStatus(Available);
	p1->updateMatch(nullptr);
}

void printMatches(vector<Person*> &ones, vector<Person*> &tens) {
	cout << "========== Matches ==========" << endl;
	for(int i = 0; i < PAIRS; i++)
		cout << ones[i]->getSelf() << " - " << 
		ones[i]->getMatch()->getSelf() << endl;
}

int main(int argc, char **argv) {
	vector<Person*> ones(PAIRS);
	vector<Person*> tens(PAIRS);	
	init(argv[1], ones, tens);
	cout << "========== Preferences ==========" << endl;
	for(int i = 0; i < PAIRS; i++) {
		cout << ones[i]->getSelf() << ": ";
		for(int j = 0; j < PAIRS; j++) {
			cout << ones[i]->getNext()->getSelf();
			if(j == PAIRS - 1)
				cout << endl;
			else
				cout << ", ";
		}
	}
	cout << endl;

	int i;
	while((i = freeMan(tens)) != -1) {
		Person * partner = tens[i]->getNext();
		if(partner->getStatus() == Available) {
			engage(tens[i], partner);	
		} else {
			if(partner->prefers(tens[i], partner->getMatch())) {
				freeMan(partner->getMatch());
				engage(partner, tens[i]);
			}
		}
	}

	printMatches(ones, tens);
	
	return 0;
}

