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