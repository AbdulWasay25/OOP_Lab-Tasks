#include<iostream>
using namespace std;

class Shape{
    protected:
    int position ;
    string color;
    public:
    Shape(int p , string col):position(p) , color(col) {}
    virtual void draw(){}
    virtual float Area(){return 0.00;}
    virtual float Perimeter(){return 0.00;}
};

class Circle : public Shape{
    float radius;
    int centreposition;
    public:
    Circle(int p , string col , float r , int cp):Shape(p,col) , radius(r) , centreposition(cp) {}
    void draw() override {
        cout<<"Drawing Circle With Radius "<<radius<<" , Having Centre At "<<centreposition<<" , and Positioned at "<<position<<endl;
    }
    float Area() override{
        float area = 3.14 * radius * radius ;
        return area ;
    }
    float Perimeter() override{
        float per = 2 * 3.14 * radius ;
        return per ;
    }
};

class Rectangle : public Shape{
    float length;
    float width;
    int lefttopposition;
    public:
    Rectangle(int p , string col , float l ,float w , int ltp):Shape(p,col) , length(l) , width(w) , lefttopposition(ltp) {}
    void draw() override {
        cout<<"Drawing Rectangle With Length "<<length<<" , Width "<< width <<" , Having Left Top At "<<lefttopposition<<" , and Positioned at "<<position<<endl;
    }
    float Area() override{ ;
        return length*width ;
    }
    float Perimeter() override{
        return 2*(length+width) ;
    }
};

class Triangle : public Shape{
    float base , height;
    float a , b , c;
    int topposition;
    public:
    Triangle(int p , string col , float bas ,float h , float a, float b, float c, int tp):Shape(p,col) , base(bas) , height(h) , topposition(tp) {}
    void draw() override {
        cout<<"Drawing Triangle With Base "<<base<<" , Height "<< height <<" , Having Top Corner At "<<topposition<<" , and Positioned at "<<position<<endl;
    }
    float Area() override{ ;
        return 0.5*base*height ;
    }
    float Perimeter() override{
        return a+b+c ;
    }
};


int main(){
    Rectangle r1(2 , "Green" , 5.5 , 3.2 , 4) ;
    r1.draw() ;
    cout<<"Area Of Rectangle r1 = "<<r1.Area() <<endl;
    cout<<"Perimeter Of Rectangle r1 = "<<r1.Perimeter() <<endl;
}