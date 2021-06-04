#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
 
 bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
	 return (a.second < b.second);
 }
// Prints a maximum set of activities that can be done by a single
// person, one at a time.
//  n   -->  Total number of activities
//  s[] -->  An array that contains start time of all activities
//  f[] -->  An array that contains finish time of all activities
void printMaxActivites(vector<pair<int,int>> v,int n){
	sort(v.begin(),v.end(),sortbysec);
	int i=0;
	cout<<"Following activities are selected \n";
	cout << "(" << v[i].first << ", " << v[i].second << "), ";
	// If this activity has start time greater than or
    // equal to the finish time of previously selected
    // activity, then select it
	for(int j=1;j<n;++j){
		if(v[i].second <= v[j].first){
			cout << "(" << v[j].first << ", " << v[j].second << "), ";
			i=j;
		}
	}
}
 
 
// driver program to test above function
int main(){
	int start[] = {1,3,0,5,8,5};
	int end[] = {2,4,6,7,9,9};
	int n = sizeof(start)/sizeof(start[0]);
	
	vector<pair<int,int>> v;
	for(int i=0;i<n;++i)
			v.push_back(make_pair(start[i],end[i]));
	
	printMaxActivites(v,n);
	
	
    return 0;
}