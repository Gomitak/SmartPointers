#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string.h>
#include "theString.h"

#include "CarPtr.h"
using namespace std;

void display(){
	cout<<"c-Create Car"<<endl;
	cout<<"l-List all cars"<<endl;
	cout<<"1...5-Edit a car"<<endl;
	cout<<"p-Change price"<<endl;
	cout<<"s-Save all cars"<<endl;
	cout<<"q-Quit"<<endl;
	cout<<"enter:";
}

void createCar(CarPtr carArray[5],int id, ofstream&file){
	char make[300];
	char model[300]; 
	int year;
	char date[300];
	int cost;
	char pic[300];
	file<<(id+1)<<endl;
	
	cout<<"make:";
	cin>>make;
	file<<make<<endl;
	
	cout<<endl<<"model:";
	cin>>model;
	file<<model<<endl;
	
	cout<<endl<<"year:";
	cin>>year;
	file<<year<<endl;
	
	cout<<endl<<"date:";
	cin>>date;
	file<<date<<endl;
	
	cout<<endl<<"cost:";
	cin>>cost;
	file<<cost<<endl;
	
	cout<<endl<<"picture:";
	cin>>pic;
	file<<pic<<endl;
	cout<<endl;
	if(id == 0)
	{carArray[id].setCar((id+1),make,model,year,date,cost,pic);}
	else
	{
		carArray[id-1].~CarPtr();
		carArray[id].setCar((id+1),make,model,year,date,cost,pic);
	}
	//carArray[id].setCar((id+1),make,model,year,date,cost,pic);
	
}

int checkEmpty(ifstream&file, int cur){
	std::streampos current = file.tellg();
	file.seekg (0, file.end);
	bool empty = !file.tellg(); // true if empty file
	file.seekg (current, file.beg);
	if(empty){
		return 69;
	}
}

bool isEmpty(ifstream& pFile)
{
    bool epy = true;
    string line;

    while( pFile >> line ) 
        epy = false;

		return epy;
}

void displayAllCars(int thei,ifstream&file){
	int id = (thei+1);
	
	int count = 0;
	string line;
	char temp[100];
	int flag = 0;
	flag = checkEmpty(file,thei);
	if(flag == 69){
		cout<<"Car:"<<id<<" is EMPTY"<<endl;
	}
	else{
		
		while(getline(file,line)){
			if(count == 0)cout<<"Car:"<<line<<endl;
			else if(count == 1)cout<<"Make: "<<line<<endl;
			else if(count == 2)cout<<"Model: "<<line<<endl;
			else if(count == 3)cout<<"Year: "<<line<<endl;
			else if(count == 4)cout<<"Date: "<<line<<endl;
			else if(count == 5)cout<<"Cost: "<<line<<endl;
			else if(count == 6)cout<<"Pic: "<<line<<endl;
			count++;
		}
	}
	
	
}

void editCar(CarPtr carArray[5],int current, ifstream&file){
	int cost;
	int id;
	int year;
	int flag = 0;
	string maker,modelr,dater,pngr,line;
	int count = 0;
	char make[100];
	char model[100];
	char date[100];
	char png[100];
	
	flag = checkEmpty(file,current);
	
	if(isEmpty(file)){
		cout<<"Car:"<<current+1<<" is EMPTY"<<endl<<endl;
	}
	else{
		//delete the carPtrs
		//for(int i = 0; i<5; i++){
		//	carArray[i].~CarPtr();
		//}
	
		while(getline(file,line)){
		if(count == 0)
		{id = stoi(line);}
		else if(count == 1)
		{maker = (line);}
		else if(count == 2)
		{modelr =(line);}
		else if(count == 3)
		{year =stoi(line);}
		else if(count == 4)
		{dater =(line);}
		else if(count == 5)
		{cost =stoi(line);}
		else if(count == 6)
		{pngr =(line);}
		count++;
		}
		strcpy(make,maker.c_str());
		strcpy(model,modelr.c_str());
		strcpy(date,dater.c_str());
		strcpy(png,pngr.c_str());
		
		carArray[(current)].setCar(current,make,model,year,date,cost,png);
		
	}
	
	
}

