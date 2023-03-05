#include "Tienda.h"

#include <stdexcept>

Tienda::Tienda(string nombre, string direccion) : nombre{ std::move(nombre) }, direccion{ std::move(direccion) } {}

const string& Tienda::getNombre() const { return nombre; }

const string& Tienda::getDireccion() const { return direccion; }

void Tienda::agregarPrenda(unique_ptr<Prenda> prenda)
{
	if (prendas.find(prenda->getId()) != prendas.end())
	{
		throw runtime_error("Ingreso duplicado de prenda");
	}

	prendas[prenda->getId()] = std::move(prenda);
}

Prenda* Tienda::identificarPrenda(const string& id) const
{
	if (prendas.find(id) != prendas.end())
	{
		return prendas.at(id).get();
	}

	return nullptr;
}