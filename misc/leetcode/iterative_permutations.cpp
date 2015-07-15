/*
Did not understood it well. should have to focus on it once again
http://www.quickperm.org/quickperm.php
*/
#define N    12   // number of elements to permute.  Let N > 2

void QuickPerm(void) {
   unsigned int a[N], p[N];
   register unsigned int i, j, tmp; // Upper Index i; Lower Index j

   for(i = 0; i < N; i++) {  // initialize arrays; a[N] can be any type
      a[i] = i + 1;   // a[i] value is not revealed and can be arbitrary
      p[i] = 0;       // p[i] == i controls iteration and index boundaries for i
   }
   //display(a, 0, 0);   // remove comment to display array a[]
   i = 1;   // setup first swap points to be 1 and 0 respectively (i & j)
   while(i < N) {
      if (p[i] < i) {
         j = i % 2 * p[i];   // IF i is odd then j = p[i] otherwise j = 0
         tmp = a[j];         // swap(a[j], a[i])
         a[j] = a[i];
         a[i] = tmp;
         //display(a, j, i); // remove comment to display target array a[]
         p[i]++;             // increase index "weight" for i by one
         i = 1;              // reset index i to 1 (assumed)
      } else {               // otherwise p[i] == i
         p[i] = 0;           // reset p[i] to zero
         i++;                // set new index value for i (increase by one)
      } // if (p[i] < i)
   } // while(i < N)
} //
