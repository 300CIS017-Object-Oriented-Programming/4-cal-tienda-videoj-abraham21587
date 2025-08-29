#include "store.h"
#include <iostream>
#include <iomanip>



using namespace std;


// Datos de los juegos: usando arreglos paralelos (estilo principiante)
static int codigosProductos[MAX_PRODUCTOS] = {1,2,3,4,5,6,7,8,9,10,11,12};
static string nombresProductos[MAX_PRODUCTOS] = {
"HYPER STRIKE","NIGHT QUEST","SKY RACER", // Accion
"FOREST LEGENDS","ISLAND MYSTERY","DEEP DUNGEON", // Aventura
"PRO FOOTBALL 25","EXTREME RALLY","HOOP STARS", // Deportes
"BATTLE TACTICS","GALACTIC WARS","CASTLE BUILDER" // Estrategia
};
static int preciosProductos[MAX_PRODUCTOS] = {
120000, 95000, 80000,
110000, 90000, 100000,
130000, 85000, 70000,
140000, 150000, 95000
};
static string plataformasProductos[MAX_PRODUCTOS] = {
"PS5","Xbox","PC",
"PC","Switch","PS5",
"PS5","Xbox","Switch",
"PC","PC","Xbox"
};
static string categoriasProductos[MAX_PRODUCTOS] = {
"Accion","Accion","Accion",
"Aventura","Aventura","Aventura",
"Deportes","Deportes","Deportes",
"Estrategia","Estrategia","Estrategia"
};


// Implementacion de funciones


void mostrarCatalogoJuegos(){
cout << "\n===== CATALOGO DE JUEGOS =====\n";
cout << left << setw(6) << "Cod" << setw(25) << "Nombre" << setw(10) << "Precio" << setw(10) << "Plataf" << "Categoria" << "\n";
cout << "----------------------------------------------------------------\n";
for(int i=0;i<MAX_PRODUCTOS;i++){
cout << left << setw(6) << codigosProductos[i]
<< setw(25) << nombresProductos[i]
<< setw(10) << preciosProductos[i]
<< setw(10) << plataformasProductos[i]
<< categoriasProductos[i] << "\n";
}
}


int leerCodigoJuego(){
int codigo;
cout << "Ingrese el codigo del juego (0 para cancelar): ";
while(!(cin >> codigo)){
cin.clear(); cin.ignore(1000,'\n');
cout << "Entrada invalida. Ingrese un numero de codigo: ";
}
// validar que exista
if(codigo==0) return 0;
bool existe=false;
for(int i=0;i<MAX_PRODUCTOS;i++) if(codigosProductos[i]==codigo) existe=true;
if(!existe){
cout << "Codigo no encontrado. Intente otra vez.\n";
return leerCodigoJuego(); // simple recursion de validacion (estilo principiante)
}
return codigo;
}
void agregarJuegoAlCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados) {
    // implementación aquí
}

void cargarCompraDemo(int codigos[], int cantidades[], int& cantidadJuegosRegistrados) {
    // implementación aquí
}

void limpiarCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados) {
    cantidadJuegosRegistrados = 0;
}

int leerTipoCliente() {
    int tipo;
    cout << "Ingrese tipo de cliente (1=Oro, 2=Plata, 3=Regular): ";
    cin >> tipo;
    return tipo;
}

double obtenerPorcentajeDescuento(int tipoCliente) {
    if (tipoCliente == 1) return 0.15;
    if (tipoCliente == 2) return 0.08;
    return 0.0;
}

void mostrarResumenCompra(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados, double porcentajeDescuento) {
    cout << "Resumen de la compra..." << endl;
    // mostrar juegos, subtotal, descuentos, total
}

