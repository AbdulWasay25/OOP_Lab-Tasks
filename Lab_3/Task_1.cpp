#include<iostream>
#include<string>

using namespace std ;

class User{
public :
string name ;
int age ;
};

int main(int argc , char* argv[]){
User user1 ;
user1.name = *(argv + 1);
user1.age = stoi(*(argv + 2));

cout<<"My Name Is "<<user1.name <<endl<<"I'm "<<user1.age<<" Years Old" ;

return 0 ;
}