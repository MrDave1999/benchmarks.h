# benchmarks.h

Este header file te permite hacer una prueba de rendimiento de una manera simplificada.

# Macros

- `start_bm()` = Inicia la prueba de rendimiento.
- `end_bm(texto)` = Termina la prueba de rendimiento con un mensaje adicional.
- `MAX_ITERS` = Determina la cantidad de iteraciones que tendrá el código.

```C
#define MAX_ITERS 10000 //El código se ejecutará 10000 veces
#include "benchmarks.h"
```
- `SECONDS` = Indica que el resultado de la prueba será en segundos.

```C
#define SECONDS
#include "benchmarks.h"
```
- `MILISECONDS` = Indica que el resultado de la prueba será en milisegundos.

```C
#define MILISECONDS
#include "benchmarks.h"
```
- `MICROSECONDS` = Indica que el resultado de la prueba será en microsegundos.

```C
#define MICROSECONDS
#include "benchmarks.h"
```
- `NANOSECONDS` = Indica que el resultado de la prueba será en nanosegundos.

```C
#define NANOSECONDS
#include "benchmarks.h"
```
Sí no agregas ninguna definición, por defecto será en `MILISECONDS`.

# Sintaxis

```C
#include "benchmarks.h"

int main(void)
{
	start_bm()
		//code
	end_bm(Mensaje1); //El mensaje va sin las comillas dobles

	start_bm()
		//code
	end_bm(Mensaje2); //El mensaje va sin las comillas dobles
  
	return 0;
}
```

# Código de Prueba
```C
#include "benchmarks.h"

int main(void)
{
	int array[10];
	int v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;
	start_bm()
		v1 = 0;
		v2 = 1;
		v3 = 2;
		v4 = 3;
		v5 = 4;
		v6 = 5;
		v7 = 6;
		v8 = 7;
		v9 = 8;
		v10 = 9;
	end_bm(Variables);

	start_bm()
		array[0] = 0;
		array[1] = 1;
		array[2] = 2;
		array[3] = 3;
		array[4] = 4;
		array[5] = 5;
		array[6] = 6;
		array[7] = 7;
		array[8] = 8;
		array[9] = 9;
	end_bm(Arrays);
	return 0;
}
```

# Resultado en Pantalla
[![resultado](https://i.imgur.com/OPgBKse.png)](https://github.com/MrDave1999)

# Créditos

- [MrDave](https://github.com/MrDave1999) 
	- Por el desarrollo de pscanf.h
- [Microsoft Corporation](https://github.com/Microsoft) 
	- Se usó el compilador `cl.exe` para poder compilar los códigos de prueba, de ese modo se comprueba sí no hubo algún error.
