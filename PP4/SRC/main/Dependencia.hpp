#ifndef DEPENDENCIA_HPP
#define DEPENDENCIA_HPP

class Dependencia {
private:
    int aIdDestino;           
    int aPeso;                
    Dependencia* apSiguiente; 

public:
    Dependencia(int idDestino, int peso)
        : aIdDestino(idDestino), aPeso(peso), apSiguiente(nullptr) {}
    int getIdDestino() const { return aIdDestino; }
    int getPeso() const { return aPeso; }
    Dependencia* getSiguiente() const { return apSiguiente; }
    void setSiguiente(Dependencia* siguiente) { apSiguiente = siguiente; }
    ~Dependencia() = default; 
};

#endif // DEPENDENCIA_HPP
