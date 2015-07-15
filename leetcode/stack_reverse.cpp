#include <iostream>
#include <stack>

using namespace std;

void insert_at_bottom(stack<int> &stk, int item){
	if(stk.empty()){
		stk.push(item);
	}
	else {
		int temp = stk.top();
		stk.pop();
		insert_at_bottom(stk,item);
		stk.push(temp);
	}
}

void reverse(stack<int> &stk){
	if(!stk.empty()){
		int temp = stk.top();
		stk.pop();
		reverse(stk);
		insert_at_bottom(stk,temp);
	}
}

// Driver Function
int main(){
	stack<int> stk;
	for(int i=0; i<4; i++) stk.push(i+1);
	reverse(stk);
	while(!stk.empty()){
		cout << stk.top() << " ";
		stk.pop();
	}
	cout << endl;
	return 0;
}
