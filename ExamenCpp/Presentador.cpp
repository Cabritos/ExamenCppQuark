#include <bitset>
#include <ostream>
#include <array>
#include "Pantalla.h"
#include "Presentador.h"
#include "Camisa.h"
#include "Pantalon.h"
#include "Vendedor.h"
#include "Tienda.h"
#include "TipoCuello.h"
#include "TipoManga.h"
#include "Vista.h"

void Presentador::ejecutar()
{
	registrarPrendasInciales();

	while (enEjecucion)
	{
		mostrarPantallaActual();
	}
}

void Presentador::registrarPrendasInciales()
{
	auto camisaMaoStandard = make_unique<Camisa>(CStandard, 100, MCorta, CMao);
	auto camisaMaoPremium = make_unique<Camisa>(CPremium, 100, MCorta, CMao);
	auto camisaStandard = make_unique<Camisa>(CStandard, 150, MCorta, CComun);
	auto camisaPremium = make_unique<Camisa>(CPremium, 150, MCorta, CComun);
	auto camisaMaoLargaStandard = make_unique<Camisa>(CStandard, 75, MLarga, CMao);
	auto camisaMaoLagaPremium = make_unique<Camisa>(CPremium, 75, MLarga, CMao);
	auto camisaLargaStandard = make_unique<Camisa>(CStandard, 175, MLarga, CComun);
	auto camisaLargaPremium = make_unique<Camisa>(CPremium, 175, MLarga, CComun);
	auto pantalonChupinStandard = make_unique<Pantalon>(CStandard, 750, PChupin);
	auto pantalonChupinPremium = make_unique<Pantalon>(CPremium, 750, PChupin);
	auto pantalonStandad = make_unique<Pantalon>(CStandard, 250, PComun);
	auto pantalonPremium = make_unique<Pantalon>(CPremium, 250, PComun);

	tienda.agregarPrenda(std::move(camisaMaoStandard));
	tienda.agregarPrenda(std::move(camisaMaoPremium));
	tienda.agregarPrenda(std::move(camisaStandard));
	tienda.agregarPrenda(std::move(camisaPremium));
	tienda.agregarPrenda(std::move(camisaMaoLargaStandard));
	tienda.agregarPrenda(std::move(camisaMaoLagaPremium));
	tienda.agregarPrenda(std::move(camisaLargaStandard));
	tienda.agregarPrenda(std::move(camisaLargaPremium));
	tienda.agregarPrenda(std::move(pantalonChupinStandard));
	tienda.agregarPrenda(std::move(pantalonChupinPremium));
	tienda.agregarPrenda(std::move(pantalonStandad));
	tienda.agregarPrenda(std::move(pantalonPremium));
}

void Presentador::mostrarPantallaActual()
{
	switch (pantallaActual)
	{
		case MenuPrincipal:
			mostrarPantallaMenu();
			break;
		case IngresoCotizacion:
			mostrarPantallaIngresoCotizcion();
			break;
		case ResultadoCotizacion:
			mostrarPantallaResultadoCotizacion();
			break;
		case HistorialCotizacion:
			mostrarPantallaHistorialCotizaciones();
			break;
	}
}

void Presentador::mostrarPantallaMenu()
{
	Vista::mostrarPantallaMenu(tienda.getNombre(), tienda.getDireccion(), vendedor.getNombre(), vendedor.getApellido(),
		vendedor.getCodigo());

	string input;

	while (true)
	{
		Vista::registrarInput(input);

		if (input == "x" || input == "X")
		{
			enEjecucion = false;
			break;
		}

		if (input == "1")
		{
			pantallaActual = HistorialCotizacion;
			break;
		}

		if (input == "2")
		{
			pantallaActual = IngresoCotizacion;
			break;
		}

		Vista::mostrarMensaje("\nIngrese una opcion valida:\n");
	}
}

void Presentador::mostrarPantallaIngresoCotizcion()
{
	/*
		Codigo de prenda:
		4 = prenda
		3 = largo mangas
		2 = tipo cuello
		1 = tipo de pantalon
		0 = calidad
	*/
	bitset<5> codigoPrenda;
	mostrarOpcionesPrendas(codigoPrenda);
}

bool Presentador::mostrarOpciones()
{
	string input;

	while (true)
	{
		Vista::registrarInput(input);

		if (input == "x" || input == "X")
		{
			pantallaActual = MenuPrincipal;
			break;
		}

		if (input == "h" || input == "H")
		{
			Vista::insertarSeparador('-');
			Vista::mostrarMensaje("HISTORIAL DE COTIZACIONES:\n");
			insertarHistorialCotizaciones();
			Vista::mostrarMensaje("\nIngrese una opcion:\n");
			continue;
		}

		if (input != "1" && input != "2")
		{
			Vista::mostrarMensaje("\nIngrese una opcion valida:\n");
			continue;
		}

		return input == "2";
	}
}

void Presentador::mostrarOpcionesPrendas(bitset<5>& codigoPrenda)
{
	Vista::mostrarPantallaIngresoCotizacion();

	codigoPrenda[4] = mostrarOpciones(); //Devuelve true si es pantalon
	if (pantallaActual == MenuPrincipal) return;
	if (codigoPrenda[4]) mostrarOpcionesTipoPantalon(codigoPrenda);
	else mostrarOpcionesMangaCamisa(codigoPrenda);
}

void Presentador::mostrarOpcionesMangaCamisa(bitset<5>& codigoPrenda)
{
	Vista::mostrarOpcionesMangaCamisa();

	codigoPrenda[3] = mostrarOpciones(); //Devuelve true si es manga larga
	if (pantallaActual == MenuPrincipal) return;
	mostrarOpcionesCuelloCamisa(codigoPrenda);
}

