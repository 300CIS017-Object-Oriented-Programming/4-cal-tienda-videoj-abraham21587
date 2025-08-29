//
// Created by Usuario on 29/08/2025.
//

#ifndef INC_4_CAL_TIENDA_VIDEOJ_ABRAHAM21587_STORE_H
#define INC_4_CAL_TIENDA_VIDEOJ_ABRAHAM21587_STORE_H

#include <string>


// Constantes
const int MAX_PRODUCTOS = 12; // 4 categorias * 3 juegos
const int MAX_CARRITO = 10; // limite maximo de items distintos en el carrito


// Prototipos de funciones (segun especificacion)
void mostrarCatalogoJuegos();
int leerCodigoJuego();
int leerCantidadJuegos();
std::string obtenerNombreJuego(int codigoJuego);
int obtenerPrecioJuego(int codigoJuego);
std::string obtenerPlataforma(int codigoJuego);
std::string obtenerCategoria(int codigoJuego);
void agregarJuegoAlCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);
double calcularSubtotalCarrito(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);
int leerTipoCliente();
double obtenerPorcentajeDescuento(int tipoCliente);
double calcularDescuentosAdicionales(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);
double calcularTotalFinal(double subtotal, double porcentajeDescuento, double descuentosAdicionales);
void mostrarResumenCompra(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados, double porcentajeDescuento);
void cargarCompraDemo(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);
void limpiarCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);

#endif //INC_4_CAL_TIENDA_VIDEOJ_ABRAHAM21587_STORE_H