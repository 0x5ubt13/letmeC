// Pointer arithmetic
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ca[10], *cp;
    int ia[10], *ip;

    cp = ca + 1;
    ip = ia + 1;

    printf("ca %p cp %p\n", ca, cp);
    printf("ia %p ip %p\n", ia, ip);
}

// ca 000000d744fffdd6 cp 000000d744fffdd7
// ia 000000d744fffda0 ip 000000d744fffda4