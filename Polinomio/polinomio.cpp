//
//  polinomio.cpp
//  Polinomio
//
//  Created by Sebastián García on 26/04/14.
//  Copyright (c) 2014 Sebastián García. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "clase-polinomio.h"

using namespace std;

void pausa() {
	char tecla;
    
	cout << "\nPulse ENTER para continuar ";
	cin.get(tecla);
}

int main () {
	Polinomio p1;
	Polinomio p2;
	Polinomio p3;
	Polinomio p4;
	Polinomio p5;
    Polinomio p6(15);
    Polinomio* vector_p = new Polinomio[10];
    
    if (!vector_p) {
        cerr << "Error al reservar la memoria" << endl;
        exit(-1);
    }
    
	p1.setCoeficiente(2, 5);
	p1.setCoeficiente(1, 3);
	p1.setCoeficiente(0, 1);
	p2.setCoeficiente(1, 4);
	p2.setCoeficiente(0, 2);
	p1.print();
	p2.print();
	cout << p2.getGrado() << endl;
	p2.sumar(p1);
	p2.print();
    
	p4.setCoeficiente(2, 5);
	p4.setCoeficiente(1, 3);
	p4.setCoeficiente(0, 1);
	p5.setCoeficiente(1, 4);
	p5.setCoeficiente(0, 2);
	p3.sumar_v2(p4, p5);
	p3.print();
    
    Polinomio resul = p1; // Aquí sí llama al constructor por copia
    Polinomio res = p1.sumar_v1(p2); // pero aquí no entiendo por qué llama al constructor por defecto
    cout << "Imprimimos res: ";
    res.print();
    
    vector_p[0].setCoeficiente(2,5);
    vector_p[0].setCoeficiente(1,4);
    vector_p[0].setCoeficiente(0,1);
    
    vector_p[0].print();
    
    vector_p[1] = p4;
    
    vector_p[1].print();
    vector_p[2].print();
    
	pausa();
    
    delete [] vector_p;
    cout << "Hemos borrado el vector" << endl;
    
    p6.setCoeficiente(12, 6);
    p6.print();
    cout << p6.getGrado() << endl;
    Polinomio resul2 = p6.sumar_v1(p1);
    cout << resul2.getGrado() << endl;
    resul2.print();
    resul = resul2 + p6;
    resul.print();
    
}


