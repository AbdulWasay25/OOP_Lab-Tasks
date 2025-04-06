#include<iostream>
#include<sstream>
#include<cmath>
#include<vector>
using namespace std;

class PolyUtils;

class Polynomials{
    vector<int> coeff ;
    void removezero(){
        while(!coeff.empty() && (coeff.back()) == 0){
            coeff.pop_back() ;
        }
    }
    public:
    Polynomials(){}
    Polynomials(vector<int> anyv) : coeff(anyv) {removezero();}
    friend class PolyUtils ;

    Polynomials operator+(const Polynomials& other)const{
        vector<int> result(max(coeff.size() , other.coeff.size()) , 0) ;
        for(size_t i=0 ; i<coeff.size() ; ++i){
            if(i<coeff.size()) result[i] += coeff[i] ;
            if(i<other.coeff.size()) result[i] += other.coeff[i] ;
        }
        return Polynomials(result) ;
    }
    Polynomials operator-(const Polynomials& other)const{
        vector<int> result(max(coeff.size() , other.coeff.size()) , 0) ;
        for(size_t i=0 ; i<coeff.size() ; ++i){
            if(i<coeff.size()) result[i] += coeff[i] ;
            if(i<other.coeff.size()) result[i] -= other.coeff[i] ;
        }
        return Polynomials(result) ;
    }
    Polynomials operator*(const Polynomials& other)const{
        vector<int> result(coeff.size() + other.coeff.size() - 1 , 0) ;
        for(size_t i=0 ; i<coeff.size() ; ++i){
            for(size_t j=0 ; j<other.coeff.size() ; ++j){
            result[i + j] += coeff[i] * other.coeff[i] ;}
        }
        return Polynomials(result) ;
    }

    friend ostream& operator<<(ostream& os , const Polynomials& poly){
        if(poly.coeff.empty()){ os << "0" ; return os ;}
        bool first = true ;
        for(int i = poly.coeff.size() - 1 ; i>=0 ; --i){
            int c = poly.coeff[i];
            if(c == 0){continue ;}
            if(!first){
                os << (c>0 ? "+" : "-") ;
            } else{
                if(c<0){os << "-" ;}
                first = false ;
            }
            int absolute = abs(c) ;
            if(absolute!=1 || i==0) os<<absolute;
            if(i>=1) os << "x";
            if(i>1) os<<"^"<<i ;
        }
        return os ;
    }
};

class PolyUtils{
    public:
    int evaluate(const Polynomials &p , int x ){
        int a = p.coeff.size() -1 ;
        int ans = 0 ;
        for(int i=a ; i>=0 ; --i){
            if(i==0){
                ans += p.coeff[i];
            }else{
            ans += p.coeff[i] * (pow(x , i)) ;
        }}
        return ans;
    }
    Polynomials derivative(const Polynomials &p) {
        int n = p.coeff.size();
        if (n <= 1) {
            return Polynomials({0});
        }
        vector<int> deriv(n - 1);
        for (int i = 1; i < n; ++i) {
            deriv[i - 1] = p.coeff[i] * i;
        }
    
        return Polynomials(deriv);
    }
};

int main(){
    Polynomials p1({1, 2, 3});    // 3x^2 + 2x + 1
    Polynomials p2({8, -2, 1});   // x^2 - 2x + 8

    Polynomials sum = p1 + p2;
    Polynomials diff = p1 - p2;
    Polynomials prod = p1 * p2;

    cout << "P1: " << p1 << std::endl;
    cout << "P2: " << p2 << std::endl;
    cout << "Sum: " << sum << std::endl;
    cout << "Difference: " << diff << std::endl;
    cout << "Product: " << prod << std::endl;
    class PolyUtils pu;

    int y = pu.evaluate(p1 , 2);
    cout<<y<<endl;
    cout<<pu.derivative(p2);

    return 0;
}