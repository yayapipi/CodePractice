#include <iostream>
#include "Polynomial.h"
#include "Interface.h"

using namespace std;


void NewPolynomial();
void ShowPolynomial();
void AddPolynomial();
void SubPolynomial();
void MulPolynomial();
void ComparePolynomial();
void DevPolynomial();
void CalPolynomial();

Polynomial pl[Max];
int polynomial_size=0;

int main(){

	//TA DATA TEST
	cout << "-------------------------------------------------------------" << endl;
	cout << "Please Type in coefficients and exponents, seperated by SPACE" << endl;
	cout << ", and add 0 -1 in the end" << endl;
	cout << "For example, if you wish to assign P1 as 5x^3 -4x^2 + x -9" << endl;
	cout << "Type: 5 3 -4 2 1 1 -9 0 0 -1"<<endl;
	cout << "-------------------------------------------------------------" << endl << endl;

	Polynomial P1, P2, P3, P4;
	cout << "* Assign values for polynomial P1 *" << endl;
	cout << "Input: ";
	cin >> P1;
	cout << "P1 is: " << P1 << endl << endl;

	cout << "* Assign values for polynomial P2 *" << endl;
	cout << "Input: ";
	cin >> P2;
	cout << "P2 is: " << P2 << endl << endl;

	cout << "P3 = P1 - P2" <<endl;
	P3 = P1 - P2;
	cout << "Now P3 is: " << P3 << endl << endl;

	cout << "P3 += 11" << endl;
	P3 += 11;
	cout << "Now P3 is: " << P3 << endl << endl;

	cout << "P3 += P1" << endl;
	P3 += P1;
	cout << "Now P3 is: " << P3 << endl << endl;

	cout << "P3 = P1 * 4" << endl;
	P3 = P1 * 4;
	cout << "Now P3 is: " << P3 << endl << endl;

	cout << "P3 *= P2" << endl;
	P3 *= P2;
	cout << "Now P3 is: " << P3 << endl << endl;

	cout << "P3 = 2 * P1 * P2" << endl;
	P3 = 2 * P1 * P2;
	cout << "Now P3 is: " << P3 << endl << endl;

	cout << "P4 = P2 * 2 * P1" << endl;
	P4 = P2 * 2 * P1;
	cout << "Now P4 is: " << P4 << endl << endl;

	cout << "P3 now equals to P4, is that true?" << endl;
	if (P3 == P4) cout << "TRUE";
	else cout << "FALSE";
	cout << endl << endl;
	
	cout << "P4 is: " << P4 << endl;
	cout << "P4 (-6) equals to: " << P4(-6) <<endl << endl;

	cout << "---------- END TA PROGRAM ----------" << endl << endl;




	cout<<"Press any key to continue with my own data test"<<endl;
	getchar();getchar();
	//My Main Test Data

	//Constructor & Destructor
	Polynomial a;
	cin >>a;
	Polynomial cp(a);	 // Copy Constructor
	cout<<"Copy Constructor:"<<endl;
	cout<<cp<<endl;
	Polynomial b;
	cin >>b;
	//Polynomial Function
	/*Get & Set */
	int ary[]={8,7,6,5,4,3,2,1,0,-1};
	int ary2[10];
	Polynomial s;
	s.Set(ary,10);
	cout<<"Set Polynomial:"<<endl;
	//cout<<s;
	s.Get(ary2,10);

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
	c = a+2;
	cout<<"c=a+2:"<<c<<endl;

	/*Operator(int)(+)*/
	c = 2+a;
	cout<<"c=2+a:"<<c<<endl;

	/*Operator(-)*/
	cout<<"Operator(-) a-b:"<<endl;
	c = a-b;
	cout<<c<<endl;
	/*Operator(-)(int)*/
	c = 2-a;
	cout<<"c=2-a:"<<c<<endl;

	/*Operator(int)(-)*/
		c = a-2;
	cout<<"c=a-2:"<<c<<endl;

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

	/*Operator(-=)*/
	cout<<"Operator(-=)  c-=a:"<<endl;
	c -=a;
	cout<<c<<endl;

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









	cout<<"Press Any Key To Enter Interface System!!!"<<endl;
	getchar();
	//Interface System
	Interface interface;

	interface.SetProgramName("Polynomial Hw5 Interface Demo");

	//Setting Function 1
	interface.SetListName("New Polynomial",1);
	interface.SetListHelp("to create a new polynomial",1);
	interface.SetFunc(NewPolynomial,1);

	//Setting Function 2
	interface.SetListName("Show Polynomial",2);
	interface.SetListHelp("to show all polynomial list",2);
	interface.SetFunc(ShowPolynomial,2);

	//Setting Function 3
	interface.SetListName("Add Polynomial",3);
	interface.SetListHelp("adding two polynomial in the list",3);
	interface.SetFunc(AddPolynomial,3);

	//Setting Function 4
	interface.SetListName("Substract Polynomial",4);
	interface.SetListHelp("subtracting two polynomial in the list",4);
	interface.SetFunc(SubPolynomial,4);

	//Setting Function 5
	interface.SetListName("Multiply Polynomial",5);
	interface.SetListHelp("to multiply two polynomial in the list",5);
	interface.SetFunc(MulPolynomial,5);

	//Setting Function 6
	interface.SetListName("Compare Polynomial",6);
	interface.SetListHelp("compare two polynomial in the list",6);
	interface.SetFunc(ComparePolynomial,6);

	//Setting Function 7
	interface.SetListName("Derivative Polynomial",7);
	interface.SetListHelp("to derivative a polynomial",7);
	interface.SetFunc(DevPolynomial,7);

	//Setting Function 8
	interface.SetListName("XPolynomial",8);
	interface.SetListHelp("insert value 'x into Polynomial",8);
	interface.SetFunc(CalPolynomial,8);

	interface.Start();


}

