/*
Dp - O(n**2) solution and O(n) solution both pass
@Author: Rohit
*/

class JumpGame{
Public:
	bool CanJump(int A[], int n){
		if (n == 1) return true;
		if ( !A[0] ) return false;
		for(int i=1; i!=n-1; i++){
			A[i] = std::max(A[i-1]-1,A[i]);
			if(!A[i]) return false;
		}
		return true;
	}
}
