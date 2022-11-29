#include "pila.h"
#include <iostream>
#include <sstream>
#include <string>
#include "generadorcodigo.h"
#define MAX 50

using namespace std;

//Reglas

Generador calculadora;

string tipoauxiliar;
string ambito = "global";
string tipovar;
string tipoambito;
string auxvariable;
string auxoperador;
string funcionauxiliar;
int contuniversal;
string tipo1;
string tipo2;
bool iden = false;
bool opsuma = false;
bool ret = false;
bool especial = false;

int fila = 0;
int filaf = 0;
int filavalores = 0;

string lfunciones[MAX][2];
string lvariables[MAX][4];
string lvalores[MAX][3];

string obtvalores(string variable){
    for(int i = 0; i <= filavalores-1; i++){
        if(lvalores[i][1]==variable){
            return lvalores[i][2];
        }
    }
}


void agregarvalor(string ambito, string variable, string valor){
    lvalores[filavalores][0] = ambito;
    lvalores[filavalores][1] = variable;
    lvalores[filavalores][2] = valor;
    filavalores = filavalores + 1;
}

void printvalores(){
    for(int i = 0; i <= filavalores-1; i++){
        cout<<endl;
        cout<<lvalores[i][0]<<"|"<<lvalores[i][1]<<"|"<<lvalores[i][2]<<endl;
    }

}

void utilizadas(){
    for(int i = 0; i < MAX;i++){
        if(lvariables[i][3]=="no"){
            cout<<"Warning: variable "<<lvariables[i][1]<<" no utilizada"<<endl;
        }//end if
    }//end for

}

bool existenciavar(string identificador,string ambito){
    for(int i = 0; i < MAX;i++){
        if(lvariables[i][1]==identificador && lvariables[i][2]==ambito){
            return true;
        }//end if
    }//end for
    return false;
}

bool existenciafunc(string tipo,string identificador){
    for(int i = 0; i < MAX;i++){
        if(lfunciones[i][0]==tipo && lfunciones[i][1]==identificador){
            return true;
        }//end if
    }//end for
    return false;
}

bool existenciafunc2(string identificador){
    for(int i = 0; i < MAX;i++){
        if(lfunciones[i][1]==identificador){
            return true;
        }//end if
    }//end for
    return false;
}

string getTipo(string identificador, string ambito){
    for(int i = 0; i < MAX;i++){
        if(lvariables[i][1]==identificador && lvariables[i][2]==ambito){
            lvariables[i][3] = "si";
            return lvariables[i][0];
        }//end if
    }//end for
}

string getTipoAmbito(){
    for(int i = 0; i < MAX;i++){
        if(lfunciones[i][1]==ambito){
            cout<<"Se encontro"<<endl;
            return lfunciones[i][0];
        }//end if
    }//end for
}


Nodo::Nodo(){

}

void Nodo::semantica(){
    cout<<"Base"<<endl;
}

void Nodo::muestra(){
    cout<<"Base"<<endl;
}



ObR1::ObR1(Nodo* definiciones):Nodo(){
    this->definiciones = definiciones;
}

void ObR1::muestra(){
    cout<<"<Programa>"<<endl;
    this->definiciones->muestra();
}

void ObR1::semantica(){
    this->definiciones->semantica();
}

ObR2::ObR2(string vacio):Nodo(){
    this->vacio = vacio;
}

void ObR2::muestra(){
    cout<<"<Definiciones>"<<endl;
    cout<<this->vacio<<endl;
}

void ObR2::semantica(){

}

ObR3::ObR3(Nodo* definicion, Nodo* definiciones):Nodo(){
    this->definicion = definicion;
    this->definiciones = definiciones;
}

void ObR3::muestra(){
    cout<<"<Definiciones>"<<endl;
    this->definicion->muestra();
    this->definiciones->muestra();
}

void ObR3::semantica(){

    this->definicion->semantica();
    this->definiciones->semantica();
}



ObR4::ObR4(Nodo* defvar):Nodo(){
    this->defvar = defvar;
}

void ObR4::muestra(){
    cout<<"<Definicion>"<<endl;
    this->defvar->muestra();
}

void ObR4::semantica(){

    this->defvar->semantica();
}

ObR5::ObR5(Nodo* defunc):Nodo(){
    this->defunc = defunc;
}

void ObR5::muestra(){
    cout<<"<Definicion>"<<endl;
    this->defunc->muestra();


}

