#include "pila.h"
#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;
//Variables globales


Pila p1;
stack<int> pila;

int E = 3;
int programa = 24;
int Definiciones = 25;
int Definicion = 26;
int DefVar = 27;
int ListaVar = 28;
int DefFunc = 29;
int Parametros = 30;
int ListaParam = 31;
int BloqFunc = 32;
int DefLocales = 33;
int DefLocal = 34;
int Sentencias = 35;
int Sentencia = 36;
int Otro = 37;
int Bloque = 38;
int ValorRegresa = 39;
int Argumentos = 40;
int ListaArgumentos = 41;
int Termino = 42;
int LlamadaFunc = 43;
int SentenciaBloque = 44;
int Expresion = 45;
int Matriz[95][46];
int Array[20] = {2,0,0,1,0,0,-1,0,0,3,0,0,4,0,0,0,0,0,-2,0};
int Array2[4370];

void loadfile(){
    int toint;
    string aux;
    ifstream fmatriz("compilador.lr");
    int i= 0;
    while(fmatriz>>toint){
        Array2[i] = toint;
        i++;
    }
}//end loadfile

/*
Pila regla2(Pila pila1){
    ElementoPila *p11 = new ElementoPila;
    ElementoPila *p2 = new ElementoPila;
    ElementoPila *p3 = new ElementoPila;
    ElementoPila *fila = new ElementoPila;
    int dato;
    Terminal *t1;
    Terminal *t2;
    pila1.pop();
    p11 = pila1.pop();
    pila1.pop();
    p2 = pila1.pop();
    pila1.pop();
    p3 = pila1.pop();
    int d1,d2,d3;
    d1 = p11->getElemento();
    d2 = p2->getElemento();
    d3 = p3->getElemento();
    R2 *reg2 = new R2(d1,d2,d3);
    NoTerminal *nt1 = new NoTerminal(reg2);
    fila = pila1.top();
    dato = fila->getElemento();
    int columna = E;
    int elemento = Matriz[dato][columna];
    t1 = new Terminal(columna);
    t2 = new Terminal(elemento);
    pila1.push(nt1);
    pila1.push(t2);
    return pila1;

}

Pila regla1(Pila pila1){
    ElementoPila *p11 = new ElementoPila;
    ElementoPila *p2 = new ElementoPila;
    ElementoPila *p3 = new ElementoPila;
    ElementoPila *fila = new ElementoPila;
    int dato;
    Terminal *t1;
    Terminal *t2;
    pila1.pop();
    p11 = pila1.pop();
    pila1.pop();
    p2 = pila1.pop();
    pila1.pop();
    p3 = pila1.pop();
    int d1,d2,d3;
    Nodo *nd1 = new Nodo;
    nd1 = p11->DevuelveNodo();
    d2 = p2->getElemento();
    d3 = p3->getElemento();
    R1 *reg2 = new R1(nd1,d2,d3);
    NoTerminal *nt1 = new NoTerminal(reg2);
    fila = pila1.top();
    dato = fila->getElemento();
    int columna = E;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Terminal(columna);
    t2 = new Terminal(elemento);
    pila1.push(nt1);
    pila1.push(t2);
    return pila1;

}
*/

