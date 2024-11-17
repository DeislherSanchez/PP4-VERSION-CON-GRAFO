/*****Datos administrativos************************
 * Nombre del archivo: String.hpp
 * Tipo de archivo: Encabezado
 * Proyecto: Constructor XML
 * Autor: Deislher Sánchez, Yeremi Calvo, Sidney Salazar, Gilbert Aguilar.
 * Empresa: Tecnologico de Costa Rica.
 *****Descripción**********************************
 * La clase String gestiona
 * cadenas de caracteres de manera dinámica sin 
 * usar la biblioteca estándar de C++ `string`.
 *****Versión**************************************
 * ##   | Fecha y hora | Autores
 * Final|  28/10/2024   | Deislher Sánchez, Gilbert Aguilar, Yeremi Calvo y Sidney Salazar.
 **************************************************/

#ifndef STRING_HPP
#define STRING_HPP
#include <fstream>

/*****Nombre***************************************
 * String
 *****Descripción**********************************
 * Clase para manejar cadenas de caracteres dinámicas
 * sin usar la biblioteca estándar `string`.
 *****Atributos************************************
 * - char* apCadena: Puntero a la cadena de caracteres.
 *****Métodos**************************************
 * - String()
 * - String(const char*)
 * - String(const String&)
 * - String& operator=(const String&)
 * - ~String()
 * - char* mostrarCadena()
 * - int len() const
 * - int leng(const char*)
 * - void cambiarCadena(const char*)
 * - char caracterEn(int)
 **************************************************/
class String {
private:
    char *apCadena = nullptr;

    /*****Nombre***************************************
     * copiarCadena
     *****Descripción**********************************
     * Copia el contenido de una cadena fuente a la cadena
     * del objeto actual.
     *****Entradas*************************************
     * - const char *pFuente: Puntero a la cadena fuente.
     **************************************************/
    void copiarCadena(const char *pFuente) {
        if (pFuente != nullptr) {
            int largo = 0;
            while (pFuente[largo] != '\0') {
                ++largo;
            }
            apCadena = new char[largo + 1];  
            for (int i = 0; i <= largo; ++i) {
                apCadena[i] = pFuente[i];
            }
        } else {
            apCadena = nullptr;
        }
    }

public:
    /*****Nombre***************************************
     * String (constructor por defecto)
     *****Descripción**********************************
     * Constructor que inicializa la cadena como un puntero
     * nulo.
     **************************************************/
    String() : apCadena(nullptr) {}

    /*****Nombre***************************************
     * String (constructor con argumento)
     *****Descripción**********************************
     * Constructor que inicializa la cadena con una cadena
     * proporcionada.
     *****Entradas*************************************
     * - const char *pCadena: Puntero a la cadena de caracteres.
     **************************************************/
    String(const char *pCadena) : apCadena(nullptr) {
        copiarCadena(pCadena);
    }

    /*****Nombre***************************************
     * String (constructor de copia)
     *****Descripción**********************************
     * Constructor que copia el contenido de otra cadena.
     *****Entradas*************************************
     * - const String& other: Referencia a otro objeto String.
     **************************************************/
    String(const String &other) : apCadena(nullptr) {
        copiarCadena(other.apCadena);
    }

    /*****Nombre***************************************
     * operator=
     *****Descripción**********************************
     * Sobrecarga del operador de asignación para copiar el
     * contenido de otra cadena.
     *****Entradas*************************************
     * - const String& other: Referencia a otro objeto String.
     *****Retorno**************************************
     * - String&: Referencia al objeto actual.
     **************************************************/
    String &operator=(const String &other) {
        if (this != &other) {
            delete[] apCadena;
            copiarCadena(other.apCadena);
        }
        return *this;
    }

    /*****Nombre***************************************
     * ~String (destructor)
     *****Descripción**********************************
     * Destructor que libera la memoria ocupada por la cadena.
     **************************************************/
    ~String() {
        delete[] apCadena;
    }

    /*****Nombre***************************************
     * mostrarCadena
     *****Descripción**********************************
     * Retorna una copia de la cadena almacenada.
     *****Retorno**************************************
     * - char*: Puntero a la copia de la cadena de caracteres.
     **************************************************/
    char *mostrarCadena() {
        if (apCadena == nullptr) {
            return nullptr;
        }

        int length = len();
        char *copiaCadena = new char[length + 1];
        for (int i = 0; i < length; i++) {
            copiaCadena[i] = apCadena[i];
        }
        copiaCadena[length] = '\0';
        return copiaCadena;
    }

