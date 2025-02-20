#include<iostream>

using namespace std ;

class Menu{
	string name;
	string type;
	double price;
	public:
		Menu(string n , string t , double p) : name(n) , type(t) {
		if(p<0){
            price=0;
        }else{
            price=p;}}
        void display(){
        	cout<<"Item Name : "<<name ;
        	cout<<"Item Type : "<<type ;
        	cout<<"Item Price : "<<price ;
		}   
		string getName(){
			return name;
		} 
		string getType(){
			return type;
		}
		double getPrice(){
			return price;
		}
		double Totalprice(int quantity){
			return quantity*price ;
		}
};
class CoffeeShop{
	string name ;
	Menu** menu ;
	string* orders ;
	int s1 ; int s2;int ordersize;
	public:
		CoffeeShop(string name , int s1 , int s2 , Menu* m[] ){
			this->name=name ;
			this->s1=s1; this->s2=s2 ;
			ordersize=0 ;
			menu = new Menu*[s1] ;
			orders = new string[s2] ;
			for(int i=0 ; i<s1 ; i++){
				menu[i] = m[i] ; 
			}
		}
		string addOrder(string dish){
			for(int i=0 ; i<s1 ; i++){
				if(menu[i]->getName()==dish){
					if(ordersize<s2){
						orders[ordersize++]=dish;}
						return "Order Added" ;
				}
			}
			return "Unavailable" ;
		}
		string fullfillorder(){
			if(ordersize > 0) {
            	string fulfilled = orders[0];
            	for(int i = 1; i < ordersize; ++i) {
                	orders[i-1] = orders[i];
            		}
            	--ordersize;
            	return "The " + fulfilled + " is ready";
        }
        return "All orders have been fulfilled";
		}
		string listorders(){
			if(ordersize == 0) {
            string emptyArray[1] = {""};
            //return emptyArray;
        }
        return *orders;
		}
		double dueAmount(){
			double total = 0.0;
        	for(int i = 0; i < ordersize; ++i) {
            	for(int j = 0; j < s1; ++j) {
                	if(orders[i] == menu[j]->getName()) {
                    	total += menu[j]->getPrice();
                	}
            	}
        	}
        	return total ;
		}
		string cheapestItem(){
			double minPrice = menu[0]->getPrice();
        	string cheapest = menu[0]->getName();
        	for(int i = 1; i < s1; ++i) {
            	if(menu[i]->getPrice() < minPrice) {
                	minPrice = menu[i]->getPrice();
                	cheapest = menu[i]->getName();
           		}
        	}
        	return cheapest;
		}
		string drinksOnly(){
			string drinks[s1];
        	int count = 0;
        	for(int i = 0; i < s1; ++i) {
            	if(menu[i]->getType() == "Drink" && count < s1) {
                	drinks[count++] = menu[i]->getName();
            	}
        	}
        	return *drinks;
		}
		string foodOnly(){
			string food[s1];
        	int count = 0;
        	for(int i = 0; i < s1; ++i) {
            	if(menu[i]->getType() == "Food" && count < s1) {
                	food[count++] = menu[i]->getName();
            	}
        	}
        	return *food;
    }
		
};

int main(int argc , char* argv[]){
	Menu m[4]= {{"Latte" , "Drink" , 250} , {"abc" , "Food" , 100} , {"xyz" , "Food" , 200} , {"def" , "Drink" , 150}};
	CoffeeShop cafe(*(argv + 1) , stoi(*(argv + 2)) , stoi(*(argv + 2)) , &m);
	return 0;
}