void ObR5::semantica(){

    this->defunc->semantica();


}


ObR6::ObR6(string puntoycoma, Nodo* listavar,string identificador,string tipo):Nodo(){

    this->puntoycoma = puntoycoma;
    this->listavar = listavar;
    this->identificador = identificador;
    this->tipo = tipo;
}

void ObR6::muestra(){
    cout<<"<DefVar>"<<endl;
    cout<<this->tipo<<endl;
    cout<<this->identificador<<endl;
    this->listavar->muestra();
    cout<<this->puntoycoma<<endl;

}

void ObR6::semantica(){
    if(existenciavar(this->identificador,ambito)==true){
        cout<<"Error semantico, variable: "<<this->identificador<<" repetida"<<endl;
    }else{
        lvariables[fila][0] = this->tipo;
        lvariables[fila][1] = this->identificador;
        lvariables[fila][2] = ambito;
        lvariables[fila][3] = "no";
        tipoauxiliar = this->tipo;
        fila = fila + 1;
        this->listavar->semantica();
    }
    for(int i = 0; i < 5;i++){
        cout<<lvariables[i][0]<<" "<<lvariables[i][1]<<" "<<lvariables[i][2]<<" "<<lvariables[i][3]<<endl;
    }
}

ObR7::ObR7(string vacio):Nodo(){
    this->vacio = vacio;
}

void ObR7::muestra(){
    cout<<"<ListaVar>"<<endl;
    cout<<this->vacio<<endl;
}

ObR8::ObR8(string coma,string identificador,Nodo* listavar):Nodo(){

    this->coma = coma;
    this->listavar = listavar;
    this->identificador = identificador;
}

void ObR8::muestra(){
    cout<<"<ListaVar>"<<endl;
    cout<<this->coma<<endl;
    cout<<this->identificador<<endl;
    this->listavar->muestra();

}

void ObR8::semantica(){
    if(existenciavar(this->identificador,ambito)==true){
        cout<<"Error semantico, variable: "<<this->identificador<<" repetida"<<endl;
    }else{
        lvariables[fila][0] = tipoauxiliar;
        lvariables[fila][1] = this->identificador;
        lvariables[fila][2] = ambito;
        lvariables[fila][3] = "no";
        fila = fila + 1;
        this->listavar->semantica();
    }
    for(int i = 0; i < 5;i++){
        cout<<lvariables[i][0]<<" "<<lvariables[i][1]<<" "<<lvariables[i][2]<<" "<<lvariables[i][3]<<endl;
    }
}


ObR9::ObR9(string tipo,string identificador,string parentesis1,Nodo *parametros,string parentesis2,Nodo *bloqfunc):Nodo(){
    this->tipo = tipo;
    this->identificador = identificador;
    this->parentesis1 = parentesis1;
    this->parametros = parametros;
    this->parentesis2 = parentesis2;
    this->bloqfunc = bloqfunc;
}

void ObR9::muestra(){
    cout<<"<DefFunc>"<<endl;
    cout<<this->tipo<<endl;
    cout<<this->identificador<<endl;
    cout<<this->parentesis1<<endl;
    this->parametros->muestra();
    cout<<this->parentesis2<<endl;
    this->bloqfunc->muestra();

}

void ObR9::semantica(){
    if(existenciafunc(this->tipo,identificador)==true){
        cout<<"Error semantico, funcion: "<<this->identificador<<" repetida"<<endl;
    }else{
        lfunciones[filaf][0] = this->tipo;
        lfunciones[filaf][1] = this->identificador;
        filaf = filaf + 1;
        ambito = this->identificador;
        this->parametros->semantica();
        this->bloqfunc->semantica();
    }
    for(int i = 0; i < 5;i++){
        cout<<lfunciones[i][0]<<" "<<lfunciones[i][1]<<endl;
    }

}

ObR10::ObR10(string vacio):Nodo(){
    this->vacio = vacio;
}

void ObR10::muestra(){
    cout<<"<Parametros>"<<endl;
    cout<<this->vacio<<endl;
}
void ObR10::semantica(){

}

ObR11::ObR11(Nodo* listaparam,string identificador,string tipo):Nodo(){
    this->listaparam = listaparam;
    this->identificador = identificador;
    this->tipo = tipo;
}

