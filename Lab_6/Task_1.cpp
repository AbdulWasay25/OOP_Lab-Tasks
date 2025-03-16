#include<iostream>
using namespace std;

class Books{
    string Genre;
    public:
    Books(string g){Genre = g ;}
    string getgenre(){return Genre;}
};

class Novel : public Books {
    string title ;
    string author;
    public:
    Novel(string g , string t , string a) : Books(g) , title(t) , author(a) {}
    void displayinfo(){
        cout<<"Title : "<<title<<"\nAuthor : "<<author<<"\nGenre : "<<getgenre()<<endl ;
    }
};

class Narrative : public Books {
    string title ;
    string author;
    public:
    Narrative(string g , string t , string a) : Books(g) , title(t) , author(a) {}
    void displayinfo(){
        cout<<"Title : "<<title<<"\nAuthor : "<<author<<"\nGenre : "<<getgenre()<<endl ;
    }
};

class Mystery : public Books {
    string title ;
    string author;
    public:
    Mystery(string g , string t , string a) : Books(g) , title(t) , author(a) {}
    void displayinfo(){
        cout<<"Title : "<<title<<"\nAuthor : "<<author<<"\nGenre : "<<getgenre()<<endl ;
    }
};

int main(){
    Novel n = {"Novel" , "Harry Potter" , "Author1"} ;
    Narrative nar = {"Narrative" , "Narrative Book" , "Author2"} ;
    Mystery m = {"Mystery" , "Mystery Novel" , "Author3"} ;
    n.displayinfo();
    nar.displayinfo();
    m.displayinfo();
}