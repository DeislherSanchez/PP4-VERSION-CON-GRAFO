/*****Datos administrativos************************
 * Nombre del archivo: Nodo.hpp
 * Tipo de archivo: Encabezado
 * Proyecto: Gestión de Tareas y Proyectos
 * Autor: Deislher Sánchez, Yeremi Calvo, Sidney Salazar
 * Empresa: Tecnológico de Costa Rica
 *****Descripción**********************************
 * Clase que representa un nodo dentro de un grafo 
 * de tareas. Cada nodo corresponde a una tarea y 
 * puede contener dependencias hacia otros nodos.
 *****Versión**************************************
 * 1.0 | [17-11-2024 11:50] | [Deislher Sánchez]
 **************************************************/

#ifndef NODO_HPP
#define NODO_HPP

#include "Tareas.hpp"

/*****Nombre***************************************
 * Nodo
 *****Descripción**********************************
 * Clase que implementa un nodo en el grafo de tareas.
 * Cada nodo corresponde a una tarea específica y 
 * mantiene una lista de dependencias hacia otros nodos.
 *****Atributos************************************
 * - pTarea: Puntero a la tarea representada por el nodo.
 * - apDependencias: Arreglo dinámico de nodos dependientes.
 * - aCantidadDependencias: Número de dependencias actuales.
 *****Métodos**************************************
 * - getTarea: Obtiene la tarea asociada al nodo.
 * - getCantidadDependencias: Devuelve el número de 
 *   dependencias del nodo.
 * - getDependencias: Obtiene las dependencias del nodo.
 * - agregarDependencia: Agrega una nueva dependencia.
 * - existeDependencia: Verifica si existe una dependencia.
 * - setDependencias: Establece las dependencias del nodo.
 **************************************************/
class Nodo {
private:
    Tarea* pTarea;               // Tarea asociada al nodo
    Nodo** apDependencias;       // Arreglo dinámico de dependencias
    int aCantidadDependencias;   // Número de dependencias actuales

public:
    /*****Nombre***************************************
     * Nodo (constructor)
     *****Descripción**********************************
     * Inicializa un nodo con una tarea específica.
     *****Retorno**************************************
     * Ninguno.
     *****Entradas*************************************
     * - pNuevaTarea: Puntero a la tarea asociada al nodo.
     **************************************************/
    Nodo(Tarea* pNuevaTarea) 
        : pTarea(pNuevaTarea), apDependencias(nullptr), aCantidadDependencias(0) {}

    /*****Nombre***************************************
     * ~Nodo (destructor)
     *****Descripción**********************************
     * Libera los recursos asociados al nodo, incluyendo 
     * su tarea y dependencias.
     *****Retorno**************************************
     * Ninguno.
     *****Entradas*************************************
     * Ninguna.
     **************************************************/
    ~Nodo() {
        delete pTarea;
        if (apDependencias != nullptr) {
            delete[] apDependencias;
        }
    }

    /*****Nombre***************************************
     * getTarea
     *****Descripción**********************************
     * Devuelve la tarea asociada al nodo.
     *****Retorno**************************************
     * Puntero a la tarea del nodo.
     *****Entradas*************************************
     * Ninguna.
     **************************************************/
    Tarea* getTarea() const {
        return pTarea;
    }

    /*****Nombre***************************************
     * getCantidadDependencias
     *****Descripción**********************************
     * Devuelve el número de dependencias del nodo.
     *****Retorno**************************************
     * Número de dependencias.
     *****Entradas*************************************
     * Ninguna.
     **************************************************/
    int getCantidadDependencias() const {
        return aCantidadDependencias;
    }

    /*****Nombre***************************************
     * getDependencias
     *****Descripción**********************************
     * Devuelve el arreglo de dependencias del nodo.
     *****Retorno**************************************
     * Arreglo dinámico de nodos dependientes.
     *****Entradas*************************************
     * Ninguna.
     **************************************************/
    Nodo** getDependencias() const {
        return apDependencias;
    }

    /*****Nombre***************************************
     * agregarDependencia
     *****Descripción**********************************
     * Agrega una nueva dependencia al nodo.
     *****Retorno**************************************
     * Ninguno.
     *****Entradas*************************************
     * - pDependencia: Nodo a agregar como dependencia.
     **************************************************/
    void agregarDependencia(Nodo* pDependencia) {
        Nodo** nuevasDependencias = new Nodo*[aCantidadDependencias + 1];

        for (int i = 0; i < aCantidadDependencias; i++) {
            nuevasDependencias[i] = apDependencias[i];
        }

        nuevasDependencias[aCantidadDependencias] = pDependencia;

        delete[] apDependencias;
        apDependencias = nuevasDependencias;
        aCantidadDependencias++;
    }

    /*****Nombre***************************************
     * existeDependencia
     *****Descripción**********************************
     * Verifica si existe una dependencia específica.
     *****Retorno**************************************
     * true si la dependencia existe; false en caso contrario.
     *****Entradas*************************************
     * - pDependencia: Nodo a buscar como dependencia.
     **************************************************/
    bool existeDependencia(Nodo* pDependencia) const {
        for (int i = 0; i < aCantidadDependencias; i++) {
            if (apDependencias[i] == pDependencia) {
                return true;
            }
        }
        return false;
    }

    /*****Nombre***************************************
     * setDependencias
     *****Descripción**********************************
     * Establece un nuevo arreglo de dependencias para el nodo.
     *****Retorno**************************************
     * Ninguno.
     *****Entradas*************************************
     * - apNuevasDependencias: Nuevo arreglo de dependencias.
     * - nuevaCantidad: Número de dependencias en el arreglo.
     **************************************************/
    void setDependencias(Nodo** apNuevasDependencias, int nuevaCantidad) {
        if (apDependencias != nullptr) {
            delete[] apDependencias;
        }
        apDependencias = apNuevasDependencias;
        aCantidadDependencias = nuevaCantidad;
    }
};

#endif // NODO_HPP
