#include "store.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Datos de los juegos: usando arreglos paralelos (estilo principiante)
static int codigosProductos[MAX_PRODUCTOS] = {1,2,3,4,5,6,7,8,9,10,11,12};
static string nombresProductos[MAX_PRODUCTOS] = {
    "HYPER STRIKE","NIGHT QUEST","SKY RACER",      // Accion
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

int leerCantidadJuegos(){
    int cantidad;
    cout << "Ingrese la cantidad: ";
    while(!(cin >> cantidad) || cantidad <= 0){
        cin.clear(); cin.ignore(1000,'\n');
        cout << "Cantidad invalida. Ingrese un numero entero positivo: ";
    }
    return cantidad;
}

string obtenerNombreJuego(int codigoJuego){
    for(int i=0;i<MAX_PRODUCTOS;i++) if(codigosProductos[i]==codigoJuego) return nombresProductos[i];
    return "DESCONOCIDO";
}

int obtenerPrecioJuego(int codigoJuego){
    for(int i=0;i<MAX_PRODUCTOS;i++) if(codigosProductos[i]==codigoJuego) return preciosProductos[i];
    return 0;
}

string obtenerPlataforma(int codigoJuego){
    for(int i=0;i<MAX_PRODUCTOS;i++) if(codigosProductos[i]==codigoJuego) return plataformasProductos[i];
    return "";
}

string obtenerCategoria(int codigoJuego){
    for(int i=0;i<MAX_PRODUCTOS;i++) if(codigosProductos[i]==codigoJuego) return categoriasProductos[i];
    return "";
}

void agregarJuegoAlCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados){
    if(cantidadJuegosRegistrados >= MAX_CARRITO){
        cout << "No se puede agregar mas items. Ya alcanzo el limite de " << MAX_CARRITO << " items distintos.\n";
        return;
    }
    int codigo = leerCodigoJuego();
    if(codigo==0) return; // cancelar
    int cantidad = leerCantidadJuegos();

    // buscar si ya existe en carrito
    for(int i=0;i<cantidadJuegosRegistrados;i++){
        if(codigos[i]==codigo){
            cantidades[i] += cantidad; // actualizar cantidad
            cout << "Se actualizo la cantidad del juego en el carrito.\n";
            return;
        }
    }
    // si no existe, agregar nuevo item
    codigos[cantidadJuegosRegistrados] = codigo;
    cantidades[cantidadJuegosRegistrados] = cantidad;
    cantidadJuegosRegistrados++;
    cout << "Juego agregado al carrito.\n";
}

double calcularSubtotalCarrito(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados){
    double subtotal = 0.0;
    for(int i=0;i<cantidadJuegosRegistrados;i++){
        subtotal += obtenerPrecioJuego(codigos[i]) * cantidades[i];
    }
    return subtotal;
}

int leerTipoCliente(){
    cout << "Tipo de cliente:\n1. Miembro Oro (15%)\n2. Miembro Plata (8%)\n3. Cliente Regular (0%)\nElija (1-3): ";
    int t;
    while(!(cin >> t) || t<1 || t>3){
        cin.clear(); cin.ignore(1000,'\n');
        cout << "Opcion invalida. Elija 1, 2 o 3: ";
    }
    return t;
}

double obtenerPorcentajeDescuento(int tipoCliente){
    if(tipoCliente==1) return 0.15; // 15%
    if(tipoCliente==2) return 0.08; // 8%
    return 0.0; // regular
}

// Descuentos adicionales: ejemplo de reglas sencillas
// - Si la plataforma es PC -> 5% extra sobre ese item
// - Si la categoria es Estrategia -> 3% extra sobre ese item

double calcularDescuentosAdicionales(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados){
    double extra = 0.0;
    for(int i=0;i<cantidadJuegosRegistrados;i++){
        int code = codigos[i];
        double precioUnit = obtenerPrecioJuego(code);
        double importe = precioUnit * cantidades[i];
        string platform = obtenerPlataforma(code);
        string categoria = obtenerCategoria(code);
        if(platform == "PC"){
            extra += importe * 0.05; // 5% sobre importe de items PC
        }
        if(categoria == "Estrategia"){
            extra += importe * 0.03; // 3% sobre importe de estrategia
        }
    }
    return extra;
}

double calcularTotalFinal(double subtotal, double porcentajeDescuento, double descuentosAdicionales){
    double descuentoCliente = subtotal * porcentajeDescuento;
    double total = subtotal - descuentoCliente - descuentosAdicionales;
    if(total < 0) total = 0;
    return total;
}

void mostrarResumenCompra(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados, double porcentajeDescuento){
    cout << "\n===== RESUMEN DE COMPRA =====\n";
    cout << left << setw(6) << "Cod" << setw(25) << "Nombre" << setw(8) << "Cant" << setw(12) << "PrecioU" << "Subtotal" << "\n";
    cout << "----------------------------------------------------------------\n";
    for(int i=0;i<cantidadJuegosRegistrados;i++){
        int code = codigos[i];
        double pu = obtenerPrecioJuego(code);
        double sub = pu * cantidades[i];
        cout << left << setw(6) << code << setw(25) << obtenerNombreJuego(code) << setw(8) << cantidades[i] << setw(12) << pu << sub << "\n";
    }
    double subtotal = calcularSubtotalCarrito(codigos, cantidades, cantidadJuegosRegistrados);
    double descuentosAdic = calcularDescuentosAdicionales(codigos, cantidades, cantidadJuegosRegistrados);
    double descuentoCliente = subtotal * porcentajeDescuento;
    double total = subtotal - descuentoCliente - descuentosAdic;

    cout << "\nSubtotal: " << subtotal << "\n";
    cout << "Descuento por tipo de cliente (" << porcentajeDescuento*100 << "%): " << descuentoCliente << "\n";
    cout << "Descuentos adicionales: " << descuentosAdic << "\n";
    cout << "Total final: " << total << "\n";
}

void cargarCompraDemo(int codigos[], int cantidades[], int& cantidadJuegosRegistrados){
    // ejemplo simple: carga 3 items de demostracion
    cantidadJuegosRegistrados = 0;
    codigos[0] = 1; cantidades[0] = 1; // HYPER STRIKE
    codigos[1] = 10; cantidades[1] = 2; // BATTLE TACTICS
    codigos[2] = 7; cantidades[2] = 1; // PRO FOOTBALL 25
    cantidadJuegosRegistrados = 3;
    cout << "Compra de demostracion cargada.\n";
}

void limpiarCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados){
    for(int i=0;i<MAX_CARRITO;i++){
        codigos[i]=0; cantidades[i]=0;
    }
    cantidadJuegosRegistrados = 0;
    cout << "Carrito limpiado.\n";
}


