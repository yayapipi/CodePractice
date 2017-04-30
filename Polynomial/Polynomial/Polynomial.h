#ifndef _POLYNOMIAL_H_
#define  _POLYNOMIAL_H_

#include <iostream>
#include "CircularList.h"
using namespace std;

class Polynomial{
	private:
		CircularList cl;
	public:
		//Constructor & Destructor
		Polynomial(){	};
		Polynomial(const Polynomial &p):cl(p.cl){ };	//Copy Constructor
		~Polynomial(){ };

		//Friend Cin & Cout
		friend istream& operator>>(istream& in, Polynomial p){
			cout<<"Please Input As The Following Format:"<<endl;
			cout<<"C1E1 , C2E2 , C3E3 , ... , CmEm , 0 -1"<<endl;
			cout<<"*Enter Cm = 0 , Em = -1 To End The Input ."<<endl;
			
			int i =0;
			int array[100][2];
			while(i<100){
				array[i][0]=-2;
				array[i][0]=-2;
				i++;
			}
			i=0;
			while(array[i-1][0]!=0 && array[i-1][1]!= -1){
				cout<<"C"<<i+1<<":";
				in >>array[i][0];
				cout<<"E"<<i+1<<":";
				in >>array[i][1];
				i++;
			}
			
			cout<<"\nEnd Input"<<endl;
			cout<<"Your Input Polynomial List:"<<endl;
			int size = i;
			i=0;
			while(i<size-2){
				cout<<array[i][0]<<"x^"<<array[i][1]<<" + ";
				i++;
			}
			if(array[i][1]!=0){
				cout<<array[i][0]<<"x^"<<array[i][1]<<endl;
			}else{
				cout<<array[i][0]<<endl;
			}

			p.cl.Insert_Node(array,size);
			
			};
		friend ostream& operator<<(ostream& out,Polynomial &p){
			p.cl.Display();
		};

		//Set & Get Array Function
		void Set(const int *c,int size){
			int array[100][2];
			cl = cl.Clean();
			int i,j;
			i=j=0;
			while(j<size){
				array[i][0]=c[j];
				j++;
				array[i][1]=c[j];
				i++;
				j++;
			}
			cl.Insert_Node(array,i);
			return ;
		}

		void Get(int *c,int size){
			cl.Fill_Array(c);
			return;
		}

		//Derivative Function
		Polynomial Derivative(){
			Polynomial temp;
			temp.cl =cl;
			temp.cl.Derivative();
			return temp;
		};

		//Overload Operator Function

			//(Equal Polynomial (=))
			Polynomial &operator=(const Polynomial p){
				cl = p.cl;
				return *this;
			}

			Polynomial &operator=(const int n){
				return *this;
			}
	
			//(Add Polynomial (+))
			Polynomial operator+(const Polynomial &p){
				Polynomial temp;
				temp.cl = cl.Add(p.cl);
				return temp;
			}

			Polynomial operator+(const int &n){
				Polynomial temp;
				temp.cl = cl.AddInt(n);
				return temp;
			}

			friend Polynomial operator+(int n, Polynomial &p){
				Polynomial temp;
				temp.cl = p.cl.AddInt(n);
				return temp;
			}

			//(Substract Polynomial (-))
			Polynomial operator-(const Polynomial &p){
				Polynomial temp;
				temp.cl = cl.Sub(p.cl);
			//	cout<<temp;
				return temp;
			}

			Polynomial operator-(const int &n){
				Polynomial temp;
				temp.cl = cl.SubInt(n);
				return temp;
			}

			friend Polynomial operator-(int n, Polynomial &p){
				Polynomial temp;
				temp.cl = p.cl.SubInt(n);
				return temp;
			}

			//(Multiply Polynomial (*))

			friend Polynomial operator*(int n,Polynomial &p){
				Polynomial temp;
				temp.cl = p.cl.Mulint(n);
				return temp;
			}


			Polynomial operator*(const int n){
				Polynomial temp;
				temp.cl = cl.Mulint(n);
				return temp;
			}

			Polynomial operator*(const Polynomial &p){
				Polynomial temp;
				temp.cl = cl.Multpol(p.cl);
				return temp;
			}

			//(Add Assign Polynomial (+=))
			Polynomial operator+=(const Polynomial &p){
				cl = cl.Add(p.cl);				
				return *this;
			}

			Polynomial operator+=(const int &n){
				cl = cl.AddInt(n);				
				return *this;
			}
			//(Substract Assign Polynomial (-=))
			Polynomial operator-=(const Polynomial &p){
				cl = cl.Sub(p.cl);				
				return *this;
			}

			Polynomial operator-=(const int &n){
				cl = cl.SubInt(n);				
				return *this;
			}

			//(Multiply Assign Polynomial (*=))
			Polynomial operator*=(const Polynomial &p){
				cl = cl.Multpol(p.cl);				
				return *this;
			}

			Polynomial operator*=(const int n){
				cl = cl.Mulint(n);
				return *this;
			}

			//(Equal Polynomial Operator(==))
			bool operator==(const Polynomial &p){
				bool b;
				b = cl.eql(p.cl);
				return b;
			}

			//(Not Equal Polynomial Operator(!=))
			bool operator!=(const Polynomial &p){
				bool b;
				b = cl.eql(p.cl);
				if(b){
					return false;
				}else{
					return true;
				}
			}

			//(Insert int x Polynomial Operator())
			int operator()(const int &x){
				int ans =  cl.CalculateX(x);
				return ans;
			}

			//(Compare Polynomial Operator(>,<,>=,<=))
			bool operator>(const Polynomial &p){
				int ans =  cl.Compare(p.cl);
				if(ans>0){
					return true;
				}else{
					return false;
				}
			}
			bool operator>=(const Polynomial &p){
				int ans =  cl.Compare(p.cl);
				if(ans>=0){
					return true;
				}else{
					return false;
				}
			}
			bool operator<(const Polynomial &p){
				int ans =  cl.Compare(p.cl);
				if(ans<0){
					return true;
				}else{
					return false;
				}
			}
			bool operator<=(const Polynomial &p){
				int ans =  cl.Compare(p.cl);
				if(ans<=0){
					return true;
				}else{
					return false;
				}
			}

};

#endif