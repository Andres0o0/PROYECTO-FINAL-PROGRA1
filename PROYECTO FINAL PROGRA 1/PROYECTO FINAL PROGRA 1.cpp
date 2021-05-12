// PROYECTO FINAL PROGRA 1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Cliente.h"
#include "Puesto.h"
#include "Empleado.h"
#include "Proveedor.h"
#include "Marca.h"
#include "Producto.h"
#include "Venta.h"
#include "Compra_Detalle.h"
#include "Venta_Detalle.h"
#include "Compra.h"
using namespace std;

Cliente c = Cliente();
Puesto p = Puesto();
Empleado e = Empleado();
Proveedor pv = Proveedor();
Producto pr = Producto();
Marca m = Marca();
Venta v = Venta();
Venta_Detalle vd = Venta_Detalle();
Compra cp = Compra();
Compra_Detalle cdt = Compra_Detalle();

void menu();
int main()
{    
    pv.mostrar();
    cout << "--------------"<<endl;
    m.mostrar();
    cout << "--------------" << endl;
    pr.mostrar();
    cout << "-------------" << endl;
    v.mostrar();
    cout << "-------------" << endl;
    e.mostrar();
    cout << "-------------" << endl;
    p.mostrar();
    cout << "-------------" << endl;
    c.mostrar();
    cout << "-------------" << endl;
    vd.mostrar();
    cout << "-------------" << endl;
    cp.mostrar();
    cout << "-------------" << endl;
     cdt.mostrar();
     menu();
}
void menu() {
    int opcion;
    do {
        system("cls");
        cout << "----------------" << endl;
        cout << "PROYECTO FINAL PROGRAMACION 1" << endl;
        cout << " [1]  ACCEDER A  LOS PRODUCTOS" << endl;
        cout << " [2]  ACCEDER A LOS CLIENTES" << endl;
        cout << " [3]  ACCEDER A LAS MARCAS" << endl;
        cout << " [4]  ACCEDER A LOS PUESTOS" << endl;
        cout << " [5]  ACCEDER A LOS EMPLEADOS" << endl;
        cout << " [6]  ACCEDER A LAS VENTAS" << endl;
        cout << " [7]  ACCEDER A LOS PROVEEDORES" << endl;
        cout << " [8]  ACCEDER A LAS COMPRAS" << endl;
        cout << " [9]  REALIZAR UNA VENTA" << endl;
        cout << " [10] SALIR" << endl;
        cin >> opcion;
    } while (opcion != 10);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
