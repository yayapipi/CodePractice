#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

class Number{
	protected:
		int n;
	public:
		//Constructor & Destructor
		Number(){
			this->n=0;
		}
		Number(const int &a){
			if(a>-10&&a<10){
				this->n = a;
			}else{
				cout<<"Input Error,Please Input 1 digit number :D"<<endl;
				exit(1);
			}
		}
		Number(const Number &a):n(a.n){}
		~Number(){};

		//Function
		int getNumber(){
			return n;
		}
		int setNumber(const int a){
			if(a>-10&&a<10){
				this->n = a;
			}else{
				cout<<"Input Error,Please Input 1 digit number :D"<<endl;
				exit(1);
			}
		}

	virtual	bool equals(const Number &a){
			if(this->n == a.n){
				return true;
			}else{
				return false;
			}
		}

	virtual	bool compare(const Number &a){
			if(this->n > a.n){
				return true;
			}else{
				return false;
			}
		}

	virtual	std::string toString(){
			string number;
			number = this->n + '0';
			return number;
		}



};
