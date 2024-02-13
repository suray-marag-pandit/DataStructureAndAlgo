#include<stdio.h>

enum suit {
    const1,
    const2,
    Wednesday,
};

int main(int argc, char const *argv[])
{   
    enum suit apple;

    apple = const2;

    printf("%d",apple);
    
    return 0;
}
