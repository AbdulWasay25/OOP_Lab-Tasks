#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Car{
	string name;
	int ID;
	public:
		Car(string name , int ID) : name(name) , ID(ID){cout<<"Car Class Created"<<endl;}
		string getcarname(){
			return name ;
		}
		int getcarID(){
			return ID ;
		}
		~Car(){
			cout<<"Car Class Destroyed"<<endl;
		}
	};

class Garage{
	vector< Car*>cars;
	public:
		Garage(){cout<<"Garage Class Created"<<endl;};
		void parkCar(Car* car){
			cars.push_back(car);
		}
		void listcars(){
			for(auto& car : cars )
				cout<<"Car Name : "<<car->getcarname() <<"\tCar ID : "<<car->getcarID()<<endl;
		}
		~Garage(){
			cout<<"Garage Class Destroyed"<<endl;
		}
};

int main(int argc, char* argv[]) {
    auto car1 = Car(*(argv + 1), stoi(*(argv + 2)));
    auto car2 = Car(*(argv + 3), stoi(*(argv + 4)));
     auto car3 = Car(*(argv + 5), stoi(*(argv + 6)));
    Garage garage;
    garage.parkCar(&car1);
    garage.parkCar(&car2);
    garage.parkCar(&car3);
	garage.listcars();
}