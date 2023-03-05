#include <bitset>
#include "Pantalon.h"

Pantalon::Pantalon(const Calidad& calidad, const int& stock, const TipoPantalon& tipoPantalon) :
	Prenda(calidad, stock), tipoPantalon{ tipoPantalon }
{
	generarId();
	generarDescripcion();
}

float Pantalon::calcularRebajaPorTipo(const float& monto)
{
	return (monto * porcentajeRebaja) / 100;
}

void Pantalon::generarId()
{
	bitset<5> codigo;

	codigo[4] = true;
	if (tipoPantalon == PChupin) codigo[1] = true;
	if (calidad == CPremium) codigo[0] = true;

	id = codigo.to_string();
}

void Pantalon::generarDescripcion()
{
	const string tipo = tipoPantalon == PComun ? "comun" : "chupin";
	const string cal = calidad == CStandard ? "standard" : "premium";

	descripcion = "Pantalon corte " + tipo + " calidad " + cal;
}

float Pantalon::calcularPrecioFinal(const float& precioBase)
{
	auto calculo = precioBase;

	if (tipoPantalon == PChupin) calculo -= calcularRebajaPorTipo(calculo);
	calculo += calcularVariacionPorCalidad(calculo);

	const int redondeo = static_cast<int>(calculo * 100);
	const float resultado = redondeo / 100.0;

	return resultado;
}

float Pantalon::porcentajeRebaja = 12;