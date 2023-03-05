#pragma once

#include<string>
#include<vector>

#include "Tienda.h"
#include "Cotizacion.h"
#include "Prenda.h"

using namespace std;

class Vendedor
{
public:
	Vendedor(string nombre, string apellido, string codigo);
	const string& getNombre() const;
	const string& getApellido() const;
	const string& getCodigo() const;
	const vector<Cotizacion>& getHistorialCotizaciones();
	const Cotizacion& cotizar(Prenda* prenda, const int& cantidad, const float& precioBase);
	void setTienda(const Tienda& tienda);
	const Tienda& getTienda() const;
private:
	string nombre;
	string apellido;
	string codigo;
	vector<Cotizacion> historialCotizaciones{};
	const Tienda* tienda = nullptr;
};