void ObR11::muestra(){
    cout<<"<Parametros>"<<endl;
    cout<<this->tipo<<endl;
    cout<<this->identificador<<endl;
    this->listaparam->muestra();


}
void ObR11::semantica(){
    if(existenciavar(this->identificador,ambito)==true){
        cout<<"Error semantico, variable: "<<this->identificador<<" repetida"<<endl;
    }else{
        lvariables[fila][0] = this->tipo;
        lvariables[fila][1] = this->identificador;
        lvariables[fila][2] = ambito;
        lvariables[fila][3] = "no";
        tipoauxiliar = this->tipo;
        fila = fila + 1;
        this->listaparam->semantica();
    }
    for(int i = 0; i < 5;i++){
        cout<<lvariables[i][0]<<" "<<lvariables[i][1]<<" "<<lvariables[i][2]<<" "<<lvariables[i][3]<<endl;
    }


}


ObR12::ObR12(string vacio):Nodo(){
    this->vacio = vacio;
}

void ObR12::muestra(){
    cout<<"<ListaParam>"<<endl;
    cout<<this->vacio<<endl;
}

void ObR12::semantica(){

}

ObR13::ObR13(Nodo* listaparam,string identificador,string tipo, string coma):Nodo(){
    this->listaparam = listaparam;
    this-> coma = coma;
    this->identificador = identificador;
    this->tipo = tipo;
}

void ObR13::muestra(){
    cout<<"<ListaParam>"<<endl;
    cout<<this->coma<<endl;
    cout<<this->tipo<<endl;
    cout<<this->identificador<<endl;
    this->listaparam->muestra();


}

void ObR13::semantica(){
    if(existenciavar(this->identificador,ambito)==true){
        cout<<"Error semantico, variable: "<<this->identificador<<" repetida"<<endl;
    }else{
        lvariables[fila][0] = tipo;
        lvariables[fila][1] = this->identificador;
        lvariables[fila][2] = ambito;
        lvariables[fila][3] = "no";
        fila = fila + 1;
        this->listaparam->semantica();
    }
    for(int i = 0; i < 5;i++){
        cout<<lvariables[i][0]<<" "<<lvariables[i][1]<<" "<<lvariables[i][2]<<" "<<lvariables[i][3]<<endl;
    }


}

ObR14::ObR14(string llave1,Nodo* deflocales,string llave2):Nodo(){
    this->llave1 = llave1;
    this->deflocales = deflocales;
    this ->llave2 = llave2;
}

void ObR14::muestra(){
    cout<<"<BloqFunc>"<<endl;
    cout<<this->llave1<<endl;
    this->deflocales->muestra();
    cout<<this->llave2<<endl;


}

void ObR14::semantica(){
    this->deflocales->semantica();
}

ObR15::ObR15(string vacio):Nodo(){
    this->vacio = vacio;
}

void ObR15::muestra(){
    cout<<"<DefLocales>"<<endl;
    cout<<this->vacio<<endl;
}
void ObR15::semantica(){
}

ObR16::ObR16(Nodo* deflocal,Nodo* deflocales):Nodo(){
    this->deflocal = deflocal;
    this->deflocales = deflocales;
}

void ObR16::muestra(){
    cout<<"<DefLocales>"<<endl;
    this->deflocal->muestra();
    this->deflocales->muestra();


}
void ObR16::semantica(){
    this->deflocal->semantica();
    this->deflocales->semantica();


}

ObR17::ObR17(Nodo* defvar):Nodo(){
    this->defvar = defvar;
}

void ObR17::muestra(){
    cout<<"<DefLocal>"<<endl;
    this->defvar->muestra();


}

void ObR17::semantica(){

    this->defvar->semantica();


}

ObR18::ObR18(Nodo *sentencia):Nodo(){
    this->sentencia = sentencia;
}

void ObR18::muestra(){
    cout<<"<DefLocal>"<<endl;
    this->sentencia->muestra();
}

void ObR18::semantica(){

    this->sentencia->semantica();


}

ObR21::ObR21(string identificador,string igual,Nodo* expresion,string puntoycoma):Nodo(){
    this->identificador = identificador;
    this->igual = igual,
    this->expresion = expresion;
    this->puntoycoma = puntoycoma;
}

void ObR21::muestra(){
    cout<<"<Sentencia>"<<endl;
    cout<<this->identificador<<endl;
    cout<<this->igual<<endl;
    this->expresion->muestra();
    cout<<this->puntoycoma<<endl;


}

