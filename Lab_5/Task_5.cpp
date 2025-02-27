#include <iostream>
#include <string>

using namespace std;

class Car{
	public:
		double hp;
		int seatcap;
		int speakers;
		Car(double hp , int seatcap , int speakers) : hp(hp),seatcap(seatcap) , speakers(speakers) {}
		void displayinfo(){
			cout<<"Horse Power : "<<hp<<endl<<"Seating Capacity : "<<seatcap<<endl<<"Speakers : "<<speakers<<endl;  
		}
		void changevalue(double nhp , int nseatcap , int nspeakers)const{
			const_cast<Car*>(this)->hp = nhp ; const_cast<Car*>(this)->seatcap = nseatcap ; const_cast<Car*>(this)->speakers = nspeakers ;
		}
};

int main(int argc , char* argv[]){
	Car car(stod(*(argv + 1)) , stoi(*(argv + 2)) , stoi(*(argv + 3))) ;
	cout<<"Initial Values :"<<endl ;
	car.displayinfo();
	car.changevalue(stod(*(argv + 4)), stoi(*(argv + 5)) , stoi(*(argv + 6)));
	cout<<"New Attributes :"<<endl ;
	car.displayinfo();
}