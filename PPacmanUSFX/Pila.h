#pragma once
#include <iostream>
using namespace std;

template<class T>
class Pila
{
private:
	T* Datos;
	int Cima;
	int numeroElementos;
public:
	Pila(int _numeroElementos) : numeroElementos(_numeroElementos) {
		Datos = new T[numeroElementos];
		Cima = -1;
	}
	~Pila() { delete[] Datos; }
	void Insertar(T elementoInsertar);
	T Sacar();
	bool Vacia();
	bool Llena();
	void setNumero(int _numero);
};

template<class T>
void Pila<T>::Insertar(T elementoInsertar) {
	if (!Llena()) {
		Cima++;
		Datos[Cima] = elementoInsertar;
		//cout << "Se insertado satisfactoriamente" << endl;
	}
	else {
		cout << "No se pudo ingresar el elemento en la pila" << endl;
	}
}

template<class T>
T Pila<T>::Sacar() {
	if (!Vacia()) {
		T elementoSacar = Datos[Cima];
		Cima--;
		return elementoSacar;
	}
	else {
		cout << "No se pudo sacar el elemento de la pila" << endl;
	}
}

template<class T>
bool Pila<T>::Vacia() {
	if (Cima < 0) {
		return true;
	}
	else
		return false;
}

template<class T>
bool Pila<T>::Llena() {
	if (Cima < numeroElementos - 1) {
		return false;
	}
	else {
		return true;
	}

}

template<class T>
void Pila<T>::setNumero(int _numero) { numeroElementos = _numero; }