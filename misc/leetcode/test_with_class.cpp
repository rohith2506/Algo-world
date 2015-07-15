#include<iostream>
using namespace std;
 
int main()
{
   int x = NULL;
   int *ptr = &x;
   cout<<*ptr<<endl;
   //int &*ptr1 = ptr;
   return 0;
}