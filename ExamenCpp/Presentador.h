#pragma once

#include <bitset>
#include <array>
#include "Presentador.h"
#include "Vendedor.h"
#include "Tienda.h"
#include "Vista.h"
#include "Pantalla.h"

class Presentador
{
public:
	void ejecutar();
private:
	bool enEjecucion = true;
	Vista vista;
	Vendedor vendedor = { "Manuel", "Fuentes", "001" };
	Tienda tienda = { "Lo de Manolo", "Av. Mayo 955" };
	Pantalla pantallaActual = MenuPrincipal;
	const vector<Cotizacion>& historial = vendedor.getHistorialCotizaciones();
	void registrarPrendasInciales();
	void mostrarPantallaActual();
	void mostrarPantallaMenu();
	void mostrarPantallaIngresoCotizcion();
	bool mostrarOpciones();
	void mostrarOpcionesPrendas(bitset<5>& codigoPrenda);
	void mostrarOpcionesMangaCamisa(bitset<5>& codigoPrenda);
	void mostrarOpcionesCuelloCamisa(bitset<5>& codigoPrenda);
	void mostrarOpcionesCalidad(bitset<5>& codigoPrenda);
	void mostrarOpcionesTipoPantalon(bitset<5>& codigoPrenda);
	void mostrarIngresoDePrecio(bitset<5>& codigoPrenda);
	void mostrarIngresoDeCantidad(bitset<5>& codigoPrenda, float precio);
	array<string, 8> convertirCotizacionAStringArray(const Cotizacion& cotizacion) const;
	void mostrarPantallaResultadoCotizacion();
	void mostrarPantallaHistorialCotizaciones();
	void insertarHistorialCotizaciones() const;
};