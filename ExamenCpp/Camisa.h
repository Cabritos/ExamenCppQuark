#pragma once

#include "Prenda.h"
#include "TipoCuello.h"
#include "TipoManga.h"

class Camisa : public Prenda
{
public:
	Camisa(const Calidad& calidad, const int& stock, const TipoManga& tipoManga, const TipoCuello& tipoCuello);
private:
	const TipoManga tipoManga;
	const TipoCuello tipoCuello;
	static float porcentajeRebaja;
	static float porcentajeAumento;
	static float calcularRebajaPorManga(const float& monto);
	static float calcularAumentoPorCuello(const float& monto);
	void generarId() override;
	void generarDescripcion() override;
	float calcularPrecioFinal(const float& precioBase) override;
};