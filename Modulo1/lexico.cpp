#include <iostream>

using namespace std;

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
            }else{
                cout<<"Cadena no valida Estado 1"<<endl;
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
                break;
            }//end else
            break;
        case 4:
            if(EsDigito(cadena[i]) == true){
                Estado = 5;
            }else{
                cout<<"Cadena no valida Estado 4"<<endl;
                break;
            }//end if else      
            break;
        case 5:
            if(EsDigito(cadena[i]) == true){
                Estado = 5;
            }else{
                cout<<"Cadena no valida Estado 5"<<endl;
                break;
            }//end if else  
            break;
        default:
            cout<<"Estdo no esperado"<<endl;
            break;
        }//end switch
    }//end for

    switch (Estado)
    {
    case 2:
        cout<<"Identificador"<<endl;
        return 0;
        break;
    case 3:
        cout<<"Entero"<<endl;
        return 1;
        break;
    case 5:
        cout<<"Real"<<endl;
        return 2;
        break;
    default:
        break;
    }
}//end AutomataLexico


int main(){
    string separador;
    string datos = "hola25a mundo tiene palabras 25 23.2 1.1";
    for(int i = 0; i < datos.size(); i++){
        if(datos[i] !=' '){
            separador += datos[i];
        }else{
            AutomataLexico(separador);
            separador = "";
        }//end if else
    }//end for
    if(separador != ""){
        AutomataLexico(separador);
        separador = "";
    }//end if
}//end main