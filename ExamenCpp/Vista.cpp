#include <iostream>
#include <array>
#include "Vista.h"

using namespace std;

void Vista::mostrarPantallaMenu(const string& nombreTienda, const string& direccion, const string& nombreVendedor,
	const string& apellidoVendedor, const string& codigoVendedor)
{
	limpiarPantalla();
	insertarEncabezado("MENU PRINCIPAL");
	cout << nombreVendedor << " " << apellidoVendedor << " - " << codigoVendedor << endl;
	insertarSeparador('*');
	cout << endl;
	cout << "SELECCIONE UNA OPCION" << endl << endl;
	cout << "	1) Ver historial de cotizaciones" << endl;
	cout << "	2) Realizar nueva cotizacion" << endl;
	cout << "	X) Salir" << endl << endl;
}

void Vista::mostrarPantallaIngresoCotizacion()
{
	limpiarPantalla();
	insertarEncabezadoConRetorno("COTIZACION");
	cout << "PASO 1: Seleccione la prenda a cotizar:" << endl << endl;
	cout << "	1) Camisa" << endl;
	cout << "	2) Pantalon" << endl << endl;
}

void Vista::registrarInput(string& salida)
{
	cin >> salida;
}

void Vista::mostrarMensaje(const string& mensaje)
{
	cout << mensaje << endl;
}

void Vista::limpiarPantalla()
{
	system("cls");
}

void Vista::mostrarOpcionesMangaCamisa()
{
	limpiarPantalla();
	insertarEncabezadoConRetorno("COTIZACION");
	cout << "PASO 2.1: Elija el tipo de manga:" << endl << endl;
	cout << "	1) Manga corta" << endl;
	cout << "	2) Manga larga" << endl << endl;
}

void Vista::mostrarOpcionesCuelloCamisa()
{
	limpiarPantalla();
	insertarEncabezadoConRetorno("COTIZACION");
	cout << "PASO 2.2: Elija el tipo de cuello:" << endl << endl;
	cout << "	1) Cuello comun" << endl;
	cout << "	2) Cuello Mao" << endl << endl;
}

void Vista::mostrarOpcionesCalidad()
{
	limpiarPantalla();
	insertarEncabezadoConRetorno("COTIZACION");
	cout << "PASO 2.3: Elija la calidad de la prenda:" << endl << endl;
	cout << "	1) Calidad comun" << endl;
	cout << "	2) Calidad premium" << endl << endl;
}

void Vista::mostrarOpcionesTipoPantalon()
{
	limpiarPantalla();
	insertarEncabezadoConRetorno("COTIZACION");
	cout << "PASO 2.3: Elija la calidad de la prenda:" << endl << endl;
	cout << "	1) Pantalon comun" << endl;
	cout << "	2) Pantalon chupin" << endl << endl;
}

void Vista::mostrarIngresoDePrecio()
{
	limpiarPantalla();
	insertarEncabezadoConRetorno("COTIZACION");
	cout << "PASO 3: Ingrese el valor unitario de la prenda a cotizar:" << endl << endl;
}

void Vista::mostrarIngresoDeCantidad(const int& stock)
{
	limpiarPantalla();
	insertarEncabezadoConRetorno("COTIZACION");
	cout << "PASO 4: Ingrese la cantidad de unidades a cotizar." << endl << endl;
	cout << "El stock actual es de " << stock << " unidades." << endl << endl;
}

void Vista::mostrarPantallaResultadoCotizacion(const array<string, 8>& cotizacion)
{
	limpiarPantalla();
	insertarEncabezado("RESULTADO DE COTIZACION");
	insertarCotiacion(cotizacion);
}

void Vista::mostrarPantallaHistorialCotizaciones()
{
	limpiarPantalla();
	insertarEncabezado("HISTORIAL DE COTIZACIONES");
}

void Vista::insertarCotiacion(const array<string, 8>& cotizacion)
{
	cout << endl;
	cout << "Numero de identificacion: " << cotizacion[0] << endl;
	cout << "Fecha y hora de la cotizacion: " << cotizacion[1] << endl;
	cout << "Codigo del vendedor: " << cotizacion[2] << endl;
	cout << "Penda: " << cotizacion[3] << endl;
	cout << "Precio incial: $" << cotizacion[4] << endl;
	cout << "Precio final: $" << cotizacion[5] << endl;
	cout << "Unidades cotizadas: " << cotizacion[6] << endl;
	cout << "Total cotizacion: $" << cotizacion[7] << endl;
	cout << endl;
}

void Vista::insertarSeparador(const char& separador)
{
	cout << string(60, separador) << endl;
}

void Vista::insertarEncabezado(const string& tituloPantalla)
{
	insertarSeparador('*');
	cout << "MAXICOTIZADOR - " << tituloPantalla << endl;
	insertarSeparador('-');
}

void Vista::insertarEncabezadoConRetorno(const string& tituloPantalla)
{
	insertarSeparador('*');
	cout << "MAXICOTIZADOR -  " << tituloPantalla << endl;
	insertarSeparador('-');
	cout << "Ingresa X para volver al menu principal" << endl;
	cout << "Ingresa H para mostrar el historial de cotizaciones" << endl;
	insertarSeparador('*');
	cout << endl;
}

void Vista::insertarEsperaInput()
{
	system("pause");
}