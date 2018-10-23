#include<iostream>
#include<stack>
#include<string>

using namespace std;

void InfixToPostfix(string s) {
	stack<char> exp;
	string post;

	for (unsigned int i = 0; i < s.length(); i++) {
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] <= 'A' && s[i] >= 'Z')) {
			post += s[i];									//Add to output string if
		}													//scanned char is a propositional atom
		
		else if (s[i] == '(') {
			exp.push('(');
		}

		else if (s[i] == ')') {
			while (!exp.empty() && exp.top() != '(') {
				post += exp.top();							//Pop and put into output string
				exp.pop();									//until '(' is on top of the stack.
			}
			if (exp.top() == '(') { exp.top(); }
		}
		
		else {
			while (!exp.empty() && (exp.top() != '~' || exp.top() != '^' || exp.top() != 'V' || exp.top() != '>')) {
				post += exp.top();								//if ~, ^, V or > are scanned
				exp.pop();										//pop stack and 
			}
			exp.push(s[i]);
		}
	}

	while (!exp.empty()) {					
		post += exp.top();
		exp.pop();
	}
	cout << post << endl;
}
int main()
{
	//Driver code. ignore this.
	string exp = "(~b)^a";
	InfixToPostfix(exp);
	system("pause");
	return 0;
}