void printCarPtr(CarPtr carArray[5],int i){
	cout<<"Car: "<<i+1<<endl;
	cout<<"Make: "<<carArray[i]->getMake()<<endl;
	cout<<"Model: "<<carArray[i]->getModel()<<endl;
	cout<<"Year: "<<carArray[i]->getYear()<<endl;
	cout<<"Date: "<<carArray[i]->getDate()<<endl;
	cout<<"Cost: "<<carArray[i]->getCost()<<endl;
	cout<<"Pic: "<<carArray[i]->getPic()<<endl;
}

int main()
{
	
	//id is 1-5
	//int id, string make, string model, string year, string date,int cost,string pic
	//Car c1(1,"Honda","Civic","2017","03/28/2017",20000,"civi");
	
    CarPtr carArray[5];//carPtr array of 5
	string result;
	ofstream myFile1("1.txt");
	ofstream myFile2("2.txt");
	ofstream myFile3("3.txt");
	ofstream myFile4("4.txt");
	ofstream myFile5("5.txt");
	ifstream getFile1;
	ifstream getFile2;
	ifstream getFile3;
	ifstream getFile4;
	ifstream getFile5;
	
	int carCount = 0;
	int currentCar = carCount;
	int otherCarCount = 0;
	char input[300];//input
	
	display();
	cin>>input;
	while(strcmp("q",input)!=0)
	{
		if(strcmp("c",input)==0){
			if(carCount<5){
				cout<<"creating car "<<(carCount+1)<<endl;
				if(carCount==0)createCar(carArray,carCount, myFile1);	
				else if(carCount==1)createCar(carArray,carCount,myFile2);
				else if(carCount==2)createCar(carArray,carCount,myFile3);
				else if(carCount==3)createCar(carArray,carCount,myFile4);
				else if(carCount==4)createCar(carArray,carCount,myFile5);
				currentCar = carCount;
				carCount++;
			}
			else cout<<"Exceeded limit of created cars"<<endl;
		}
		else if(strcmp("l",input)==0){
			for(int i = 0; i<5; i++){
				if(i == 0){
					getFile1.open("1.txt");
					displayAllCars(i,getFile1);
					getFile1.close();
				}
				else if(i == 1){
					getFile2.open("2.txt");
					displayAllCars(i,getFile2);
					getFile2.close();
				}
				else if(i == 2){
					getFile3.open("3.txt");
					displayAllCars(i,getFile3);
					getFile3.close();
				}
				else if(i == 3){
					getFile4.open("4.txt");
					displayAllCars(i,getFile4);
					getFile4.close();
				}
				else if(i == 4){
					getFile5.open("5.txt");
					displayAllCars(i,getFile5);
					getFile5.close();
				}
			}
		}
		else if(strcmp("1",input)==0){
			cout<<endl<<"editing car 1"<<endl;
			getFile1.open("1.txt");
			editCar(carArray,0,getFile1);
			getFile1.close();
			if(carCount >1)
			{
				cout<<"Nope"<<endl;
				carArray[(currentCar)].~CarPtr();
			}
			currentCar = 0;
		}
		else if(strcmp("2",input)==0){
			cout<<endl<<"editing car 2"<<endl;
			getFile2.open("2.txt");
			editCar(carArray,1,getFile2);
			getFile2.close();
			carArray[currentCar].~CarPtr();
			currentCar = 1;
		}
		else if(strcmp("3",input)==0){
			cout<<endl<<"editing car 3"<<endl;
			getFile3.open("3.txt");
			editCar(carArray,2,getFile3);
			getFile3.close();
			carArray[currentCar].~CarPtr();
			currentCar = 2;
		}
		else if(strcmp("4",input)==0){
			cout<<endl<<"editing car 4"<<endl;
			getFile4.open("4.txt");
			editCar(carArray,3,getFile4);
			getFile4.close();
			carArray[currentCar].~CarPtr();
			currentCar = 3;
		}
		else if(strcmp("5",input)==0){
			cout<<endl<<"editing car 5"<<endl;
			getFile5.open("5.txt");
			editCar(carArray,4,getFile5);
			getFile5.close();
			carArray[currentCar].~CarPtr();
			currentCar = 4;
		}
		else if(strcmp("p",input)==0){
			int amount;
			cout<<endl<<"Price change for Car"<<(currentCar+1)<<endl;
			cout<<"enter amount:";
			cin>>amount;
			cout<<"Entered:"<<amount<<endl;
			carArray[currentCar]->setCost(amount);
			printCarPtr(carArray,currentCar);
		}
		
		display();
		cin>>input;
	}
	

	
	
	return 0;
}