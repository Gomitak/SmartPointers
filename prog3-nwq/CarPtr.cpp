#include "CarPtr.h"
using namespace std;

CarPtr::CarPtr()
:pCar(NULL){
}

CarPtr::CarPtr(int theid, theString theMake, theString theModel, int theYear, theString theDate, int theCost, theString thePic)
{
Car *c = new Car(theid, theMake,theModel,theYear, theDate, theCost, thePic);
id = theid;
pCar = c;
}

Car*CarPtr::setCar(int theid, theString theMake, theString theModel, int theYear, theString theDate, int theCost, theString thePic)
{
	Car *c = new Car(theid, theMake,theModel,theYear, theDate, theCost, thePic);
	id = theid;
	pCar = c;
	return pCar;
}
 //inline CarPtr::CarPtr(Car*theCar):pCar(NULL){
//	 pCar=theCar;
	 
 //}
//inline CarPtr::~CarPtr(){
//	delete pCar;
//}
 
Car* CarPtr::operator->() const{
	 //if (pCar == NULL)
	 //pCar = cache.loadFromFile(id, carIndex, pCar);
	 return pCar; 
 }
 
Car& CarPtr::operator*() const{
	 //if (pCar == NULL)
	 //pCar = cache.loadFromFile(id, carIndex, pCar);
	 return *pCar; 
 } 