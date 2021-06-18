/* C++ implementation to convert
infix expression to postfix*/

#include<stack>
#include<iostream>
#include<algorithm>

using namespace std;

//Function to return precedence of operators
int precedence(char c){
	if(c=='^')return 3;
	else if(c == '*' || c== '/')return 2;
	else if(c == '+' || c=='-')return 1;
	return -1;
}

// The main function to convert infix expression
//to postfix expression
string infixToPostfix(string s){
	
	stack<char> st;
	string result;
	int n = s.length();
	char ch;
	
	for(int i=0;i<n;++i){
		ch = s[i];
		// If the scanned character is
        // an operand, add it to output string.
		if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9') )result+=ch;
		// If the scanned character is an
        // ‘(‘, push it to the stack.
		else if(ch=='(')st.push('(');
		// If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
		else if(ch==')'){
			while(!st.empty() && st.top() != '('){
					char temp = st.top();
					st.pop();
					result+=temp;
			}
			st.pop();
		}
		//If an operator is scanned
		else{
			while(!st.empty() && precedence(ch)<=precedence(st.top())){
				char temp = st.top();
				st.pop();
				result+=temp;
			}
			st.push(ch);
		}
	}
	// Pop all the remaining elements from the stack
    while(!st.empty()) {
        char temp = st.top();
        st.pop();
        result += temp;
    }
  
    return result;
}

// The main function to convert infix expression
//to prefix expression
string infixToPrefix(string s){
	reverse(s.begin(),s.end());
	int n = s.length(),i=0;
	for(i=0;i<n;++i){
		if(s[i]=='(')s[i]=')';
		else if(s[i]==')')s[i]='(';
	}
	s = infixToPostfix(s);
	reverse(s.begin(),s.end());
	return s;
}
// function to check if brackets are balanced
bool BalancedBrackets(string s){
	stack<char> st;
	int n = s.length();
	for(int i=0;i<n;++i){
		if(s[i]=='(' || s[i]=='{' || s[i]=='[')st.push(s[i]);
		else{
			if(s[i]==')' && !st.empty() && st.top()=='(')st.pop();
			else if(s[i]=='}' && !st.empty() && st.top()=='{')st.pop();
			else if(s[i]==']' && !st.empty() && st.top()=='[')st.pop();
			else return false;
		}
	}
	return true;
}

// The main function that returns value of a given postfix expression
int evaluatePostfix(){
	int result = 0;
	
	return result;
}

int main(){
	string expression = "2+3*(9^4-6)^(7+9*1)-5";
    cout<<infixToPostfix(expression)<<"\n";
	cout<<infixToPrefix(expression)<<"\n";
	cout<<( BalancedBrackets("{()}]") ? "True" : "False");
    return 0;
}

