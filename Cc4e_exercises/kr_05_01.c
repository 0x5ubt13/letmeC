#include <stdio.h>

int main() {
    int x, y;
    int* px;

    x = 42;
    px = &x;
    y = *px;
    printf("%d %p %d\n", x,px,y);
}

// 42 00000009d01ff790 42