#pragma once
#include <iostream>
#include "theString.h"
#include <string>
class CarPrt;
using namespace std;
class Car{
	
	friend class CarPtr;
	private:
		int id;
		//string make;
		//string model;
		//string year;
		//string date;
		//string pic;
		int cost;
		theString make;
		theString model;
		int year;
		theString date;
		theString pic;
		//Car(int theid, string theMake, string theModel, string theYear, string theDate, int theCost, string thePic);
		Car(int theid, theString theMake, theString theModel, int theYear, theString theDate, int theCost, theString thePic);
		~Car(){}
	
		
	public:
	//Car(int theid, theString theMake, theString theModel, theString theYear, theString theDate, int theCost, theString thePic);
	int getId(){
		return id;
	}
	
	
	int setCost(int newCost){
		cost = newCost;
	}
	
	int getCost(){
		return cost;
	}
	
	int getYear(){
		return year;
	}
	
	theString getMake(){
		return make;
	}
	
	theString getModel(){
		return model;
	}
	theString getDate(){
		return date;
	}
	theString getPic(){
		return pic;
	}
	
};