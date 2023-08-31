/*
    * news.cpp

    * Created on: 25/08/2023 15:35

    * Last modified on: 25/08/2023

    * Author: Jeffry Alberto Araya Chaves.
*/

#include "caso1.cpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Noticias *noticias = new Noticias();
    // Probando mostrar lista vacía
    cout << "Mostrando lista vacía: " << endl;
    cout << noticias->esVacio() << endl;

    // Probando insertar al inicio
    cout << "Insertando al inicio: " << endl;
    noticias->insertarAlInicio(10, "Noticia 1");
    noticias->insertarAlInicio(15, "Noticia 2");
    noticias->insertarAlInicio(20, "Noticia 3");	
    noticias->insertarAlInicio(25, "Noticia 4");
    noticias->insertarAlInicio(30, "Noticia 5");
    noticias->insertarAlInicio(35, "Noticia 6");
    noticias->insertarAlInicio(40, "Noticia 7");
    noticias->insertarAlInicio(45, "Noticia 8");
    noticias->insertarAlInicio(50, "Noticia 9");
    noticias->insertarAlInicio(55, "Noticia 10");
    noticias->insertarAlInicio(60, "Noticia 11");
    
    // Probando mostrar lista total
    cout << "Mostrando lista total: " << endl;
    cout << noticias->esVacio() << endl;
    noticias->mostrarListaTotal();

    cout << endl;


    // Probando Top 5
    cout << "Noticias más leídas: " << endl;
    noticias->mostrarTop5Noticias();

    cout << endl;

    // Probando eliminar al inicio
    noticias->eliminarAlInicio();

    cout << endl;

    // Probando mostrar lista total
    noticias->mostrarListaTotal();
    
    cout << endl;

    // Probando Eliminar al final
    noticias->eliminarAlFinal();

    noticias->mostrarListaTotal();

    cout << endl;

    // Probando insertar al final
    noticias->insertarAlFinal(65, "Noticia 1");

    noticias->mostrarListaTotal();

    cout << endl;

    // Probando eliminar por posición
    noticias->eliminarEnPosicion(2);

    noticias->mostrarListaTotal();

    cout << endl;

    // Probando eliminar por Titular
    noticias->eliminarTitular("Noticia 3");

    noticias->mostrarListaTotal();

    cout << endl;

    // Probando insertar por posición
    noticias->insertarEnPosicion(70, "Noticia 3", 2);

    noticias->mostrarListaTotal();

    cout << endl;

    // Probando modificar por Titular
    noticias->modificarPorTitular("Noticia 4", 75, "Noticia 4.0");

    noticias->mostrarListaTotal();

    cout << endl;

    // Probando modificar por posición
    noticias->modificarPorPosicion(3, 80, "Noticia 8.1");
    
    noticias->mostrarListaTotal();

    cout << endl;

    // Probando buscar por Titular
    noticias->buscarPorTitular("Noticia 8.1");

    cout << endl;

    // Probando buscar por posición
    noticias->buscarPorPosicion(6); // Noticia 5

    cout << endl;

    // Probando buscar por Titular
    noticias->buscarPorTitular("Noticia 7");

    cout << endl;
    return 0;
}