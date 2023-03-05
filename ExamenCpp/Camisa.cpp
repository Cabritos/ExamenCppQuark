#include<bitset>
#include "Camisa.h"

Camisa::Camisa(const Calidad& calidad, const int& stock, const TipoManga& tipoManga, const TipoCuello& tipoCuello) :
	Prenda(calidad, stock), tipoManga{ tipoManga }, tipoCuello{ tipoCuello }
{
	generarId();
	generarDescripcion();
}

float Camisa::calcularRebajaPorManga(const float& monto)
{
	return (monto * porcentajeRebaja) / 100;
}

float Camisa::calcularAumentoPorCuello(const float& monto)
{
	return (monto * porcentajeAumento) / 100;
}

void Camisa::generarId()
{
	bitset<5> codigo;

	if (tipoManga == MLarga) codigo[3] = true;
	if (tipoCuello == CMao) codigo[2] = true;
	if (calidad == CPremium) codigo[0] = true;

	id = codigo.to_string();
}

void Camisa::generarDescripcion()
{
	const string cuello = tipoCuello == CComun ? "comun" : "mao";
	const string manga = tipoManga == MCorta ? "corta" : "larga";
	const string cal = calidad == CStandard ? "standard" : "premium";

	descripcion = "Camisa cuello " + cuello + " manga " + manga + " calidad " + cal;
}

float Camisa::calcularPrecioFinal(const float& precioBase)
{
	auto calculo = precioBase;

	if (tipoManga == MCorta) calculo -= calcularRebajaPorManga(calculo);
	if (tipoCuello == CMao) calculo += calcularAumentoPorCuello(calculo);
	calculo += calcularVariacionPorCalidad(calculo);

	const int redondeo = static_cast<int>(calculo * 100 );
	const float resultado = redondeo / 100.0;

	return resultado;
}

float Camisa::porcentajeRebaja = 10;

float Camisa::porcentajeAumento = 3;