void ObR21::semantica(){
    if(existenciavar(this->identificador,ambito)==true){
        tipoauxiliar = getTipo(this->identificador,ambito);
        cout<<"El tipo es:"<<tipoauxiliar<<endl;
        auxvariable = this->identificador;
        this->expresion->semantica();
    }else{
        cout<<"Error semantico, variable: " <<this->identificador<<" No declarada"<<endl;
    }


}

ObR24::ObR24(string retur,Nodo *valorregresa,string puntoycoma):Nodo(){
    this->puntoycoma = puntoycoma;
    this->valorregresa = valorregresa;
    this->retur = retur;
}

void ObR24::muestra(){
    cout<<"<Sentencia>"<<endl;
    cout<<this->retur<<endl;
    this->valorregresa->muestra();
    cout<<this->puntoycoma<<endl;
}

void ObR24::semantica(){
    ret = true;
    tipoambito = getTipoAmbito();
    this->valorregresa->semantica();

}

ObR29::ObR29(string vacio):Nodo(){
    this->vacio = vacio;
}

void ObR29::muestra(){
    cout<<"<ValorRegresa>"<<endl;
    cout<<this->vacio<<endl;
}
void ObR29::semantica(){
    if(tipoambito == "void"){

    }else{
        cout<<"Error semantico, se esperaba tipo de dato despues de return"<<endl;
    }
}

ObR30::ObR30(Nodo *expresion):Nodo(){
    this->expresion = expresion;
}

void ObR30::muestra(){
    cout<<"<ValorRegresa>"<<endl;
    this->expresion->muestra();
}

void ObR30::semantica(){
    this->expresion->semantica();
}

ObR32::ObR32(Nodo *expresion,Nodo *listaargumentos):Nodo(){
    this->expresion = expresion;
    this->listaargumentos = listaargumentos;
}

void ObR32::muestra(){
    cout<<"<Argumentos>"<<endl;
    this->expresion->muestra();
    this->listaargumentos->muestra();
}

string ObR32::obtenerv(){
    cout<<"Entra"<<endl;
    return this->expresion->obtenerv();
}

ObR33::ObR33(string vacio):Nodo(){
    this->vacio = vacio;
}

void ObR33::muestra(){
    cout<<"<ListaArgumentos>"<<endl;
    cout<<this->vacio<<endl;
}

ObR34::ObR34(string coma, Nodo* expresion, Nodo* listaargumentos):Nodo(){
    this->coma = coma;
    this->expresion = expresion;
    this->listaargumentos = listaargumentos;
}

void ObR34::muestra(){
    cout<<"<ListaArgumentos>"<<endl;
    cout<<this->coma<<endl;
    this->expresion->muestra();
    this->listaargumentos->muestra();
}

ObR35::ObR35(Nodo* llamadafunc):Nodo(){
    this->llamadafunc = llamadafunc;
}

void ObR35::muestra(){
    cout<<"<Termino>"<<endl;
    this->llamadafunc->muestra();


}

void ObR35::semantica(){
    cout<<"<Termino>"<<endl;
    this->llamadafunc->semantica();


}


ObR36::ObR36(string identificador):Nodo(){
    this->identificador = identificador;
}


void ObR36::muestra(){
    cout<<"<Termino 6>"<<endl;
    cout<<this->identificador<<endl;
}





void ObR36::semantica(){
    string tipos;
    if(ret == true){
        tipos = getTipo(this->identificador,ambito);
        if(tipoambito == tipos){
        }else{
            cout<<"Error semantico, el tipo de datos que acepta la funcion no es compatible con el dato especificado: Funcion suma"<<endl;
            cout<<"Error semantico, el tipo de datos que acepta la funcion no es compatible con el dato especificado: Funcion suma"<<endl;
            ret = false;
        }
    }

    if(existenciavar(this->identificador,ambito)== true){
        tipos = getTipo(this->identificador,ambito);
        if(tipos != tipoauxiliar){
                if((tipos == "int" || tipos == "float") && (tipoauxiliar == "int" || tipoauxiliar == "float")){
                    cout<<"Tipos de datos no compatibles en opSuma"<<endl;
                }
                else{
                    cout<<"Error semantico, tipos de datos no compatibles"<<endl;
                }

        }
    }else{
        cout<<"Error semantico, variable: "<<this->identificador<<" No declarada"<<endl;
    }
}

string ObR36::obtenerv(){

    if(especial == true){

        iden = true;
    }

    return this->identificador;
}

ObR37::ObR37(string entero):Nodo(){
    this->entero = entero;
}

