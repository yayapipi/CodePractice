#ifndef _CIRCULARLIST_H_
#define _CIRCULARLIST_H_

#include <iostream>
#include <cmath>
#include "Node.h"

using namespace std;

class CircularList{
	private:
		Node *first;
		Node *current;
		Node *new_node;
	public:
		//Constructor & Destructor
		CircularList(){
			first = new Node;
			current = NULL;
			new_node = NULL;
		};
		~CircularList(){};

		//Function Insert New Node
		void Insert_Node(int array[100][2],int size){
			int i=0;
			if(size<2){
				return ;
			}
			while(i<size){
				//Execute First Time
				if(current==NULL){
					if(array[i][0]!=0 && array[i][1]!=-1){
						current = new Node(array[i][0],array[i][1]); //Create A  New Node
						first->SetNext(*current);				//Linked The First Link To Current
					}else{
						first->SetNext(*first);				//Link To First Node When End
					}
				}else{
					//Execute After First Time
					if(array[i][0]!=0 && array[i][1]!=-1){
					new_node = new Node(array[i][0],array[i][1]);	//Create A New Node				
					current->SetNext(*new_node);				//Linked Current->next to this node
					current = new_node;						//Set Current To This Node
					}else{
						current->SetNext(*first);				//Link To First Node When End
					}
				}
				i++;
			}
		};

		//Function Display CircularList
		void  Display(){
			if(first->GetNext()!=NULL){
					current = first->GetNext();
			}
			else{
				cout<<"Nothing In This Polynomial List"<<endl;
				return ;		
			}
			//cout<<"\nPolynomial List:"<<endl;
			while( current->GetNext()!= first){
				//cout data
				if(current->Getc()!=0 && current->Gete()!=-1)
					if(current->Gete()!=0)
						cout<<current->Getc()<<"x^"<<current->Gete()<<" + ";
					else
						cout<<current->Getc()<<endl;

				//update next_node
				current = current->GetNext();
			}
			if(current->Getc()!=0 && current->Gete()!=-1)
				if(current->Gete()!=0)
					cout<<current->Getc()<<"x^"<<current->Gete()<<endl;
				else
					cout<<current->Getc()<<endl;
			return ;
		};

		//Derivative
		CircularList Derivative(){
			int dc;
			int de;
			current = first->GetNext();
			while( current!= first){
				//Derivative data
					dc = current->Getc();
					de = current->Gete();
					dc = dc * de;
					de = de-1;
					if(dc==0 && de ==-1){
						current->SetNext(*first);
						break;
					}
					current->Setc(dc);
					current->Sete(de);
				//update next_node
				current = current->GetNext();
			}
			return *this;
		};

		//Get And Set Node Variable
		Node *GetFirst(){ return  first;	};
		Node *GetCurrent(){ return  current;	};
		Node *GetNewNode(){ return  new_node;	};

		void SetCurrent(Node &n){ 
			current =  &n;
			return ;
		}
		void SetNewNode(Node &n){ 
			new_node = &n;
			return;
		};


//Polynomial Operator Calculate Function

	//Add Function
		CircularList Add(CircularList c){
			CircularList temp;
			Node *cfirst;
			Node *cCurrent;
			int array[100][2];
			int i =0;

			//Clean Array Data
			while(i<100){
				array[i][0]=-2;
				array[i][0]=-2;
				i++;
			}
			i=0;

			//Setting Initial Value
			if(first->GetNext()!=NULL){
			current = first->GetNext();
			}else{
				current = first;
			}

			cfirst = c.GetFirst();
			if(cfirst->GetNext()!=NULL){
			cCurrent = cfirst->GetNext();
			}else{
				cCurrent = cfirst;
			}

			while( current!= first && cCurrent!=cfirst){
				//Add data
					if(current->Gete() == cCurrent->Gete()){
						//adding data
						array[i][0] = current->Getc() + cCurrent->Getc();
						array[i][1] = current->Gete();

						//update next node
						current = current->GetNext();
						cCurrent = cCurrent->GetNext();
						i++;

					}else if(current->Gete() > cCurrent->Gete()){
						array[i][0] = current->Getc();
						array[i][1] = current->Gete();
						
						//update current next node
						current = current->GetNext();
						i++;
					}else{
						array[i][0] = cCurrent->Getc();
						array[i][1] = cCurrent->Gete();
						
						//update current next node
						cCurrent = cCurrent->GetNext();
						i++;
					}

			}
			//Insert Remain Polynomial
			if(current != first){
				while(current!=first){
					//input data
						array[i][0] = current->Getc() ;
						array[i][1] = current->Gete();

					//update data
						current = current->GetNext();
						i++;
				}
			}else if(cCurrent != cfirst){
				while(cCurrent!=cfirst){
					//input data
						array[i][0] = cCurrent->Getc() ;
						array[i][1] = cCurrent->Gete();

					//update data
						cCurrent = cCurrent->GetNext();
						i++;
				}
			}
			array[i][0] = 0;
			array[i][1] = -1;
			i++;
			temp.Insert_Node(array,i);
			return temp;

		}

