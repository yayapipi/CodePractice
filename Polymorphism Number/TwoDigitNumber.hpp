#include "Number.hpp"

class TwoDigitNumber:public Number{
	protected:
		Number n1; //First Digit
		Number n2; //Second Digit
	public:
		//Constructor & Destructor
		TwoDigitNumber(){}
		TwoDigitNumber(const Number &a,const Number &b):n1(a),n2(b){};
		~TwoDigitNumber(){};

		//Function

	virtual	bool equals(TwoDigitNumber &a){
			if( n1.getNumber() == a.n1.getNumber() && n2.getNumber() == a.n2.getNumber()){
				return true;
			}else{
				return false;
			}
		}

	virtual bool compare(TwoDigitNumber &a){
			if(n1.getNumber() > a.n1.getNumber()){
				return true;
			}else if(n1.getNumber() == a.n1.getNumber()){
				if(n2.getNumber() > a.n2.getNumber()){
					return true;
				}else{return false;
				}
			}else{
				return false;
			}
		}

	virtual	std::string toString(){
			string number1;
			string number2;
			string number;
			number1 = n1.getNumber() + '0';
			number2 = n2.getNumber() + '0';
			number = number1 +number2;
			return number;
		}


};