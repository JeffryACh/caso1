/*
    * caso1.cpp
    *
    * Created on: 21/08/2023 11:45
    * 
    * Last modified on: 25/08/2023 12:40 
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
    2) Determine cuáles métodos del TAD lista seleccionado necesita tener implementados y escribalos en un archivo .cpp, no hace falta que tengan body, pero si agregue comentarios indicando lo que supuestamente haría el método
    3) Determine que métodos de operación para agregar, buscar, eliminar y reordenar titulares se van a necesitar y a cuáles métodos de la lista seleccionada va a ser necesario llamarlos, escriba esos métodos en un archivo .cpp, no hace falta que tengan body, pero si agregue comentarios indicando lo que supuestamente haría el método
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

// Preliminar #1 c) Determine que métodos de operación para agregar, buscar, eliminar y reordenar titulares se van a necesitar y a cuáles métodos de la lista seleccionada va a ser necesario llamarlos, escriba esos métodos en un archivo .cpp, no hace falta que tengan body, pero si agregue comentarios indicando lo que supuestamente haría el método
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

#include <iostream> // Para usar cout y cin
#include <string> // Para usar string

using namespace std; // Para no tener que escribir std::cout o std::cin

struct Node // Estructura de un nodo
{
    // Atributos públicos
    int relevancia; // Relevancia del titular
    string titular; // Titular de la noticia
    Node *next; // Puntero al siguiente nodo
    Node *prev; // Puntero al nodo anterior
};

class Queue // 
{
    // Atributos privados
    private:
        Node *head; // Puntero al primer nodo
        Node *tail; // Puntero al último nodo
        int size; // Tamaño de la lista
    public:
        // Constructor y destructor
        Queue()
        {
            head = NULL; // Inicializa el puntero al primer nodo en NULL
            tail = NULL; // Inicializa el puntero al último nodo en NULL
            size = 0; // Inicializa el tamaño de la lista en 0
        }
        ~Queue()
        {
            delete head; // Elimina el puntero al primer nodo
            delete tail; // Elimina el puntero al último nodo
        }

        // Métodos

        // Getters
        void insertarAlInicio(int relevancia, string titular) // Inserta un nodo al inicio de la lista
        {
            Node *newNode = new Node(); // Crea un nuevo nodo
            newNode->relevancia = relevancia; // Asigna la relevancia al nuevo nodo
            newNode->titular = titular; // Asigna el titular al nuevo nodo
            if (head == NULL) // Si el puntero al primer nodo es NULL
            {
                head = newNode; // El puntero al primer nodo apunta al nuevo nodo
                tail = newNode; // El puntero al último nodo apunta al nuevo nodo
                head->next = head; // El puntero al siguiente nodo del nuevo nodo apunta al primer nodo
                head->prev = head; // El puntero al nodo anterior del nuevo nodo apunta al primer nodo
            }
            else // Si el puntero al primer nodo no es NULL
            {
                newNode->next = head; // El puntero al siguiente nodo del nuevo nodo apunta al primer nodo
                newNode->prev = tail; // El puntero al nodo anterior del nuevo nodo apunta al último nodo
                head->prev = newNode; // El puntero al nodo anterior del primer nodo apunta al nuevo nodo
                tail->next = newNode; // El puntero al siguiente nodo del último nodo apunta al nuevo nodo
                head = newNode; // El puntero al primer nodo apunta al nuevo nodo
            }
            size++; // Incrementa el tamaño de la lista
        };
        void insertarAlFinal(int relevancia, string titular) // Inserta un nodo al final de la lista
        {
            Node *newNode = new Node(); // Crea un nuevo nodo
            newNode->relevancia = relevancia; // Asigna la relevancia al nuevo nodo
            newNode->titular = titular; // Asigna el titular al nuevo nodo
            if (head == NULL) // Si el puntero al primer nodo es NULL
            {
                head = newNode; // El puntero al primer nodo apunta al nuevo nodo
                tail = newNode; // El puntero al último nodo apunta al nuevo nodo
                head->next = head; // El puntero al siguiente nodo del nuevo nodo apunta al primer nodo
                head->prev = head; // El puntero al nodo anterior del nuevo nodo apunta al primer nodo
            }
            else // Si el puntero al primer nodo no es NULL
            {
                newNode->next = head; // El puntero al siguiente nodo del nuevo nodo apunta al primer nodo
                newNode->prev = tail; // El puntero al nodo anterior del nuevo nodo apunta al último nodo
                head->prev = newNode; // El puntero al nodo anterior del primer nodo apunta al nuevo nodo
                tail->next = newNode; // El puntero al siguiente nodo del último nodo apunta al nuevo nodo
                tail = newNode; // El puntero al último nodo apunta al nuevo nodo
            }
            size++; // Incrementa el tamaño de la lista
        };
        void insertarEnPsosicion(int relevancia, string titular, int posicion) // Inserta un nodo en una posición de la lista
        {
            if (posicion == 1) // Si la posición es 1
            {
                insertarAlInicio(relevancia, titular); // Inserta el nodo al inicio de la lista
            }
            else if (posicion == size + 1) // Si la posición es igual al tamaño de la lista más 1
            {
                insertarAlFinal(relevancia, titular); // Inserta el nodo al final de la lista
            }
            else if (posicion > 1 && posicion <= size) // Si la posición es mayor a 1 y menor o igual al tamaño de la lista
            {
                Node *newNode = new Node(); // Crea un nuevo nodo
                newNode->relevancia = relevancia; // Asigna la relevancia al nuevo nodo
                newNode->titular = titular; // Asigna el titular al nuevo nodo
                Node *aux = head; // Crea un nodo auxiliar y lo inicializa con el puntero al primer nodo
                for (int i = 1; i < posicion - 1; i++) // Recorre la lista hasta la posición anterior a la posición indicada
                {
                    aux = aux->next; // El puntero al siguiente nodo del nodo auxiliar apunta al siguiente nodo del nodo auxiliar
                }
                newNode->next = aux->next; // El puntero al siguiente nodo del nuevo nodo apunta al siguiente nodo del nodo auxiliar
                newNode->prev = aux; // El puntero al nodo anterior del nuevo nodo apunta al nodo auxiliar
                aux->next->prev = newNode; // El puntero al nodo anterior del siguiente nodo del nodo auxiliar apunta al nuevo nodo
                aux->next = newNode; // El puntero al siguiente nodo del nodo auxiliar apunta al nuevo nodo
                size++; // Incrementa el tamaño de la lista
            }
            else // Si la posición es menor a 1 o mayor al tamaño de la lista
            {
                cout << "La posicion no es valida" << endl; // Imprime un mensaje de error
            }
        };

        // Deleters
        void eliminarAlInicio() // Elimina un nodo al inicio de la lista
        {
            if (head == NULL) // Si el puntero al primer nodo es NULL
            {
                cout << "La lista esta vacia" << endl; // Imprime un mensaje de error
            }
            else if (head == tail) // Si el puntero al primer nodo es igual al puntero al último nodo
            {
                head = NULL; // El puntero al primer nodo apunta a NULL
                tail = NULL; // El puntero al último nodo apunta a NULL
                size--; // Decrementa el tamaño de la lista
            }
            else // Si el puntero al primer nodo no es NULL y es diferente al puntero al último nodo
            {
                head = head->next; // El puntero al primer nodo apunta al siguiente nodo del primer nodo
                head->prev = tail; // El puntero al nodo anterior del primer nodo apunta al último nodo
                tail->next = head; // El puntero al siguiente nodo del último nodo apunta al primer nodo
                size--; // Decrementa el tamaño de la lista
            }
        };
        void eliminarAlFinal() // Elimina un nodo al final de la lista
        {
            if (head == NULL) // Si el puntero al primer nodo es NULL
            {
                cout << "La lista esta vacia" << endl; // Imprime un mensaje de error
            }
            else if (head == tail) // Si el puntero al primer nodo es igual al puntero al último nodo
            {
                head = NULL; // El puntero al primer nodo apunta a NULL
                tail = NULL; // El puntero al último nodo apunta a NULL
                size--; // Decrementa el tamaño de la lista
            }
            else // Si el puntero al primer nodo no es NULL y es diferente al puntero al último nodo
            {
                tail = tail->prev; // El puntero al último nodo apunta al nodo anterior del último nodo
                tail->next = head; // El puntero al siguiente nodo del último nodo apunta al primer nodo
                head->prev = tail; // El puntero al nodo anterior del primer nodo apunta al último nodo
                size--; // Decrementa el tamaño de la lista
            }
        };
        void eliminarEnPosicion(int posicion) // Elimina un nodo en una posición de la lista
        {
            if (posicion == 1) // Si la posición es 1
            {
                eliminarAlInicio(); // Elimina el nodo al inicio de la lista
            }
            else if (posicion == size) // Si la posición es igual al tamaño de la lista
            {
                eliminarAlFinal(); // Elimina el nodo al final de la lista
            }
            else if (posicion > 1 && posicion < size) // Si la posición es mayor a 1 y menor al tamaño de la lista
            {
                Node *aux = head; // Crea un nodo auxiliar y lo inicializa con el puntero al primer nodo
                for (int i = 1; i < posicion; i++) // Recorre la lista hasta la posición indicada
                {
                    aux = aux->next; // El puntero al siguiente nodo del nodo auxiliar apunta al siguiente nodo del nodo auxiliar
                }
                aux->prev->next = aux->next; // El puntero al siguiente nodo del nodo anterior del nodo auxiliar apunta al siguiente nodo del nodo auxiliar
                aux->next->prev = aux->prev; // El puntero al nodo anterior del siguiente nodo del nodo auxiliar apunta al nodo anterior del nodo auxiliar
                size--; // Decrementa el tamaño de la lista
            }
            else // Si la posición es menor a 1 o mayor o igual al tamaño de la lista
            {
                cout << "La posicion no es valida" << endl; // Imprime un mensaje de error
            }
        };
        void eliminarTitualar(string titular) // Elimina un nodo con un titular de la lista
        {
            Node *aux = head; // Crea un nodo auxiliar y lo inicializa con el puntero al primer nodo
            for (int i = 1; i <= size; i++) // Recorre la lista
            {
                if (aux->titular == titular) // Si el titular del nodo auxiliar es igual al titular indicado
                {
                    eliminarEnPosicion(i); // Elimina el nodo en la posición indicada
                    break; // Rompe el ciclo
                }
                aux = aux->next; // El puntero al siguiente nodo del nodo auxiliar apunta al siguiente nodo del nodo auxiliar
            }
        };

        // Searchers
        void buscarPorPosicion(int posicion) // Busca un nodo por posición de la lista
        {
            if (posicion > 0 && posicion <= size) // Si la posición es mayor a 0 y menor o igual al tamaño de la lista
            {
                Node *aux = head; // Crea un nodo auxiliar y lo inicializa con el puntero al primer nodo
                for (int i = 1; i < posicion; i++) // Recorre la lista hasta la posición indicada
                {
                    aux = aux->next; // El puntero al siguiente nodo del nodo auxiliar apunta al siguiente nodo del nodo auxiliar
                }
                cout << "Relevancia: " << aux->relevancia << endl; // Imprime la relevancia del nodo auxiliar
                cout << "Titular: " << aux->titular << endl; // Imprime el titular del nodo auxiliar
            }
            else // Si la posición es menor o igual a 0 o mayor al tamaño de la lista
            {
                cout << "La posicion no es valida" << endl; // Imprime un mensaje de error
            }
        };
        void buscarPorTitular(string titular) // Busca un nodo por titular de la lista
        {
            Node *aux = head; // Crea un nodo auxiliar y lo inicializa con el puntero al primer nodo
            for (int i = 1; i <= size; i++) // Recorre la lista
            {
                if (aux->titular == titular) // Si el titular del nodo auxiliar es igual al titular indicado
                {
                    cout << "Relevancia: " << aux->relevancia << endl; // Imprime la relevancia del nodo auxiliar
                    cout << "Titular: " << aux->titular << endl; // Imprime el titular del nodo auxiliar
                    break; // Rompe el ciclo
                }
                aux = aux->next; // El puntero al siguiente nodo del nodo auxiliar apunta al siguiente nodo del nodo auxiliar
            }
        };

        // Setters
        void modificarPorPosicion(int posicion, int relevancia, string titular) // Modifica un nodo por posición de la lista
        {
            if (posicion > 0 && posicion <= size) // Si la posición es mayor a 0 y menor o igual al tamaño de la lista
            {
                Node *aux = head; // Crea un nodo auxiliar y lo inicializa con el puntero al primer nodo
                for (int i = 1; i < posicion; i++) // Recorre la lista hasta la posición indicada
                {
                    aux = aux->next; // El puntero al siguiente nodo del nodo auxiliar apunta al siguiente nodo del nodo auxiliar
                }
                aux->relevancia = relevancia; // Asigna la relevancia al nodo auxiliar
                aux->titular = titular; // Asigna el titular al nodo auxiliar
            }
            else // Si la posición es menor o igual a 0 o mayor al tamaño de la lista
            {
                cout << "La posicion no es valida" << endl; // Imprime un mensaje de error
            }
        };
        void modificarPorTitular(string titular, int relevancia, string titularNuevo) // Modifica un nodo por titular de la lista
        {
            Node *aux = head; // Crea un nodo auxiliar y lo inicializa con el puntero al primer nodo
            for (int i = 1; i <= size; i++) // Recorre la lista
            {
                if (aux->titular == titular) // Si el titular del nodo auxiliar es igual al titular indicado
                {
                    aux->relevancia = relevancia; // Asigna la relevancia al nodo auxiliar
                    aux->titular = titularNuevo; // Asigna el titular al nodo auxiliar
                    break; // Rompe el ciclo
                }
                aux = aux->next; // El puntero al siguiente nodo del nodo auxiliar apunta al siguiente nodo del nodo auxiliar
            }
        };
        void modificarRelevancia(string titular, int relevancia)
        {
            Node *aux = head; // Crea un nodo auxiliar y lo inicializa con el puntero al primer nodo
            for (int i = 1; i <= size; i++) // Recorre la lista
            {
                if (relevancia > 0) // Si la relevancia es mayor a 0
                {
                    if (aux->titular == titular) // Si el titular del nodo auxiliar es igual al titular indicado
                    {
                        aux->relevancia -= relevancia; // Asigna la relevancia al nodo auxiliar
                        break; // Rompe el ciclo
                    }
                    aux = aux->next; // El puntero al siguiente nodo del nodo auxiliar apunta al siguiente nodo del nodo auxiliar
                }
                else // Si la relevancia es menor o igual a 0
                {
                    if (aux->titular == titular) // Si el titular del nodo auxiliar es igual al titular indicado
                    {
                        aux->relevancia += relevancia; // Asigna la relevancia al nodo auxiliar
                        break; // Rompe el ciclo
                    }
                    aux = aux->next; // El puntero al siguiente nodo del nodo auxiliar apunta al siguiente nodo del nodo auxiliar
                }
            }
        };

        // Showers
        void mostrarListaTotal() // Muestra la lista total
        {
            Node *aux = head; // Crea un nodo auxiliar y lo inicializa con el puntero al primer nodo
            for (int i = 1; i <= size; i++) // Recorre la lista
            {
                cout << "Relevancia: " << aux->relevancia << endl; // Imprime la relevancia del nodo auxiliar
                cout << "Titular: " << aux->titular << endl; // Imprime el titular del nodo auxiliar
                aux = aux->next; // El puntero al siguiente nodo del nodo auxiliar apunta al siguiente nodo del nodo auxiliar
            }
        };
        void mostrarListaPorRelevancia() // Muestra la lista por relevancia
        {
            Node *aux = head; // Crea un nodo auxiliar y lo inicializa con el puntero al primer nodo
            for (int i = 1; i <= size; i++) // Recorre la lista
            {
                cout << "Relevancia: " << aux->relevancia << endl; // Imprime la relevancia del nodo auxiliar
                cout << "Titular: " << aux->titular << endl; // Imprime el titular del nodo auxiliar
                aux = aux->next; // El puntero al siguiente nodo del nodo auxiliar apunta al siguiente nodo del nodo auxiliar
            }
        };
        void mostrarTop5Noticias() // Muestra los 5 titulares con más relevancia
        {
            Node *aux = head; // Crea un nodo auxiliar y lo inicializa con el puntero al primer nodo
            for (int i = 1; i <= 5; i++) // Recorre la lista
            {
                cout << "Relevancia: " << aux->relevancia << endl; // Imprime la relevancia del nodo auxiliar
                cout << "Titular: " << aux->titular << endl; // Imprime el titular del nodo auxiliar
                aux = aux->next; // El puntero al siguiente nodo del nodo auxiliar apunta al siguiente nodo del nodo auxiliar
            }
        };
        void mostrarListaPorAlmenosUnaPalabraProporcionadaPorElUsuario(string palabra) // Muestra la lista por almenos una palabra proporcionada por el usuario
        {
            Node *aux = head; // Crea un nodo auxiliar y lo inicializa con el puntero al primer nodo
            for (int i = 1; i <= size; i++) // Recorre la lista
            {
                if (aux->titular.find(palabra) != string::npos) // Si el titular del nodo auxiliar contiene la palabra indicada
                {
                    cout << "Relevancia: " << aux->relevancia << endl; // Imprime la relevancia del nodo auxiliar
                    cout << "Titular: " << aux->titular << endl; // Imprime el titular del nodo auxiliar
                }
                aux = aux->next; // El puntero al siguiente nodo del nodo auxiliar apunta al siguiente nodo del nodo auxiliar
            }
        };
};