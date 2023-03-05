#pragma once

#include "Prenda.h"
#include "TipoPantalon.h"

class Pantalon : public Prenda
{
public:
	Pantalon(const Calidad& calidad, const int& stock, const TipoPantalon& tipoPantalon);
private:
	const TipoPantalon tipoPantalon;
	static float porcentajeRebaja;
	float calcularRebajaPorTipo(const float& monto);
	void generarId() override;
	void generarDescripcion() override;
	float calcularPrecioFinal(const float& precioBase) override;
};