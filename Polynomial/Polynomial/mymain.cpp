#include <iostream>
#include "Polynomial.h"
#include "Interface.h"

int main(int argc, char *argv[]){
	//Constructor & Destructor
	Polynomial a;
	cin >>a;
	Polynomial cp(a); // Copy Constructor
	cout<<cp<<endl;
	Polynomial b;
	cin >>b;

	//Polynomial Function
	/*Get & Set */

	/*Derivative*/
	a.Derivative();
	cout<<"Derivative a:";
	cout<<a<<endl;
	b.Derivative().Derivative();	
	cout<<"Double Derivative b :";
	cout<<b<<endl;

	//Operator Overloading
	Polynomial c;
	/*Operator(+)*/
	cout<<"Operator(+) a+b:"<<endl;
	c = a+b;
	cout<<c<<endl;
	/*Operator(+)(int)*/

	/*Operator(int)(+)*/

	/*Operator(-)*/
	cout<<"Operator(-) a-b:"<<endl;
//	c = a-b;
	cout<<c<<endl;
	/*Operator(+)(int)*/

	/*Operator(int)(+)*/

	/*Operator(*)*/
	cout<<"Operator(*) a*b:"<<endl;
	c = a*b;
	cout<<c<<endl;
	/*Operator(*)(int)*/
	cout<<"Operator(*) a*(2):"<<endl;
	c = a*2;
	cout<<c<<endl;
	/*Operator(int)(*)*/
	cout<<"Operator(*) (2)*a:"<<endl;
	c= 2*a;
	cout<<c<<endl;


	/*Operator(+=)*/
	cout<<"Operator(+=)  c+=a:"<<endl;
	c +=a;
	cout<<c<<endl;
	/*Operator(+=)*(int)/


	/*Operator(-=)*/
	cout<<"Operator(-=)  c-=a:"<<endl;
	c -=a;
	cout<<c<<endl;
	/*Operator(-=)*(int)/



	/*Operator(*=)*/
	cout<<"Operator(-=)  c-=a:"<<endl;
	c -=a;
	cout<<c<<endl;

	/*Operator(*=)(int)*/
	cout<<"Operator(*=)  c*=2:"<<endl;
	c *=2;
	cout<<c<<endl;

	//Operator Comparison
	if(c==a){
		cout<<"Polynomial c is equal a"<<endl;
	}
	if(c!=a){
		cout<<"Polynomial c is not equal a"<<endl;
	}

	if(c>a){
		cout<<"Polynomial c is longer than a"<<endl;
	}

	if(c<a){
		cout<<"Polynomial c is shorter than a"<<endl;
	}

	int ans = c(3); //operator() overloading


	//Interface Program

}