#include <iostream>
#include "conio.h"


using namespace std;

int add(int i, int j)
{
    int res = 0;
    __asm__ ( "addl %%ebx, %%eax;"
        : "=a" (i)
        : "a" (i), "b" (j) );

    res = i;



}


long double LD_SIN(long double __X)
{
    register long double __VALUE;

    __asm__ __volatile__(
        "fsin                  \n\t"
        : "=t" (__VALUE)
        : "0" (__X)
    );
    return __VALUE;
}

long double LD_COS(long double __X)
{
    register long double __VALUE;

    __asm__ __volatile__(
        "fcos                  \n\t"
        : "=t" (__VALUE)
        : "0" (__X)
    );
    return __VALUE;
}

long double LD_TAN(long double __X )
{
    register long double __VALUE;

    __asm__ __volatile__(
        "fptan                 \n\t"
        "fdivr                \n\t"

        : "=t" (__VALUE)
        : "0" (__X)
    );
    return __VALUE;
}

int main(){
    int a = 1;
    int b = 2;
    int c = 0;
    c = add(a,b);
    cout<<c<<endl;
    long double i;
    i = LD_TAN(10);
    cout<<i<<endl;

    __asm(
        "movl %eax, %ebx"


    );


    return 0;
}
