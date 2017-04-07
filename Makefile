cc = g++

options = -g -std=c++11
exe = Matching

all: Matching
Matching: matching.cpp Person.cpp
	$(cc) matching.cpp Person.cpp -o $(exe) $(options)

clean:
	rm $(exe) 
