#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include "Prenda.h"

using namespace std;

class Tienda
{
public:
	Tienda(string nombre, string direccion);
	const string& getNombre() const;
	const string& getDireccion() const;
	void agregarPrenda(unique_ptr<Prenda> prenda);
	Prenda* identificarPrenda(const string& id) const;
private:
	string nombre;
	string direccion;
	unordered_map<string, unique_ptr<Prenda>> prendas;
};