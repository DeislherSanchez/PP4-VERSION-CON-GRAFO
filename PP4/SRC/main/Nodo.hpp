#ifndef NODO_HPP
#define NODO_HPP

#include "Tareas.hpp"

class Nodo {
private:
    Tarea* tarea;
    Nodo** dependencias; 
    int cantidadDependencias;

public:
    Nodo(Tarea* nuevaTarea) 
        : tarea(nuevaTarea), dependencias(nullptr), cantidadDependencias(0) {}

    ~Nodo() {
        delete tarea;
        if (dependencias != nullptr) {
            delete[] dependencias;
        }
    }

    Tarea* getTarea() const {
        return tarea;
    }

    int getCantidadDependencias() const {
        return cantidadDependencias;
    }

    Nodo** getDependencias() const {
        return dependencias;
    }


    void agregarDependencia(Nodo* dependencia) {
        Nodo** nuevasDependencias = new Nodo*[cantidadDependencias + 1];

        for (int i = 0; i < cantidadDependencias; i++) {
            nuevasDependencias[i] = dependencias[i];
        }

        nuevasDependencias[cantidadDependencias] = dependencia;

        delete[] dependencias;
        dependencias = nuevasDependencias;
        cantidadDependencias++;
    }

    bool existeDependencia(Nodo* dependencia) const {
        for (int i = 0; i < cantidadDependencias; i++) {
            if (dependencias[i] == dependencia) {
                return true;
            }
        }
        return false;
    }


    void setDependencias(Nodo** nuevasDependencias, int nuevaCantidad) {
        if (dependencias != nullptr) {
            delete[] dependencias;
        }
        dependencias = nuevasDependencias;
        cantidadDependencias = nuevaCantidad;
    }

};

#endif // NODO_HPP
