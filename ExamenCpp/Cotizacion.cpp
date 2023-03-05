#include <string>
#include <chrono>
#include <ctime>
#include "Cotizacion.h"

Cotizacion::Cotizacion(string codigoVendedor, Prenda* prenda, const int& cantidad, const float& precioBase) :
	codigoVendedor{ std::move(codigoVendedor) }, cantidad{ cantidad }, precioBase{ precioBase }
{
	cantidadCotizaciones++;
	id = cantidadCotizaciones;
	descripcionPrenda = prenda->getDescripcion();
	setFechaYHora();
	precioFinal = prenda->calcularPrecioFinal(precioBase);

	resultado = precioFinal * cantidad;
}

const int& Cotizacion::getId() const { return id; }

const string& Cotizacion::getFechaYHora() const { return fechaYHora; }

const string& Cotizacion::getCodigoVendedor() const { return codigoVendedor; }

const string& Cotizacion::getPrenda() const { return descripcionPrenda; }

const int& Cotizacion::getCantidad() const { return cantidad; }

const float& Cotizacion::getPrecioBase() const { return precioBase; }

const float& Cotizacion::getPrecioFinal() const { return precioFinal; }

const float& Cotizacion::getResultado() const {	return resultado; }

void Cotizacion::setFechaYHora()
{
	const auto ahora = std::chrono::system_clock::now();
	const auto conversion = std::chrono::system_clock::to_time_t(ahora);

	tm tiempo;
	localtime_s(&tiempo, &conversion);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "%d/%m/%y %H:%M:%S", &tiempo);

	fechaYHora = string(buffer);
}

int Cotizacion::cantidadCotizaciones = 0;