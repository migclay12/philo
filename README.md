# 🍴 Dining Philosophers Problem

![Build Status](https://github.com/tu-usuario/philo/workflows/CI/badge.svg)
![License](https://img.shields.io/badge/license-42-blue.svg)
![C](https://img.shields.io/badge/C-99-green.svg)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS-lightgrey.svg)
[![42 School](https://img.shields.io/badge/42-Project-orange.svg)](https://42.fr)

Una implementación concurrente del clásico problema de los filósofos comensales en C usando hilos POSIX (pthreads).

## 📖 Descripción

Este proyecto simula el **problema de los filósofos comensales**, un problema clásico de sincronización en programación concurrente. Los filósofos alternan entre pensar, comer y dormir, compartiendo un número limitado de tenedores (forks) que deben ser tomados en pares para poder comer.

## 🎯 Características

- ✅ **Sincronización con mutexes** para evitar condiciones de carrera
- ✅ **Detección de inanición** (starvation) y muerte de filósofos
- ✅ **Gestión de argumentos flexible** (4-5 argumentos)
- ✅ **Mensajes coloreados** para mejor visualización
- ✅ **Manejo de casos especiales** (un solo filósofo)
- ✅ **Límite de comidas opcional**
- ✅ **Gestión robusta de memoria y recursos**

## 🚀 Compilación y Uso

### Compilación
```bash
make
```

### Ejecución
```bash
# Sintaxis básica: número_de_filósofos tiempo_para_morir tiempo_para_comer tiempo_para_dormir
./philo 5 800 200 200

# Con límite de comidas: [número_de_veces_que_cada_filósofo_debe_comer]
./philo 5 800 200 200 7
```

### Parámetros
- `número_de_filósofos`: Número de filósofos (1-200)
- `tiempo_para_morir`: Tiempo en ms después del cual un filósofo muere si no ha comido
- `tiempo_para_comer`: Tiempo en ms que tarda un filósofo en comer
- `tiempo_para_dormir`: Tiempo en ms que tarda un filósofo en dormir
- `número_de_comidas` (opcional): Límite de veces que cada filósofo debe comer

## 📋 Ejemplos de Uso

### Ejemplo 1: Filósofos básicos
```bash
./philo 4 410 200 200
```
Salida esperada:
```
145ms  1  has taken a fork
146ms  1  has taken a fork
146ms  1  is eating
346ms  1  is sleeping
546ms  1  is thinking
...
```

### Ejemplo 2: Con límite de comidas
```bash
./philo 3 610 200 100 5
```
Los filósofos se detendrán después de que cada uno haya comido 5 veces.

### Ejemplo 3: Caso especial (1 filósofo)
```bash
./philo 1 800 200 200
```
El filósofo tomará un tenedor y morirá después de 800ms.

## 🔧 Limpieza
```bash
make clean    # Eliminar archivos objeto
make fclean   # Eliminar ejecutable y archivos objeto
make re       # Recompilar todo
```

## 📁 Estructura del Proyecto

```
philo/
├── 📁 src/                 # Código fuente
│   ├── philo.h            # Cabeceras y definiciones
│   ├── main.c             # Función principal y gestión de threads
│   ├── parser.c           # Parsing y validación de argumentos
│   ├── philo_life.c       # Lógica principal de los filósofos
│   ├── dead.c             # Detección de muerte e inanición
│   ├── utils.c            # Utilidades (tiempo, impresión, etc.)
│   └── functions.c        # Implementaciones de funciones básicas
├── 📁 examples/           # Casos de uso y configuraciones
├── 📁 .github/            # Configuración de GitHub Actions
├── Makefile              # Sistema de compilación
├── README.md             # Este archivo
├── test.sh               # Script de testing
└── .gitignore            # Archivos a ignorar
```

## 🎨 Estados de los Filósofos

Los filósofos pueden estar en los siguientes estados:

| Estado | Color | Descripción |
|--------|-------|-------------|
| 🍽️ **Comiendo** | Verde | Filósofo comiendo con dos tenedores |
| 💭 **Pensando** | Morado | Filósofo pensando |
| 😴 **Durmiendo** | Amarillo | Filósofo durmiendo después de comer |
| 🍴 **Tenedor** | Cyan | Filósofo toma un tenedor |
| 💀 **Muerto** | Rojo | Filósofo ha muerto de inanición |

## 🛡️ Sincronización

- **Mutexes por tenedor**: Cada tenedor tiene su propio mutex
- **Mutex de escritura**: Para sincronizar los mensajes de salida
- **Mutex de muerte**: Para detectar cuando un filósofo muere
- **Mutex de comidas**: Para contar las comidas completadas

## ⚠️ Consideraciones

- Los tiempos deben ser ≥ 60ms para evitar comportamientos inesperados
- Número máximo de filósofos: 200
- El programa maneja correctamente la liberación de recursos
- Implementa una estrategia para evitar deadlocks

## 🤝 Contribuir

1. Fork el proyecto
2. Crea una rama para tu feature (`git checkout -b feature/AmazingFeature`)
3. Commit tus cambios (`git commit -m 'Add some AmazingFeature'`)
4. Push a la rama (`git push origin feature/AmazingFeature`)
5. Abre un Pull Request

## 📄 Licencia

Este proyecto es parte del currículo de 42 Madrid.

---

**Autor:** Miguel González
**Fecha:** Junio 2024
