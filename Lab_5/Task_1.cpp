#include<iostream>

using namespace std;

class Engine{
	bool isRunning;
	public:
		Engine(){
			cout<<"Engine Class created"<<endl;
/*if(isr == 1){
cout<<"Engine Running"<<endl;
}else{
cout<<"Engine Not Running"<<endl;
}*/
		}
		~Engine(){
			cout<<"Engine Class Destroyed"<<endl;
		}
		void start(){
			cout<<"Engine Started"<<endl;
		}
		void stop(){
			cout<<"Engine Stopped"<<endl;
		}
	};

class Car{
	Engine engine ;
	public:
		Car(){
			cout<<"Car Class Created"<<endl;
		}
		~Car(){
			cout<<"Car Class Destroyed"<<endl;
		}
		void startcar(){
			engine.start();
		}
		void stopcar(){
			engine.stop();
		}
	};

int main(int argc , char*argv[]){
	Car car1;
	car1.startcar();
	car1.stopcar();
	return 0;
	}