void ObR37::muestra(){
    cout<<"<Termino>"<<endl;
    cout<<this->entero<<endl;
}

string ObR37::obtenerv(){
    iden = false;
    return this->entero;
}

void ObR37::semantica(){
    if(ret == true){
        if(tipoambito == "int"){
        }else{
            cout<<"Error semantico, se esperaba un int en el tipo de ambito"<<endl;
            ret = false;
        }
    }

    if(tipoauxiliar == "float"){
        cout<<"Warning, tipos diferentes pero compatibles"<<endl;
    }else if(tipoauxiliar == "int"){
        agregarvalor(ambito,auxvariable,this->entero);
        printvalores();
    }else{
        cout<<"Error semantico, tipo de datos no compatibles"<<endl;
    }//end if else
}

ObR38::ObR38(string real):Nodo(){
    this->real = real;
}

void ObR38::muestra(){
    cout<<"<Termino>"<<endl;
    cout<<this->real<<endl;
}

void ObR38::semantica(){
    if(ret == true){
        if(tipoambito == "float"){
        }else{
            cout<<"Error semantico, se esperaba un float en el tipo de ambito"<<endl;
            ret = false;
        }
    }
    if(tipoauxiliar == "float"){

    }else if(tipoauxiliar == "int"){
        cout<<"Warning, tipos diferentes pero compatibles"<<endl;
    }else{
        cout<<"Error semantico, tipo de datos no compatibles"<<endl;
    }//end if else
}

ObR39::ObR39(string cadena):Nodo(){
    this->cadena = cadena;
}

void ObR39::muestra(){
    cout<<"<Termino>"<<endl;
    cout<<this->cadena<<endl;
}

void ObR39::semantica(){
    if(tipoauxiliar == "float"){
        cout<<"Error semantico, tipo de datos no compatibles"<<endl;
    }else if(tipoauxiliar == "int"){
        cout<<"Error semantico, tipo de datos no compatibles"<<endl;
    }else if(tipoauxiliar == "string"){

    }//end if else
}

ObR40::ObR40(string identificador,string parentesis1,Nodo *argumentos,string parentesis2):Nodo(){
    this->identificador = identificador;
    this->parentesis1 = parentesis1;
    this->argumentos = argumentos;
    this->parentesis2 = parentesis2;
}

void ObR40::muestra(){
    cout<<"<LlamadaFunc>"<<endl;
    cout<<this->identificador<<endl;
    cout<<this->parentesis1<<endl;
    this->argumentos->muestra();
    cout<<this->parentesis2<<endl;
}

void ObR40::semantica(){
    string valor;
    string funcion;
    long double res;
    int valores;
    bool reservado = false;
    if(this->identificador == "sin" || this->identificador == "cos" || this->identificador == "tan"){
        reservado = true;
        funcion = this->identificador;
        cout<<"Se reserva"<<endl;
    }

    if(existenciafunc2(this->identificador)==true){
        cout<<"No problem"<<endl;
    }else{
        if(reservado == false){
            cout<<"Error semantico, la funcion "<<this->identificador<<" No esta definida"<<endl;
        }else{
            cout<<"Funcion reservada: "<<this->identificador<<endl;
        }

    }
    if(reservado == true){
        especial = true;
        funcionauxiliar = this->identificador;
        valor = this->argumentos->obtenerv();
        if(iden == true){
            cout<<"entra"<<endl;
            string numero = obtvalores(valor);
            cout<<numero<<endl;
            valor = numero;

        }
        cout<<"El valor es"<<valor<<endl;
        valores = stoi(valor);
        long double v2 = valores;
        if(funcion == "sin"){
            res = calculadora.LD_SIN(v2);
            cout<<"El seno es: "<<res<<endl;

        }else if(funcion == "cos"){
            res = calculadora.LD_COS(v2);
            cout<<"El coseno es: "<<res<<endl;
        }else if(funcion == "tan"){
            res = calculadora.LD_TAN(v2);
            cout<<"La tangente es: "<<res<<endl;
        }

    }
}

ObR46::ObR46(Nodo* expresion1,string opmul,Nodo* expresion2):Nodo(){
    this->expresion1 = expresion1;
    this->opmul = opmul;
    this->expresion2 = expresion2;
}

void ObR46::muestra(){
    cout<<"<Expresion>"<<endl;
    this->expresion1->muestra();
    cout<<this->opmul<<endl;
    this->expresion2->muestra();


}



