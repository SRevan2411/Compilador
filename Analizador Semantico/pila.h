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
    virtual void muestra();
    virtual void semantica();

};

class ObR1: public Nodo{
private:
    Nodo *definiciones;

public:
    ObR1(Nodo*);
    void muestra();
    void semantica();

};

class ObR2: public Nodo{
private:
    string vacio;

public:
    ObR2(string);
    void muestra();
    void semantica();
};

class ObR3: public Nodo{
private:
    Nodo *definicion;
    Nodo *definiciones;

public:
    ObR3(Nodo*,Nodo*);
    void muestra();
    void semantica();

};

class ObR4: public Nodo{
private:
    Nodo *defvar;

public:
    ObR4(Nodo*);
    void muestra();
    void semantica();

};

class ObR5: public Nodo{
private:
    Nodo *defunc;

public:
    ObR5(Nodo*);
    void muestra();
    void semantica();

};

class ObR6: public Nodo{
private:
    string puntoycoma;
    Nodo *listavar;
    string identificador;
    string tipo;

public:
    ObR6(string,Nodo*,string,string);
    void muestra();
    void semantica();

};

class ObR7: public Nodo{
private:
    string vacio;

public:
    ObR7(string);
    void muestra();

};

class ObR8: public Nodo{
private:
    string coma;
    Nodo *listavar;
    string identificador;


public:
    ObR8(string,string,Nodo*);
    void muestra();
    void semantica();


};

class ObR9: public Nodo{
private:
    string tipo;
    string identificador;
    string parentesis1;
    Nodo *parametros;
    string parentesis2;
    Nodo *bloqfunc;

public:
    ObR9(string,string,string,Nodo*,string,Nodo*);
    void muestra();
    void semantica();

};

class ObR10: public Nodo{
private:
    string vacio;

public:
    ObR10(string);
    void muestra();
    void semantica();

};


class ObR11: public Nodo{
private:

    Nodo *listaparam;
    string identificador;
    string tipo;

public:
    ObR11(Nodo*,string,string);
    void muestra();
    void semantica();

};

class ObR12: public Nodo{
private:
    string vacio;

public:
    ObR12(string);
    void muestra();
    void semantica();

};

class ObR13: public Nodo{
private:

    Nodo *listaparam;
    string identificador;
    string tipo;
    string coma;

public:
    ObR13(Nodo*,string,string,string);
    void muestra();
    void semantica();

};

class ObR14: public Nodo{
private:
    string llave1;
    Nodo *deflocales;
    string llave2;

public:
    ObR14(string,Nodo*,string);
    void muestra();
    void semantica();

};

class ObR15: public Nodo{
private:
    string vacio;

public:
    ObR15(string);
    void muestra();
    void semantica();

};

class ObR16: public Nodo{
private:
    Nodo *deflocal;
    Nodo *deflocales;

public:
    ObR16(Nodo*,Nodo*);
    void muestra();
    void semantica();

};

class ObR17: public Nodo{
private:
    Nodo *defvar;

public:
    ObR17(Nodo*);
    void muestra();
    void semantica();

};

class ObR18: public Nodo{
private:
    Nodo *sentencia;

public:
    ObR18(Nodo*);
    void muestra();
    void semantica();

};

class ObR21: public Nodo{
private:
    string puntoycoma;
    Nodo *expresion;
    string igual;
    string identificador;

public:
    ObR21(string,string,Nodo*,string);
    void muestra();
    void semantica();

};

class ObR24: public Nodo{
private:
    string puntoycoma;
    Nodo *valorregresa;
    string retur;

public:
    ObR24(string,Nodo*,string);
    void muestra();
    void semantica();

};

class ObR29: public Nodo{
private:
    string vacio;

public:
    ObR29(string);
    void muestra();
    void semantica();

};

class ObR30: public Nodo{
private:
    Nodo *expresion;

public:
    ObR30(Nodo*);
    void muestra();
    void semantica();
};

class ObR32: public Nodo{
private:
    Nodo *expresion;
    Nodo *listaargumentos;

public:
    ObR32(Nodo*,Nodo*);
    void muestra();

};


class ObR33: public Nodo{
private:
    string vacio;

public:
    ObR33(string);
    void muestra();

};

class ObR35: public Nodo{
private:
    Nodo *llamadafunc;

public:
    ObR35(Nodo*);
    void muestra();

};

class ObR36: public Nodo{
private:
    string identificador;

public:
    ObR36(string);
    void muestra();
    void semantica();

};

class ObR37: public Nodo{
private:
    string entero;

public:
    ObR37(string);
    void muestra();
    void semantica();

};

class ObR38: public Nodo{
private:
    string real;

public:
    ObR38(string);
    void muestra();
    void semantica();
};

class ObR39: public Nodo{
private:
    string cadena;

public:
    ObR39(string);
    void muestra();
    void semantica();
};

class ObR40: public Nodo{
private:
    string identificador;
    string parentesis1;
    Nodo *argumentos;
    string parentesis2;

public:
    ObR40(string,string,Nodo*,string);
    void muestra();

};

class ObR46: public Nodo{
private:
    Nodo *expresion1;
    string opmul;
    Nodo *expresion2;

public:
    ObR46(Nodo*,string,Nodo*);
    void muestra();
    void semantica();

};

class ObR47: public Nodo{
private:
    Nodo *expresion1;
    string opsuma;
    Nodo *expresion2;

public:
    ObR47(Nodo*,string,Nodo*);
    void muestra();
    void semantica();

};

class ObR52: public Nodo{
private:
    Nodo *termino;

public:
    ObR52(Nodo*);
    void muestra();
    void semantica();

};

//Clases de prueba
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
        virtual int getElemento(){return 0;}
        virtual string getElementos(){return "";}
        virtual Nodo* DevuelveNodo();
        virtual void identificate();
        virtual void muestra();
        virtual void semantica();
        virtual void usadas();


};

class Estado: public ElementoPila{
    private:
    int elemento;
    public:
        Estado(int);
        bool esEstado(){return true;}
        void identificate();
        int getElemento();
        void muestra();

};

class Terminal: public ElementoPila{
    private:
    string elemento;
    public:
        Terminal(string);
        bool esTerminal(){return true;}
        void identificate();
        string getElementos();
        void muestra();



};

class NoTerminal: public ElementoPila{
private:
    Nodo *siguiente;
public:
    NoTerminal(Nodo*);
    bool esNoTerminal(){return true;}
    void identificate();
    Nodo* DevuelveNodo();
    void muestra();
    void semantica();
    void usadas();


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
