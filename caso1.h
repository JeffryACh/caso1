/*
    * caso1.h
    *
    * Created on: 21/08/2023 11:45
    * 
    * Last modified on: 
    * 
    * Author: Jeffry Alberto Araya Chaves.
*/

/*
    * Description: 
    * un ejecutivo le ha pedido que le facilite una forma rápida de poder leer los titulares de noticias que le interesan únicamente, y solo aquellas que son más relevantes.
    * Para ello, esa persona quiere un programa en C++ donde le pueda dar una única palabra que sea el tópico de su interés y la fecha a partir del cual quiere saber acerca del tema.
    * Con esa información el programa obtiene un conjunto de titulares que tienen que ver con el tema seleccionado.
    * Una vez que el programa obtiene todos los titulares de las noticias, le muestra únicamente los 5 más relevantes, en orden de relevancia siempre.
*/

/*
    * Acciones:
    a) Mostrar todas las noticias ordenadas por relevancia
    b) Mostrar solo aquellos titulares que contengan al menos una vez una palabra de una lista proporcionada como input del usuario, donde cada palabra es separada por coma ,
    c) Eliminar de la lista de noticias, todas aquellas que tengan al menos una vez una palabra de una lista proporcionada como input del usuario, donde cada palabra es separada por coma ,
    d) Subir o bajar un titular de relevancia, es decir, indicando la posición actual del titular, puede indicarle ya sea un +Y o -Y, de tal forma que el titular sube o baja de posición de relevancia según el desplazamiento indicado por Y, por ejemplo si una noticia está en la posición 16, si el usuario indica reubicar(16, +7), pasaría a la posición 9.
    * Cuando muestra los titulares, debe mostrar el número de posición de relevancia donde se encuentra el titular 1, 2, 3...N, y el titular respectivo.
*/

/*
    Preliminar #1:
    1) Determine que tipo de lista va a requerir para implementar el programa, ya sea lista simple, doblemente enlazada, circular, o doblemente enlazada circular
    2) Determine cuáles métodos del TAD lista seleccionado necesita tener implementados y escribalos en un archivo .h, no hace falta que tengan body, pero si agregue comentarios indicando lo que supuestamente haría el método
    3) Determine que métodos de operación para agregar, buscar, eliminar y reordenar titulares se van a necesitar y a cuáles métodos de la lista seleccionada va a ser necesario llamarlos, escriba esos métodos en un archivo .h, no hace falta que tengan body, pero si agregue comentarios indicando lo que supuestamente haría el método
    4) Deberá enviar esto listo al profesor vía discord, usando un mensaje directo, a más tardar a las 10pm, indique su nombre completo y el link de github donde hizo commit del código
*/

// Preliminar #1 a) Determine que tipo de lista va a requerir para implementar el programa, ya sea lista simple, doblemente enlazada, circular, o doblemente enlazada circular
// Se utilizará una lista doblemente enlazada circular
/*
    * Lista doblemente enlazada circular:
    * Es una lista doblemente enlazada, donde el último nodo apunta al primero y el primero apunta al último.
    * La usare porque es una lista que permite recorrerla en ambos sentidos, y al ser circular, no se pierde el primer nodo.
    * Además, al ser doblemente enlazada, permite recorrerla en ambos sentidos.
*/

// Preliminar #1 b) Determine cuáles métodos del TAD lista seleccionado necesita tener implementados y escribalos en un archivo .h, no hace falta que tengan body, pero si agregue comentarios indicando lo que supuestamente haría el método
/*
    * Métodos:
    * 1) Insertar al inicio
    * 2) Insertar al final
    * 3) Insertar en una posición
    * 4) Eliminar al inicio
    * 5) Eliminar al final
    * 6) Eliminar en una posición
    * 7) Buscar por posición
    * 8) Buscar por valor
    * 9) Modificar por posición
    * 10) Modificar por valor
    * 11) Mostrar lista total
    * 12) Mostrar lista por relevancia
    * 13) Mostrar lista por almenos una palabra proporcionada por el usuario
*/

// Preliminar #1 c) Determine que métodos de operación para agregar, buscar, eliminar y reordenar titulares se van a necesitar y a cuáles métodos de la lista seleccionada va a ser necesario llamarlos, escriba esos métodos en un archivo .h, no hace falta que tengan body, pero si agregue comentarios indicando lo que supuestamente haría el método
/*
    * Métodos:
    * 1) Agregar titular
        a) Agregar titular al inicio
        b) Agregar titular al final
        c) Agregar titular en una posición
    * 2) Buscar titular
        a) Buscar titular por posición
        b) Buscar titular por valor
    * 3) Eliminar titular
        a) Eliminar titular al inicio
        b) Eliminar titular al final
        c) Eliminar titular en una posición
    * 4) Reordenar titular
        a) Reordenar titular por posición
        b) Reordenar titular por valor
    * 5) Mostrar titulares
        a) Mostrar titulares totales
        b) Mostrar titulares por relevancia
        c) Mostrar titulares por almenos una palabra proporcionada por el usuario
*/