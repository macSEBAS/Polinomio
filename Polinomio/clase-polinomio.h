//
//  clase-polinomio.h
//  Polinomio
//
//  Created by Sebastián García on 26/04/14.
//  Copyright (c) 2014 Sebastián García. All rights reserved.
//

#ifndef _CLASE_POLINOMIO_H
#define _CLASE_POLINOMIO_H

class Polinomio {
private:
    float* coef;
    int grado;
    int max_grado;
public:
    Polinomio();
    Polinomio(int maxGrado);
    Polinomio(const Polinomio &p);
    ~Polinomio();
    void setCoeficiente (int i, float c);
    inline void setGrado(int grado) { this->grado = grado;}
    inline void setMaxGrado(int grado) { this->max_grado = grado;}
    inline float getCoeficiente(int i) const {
        return ((i > grado) || (i < 0)) ? 0.0 : coef[i];  // se hace esta excepción con los métodos que son muy cortos, que se ponen inline en una sola línea
    }
    int getGrado() const;
    inline int getMaxGrado() {return max_grado;}
    void print() const;
    void sumar(const Polinomio &p);
    Polinomio sumar_v1 (Polinomio &p); // res = p1.sumar(p2) yo llamo y devuelvo un resultado, pero no me modifico
    void sumar_v2 (const Polinomio &p1, const Polinomio &p2); // res.sumar(p1, p2) -- aquí si me modifico yo
    Polinomio operator+(const Polinomio &p);
    Polinomio& operator=(const Polinomio &p);
};

#endif
