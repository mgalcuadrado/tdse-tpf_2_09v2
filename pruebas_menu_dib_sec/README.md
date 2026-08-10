# Tests de escritorio para Menu, Secuencia y Dibujo

### 1. Armar la carpeta

Necesitás juntar en una misma carpeta:
- Los `.c`/`.h` reales del proyecto: `estado.*`, `menu_principal.*`,
  `menu_dibujo.*`, `menu_secuencia.*`, `dibujo.*`, `secuencia.c`,
  `boton.h`.
- La carpeta `mocks/` completa (con todos sus `.h` y `.c`).
- `test_framework.h`, `test_dibujo.c`, `test_menu.c` y `test_secuencia.c`.

Es decir, algo así:
```
mi_carpeta_de_tests/
├── estado.c / estado.h
├── menu_principal.c / menu_principal.h
├── menu_dibujo.c / menu_dibujo.h
├── menu_secuencia.c / menu_secuencia.h
├── dibujo.c / dibujo.h
├── secuencia.c
├── boton.h
├── test_framework.h
├── test_dibujo.c
├── test_menu.c
├── test_secuencia.c
└── mocks/
    ├── matriz.h / matriz_mock.c
    ├── lcd.h / lcd_mock.c
    ├── mem.h / mem_mock.c
    ├── frame_buffer.h / frame_buffer_mock.c
    ├── secuencia.h
    └── main.h / main_mock.c
```

### 2. Compilar y Correr

```bash
gcc -Wall -Wextra -I. -Imocks -o test_dibujo \
    test_dibujo.c dibujo.c \
    mocks/matriz_mock.c mocks/lcd_mock.c
```
```bash
gcc -Wall -Wextra -I. -Imocks -o test_menu \
    test_menu.c estado.c menu_principal.c menu_dibujo.c menu_secuencia.c \
    dibujo.c secuencia.c \
    mocks/matriz_mock.c mocks/lcd_mock.c mocks/frame_buffer_mock.c mocks/mem_mock.c mocks/main_mock.c

./test_menu
```

```bash
gcc -Wall -Wextra -I. -Imocks -o test_secuencia \
    test_secuencia.c secuencia.c \
    mocks/matriz_mock.c

./test_secuencia
```

## Qué prueba cada archivo

**`test_dibujo.c`** — lógica pura de `dibujo.c`, sin pasar por menús:
- Estado inicial de `dibujoCrear()`.
- Wrap-around del cursor en las 4 direcciones, con `tam_pincel=1` y
  con `tam_pincel=2`.
- `dibujoPintar()` pinta la cantidad correcta de celdas y con el color
  correcto, respetando el tamaño de pincel.
- `dibujoReiniciar()` apaga la matriz y resetea el cursor.
- `dibujoCambiarPincelTick()`: duplica/divide el pincel, hace
  wrap-around 1↔8, y devuelve `true` solo con ACEPTAR/ATRAS (la señal
  que usa `menu_dibujo.c` para saber cuándo volver al menú anterior).

**`test_menu.c`** — la máquina de estados completa, inyectando
eventos directo a `sistemaTick()` (sin pasar por `botonLeer()`, porque
esa función lee GPIO real y no tiene sentido mockearla para esto):
- `sistemaInit()` arranca en `ESTADO_MENU_PRINCIPAL`.
- `BOTON_NINGUNO` no cambia de estado ni reimprime nada — esto es
  justamente lo que confirma que `sistemaTick()` vuelve al instante
  en cada vuelta del loop, en vez de quedarse esperando.
- Recorrido completo Principal → Dibujo → Dibujando → vuelta.
- Navegación circular del menú de Dibujo (ARRIBA desde el primer ítem
  da la vuelta al último, "Cambiar Pincel") y su sub-estado.
- Recorrido completo Principal → Secuencia → Completando → vuelta, y
  que "Limpiar Secuencia" ejecuta la acción sin cambiar de pantalla.

**`test_secuencia.c`** — lógica pura de `secuencia.c`, sin pasar por
menús. Como `Secuencia_t` tiene todos sus campos visibles (no es un
puntero opaco), los tests escriben directamente `lista_sec`/`indice_sec`
para armar escenarios controlados, en vez de depender del patrón
aleatorio que genera `rand()` en `secuenciaCrear()`:
- Estado inicial: lista del usuario en 0, objetivo con solo valores
  `0`/`255`.
- Wrap-around de `secuenciaAvanzar()` en las 4 direcciones sobre la
  grilla `DIM_SECUENCIA x DIM_SECUENCIA`, y su guarda defensiva si
  `indice_sec` quedó fuera de rango.
- `secuenciaInsertarElemento()`: pinta el bloque correcto de celdas en
  la matriz, en la posición correcta de la lista, y no hace nada si
  `fil`/`col` están fuera de rango.
- `secuenciaElementoActual()` refleja lo insertado.
- `secuenciaVaciar()` apaga toda la lista del usuario.
- `secuenciaCompleta()` da `true` solo cuando la lista del usuario
  coincide exactamente con el objetivo.

**`test_secuencia.c`** — lógica pura de `secuencia.c` (sin modificar,
usa la tuya real), sin pasar por menús:
- Estado inicial de `secuenciaCrear()`: `indice_sec=0`, lista del
  usuario en 0, y la secuencia objetivo con solo valores 0/255.
- Wrap-around del cursor en las 4 direcciones dentro de la grilla
  `DIM_SECUENCIA x DIM_SECUENCIA`.
- La guarda defensiva de `secuenciaAvanzar()` cuando `indice_sec`
  quedó fuera de rango.
- `secuenciaInsertarElemento()`: pinta el bloque correcto de la matriz
  (solo canal azul, tal como está tu código), guarda el color en la
  posición correcta de la lista, y no hace nada si fila/columna están
  fuera de rango.
- `secuenciaElementoActual()`, `secuenciaVaciar()`.
- `secuenciaCompleta()`: solo da `true` cuando la lista del usuario
  coincide exactamente con la secuencia objetivo (que se genera al
  azar en `secuenciaCrear()` — el test la lee directo de la struct,
  ya que `Secuencia_t` no es un puntero opaco).

