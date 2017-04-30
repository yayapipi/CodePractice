#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
using namespace std;

class Node{
	private:
		int c;
		int e;
		Node * next;
	public:

		//Constructor & Destructor
		Node(){
			c = 0;
			e = -1;
			next = NULL;
		};

		Node(int a , int  b):c(a),e(b){
			next = NULL;
		}
		~Node(){};

		//Function Setting
		void SetNext(Node &destination_Node){
			next = &destination_Node;
			return ;
		}
		int Setc(int a) {c = a;};
		int Sete(int b) {e = b;};

		//GetData
		Node *GetNext(){ return  next;};
		int Getc() const{return c;};
		int Gete() const{return e;};



};

#endif