		CircularList AddInt(const int n){
			Node *nod;
			//Setting Initial Value
			if(first->GetNext()!=NULL){
			current = first->GetNext();
			}else{
				current = first;
				nod = new Node(n,0);
				current->SetNext(*nod);
				nod->SetNext(*first);
				return *this;
			}

			while(current->GetNext()!=first){
				if(current->Gete()==0){
					current->Setc(current->Getc()+n);
					return *this;
				}
				current = current->GetNext();
			}

				if(current->Gete()==0){
					current->Setc(current->Getc()+n);
					return *this;
				}else{
					nod = new Node(n,0);
					current->SetNext(*nod);
					nod->SetNext(*first);
					return *this;
				}

		
		}
	
	//Substract Function
		CircularList Sub(CircularList c){
			CircularList temp;
			Node *cfirst;
			Node *cCurrent;
			int array[100][2];
			int i =0;

			//Clean Array Data
			while(i<100){
				array[i][0]=-2;
				array[i][0]=-2;
				i++;
			}
			i=0;

			//Setting Initial Value
			if(first->GetNext()!=NULL){
			current = first->GetNext();
			}else{
				current = first;
			}

			cfirst = c.GetFirst();
			if(cfirst->GetNext()!=NULL){
			cCurrent = cfirst->GetNext();
			}else{
				cCurrent = cfirst;
			}

			while( current!= first && cCurrent!=cfirst){
				//Substract data
					if(current->Gete() == cCurrent->Gete()){
						//substracting data
						if(current->Getc()>= cCurrent->Getc()){
						array[i][0] = current->Getc() - cCurrent->Getc();
						array[i][1] = current->Gete();
						}else{
						array[i][0] = cCurrent->Getc() - current->Getc();
						array[i][1] = current->Gete();
						}

						//update next node
						current = current->GetNext();
						cCurrent = cCurrent->GetNext();
						i++;

					}else if(current->Gete() > cCurrent->Gete()){
						array[i][0] = current->Getc();
						array[i][1] = current->Gete();
						
						//update current next node
						current = current->GetNext();
						i++;
					}else{
						array[i][0] = cCurrent->Getc();
						array[i][1] = cCurrent->Gete();
						
						//update current next node
						cCurrent = cCurrent->GetNext();
						i++;
					}

			}

			//Insert Remain Polynomial
			if(current != first){
				while(current!=first){
					//input data
						array[i][0] = current->Getc() ;
						array[i][1] = current->Gete();

					//update data
						current = current->GetNext();
						i++;
				}
			}else if(cCurrent != cfirst){
				while(cCurrent!=cfirst){
					//input data
						array[i][0] = cCurrent->Getc() ;
						array[i][1] = cCurrent->Gete();

					//update data
						cCurrent = cCurrent->GetNext();
						i++;
				}
			}

			array[i][0] = 0;
			array[i][1] = -1;
			i++;
			temp.Insert_Node(array,i);

			return temp;

		}

		CircularList SubInt(const int n){
			Node *nod;
			//Setting Initial Value
			if(first->GetNext()!=NULL){
			current = first->GetNext();
			}else{
				current = first;
				nod = new Node(-n,0);
				current->SetNext(*nod);
				nod->SetNext(*first);
				return *this;
			}

			while(current->GetNext()!=first){
				if(current->Gete()==0){
					current->Setc(abs(current->Getc()-n));
					return *this;
				}
				current = current->GetNext();
			}

				if(current->Gete()==0){
					current->Setc(abs(current->Getc()-n));
					return *this;
				}else{
					nod = new Node(-n,0);
					current->SetNext(*nod);
					nod->SetNext(*first);
					return *this;
				}

		
		}

