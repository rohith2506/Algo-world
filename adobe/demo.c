#include <stdio.h>

int main() {
    char *p1 = "the world is", *p2;
    p2 = p1;
    p1 = "beautiful";
    printf("%s %s\n", p1, p2);
    return 0;
}