void Presentador::mostrarOpcionesCuelloCamisa(bitset<5>& codigoPrenda)
{
	Vista::mostrarOpcionesCuelloCamisa();

	codigoPrenda[2] = mostrarOpciones(); //Devuelve true si es cuello mao
	if (pantallaActual == MenuPrincipal) return;
	mostrarOpcionesCalidad(codigoPrenda);
}

void Presentador::mostrarOpcionesCalidad(bitset<5>& codigoPrenda)
{
	Vista::mostrarOpcionesCalidad();

	codigoPrenda[0] = mostrarOpciones(); //Devuelve true si es premium
	if (pantallaActual == MenuPrincipal) return;
	mostrarIngresoDePrecio(codigoPrenda);
}

void Presentador::mostrarOpcionesTipoPantalon(bitset<5>& codigoPrenda)
{
	Vista::mostrarOpcionesTipoPantalon();

	codigoPrenda[1] = mostrarOpciones(); //Devuelve true si es chupin
	if (pantallaActual == MenuPrincipal) return;
	mostrarOpcionesCalidad(codigoPrenda);
}

void Presentador::mostrarIngresoDePrecio(bitset<5>& codigoPrenda)
{
	Vista::mostrarIngresoDePrecio();

	string input;
	float precio = 0;

	while (true)
	{
		Vista::registrarInput(input);

		if (input == "x" || input == "X")
		{
			pantallaActual = MenuPrincipal;
			break;
		}

		if (input == "h" || input == "H")
		{
			insertarHistorialCotizaciones();
			Vista::mostrarMensaje("\nIngrese un precio:\n");
			continue;
		}

		try {
			precio = stof(input);
		}
		catch (const invalid_argument& e)
		{
			Vista::mostrarMensaje("\nIngrese un numero superior a cero:\n");
			continue;
		}

		if (precio <= 0)
		{
			Vista::mostrarMensaje("\nIngrese un numero superior a cero:\n");
			continue;
		}

		break;
	}

	if (pantallaActual == MenuPrincipal) return;
	mostrarIngresoDeCantidad(codigoPrenda, precio);
}

void Presentador::mostrarIngresoDeCantidad(bitset<5>& codigoPrenda, float precio)
{
	const auto codigo = codigoPrenda.to_string();
	Prenda* prenda = tienda.identificarPrenda(codigo);

	Vista::mostrarIngresoDeCantidad(prenda->getStock());

	string input;
	int cantidad;

	while (true)
	{
		Vista::registrarInput(input);

		if (input == "x" || input == "X")
		{
			pantallaActual = MenuPrincipal;
			break;
		}

		if (input == "h" || input == "H")
		{
			Vista::insertarSeparador('-');
			Vista::mostrarMensaje("HISTORIAL DE COTIZACIONES:\n");
			insertarHistorialCotizaciones();
			Vista::mostrarMensaje("\nIngrese una opcion:\n");
			continue;
		}

		try {
			cantidad = stof(input);
		}
		catch (const invalid_argument& e) {
			Vista::mostrarMensaje("\nIngrese un numero entero sueperior a cero:\n");
			continue;
		}

		if (cantidad <= 0)
		{
			Vista::mostrarMensaje("\nIngrese un numero entero sueperior a cero:\n");
			continue;
		}

		if (prenda->getStock() < cantidad)
		{
			Vista::mostrarMensaje("\nIngrese una cantidad menor o igual al stock actual:\n");
			continue;
		}

		break;
	}

	if (pantallaActual == MenuPrincipal) return;

	vendedor.cotizar(prenda, cantidad, precio);

	pantallaActual = ResultadoCotizacion;
}

array<string, 8> Presentador::convertirCotizacionAStringArray(const Cotizacion& cotizacion) const
{
	auto precioBase = to_string(cotizacion.getPrecioBase());
	precioBase = precioBase.substr(0, precioBase.find('.') + 3);

	auto precioFinal = to_string(cotizacion.getPrecioFinal());
	precioFinal = precioFinal.substr(0, precioFinal.find('.') + 3);

	auto resultadoCotizacion = to_string(cotizacion.getResultado());
	resultadoCotizacion = resultadoCotizacion.substr(0, resultadoCotizacion.find('.') + 3);

	array<string, 8> resultado
	{
		to_string(cotizacion.getId()),
		cotizacion.getFechaYHora(),
		cotizacion.getCodigoVendedor(),
		cotizacion.getPrenda(),
		precioBase,
		precioFinal,
		to_string(cotizacion.getCantidad()),
		resultadoCotizacion
	};

	return resultado;
};

void Presentador::mostrarPantallaResultadoCotizacion()
{
	const auto ultimaCotizacion = historial.back();
	const auto cotizacion = convertirCotizacionAStringArray(ultimaCotizacion);

	Vista::mostrarPantallaResultadoCotizacion(cotizacion);
	Vista::insertarEsperaInput();

	pantallaActual = MenuPrincipal;
}

void Presentador::mostrarPantallaHistorialCotizaciones()
{
	Vista::mostrarPantallaHistorialCotizaciones();
	insertarHistorialCotizaciones();
	Vista::insertarEsperaInput();

	pantallaActual = MenuPrincipal;
}

void Presentador::insertarHistorialCotizaciones() const
{
	if (historial.empty())
	{
		Vista::mostrarMensaje("\nEl historial esta vacio.\n");
	}
	else
	{
		for (const auto& cotizacion : historial)
		{
			const auto cotizacionString = convertirCotizacionAStringArray(cotizacion);

			Vista::insertarCotiacion(cotizacionString);
			Vista::insertarSeparador('-');
		}
	}
}