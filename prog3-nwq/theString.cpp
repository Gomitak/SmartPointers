#include "theString.h"
#include <iostream>
# include <string.h>


theString::theString(){
	stringLength = 0;
	myString = new char[1];
	myString[0] = '\0';
}

theString::theString(const char *sentString){
	stringLength = strlen(sentString);
	myString = new char[stringLength+1];
	strcpy(myString,sentString);
	//for (int i = 0; i < stringLength; i++)
	//	myString[i] = sentString[i];

}

theString::theString(const theString &sentString){
	stringLength = sentString.stringLength;
	myString = new char[stringLength+1];
	//for (int i = 0; i < stringLength; i++)
	//	myString[i] = sentString.myString[i];
	strcpy(myString,sentString.myString);
}

theString::~theString(){
	delete[]myString;
}

theString& theString::operator=(const theString& rhs) {
	if (this == &rhs) return *this; // if same rhs and lhs, do nothing
	else {
		stringLength = rhs.stringLength;
		delete[] myString; // delete old receiver
		myString = new char[stringLength + 1];
		strcpy(myString, rhs.myString);
		return *this; 
		}
} 

ostream& operator <<(ostream &os, const theString& sentString){
	os<<sentString.myString;
	return os;
}


char*& theString::getString(){
	return myString;
}

int theString::getLength(){
	return stringLength;
}
