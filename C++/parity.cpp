//============================================================================
// Name        : parity.cpp
// Author      : SidPro
// Version     : 1.0
// Description : Two-dimensional Parity check
/*

=>	Parity check bits are calculated for each row, which is equivalent to a 
	simple parity check bit. Parity check bits are also calculated for all columns, 
	then both are sent along with the data. At the receiving end these are compared 
	with the parity bits calculated on the received data.

=>	https://www.geeksforgeeks.org/error-detection-in-computer-networks/
*/
//============================================================================


/* input - output format
 *
 * Enter input stream: 0001110110111100110110100
   Enter number of columns: 5
Row parity:  0 1 0 1 0
column parity:  1 0 0 1 0
0001110110111100110110100100100

No Error
 */
#include <iostream>
#include<tuple>
using namespace std;
// 0001110110111100110110100
tuple<string,int> sender();
void receiver(string,int);

int main(){
	string s;
	int col=0;
	tie(s,col) = sender();
	if(s!=""&&col!=0)
		receiver(s,col);
	return 0;
}
tuple<string,int> sender(){
		int col,i,j,track=-1,len,count;
		bool check = false;
		char parity,ch1;
		string s;
		cout<<"Enter input stream: ";
		cin>>s;
		len = s.length();
		cout<<"Enter number of columns: ";
		cin>>col;
		char column[col];
		char row[len/col];
		if(len%col == 0)check = true;
		if(check){
	//-------------- Row parity --------->

			for(i=0;i<len;++i){
				if(i%col==0 && i>0){
					if(count%2==0)
						row[track] = '0';
					else
						row[track] = '1';
				}
				if(i%col==0){
					++track;
					count=0;
				}
				if(s[i]=='1')count++;
			}
			if(count%2)row[track] = '1';
			else row[track] = '0';
	//---------------------column Parity------------------->
			track = col;
			for(i=0;i<track;++i){
				count=0;
				if(s[i]=='1')++count;
				for(j=i+track;j<len;j=j+track){
					if(s[j]=='1')++count;
				}
				if(count%2==0)column[i]='0';
				else column[i]='1';
			}
	//------------------Parity Bit-------------------->
			count=0;
			track=0;
			for(i=0;i<col;++i){
				if(column[i]=='1')++track;
			}
			for(i=0;i<len/col;++i){
				if(row[i]=='1')++count;
			}
			if(count%2==0)ch1='0';
			else ch1='1';
			if(track%2==0)parity='0';
			else parity='1';

			if(ch1==parity)parity=ch1;
			else cout<<"message is not clear"<<endl;
	//----------------------print everything-------------->
			cout<<"Row parity: ";
			for(i=0;i<len/col;++i){
				cout<<" "<<row[i];
			}
			cout<<endl;
			cout<<"column parity: ";
			for(i=0;i<col;++i){
				cout<<" "<<column[i];
				s = s+column[i];
			}
			s = s + parity;
			cout<<"\n"<<s<<endl;

		}
	//-------------------------------------------
		else
			cout<<"Please check your input steam and column inputs Best Regards!!!";
	return make_tuple(s,col);
}
void receiver(string s,int col){
	string parity = s.substr(s.length()-(col + 1));
	string s2 = s.substr(0,(s.length()-(col + 1)));
//	cout<<parity<<endl;
//	cout<<s2<<endl;
	int len = s2.length();
	int i,j,track=-1,count;
	char column[col],row[len/col],p1,p2;
	bool pass1 = true;

	track = col;
	for(i=0;i<track;++i){
		count=0;
		if(s[i]=='1')++count;
		for(j=i+track;j<len;j=j+track){
			if(s[j]=='1')++count;
		}
		if(count%2==0)column[i]='0';
		else column[i]='1';
	}


	for(i=0;i<col;++i){
		if(parity[i]!=column[i])pass1=false;
	}

	cout<<"\n";
	if(pass1){
		track=-1;
		for(i=0;i<len;++i){
				if(i%col==0 && i>0){
					if(count%2==0)
						row[track] = '0';
					else
						row[track] = '1';
				}
				if(i%col==0){
					++track;
					count=0;
				}
				if(s[i]=='1')count++;
			}
			if(count%2)row[track] = '1';
			else row[track] = '0';
		count=0;
		track=0;
		for(i=0;i<col;++i){
			if(column[i]=='1')++track;
		}
		for(i=0;i<len/col;++i){
			if(row[i]=='1')++count;
		}

		if(count%2==0)p1='0';
		else p1='1';
		if(track%2==0)p2='0';
		else p2='1';

		if(p1==parity[parity.length() - 1] && p2==parity[parity.length() - 1])
			cout<<"No Error";
		else
			cout<<"Error";
	}
	else{
		cout<<"message is courrepeted";
	}
}
