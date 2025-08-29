#include <iostream>
#include "store.h"
using namespace std;

int main(){
    int carritoCodigos[MAX_CARRITO] = {0};
    int carritoCantidades[MAX_CARRITO] = {0};
    int cantidadJuegosRegistrados = 0;

    bool salir = false;
    while(!salir){
        cout << "\n===== G A M E S T O R E - MENU =====\n";
        cout << "1. Mostrar catalogo\n";
        cout << "2. Agregar juego al carrito\n";
        cout << "3. Cargar compra demo\n";
        cout << "4. Limpiar carrito\n";
        cout << "5. Mostrar resumen y calcular totales\n";
        cout << "6. Salir\n";
        cout << "Elija una opcion: ";
        int opcion;
        while(!(cin >> opcion)){
            cin.clear(); cin.ignore(1000,'\n');
            cout << "Opcion invalida. Ingrese un numero: ";
        }
        switch(opcion){
            case 1:
                mostrarCatalogoJuegos();
                break;
            case 2:
                agregarJuegoAlCarrito(carritoCodigos, carritoCantidades, cantidadJuegosRegistrados);
                break;
            case 3:
                cargarCompraDemo(carritoCodigos, carritoCantidades, cantidadJuegosRegistrados);
                break;
            case 4:
                limpiarCarrito(carritoCodigos, carritoCantidades, cantidadJuegosRegistrados);
                break;
            case 5: {
                if(cantidadJuegosRegistrados==0){
                    cout << "El carrito esta vacio.\n";
                    break;
                }
                int tipo = leerTipoCliente();
                double porcentaje = obtenerPorcentajeDescuento(tipo);
                mostrarResumenCompra(carritoCodigos, carritoCantidades, cantidadJuegosRegistrados, porcentaje);
                break;
            }
            case 6:
                salir = true;
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    }
    cout << "Gracias por usar GameStore. Hasta luego!\n";
    return 0;
}
