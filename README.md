# Mytest

**Mi primer repositorio de GitHub — creado el 4 de marzo de 2019.**

Su contenido original era literalmente esto (`sample.c`, inmortalizado aquí):

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Hello world!");
    return 0;
}
```

con un README que decía *"This is a git repo"* 😄

## Por qué sigue vivo

No por el código — por lo que representa: el primer commit de todo. Este repo se queda como **monumento histórico**, pero en el revival (2026-10) recibió lo que le faltaba para ser un proyecto C pequeño pero bien hecho:

- **Función testeable**: `hello_greet(name)` separada del `main`, con buffer estático truncado de forma segura
- **7 checks** con un mini-framework de asserts (cero dependencias — ni CUnit)
- **Makefile**: `make`, `make test`, `make run`, `make clean`
- Compila limpio con `-Wall -Wextra -std=c99`

## Uso

```bash
make          # compila
make test     # corre los checks
make run      # ./hello y ./hello Fernando
```

## Tests

```bash
make test
```

Cubren: saludo por defecto (NULL y vacío), saludo con nombre, y truncado seguro ante nombres de 300 caracteres (sin overflow del buffer de 128).

## Licencia

MIT — ver [LICENSE](LICENSE).

## Autor

[FernandoMay](https://github.com/FernandoMay)
