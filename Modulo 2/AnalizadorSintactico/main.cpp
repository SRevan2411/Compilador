#include "pila.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;
//Variables globales


Pila p1;
stack<int> pila;

int E = 3;
int Matriz[5][4];
int Array[20] = {2,0,0,1,0,0,-1,0,0,3,0,0,4,0,0,0,0,0,-2,0};
int Array2[20] = {2,0,0,1,0,0,-1,0,0,3,-3,0,2,0,0,4,0,0,-2,0};

void StoreMatriz(){
    int h = 0;
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            Matriz[i][j] = Array2[h];
            h++;
        }//end for
    }//end for

    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            cout<<Matriz[i][j]<<" ";
            h++;
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
            }else if(cadena[i]== 39){
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
        return 1;
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
        cout<<"'"<<endl;
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
        cout<<")"<<endl;
        return 16;
        break;
    case 27:
        cout<<")"<<endl;
        return 17;
        break;
    case 28:
        cout<<"$"<<endl;
        return 2;
        break;
    default:
        break;
    }
}//end AutomataLexico

bool nAnalizadorS(int operando){
    ElementoPila *t1 = p1.top();
    if(t1->esTerminal()==true){
        cout<<"Hey"<<endl;
    }


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
            AnalizadorSintactico(elemento);
            separador = "";
        }//end if else
    }//end for
    if(separador != ""){
        elemento = AutomataLexico(separador);
        cout<<elemento<<endl;
        AnalizadorSintactico(elemento);
    }//end if
    while(flag == false){
        cout<<"entra"<<endl;
        flag = AnalizadorSintactico(elemento);
    }
}


int main(){
    Terminal *t1;
    Terminal *t2;
    t1 = new Terminal(2);
    t2 = new Terminal(0);
    p1.push(t1);
    p1.push(t2);
    nAnalizadorS(1);
    /*
    string cadena = "hola + mundo $";
    pila.push(2);
    pila.push(0);
    //cout<<"Ingrese la cadena a analizar: "<<endl;
    //getline(cin,cadena);
    StoreMatriz();
    separarCadena(cadena);
    */
}//end main
