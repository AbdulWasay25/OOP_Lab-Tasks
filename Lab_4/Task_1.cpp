#include<iostream>

using namespace std ;

class Circle{
	double radius ;
	public :
			Circle(double r) : radius(r) {}
			double getArea(){
				return (3.14)*(radius)*(radius) ;
			}
			double getPerimeter(){
				return 2*(3.14)*(radius) ;
			}
};

int main(int argc , char* argv[]){
	Circle circle(stod(*(argv + 1)));
	cout<<"Area = "<<circle.getArea()<<endl;
	cout<<"Perimeter = "<<circle.getPerimeter();
	return 0 ;
}