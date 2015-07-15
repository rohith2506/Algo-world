/*

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n,k;
		cin >> n >>k;
		vector<int> inp(n);
		for(int i=0;i<n;i++) cin >> inp[i];
		int cnt = k;

	}
}

*/

#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node
{   
    int key;
    node* prev;
    node* next;
}node;

node* createNode(int x)
{
    node *temp = new node;
    temp->key = x;
    temp->next = temp->prev = NULL;
    return temp;
}

node* createList(node* head, int n)
{
   int x;
   node * last;
   for(int i = 0; i<n ;i++)
   {
       cin>>x;
       if(head == NULL)
       {
           head = createNode(x);
           last = head;
       }
       else
       {
           last->next = createNode(x);
           last->next->prev = last;
           last = last->next;
       }
   }
   return head;
}

void deleteNode(node* p)
{
   p->next->prev = p->prev;

   if(p->prev)
      p->prev->next = p->next;
}

node* deleteFromBack(node *p, int cnt)
{

	cout << cnt << endl;
    while(cnt)
    {
        p = p->prev;
        cnt--;
    }
    p->next = NULL;
    return p;
}

node* deleteList(node* head, int k, int n)
{
   node* p1, *p2;
   int cnt =k;

   p1 = head;
   p2 = p1->next;

   while(p2 && cnt)
   {
       if((p1->key < p2->key) && p1)
       {
        deleteNode(p1);
        if(p2->prev)
        p1 = p2->prev;
        else
        {
            p1 = p2;
            p2 = p2->next;
        }
        cnt--;
       }
       else{
        p1 = p2;
        p2 = p2->next;
       }
   }

   cout << p1 -> key << endl;

   if(cnt )
       p1 = deleteFromBack(p1, cnt);

   cout << p1 -> key << endl;

   while(p1 && p1->prev)
       p1 = p1->prev;

   return p1;
 }

int main()
{
    int t, n, k, i;
    node* head =NULL;
    cin>>t;

    while(t--){
        cin>>n>>k;
        head =NULL;
        head= createList(head, n);

        if(n==1)
        {
           cout<<head->key<<endl;
           continue;
         }

         head  = deleteList(head, k, n);

         while(head)
         {
            cout<<head->key<<" ";
            head = head->next;
          }
          cout<<endl;
     }

     return 0;
 }