	//Multiply Function
		CircularList Mulint(int n){
			CircularList temp;
			Node *cfirst;
			int array[100][2];
			int i =0;

			//Clean Array Data
			while(i<100){
				array[i][0]=-2;
				array[i][0]=-2;
				i++;
			}
			i=0;

			//Setting Initial Value
			if(first->GetNext()!=NULL){
			current = first->GetNext();
			}else{
				current = first;
			}

			while( current!= first){
				//Add data
				array[i][0] = current->Getc() * n;
				array[i][1] = current->Gete();

				//update next node
				current = current->GetNext();
				i++;

			}

			array[i][0] = 0;
			array[i][1] = -1;
			i++;
			temp.Insert_Node(array,i);
			return temp;
		}


		CircularList Multpol(CircularList c){

			//Data Declation
			CircularList temp;
			CircularList mul_array[100];
			Node *cfirst;
			Node *cCurrent;
			int array[100][2];
			int i =0;
			int j=0;

			//Clean Array Data
			while(j<100){
					array[j][0]=-2;
					array[j][1]=-2;
					j++;
				}


			//Setting Initial Value
			if(first->GetNext()!=NULL){
				current = first->GetNext();
			}else{
				return temp;
				current = first;
			}

			cfirst = c.GetFirst();
			if(cfirst->GetNext()!=NULL){
				cCurrent = cfirst->GetNext();

				if(cCurrent->Getc() == 0 && cCurrent->Gete() == -1){
					return *this;		//return if multiply a null polynomial
				}

			}else{
				return temp;
				cCurrent = cfirst;
			}

			//Multiply Algorithms
			i=j=0;
			while(cCurrent!=cfirst){
				j=0;
				if(first->GetNext()!=NULL){
					current = first->GetNext();
				}else{
					current = first;
				}
				while(current!=first){
					array[j][0] = current->Getc() * cCurrent->Getc();
					array[j][1] = current->Gete() + cCurrent->Gete();

					//update next current list
					j++;
					current = current->GetNext();
				}

				array[j][0] = 0;
				array[j][1] = -1;
				j++;
				mul_array[i] .Insert_Node(array,j);
				i++;
				cCurrent = cCurrent->GetNext();
			}

			//Adding All Multiply Value List
			for(j=0;j<i;j++){
				temp = temp.Add(mul_array[j]);
			}
	
			return temp;

		}

	//Equal Function
		bool eql(CircularList c){
			Node *cfirst;
			Node *cCurrent;
			int i =0;


			//Setting Initial Value
			if(first->GetNext()!=NULL){
			current = first->GetNext();
			}else{
				current = first;
			}

			cfirst = c.GetFirst();
			if(cfirst->GetNext()!=NULL){
			cCurrent = cfirst->GetNext();
			}else{
				cCurrent = cfirst;
			}

			while(current!=first && cCurrent!=cfirst){
				if(current->Getc()!=cCurrent->Getc() || current->Gete()!=cCurrent->Gete()){
					return false;
				}
				current =current->GetNext();
				cCurrent = cCurrent->GetNext();
			}
			return true;
		}

	//Equal Function
		int Compare(CircularList c){
			Node *cfirst;
			Node *cCurrent;
			int i ,j;

			//Setting Initial Value
			if(first->GetNext()!=NULL){
			current = first->GetNext();
			}else{
				current = first;
			}

			cfirst = c.GetFirst();
			if(cfirst->GetNext()!=NULL){
			cCurrent = cfirst->GetNext();
			}else{
				cCurrent = cfirst;
			}

			i=j=0;

			while(current!=first ){
				i++;
				current = current->GetNext();
			}
			while(cCurrent!=cfirst ){
				j++;
				cCurrent = cCurrent->GetNext();
			}
			if(i==j){
				return 0;
			}else if(i>j){
				return 1;
			}else{
				return -1;
			}
		}

	//Calculate int x function
		int CalculateX(int x){
			int xe,xc;
			int ans=0;
			//Setting Initial Value
			if(first->GetNext()!=NULL){
			current = first->GetNext();
			}else{
				current = first;
			}

			while(current!=first){
				xe = pow(x,current->Gete());
				xc = xe * current->Getc();
				ans += xc;
				current = current->GetNext();
			}
			return ans;
		}

	//Clean Node
		CircularList Clean(){
			CircularList reset;
			return reset;
		}	

	//Fill Array Node
		void Fill_Array(int *c){
			int i=0;
			//Setting Initial Value
			if(first->GetNext()!=NULL){
			current = first->GetNext();
			}else{
				current = first;
			}

			while(current!=first){
				c[i++] = current->Getc();
				c[i++] = current->Gete();
				current=current->GetNext();
			}	
			return ;		
		}
		
};

#endif