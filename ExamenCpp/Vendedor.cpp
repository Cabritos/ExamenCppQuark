#include "Vendedor.h"

Vendedor::Vendedor(string nombre, string apellido, string codigo) :
	nombre{ std::move(nombre) }, apellido{ std::move(apellido) }, codigo{ std::move(codigo) } {}

const string& Vendedor::getNombre() const {	return nombre; }

const string& Vendedor::getApellido() const { return apellido; }

const string& Vendedor::getCodigo() const { return codigo; }

const Cotizacion& Vendedor::cotizar(Prenda* prenda, const int& cantidad, const float& precioBase)
{
	const auto cotizacion = Cotizacion{ codigo, prenda, cantidad, precioBase};
	historialCotizaciones.push_back(cotizacion);

	return historialCotizaciones.back();
}

const vector<Cotizacion>& Vendedor::getHistorialCotizaciones()
{
	return historialCotizaciones;
}

void Vendedor::setTienda(const Tienda& tienda)
{
	this->tienda = &tienda;
}

const Tienda& Vendedor::getTienda() const {	return *tienda; }