#include "TestNumber.hpp"

int main(){
	TestNumber t1;
	Number **num = t1.genNum();
	cout<<"Generate Number: "<<endl;
	for(int i=0;i<100;i++){
		cout<<(*num[i]).toString()<<" ";
	}
	cout<<"\n\nAverage Number Of 'ThreeDigitNumber' : ";
	string avg = t1.printAvg(num); 
	cout<<avg<<endl;
}