    /*****Nombre***************************************
     * len
     *****Descripción**********************************
     * Calcula la longitud de la cadena almacenada.
     *****Retorno**************************************
     * - int: Longitud de la cadena.
     **************************************************/
    int len() const {
        if (apCadena == nullptr) {
            return 0;
        }
        int largo = 0;
        while (apCadena[largo] != '\0') {
            ++largo;
        }
        return largo;
    }

    /*****Nombre***************************************
     * leng
     *****Descripción**********************************
     * Calcula la longitud de una cadena proporcionada.
     *****Entradas*************************************
     * - const char* cadena: Puntero a la cadena de caracteres.
     *****Retorno**************************************
     * - int: Longitud de la cadena.
     **************************************************/
    int leng(const char *cadena) {
        int largo = 0;
        while (cadena[largo] != '\0') {
            ++largo;
        }
        return largo;
    }

    /*****Nombre***************************************
     * cambiarCadena
     *****Descripción**********************************
     * Cambia el contenido de la cadena actual por una nueva cadena.
     *****Entradas*************************************
     * - const char *pCadenaNueva: Puntero a la nueva cadena de caracteres.
     **************************************************/
    void cambiarCadena(const char *pCadenaNueva) {
        delete[] apCadena;
        apCadena = nullptr;
        copiarCadena(pCadenaNueva);
    }

        /*****Nombre***************************************
     * caracterEn
     *****Descripción**********************************
    * Retorna el carácter en una posición específica de la cadena.
    *****Entradas*************************************
    * - int pos: Posición del carácter en la cadena.
    *****Retorno**************************************
    * - char: Carácter en la posición especificada o '\0' si la posición
    *   está fuera de los límites de la cadena.
    **************************************************/
    char caracterEn(int pos) {
        if (pos > len()) {
            return '\0';
        }
        return apCadena[pos];
    }

    /*****Nombre***************************************
     * operator==
     *****Descripción**********************************
    * Sobrecarga del operador de igualdad para comparar la cadena
    * almacenada con otra cadena de caracteres.
    *****Entradas*************************************
    * - const char* pCadena: Puntero a la cadena a comparar.
    *****Retorno**************************************
    * - bool: true si ambas cadenas son iguales, false en caso contrario.
    **************************************************/
    bool operator==(const String& otro) const {
        if (apCadena == nullptr && otro.apCadena == nullptr) {
            return true;
        } else if (apCadena != nullptr && otro.apCadena != nullptr) {
            int i = 0;
            while (apCadena[i] != '\0' && otro.apCadena[i] != '\0') {
                if (apCadena[i] != otro.apCadena[i]) {
                    return false;
                }
                i++;
            }
            return apCadena[i] == '\0' && otro.apCadena[i] == '\0';
        } else {
            return false;
        }
    }


    /*****Nombre***************************************
     * operator==
     *****Descripción**********************************
    * Sobrecarga del operador de igualdad para comparar la cadena
    * almacenada con otra instancia de la clase String.
    *****Entradas*************************************
    * - const String& otro: Referencia a otra instancia de String.
    *****Retorno**************************************
    * - bool: true si ambas cadenas son iguales, false en caso contrario.
    **************************************************/
    bool operatorB(const String &otro) const {
        if (apCadena == nullptr && otro.apCadena == nullptr) {
            return true;
        } else if (apCadena != nullptr && otro.apCadena != nullptr) {
            int i = 0;
            while (apCadena[i] != '\0' && otro.apCadena[i] != '\0') {
                if (apCadena[i] != otro.apCadena[i]) {
                    return false;
                }
                i++;
            }
            return apCadena[i] == '\0' && otro.apCadena[i] == '\0';
        } else {
            return false;
        }
    }

    /*****Nombre***************************************
     * split
     *****Descripción**********************************
    * Divide la cadena en subcadenas utilizando un carácter separador.
    *****Entradas*************************************
    * - char separador: Carácter utilizado como separador.
    *****Retorno**************************************
    * - String**: Arreglo de punteros a objetos String que contienen
    *   las subcadenas resultantes.
    **************************************************/
    String **split(char separador) {
        if (apCadena == nullptr) {
            return nullptr;
        }

        int numPartes = contarCaracter(separador) + 1;
        String **ppRes = new String *[numPartes + 1];
        char *pTempList = new char[len() + 1];

        int ind = 0, indR = 0;
        for (int i = 0; i <= len(); i++) {
            if (apCadena[i] == separador || apCadena[i] == '\0') {
                pTempList[ind] = '\0';
                ppRes[indR++] = new String(pTempList);
                ind = 0;
            } else {
                pTempList[ind++] = apCadena[i];
            }
        }
        delete[] pTempList;
        ppRes[indR] = nullptr;

        return ppRes;
    }

