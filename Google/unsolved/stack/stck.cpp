*
 * Using Functions to implement this.
 * reverse(4,3,2,1)
 *     |
 *     ----> 4 = reverse(3,2,1)
 *                  |
 *                  ----> 3 = reverse(2,1)
 *                              |
 *                              -----> 2 = reverse(1)
 *                                           |
 *                                           ----> 1 = reverse()
 *                                                       |
 *                                                       --> insert((), 1)
 *                                                             |
 *                                                             ---> stk = [1]
 *                                           |
 *                                           -----> insert([1],2)
 *                                           		  |
 *                                           		  ---> 1 = insert([],2)
 *                                           		                |
 *                                           		                ---> insert([2],1)
 *                                           		                          |
 *                                           		                          --> insert([2,1])
 *                             |
 *                             --> insert([2,1],3)
 *                             		|
 *                             		---> 1 = insert([1],3)
 *                             		            |
 *                             		            ---> 2 = insert([],3)
 *                             		                        |
 *                             		                        ---> insert([3,2,1])
 *                |
 * 		  ----> insert([3,2,1],4)
 * 		             |
 * 		             ---> 1 = insert([3,2],4)
 *   					  |
 *   					  ---> 2 = insert([3], 4)
 *   					              |
 *   					              -----> 3 = insert([], 4)
 *   					                       |
 *   					                       ---> insert([4,3,2,1]) (finally return it)
 */

#include <iostream>
#include <stack>

using namespace std;

void insert(stack<int> &stk, int item){
	if(stk.empty()){
		stk.push(item);
	}
	else {
		int temp = stk.top();
		stk.pop();
		insert(stk, item);
		stk.push(temp);
	}
}

void reverse(stack<int> &stk){
	if(!stk.empty()){
		int temp = stk.top();
		stk.pop();
		reverse(stk);
		insert(stk, temp);
	}
}

int main(){
	stack<int> stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);
	reverse(stk);
	while(!stk.empty()){
		cout << stk.top() << endl;
		stk.pop();
	}
	return 0;
}
