#pragma once

#include <string>
#include "Calidad.h"

using namespace std;

class Prenda
{
public:
	Prenda(const Calidad& calidad, const int& stock);
	virtual ~Prenda();
	const string& getId() const;
	const int& getStock() const;
	const string& getDescripcion() const;
	bool haySuficienteStock(const int& cantidadAControlar) const;
	virtual float calcularPrecioFinal(const float& precioBase) = 0;
protected:
	string id;
	string descripcion;
	Calidad calidad;
	int stock;
	static float porcentajeAumentoPremium;
	float calcularVariacionPorCalidad(const float& monto) const;
	virtual void generarId() = 0;
	virtual void generarDescripcion() = 0;
};