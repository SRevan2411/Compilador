# Compilador
Proyecto de Traductores de Lenguajes.

Desarrollado por: Pérez Flores Eduardo Rafael

## Etapas de desarrollo-Modulos

1. Modulo 1: Analizador Léxico
  
  
## Modulo 1
### Analizador léxico
Funcionamiento:
Utiliza un automata para decidir que tipo de cadena es la analizada \
Enlace al README correspondiente: https://github.com/SRevan2411/Compilador/tree/main/Analizador%20Lexico/Codigo
## Modulo 2
### Analizador sintáctico
Funcionamiento:
Utiliza gramática del compilador (LR) para validar la sintáctica y genera un árbol sintáctico

## Modulo 3
### Analizador semántico
Funcionamiento:
Utiliza el árbol sintáctico y realiza recorridos, se apoya de tablas de variables para comprobar la semántica
## Modulo 4
### Generación de código
Funcionamiento:
Una vez validado lo anterior vuelve a hacer un recorrido al árbol y utiliza ensablador insertado para traducir el código de entrada
y lo ejecuta
