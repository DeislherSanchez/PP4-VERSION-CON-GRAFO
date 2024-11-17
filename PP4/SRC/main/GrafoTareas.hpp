#ifndef GRAFOTAREAS_HPP
#define GRAFOTAREAS_HPP

#include "NodoTarea.hpp"
#include <iostream>

class NodoLista {
private:
    NodoTarea aTarea;  // NodoTarea asociado a este nodo de la lista
    NodoLista* apSiguiente; // Puntero al siguiente nodo en la lista

public:
    // Constructor
    NodoLista(const Tarea& tarea) : aTarea(tarea), apSiguiente(nullptr) {}

    // Getters y setters
    NodoTarea& getTarea() { return aTarea; }
    NodoLista* getSiguiente() const { return apSiguiente; }
    void setSiguiente(NodoLista* siguiente) { apSiguiente = siguiente; }

    // Destructor
    ~NodoLista() = default;
};

class GrafoTareas {
private:
    NodoLista* apNodos; 

public:
    // Constructor
    GrafoTareas() : apNodos(nullptr) {}

    ~GrafoTareas() {
        while (apNodos) {
            NodoLista* temp = apNodos;
            apNodos = apNodos->getSiguiente();
            delete temp;
        }
    }

    
    void agregarNodo(const Tarea& nuevaTarea) {
        NodoLista* nuevo = new NodoLista(nuevaTarea);
        nuevo->setSiguiente(apNodos);
        apNodos = nuevo;
    }

 
    void agregarArista(int idOrigen, int idDestino, int peso = 1) {
        NodoLista* actual = apNodos;
        while (actual) {
            if (actual->getTarea().getTarea().getDuracion() == idOrigen) { // Identificador ficticio
                actual->getTarea().agregarDependencia(idDestino, peso);
                return;
            }
            actual = actual->getSiguiente();
        }
        std::cerr << "Error: Nodo origen no encontrado\n";
    }

    void eliminarNodo(int id) {
        NodoLista** actual = &apNodos;
        while (*actual) {
            if ((*actual)->getTarea().getTarea().getDuracion() == id) { // Identificador ficticio
                NodoLista* temp = *actual;
                *actual = (*actual)->getSiguiente();
                delete temp;
                return;
            }
            actual = &(*actual)->getSiguiente();
        }
        std::cerr << "Error: Nodo no encontrado\n";
    }

    // Imprimir grafo
    void imprimirGrafo() const {
        NodoLista* actual = apNodos;
        while (actual) {
            actual->getTarea().imprimirNodo();
            actual = actual->getSiguiente();
        }
    }


    NodoLista* getNodos() const {
        return apNodos;
    }

};

#endif // GRAFOTAREAS_HPP