    /*****Nombre***************************************
     * reemplazarOcurrencias
     *****Descripción**********************************
    * Reemplaza todas las ocurrencias de una subcadena con otra.
    *****Entradas*************************************
    * - char* anterior: Subcadena a ser reemplazada.
    * - char* nuevo: Subcadena que reemplaza a la original.
    *****Retorno**************************************
    * - String*: Puntero al objeto String actualizado.
    **************************************************/
    String* reemplazarOcurrencias(char* pAnterior, char* pNuevo) {
        if (pAnterior == nullptr || pNuevo == nullptr || apCadena == nullptr) {
            return this;
        }

        int largo = len();
        int largoAnterior = leng(pAnterior);
        int largoNuevo = leng(pNuevo);

        if (largoAnterior == 0 || largo < largoAnterior) {
            return this;
        }

        int conteo = 0;
        for (int i = 0; i <= largo - largoAnterior; ++i) {
            bool iguales = true;
            for (int j = 0; j < largoAnterior; ++j) {
                if (apCadena[i + j] != pAnterior[j]) {
                    iguales = false;
                    break;
                }
            }
            if (iguales) {
                ++conteo;
                i += largoAnterior - 1;
            }
        }

        int nuevoLargo = largo + conteo * (largoNuevo - largoAnterior);
        char* pResultado = new char[nuevoLargo + 1];

        int indice2 = 0;
        int i = 0;

        while (i < largo) {
            bool iguales = true;
            if (i <= largo - largoAnterior) {
                for (int j = 0; j < largoAnterior; ++j) {
                    if (apCadena[i + j] != pAnterior[j]) {
                        iguales = false;
                        break;
                    }
                }
            } else {
                iguales = false;
            }

            if (iguales) {
                for (int j = 0; j < largoNuevo; ++j) {
                    pResultado[indice2++] = pNuevo[j];
                }
                i += largoAnterior;
            } else {
                pResultado[indice2++] = apCadena[i++];
            }
        }

        pResultado[indice2] = '\0';
        cambiarCadena(pResultado);
        delete[] pResultado;
        return this;
    }

    /*****Nombre***************************************
     * concatenarCadenas
     *****Descripción**********************************
    * Concatena múltiples cadenas al objeto String actual.
    *****Entradas*************************************
    * - char** cadenas: Arreglo de punteros a cadenas de caracteres.
    *****Retorno**************************************
    * - String*: Puntero al objeto String actualizado.
    **************************************************/
    String* concatenarCadenas(char** pCadenas) {
        int i = 0;
        while (pCadenas[i] != nullptr) {
            concatenar(pCadenas[i]);
            ++i;
        }
        return this;
    }

    /*****Nombre***************************************
     * concatenarEn
     *****Descripción**********************************
    * Concatena una cadena al objeto String actual en un índice específico.
    *****Entradas*************************************
    * - char* pCadena: Puntero a la cadena de caracteres a concatenar.
    * - int indice: Índice en el que insertar la cadena.
    **************************************************/
    void concatenarEn(char* pCadena, int indice) {
        if (pCadena == nullptr) return;

        int largoCadenaOriginal = len();
        int largoCadenaNueva = leng(pCadena);

        if (indice < 0 || indice > largoCadenaOriginal) {
            indice = largoCadenaOriginal;
        }

        char* pCadenaNueva = new char[largoCadenaOriginal + largoCadenaNueva + 1];

        for (int i = 0; i < indice; ++i) {
            pCadenaNueva[i] = apCadena[i];
        }

        for (int i = 0; i < largoCadenaNueva; ++i) {
            pCadenaNueva[indice + i] = pCadena[i];
        }

        for (int i = indice; i < largoCadenaOriginal; ++i) {
            pCadenaNueva[largoCadenaNueva + i] = apCadena[i];
        }

        pCadenaNueva[largoCadenaOriginal + largoCadenaNueva] = '\0';

        cambiarCadena(pCadenaNueva);
        delete[] pCadenaNueva;
    }