void nR1(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    ElementoPila *e2 = new ElementoPila;
    e1 = p1.pop();
    e2 = p1.pop();
    e1->identificate();
    e2->identificate();
    Nodo *nodo = new Nodo();
    nodo = e2->DevuelveNodo();
    ObR1 *n1 = new ObR1(nodo);
    NoTerminal *nt = new NoTerminal(n1);
    fila = p1.top();
    dato = fila->getElemento();
    int columna = programa;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R1

void nR2(){
    cout<<"Entra"<<endl;
    ObR2 *n2 = new ObR2("vacio");
    NoTerminal *nt = new NoTerminal(n2);
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    cout<<"Eliminando 2 datos"<<endl;
    fila = p1.top();
    dato = fila->getElemento();
    cout<<"Tope de la pila: "<<dato<<endl;
    int columna = Definiciones;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R2

void R3(){
    Estado *t1;
    Estado *t2;
    int dato;
    Nodo *definiciones = new Nodo();
    Nodo *definicion = new Nodo();
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    ElementoPila *e2 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    p1.pop();
    e2 = p1.pop();
    e1->muestra();
    e2->muestra();
    definiciones = e1->DevuelveNodo();
    definicion = e2->DevuelveNodo();
    ObR3 *n3 = new ObR3(definicion,definiciones);
    NoTerminal *nt = new NoTerminal(n3);
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Definiciones;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R3

void R4(){
    Nodo *nd = new Nodo();
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    nd = e1->DevuelveNodo();
    cout<<"Imprimiendo"<<endl;
    nd->muestra();
    ObR4 *n4 = new ObR4(nd);
    NoTerminal *nt = new NoTerminal(n4);
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Definicion;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R4

void R5(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    e1->identificate();
    Nodo *nd = new Nodo();
    nd = e1->DevuelveNodo();
    ObR5 *n5 = new ObR5(nd);
    NoTerminal *nt = new NoTerminal(n5);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Definicion;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R5

void R6(){
    string puntoycoma;
    Nodo *listavar = new Nodo();
    string identificador;
    string tipo;
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    ElementoPila *e2 = new ElementoPila;
    ElementoPila *e3 = new ElementoPila;
    ElementoPila *e4 = new ElementoPila;
    ElementoPila *e5 = new ElementoPila;
    ElementoPila *e6 = new ElementoPila;
    ElementoPila *e7 = new ElementoPila;
    ElementoPila *e8 = new ElementoPila;
    e1 = p1.pop();
    e2 = p1.pop();
    puntoycoma = e2->getElementos();
    e3 = p1.pop();
    e4 = p1.pop();
    listavar = e4->DevuelveNodo();
    e5 = p1.pop();
    e6 = p1.pop();
    identificador = e6->getElementos();
    e7 = p1.pop();
    e8 = p1.pop();
    tipo = e8->getElementos();
    ObR6 *n6 = new ObR6(puntoycoma,listavar,identificador,tipo);
    NoTerminal *nt = new NoTerminal(n6);
    e1->identificate();
    e2->identificate();
    e3->identificate();
    e4->identificate();
    e5->identificate();
    e6->identificate();
    e7->identificate();
    e8->identificate();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = DefVar;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R6

void R7(){
    Estado *t1;
    Estado *t2;
    int dato;
    ObR7 *n7 = new ObR7("vacio");
    NoTerminal *nt = new NoTerminal(n7);
    ElementoPila *fila = new ElementoPila;
    fila = p1.top();
    dato = fila->getElemento();
    int columna = ListaVar;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);
}//end R7


void R8(){
    string coma,identificador;
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    ElementoPila *e2 = new ElementoPila;
    ElementoPila *e3 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    p1.pop();
    e2 = p1.pop();
    p1.pop();
    e3 = p1.pop();
    Nodo *listavar = new Nodo();
    listavar = e1->DevuelveNodo();
    identificador = e2->getElementos();
    coma = e3->getElementos();
    ObR8 *n8 = new ObR8(coma,identificador,listavar);
    NoTerminal *nt = new NoTerminal(n8);
    fila = p1.top();
    dato = fila->getElemento();
    int columna = ListaVar;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R8

void R9(){
    string tipo,identificador,parentesis1,parentesis2;
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    ElementoPila *e2 = new ElementoPila;
    ElementoPila *e3 = new ElementoPila;
    ElementoPila *e4 = new ElementoPila;
    ElementoPila *e5 = new ElementoPila;
    ElementoPila *e6 = new ElementoPila;
    Nodo *bloqfunc = new Nodo();
    Nodo *parametros = new Nodo();
    p1.pop();
    e1 = p1.pop();
    p1.pop();
    e2 = p1.pop();
    p1.pop();
    e3 = p1.pop();
    p1.pop();
    e4 = p1.pop();
    p1.pop();
    e5 = p1.pop();
    p1.pop();
    e6 = p1.pop();
    e1->identificate();
    e2->identificate();
    e3->identificate();
    e4->identificate();
    e5->identificate();
    e6->identificate();
    bloqfunc = e1->DevuelveNodo();
    parentesis2 = e2->getElementos();
    parametros = e3->DevuelveNodo();
    parentesis1 = e4->getElementos();
    identificador = e5->getElementos();
    tipo = e6->getElementos();
    ObR9 *n9 = new ObR9(tipo,identificador,parentesis1,parametros,parentesis2,bloqfunc);
    NoTerminal *nt = new NoTerminal(n9);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = DefFunc;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R9

void R10(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ObR10 *n10 = new ObR10("vacio");
    NoTerminal *nt = new NoTerminal(n10);
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Parametros;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R10

void R11(){
    string tipo,identificador;
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    ElementoPila *e2 = new ElementoPila;
    ElementoPila *e3 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    p1.pop();
    e2 = p1.pop();
    p1.pop();
    e3 = p1.pop();
    e1->identificate();
    e2->identificate();
    e3->identificate();
    Nodo *nd = new Nodo();
    nd = e1->DevuelveNodo();
    identificador = e2->getElementos();
    tipo = e3->getElementos();
    ObR11 *n11 = new ObR11(nd,identificador,tipo);
    NoTerminal *nt = new NoTerminal(n11);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Parametros;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R11

void R12(){
    Estado *t1;
    Estado *t2;
    int dato;
    ObR12 *n12 = new ObR12("vacio");
    NoTerminal *nt = new NoTerminal(n12);
    ElementoPila *fila = new ElementoPila;
    fila = p1.top();
    dato = fila->getElemento();
    int columna = ListaParam;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R12

void R13(){
    string coma,tipo,identificador;
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    ElementoPila *e2 = new ElementoPila;
    ElementoPila *e3 = new ElementoPila;
    ElementoPila *e4 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    p1.pop();
    e2 = p1.pop();
    p1.pop();
    e3 = p1.pop();
    p1.pop();
    e4 = p1.pop();
    e1->identificate();
    e2->identificate();
    e3->identificate();
    e4->identificate();
    identificador = e2->getElementos();
    tipo = e3->getElementos();
    coma = e4->getElementos();
    Nodo *nd = new Nodo();
    nd = e1->DevuelveNodo();
    ObR13 *n13 = new ObR13(nd,identificador,tipo,coma);
    NoTerminal *nt = new NoTerminal(n13);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = ListaParam;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R13

void R14(){
    string llave1,llave2;
    Nodo *nd = new Nodo();
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    ElementoPila *e2 = new ElementoPila;
    ElementoPila *e3 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    p1.pop();
    e2 = p1.pop();
    p1.pop();
    e3 = p1.pop();
    e1->identificate();
    e2->identificate();
    e3->identificate();
    llave2 = e1->getElementos();
    llave1 = e3->getElementos();
    nd = e2->DevuelveNodo();
    ObR14 *n14 = new ObR14(llave1,nd,llave2);
    NoTerminal *nt = new NoTerminal(n14);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = BloqFunc;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R14

void R15(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ObR15 *n15 = new ObR15("vacio");
    NoTerminal *nt = new NoTerminal(n15);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = DefLocales;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R15

void R16(){
    Nodo *deflocales = new Nodo();
    Nodo *deflocal = new Nodo();
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    ElementoPila *e2 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    p1.pop();
    e2 = p1.pop();
    e1->identificate();
    e2->identificate();
    deflocales = e1->DevuelveNodo();
    deflocal = e2->DevuelveNodo();
    ObR16 *n16 = new ObR16(deflocal,deflocales);
    NoTerminal *nt = new NoTerminal(n16);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = DefLocales;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R16

void R17(){
    Nodo *nd = new Nodo();
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    e1->identificate();
    nd = e1->DevuelveNodo();
    ObR17 *n17 = new ObR17(nd);
    NoTerminal *nt = new NoTerminal(n17);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = DefLocal;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R17

void R18(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    e1->identificate();
    Nodo *nd = new Nodo();
    nd = e1->DevuelveNodo();
    ObR18 *n18 = new ObR18(nd);
    NoTerminal *nt = new NoTerminal(n18);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = DefLocal;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R18

void R19(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Sentencias;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(t1);
    p1.push(t2);

}//end R19

void R20(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Sentencias;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(t1);
    p1.push(t2);

}//end R20

void R21(){
    string identificador,igual,puntoycoma;
    Nodo *nd = new Nodo();
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    ElementoPila *e2 = new ElementoPila;
    ElementoPila *e3 = new ElementoPila;
    ElementoPila *e4 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    p1.pop();
    e2 = p1.pop();
    p1.pop();
    e3 = p1.pop();
    p1.pop();
    e4 = p1.pop();
    e1->identificate();
    e2->identificate();
    e3->identificate();
    e4->identificate();
    puntoycoma = e1->getElementos();
    nd = e2->DevuelveNodo();
    igual = e3->getElementos();
    identificador = e4->getElementos();
    ObR21 *n21 = new ObR21(identificador,igual,nd,puntoycoma);
    NoTerminal *nt = new NoTerminal(n21);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Sentencia;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R21

void R24(){
    string retur,puntoycoma;
    Nodo *nd = new Nodo();
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    ElementoPila *e2 = new ElementoPila;
    ElementoPila *e3 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    p1.pop();
    e2 = p1.pop();
    p1.pop();
    e3 = p1.pop();
    e1->identificate();
    e2->identificate();
    e3->identificate();
    puntoycoma = e1->getElementos();
    nd = e2->DevuelveNodo();
    retur = e3->getElementos();
    ObR24 *n24 = new ObR24(retur,nd,puntoycoma);
    NoTerminal *nt = new NoTerminal(n24);
    nt ->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Sentencia;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R24

void R25(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Sentencia;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(t1);
    p1.push(t2);

}//end R25

void R29(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    fila = p1.top();
    dato = fila->getElemento();
    int columna = ValorRegresa;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(t1);
    p1.push(t2);

}//end R29

void R30(){
    Nodo *nd = new Nodo();
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    e1->identificate();
    nd = e1->DevuelveNodo();
    ObR30 *n30 = new ObR30(nd);
    NoTerminal *nt = new NoTerminal(n30);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = ValorRegresa;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R30

void R31(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Argumentos;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(t1);
    p1.push(t2);

}//end R31

void R32(){
    Nodo *expresion = new Nodo();
    Nodo *listaargumentos = new Nodo();
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    ElementoPila *e2 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    p1.pop();
    e2 = p1.pop();
    e1->identificate();
    e2->identificate();
    listaargumentos = e1->DevuelveNodo();
    expresion = e2->DevuelveNodo();
    ObR32 *n32 = new ObR32(expresion,listaargumentos);
    NoTerminal *nt = new NoTerminal(n32);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Argumentos;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R32

void R33(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ObR33 *n33 = new ObR33("vacio");
    NoTerminal *nt = new NoTerminal(n33);
    fila = p1.top();
    dato = fila->getElemento();
    int columna = ListaArgumentos;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R33

void R34(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = ListaArgumentos;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(t1);
    p1.push(t2);

}//end R34

void R35(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    e1->identificate();
    Nodo *nd = new Nodo();
    nd = e1->DevuelveNodo();
    ObR35 *n35 = new ObR35(nd);
    NoTerminal *nt = new NoTerminal(n35);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Termino;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R35

void R36(){
    string identificador;
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    e1->identificate();
    identificador = e1->getElementos();
    ObR36 *n36 = new ObR36(identificador);
    NoTerminal *nt = new NoTerminal(n36);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Termino;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R36

void R37(){
    string entero;
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    e1->identificate();
    entero = e1->getElementos();
    ObR37 *n37 = new ObR37(entero);
    NoTerminal *nt = new NoTerminal(n37);
    nt->muestra();

    fila = p1.top();
    dato = fila->getElemento();
    int columna = Termino;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R37

void R38(){
    string real;
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    real = e1->getElementos();
    ObR38 *n38 = new ObR38(real);
    NoTerminal *nt = new NoTerminal(n38);
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Termino;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R38

void R39(){
    string cadena;
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    cadena = e1->getElementos();
    ObR39 *n39 = new ObR39(cadena);
    NoTerminal *nt = new NoTerminal(n39);
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Termino;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R39

void R40(){
    string identificador,parentesis1,parentesis2;
    Nodo *argumentos = new Nodo();
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    ElementoPila *e2 = new ElementoPila;
    ElementoPila *e3 = new ElementoPila;
    ElementoPila *e4 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    p1.pop();
    e2 = p1.pop();
    p1.pop();
    e3 = p1.pop();
    p1.pop();
    e4 = p1.pop();
    e1->identificate();
    e2->identificate();
    e3->identificate();
    e4->identificate();
    parentesis2 = e1->getElementos();
    argumentos = e2->DevuelveNodo();
    parentesis1 = e3->getElementos();
    identificador = e4->getElementos();
    ObR40 *n40 = new ObR40(identificador,parentesis1,argumentos,parentesis2);
    NoTerminal *nt = new NoTerminal(n40);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = LlamadaFunc;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R40

void R46(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Expresion;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(t1);
    p1.push(t2);

}//end R46

void R47(){
    Nodo *nd1 = new Nodo();
    string opsuma;
    Nodo *nd2 = new Nodo();
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    ElementoPila *e2 = new ElementoPila;
    ElementoPila *e3 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    p1.pop();
    e2 = p1.pop();
    p1.pop();
    e3 = p1.pop();
    e1->identificate();
    e2->identificate();
    e3->identificate();
    nd1 = e1->DevuelveNodo();
    opsuma = e2->getElementos();
    nd2 = e3->DevuelveNodo();
    ObR47 *n47 = new ObR47(nd2,opsuma,nd1);
    NoTerminal *nt = new NoTerminal(n47);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Expresion;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R47

void R48(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Expresion;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(t1);
    p1.push(t2);

}//end R48

void R49(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Expresion;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(t1);
    p1.push(t2);

}//end R49

void R52(){
    Estado *t1;
    Estado *t2;
    int dato;
    ElementoPila *fila = new ElementoPila;
    ElementoPila *e1 = new ElementoPila;
    p1.pop();
    e1 = p1.pop();
    e1->identificate();
    Nodo *nd = new Nodo();
    nd = e1->DevuelveNodo();
    ObR52 *n52 = new ObR52(nd);
    NoTerminal *nt = new NoTerminal(n52);
    nt->muestra();
    fila = p1.top();
    dato = fila->getElemento();
    int columna = Expresion;
    int elemento = Matriz[dato][columna];
    cout<<"Elemento obtenido"<<elemento<<endl;
    t1 = new Estado(columna);
    t2 = new Estado(elemento);
    p1.push(nt);
    p1.push(t2);

}//end R52





void StoreMatriz(){
    int h = 0;
    for (int i = 0; i < 95; i++){
        for(int j = 0; j < 46; j++){
            Matriz[i][j] = Array2[h];
            h++;
        }//end for
    }//end for

    for (int i = 0; i < 95; i++){
        for(int j = 0; j < 46; j++){
            cout<<Matriz[i][j]<<" ";
        }//end for
        cout<<endl;
    }//end for

}//end StoreMatriz

void PruebaRecorrerCadena(string cadena){

    cout<<cadena<<endl;
}//end PruebaRecorrerCadena

bool EsLetra(char caracter){
    bool bandera = false;
    char letras[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int i = 0; i < 27; i++){
        if(letras[i] == caracter){
            bandera = true;
            break;
        }//end if
    }//end for
    return bandera;
}//end EsLetra

bool EsDigito(char caracter){
    bool bandera = false;
    char letras[10] = {'0','1','2','3','4','5','6','7','8','9'};
    for(int i = 0; i < 10; i++){
        if(letras[i] == caracter){
            bandera = true;
            break;
        }//end if
    }//end for
    return bandera;
}//end EsDigito

int AutomataLexico(string cadena){
    cout<<"Analizando: "<<cadena<<endl;
    int Estado = 1;
    for(int i = 0; i < cadena.size(); i++){
        switch (Estado)
        {
        case 1:
            if(EsLetra(cadena[i]) == true){
                Estado = 2;
            }else if(EsDigito(cadena[i])==true){
                Estado = 3;
            }else if(cadena[i]=='"'){
                Estado = 6;
            }else if(cadena[i]=='+' || cadena[i] == '-'){
                Estado = 10;
            }else if(cadena[i]=='*' || cadena[i] == '/'){
                Estado = 11;
            }else if(cadena[i]=='<' || cadena[i] == '>'){
                Estado = 12;
            }else if(cadena[i]=='|'){
                Estado = 14;
            }else if(cadena[i]=='&'){
                Estado = 16;
            }else if(cadena[i]=='!'){
                Estado = 18;
            }else if(cadena[i]=='='){
                Estado = 20;
            }else if(cadena[i]==';'){
                Estado = 22;
            }else if(cadena[i]== ','){
                Estado = 23;
            }else if(cadena[i]=='('){
                Estado = 24;
            }else if(cadena[i]==')'){
                Estado = 25;
            }else if(cadena[i]=='{'){
                Estado = 26;
            }else if(cadena[i]=='}'){
                Estado = 27;
            }else if(cadena[i]=='$'){
                Estado = 28;
            }

            else{
                cout<<"Cadena no valida Estado 1"<<endl;
                return -1;
                break;
            }//end else
            break;
        case 2:
            if(EsLetra(cadena[i]) == true){
                Estado = 2;
            }else if(EsDigito(cadena[i])==true){
                Estado = 2;
            }else{
                cout<<"Cadena no valida Estado 2"<<endl;
                return -1;
                break;
            }//end else
            break;
        case 3:
            if(EsDigito(cadena[i]) == true){
                Estado = 3;
            }else if(cadena[i] == '.'){
                Estado = 4;
            }else{
                cout<<"Cadena no valida Estado 3"<<endl;
                return -1;
                break;
            }//end else
            break;
        case 4:
            if(EsDigito(cadena[i]) == true){
                Estado = 5;
            }else{
                cout<<"Cadena no valida Estado 4"<<endl;
                return -1;
                break;
            }//end if else
            break;
        case 5:
            if(EsDigito(cadena[i]) == true){
                Estado = 5;
            }else{
                cout<<"Cadena no valida Estado 5"<<endl;
                return -1;
                break;
            }//end if else
            break;
        case 6:
            if (cadena[i] == '"'){
                Estado = 7;
            }else if(EsLetra(cadena[i]) == true || EsDigito(cadena[i]) == true){
                Estado = 8;
            }else{
                cout<<"Cadena no valida Estado 6"<<endl;
                return -1;
                break;
            }//end if else
            break;
        case 8:
            if (cadena[i] == '"'){
                Estado = 9;
            }else if(EsLetra(cadena[i]) == true || EsDigito(cadena[i]) == true){
                Estado = 8;
            }else{
                cout<<"Cadena no valida Estado 8"<<endl;
                return -1;
                break;
            }//end if else
            break;
        case 12:
            if(cadena[i] == '='){
                Estado = 13;
                break;
            }else{
                cout<<"Cadena no valida Estado 12"<<endl;
                return -1;
                break;
            }//end if else
            break;
        case 14:
            if(cadena[i] == '|'){
                Estado = 15;
                break;
            }else{
                cout<<"Cadena no valida Estado 14"<<endl;
                return -1;
                break;
            }//end if else
            break;
        case 16:
            if(cadena[i] == '&'){
                Estado = 17;
                break;
            }else{
                cout<<"Cadena no valida Estado 16"<<endl;
                return -1;
                break;
            }//end if else
            break;
        case 18:
            if(cadena[i] == '='){
                Estado = 19;
                break;
            }else{
                cout<<"Cadena no valida Estado 16"<<endl;
                return -1;
                break;
            }//end if else
            break;
        case 20:
            if(cadena[i] == '='){
                Estado = 21;
                break;
            }else{
                cout<<"Cadena no valida Estado 16"<<endl;
                return -1;
                break;
            }//end if else
            break;
        default:
            cout<<"Estdo no esperado"<<endl;
            return -1;
            break;
        }//end switch
    }//end for

    switch (Estado)
    {
        //hola 2 2.2 "hola" int float void + - * / < > <= >= || && ! != == ; ' ( ) { } = if while return else $
    case 2:
        if(cadena == "int" || cadena == "float" || cadena == "void"){
            cout<<"Palabra reservada: "<<cadena<<endl;
            return 4;
        }else if(cadena == "if"){
            cout<<"Palabra reservada: "<<cadena<<endl;
            return 19;
        }else if(cadena == "while"){
            cout<<"Palabra reservada: "<<cadena<<endl;
            return 20;
        }else if(cadena == "return"){
            cout<<"Palabra reservada: "<<cadena<<endl;
            return 21;
        }else if(cadena == "else"){
            cout<<"Palabra reservada: "<<cadena<<endl;
            return 22;
        }else{
            cout<<"Identificador"<<endl;
            return 0;
        }//end if anidado
        break;

    case 3:
        cout<<"Entero"<<endl;
        return 1;
        break;
    case 5:
        cout<<"Real"<<endl;
        return 2;
        break;
    case 7:
        cout<<"Cadena"<<endl;
        return 3;
        break;
    case 9:
        cout<<"Cadena"<<endl;
        return 3;
        break;
    case 10:
        cout<<"OpSuma"<<endl;
        return 5;
        break;
    case 11:
        cout<<"OpMul"<<endl;
        return 6;
        break;
    case 12:
        cout<<"OpRelac"<<endl;
        return 7;
        break;
    case 13:
        cout<<"OpRelac"<<endl;
        return 7;
        break;
    case 15:
        cout<<"OpOr"<<endl;
        return 8;
        break;
    case 17:
        cout<<"OpAnd"<<endl;
        return 9;
        break;
    case 18:
        cout<<"OpNot"<<endl;
        return 10;
        break;
    case 19:
        cout<<"OpIgualdad"<<endl;
        return 11;
        break;
    case 20:
        cout<<"="<<endl;
        return 18;
        break;
    case 21:
        cout<<"OpIgualdad"<<endl;
        return 11;
        break;
    case 22:
        cout<<";"<<endl;
        return 12;
        break;
    case 23:
        cout<<","<<endl;
        return 13;
        break;
    case 24:
        cout<<"("<<endl;
        return 14;
        break;
    case 25:
        cout<<")"<<endl;
        return 15;
        break;
    case 26:
        cout<<"{"<<endl;
        return 16;
        break;
    case 27:
        cout<<"}"<<endl;
        return 17;
        break;
    case 28:
        cout<<"$"<<endl;
        return 23;
        break;
    default:
        break;
    }
}//end AutomataLexico

bool nAnalizadorS(int operando,string cadena){
    bool bandera = false;
    /*
    ElementoPila *t1 = p1.top();
    if(t1->esTerminal()==true){
        cout<<"Hey"<<endl;
        cout<<t1->getElemento()<<endl;

    }
    */
    ElementoPila *tope = new ElementoPila;
    tope = p1.top();
    int fila = tope->getElemento();
    int columna = operando;
    int elemento = Matriz[fila][columna];
    cout<<"La fila es: "<<fila;
    cout<<"La columna es: "<<columna;
    cout<<"El elemento es: "<<elemento<<endl;
    if(elemento > 0){
        Terminal *t1 = new Terminal(cadena);
        Estado *t2 = new Estado(elemento);
        p1.push(t1);
        p1.push(t2);
    }else if(elemento < 0){
        if(elemento == -1){
            cout<<"La gramatica fue validada"<<endl;
            bandera = true;
            return bandera;
        }
        else if(elemento == -2){
            cout<<"Regla 1"<<endl;
            nR1();
        }else if(elemento == -3){
            cout<<"Regla 2"<<endl;
            nR2();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -4){
            cout<<"Regla 3"<<endl;
            R3();
        }else if(elemento == -5){
            cout<<"Regla 4"<<endl;
            R4();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -6){
            cout<<"Regla 5"<<endl;
            R5();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -7){
            cout<<"Regla 6"<<endl;
            R6();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -8){
            cout<<"Regla 7"<<endl;
            R7();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -9){
            cout<<"Regla 8"<<endl;
            R8();
            nAnalizadorS(12,cadena);
        }else if(elemento == -10){
            cout<<"Regla 9"<<endl;
            R9();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -11){
            cout<<"Regla 10"<<endl;
            R10();
            nAnalizadorS(15,cadena);
        }else if(elemento == -12){
            cout<<"Regla 11"<<endl;
            R11();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -13){
            cout<<"Regla 12"<<endl;
            R12();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -14){
            cout<<"Regla 13"<<endl;
            R13();
            nAnalizadorS(15,cadena);
        }else if(elemento == -15){
            cout<<"Regla 14"<<endl;
            R14();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -16){
            cout<<"Regla 15"<<endl;
            R15();
            nAnalizadorS(17,cadena);
        }else if(elemento == -17){
            cout<<"Regla 16"<<endl;
            R16();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -18){
            cout<<"Regla 17"<<endl;
            R17();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -19){
            cout<<"Regla 18"<<endl;
            R18();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -20){
            cout<<"Regla 19"<<endl;
            R19();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -21){
            cout<<"Regla 20"<<endl;
            R20();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -22){
            cout<<"Regla 21"<<endl;
            R21();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -25){
            cout<<"Regla 24"<<endl;
            R24();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -26){
            cout<<"Regla 25"<<endl;
            R25();

        }
        else if(elemento == -30){
            cout<<"Regla 29"<<endl;
            R29();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -31){
            cout<<"Regla 30"<<endl;
            R30();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -32){
            cout<<"Regla 31"<<endl;
            R31();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -33){
            cout<<"Regla 32"<<endl;
            R32();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -34){
            cout<<"Regla 33"<<endl;
            R33();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -35){
            cout<<"Regla 34"<<endl;
            R34();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -36){
            cout<<"Regla 35"<<endl;
            R35();
            nAnalizadorS(operando,cadena);
        }
        else if(elemento == -37){
            cout<<"Regla 36"<<endl;
            R36();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -38){
            cout<<"Regla 37"<<endl;
            R37();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -39){
            cout<<"Regla 38"<<endl;
            R38();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -40){
            cout<<"Regla 39"<<endl;
            R39();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -41){
            cout<<"Regla 40"<<endl;
            R40();
            nAnalizadorS(operando,cadena);
        }
        else if(elemento == -47){
            cout<<"Regla 46"<<endl;
            R46();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -48){
            cout<<"Regla 47"<<endl;
            R47();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -49){
            cout<<"Regla 48"<<endl;
            R48();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -50){
            cout<<"Regla 49"<<endl;
            R49();
            nAnalizadorS(operando,cadena);
        }else if(elemento == -53){
            cout<<"Regla 52"<<endl;
            R52();
            nAnalizadorS(operando,cadena);
        }
    }//end else if elemento
    else{
        cout<<"Error sintactico en: "<<operando<<endl;
        system("pause");
        exit(-1);
    }
    return bandera;

}



bool AnalizadorSintactico(int operando){
    cout<<"Tope de la pila: "<<pila.top()<<endl;
    int fila = pila.top();
    int columna = operando;
    int elemento = Matriz[fila][columna];
    cout<<"El elemento es: "<<elemento<<endl;
    if(elemento > 0 ){
        pila.push(operando);
        pila.push(elemento);
    }else if(elemento < 0){
        if(elemento == -1){
            cout<<"Gramatica validada"<<endl;
            return true;
        }else{
            pila.pop();
            pila.pop();
            pila.pop();
            pila.pop();
            pila.pop();
            pila.pop();
            fila = pila.top();
            columna = E;
            elemento = Matriz[fila][columna];
            pila.push(E);
            pila.push(elemento);
            return false;
        }
    }//end if else

}//end AnalizadorSintactico


int separarCadena(string datos){
    string separador;
    int elemento;
    bool flag = false;
    for(int i = 0; i < datos.size(); i++){
        if(datos[i] !=' '){
            separador += datos[i];
        }else{
            elemento = AutomataLexico(separador);
            cout<<elemento<<endl;
            nAnalizadorS(elemento,separador);
            separador = "";
        }//end if else
    }//end for
    if(separador != ""){
        elemento = AutomataLexico(separador);
        cout<<elemento<<endl;
        nAnalizadorS(elemento,separador);
    }//end if
    while(flag == false){
        cout<<"entra"<<endl;
        flag = nAnalizadorS(elemento,separador);
    }
}

void PilaMuestra(){
    ElementoPila *e1 = new ElementoPila();
    p1.pop();
    e1 = p1.pop();
    e1->identificate();
    if (e1->esNoTerminal()==true){
        cout<<"IMPRIMIENDO ARBOL SINTACTICO"<<endl;
        e1->muestra();
    }

    cout<<"SEMANTICO"<<endl;
    e1->semantica();
    e1->usadas();


}

int main(){
    loadfile();
    StoreMatriz();
    string cadena = "int main ( int a , int b ) { float c , d ; a = d ; } int coma ( int a ) { a = a ; } $";
    Estado *t1;
    Estado *t2;
    t1 = new Estado(23);
    t2 = new Estado(0);
    p1.push(t1);
    p1.push(t2);
    separarCadena(cadena);
    PilaMuestra();

    /*
    string cadena = "hola + mundo $";
    pila.push(2);
    pila.push(0);
    //cout<<"Ingrese la cadena a analizar: "<<endl;
    //getline(cin,cadena);
    StoreMatriz();
    separarCadena(cadena);
    */
    return 0;
}//end main
