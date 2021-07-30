#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

vector<double> runningMedian(vector<int> a) {

    vector<double> d;
    priority_queue <int> maxHeap;
    priority_queue <int> minHeap;
    int l = a.size(),n=0;
    for(int i=0;i<l;++i){
        n = a[i];
        if (maxHeap.empty())maxHeap.push(n);
        else if(maxHeap.size() == minHeap.size()){
            
            if(n < minHeap.top())maxHeap.push(n);
            else{
                minHeap.push(n);
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        } 
        else if(maxHeap.size() > minHeap.size()){
            if(n > maxHeap.top())minHeap.push(n);
            else{
                maxHeap.push(n);
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        
        if (maxHeap.empty())d.push_back(0);
        else if(maxHeap.size() == minHeap.size()) {
            d.push_back( (maxHeap.top() + minHeap.top()) / 2.0);
        } else { // maxHeap must have more elements than minHeap
            d.push_back(maxHeap.top());
        }
    }
    return d;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

