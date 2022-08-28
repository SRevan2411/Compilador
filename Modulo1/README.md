# Mini analizador Sintáctico

Se añadieron 2 funciones
* AnalizadorSintactico
* StoreMatriz

La primera es el funcionamiento del mini analizador sintáctico
La segunda solo se encaarga de llenar la matriz a utilizar

## Capturas de funciones
### AnalizadorSintactico
![Analizador](Capturas/Sintactico.png)
### StoreMatriz
![Analizador](Capturas/Matriz.png)

## Funcionamiento

El programa utiliza tablas LR y una pila, en si es un ciclo while infinito que se detiene cuando se valida
la gramática. En cada vuelta del ciclo se obtiene un elemento de la matriz y verifica si es positivo (para
añadir elementos a la pila) o negativo (Para relizar las reducciones).

En cada reducción se quitan los elementos de la gramática multiplicados por 2

## Tablas LR

![LR1](Capturas/LR1.png)

![LR2](Capturas/LR2.png)

## Pruebas de funcionamiento

![Test1](Capturas/MiniSalida1.png)

![Test2](Capturas/MiniSalida2.png)


