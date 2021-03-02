#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <string>
#include <fstream>
#include <utility>
#include <algorithm>
#include <sstream>
using namespace std;

// this structure is for storing L3:{I1,I2,I3 => sup}
struct four{
    int I1,I2,I3,sup;
};

float found2(int a,int b,vector<pair<int,pair<int,int>>> L2){
    int length = L2.size();
    for(int i=0;i<length;++i){
        if(L2[i].second.first == a && L2[i].second.second == b )
            return (float)L2[i].first;
    }
    return 0;
}
float found1(int a,vector<pair<int,int>> L1){
    int length = L1.size();
    for(int i=0;i<length;++i){
        if(L1[i].first == a)
            return (float)L1[i].second;
    }
    return 0;
}


int main(){
    int TD=0,i=0,j,length;
    int Min_sup;
    string line,s;
    // store unique items
    set<int> item;

    /* Input format
    first Total number of Transaction: TD
    second Minimum support
    then next TD lines with space separated Items
    */
    ifstream Tfile("T4.txt");
    if(!(Tfile.is_open())){
        cout<<"Unable to open";
        exit(1);
    }
    getline(Tfile,line);
    TD = stoi(line);
    // 2D vector to store transaction with items
    vector<int> v[TD];

    getline(Tfile,line);
    Min_sup = stoi(line);
    while(getline(Tfile,line)){
        stringstream ss(line);
        while(ss>>s){
            v[i].push_back((stoi(s)));
            item.insert(stoi(s));
        }
        ++i;
    }
    Tfile.close();

//============================ THE APRIORI ================================//
    // Frequent item set L1
    vector<pair<int,int>> L1;
    for(auto it=item.cbegin(); it != item.cend(); ++it){
        int item_count = 0;
       for(i=0;i<TD;++i){
            // find check only once
            if(find(v[i].begin(),v[i].end(),*it) != v[i].end())
                ++item_count;
       }
        if(item_count>=Min_sup)
            L1.push_back(make_pair(*it,item_count));
    }
    // free memory of set
    item.clear();

    // Frequent item set L2
    vector<pair<int,pair<int,int>>> L2;
    length = L1.size();
    for(i=0;i<length-1;++i){
        for(j=i+1;j<length;++j){
            int item_count=0;
            for(int k=0;k<TD;++k){
                if(find(v[k].begin(),v[k].end(),L1[i].first) != v[k].end() &&
                   find(v[k].begin(),v[k].end(),L1[j].first) != v[k].end() )
                    ++item_count;
            }
            if(item_count>=Min_sup)
                L2.push_back(make_pair(item_count,make_pair(L1[i].first,L1[j].first)));
        }
    }

    // Frequent item set L3
    vector<four> L3;
    vector<string> check2;
    length = L2.size();
    for(i=0;i<length-1;++i){
        for(j=i+1;j<length;++j){
            if(L2[i].second.first==L2[j].second.first ||
               L2[i].second.second==L2[j].second.second ||
               L2[i].second.second==L2[j].second.first){
                    set<int> check1;
                    check1.insert(L2[i].second.first);
                    check1.insert(L2[i].second.second);
                    check1.insert(L2[j].second.first);
                    check1.insert(L2[j].second.second);
                    string gs = "";
                    for(auto it=check1.cbegin(); it != check1.cend(); ++it){
                         gs += to_string(*it);
                    }
                    if(!(find(check2.begin(),check2.end(),gs) != check2.end())){
                            check2.push_back(gs);

                            int item_count=0;
                            for(int k=0;k<TD;++k){
                                if(find(v[k].begin(),v[k].end(),(gs[0]-'0')) != v[k].end() &&
                                   find(v[k].begin(),v[k].end(),(gs[1]-'0')) != v[k].end() &&
                                   find(v[k].begin(),v[k].end(),(gs[2]-'0')) != v[k].end())
                                    ++item_count;
                            }
                            if(item_count>=Min_sup)
                                L3.push_back({(gs[0]-'0'),(gs[1]-'0'),(gs[2]-'0'),item_count});
                    }
            }
        }
    }
//============================ PRINT EVERYTHING ================================//
    // PRINT Transactions
    cout<<"Transactions: \n";
    for(i=0;i<TD;++i){
            length=v[i].size();
        for(j=0;j<length;++j){
            cout<<"I"<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\nMinimum Support: "<<Min_sup<<"\n";
    // PRINT L1
    cout<<"\nFrequent item set L1:\n";
    length = L1.size();
    for(i=0;i<length;++i)
        cout<<"I"<<L1[i].first<<" "<<L1[i].second<<"\n";

    // PRINT L2
    if(L2.size()>0){
        cout<<"\nFrequent item set L2:\n";
        length = L2.size();
        for(i=0;i<length;++i){
            cout<<"{I"<<L2[i].second.first<<", I"<<L2[i].second.second<<"} "<<L2[i].first<<"\n";
        }
        if(L3.size()<1){
            cout<<"\nSo rules can be:\n";
            for(i=0;i<length;++i){
                cout<<"I"<<L2[i].second.first<<" => I"<<L2[i].second.second<<"  "<<( ((float)L2[i].first/found1(L2[i].second.first,L1))*100 )<<" %\n";
                cout<<"I"<<L2[i].second.second<<" => I"<<L2[i].second.first<<"  "<<( ((float)L2[i].first/found1(L2[i].second.second,L1))*100 )<<" %\n";
            }
        }
    }

    // PRINT L3
    if(L3.size()>0){
        cout<<"\nFrequent item set L3:\n";
        length = L3.size();
        for(i=0;i<length;++i){
            cout<<"{I"<<L3[i].I1<<",I"<<L3[i].I2<<",I"<<L3[i].I3<<"} "<<L3[i].sup<<"\n";
        }
        cout<<"\nSo rules can be:\n";
        for(i=0;i<length;++i){
            cout<<"I"<<L3[i].I1<<",I"<<L3[i].I2<<" => I"<<L3[i].I3<<"   "<<( ((float)L3[i].sup/found2(L3[i].I1,L3[i].I2,L2))* 100.0 )<<" %\n";
            cout<<"I"<<L3[i].I1<<",I"<<L3[i].I3<<" => I"<<L3[i].I2<<"   "<<( ((float)L3[i].sup/found2(L3[i].I1,L3[i].I3,L2))* 100.0 )<<" %\n";
            cout<<"I"<<L3[i].I2<<",I"<<L3[i].I3<<" => I"<<L3[i].I1<<"   "<<( ((float)L3[i].sup/found2(L3[i].I2,L3[i].I3,L2))* 100.0 )<<" %\n";
            cout<<"I"<<L3[i].I1<<" => I"<<L3[i].I2<<",I"<<L3[i].I3<<"   "<<( ((float)L3[i].sup/found1(L3[i].I1,L1))* 100.0 )<<" %\n";
            cout<<"I"<<L3[i].I2<<" => I"<<L3[i].I1<<",I"<<L3[i].I3<<"   "<<( ((float)L3[i].sup/found1(L3[i].I2,L1))* 100.0 )<<" %\n";
            cout<<"I"<<L3[i].I3<<" => I"<<L3[i].I1<<",I"<<L3[i].I2<<"   "<<( ((float)L3[i].sup/found1(L3[i].I3,L1))* 100.0 )<<" %\n";
            cout<<"\n";
        }
    }
    return 0;
}
    /*
    cout<<"Enter Number of Transaction: ";
    cin>>TD;
    cout<<"Enter Minimum Support: ";
    cin>>Min_sup;
    getline(cin,wow);

    // Get the all space separated Items from Terminal

    for(i=0;i<TD;++i){
        cout<<"Enter space separated Items: ";
        string line,s;

        getline(cin,line);
        stringstream ss(line);

        while(getline(ss,s,' ')){
            v[i].push_back((stoi(s)));
            item.insert(stoi(s));
        }
    } */
