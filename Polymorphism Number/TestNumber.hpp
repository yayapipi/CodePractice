#include "ThreeDigitNumber.hpp"
#include <time.h>
#include <typeinfo> 

class TestNumber{
	private:
	public:
		Number getFirstDigit(int n){
			char s[3];int digit;
			if(n>-10&&n<10){
				Number a(n);
				return a;
			}else{
				sprintf(s, "%d", n);
				digit = s[0]-'0';
				Number a(digit);
				return a;
			}
		}

		Number getSecondDigit(int n){
			char s[3];int digit;
			if(n>-10&&n<10){
				Number a(n);
				return a;
			}else{
				sprintf(s, "%d", n);
				digit = s[1]-'0';
				Number a(digit);
				return a;
			}
		}

		Number getLastDigit(int n){
			char s[3];int digit;
			if(n>-10&&n<10){
				Number a(n);
				return a;
			}else if(n>-100&&n<100){
				sprintf(s, "%d", n);
				digit = s[1]-'0';
				Number a(digit);
				return a;
			}else{
				sprintf(s, "%d", n);
				digit = s[2]-'0';
				Number a(digit);
				return a;
			}
		}


		Number **genNum(){
			Number **num = new Number *[100];	//New The Pointer Array of pointer
			int digit[100];		//Generate Random Number

			srand(1);

			//Generate Number
			for(int i=0;i<100;i++){
				digit[i] = rand()%1000;

				if(digit[i]<10){
					num[i] = new Number(digit[i]);
				//	cout<<"num["<<i<<"]:"<<(*num[i]).toString()<<endl;
				}else if(digit[i]>=10 && digit[i]<100){
					Number a1 = getFirstDigit(digit[i]);
					Number a2 = getSecondDigit(digit[i]);
					num[i] = new TwoDigitNumber(a1,a2);
				//	cout<<"num["<<i<<"]:"<<(*num[i]).toString()<<endl;
				}else{
					Number d1 = getFirstDigit(digit[i]);
					Number d2 = getSecondDigit(digit[i]);
					Number d3 = getLastDigit(digit[i]);
					TwoDigitNumber t2(d2,d3);
					num[i] = new ThreeDigitNumber(d1,t2);
				//	cout<<"num["<<i<<"]:"<<(*num[i]).toString()<<endl;
				}
			}

			/*Some Address Information
				for(int i=0;i<100;i++){
				cout<<"num["<<i<<"]:"<<(num[i])<<endl;
				}
				getchar();
	
				cout<<"*num:"<<*num<<endl;
				cout<<"(*num):"<<(*num)<<endl;
				cout<<"*(num):"<<*(num)<<endl;
	
				for(int i=0;i<100;i++){
				cout<<"\n**num:"<<(*(num+i))->toString()<<endl;
				}
				getchar();


				cout<<"*num[0]:segmentation failed"<<endl;
				*/

			return num;
		}




	static	std::string printAvg(Number **num){
			int ans,count;
			string stringAvg;
			string ans_string;
			char avg[10];
			ans = count = 0;

			for(int i=0;i<100;i++){
				try{
					//Dynamic_Cast To Test The Class Type
       				 ThreeDigitNumber t3 = dynamic_cast<ThreeDigitNumber&>((*num[i]));
       				 ans_string = (*num[i]).toString();
       				 ans += atoi(ans_string.c_str());
      				 count++;
     			   }catch(bad_cast){}
     		}

			ans /= count;
			sprintf(avg,"%d",ans);
			stringAvg = avg;
			//cout<<stringAvg;
			return stringAvg;
		}




};