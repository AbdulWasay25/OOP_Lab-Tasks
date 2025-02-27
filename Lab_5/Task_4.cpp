#include <iostream>
#include <string>

using namespace std;

class Blend{
	public:
		void blendjuice(string fruit){
			cout<<"Blending " <<fruit << endl ; 
		}
};

class Grind{
	public:
		void blendjuice(string fruit){
			cout<<"Grinding "<< fruit <<endl ; 
		}
};

class JuiceMaker{
	Blend blender;
	Grind grinder;
	public :
		void blendJuice(string fruit){
			blender.blendjuice(fruit);
		}
		void grindJuice(string fruit){
			grinder.blendjuice(fruit);
		}
};

int main(int argc , char* argv[]){
	JuiceMaker jm ;
	for(int i=0 ; i<argc ; i++){
		jm.blendJuice(*(argv + i));
	}
	for(int i=0 ; i<argc ; i++){
		jm.grindJuice(*(argv + i));
	}
}