cc = g++

options = -g -std=c++11
exe = Matching

all: Matching
Matching: matching.cpp
	$(cc) matching.cpp -o $(exe) $(options)

clean:
	rm $(exe) 
