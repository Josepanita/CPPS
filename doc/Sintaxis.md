# Sintaxis

CPPS posee una sintaxis parecida a la de PHP/C, cada linea debe terminarse con un punto y coma.

	imprimir("Esto es una funcion standard del interprete");

Toda la sintaxis explicada en este archivo es en español, la sintaxis clasica (en ingles), tambien esta permitida.

## Operadores

Los operadores de este interprete son los mas comunes.

<table>
	<tr>
		<td>Suma</td>
		<td>+</td>
		<td>Resta</td>
		<td>-</td>
		<td>Producto</td>
		<td>*</td>
	</tr>
	<tr>
		<td colspan="2"><code>3 + 4 // = 7</code></td>
		<td colspan="2"><code>7 - 3 // = 4</code></td>
		<td colspan="2"><code>2 * 3 // = 6</code></td>
	</tr>
	<tr>
		<td>Division</td>
		<td>/</td>
		<td>Modulo</td>
		<td>%</td>
		<td>Concatenacion</td>
		<td>@</td>
	</tr>
	<tr>
		<td colspan="2"><code>9 / 3 // = 3</code></td>
		<td colspan="2"><code>3 % 2 // = 1</code></td>
		<td colspan="2"><code>"Hola, " @ "Mundo!" // = "Hola, Mundo!"</code></td>
	</tr>
</table>

## Variables

Las variables se prefixan con `%` para locales `$` para locales.

	%local = "hola";
	$global = "mundo";

Las variables globales (`$`), pueden ser declaradas dentro del ambito de una funcion no obstante siguen siendo globales, se eliminan cuando el script termina.

Mientras que las variables locales (`%`), si se declaran en el ambito global no pueden accesar a ellas en un ambito de funcion. Si son declaradas en el ambito de una funcion, estaran disponibles SOLO bajo el ambito de la funcion.

Para ver un ejemplo vea el [test](../tests/07_ambitos.cpps) `07_ambitos.cpps`

## Tipos de datos

En CPPS los tipos de datos escenciales son Enteros (int), Reales (double), Cadenas (strings).

	%x = 0; // Entero
	%y = "Test"; // Cadena
	%z = 3.14169; // Real
	%w = "Lorem " @ "ipsum"; // Cadena con Concatenacion

## Funciones

Una simple declaracion de funcion

	funcion imprime_linea(%cadena) {
		// esta funcion es parte de la libreria standard de CPPS 
		// vea stdlib.cpp
		// usa escape de caracteres al estilo C
		imprimir(%cadena @ "\\n");
	}

y se llaman igual que en C

	imprime_linea("Hola, Mundo!");


## Bucles

Igual que C/PHP

### While/Mientras
	
	mientras( /*<condicion>*/ ){
		// codigo
	}

Ejemplo
	
	%x = 0;
	mientras(%x > 10){
		imprimir(%x @ "\n");
		%x++;
	}

### For/Para

	para( /* <inicializacion> */; /* <condicion> */; /* <incremento> */){
		// codigo
	}

Ejemplo
	
	para(%x = 0; %x < 10; %x++){
		imprimir(%x @ "\n");
		%x++;
	}

podemos omitir la inicializacion como en C
	%x = 0;
	para(; %x<10; %x++){
		imprimir(%x @ "\n");
		%x++;
	}

## Arreglos 

En CPPS los arreglos no son en *realidad* arreglos, lo que sucede es que la expresion en los indices del array es concatenada a la varaible que los posee con un `_` como separador.

En el [test](../tests/08_arrays.cpps) `08_arrays.cpps` se ve claramente que se puede acceder al indice de un array de la forma clasica `%var[<numero>]` ó `%var_<numero>`.
