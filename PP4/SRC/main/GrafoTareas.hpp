#ifndef GRAFODETAREAS_HPP
#define GRAFODETAREAS_HPP

#include "Nodo.hpp"
#include <iostream>

class GrafoDeTareas {
private:
    Nodo** nodos; 
    int cantidadNodos;
    int capacidad;

    void redimensionar() {
        int nuevaCapacidad = capacidad * 2;
        Nodo** nuevoArreglo = new Nodo*[nuevaCapacidad];

        for (int i = 0; i < cantidadNodos; i++) {
            nuevoArreglo[i] = nodos[i];
        }

        delete[] nodos;
        nodos = nuevoArreglo;
        capacidad = nuevaCapacidad;
    }

public:
    GrafoDeTareas(int capacidadInicial = 10)
        : nodos(new Nodo*[capacidadInicial]), cantidadNodos(0), capacidad(capacidadInicial) {}

    ~GrafoDeTareas() {
        for (int i = 0; i < cantidadNodos; i++) {
            delete nodos[i];
        }
        delete[] nodos;
    }

    void agregarTarea(Tarea* tarea) {
        if (cantidadNodos == capacidad) {
            redimensionar();
        }
        nodos[cantidadNodos++] = new Nodo(tarea);
    }

    void agregarDependencia(int idOrigen, int idDestino) {
        if (idOrigen < 0 || idOrigen >= cantidadNodos || idDestino < 0 || idDestino >= cantidadNodos) {
            std::cerr << "Error: ID de tarea fuera de rango.\n";
            return;
        }
        nodos[idOrigen]->agregarDependencia(nodos[idDestino]);
    }

    Nodo* obtenerNodo(int id) {
        if (id < 0 || id >= cantidadNodos) {
            std::cerr << "Error: ID fuera de rango.\n";
            return nullptr;
        }
        return nodos[id];
    }

    void eliminarNodo(int id) {
        if (id < 0 || id >= cantidadNodos) {
            std::cerr << "Error: ID fuera de rango.\n";
            return;
        }

        // Eliminar el nodo
        delete nodos[id];

        // Ajustar los nodos restantes
        for (int i = id; i < cantidadNodos - 1; i++) {
            nodos[i] = nodos[i + 1];
        }
        cantidadNodos--;

        // Actualizar las dependencias de los otros nodos
        for (int i = 0; i < cantidadNodos; i++) {
            Nodo** dependencias = nodos[i]->getDependencias();
            int cantidadDependencias = nodos[i]->getCantidadDependencias();
            Nodo** nuevasDependencias = new Nodo*[cantidadDependencias];
            int nuevasCantidad = 0;

            for (int j = 0; j < cantidadDependencias; j++) {
                if (dependencias[j] != nodos[id]) {
                    nuevasDependencias[nuevasCantidad++] = dependencias[j];
                }
            }

            delete[] dependencias;
            nodos[i]->setDependencias(nuevasDependencias, nuevasCantidad);
        }
    }

    void GrafoDeTareas::mostrarGrafo() {
        std::cout << "Mostrando el grafo de tareas..." << std::endl;
        std::cout << "Cantidad de nodos: " << cantidadNodos << std::endl;
        for (int i = 0; i < cantidadNodos; i++) {
            if (nodos[i] != nullptr) {
                std::cout << "Nodo " << i << ": " 
                          << nodos[i]->getTarea()->getNombre().mostrarCadena() << std::endl;
            } else {
                std::cout << "Nodo " << i << ": nullptr" << std::endl;
            }
        }
        std::cout << "Fin del grafo." << std::endl;
    }


};

#endif // GRAFODETAREAS_HPP
