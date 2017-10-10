#include <iostream>
#pragma once
using namespace std;
class theString{
	private:
		char* myString;
		int stringLength;
	public:
		theString();
		theString(const char *sentString);
		theString(const theString &sentString);
		~theString();
		theString & operator = (const theString &sentString);
		friend ostream& operator << (ostream& OS, const theString &S); //output
		//stream& operator >> (ostream& OS, const theString &S) //input
		char* &getString();
		int getLength();
};