void ObR46::semantica(){
    cout<<"HOLA2"<<endl;
    auxoperador = this->opmul;
    cout<<auxoperador;
    this->expresion1->semantica();
    this->expresion2->semantica();
    string val1;
    string val2;
    string v1;
    string v2;
    int n1;
    int n2;
    int n3;
    val1 = this->expresion1->obtenerv();
    val2 = this->expresion2->obtenerv();
    cout<<val1<<endl;
    cout<<val2<<endl;
    v1 = obtvalores(val1);
    v2 = obtvalores(val2);
    cout<<v1<<endl;
    cout<<v2<<endl;
    n1 = stoi(v1);
    n2 = stoi(v2);
    cout<<n1<<endl;
    cout<<n2<<endl;
    if(auxoperador == "*"){
        n3 = calculadora.mul(n1,n2);
        cout<<"El resultado es: "<<n3<<endl;
    }else if(auxoperador == "/"){
        n3 = calculadora.divl(n1,n2);
        cout<<"El resultado es: "<<n3<<endl;
    }



}

ObR47::ObR47(Nodo* expresion1,string opsuma,Nodo* expresion2):Nodo(){
    this->expresion1 = expresion1;
    this->opsuma = opsuma;
    this->expresion2 = expresion2;
}

void ObR47::muestra(){
    cout<<"<Expresion>"<<endl;
    this->expresion1->muestra();
    cout<<this->opsuma<<endl;
    this->expresion2->muestra();


}

void ObR47::semantica(){

    auxoperador = this->opsuma;
    cout<<auxoperador;

    this->expresion1->semantica();
    this->expresion2->semantica();
    string val1;
    string val2;
    string v1;
    string v2;
    int n1;
    int n2;
    int n3;
    val1 = this->expresion1->obtenerv();
    val2 = this->expresion2->obtenerv();
    cout<<val1<<endl;
    cout<<val2<<endl;
    v1 = obtvalores(val1);
    v2 = obtvalores(val2);
    cout<<v1<<endl;
    cout<<v2<<endl;
    n1 = stoi(v1);
    n2 = stoi(v2);
    cout<<n1<<endl;
    cout<<n2<<endl;
    if(auxoperador == "+"){
        n3 = calculadora.add(n1,n2);
        cout<<"El resultado es: "<<n3<<endl;
    }else if(auxoperador == "-"){
        n3 = calculadora.sub(n1,n2);
        cout<<"El resultado es: "<<n3<<endl;
    }



}

ObR52::ObR52(Nodo* termino):Nodo(){
    this->termino = termino;
}

void ObR52::muestra(){
    cout<<"<Expresion>"<<endl;
    this->termino->muestra();


}

string ObR52::obtenerv(){
    return this->termino->obtenerv();
}

void ObR52::semantica(){
    this->termino->semantica();


}


//Reglas de prueba
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

//Elementos pila

ElementoPila::ElementoPila(){
}

void ElementoPila::usadas(){
}

void ElementoPila::identificate(){
    cout<<"Base"<<endl;
}

void ElementoPila::muestra(){
    cout<<"Base"<<endl;
}

void ElementoPila::semantica(){
    cout<<"esto no"<<endl;
}

Nodo* ElementoPila::DevuelveNodo(){
    return nullptr;
}


Estado::Estado(int valor):ElementoPila(){
    this->elemento = valor;
}

void Estado::muestra(){
    cout<<this->elemento<<endl;
}

int Estado::getElemento(){
    return this->elemento;
}

void Estado::identificate(){
    cout<<"Soy Estado"<<endl;
}

void Terminal::muestra(){
    cout<<this->elemento;
}

Terminal::Terminal(string valor):ElementoPila(){
    this->elemento = valor;

}

void Terminal::identificate(){
    cout<<"Soy Terminal"<<endl;
}

string Terminal::getElementos(){
    return this->elemento;
}

void NoTerminal::muestra(){
    this->siguiente->muestra();
}

void NoTerminal::identificate(){
    cout<<"Soy No Terminal"<<endl;
}

void NoTerminal::semantica(){
    this->siguiente->semantica();
}

void NoTerminal::usadas(){
    utilizadas();
}

NoTerminal::NoTerminal(Nodo* nodo):ElementoPila(){
    this->siguiente = nodo;


}



Nodo* NoTerminal::DevuelveNodo(){
    return this->siguiente;

}


//Funciones pila

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

     }

     cout << endl;
  }
