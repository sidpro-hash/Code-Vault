// Sample code to perform I/O:

#include <iostream>
#include <queue>
using namespace std;

class Stack{
    queue<int> q1,q2;
    int curr_size;
    
    public:
        Stack(){
            curr_size=0;
        }
        void push(int val){
            curr_size+=1;
             // Push val first in empty q2
            q2.push(val);
            // Push all the remaining
            // elements in q1 to q2.
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            // swap the names of two queues
            queue<int> q = q1;
            q1 = q2;
            q2 = q1;
        }
        void pop(){
            if(q1.empty())return;
            q1.pop();
            curr_size-=1;
        }
        int top(){
            if(q1.empty())return -1;
            return q1.front();
        }
        int size(){
            return curr_size;
        }
};

int main() {
	Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
  
    cout << "current size: " << s.size()
         << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
  
    cout << "current size: " << s.size()
         << endl;
    return 0;
}