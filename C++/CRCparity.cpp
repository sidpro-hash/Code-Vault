//============================================================================
// Name        : CRCparity.cpp
// Author      : SidPro
// Version     : 1.0
// Description : 
/*
=> 	cyclic redundancy check (CRC), which is used in networks such as LANs and WANs.

=> 	cyclic codes have a very good performance in detecting single-bit
	errors, double errors, an odd number of errors, and burst errors. They can easily be
	implemented in hardware and software. They are especially fast when implemented in
	hardware. This has made cyclic codes a good candidate for many networks.

=> https://en.wikipedia.org/wiki/Cyclic_redundancy_check

*/
//============================================================================



/* input - output format
 *
 * Enter Data to generate CRC: 110100101
   Enter Key: 1101

CRC code: 110100101110
 0 0 0
 */

#include <iostream>
#include <string>
#include <tuple>
using namespace std;

tuple<string,string> sender(string,string);
void receiver(string,string);

int main() {
	string keys,data;
	cout<<"Enter Data to generate CRC: ";
	cin>>data;
	cout<<"Enter Key: ";
	cin>>keys;
	tie(data,keys) = sender(data,keys);
	receiver(data,keys);
	return 0;
}

tuple<string,string> sender(string data,string keys){
	int lOfKey = keys.length(),i,j;
	int lOfData = data.length();
	int range = lOfData+lOfKey-1;
	char operation[range],temp[lOfKey];

	data.copy(operation,lOfData,0);
	for(i=lOfData;i<range+1;++i)operation[i] = '0';
//	for(i=0;i<range;++i)cout<<operation[i];

	for(j=0;j<lOfKey;++j){
		temp[j] = operation[j];
	}
	for(i=0;i<lOfData;++i){
		if(temp[0]=='1'){
			for(j=0;j<lOfKey;++j){
				if((temp[j]=='0'&&keys[j]=='0')||(temp[j]=='1'&&keys[j]=='1')){
					temp[j] = '0';
				}
				else
					temp[j] = '1';
			}
			for(j=0;j<lOfKey-1;++j){
				temp[j] = temp[j+1];
			}
			temp[j] = operation[i+lOfKey];
		}
		else{
			for(j=0;j<lOfKey;++j){
				if(temp[j]=='1'){
					temp[j] = '1';
				}
				else
					temp[j] = '0';
			}
			for(j=0;j<lOfKey-1;++j){
				temp[j] = temp[j+1];
			}
			temp[j] = operation[i+lOfKey];
		}
//		cout<<"\n"<<i<<" ";
//		for(j=0;j<lOfKey;++j)cout<<temp[j];
	}
	for(j=0;j<lOfKey-1;++j){
		data = data+temp[j];
	}
	cout<<"\n"<<"CRC code: "<<data;
	return make_tuple(data,keys);
}
void receiver(string data,string keys){
	int lOfKey = keys.length(),i,j;
	int lOfData = data.length();
	char operation[lOfData],temp[lOfKey];

	data.copy(operation,lOfData,0);
//	for(i=0;i<lOfData;++i)cout<<operation[i];

	for(j=0;j<lOfKey;++j){
		temp[j] = operation[j];
	}
	for(i=0;i<lOfData-lOfKey+1;++i){
		if(temp[0]=='1'){
			for(j=0;j<lOfKey;++j){
				if((temp[j]=='0'&&keys[j]=='0')||(temp[j]=='1'&&keys[j]=='1')){
					temp[j] = '0';
				}
				else
					temp[j] = '1';
			}
			for(j=0;j<lOfKey-1;++j){
				temp[j] = temp[j+1];
			}
			temp[j] = operation[i+lOfKey];
		}
		else{
			for(j=0;j<lOfKey;++j){
				if(temp[j]=='1'){
					temp[j] = '1';
				}
				else
					temp[j] = '0';
			}
			for(j=0;j<lOfKey-1;++j){
				temp[j] = temp[j+1];
			}
			temp[j] = operation[i+lOfKey];
		}
//		cout<<"\n"<<i<<" ";
//		for(j=0;j<lOfKey;++j)cout<<temp[j];
	}
	cout<<"\n";
	for(j=0;j<lOfKey-1;++j){
		cout<<" "<<temp[j];
	}
}
