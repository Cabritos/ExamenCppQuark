El presente es un sencillo programa que permite generar c�lculos de cotizaciones de prendas para una tienda ficticia.

Desde el men� principal se puede ver el Historial de cotizaciones (opci�n 1), generar una cotizaci�n nueva (opci�n 2) o salir del programa (ingresando X).

*---------------------*
Generar una cotizaci�n:
*---------------------*

El programa ofrecer� las distintas opciones de prendas y sus caracter�sticas, las cuales se pueden elegir ingresando 1 o 2.

En calquier momento se puede acceder al historial completo de cotizaciones ingresando H.

Tambi�n es posible abandonar la cotizaci�n actual y volver al men� principal con X.

Elegida la prenda, el programa ofrecer� indicar el precio incial de las prendas y la cantidad de unidades a cotizar, las cuales no deber�n superar el stock actual de cada una (este se mostrar� en la pantalla).

Cumplido esto se mostrar� el resultado de la cotizaci�n.

*----------------------*
C�culo de la cotizaci�n
*----------------------*

Al precio incial de cada prenda se le calcular�n aumentos o rebajas seg�n reglas preestablecidas correspondientes a las caracter�sticas de cada prenda. Esto dar� un precio final por unidad.

Este precio final por unidad se multiplicar� por la cantidad de unidades.

*------------------------*
Resultado de la cotizaci�n
*------------------------*

El resultado de la cotizaci�n mostrar� los datos con el siguiente formato:

Numero de identificacion: 1
Fecha y hora de la cotizacion: 05/03/23 18:48:45
Codigo del vendedor: 001
Penda: Camisa cuello comun manga corta calidad standard
Precio incial: $1.00
Precio final: $0.90
Unidades cotizadas: 100
Total cotizacion: $90.00

*--------------------*
Dependencias externas
*--------------------*

-string
-chorno
-ctime
-array
-bitset
-ostream
-stdexcept