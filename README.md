# TADs

Repositorio de **Tipos Abstractos de Datos (TADs) genéricos en C++**, implementados con programación orientada a objetos y plantillas (`template <typename T>`), de forma que cada estructura funcione con cualquier tipo de dato: `Lista<int>`, `Lista<std::string>`, `Lista<MiClase>`, etc.

## Estructura

```
TADs/
└── TADs_base/
    ├── CMakeLists.txt
    ├── main.cpp            # pruebas de uso de los TADs
    └── Biblioteca/
        ├── Nodo.h          # nodo genérico: dato + puntero al siguiente
        └── Lista.h         # lista simplemente enlazada genérica
```

## TADs

| TAD     | Descripción                                                        | Estado         |
|---------|--------------------------------------------------------------------|----------------|
| `Nodo`  | Unidad básica: guarda un dato de tipo `T` y un puntero al siguiente | Implementado   |
| `Lista` | Lista simplemente enlazada con punteros a inicio y fin             | En desarrollo  |

Se irán agregando más TADs a la tabla conforme se implementen.

### `Lista<T>` — operaciones actuales

- `Lista()` — crea una lista vacía.
- `Lista(const Lista&)` — copia profunda: crea nodos nuevos, la copia es independiente de la original.
- `~Lista()` — libera todos los nodos.
- `insertarDatoInicio(dato)` — inserta al principio.
- `insertarDatoFinal(dato)` — inserta al final en tiempo constante gracias al puntero `fin`.
- `get_num_nodos()` — número de elementos.

## Decisiones de diseño

- **Implementación en los `.h`.** Al ser plantillas, el compilador necesita ver el cuerpo de las funciones donde se usan con un tipo concreto, por eso no hay `.cpp` para los TADs.
- **El dato se guarda por valor (`T dato`)**, no como puntero. Así cada nodo tiene su propia copia y quien usa el TAD decide si quiere guardar valores (`Lista<int>`) o punteros (`Lista<int*>`).
- **La lista es dueña de sus nodos.** Ella los crea, los enlaza y los destruye; el `Nodo` no gestiona memoria.
- **Encapsulamiento.** Los atributos son privados; el acceso a los punteros internos de la lista es privado para que no se pueda romper la estructura desde fuera.

## Cómo compilar

Requiere CMake y un compilador con soporte de C++20.

Con CLion: abrir la carpeta `TADs_base` y ejecutar.

Desde terminal:

```bash
cd TADs_base
cmake -S . -B build
cmake --build build
./build/TADs_base
```

## Ejemplo

```cpp
#include "Biblioteca/Lista.h"

int main() {
    Lista<int> numeros;
    numeros.insertarDatoInicio(1);
    numeros.insertarDatoFinal(10);

    Lista<int> copia(numeros); // copia independiente
    return 0;
}
```
