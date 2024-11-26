# **ColorMania**

## **Descripción**
ColorMania es un juego interactivo que combina lógica y gestión de datos mediante el uso de pilas y colas para ordenar colores en un tablero. El juego permite al usuario cargar colores, organizarlos según diferentes modos, y optimizar la distribución a través de algoritmos implementados en C++ y .NET Framework.

## **Características principales**
- **Estructuras de datos utilizadas:**
  - Pilas y colas para la manipulación y almacenamiento de colores.
  - Tablas dinámicas para representar los colores.
- **Modos de juego:**
  - Fácil: Sin restricciones de tiempo ni movimientos.
  - Medio: Límite de tiempo y movimientos moderado.
  - Difícil: Límite estricto de tiempo y movimientos.
- **Interfaz gráfica:**
  - Implementada en Windows Forms.
  - Botones interactivos para cargar datos, mover colores y resolver el juego.

## **Componentes del Proyecto**
### **Archivos principales**
1. **`Pila.h` y `Pila.cpp`:**
   - Definen la estructura y funciones básicas de una pila, incluyendo métodos como `Push`, `Pop`, y verificación de si está vacía.
2. **`Cola.h` y `Cola.cpp`:**
   - Definen la estructura de una cola y sus operaciones básicas.
3. **`Ordenamiento.h` y `Ordenamiento.cpp`:**
   - Contienen algoritmos de ordenamiento, como QuickSort, para organizar los colores de manera eficiente.
4. **`Lista.h` y `Lista.cpp`:**
   - Implementan una lista genérica para manejar elementos dinámicamente.
5. **`MyForm.h`:**
   - Contiene la lógica de la interfaz gráfica del juego, como botones, eventos y manejo del tablero.

### **Tecnologías utilizadas**
- C++/CLI para integrar código C++ con la interfaz de usuario.
- .NET Framework para el desarrollo de la interfaz gráfica.

## **Cómo jugar**
1. **Configuración inicial:**
   - Introduce la cantidad de pilas y su capacidad en los campos correspondientes.
   - Carga un archivo con los colores a ordenar.
2. **Modos de juego:**
   - Selecciona el modo de juego desde el menú desplegable.
3. **Interacciones:**
   - Utiliza los botones para mover colores entre pilas y colas.
   - Descarga el registro de movimientos o la solución generada al final del juego.
4. **Objetivo:**
   - Ordenar los colores siguiendo las reglas del modo seleccionado.

## **Requisitos**
- **Entorno:**
  - Visual Studio 2017 o superior.
  - .NET Framework compatible.
- **Sistema operativo:**
  - Windows 10 o superior.
- **Librerías:**
  - Incluidas en el proyecto.

## **Instrucciones de instalación**
1. **Clonar el repositorio:**
   ```bash
   git clone https://github.com/tu-usuario/ColorMania.git
