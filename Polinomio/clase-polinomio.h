//
//  clase-polinomio.h
//  Polinomio
//
//  Created by Sebastián García on 26/04/14.
//  Copyright (c) 2014 Sebastián García. All rights reserved.
//

#ifndef CLASE_POLINOMIO_H
#define CLASE_POLINOMIO_H

class TipoFloat {
private:
    float valor;
public:
    TipoFloat() : valor(0.0) {};
    TipoFloat& operator=(float f);
    inline operator float() {return valor;}
};

class Polinomio {
private:
    float* coef;
    int grado;
    int max_grado;
    void reservaMemoria(int i);
public:
    Polinomio();
    Polinomio(int maxGrado);
    Polinomio(const Polinomio &p);
    Polinomio(float terminoIndependiente);
    ~Polinomio();
    inline float getCoeficiente(int i) const {
        return ((i > grado) || (i < 0)) ? 0.0 : coef[i];}
    inline int getGrado() const {return grado;}
    inline int getMaxGrado() {return max_grado;}
    void setCoeficiente (int i, float c);
    inline void setGrado(int grado) { this->grado = grado;}
    inline void setMaxGrado(int grado) { this->max_grado = grado;}
    Polinomio& operator=(const Polinomio &p);
    
    
    Polinomio operator+(const Polinomio p);
    friend std::ostream& operator<<(std::ostream &flujo, const Polinomio &p);
    friend std::istream& operator>>(std::istream &flujo, Polinomio &p);
    float& operator[](int i);

    void print() const;
    void sumar(const Polinomio &p);
    Polinomio sumar_v1 (Polinomio &p); // res = p1.sumar(p2) yo llamo y devuelvo un resultado, pero no me modifico
    void sumar_v2 (const Polinomio &p1, const Polinomio &p2); // res.sumar(p1, p2) -- aquí si me modifico yo
   
};



#endif
