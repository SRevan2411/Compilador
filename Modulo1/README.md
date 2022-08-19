# Mini analizador Léxico

Este programa está basado en un autómata de estados.
Las gramáticas que acepta son las siguientes:
* **identificadores = letra(letra|digito)***
* **Real = entero.entero+**

## Funciones

### EsLetra
Esta función retorna *true* si el caracter analizado corresponde a una letra

### EsDigito
Esta función retorna *true* si el caracter analizado corresponde a un dígito

### AutomataLexico
Esta función recibe una cadena y la analiza.
Está basada en el siguiente autómata:

![](/../main/Imagenes/patricio.jpg)
