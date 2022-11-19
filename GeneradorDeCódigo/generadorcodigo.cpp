#include "generadorcodigo.h"
#include <iostream>

using namespace std;


Generador::Generador(){
}

int Generador::add(int i, int j){
    int a = i;
    int res = 0;
    __asm__ ( "addl %%ebx, %%eax;"
        : "=a" (i)
        : "a" (i), "b" (j) );

    res = i;

    cout<<"GENERADOR DE CODIGO"<<endl;

    cout<<"int res = 0;"<<endl;
    cout<<"__asm__ ( 'addl %%ebx, %%eax;'"<<endl;
    cout<<"    : '=a'"<< "("<<a<<")"<<endl;
    cout<<"    : 'a'"<< "("<<a<<")"<<", 'b'"<< "("<<j<<") );"<<endl;

    cout<<"res = "<<i<<endl;
    return res;

}

int Generador::sub(int i, int j)
{
    int a = i;
    int res = 0;
    __asm__ ( "subl %%ebx, %%eax;"
        : "=a" (i)
        : "a" (i), "b" (j) );

    res = i;
    cout<<"GENERADOR DE CODIGO"<<endl;

    cout<<"int res = 0;"<<endl;
    cout<<"__asm__ ( 'subl %%ebx, %%eax;'"<<endl;
    cout<<"    : '=a'"<< "("<<a<<")"<<endl;
    cout<<"    : 'a'"<< "("<<a<<")"<<", 'b'"<< "("<<j<<") );"<<endl;

    cout<<"res = "<<i<<endl;
    return res;


}

int Generador::mul(int i, int j)
{
    int a = i;
    int res = 0;
    __asm__ ( "mul %%ebx"
        : "=a" (i)
        : "a" (i), "b" (j) );

    res = i;
    cout<<"GENERADOR DE CODIGO"<<endl;

    cout<<"int res = 0;"<<endl;
    cout<<"__asm__ ( 'mul %%ebx'"<<endl;
    cout<<"    : '=a'"<< "("<<a<<")"<<endl;
    cout<<"    : 'a'"<< "("<<a<<")"<<", 'b'"<< "("<<j<<") );"<<endl;

    cout<<"res = "<<i<<endl;
    return res;



}

int Generador::divl(int i, int j)
{
    int a = i;
    int res = 0;
    __asm__ (
        "xor %%edx, %%edx;"
        "divl %%ebx;"
        : "=a" (i)
        : "a" (i), "b" (j) );

    res = i;
    cout<<"GENERADOR DE CODIGO"<<endl;

    cout<<"int res = 0;"<<endl;
    cout<<"__asm__ ("<<endl;
    cout<<" xor %%edx, %%edx;"<<endl;
    cout<<"'mul %%ebx'"<<endl;
    cout<<"    : '=a'"<< "("<<a<<")"<<endl;
    cout<<"    : 'a'"<< "("<<a<<")"<<", 'b'"<< "("<<j<<") );"<<endl;

    cout<<"res = "<<i<<endl;
    return res;


}

long double Generador::LD_SIN(long double X)
{
    register long double __VALUE;

    __asm__ __volatile__(
        "fsin                  \n\t"
        : "=t" (__VALUE)
        : "0" (X)
    );
    cout<<"GENERADOR DE CODIGO"<<endl;

    cout<<"register long double __VALUE;"<<endl;
    cout<<"__asm__ __volatile__("<<endl;
    cout<<" fsin"<<endl;
    cout<<"'=t' (__VALUE)"<<endl;
    cout<<"'0'"<<"'("<<X<<")'"<<endl;


    return __VALUE;



}


long double Generador::LD_COS(long double __X)
{
    register long double __VALUE;

    __asm__ __volatile__(
        "fcos                  \n\t"
        : "=t" (__VALUE)
        : "0" (__X)
    );

    cout<<"GENERADOR DE CODIGO"<<endl;

    cout<<"register long double __VALUE;"<<endl;
    cout<<"__asm__ __volatile__("<<endl;
    cout<<" fcos"<<endl;
    cout<<"'=t' (__VALUE)"<<endl;
    cout<<"'0'"<<"'("<<__X<<")'"<<endl;

    return __VALUE;
}

long double Generador::LD_TAN(long double __X )
{
    register long double __VALUE;

    __asm__ __volatile__(
        "fptan                 \n\t"
        "fdivr                \n\t"

        : "=t" (__VALUE)
        : "0" (__X)
    );

    cout<<"GENERADOR DE CODIGO"<<endl;

    cout<<"register long double __VALUE;"<<endl;
    cout<<"__asm__ __volatile__("<<endl;
    cout<<" fptan           \n\t"<<endl;
    cout<<" fdivr           \n\t"<<endl;
    cout<<"'=t' (__VALUE)"<<endl;
    cout<<"'0'"<<"'("<<__X<<")'"<<endl;

    return __VALUE;
}
