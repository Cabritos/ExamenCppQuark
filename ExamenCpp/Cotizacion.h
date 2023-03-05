#pragma once

#include <string>
#include "Prenda.h"

class Cotizacion
{
public:
	Cotizacion(string codigoVendedor, Prenda* prenda, const int& cantidad, const float& precioBase);
	const int& getId() const;
	const string& getFechaYHora() const;
	const string& getCodigoVendedor() const;
	const string& getPrenda() const;
	const int& getCantidad() const;
	const float& getPrecioBase() const;
	const float& getPrecioFinal() const;
	const float& getResultado() const;
private:
	int id;
	static int cantidadCotizaciones;
	string fechaYHora;
	const string codigoVendedor;
	string descripcionPrenda;
	const int cantidad;
	float precioBase;
	float precioFinal;
	float resultado;
	void setFechaYHora();
};