#include "TwoDigitNumber.hpp"

class ThreeDigitNumber:public TwoDigitNumber{
	protected:
		Number n1; //First Digit
		TwoDigitNumber n2; //Next 2-Digit
	public:
		//Constructor & Destructor
		ThreeDigitNumber(){}
		ThreeDigitNumber(const Number &a,const TwoDigitNumber &b):n1(a),n2(b){};
		~ThreeDigitNumber(){};

		//Function

	 	bool equals(ThreeDigitNumber &a){
			if( n1.getNumber() == a.n1.getNumber()){
				if(n2.equals(a.n2))
					return true;
				else
					return false;
			}else{
				return false;
			}
		}

		bool compare(ThreeDigitNumber &a){
			if(n1.getNumber() > a.n1.getNumber()){
				return true;
			}else if(n1.getNumber() == a.n1.getNumber()){
				if(n2.compare(a.n2)){
					return true;
				}else{return false;
				}
			}else{
				return false;
			}
		}

		std::string toString(){
			string number1;
			string number2;
			string number;
			number1 = n1.toString();
			number2 = n2.toString();
			number = number1 +number2;
			return number;
		}


};