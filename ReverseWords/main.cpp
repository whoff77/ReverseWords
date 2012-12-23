#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;
void runCase();
void reverseString(stringstream &);
void tryVector(stringstream &);

int cases;
string origString, reversedString, junk;
string infileName = "bLargeIn.in", outfileName = "bLargeOut.out";
ifstream infile(infileName.c_str());
ofstream outfile(outfileName.c_str());

int main() {

	clock_t tStart = clock();

	infile >> cases;
	getline(infile, junk); 
	for (int i = 1; i <= cases; i++) {
		runCase();
		outfile << "Case #" << i << ": " << reversedString << endl;
	}

	infile.close();
	outfile.close();
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	cin.get();
	return 0;
}

void runCase() {

	getline(infile, origString);
	stringstream theStream(origString);
	reverseString(theStream);
	//tryVector(theStream);	// don't use
	reversedString = theStream.str();
}

void reverseString(stringstream &theStream) {
	if (theStream.eof()) {
		theStream.clear();
		theStream.str("");
		return;
	}
	string aString;
	theStream >> aString;
	reverseString(theStream);
	theStream << aString << " ";
}

// don't use this, it takes longer
void tryVector(stringstream &theStream) {
	string aString;
	vector<string> stringVector;
	vector<string>::iterator it;
	while (!theStream.eof()) {
		it = stringVector.end();
		theStream >> aString;
		stringVector.insert(it, aString);
	}
	theStream.clear();
	theStream.str("");
	//while (!stringVector.empty()) {
	//	theStream << stringVector.back() << " ";
	//	//cout << "theStream: " << theStream.str() << endl;
	//	stringVector.pop_back();
	//}
	for (int i=stringVector.size()-1; i>=0; i--) {
		theStream << stringVector[i] << " ";
		//cout << "theStream: " << theStream.str() << endl;
	}
}