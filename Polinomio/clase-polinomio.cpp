#include <iostream>
#include <stdlib.h>
#include "clase-polinomio.h"
using namespace std;

// El orden al declarar los métodos de la clase: Constructures, destructor, set, get, print, y luego los demás

Polinomio::Polinomio() {
    cout << "Constructor" << endl;
	max_grado = 10;
	grado = 0;
	coef = new float[max_grado + 1];
	for (int i = 0; i <= max_grado; i++)
		coef[i] = 0.0;
}

Polinomio::Polinomio(int i) {
	max_grado = i;
	grado = 0;
	coef = new float[max_grado + 1];
	for (int i = 0; i <= max_grado; i++)
		coef[i] = 0.0;
}

Polinomio::Polinomio(const Polinomio &p) {	// el constructor por copia
    cout << "Constructor por copia" << endl;
	max_grado = p.max_grado;
	grado = p.grado;
	coef = new float[max_grado + 1];
	for (int i = 0; i <= max_grado; i++)
		coef[i] = p.coef[i];
}

Polinomio::~Polinomio() {
    cout << "Destructor" << endl;
	delete [] coef;
	grado = 0;
	max_grado = 0;
}

// Que el set haga lo siguiente: si no hay memoria se reserva nueva memoria!! Para el viernes.

void Polinomio::setCoeficiente(int i, float c) {
	if (i >= 0) {
		if (i > max_grado) {
			float* aux = new float[i + 1];
			//Aquí hacer la comprobación de siempre de si no hay memoria salir...
			for (int j = 0; j <= grado; j++)
				aux[j] = coef[j];
			delete [] coef;
			coef = aux;
			for (int j = grado + 1; j <= i; j++)
				coef[j] = 0.0;
			max_grado = i;
		}
		coef[i] = c;
        
		if (c != 0.0 && i > grado)
			grado = i;
		else if (c == 0.0 && i == grado)
			while (coef[grado] == 0.0 && grado > 0)
				grado--;
	}
}


Polinomio& Polinomio::operator=(const Polinomio &p) {
    cout << "Asignación" << endl;
    if (&p != this) {
        delete [] this->coef;
        this->max_grado = p.max_grado;
        this->grado = p.grado;
        this->coef = new float[this->max_grado + 1];
        for (int i = 0; i <= max_grado; i++)
            this->coef[i] = p.coef[i];
    }
    return *this;
}

Polinomio Polinomio::operator+(const Polinomio &p) {
    int grado_mayor;
	
	if (this->getGrado() <= p.getGrado())
		grado_mayor = p.getGrado();
	else
		grado_mayor = this->getGrado();
    Polinomio resultado;
	for (int i = 0; i <= grado_mayor; i++)
		resultado.setCoeficiente(i, (this->getCoeficiente(i) + p.getCoeficiente(i)));
    return resultado;
}

ostream& operator<<(ostream &flujo, const Polinomio &p) {
    flujo << p.getCoeficiente(p.getGrado());
    if (p.getGrado() > 0)
        flujo << "x^" << p.getGrado();
    for (int i = p.getGrado() - 1; i >= 0; i--) {
        if (p.getCoeficiente(i) != 0.0) {
            flujo << " + " << p.getCoeficiente(i);
            if (i > 0)
                flujo << "x^" << i;
        }
    }
    flujo << endl;
    return flujo;
}

istream& operator>>(istream &flujo, Polinomio &p) {
    int grado;
    float valor;
    
    do {
        flujo >> valor >> grado;
        if (grado >= 0)
            p.setCoeficiente(grado,valor);
    }
    while ( grado >= 0);
    return flujo;
}

void Polinomio::print() const {
	cout << getCoeficiente(getGrado());
	if (getGrado() > 0)
		cout << "x^" << getGrado();
	for (int i = getGrado() - 1; i >= 0; --i) {
		if (getCoeficiente(i) != 0.0)
			cout << " + " << getCoeficiente(i) << "x^" << i;
	}
	cout << endl;
}

void Polinomio::sumar(const Polinomio &p) {
	int grado_menor, grado_mayor;
	
	if (this->getGrado() <= p.getGrado()) {
		grado_menor = this->getGrado();
		grado_mayor = p.getGrado();
	}
	else {
		grado_menor = p.getGrado();
		grado_mayor = this->getGrado();
	}
	for (int i = 0; i <= grado_menor; i++)
		this->setCoeficiente(i, (this->getCoeficiente(i) + p.getCoeficiente(i)));
	if (grado_menor == this->getGrado()) {
		for (int i = grado_menor + 1; i <= grado_mayor; i++)
			this->setCoeficiente(i, p.getCoeficiente(i));
	}
}

Polinomio Polinomio::sumar_v1 (Polinomio &p) {
	int gradomaximo = 0;
	//1º) Distinguir qué polinomio tiene más grado y ajustamos sus tamaños para igualarlos sin cambiar sus coeficientes
	if (this->getGrado() > p.getGrado()){
		gradomaximo = this->getGrado();
		//Cambiamos el tamaño del vector de coeficientes sin cambiar el grado del polinomio
		//p.setCoeficiente(gradomaximo,0);
		//p.setGrado(gradomaximo);
	}
	else if (this->getGrado() < p.getGrado()){
		gradomaximo = p.getGrado();
		//Cambiamos el tamaño del vector de coeficientes sin cambiar el grado del polinomio
		//this->setCoeficiente(gradomaximo,0);
		//this->setGrado(gradomaximo);
	}
    else
        gradomaximo = p.getGrado();

	//2º) Crear el polinomio resultado con el gradomaximo
	Polinomio resultado;
    cout << resultado.getMaxGrado() << " El grado máximo" << endl;
	//3º) Recorrer apropiadamente los dos polinomios e ir sumando y almacenando
	for(int i = 0; i <= gradomaximo; i++)
		resultado.setCoeficiente(i, p.getCoeficiente(i) + this->getCoeficiente(i));
	//4º) Devuelvo el polinomio
	return resultado;
}

void Polinomio::sumar_v2(const Polinomio &p1, const Polinomio &p2) {
	if (p1.getGrado() <= p2.getGrado()) {
		for (int i = 0; i <= p1.getGrado(); i++)
			this->setCoeficiente(i, p1.getCoeficiente(i) + p2.getCoeficiente(i));
		for (int i = (p1.getGrado() + 1); i <= p2.getGrado(); i++)
			this->setCoeficiente(i, p2.getCoeficiente(i));
	}
	else {
		for (int i = 0; i <= p2.getGrado(); i++)
			this->setCoeficiente(i, p1.getCoeficiente(i) + p2.getCoeficiente(i));
		for (int i = (p2.getGrado() + 1); i <= p1.getGrado(); i++)
			this->setCoeficiente(i, p1.getCoeficiente(i));
	}
}

// Sobrecarga de la operación + como función externa
Polinomio operator+(const Polinomio &p1, const Polinomio &p2) {
    int grado_mayor;
	
	if (p1.getGrado() <= p2.getGrado())
		grado_mayor = p2.getGrado();
	else
		grado_mayor = p1.getGrado();
    Polinomio resultado;
	for (int i = 0; i <= grado_mayor; i++)
		resultado.setCoeficiente(i, (p1.getCoeficiente(i) + p2.getCoeficiente(i)));
	
    return resultado;
}

