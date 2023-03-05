El presente es un sencillo programa que permite generar cálculos de cotizaciones de prendas para una tienda ficticia.

Desde el menú principal se puede ver el Historial de cotizaciones (opción 1), generar una cotización nueva (opción 2) o salir del programa (ingresando X).

*---------------------*
Generar una cotización:
*---------------------*

El programa ofrecerá las distintas opciones de prendas y sus características, las cuales se pueden elegir ingresando 1 o 2.

En calquier momento se puede acceder al historial completo de cotizaciones ingresando H.

También es posible abandonar la cotización actual y volver al menú principal con X.

Elegida la prenda, el programa ofrecerá indicar el precio incial de las prendas y la cantidad de unidades a cotizar, las cuales no deberán superar el stock actual de cada una (este se mostrará en la pantalla).

Cumplido esto se mostrará el resultado de la cotización.

*----------------------*
Cáculo de la cotización
*----------------------*

Al precio incial de cada prenda se le calcularán aumentos o rebajas según reglas preestablecidas correspondientes a las características de cada prenda. Esto dará un precio final por unidad.

Este precio final por unidad se multiplicará por la cantidad de unidades.

*------------------------*
Resultado de la cotización
*------------------------*

El resultado de la cotización mostrará los datos con el siguiente formato:

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