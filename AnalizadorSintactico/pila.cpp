#include "pila.h"
#include <iostream>
#include <sstream>


using namespace std;

Nodo::Nodo(){

}

R2::R2(int t1, int t2, int t3):Nodo(){
    this->T1 = t1;
    this->T2 = t2;
    this->T3 = t3;

}

R1::R1(Nodo* nodo, int t1, int t2):Nodo(){
    this->nodo = nodo;
    this->T1 = t1;
    this->T2 = t2;
}

ElementoPila::ElementoPila(){
}

Nodo* ElementoPila::DevuelveNodo(){
    return nullptr;
}



Terminal::Terminal(int valor):ElementoPila(){
    this->elemento = valor;

}

int Terminal::getElemento(){
    return this->elemento;
}

NoTerminal::NoTerminal(Nodo* nodo):ElementoPila(){
    this->siguiente = nodo;


}



Nodo* NoTerminal::DevuelveNodo(){
    return this->siguiente;

}


Pila::Pila(){
}

void Pila::push(ElementoPila* x){
    lista.push_front(x);
}

 ElementoPila*  Pila::pop(){
    ElementoPila *elemento = *lista.begin();
    lista.erase(lista.begin());


    return elemento;
  }

ElementoPila* Pila::top(){
     return *lista.begin();
}

  void Pila::muestra(){

     list <ElementoPila*>::reverse_iterator  it;

     cout << "Pila: ";

     for (it= lista.rbegin(); it != lista.rend(); it++){
         cout << (*it) << " ";
     }

     cout << endl;
  }