void NewPolynomial(){
	if(polynomial_size<=100){
		cin >> pl[polynomial_size];
		polynomial_size++;
	}
}

void ShowPolynomial(){
	int i=0;
	cout<<"\nAll PolynomialList:"<<endl;
	while(i<polynomial_size){
		cout<<"["<<i<<"]";
		cout<<pl[i];
		i++;
	}
}

void AddPolynomial(){
	ShowPolynomial();
	int x,y;
	Polynomial ans;
	cout<<"Select a polynomial:"<<endl;
	cin>>x;
	cout<<"Select a polynomial you want to add:"<<endl;
	cin>>y;
	if(x<polynomial_size && y<polynomial_size){
		ans = pl[x]+pl[y];
		cout<<"ans:"<<ans<<endl;
	}else{
		cout<<"Polynomial code invalid"<<endl;
	}
}

void SubPolynomial(){
	ShowPolynomial();
	int x,y;
	Polynomial ans;
	cout<<"Select a polynomial:"<<endl;
	cin>>x;
	cout<<"Select a polynomial you want to minus:"<<endl;
	cin>>y;
	if(x<polynomial_size && y<polynomial_size){
		ans = pl[x]-pl[y];
		cout<<"ans:"<<ans<<endl;
	}else{
		cout<<"Polynomial code invalid"<<endl;
	}
}

void MulPolynomial(){
	ShowPolynomial();
	int x,y;
	Polynomial ans;
	cout<<"Select a polynomial:"<<endl;
	cin>>x;
	cout<<"Select a polynomial you want to multiply:"<<endl;
	cin>>y;
	if(x<polynomial_size && y<polynomial_size){
		ans = pl[x]*pl[y];
		cout<<"ans:"<<ans<<endl;
	}else{
		cout<<"Polynomial code invalid"<<endl;
	}
}

void ComparePolynomial(){
	ShowPolynomial();
	int x,y;
	Polynomial ans;
	cout<<"Select a polynomial:"<<endl;
	cin>>x;
	cout<<"Select a polynomial you want to comepare:"<<endl;
	cin>>y;
	if(x<polynomial_size && y<polynomial_size){
		if(pl[x]==pl[y]){
			cout<<"Polynomial["<<x<<"]is equal with Polynomial ["<<y<<"]."<<endl;
		}else if(pl[x] > pl[y]){
			cout<<"Polynomial["<<x<<"]is longer with Polynomial ["<<y<<"]."<<endl;
		}else if(pl[x] < pl[y]){
			cout<<"Polynomial["<<x<<"]is shorter with Polynomial ["<<y<<"]."<<endl;
		}
	}else{
		cout<<"Polynomial code invalid"<<endl;
	}
}

void DevPolynomial(){
	ShowPolynomial();
	int x,y;
	Polynomial ans;
	cout<<"Select a polynomial to derivative:"<<endl;
	cin>>x;
	if(x<polynomial_size){
		ans = pl[x].Derivative();
		cout<<"ans:"<<ans<<endl;
	}else{
		cout<<"Polynomial code invalid"<<endl;
	}
}



void CalPolynomial(){
	ShowPolynomial();
	int x,y;
	int ans;
	cout<<"Select a polynomial:"<<endl;
	cin>>x;
	cout<<"Select the 'x' number you want to insert:"<<endl;
	cin>>y;
	if(x<polynomial_size ){
		ans = pl[x](y);
		cout<<"ans:"<<ans<<endl;
	}else{
		cout<<"Polynomial code invalid"<<endl;
	}
}