//so here topics learnt:--
//1)sieve of erosthanese

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int casen;
    scanf("%d", &casen);
    while(casen--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        //cout<<"iam here"<<endl;
        int * primes = new int[m-n+1];
        for(int i=0;i<m-n+1;++i)
        primes[i] = 0;

        for(int p=2;p*p<=m;++p)
        {
            int less = n / p;
            less *= p; 

            for(int j=less;j<=m;j+=p) if(j != p && j >= n)
            primes[j - n] = 1;
        }

        for(int i=0;i<m-n+1;++i)
        {
            if(primes[i] == 0 && n+i != 1) 
            printf("%d\n",n+i);
        }

        if(casen)
          printf("\n");
        //cout<<"iam here"<<endl;
        delete [] primes;
    }
}
