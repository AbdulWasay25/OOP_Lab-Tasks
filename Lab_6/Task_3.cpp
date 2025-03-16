#include<iostream>
using namespace std;

class Student{
    int ID;
    string name;
    public:
    Student(int i , string na) : ID(i) , name(na){}
    void getstudentdetail(){
        cout<<"Student ID : "<<ID<<"\nStudent Name : "<<name<<endl;
    }
};

class Marks : public Student{
    protected:
    int oop , pf , ds , db;
    public:
    Marks(int id , string n , int oop , int pf , int ds ,int db) : Student(id , n) , oop(oop),pf(pf),ds(ds),db(db) {}
    void getmarks(){
        cout<<"OOP = "<<oop<<"\nPF = "<<pf<<"\nDS = "<<ds<<"\nDB = "<<db<<endl ;
    }
};

class Result : public Marks{
    protected:
    int totalmarks;
    double avg;
    public:
    Result(int id , string n , int oop , int pf , int ds ,int db):Marks(id , n , oop , pf , ds , db){}
    int total(){
        totalmarks = oop + pf + ds + db ;
        return totalmarks ;
    }
    double average(){
        avg = total()/4 ;
        return avg ;
    }
    void display(){
        getstudentdetail();
        cout<<"Course Wise Marks :"<<endl ;
        getmarks();
        cout<<"Total Marks = "<<total()<<"\nAverage = "<<average()<<endl ;
    }
};

int main(){
    Result r = {500 , "Abdul Wasay" , 75 , 84 , 79 ,  70} ;
    r.display();
}