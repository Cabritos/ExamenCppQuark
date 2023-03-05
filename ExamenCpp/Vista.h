#pragma once

using namespace std;

class Vista
{
public:
	static void mostrarPantallaMenu(const string& nombreTienda, const string& direccion,
		const string& nombreVendedor, const string& apellidoVendedor, const string& codigoVendedor);
	static void mostrarPantallaIngresoCotizacion();
	static void registrarInput(string& salida);
	static void mostrarMensaje(const string& mensaje);
	static inline void limpiarPantalla();
	static void mostrarOpcionesMangaCamisa();
	static void mostrarOpcionesCuelloCamisa();
	static void mostrarOpcionesCalidad();
	static void mostrarOpcionesTipoPantalon();
	static void mostrarIngresoDePrecio();
	static void mostrarIngresoDeCantidad(const int& stock);
	static void mostrarPantallaResultadoCotizacion(const array<string, 8>& cotizacion);
	static void mostrarPantallaHistorialCotizaciones();
	static void insertarCotiacion(const array<string, 8>& cotizacion);
	static void insertarSeparador(const char& separador);
	static void insertarEncabezado(const string& tituloPantalla);
	static void insertarEncabezadoConRetorno(const string& tituloPantalla);
	static void insertarEsperaInput();
};