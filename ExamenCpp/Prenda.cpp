#include "Prenda.h"

Prenda::Prenda(const Calidad& calidad, const int& stock) : calidad{ calidad }, stock{ stock } {}

Prenda::~Prenda()
{
}

const string& Prenda::getId() const { return id; }

const int& Prenda::getStock() const { return stock; }

const string& Prenda::getDescripcion() const { return descripcion; }

bool Prenda::haySuficienteStock(const int& cantidadAControlar) const
{
	return stock >= cantidadAControlar;
}

float Prenda::calcularVariacionPorCalidad(const float& monto) const
{
	return calidad == CPremium ? (monto * porcentajeAumentoPremium) / 100 : 0;
}

float Prenda::porcentajeAumentoPremium = 30;