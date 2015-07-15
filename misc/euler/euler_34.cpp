#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int factorial(int x) {
    if (x == 0) {
        return 1;
    }
    int y = x;
    for (int i = 1; i < x; i++) {
        y *= i;
    }
    return y;
}

int go(){
int result = 0;
for (int i = 10; i < 2540161; i++) {
    int sumOfFacts = 0;
    int number = i;
    while (number > 0) {
        int d = number % 10;
        number /= 10;
        sumOfFacts += factorial(d);
    }
 
    if (sumOfFacts == i) {
        cout<<i<<endl;n
        result += i;
    }
}
    return result;
}

int main(){
    cout<<go()<<endl;
    return 0;
}