    /*****Nombre***************************************
     * concatenar
     *****Descripción**********************************
    * Concatena una cadena al final del objeto String actual.
    *****Entradas*************************************
    * - const char* pCadena: Puntero a la cadena de caracteres a concatenar.
    **************************************************/
    void concatenar(const char* pCadena) {
        if (pCadena == nullptr) return;

        int largoCadenaOriginal = len();
        int largoCadenaNueva = leng(pCadena);

        char* pCadenaConcatenada = new char[largoCadenaOriginal + largoCadenaNueva + 1];

        for (int i = 0; i < largoCadenaOriginal; i++) {
            pCadenaConcatenada[i] = apCadena[i];
        }

        for (int i = 0; i < largoCadenaNueva; i++) {
            pCadenaConcatenada[largoCadenaOriginal + i] = pCadena[i];
        }

        pCadenaConcatenada[largoCadenaOriginal + largoCadenaNueva] = '\0';
        cambiarCadena(pCadenaConcatenada);
        delete[] pCadenaConcatenada;
    }

    /*****Nombre***************************************
     * contarCaracter
     *****Descripción**********************************
    * Cuenta cuántas veces aparece un carácter en la cadena.
    *****Entradas*************************************
    * - char caracter: Carácter a contar.
    *****Retorno**************************************
    * - int: Número de veces que aparece el carácter.
    **************************************************/
    int contarCaracter(char caracter) {
        int largoCadena = len();
        int contador = 0;
        for (int i = 0; i < largoCadena; i++) {
            if (apCadena[i] == caracter) contador++;
        }
        return contador;
    }

    /*****Nombre***************************************
     * ultimoIndice
     *****Descripción**********************************
    * Encuentra el último índice donde aparece un carácter en la cadena.
    *****Entradas*************************************
    * - char caracter: Carácter a buscar.
    *****Retorno**************************************
    * - int: Último índice del carácter o -1 si no se encuentra.
    **************************************************/
    int ultimoIndice(char caracter) {
        int largoCadena = len();
        int contador = -1;
        for (int i = 0; i < largoCadena; i++) {
            if (apCadena[i] == caracter) contador = i;
        }
        return contador;
    }

        
    /*****Nombre***************************************
     * guardarEnArchivo
     *****Descripción**********************************
    * Guarda la cadena actual en un archivo especificado.
    *****Entradas*************************************
    * - char* pRuta: Ruta del archivo.
    * - const char* pModo: Modo de apertura del archivo ('w' para escribir, 'a' para anexar).
    **************************************************/
    void guardarEnArchivo(char *pRuta, const char *pModo) {
        if (pRuta == nullptr || pModo == nullptr) return;

        int longitud = 0;
        while (pModo[longitud] != '\0') {
            longitud++;
        }

        if (longitud != 1) return;
        if (pModo[0] != 'w' && pModo[0] != 'a') return;

        std::ofstream archivo(pRuta, (pModo[0] == 'w') ? std::ios::out : std::ios::app);
        if (!archivo.is_open()) return;

        archivo << apCadena << std::endl;
        archivo.close();
    }

    /*****Nombre***************************************
     * leerArchivo
     *****Descripción**********************************
    * Lee el contenido de un archivo y lo almacena en la cadena actual.
    *****Entradas*************************************
    * - char* pRuta: Ruta del archivo a leer.
    **************************************************/
    void leerArchivo(char *pRuta) {
        if (pRuta == nullptr) return;

        std::ifstream archivo(pRuta);
        if (!archivo.is_open()) return;

        archivo.seekg(0, std::ios::end);
        int tamanoArchivo = archivo.tellg();
        archivo.seekg(0, std::ios::beg);

        char *pTexto = new char[tamanoArchivo + 1];
        archivo.read(pTexto, tamanoArchivo);
        pTexto[tamanoArchivo] = '\0';

        archivo.close();
        cambiarCadena(pTexto);
        delete[] pTexto;
    }

    /*****Nombre***************************************
     * contains
     *****Descripción**********************************
    * Verifica si la cadena actual contiene una subcadena específica.
    *****Entradas*************************************
    * - char* subcadena: Puntero a la subcadena a buscar.
    *****Retorno**************************************
    * - bool: true si la subcadena se encuentra, false en caso contrario.
    **************************************************/
    bool contains(char *pSubcadena) {
        if (apCadena == nullptr || pSubcadena == nullptr) return false;

        int largoSubcadena = leng(pSubcadena);
        int largoCadena = len();

        for (int i = 0; i <= largoCadena - largoSubcadena; i++) {
            bool encontrado = true;
            for (int j = 0; j < largoSubcadena; j++) {
                if (apCadena[i + j] != pSubcadena[j]) {
                    encontrado = false;
                    break;
                }
            }
            if (encontrado) return true;
        }
        return false;
    }

};

#endif  // STRING_HPP


