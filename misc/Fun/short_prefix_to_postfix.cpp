#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;


int main(){
        char c = getchar();
        (c == '+' || c == '-' || c == '*' || c == '/') ? main(), main() : 0;
        putchar(c);
        return 0;  
}
