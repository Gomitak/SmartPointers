//class Car;
#pragma once
#include <iostream>
#include <string>
//#include "carFile.h"
#include "Car.h"
#include "theString.h"
using namespace std;

class CarPtr {
	
	int id;
	Car* pCar; 
	public:
		//CarPtr(int);
		//CarPtr(Car*theCar);
		CarPtr();
		//CarPtr(int theid, string theMake, string theModel, string theYear, string theDate, int theCost, string thePic);
		//Car* setCar(int theid, string theMake, string theModel, string theYear, string theDate, int theCost, string thePic);
		CarPtr(int theid, theString theMake, theString theModel, int theYear, theString theDate, int theCost, theString thePic);
		Car* setCar(int theid, theString theMake, theString theModel, int theYear, theString theDate, int theCost, theString thePic);
		//{pCar(theid, theMake,theModel,theYear, theDate, theCost, thePic);}
		~CarPtr(){cout<<"Car:"<<id<<" deleted from Mem"<<endl;}
		Car* operator->() const;
		Car& operator*() const; 
		Car* getPcar(){return pCar;}
	
	//protected:
		//int id;
		//Car* pCar;
		//CarPtr(const CarPtr&); 
		//CarPtr& operator=(const CarPtr&) ; // no assignment operator
		//carFile carIndex(id);
		//static int CACHE_SIZE;
		//static carCache cache(CACHE_SIZE); 
};