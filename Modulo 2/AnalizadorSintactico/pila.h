#ifndef _PILA
#define _PILA

#include <list>
#include <iostream>
#include <string>

using namespace std;

class Nodo{
private:

public:
    Nodo();

};

class R1: public Nodo{
private:
    Nodo *nodo;
    int T1;
    int T2;

public:
    R1(Nodo*,int,int);

};

class R2: public Nodo{
private:
    int T1;
    int T2;
    int T3;

public:
    R2(int,int,int);

};

class ElementoPila{
    private:

    public:
        ElementoPila();
        virtual bool esEstado(){return false;}
        virtual bool esTerminal(){return false;}
        virtual bool esNoTerminal(){return false;}


};

class Estado: public ElementoPila{
    private:
    int elemento;
    public:
        Estado(int);
        bool esEstado(){return true;}

};

class Terminal: public ElementoPila{
    private:
    int elemento;
    public:
        Terminal(int);
        bool esTerminal(){return true;}


};

class NoTerminal: public ElementoPila{
private:
    Nodo *siguiente;
public:
    NoTerminal(Nodo*);
    bool esNoTerminal(){return true;}
    Nodo* DevuelveNodo();


};


class Pila{

   private:
      list <ElementoPila*> lista;

   public:
      void push(ElementoPila*);
      ElementoPila* top();
      ElementoPila* pop();
      void muestra();
      Pila();
};


#endif
