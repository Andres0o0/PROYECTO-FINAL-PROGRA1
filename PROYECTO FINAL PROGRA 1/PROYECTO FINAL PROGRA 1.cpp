// PROYECTO FINAL PROGRA 1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <windows.h>
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
#include <string>
#include"Pantalla.h"
#include <fstream> 
#include <conio.h>
#include"SerialPort.h"

using namespace std;

typedef std::basic_ifstream<TCHAR> tifstream;
typedef std::basic_string<TCHAR> tstring;

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];

char commport[] = "\\\\.\\COM4";
char* port = commport;
SerialPort arduino(port);
void cinta_transportadora();
void apagar_cinta();
void caja_registradora();
void apagar();
void salir();

//PARA IMPRIMIR
void Outtextxy(HDC hdc, int x, int y, tstring Msg);
void ShowError(tstring strMsg);
void ShowInformation(tstring strText);
void PrintFile(tifstream& f);

void menu();

void ingresarPuesto();
void buscarPuesto();
void modificarPuesto();
void eliminarPuesto();

void ingresarEmpleado();
void buscarEmpleado();
void modificarEmpleado();
void eliminarEmpleado();

void ingresarCliente(string nit);
void buscarCliente();
void modificarCliente();
void eliminarCliente();

void ingresarVenta();
void buscarVenta();
void mostrarVenta();
void modificarVenta();
void eliminarVenta();
void imprimirf(string idv);

void ingresarMarca();
void buscarMarca();
void modificarMarca();
void eliminarMarca();

void ingresarProducto();
void buscarProducto();
void modificarProducto();
void eliminarProducto();

void ingresarCompra();
void MostrarCompras();
void BuscarCompras();
void ModificarCompras();
void eliminarCompras();
void imprimirfc(int idc);

void IngresarProveedor();
void MostrarProveedor();
void BuscarProveedor();
void ModificarProveedor();
void EliminarProveedor();

void puestos();
void empleados();
void clientes();
void proveedores();
void marcas();
void productos();
void ventas();
void compras();

int main()
{    
    SetConsoleTitleA("                                                                                                                [UMG]          CADEX PUNTO VENTA");
     menu();
}
void menu() {
    Pantalla p = Pantalla();
    int opcion;
    do {
        system("cls");
        p.color(112);
        p.dibujarCuadro(37, 1, 77, 4);
        p.gotoxy(38, 2);
        cout << "PROYECTO FINAL G No.4    PROGRAMACION 1";
        p.gotoxy(38, 3);
        cout << "           [MENU  PRINCIPAL]           ";
        p.color(15);
        p.gotoxy(0, 7);
        cout << "   \t\t\t\t\t[1]  ACCEDER A LOS PUESTOS "<<endl ;
        cout << "   \t\t\t\t\t[2]  ACCEDER A LOS EMPLEADOS " << endl;
        cout << "   \t\t\t\t\t[3]  ACCEDER A LOS CLIENTES " << endl;
        cout << "   \t\t\t\t\t[4]  ACCEDER A LOS PROVEEDORES" << endl;
        cout << "   \t\t\t\t\t[5]  ACCEDER A LAS MARCAS" << endl;
        cout << "   \t\t\t\t\t[6]  ACCEDER A LOS PRODUCTOS" << endl;
        cout << "   \t\t\t\t\t[7]  ACCEDER A LAS VENTAS" << endl;
        cout << "   \t\t\t\t\t[8]  ACCEDER A LAS COMPRAS" << endl;
        cout << "   \t\t\t\t\t[9]  SALIR" << endl;
        p.color(8);
        p.dibujarCuadro(37, 6, 77, 16);
        p.dibujarCuadro(37, 18, 77, 20);
        p.color(15);
        p.gotoxy(39, 19);
        cout << "PORFAVOR INGRESE UNA OPCION: [ ]\b\b";
        p.color(10);
        cin >> opcion;
        p.color(15);
        switch (opcion) {
        case 1:
            puestos();
            break;
        case 2:
            empleados();
            break;
        case 3:
            clientes();
            break;
        case 4:
            proveedores();
            break;
        case 5:
            marcas();
            break;
        case 6:
            productos();
            break;
        case 7:
            ventas();
            break;
        case 8:
            compras();
            break;
        }
    } while (opcion != 9);
}

void puestos(){
    int opc=0;
    Puesto p =Puesto();
    Pantalla pa = Pantalla();
    do {
        system("cls");
        pa.color(96);
        pa.dibujarCuadro(37, 1, 77, 4);
        pa.gotoxy(38, 2);
        cout << "   TABLA  DE  REGISTRO  DE  PUESTOS    ";
        pa.gotoxy(38, 3);
        cout << "          QUE DESEA  REALIZAR          ";
        pa.color(15);
        pa.gotoxy(0, 8);
        cout << "      \t\t\t\t\t[1] INGRESAR REGISTROS" << endl;
        cout << "      \t\t\t\t\t[2] BUSCAR REGISTRO" << endl;
        cout << "      \t\t\t\t\t[3] MOSTRAR EL LISTADO" << endl;
        cout << "      \t\t\t\t\t[4] MODIFICAR UN REGISTRO" << endl;
        cout << "      \t\t\t\t\t[5] ELIMINAR UN REGISTRO" << endl;
        cout << "      \t\t\t\t\t[6] REGRESAR" << endl;
        pa.color(8);
        pa.dibujarCuadro(37, 6, 77, 16);
        pa.dibujarCuadro(37, 18, 77, 20);
        pa.color(15);
        pa.gotoxy(39, 19);
        cout << "PORFAVOR INGRESE UNA OPCION: [ ]\b\b";
        pa.color(6);
        cin >> opc;
        switch (opc) {
        case 1:
            system("cls");
            ingresarPuesto();
            system("pause");
            break;
        case 2:
            system("cls");
            buscarPuesto();
            system("pause");
            break;
        case 3:
            system("cls");
            p.mostrar();
            system("pause");
            break;
        case 4:
            system("cls");
            modificarPuesto();
            system("pause");
            break;
        case 5:
            system("cls");
            eliminarPuesto();
            system("pause");
            break;
        }
    } while (opc != 6);

}
void empleados(){
    int opc;
    Empleado e = Empleado(); 
    Pantalla pa = Pantalla();
    do {
        system("cls");
        pa.color(96);
        pa.dibujarCuadro(37, 1, 77, 4);
        pa.gotoxy(38, 2);
        cout << "  TABLA  DE  REGISTRO  DE  EMPLEADOS   ";
        pa.gotoxy(38, 3);
        cout << "          QUE DESEA  REALIZAR          ";
        pa.color(15);
        pa.gotoxy(0, 8);
        cout << "      \t\t\t\t\t[1] INGRESAR REGISTROS" << endl;
        cout << "      \t\t\t\t\t[2] BUSCAR REGISTRO" << endl;
        cout << "      \t\t\t\t\t[3] MOSTRAR EL LISTADO" << endl;
        cout << "      \t\t\t\t\t[4] MODIFICAR UN REGISTRO" << endl;
        cout << "      \t\t\t\t\t[5] ELIMINAR UN REGISTRO" << endl;
        cout << "      \t\t\t\t\t[6] REGRESAR" << endl;
        pa.color(8);
        pa.dibujarCuadro(37, 6, 77, 16);
        pa.dibujarCuadro(37, 18, 77, 20);
        pa.color(15);
        pa.gotoxy(39, 19);
        cout << "PORFAVOR INGRESE UNA OPCION: [ ]\b\b";
        pa.color(6);
        cin >> opc;
        switch (opc) {
        case 1:
            system("cls");
            ingresarEmpleado();
            system("pause");
            break;
        case 2:
            system("cls");
            buscarEmpleado();
            system("pause");
            break;
        case 3:
            system("cls");
            e.mostrar();
            system("pause");
            break;
        case 4:
            system("cls");
            modificarEmpleado();
            system("pause");
            break;
        case 5:
            system("cls");
            eliminarEmpleado();
            system("pause");
            break;
        }
    } while (opc != 6);
}
void clientes(){
    int opc;
    string nit;
    Cliente c = Cliente();
    Pantalla pa = Pantalla();
    do {
        system("cls");
        pa.color(96);
        pa.dibujarCuadro(37, 1, 77, 4);
        pa.gotoxy(38, 2);                   
        cout << "   TABLA  DE  REGISTRO  DE  CLIENTES   ";
        pa.gotoxy(38, 3);
        cout << "          QUE DESEA  REALIZAR          ";
        pa.color(15);
        pa.gotoxy(0, 8);
        cout << "      \t\t\t\t\t[1] INGRESAR REGISTROS" << endl;
        cout << "      \t\t\t\t\t[2] BUSCAR REGISTRO" << endl;
        cout << "      \t\t\t\t\t[3] MOSTRAR EL LISTADO" << endl;
        cout << "      \t\t\t\t\t[4] MODIFICAR UN REGISTRO" << endl;
        cout << "      \t\t\t\t\t[5] ELIMINAR UN REGISTRO" << endl;
        cout << "      \t\t\t\t\t[6] REGRESAR" << endl;
        pa.color(8);
        pa.dibujarCuadro(37, 6, 77, 16);
        pa.dibujarCuadro(37, 18, 77, 20);
        pa.color(15);
        pa.gotoxy(39, 19);
        cout << "PORFAVOR INGRESE UNA OPCION: [ ]\b\b";
        pa.color(6);
        cin >> opc;
        switch (opc) {
        case 1:
            system("cls");
            pa.color(240);
            pa.dibujarCuadro(37, 1, 77, 5);
            pa.gotoxy(38, 3);
            cout << "    INGRESE  LOS  SIGUIENTES  DATOS    ";
            pa.gotoxy(38, 2);
            cout << "                                       ";
            pa.gotoxy(38, 4);
            cout << "                                       ";
            pa.color(15);
            pa.gotoxy(2, 11);
            cout << "INGRESE SU NIT ";
            pa.gotoxy(2, 12);
            pa.color(6);
            cin>>nit;
            pa.color(15);
            bool existe;
            c.setNit(nit);
            existe = c.existexnit();
            if (existe == false) {
                ingresarCliente(nit);
            }
            else {
                pa.gotoxy(2, 11);
                cout << "ESTE NIT YA EXISTE" << endl;
            }
            system("pause");
            break;
        case 2:system("cls");
            buscarCliente();
            system("pause");
            break;
        case 3:
            system("cls");
            c.mostrar();
            system("pause");
            break;
        case 4:
            system("cls");
            modificarCliente();
            system("pause");
            break;
        case 5:
            system("cls");
            eliminarCliente();
            system("pause");
            break;
        }
    } while (opc != 6);
}
void proveedores(){
    int opc;
    Proveedor pv = Proveedor();
    Pantalla pa = Pantalla();
    do {
        system("cls");
        pa.color(96);
        pa.dibujarCuadro(37, 1, 77, 4);
        pa.gotoxy(38, 2);                   
        cout << " TABLA  DE  REGISTRO  DE  PROVEEDORES  ";
        pa.gotoxy(38, 3);
        cout << "          QUE DESEA  REALIZAR          ";
        pa.color(15);
        pa.gotoxy(0, 8);
        cout << "      \t\t\t\t\t[1] INGRESAR REGISTROS" << endl;
        cout << "      \t\t\t\t\t[2] BUSCAR REGISTRO" << endl;
        cout << "      \t\t\t\t\t[3] MOSTRAR EL LISTADO" << endl;
        cout << "      \t\t\t\t\t[4] MODIFICAR UN REGISTRO" << endl;
        cout << "      \t\t\t\t\t[5] ELIMINAR UN REGISTRO" << endl;
        cout << "      \t\t\t\t\t[6] REGRESAR" << endl;
        pa.color(8);
        pa.dibujarCuadro(37, 6, 77, 16);
        pa.dibujarCuadro(37, 18, 77, 20);
        pa.color(15);
        pa.gotoxy(39, 19);
        cout << "PORFAVOR INGRESE UNA OPCION: [ ]\b\b";
        pa.color(6);
        cin >> opc;
        switch (opc) {
        case 1:
            system("cls");
            IngresarProveedor();
            system("pause");
            break;
        case 2:
            system("cls");
            BuscarProveedor();
            system("pause");
            break;
        case 3:
            system("cls");
            MostrarProveedor();
            system("pause");
            break;
        case 4:
            system("cls");
           ModificarProveedor();
            system("pause");
            break;
        case 5:
            system("cls");
            EliminarProveedor();
            system("pause");
            break;
        }
    } while (opc != 6);
}
void marcas(){
    int opc;
    Marca m = Marca();
    Pantalla pa = Pantalla();
    do {
        system("cls");
        pa.color(96);
        pa.dibujarCuadro(37, 1, 77, 4);
        pa.gotoxy(38, 2);                   
        cout << "    TABLA  DE  REGISTRO  DE  MARCAS    ";
        pa.gotoxy(38, 3);
        cout << "          QUE DESEA  REALIZAR          ";
        pa.color(15);
        pa.gotoxy(0, 8);
        cout << "      \t\t\t\t\t[1] INGRESAR REGISTROS" << endl;
        cout << "      \t\t\t\t\t[2] BUSCAR REGISTRO" << endl;
        cout << "      \t\t\t\t\t[3] MOSTRAR EL LISTADO" << endl;
        cout << "      \t\t\t\t\t[4] MODIFICAR UN REGISTRO" << endl;
        cout << "      \t\t\t\t\t[5] ELIMINAR UN REGISTRO" << endl;
        cout << "      \t\t\t\t\t[6] REGRESAR" << endl;
        pa.color(8);
        pa.dibujarCuadro(37, 6, 77, 16);
        pa.dibujarCuadro(37, 18, 77, 20);
        pa.color(15);
        pa.gotoxy(39, 19);
        cout << "PORFAVOR INGRESE UNA OPCION: [ ]\b\b";
        pa.color(6);
        cin >> opc;
        switch (opc) {
        case 1:
            system("cls");
            ingresarMarca();
            system("pause");
            break;
        case 2:
            system("cls");
            buscarMarca();
            system("pause");
            break;
        case 3:
            system("cls");
            m.mostrar();
            system("pause");  
            break;
        case 4:
            system("cls");
            modificarMarca();
            system("pause");
            break;
        case 5:
            system("cls");
            eliminarMarca();
            system("pause");
            break;
        }
    } while (opc != 6);
}
void productos(){
    int opc;
    Producto pr = Producto();
    Pantalla pa = Pantalla();
    do {
        system("cls");
        pa.color(96);
        pa.dibujarCuadro(37, 1, 77, 4);
        pa.gotoxy(38, 2);
        cout << "  TABLA  DE  REGISTRO  DE  PRODUCTOS   ";
        pa.gotoxy(38, 3);
        cout << "          QUE DESEA  REALIZAR          ";
        pa.color(15);
        pa.gotoxy(0, 8);
        cout << "      \t\t\t\t\t[1] INGRESAR REGISTROS" << endl;
        cout << "      \t\t\t\t\t[2] BUSCAR REGISTRO" << endl;
        cout << "      \t\t\t\t\t[3] MOSTRAR EL LISTADO" << endl;
        cout << "      \t\t\t\t\t[4] MODIFICAR UN REGISTRO" << endl;
        cout << "      \t\t\t\t\t[5] ELIMINAR UN REGISTRO" << endl;
        cout << "      \t\t\t\t\t[6] REGRESAR" << endl;
        pa.color(8);
        pa.dibujarCuadro(37, 6, 77, 16);
        pa.dibujarCuadro(37, 18, 77, 20);
        pa.color(15);
        pa.gotoxy(39, 19);
        cout << "PORFAVOR INGRESE UNA OPCION: [ ]\b\b";
        pa.color(6);
        cin >> opc;
        switch (opc) {
        case 1:
            system("cls");
            ingresarProducto();
            system("pause");
            break;
        case 2:
            system("cls");
            buscarProducto();
            system("pause");
            break;
        case 3:
            system("cls");
            pr.mostrar();
            system("pause");
            break;
        case 4:
            system("cls");
            modificarProducto();
            system("pause");
            break;
        case 5:
            system("cls");
            eliminarProducto();
            system("pause");
            break;
        }
    } while (opc != 6);
}
void ventas(){
    int opc;
    Pantalla pa = Pantalla();
    do {
        system("cls");
        pa.color(96);
        pa.dibujarCuadro(37, 1, 77, 4);
        pa.gotoxy(38, 2);
        cout << "    TABLA  DE  REGISTRO  DE  VENTAS    ";
        pa.gotoxy(38, 3);
        cout << "          QUE DESEA  REALIZAR          ";
        pa.color(15);
        pa.gotoxy(0, 8);
        cout << "      \t\t\t\t\t[1] INGRESAR REGISTROS" << endl;
        cout << "      \t\t\t\t\t[2] BUSCAR REGISTRO" << endl;
        cout << "      \t\t\t\t\t[3] MOSTRAR EL LISTADO" << endl;
        cout << "      \t\t\t\t\t[4] MODIFICAR UN REGISTRO" << endl;
        cout << "      \t\t\t\t\t[5] ELIMINAR UN REGISTRO" << endl;
        cout << "      \t\t\t\t\t[6] REGRESAR" << endl;
        pa.color(8);
        pa.dibujarCuadro(37, 6, 77, 16);
        pa.dibujarCuadro(37, 18, 77, 20);
        pa.color(15);
        pa.gotoxy(39, 19);
        cout << "PORFAVOR INGRESE UNA OPCION: [ ]\b\b";
        pa.color(6);
        opc = 0;
        cin >> opc;
        switch (opc) {
        case 1:
            system("cls");
            ingresarVenta();
            system("pause");
            break;
        case 2:
            system("cls");
            buscarVenta();
            system("pause");
            break;
        case 3:
            system("cls");
            mostrarVenta();
            system("pause");
            break;
        case 4:
            system("cls");
            modificarVenta();
            system("pause");
            break;
        case 5:
            system("cls");
            eliminarVenta();
            system("pause");
            break;
        }
    } while (opc != 6);
}
void compras(){
    int opc;
    Compra cp = Compra();
    Compra_Detalle cdt = Compra_Detalle();
    Pantalla pa = Pantalla();
    do {
        system("cls");
        pa.color(96);
        pa.dibujarCuadro(37, 1, 77, 4);
        pa.gotoxy(38, 2);
        cout << "   TABLA  DE  REGISTRO  DE  COMPRAS    ";
        pa.gotoxy(38, 3);
        cout << "          QUE DESEA  REALIZAR          ";
        pa.color(15);
        pa.gotoxy(0, 8);
        cout << "      \t\t\t\t\t[1] INGRESAR REGISTROS" << endl;
        cout << "      \t\t\t\t\t[2] BUSCAR REGISTRO" << endl;
        cout << "      \t\t\t\t\t[3] MOSTRAR EL LISTADO" << endl;
        cout << "      \t\t\t\t\t[4] MODIFICAR UN REGISTRO" << endl;
        cout << "      \t\t\t\t\t[5] ELIMINAR UN REGISTRO" << endl;
        cout << "      \t\t\t\t\t[6] REGRESAR" << endl;
        pa.color(8);
        pa.dibujarCuadro(37, 6, 77, 16);
        pa.dibujarCuadro(37, 18, 77, 20);
        pa.color(15);
        pa.gotoxy(39, 19);
        cout << "PORFAVOR INGRESE UNA OPCION: [ ]\b\b";
        pa.color(6);
        cin >> opc;
        switch (opc) {
        case 1:
            system("cls");
            ingresarCompra();
            system("pause");
            break;
        case 2:
            system("cls");
            BuscarCompras();
            system("pause");
            break;
        case 3:
            system("cls");
            MostrarCompras();
            system("pause");
            break;
        case 4:
            system("cls");
            ModificarCompras();
            system("pause");
            break;
        case 5:
            system("cls");
            eliminarCompras();
            system("pause");
            break;
        }
    } while (opc != 6);
}

void ingresarPuesto() {
    string puesto;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 12, 77, 14);
    pa.color(240);
    pa.dibujarCuadro(37, 8, 77, 10);
    pa.gotoxy(38, 9);
    cout << "        INGRESE NOMBRE DEL PUESTO      ";
    pa.color(15);
    pa.gotoxy(39, 13);
    cin.ignore();
    getline(cin, puesto);
    Puesto p = Puesto(puesto);
    p.ingresar();
}
void buscarPuesto() {
    int idp;
    bool existe;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "   INGRESE EL ID DEL PUESTO A BUSCAR   ";
    pa.color(15);
    pa.gotoxy(39, 6);
    cin >> idp;
    Puesto p = Puesto();
    existe = p.existepuesto(idp);
    if (existe == true) {
        pa.gotoxy(39, 9);
        p.buscar(idp);
    }
    else {
        pa.gotoxy(39, 9);
        cout << "NO SE ENCONTRO EL ID EN LA BASE DE DATOS" << endl;
    }
}
void modificarPuesto() {
    int idp;
    string puesto;
    char respuesta;
    bool existe;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "  INGRESE EL ID DEL PUESTO A MODIFICAR ";
    pa.color(15);
    pa.gotoxy(39, 6);
    cin >> idp;
    Puesto p = Puesto();
    existe = p.existepuesto(idp);
    if (existe == true) {
        p.buscar(idp);
        pa.gotoxy(35,18);
        cout << "SEGURO QUE QUIERE MODIFICAR ESTE REGISTRO [S/N] " ;
        pa.color(6);
        cin >> respuesta;
        pa.color(15);
        if ((respuesta == 's') || (respuesta == 'S')) {
            system("cls");
            pa.gotoxy(39,1);
            cout << "  INGRESE EL NUEVO NOMBRE DEL PUESTO   ";
            pa.color(6);
            cin.ignore();
            getline(cin, puesto);
            p = Puesto(puesto);
            p.modificar(idp);
        }
        else
        {
            pa.gotoxy(41, 18);
            cout << "SE HA INTERRUMPIDO LA MODIFICACION" << endl;
        }
    }
    else {
        pa.gotoxy(31, 8);
        cout << "EL ID QUE INGRESO NO ESTA REGISTRADO EN LA BASE DE DATOS"<<endl;
    }
}
void eliminarPuesto() {
    int idp;
    string puesto;
    char respuesta;
    bool existe;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "   INGRESE EL ID DEL PUESTO A BORRAR   ";
    pa.color(15);
    pa.gotoxy(39, 6);
    cin >> idp;
    Puesto p = Puesto();
    existe = p.existepuesto(idp);
    pa.color(15);
    if (existe == true) {
        p.buscar(idp);
        pa.gotoxy(22, 18);
        cout << "RECUERDE QUE NO PUEDE ELIMINAR UN PUESTO SI HAY EMPLEADOS ASIGNADOS A ESTE";
        pa.gotoxy(36, 19);
        cout << "SEGURO QUE QUIERE ELIMINAR ESTE REGISTRO [S/N] ";
        pa.color(6);
        cin >> respuesta;
        pa.color(15);
        if ((respuesta == 's') || (respuesta == 'S')) {
            pa.gotoxy(36, 21);
            p.eliminar(idp);
        }
        else
        {
            pa.gotoxy(42, 21);
            cout << "SE HA INTERRUMPIDO LA ELIMINACION" << endl;
        }
    }
    else {
        pa.gotoxy(36, 8);
        cout << "NO SE HA ENCONTRADO EL ID EN LA BASE DE DATOS" << endl;
    }
}

void ingresarEmpleado() {
    Puesto pu = Puesto();
    string nombres, apellidos,direccion, dpi, fecha_nacimiento, fecha_inicio_lab,mf;
    int id_puesto,telefono,genero=-1;
    bool existe;
    Pantalla pa = Pantalla();
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 5);
    pa.gotoxy(38, 3);
    cout << "    INGRESE  LOS  SIGUIENTES  DATOS    ";
    pa.gotoxy(38, 2);
    cout << "                                       ";
    pa.gotoxy(38, 4);
    cout << "                                       ";
    pa.color(15);
    Empleado e = Empleado();
    pa.gotoxy(2, 11);
    cout << "INGRESE NOMBRES ";
    pa.gotoxy(30, 11);
    cout << "INGRESE APELLIDOS ";
    pa.gotoxy(80, 11);
    cout << "INGRESE LA DIRECCION DE DOMICILIO ";
    pa.gotoxy(2, 14);
    cout << "INGRESE TELEFONO ";
    pa.gotoxy(30, 14);
    cout << "INGRESE SU DPI ";
    pa.gotoxy(50, 14);
    cout << "INGRESE SU GENERO [M/F] ";
    pa.gotoxy(80, 14);
    cout << "INGRESE LA FECHA DE NACIMIENTO ";
    pa.gotoxy(80, 15);
    cout << "[ANIO-MES-DIA] ";
    pa.gotoxy(2, 17);
    cout << "INGRESE LA FECHA DE INICIO DE LABORES [ANIO-MES-DIA] ";
    pa.color(6);
    pa.gotoxy(2, 12);
    cin.ignore();
    getline(cin, nombres);
    pa.gotoxy(30, 12);
    getline(cin, apellidos);
    pa.gotoxy(80, 12);
    getline(cin, direccion);
    pa.gotoxy(2, 15);
    cin >> telefono;
    pa.gotoxy(30, 15);
    cin.ignore();
    getline(cin, dpi);
    do {
        pa.gotoxy(55, 15);
        cin >> mf;
        if (mf == "M" || mf == "m") {
            genero = 0;
        }
        else {
            if (mf == "F" || mf == "f") {
                genero = 1;
            }
            else {
                pa.gotoxy(55, 15);
                cout << "        ";
            }
        }
    } while (genero != 0 && genero != 1);
    pa.color(6);

    pa.gotoxy(95, 15);
    cin.ignore();
    getline(cin, fecha_nacimiento);
    pa.gotoxy(2, 18);
    cin >> fecha_inicio_lab;
    pa.color(15); //aqui
    do {
        system("cls");
        pa.gotoxy(2, 1);
        cout << "NOMBRES ";
        pa.gotoxy(21, 1);
        cout << "APELLIDOS ";
        pa.gotoxy(2, 4);
        cout << "DIRECCION ";
        pa.gotoxy(21, 4);
        cout << "TELEFONO ";
        pa.gotoxy(2, 7);
        cout << "DPI ";
        pa.gotoxy(21, 7);
        cout << "GENERO ";
        pa.gotoxy(10, 10);
        cout << "FECHA DE NACIMIENTO ";
        pa.gotoxy(10, 13);
        cout << "FECHA INICIO LABORES ";
        pa.color(6);
        pa.gotoxy(2, 2);
        cout << nombres;
        pa.gotoxy(21, 2);
        cout << apellidos;
        pa.gotoxy(2, 5);
        cout << direccion;
        pa.gotoxy(21, 5);
        cout << telefono;
        pa.gotoxy(2, 8);
        cout << dpi;
        pa.gotoxy(21, 8);
        cout << mf;
        pa.gotoxy(10, 11);
        cout << fecha_nacimiento;
        pa.gotoxy(10, 14);
        cout << fecha_inicio_lab;
        pa.color(15);
        pu.mostrar();
        pa.gotoxy(10, 17);
        cout << "ASIGNE UN VALOR DE PUESTO --->    \b";
        cin >> id_puesto;
        existe = pu.existepuesto(id_puesto);
    } while (existe == false);
    pa.gotoxy(10, 18);
    e = Empleado(nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_lab, "");
    e.ingresar();
}
void buscarEmpleado() {
    Empleado e = Empleado();
    bool existe;
    int ide;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "  INGRESE EL ID DEL EMPLEADO A BUSCAR  ";
    pa.color(15);
    pa.gotoxy(39, 6);
    cin >> ide;
    existe = e.existeEmpleado(ide);
    if (existe == true) {
        system("cls");
        e.buscar(ide);
    }
    else {
        pa.gotoxy(39, 9);
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }
    pa.gotoxy(39, 10);
}
void modificarEmpleado() {
    Empleado e = Empleado();
    Puesto pu = Puesto();
    string nombres, apellidos, direccion, dpi, fecha_nacimiento, fecha_inicio_lab, mf;
    int id_puesto, telefono, genero = -1;
    bool existeE, existe;
    int ide;
    char respuesta;

    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "  INGRESE ID DEL EMPLEADO A MODIFICAR  ";
    pa.color(15);
    pa.gotoxy(39, 6);
    cin >> ide;
    existe = e.existeEmpleado(ide);
    pa.color(15);
    if (existe == true) {
        system("cls");
        e.buscar(ide);
        pa.gotoxy(22, 9);
        cout << "SEGURO QUE QUIERE MODIFICAR ESTE REGISTRO [S/N] ";
        pa.color(6);
        cin >> respuesta;
        pa.color(15);
        if (respuesta == 'S' || respuesta == 's') {
            pa.gotoxy(2, 11);
            cout << "INGRESE NOMBRES ";
            pa.gotoxy(30, 11);
            cout << "INGRESE APELLIDOS ";
            pa.gotoxy(80, 11);
            cout << "INGRESE LA DIRECCION DE DOMICILIO ";
            pa.gotoxy(2, 14);
            cout << "INGRESE TELEFONO ";
            pa.gotoxy(30, 14);
            cout << "INGRESE SU DPI ";
            pa.gotoxy(50, 14);
            cout << "INGRESE SU GENERO [M/F] ";
            pa.gotoxy(80, 14);
            cout << "INGRESE LA FECHA DE NACIMIENTO ";
            pa.gotoxy(80, 15);
            cout << "[ANIO-MES-DIA] ";
            pa.gotoxy(2, 17);
            cout << "INGRESE LA FECHA DE INICIO DE LABORES [ANIO-MES-DIA] ";
            pa.color(6);
            pa.gotoxy(2, 12);
            cin.ignore();
            getline(cin, nombres);
            pa.gotoxy(30, 12);
            getline(cin, apellidos);
            pa.gotoxy(80, 12);
            getline(cin, direccion);
            pa.gotoxy(2, 15);
            cin >> telefono;
            pa.gotoxy(30, 15);
            cin.ignore();
            getline(cin, dpi);
            do {
                pa.gotoxy(55, 15);
                cin >> mf;
                if (mf == "M" || mf == "m") {
                    genero = 0;
                }
                else {
                    if (mf == "F" || mf == "f") {
                        genero = 1;
                    }
                    else {
                        pa.gotoxy(55, 15);
                        cout << "        ";
                    }
                }
            } while (genero != 0 && genero != 1);
            pa.color(6);

            pa.gotoxy(95, 15);
            cin.ignore();
            getline(cin, fecha_nacimiento);
            pa.gotoxy(2, 18);
            cin>>fecha_inicio_lab;
            pa.color(15); //aqui
            do {
                system("cls");
                pa.gotoxy(2, 1);
                cout << "NOMBRES ";
                pa.gotoxy(21, 1);
                cout << "APELLIDOS ";
                pa.gotoxy(2, 4);
                cout << "DIRECCION ";
                pa.gotoxy(21, 4);
                cout << "TELEFONO ";
                pa.gotoxy(2, 7);
                cout << "DPI ";
                pa.gotoxy(21, 7);
                cout << "GENERO ";
                pa.gotoxy(10, 10);
                cout << "FECHA DE NACIMIENTO ";
                pa.gotoxy(10, 13);
                cout << "FECHA INICIO LABORES ";
                pa.color(6);
                pa.gotoxy(2, 2);
                cout << nombres;
                pa.gotoxy(21, 2);
                cout << apellidos;
                pa.gotoxy(2, 5);
                cout << direccion;
                pa.gotoxy(21, 5);
                cout << telefono;
                pa.gotoxy(2, 8);
                cout << dpi;
                pa.gotoxy(21, 8);
                cout << mf;
                pa.gotoxy(10, 11);
                cout << fecha_nacimiento;
                pa.gotoxy(10, 14);
                cout << fecha_inicio_lab;
                pa.color(15);
                pu.mostrar();
                pa.gotoxy(10, 17);
                cout << "ASIGNE UN VALOR DE PUESTO --->    \b";
                cin >> id_puesto;
                existe = pu.existepuesto(id_puesto);
            } while (existe == false);


            pa.gotoxy(10, 18);
            e = Empleado(nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_lab, "");
            e.modificar(ide);
        }
        else {
            cout << "MODIFICACION CANCELADA" << endl;
        }
    }
    else {
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }
}
void eliminarEmpleado() {
    Empleado e = Empleado();
    bool existe;
    int ide;
    char respuesta;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "  INGRESE EL ID DEL EMPLEADO A BORRAR  ";
    pa.color(15);
    pa.gotoxy(39, 6);
    cin >> ide;
    existe = e.existeEmpleado(ide);
    pa.color(15);
    if (existe == true) {
        system("cls");
        e.buscar(ide);
        pa.gotoxy(22, 9);
        cout << "RECUERDE QUE NO PUEDE ELIMINAR UN PUESTO SI HAY EMPLEADOS ASIGNADOS A ESTE";
        pa.gotoxy(36, 10);
        cout << "SEGURO QUE QUIERE ELIMINAR ESTE REGISTRO [S/N] ";
        pa.color(6);
        cin >> respuesta;
        pa.color(15);
        if (respuesta == 'S' || respuesta == 's') {
            pa.gotoxy(39, 11);
            e.eliminar(ide);
        }
        else {
            pa.gotoxy(42, 12);
            cout << "SE HA DETENIDO LA ELIMINACION" << endl;
        }
    }
    else {
        pa.gotoxy(39, 9);
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }

}

void ingresarCliente(string nit){
    Cliente c = Cliente();
    string correo_electronico, nombres, apellidos,mf;
    int telefono, genero =-1;

    Pantalla pa = Pantalla();
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 5);
    pa.gotoxy(38, 3);
    cout << "    INGRESE  LOS  SIGUIENTES  DATOS    ";
    pa.gotoxy(38, 2);
    cout << "                                       ";
    pa.gotoxy(38, 4);
    cout << "                                       ";
    pa.color(15);
    pa.gotoxy(2, 11);
    cout << "NIT                     ";
    pa.gotoxy(30, 11);
    cout << "INGRESE NOMBRES ";
    pa.gotoxy(80, 11);
    cout << "INGRESE APELLIDOS ";
    pa.gotoxy(2, 14);
    cout << "INGRESE CORREO ELECTRONICO ";
    pa.gotoxy(50, 14);
    cout << "INGRESE TELEFONO ";
    pa.gotoxy(80, 14);
    cout << "INGRESE SU GENERO [M/F] ";
    pa.color(6);
    pa.gotoxy(2, 12);
    cout << nit;
    pa.gotoxy(30, 12);
    cin.ignore();
    getline(cin, nombres);
    pa.gotoxy(80, 12);
    getline(cin, apellidos);
    pa.gotoxy(2, 15);
    getline(cin, correo_electronico);
    pa.gotoxy(50, 15);
    cin >> telefono;
    do {
        pa.gotoxy(85, 15);
        cin >> mf;
        if (mf == "M" || mf == "m") {
            genero = 0;
        }
        else {
            if (mf == "F" || mf == "f") {
                genero = 1;
            }
            else {
                pa.gotoxy(85, 15);
                cout << "        ";
            }
        }
    } while (genero != 0 && genero != 1);
    pa.color(15); //aqui
    pa.gotoxy(40, 16);
    c = Cliente(nombres, apellidos, genero, telefono, nit, "", correo_electronico);
    c.ingresar();
}
void buscarCliente() {
    Cliente c = Cliente();
    bool existe;
    int idc, opcion;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 8);
    pa.dibujarCuadro(37, 10, 77, 12);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "   INGRESE METODO POR EL CUAL BUSCAR   ";
    pa.color(15);
    pa.gotoxy(49, 6);
    cout << "[1] ID CLIENTE";
    pa.gotoxy(49, 7);
    cout << "[2] NIT" << endl;
    pa.color(6);
    pa.gotoxy(49, 11);
    cin >> opcion;
    pa.color(15);
    if (opcion == 1)
    {
        system("cls");
        pa.color(8);
        pa.dibujarCuadro(37, 5, 77, 7);
        pa.color(240);
        pa.dibujarCuadro(37, 1, 77, 3);
        pa.gotoxy(38, 2);
        cout << "        INGRESE ID  DEL CLIENTE        ";
        pa.color(6);
        pa.gotoxy(49, 6);
        cin >> idc;
        pa.color(15);
        existe = c.existexid(idc);
        if (existe == true) {
            system("cls");
            c.buscar(idc);
        }
        else {
            pa.gotoxy(39, 6);
            cout << "ESTE ID NO ESTA EN LA BASE DE DATOS" << endl;
            Sleep(1500);
        }
    }
    if (opcion == 2) {
        string nit;
        system("cls");
        pa.color(8);
        pa.dibujarCuadro(37, 5, 77, 7);
        pa.color(240);
        pa.dibujarCuadro(37, 1, 77, 3);
        pa.gotoxy(38, 2);
        cout << "      INGRESE  NIT  DEL  CLIENTE       ";
        pa.color(6);
        pa.gotoxy(49, 6);
        cin >> nit;
        pa.color(15);
        pa.gotoxy(46, 6);
        cout << "       ";
        c.setNit(nit);
        existe = c.existexnit();
        if (existe == true) {
            system("cls");
            string idc = c.asignardatos();
            int idcliente = stoi(idc);
            c.buscar(idcliente);
        }
        else {
            pa.gotoxy(39, 6);
            cout << "ESTE NIT NO ESTA EN LA BASE DE DATOS" << endl;
            Sleep(1500);
        }
    }
    if (opcion != 2 && opcion != 1) {
        pa.gotoxy(39, 11);
        cout << "ESCOJA UNA ACCION CORRECTA" << endl;
        Sleep(1500);
    }
}
void modificarCliente(){
    Cliente c = Cliente();
    char respuesta;
    string correo_electronico, nombres, apellidos, mf,nit;
    int telefono,idc, genero = -1;
    bool existe;
    bool existenit;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "  INGRESE ID DEL REGISTRO A MODIFICAR  ";
    pa.color(6);
    pa.gotoxy(49, 6);
    cin >> idc;
    if (idc != 10) {
        existe = c.existexid(idc);
        pa.color(15);
        if (existe == true) {
            system("cls");
            c.buscar(idc);
            pa.gotoxy(40, 10);
            cout << "SEGURO QUE QUIERES MODIFICAR ESTE REGISTRO [S/N] ";
            pa.color(6);
            cin >> respuesta;
            pa.color(15);
            pa.gotoxy(40, 11);
            if (respuesta == 'S' || respuesta == 's') {
                cout << "INGRESE LOS DATOS QUE SE LE SOLICITA " << endl;
                pa.gotoxy(2, 12);
                cout << "INGRESE NIT ";
                pa.gotoxy(20, 12);
                cout << "INGRESE NOMBRES ";
                pa.gotoxy(40, 12);
                cout << "INGRESE APELLIDOS ";
                pa.gotoxy(70, 12);
                cout << "INGRESE TELEFONO ";
                pa.gotoxy(95, 12);
                cout << "INGRESE SU GENERO [M/F] ";
                pa.gotoxy(2, 15);
                cout << "INGRESE SU CORREO ELECTRONICO ";
                pa.color(6);
                do {
                    pa.gotoxy(2, 13);
                    cin >> nit;
                    c.setNit(nit);
                    existenit = c.existexnit();
                    if (existenit == true) {
                        pa.gotoxy(2, 13);
                        cout << "     ";
                        pa.gotoxy(2, 11);
                        cout << "INGRESE NIT";
                        pa.gotoxy(2, 12);
                        cout << "(SIN REGISTRAR) ";
                    }
                } while (existenit == true);
                pa.gotoxy(20, 13);
                cin.ignore();
                getline(cin, nombres);
                pa.gotoxy(40, 13);
                getline(cin, apellidos);
                pa.gotoxy(70, 13);
                cin >> telefono;
                pa.gotoxy(95, 13);
                do {
                    pa.gotoxy(95, 13);
                    cin >> mf;
                    if (mf == "M" || mf == "m") {
                        genero = 0;
                    }
                    else {
                        if (mf == "F" || mf == "f") {
                            genero = 1;
                        }
                        else {
                            pa.gotoxy(94, 13);
                            cout << "    ";
                        }
                    }
                } while (genero != 0 && genero != 1);
                pa.gotoxy(2, 16);
                cin.ignore();
                getline(cin, correo_electronico);
                pa.color(15);
                c = Cliente(nombres, apellidos, genero, telefono, nit, "", correo_electronico);
                c.modificar(idc);
            }
            else {
                cout << "HA DETENIDO LA MODIFICACION DE FORMA EXISTOSA " << endl;
            }
        }
        else {
            pa.gotoxy(40, 10);
            cout << "ESTE ID NO ESTA EN LA BASE DE DATOS" << endl;
        }
    }
    else {
        pa.color(4);
        cout << " ERROR ";
        pa.color(15);
    }
    
}
void eliminarCliente() {
    Cliente c = Cliente();
    bool existe;
    int idc;
    char respuesta;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "  INGRESE EL ID DEL CLIENTE A ELIMINAR ";
    pa.color(15);
    pa.gotoxy(39, 6);
    cin >> idc;
    if (idc != 10) {
        existe = c.existexid(idc);
        pa.color(15);
        if (existe == true) {
            system("cls");
            c.buscar(idc);
            pa.gotoxy(22, 18);
            cout << "SI YA SE HA GENERADO UNA VENTA CON ESTE CLIENTE NO PODRA SER ELIMINADA DEL REGISTRO" << endl;
            pa.gotoxy(36, 19);
            cout << "SEGURO QUE QUIERE ELIMINAR ESTE REGISTRO [S/N] ";
            pa.color(6);
            cin >> respuesta;
            pa.color(15);
            if ((respuesta == 's') || (respuesta == 'S')) {
                pa.gotoxy(36, 21);
                c.eliminar(idc);
            }
            else {
                pa.gotoxy(36, 21);
                cout << "SE HA DETENIDO LA ELIMINACION" << endl;
            }
        }
        else {
            pa.gotoxy(36, 7);
            cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
        }
    }
    else {
        pa.color(4);
        cout << " ERROR";
        pa.color(15);
    }
}

void ingresarVenta(){
    Pantalla pa = Pantalla();
    char serie,respuesta;
    int no_factura, id_empleado;
    string  id_cliente;
    Venta v = Venta();
    Venta_Detalle vd = Venta_Detalle();
    Empleado e = Empleado();
    Cliente c = Cliente();
    Producto p = Producto();
    int id_venta, id_producto;
    string cantidad;
    float precio_unitario;
    bool existe;
    int opcion;
    float subtotal;
    float total = 0;
    pa.color(96);
    pa.dibujarCuadro(37, 1, 77, 4);
    pa.gotoxy(38, 2);
    cout << " GENERANDO UNA NUEVA  FACTURA DE VENTA ";
    pa.gotoxy(38, 3);
    cout << "           -----------------           ";
    pa.color(15);
    pa.gotoxy(1, 5);
    cout << "\t\t\t\tINGRESE ID DEL EMPLEADO QUE ATIENDE ";
    pa.color(6);
    cin >> id_empleado;
    pa.color(15);
    existe = e.existeEmpleado(id_empleado);
    if (existe == true) {
        e.asignardatos(id_empleado);
        string ne = e.getNombres(); 
        string ae = e.getApellidos();
        string nit;
        pa.gotoxy(1, 6);
        cout << "\t\t\t\tBIENVENIDO(A) DE NUEVO ";
        pa.color(10);
        cout<< ne << "   " << ae <<endl;
        pa.color(15);
        cout << "\t\t\t\t\tDESEA AGREGAR NIT O GENERAR COMO CONSUMIDOR FINAL" << endl;
        cout << "\t\t\t\t\t[1] NIT" << endl;
        cout << "\t\t\t\t\t[2] CF" << endl;
        pa.color(6);
        cout << "\t\t\t\t\t";
        cin >> opcion;
        pa.color(15);
        if (opcion == 1) {
            int i = 0;
            cout << "\t\t\t\t\tPORFAVOR INGRESE SU NIT ";
            pa.color(6);
            cin >> nit;
            pa.color(15);
            do {
                c.setNit(nit);
                existe = c.existexnit();
                if (existe == false) {
                    cout << "REDIRIGIENDO AL REGISTRO DE CLIENTES..." << endl;
                    system("cls");
                    ingresarCliente(nit);
                }
                if (existe == true) {
                    i = 1;
                }
            } while (i == 0);
           id_cliente= c.asignardatos();
           if (id_cliente == "ERROR") {
               cout << "NO SE ENCONTRO DICHO REGISTRO";
               id_cliente = "10";
           }
           else
           {
               pa.color(10);
               c.buscarXnit();
           }
            
        }
        else {
            id_cliente = "10";
        }
        pa.color(15);
        string idventa;
        existe=v.existeVenta();
        if (existe == false) {
            v.setfactura();
            v.setSerie('D');
            v.setIdCliente(id_cliente);
            v.setIdEmpleado(id_empleado);
            v.ingresar();//ingresar productos cambia
            system("cls");
            idventa = v.asignardatos();
            if (idventa != "ERROR") {
                do {
                    system("cls");
                    cinta_transportadora();
                    id_venta = stoi(idventa);
                    v.buscar();
                    pa.gotoxy(20, 8);
                    pa.color(15);
                    cout << "AGREGUE ID DE UN PRODUCTO ";
                    pa.color(6);
                    cin >> id_producto;
                    pa.color(15);
                    bool existeproducto = p.existeProducto(id_producto);
                    if (existeproducto == true){
                        pa.gotoxy(20, 8);
                        p.verProducto(id_producto);
                        pa.gotoxy(20, 9);
                        cout << "AGREGUE CANTIDAD: ";
                        pa.color(6);
                        cin >> cantidad;
                        pa.color(15);
                        pa.gotoxy(18, 9);
                        cout << "                       ";
                        int cant = stoi(cantidad);
                        string precioventa;
                        precioventa = p.returnPV(id_producto);
                        if (precioventa == "ERROR") {
                            cout << endl;
                            cout << "\t\t\t\t\tERROR AL HALLAR EL PRECIO DEL PRODUCTO INGRESELO MANUALMENTE ";
                            pa.color(6);
                            cin >> precio_unitario;
                            pa.color(15);
                        }
                        else {
                            pa.gotoxy(30, 9);
                            cout << "PRECIO ES ";
                            pa.color(10);
                            cout<< precioventa << endl;
                            pa.color(15);
                            precio_unitario = stoi(precioventa);
                        }
                        vd = Venta_Detalle(id_venta, id_producto, cantidad, precio_unitario);
                        vd.ingresar();
                        vd.buscar();
                    }
                    else {
                        pa.gotoxy(20, 8);
                        cout << "NO EXISTE ESTE PRODUCTO                    " ;
                    }
                    pa.gotoxy(20, 10);
                    cout << "DESEA AGREGAR OTRO PRODUCTO [S/N] ";
                    pa.color(6);
                    cin >> respuesta;
                    pa.color(15);
                } while (respuesta == 'S' || respuesta == 's');
                system("cls");
                vd.setIdVenta(id_venta);  //aqui me quede uwu
                v.buscar();
                vd.buscar();
                pa.color(10);
                apagar_cinta();
                caja_registradora();
                pa.gotoxy(20, 10);
                cout << " DESEA IMPRIMIR LA FACTURA [S/N] : ";
                cin >> respuesta;
                pa.color(15);
                if (respuesta == 'S' || respuesta == 's') {
                    pa.gotoxy(20, 10);
                    imprimirf(idventa);
                }
            }
            else
            {
                cout << "\t\t\t\t\tSE GENERO UN ERROR DE IMPREVISTO" << endl;
            }
        }
        else {
            cout << "\t\t\t\t\tESTA FACTURA YA EXISTE" << endl;;
        }

    }
    else {
        cout << "\t\t\t\t\tNO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }
    apagar();
    salir();
    pa.gotoxy(40, 13);
}
void buscarVenta(){
    Venta v = Venta();
    Venta_Detalle vd = Venta_Detalle();
    int factura;
    char serie;
    string id_venta;
    bool existe;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.dibujarCuadro(37, 9, 77, 11);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "  INGRESE LA INFORMACION PARA BUSCAR   ";
    pa.color(15);
    pa.gotoxy(38, 6);
    cout << "INGRESE EL NUMERO DE FACTURA ";
    pa.color(6);
    cin >> factura;
    pa.color(15);
    pa.gotoxy(38, 10);
    cout << "INGRESE LA SERIE ";
    pa.color(6);
    cin >> serie;
    pa.color(15);
    v.setNoFactura(factura);
    v.setSerie(serie);
    existe = v.existeVenta();
    if (existe == true) {
        system("cls");
        v.buscar();
        id_venta=v.asignardatos();
        if (id_venta != "ERROR") {
            int idv = stoi(id_venta);
            vd.setIdVenta(idv);
            vd.buscar();
            char respuesta;
            pa.gotoxy(20, 10);
            pa.color(15);
            cout << " DESEA IMPRIMIR LA FACTURA [S/N] : ";
            cin >> respuesta;
            pa.color(15);
            if (respuesta == 'S' || respuesta == 's') {
                pa.gotoxy(20, 10);
                cout << "                                          ";
                pa.gotoxy(20, 10);
                imprimirf(id_venta);
            }
        }
        else {
            pa.gotoxy(38, 12);
            cout << "ERROR AL GENERAR LA FACTURA"<<endl;
        }
    }
    else {
        pa.gotoxy(37, 12);
        cout << "ESTA FACTURA NO ESTA EN LA BASE DE DATOS" << endl;
    }

    pa.color(15);
    cout << endl;
}
void mostrarVenta(){
    Pantalla pa = Pantalla();
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "      LISTADO DE VENTAS REALIZADAS     ";
    pa.color(15);
    Venta v = Venta();//vamos aqui :D
    v.mostrar();
    pa.color(15);
    cout << endl;
}
void modificarVenta() {
    Pantalla pa = Pantalla();
    Venta v = Venta();
    Venta_Detalle vd = Venta_Detalle();
    Producto p = Producto();
    int  idvd, idproducto, factura;
    float precio;
    char serie, respuesta;
    string id_venta, cantidad, fechafactura;
    bool existe;

    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.dibujarCuadro(37, 9, 77, 11);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << " INGRESE LA INFORMACION PARA ELIMINAR  ";
    pa.color(15);
    pa.gotoxy(38, 6);
    cout << "INGRESE EL NUMERO DE FACTURA ";
    pa.color(6);
    cin >> factura;
    pa.color(15);
    pa.gotoxy(38, 10);
    cout << "INGRESE LA SERIE ";
    pa.color(6);
    cin >> serie;
    pa.color(15);
    v.setNoFactura(factura);
    char a = serie;
    v.setSerie(a);
    existe = v.existeVenta();
    if (existe == true) {
        v.buscar();
        id_venta = v.asignardatos();
        if (id_venta != "ERROR") {
            int idv = stoi(id_venta);
            vd.setIdVenta(idv);
            vd.buscar();
            int i = 0;
            pa.color(15);
            pa.gotoxy(20, 9);
            cout << "SEGURO QUIERES MODIFICAR ESTA FACTURA [S/N] ";
            pa.color(6);
            cin >> respuesta;
            pa.color(15);
            if (respuesta == 'S' || respuesta == 's') {
                pa.color(15);
                pa.gotoxy(20, 9);
                cout << "DESEA ALTERAR LA FECHA DE LA FACTURA  [S/N]  \b";
                pa.color(6);
                cin >> respuesta;
                pa.color(15);
                if (respuesta == 'S' || respuesta == 's') {
                    int res;
                    pa.color(15);
                    pa.gotoxy(20, 9);
                    cout << "[1] DESEA INGRESAR MANUALMENTE                ";
                    pa.gotoxy(20, 10);
                    cout << "[2] DESEA INGRESAR LA FECHA ACTUAL             ";
                    pa.color(6);
                    pa.gotoxy(42, 11);
                    cin >> res;
                    if (res == 1) {
                        string ff;
                        pa.color(15);
                        pa.gotoxy(20, 9);
                        cout << "                                               ";
                        pa.gotoxy(20, 10);
                        cout << "                                               ";
                        pa.gotoxy(20, 11);
                        cout << "                                               ";
                        pa.gotoxy(20, 9);
                        cout << "INGRESE FECHA DE FACTURA [ANIO-MES-DIA] ";
                        pa.color(6);
                        cin >> ff;
                        pa.color(15);
                        pa.gotoxy(20, 10);
                        cout << "                                               ";
                        pa.gotoxy(20, 11);
                        cout << "                                               ";
                        fechafactura = "'" + ff + "'";
                    }
                    else {
                        pa.color(15);
                        pa.gotoxy(20, 9);
                        cout << "                                               ";
                        pa.gotoxy(20, 10);
                        cout << "                                               ";
                        pa.gotoxy(20, 11);
                        cout << "                                               ";
                        fechafactura = "now()";

                    }
                    v.setFechaFactura(fechafactura);
                    v.modificarFechaFactura(id_venta);
                    v.buscar();
                    vd.buscar();
                }
                pa.color(15);
                pa.gotoxy(20, 9);
                cout << "                                               ";
                pa.gotoxy(20, 10);
                cout << "                                               ";
                pa.gotoxy(20, 11);
                cout << "                                               ";
                pa.gotoxy(20, 9);
                cout << "DESEA MODIFICAR EL ID DEL CLIENTE [S/N] ";
                pa.color(6);
                cin >> respuesta;
                pa.color(15);
                if (respuesta == 'S' || respuesta == 's') {
                    bool existecliente;
                    Cliente c = Cliente();
                    int idc;
                    do {
                        pa.color(15);
                        pa.gotoxy(30, 10);
                        cout << "INGRESE ID DEL CLIENTE ";
                        pa.color(6);
                        cin >> idc;
                        pa.color(15);
                        existecliente = c.existexid(idc);
                        if (existecliente == true) {
                            string id_cliente;
                            pa.gotoxy(20, 9);
                            cout << "                                               ";
                            pa.gotoxy(20, 10);
                            cout << "                                               ";
                            pa.gotoxy(20, 11);
                            cout << "                                               ";
                            v.buscar();
                            //c.buscar(idc);
                            pa.color(15);
                            id_cliente = to_string(idc);
                            v.setIdCliente(id_cliente);
                            v.modificarIdCliente(id_venta);
                        }
                        if (existecliente == false) {
                            pa.gotoxy(20, 9);
                            cout << "                                               ";
                            pa.gotoxy(20, 10);
                            cout << "                                               ";
                            pa.gotoxy(20, 11);
                            cout << "                                               ";
                            pa.gotoxy(20, 9);
                            cout << "INGRESE UN VALOR VALIDO ";
                            Sleep(1000);
                        }
                        v.buscar();
                        vd.setIdVenta(idv);
                        vd.buscar();
                        pa.color(15);
                    } while (existecliente == false);
                }
                pa.color(15);
                pa.gotoxy(20, 9);
                cout << "                                                      ";
                pa.gotoxy(20, 9);
                cout << "DESEA MODIFICAR AL EMPLEADO [S/N] ";
                pa.color(6);
                cin >> respuesta;
                pa.color(15);
                int ide;
                bool existeempleado;
                Empleado e = Empleado();
                if (respuesta == 'S' || respuesta == 's') {
                    do {
                        pa.color(15);
                        pa.gotoxy(20, 10);
                        cout << "                                                      ";
                        pa.gotoxy(20, 10);
                        cout << "INGRESE EL ID DEL EMPLEADO ";
                        pa.color(6);
                        cin >> ide;
                        pa.color(15);
                        existeempleado = e.existeEmpleado(ide);
                        if (existeempleado == true) {

                            pa.gotoxy(20, 9);
                            cout << "                                               ";
                            pa.gotoxy(20, 10);
                            cout << "                                               ";
                            pa.gotoxy(20, 11);
                            cout << "                                               ";
                            pa.color(15);
                            v.setIdEmpleado(ide);
                            v.modificarIdEmpleado(id_venta);

                        }
                        if (existeempleado == true) {
                            pa.gotoxy(20, 9);
                            cout << "INGRESE UN VALOR VALIDO ";
                            Sleep(1000);
                        }
                        v.buscar();
                        vd.buscar();
                    } while (existeempleado == false);
                }
                pa.color(15);
                pa.gotoxy(12, 9);
                cout << "DESEA AGREGAR PRODUCTOS O MODIFICAR LOS YA REGISTRADOS EN LA VENTA [S/N] ";
                pa.color(6);
                char respuest;
                cin >> respuest;
                if (respuest == 's' || respuest == 'S') {
                    pa.color(15);
                    pa.gotoxy(12, 9);
                    cout << "                                                                            ";
                    do {
                        v.buscar();
                        vd.buscar();
                        vd.setIdVenta(idv);
                        pa.color(15);
                        int r;
                        pa.gotoxy(30, 9);
                        cout << "[1] MODIFICAR UN PRODUCTO ";
                        pa.gotoxy(30, 10);
                        cout << "[2] INGRESAR OTRO PRODUCTO";
                        pa.gotoxy(40, 11);
                        pa.color(6);
                        int res;
                        cin >> res;
                        pa.color(15);
                        bool existevd;
                        bool existeP;
                        pa.gotoxy(20, 9);
                        cout << "                                               ";
                        pa.gotoxy(20, 10);
                        cout << "                                               ";
                        pa.gotoxy(20, 11);
                        cout << "                                               ";
                        cinta_transportadora();
                        if (res == 1) {
                            
                            pa.color(15);
                            pa.gotoxy(20, 9);
                            cout << "INGRESE ID DEL DETALLE A MODIFICAR ";
                            pa.color(6);
                            cin >> idvd;
                            pa.color(15);
                            existevd = vd.existeVD(idvd);
                            if (existevd == true) {
                                
                                pa.gotoxy(20, 9);
                                cout << "                                               ";
                                pa.gotoxy(20, 11);
                                cout << "                                               ";
                                pa.gotoxy(20, 9);
                                vd.buscarEspecifico(idvd);
                                pa.gotoxy(20, 11);
                                cout << "INGRESE ID DEL PRODUCTO ";
                                pa.color(6);
                                cin >> idproducto;
                                pa.color(15);
                                existeP = p.existeProducto(idproducto);
                                if (existeP == true) {
                                    pa.gotoxy(8, 9);
                                    cout << "                                                                                               ";
                                    pa.gotoxy(8, 11);
                                    cout << "                                                                                               ";
                                    pa.gotoxy(8, 10);
                                    cout << "                                                                                               ";
                                    pa.gotoxy(20, 9);
                                    p.verProducto(idproducto);
                                    pa.gotoxy(20, 10);
                                    cout << "INGRESE CANTIDAD ";
                                    pa.color(6);
                                    cin >> cantidad;
                                    pa.color(15);
                                    string precioventa;
                                    precioventa = p.returnPV(idproducto);
                                    if (precioventa == "ERROR") {
                                        pa.gotoxy(20, 10);
                                        cout << "ERROR AL HALLAR EL PRECIO DEL PRODUCTO INGRESELO MANUALMENTE ";
                                        cin >> precio;
                                    }
                                    else {
                                        pa.gotoxy(20, 11);
                                        cout << "EL PRECIO UNITARIO ES ";
                                        pa.color(10);
                                        cout << precioventa;
                                        Sleep(2000);
                                        pa.color(15);
                                        precio = stoi(precioventa);
                                    }
                                    vd.setIdProducto(idproducto);
                                    vd.setCantidad(cantidad);
                                    vd.setPrecioUnitario(precio);
                                    vd.modificar(idvd);

                                }
                                else {
                                    pa.gotoxy(8, 9);            
                                    cout << "                                                                                               ";
                                    pa.gotoxy(8, 11);
                                    cout << "                                                                                               ";
                                    pa.gotoxy(8, 10);
                                    cout << "                                                                                               ";
                                    pa.gotoxy(20, 9);
                                    cout << "ID DEL PRODUCTO NO VALIDO" << endl;
                                    Sleep(2000);
                                }
                                
                            }
                            else {
                                pa.gotoxy(20, 9);
                                cout << "                                                  " << endl;
                                cout << "ESTE ID POR VENTA DETALLE NO EXISTE " << endl;
                                Sleep(2000);
                            }
                        }
                        if (res == 2) {
                            pa.gotoxy(20, 9);
                            cout << "INGRESE ID DEL PRODUCTO ";
                            pa.color(6);
                            cin >> idproducto;
                            pa.color(15);
                            existeP = p.existeProducto(idproducto);
                            if (existeP == true) {
                                pa.gotoxy(20, 9);
                                p.verProducto(idproducto);
                                pa.gotoxy(20, 10);
                                cout << "INGRESE CANTIDAD ";
                                pa.color(6);
                                cin >> cantidad;
                                pa.color(15);
                                string precioventa;
                                precioventa = p.returnPV(idproducto);
                                if (precioventa == "ERROR") {
                                    pa.gotoxy(20, 11);
                                    cout << "ERROR AL HALLAR EL PRECIO DEL PRODUCTO INGRESELO MANUALMENTE ";
                                    cin >> precio;
                                }
                                else {
                                    pa.gotoxy(20, 11);
                                    cout << "EL PRECIO UNITARIO ES ";
                                    pa.color(10);
                                    cout << precioventa << endl;
                                    precio = stoi(precioventa);
                                    pa.color(15);
                                    Sleep(2000);
                                }
                                int idv = stoi(id_venta);
                                vd.setIdVenta(idv);
                                vd.setIdProducto(idproducto);
                                vd.setCantidad(cantidad);
                                vd.setPrecioUnitario(precio);
                                vd.ingresar();

                            }
                            else {
                                cout << "ESTE PRODUCTO NO EXISTE EN LA BASE DE DATOS ";
                                Sleep(2000);
                            }

                        }
                        apagar_cinta();
                        pa.color(15);
                        id_venta = v.asignardatos();
                        if (id_venta != "ERROR") {
                            int idv = stoi(id_venta);
                            vd.setIdVenta(idv);
                            system("cls");
                            vd.buscar();
                        }
                        else {
                            cout << "ERROR AL GENERAR LA FACTURA" << endl;
                        }
                        v.buscar();
                        vd.buscar();
                        pa.color(15);
                        pa.gotoxy(20, 10);
                        cout << "DESEA AGREGAR PRODUCTOS O MODIFICAR LOS YA REGISTRADOS EN LA VENTA [S/N] ";
                        pa.color(6);
                        cin >> respuesta;
                        pa.color(15);
                        pa.gotoxy(20, 10);
                        cout << "                                                                                        ";
                    } while (respuesta == 'S' || respuesta == 's');
                    salir();
                }
                else {
                    pa.gotoxy(30, 10);
                    cout << "MODIFICACION DETENIDA" << endl;
                }
               
            }
        }
        else {
            pa.gotoxy(30, 10);
            cout << "ERROR AL GENERAR FACTURA" << endl;
        }

    }
    else {
    pa.gotoxy(30, 14);
    cout << "ESTA FACTURA NO ESTA EN LA BASE DE DATOS" << endl;
     }
}
void eliminarVenta() {
    Venta v = Venta();
    Venta_Detalle vd = Venta_Detalle();
    int factura, opcion, idvd;
    char serie, respuesta;
    string id_venta;
    bool existe, existevd;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.dibujarCuadro(37, 9, 77, 11);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "   INGRESE INFORMACION PARA BORRAR     ";
    pa.color(15);
    pa.gotoxy(38, 6);
    cout << "INGRESE EL NUMERO DE FACTURA ";
    pa.color(6);
    cin >> factura;
    pa.color(15);
    pa.gotoxy(38, 10);
    cout << "INGRESE LA SERIE ";
    pa.color(6);
    cin >> serie;
    pa.color(15);
    v.setNoFactura(factura);
    v.setSerie(serie);
    existe = v.existeVenta();
    if (existe == true) {
        system("cls");
        v.buscar();
        id_venta = v.asignardatos();
        if (id_venta != "ERROR") {
            int idv = stoi(id_venta);
            vd.setIdVenta(idv);
            vd.buscar();
            char respuesta;
            pa.gotoxy(20, 9);
            cout << "ES ESTE EL REGISTRO [S/N] ";
            pa.color(6);
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                pa.color(15);
                cout << "                           ";
                pa.gotoxy(20, 9);
                pa.color(15);
                cout << "[1] BORRAR FACTURA POR COMPLETO ";
                pa.gotoxy(20, 10);
                cout << "[2] BORRAR PRODUCTOS DE LA FACTURA";
                pa.gotoxy(30, 11);
                pa.color(6);
                cin >> opcion;
                pa.color(15);
                pa.gotoxy(20, 10);
                cout << "                                                ";
                pa.gotoxy(30, 11);
                cout << "              ";
                pa.gotoxy(20, 9);
                cout << "SEGURO DE ELIMINAR MEDIANTE ESTA OPCION [S/N] ";
                pa.color(6);
                cin >> respuesta;
                pa.color(15);
                if (respuesta == 'S' || respuesta == 's') {
                    if (opcion == 1) {
                        int ivd = stoi(id_venta);
                        vd.eliminar(idv);
                        v.eliminar(id_venta);
                        pa.gotoxy(20, 10);
                        cout << "ELIMINACION CONCLUIDA ";
                        Sleep(2000);
                    }
                    if (opcion == 2) {
                        pa.gotoxy(20, 9);
                        cout << "                                                                        ";
                        pa.gotoxy(20, 9);
                        cout << "INGRESE ID DEL DETALLE A ELIMINAR ";
                        pa.color(6);
                        cin >> idvd;
                        pa.color(15);
                        existevd = vd.existeVD(idvd);
                        if (existevd == true) {
                            vd.buscarEspecifico(idvd);
                            pa.gotoxy(20, 11);
                            cout << "SEGURO DE ELIMINAR ESTE DATO [S/N] ";
                            pa.color(6);
                            cin >> respuesta;
                            pa.color(15);
                            if (respuesta == 'S' || respuesta == 's') {
                                vd.eliminarEspecifico(idvd);
                                pa.gotoxy(20, 11);
                                cout << "ELIMINACION CONCLUIDA                              ";
                                Sleep(2000);
                            }
                            else {
                                pa.gotoxy(20, 11);
                                cout << "SE HA DETENDIO LA ELIMINACION               " << endl;
                            }
                        }
                        else {
                            pa.gotoxy(20, 11);
                            cout << "NO SE ENCONTRO DICHO REGISTRO                  " << endl;
                        }
                    }
                }
            }
            else {
                pa.gotoxy(20, 11);
                cout << "DETENIENDO ELIMINACION                    " << endl;
            }
        }
        else {
            pa.gotoxy(20, 11);
            cout << "ERROR AL GENERAR LA FACTURA              " << endl;
        }
    }
    else {
        pa.gotoxy(20, 11);
            cout << "ESTA FACTURA NO ESTA EN LA BASE DE DATOS    " << endl;
    }
    pa.gotoxy(20, 12);
    pa.color(15);
}

void imprimirf(string idv) {
    Pantalla pa = Pantalla();
    pa.color(10);
    Venta v = Venta();
    v.imprimirFactura(idv);
    tifstream in(TEXT("factura.txt"));
    PrintFile(in);
    in.close();
    pa.color(15);
    pa.gotoxy(38, 10);
    
}

void ingresarMarca(){
    string marca;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 12, 77, 14);
    pa.color(240);
    pa.dibujarCuadro(37, 8, 77, 10);
    pa.gotoxy(38, 9);
    cout << "       INGRESE NOMBRE DE LA MARCA      ";
    pa.color(15);
    pa.gotoxy(39, 13);
    cin.ignore();
    pa.color(6);
    getline(cin, marca);
    Marca m = Marca(marca);
    pa.gotoxy(39, 16);
    pa.color(15);
    m.ingresar();
}
void buscarMarca(){
    int idm;
    bool existe;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "   INGRESE EL ID DE LA MARCA A BUSCAR  ";
    pa.gotoxy(39, 6);
    pa.color(6);
    cin >> idm;
    pa.color(15);
    Marca m = Marca();
    existe = m.existemarca(idm);
    if (existe == true) {
        pa.gotoxy(39, 9);
        m.buscar(idm);
    }
    else {
        pa.gotoxy(38, 6);
        cout << " NO SE ENCONTRO EL ID EN BASE DE DATOS ";
        pa.gotoxy(38, 9);
        pa.color(15);
    }
}
void modificarMarca(){
    int idm;
    string marca;
    char respuesta;
    bool existe;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << " INGRESE EL ID DE LA MARCA A MODIFICAR ";
    pa.gotoxy(39, 6);
    pa.color(6);
    cin >> idm;
    pa.color(15);
    Marca m = Marca();
    existe = m.existemarca(idm);
    if (existe == true) {
        m.buscar(idm);
        pa.gotoxy(35, 18);
        cout << "SEGURO QUE QUIERE MODIFICAR ESTE REGISTRO [S/N] ";
        pa.color(6);
        cin >> respuesta;
        pa.color(15);
        if ((respuesta == 's') || (respuesta == 'S')) {
            system("cls");
            pa.gotoxy(39, 1);
            cout << "  INGRESE EL NUEVO NOMBRE DE LA MARCA  ";
            pa.color(6);
            cin.ignore();
            getline(cin, marca);
            m = Marca(marca);
            pa.color(15);
            pa.gotoxy(39, 3);
            m.modificar(idm);
        }
        else
        {
            pa.color(15);
            pa.gotoxy(39, 19);
            cout << "SE HA INTERRUMPIDO LA MODIFICACION" ;
        }
    }
    else {
        pa.gotoxy(35, 18);
        cout << "EL ID QUE INGRESO NO ESTA REGISTRADO EN LA BASE DE DATOS" << endl;
    }
    pa.gotoxy(39, 20);
}
void eliminarMarca(){
    int idm;
    string marca;
    char respuesta;
    bool existe;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "  INGRESE EL ID DE LA MARCA A BORRAR   ";
    pa.gotoxy(39, 6);
    pa.color(6);
    cin >> idm;
    pa.color(15);
    Marca m = Marca();
    existe = m.existemarca(idm);
    if (existe == true) {
        m.buscar(idm);
        pa.color(15);
        pa.gotoxy(22, 18);
        cout << "RECUERDE QUE NO PUEDE ELIMINAR UNA MARCA SI HAY PRODUCTOS ASIGNADOS A ESTE";
        pa.gotoxy(36, 19);
        cout << "SEGURO QUE QUIERE ELIMINAR ESTE REGISTRO [S/N] " ;
        pa.color(6);
        cin >> respuesta;
        pa.color(15);
        if ((respuesta == 's') || (respuesta == 'S')) {
            pa.gotoxy(36, 21);
            m.eliminar(idm);
        }
        else
        {
            pa.gotoxy(36, 21);
            cout << "SE HA INTERRUMPIDO LA ELIMINACION" << endl;
        }
    }
    else {
        pa.color(15);
        pa.gotoxy(22, 18);
        cout << "NO SE HA ENCONTRADO EL ID EN LA BASE DE DATOS" << endl;
    }
}

void ingresarProducto(){
    Producto p = Producto();
    Marca m = Marca();
    Pantalla pa = Pantalla();
    string producto, descripcion, imagen;
    int id_marca, existencia;
    float p_c, p_v;
    int idm;
    bool existe;
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << " INGRESE EL LOS DATOS QUE SE SOLICITAN ";
    pa.gotoxy(2, 2);
    pa.color(15);
    cout << "INGRESE  PRODUCTO " << endl;
    pa.gotoxy(2, 5);
    cout << "INGRESE LA DESCRIPCION " << endl;
    pa.gotoxy(2, 9);
    cout << "INGRESE LA IMAGEN (ejemplo.png) " << endl;
    pa.gotoxy(80, 2);
    cout << "INGRESE EL PRECIO COSTO " << endl;
    pa.gotoxy(80, 5);
    cout << "INGRESE SU PRECIO VENTA " << endl;
    pa.gotoxy(80, 9);
    cout << "INGRESE LAS EXISTENCIAS " << endl;
    pa.color(6);
    pa.gotoxy(2, 3);
    cin.ignore();
    getline(cin, producto);
    pa.gotoxy(2, 6);
    getline(cin, descripcion);
    pa.gotoxy(2, 10);
    getline(cin, imagen);
    pa.color(15);
    do {
        m.mostrar();
        cout << "\n\n                                        ASIGNE ID DE MARCA       \b\b";
        pa.color(6);
        cin >> id_marca;
        pa.color(15);
        existe = m.existemarca(id_marca);
    } while (existe == false);
    pa.color(6);
    pa.gotoxy(80, 3);
    cout << "Q ";
    cin >> p_c;
    pa.gotoxy(80, 6);
    cout << "Q ";
    cin >> p_v;
    pa.gotoxy(80, 10);
    cin >> existencia;
    p = Producto(producto, id_marca, descripcion, imagen, p_c, p_v, existencia, "");
    pa.color(15);
    pa.gotoxy(2, 12);
    p.ingresar();
    pa.gotoxy(2, 13);
}
void buscarProducto(){
    Producto p = Producto();
    bool existe;
    int idp;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "  INGRESE EL ID DEL PRODUCTO A BUSCAR  ";
    pa.gotoxy(39, 6);
    pa.color(6);
    cin >> idp;
    pa.color(15);
    existe = p.existeProducto(idp);
    if (existe == true) {
        p.buscar(idp);
    }
    else {
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }
}
void modificarProducto(){
    Producto p = Producto();
    bool existe;
    int idp;

    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "INGRESE EL ID DEL PRODUCTO A MODIFICAR ";
    pa.gotoxy(39, 6);
    pa.color(6);
    cin >> idp;
    pa.color(15);
    existe = p.existeProducto(idp);
    pa.gotoxy(39, 9);
    if (existe == true) {
        p.buscar(idp);
        char respuesta;
        pa.gotoxy(35, 9);
        cout << "SEGURO QUE QUIERES MODIFICAR ESTE REGISTRO [S/N] ";
        pa.color(6);
        cin >> respuesta;
        pa.color(15);
        pa.gotoxy(35, 10);
        if (respuesta == 'S' || respuesta == 's') {
            cout << "DESEA MODIFICAR EL NOMBRE DEL PRODUCTO [S/N] ";
            pa.color(6);
            cin >> respuesta;
            pa.color(15);
            pa.gotoxy(35, 11);
            if (respuesta == 'S' || respuesta == 's') {
                string producto;
                cout << "INGRESE NUEVO PRODUCTO ";
                pa.color(6);
                cin.ignore();
                    getline(cin, producto);
                pa.color(15);
                p.setProducto(producto);
                p.modificarProducto(idp);      
            }
            system("cls");
            p.buscar(idp);
            pa.gotoxy(35, 10);
            cout << "DESEA MODIFICAR EL EL ID DE LA MARCA [S/N] ";
            pa.color(6);
            cin >> respuesta;
            pa.color(15);
            system("cls");
            if (respuesta == 'S' || respuesta == 's') {
                int idMarca;
                Marca m = Marca();
                bool exM;
                do {
                    m.mostrar();
                    pa.color(15);
                    cout << "INGRESE NUEVO ID DE MARCA EXISTENTE       \b\b\b";
                    pa.color(6);
                    cin >> idMarca;
                    pa.color(15);
                    exM = m.existemarca(idMarca);
                    if (exM == true) {
                        p.setIdMarca(idMarca);
                        p.modificarIdMarca(idp);
                    }
                   
                } while (exM == false);
            }
            system("cls");
            p.buscar(idp);
            pa.gotoxy(35, 10);
            cout << "DESEA MODIFICAR LA DESCRIPCION DEL PRODUCTO [S/N] ";
            pa.color(6);
            cin >> respuesta;
            pa.color(15);
            if (respuesta == 'S' || respuesta == 's') {
                string descripcion;
                pa.gotoxy(35, 11);
                cout << "INGRESE NUEVA DESCRIPCION ";
                pa.color(6);
                cin.ignore();
                getline(cin, descripcion);
                pa.color(15);
                p.setDescripcion(descripcion);
                p.modificarDescripcion(idp);
            }
            pa.color(15);
            system("cls");
            p.buscar(idp);
            pa.gotoxy(35, 10);
            cout << "DESEA MODIFICAR IMAGEN DEL PRODUCTO [S/N] ";
            pa.color(6);
            cin >> respuesta;
            pa.color(15);
            if (respuesta == 'S' || respuesta == 's') {
                string imagen;
                pa.gotoxy(35, 11);
                cout << "INGRESE NUEVA IMAGEN ";
                pa.color(6);
                cin.ignore();
                getline(cin, imagen);
                pa.color(15);
                p.setImagen(imagen);
                p.modificarImagen(idp);
            }
            system("cls");
            p.buscar(idp);
            pa.gotoxy(35, 10);
            cout << "DESEA MODIFICAR EL PRECIO DE COSTO DEL PRODUCTO [S/N] ";
            pa.color(6);
            cin >> respuesta;
            pa.color(15);
            if (respuesta == 'S' || respuesta == 's') {
                float preciocosto;
                pa.gotoxy(35, 11);
                cout << "INGRESE NUEVO PRECIO DE COSTO ";
                pa.color(6);
                cin >> preciocosto;
                pa.color(15);
                p.setPrecioCosto(preciocosto);
                p.modificarPrecioCosto(idp);
            }
            system("cls");
            p.buscar(idp);
            pa.gotoxy(35, 10);
            cout << "DESEA MODIFICAR EL PRECIO DE VENTA DEL PRODUCTO [S/N] ";
            pa.color(6);
            cin >> respuesta;
            pa.color(15);
            if (respuesta == 'S' || respuesta == 's') {
                float precioventa;
                pa.gotoxy(35, 11);
                cout << "INGRESE NUEVO PRECIO DE VENTA ";
                pa.color(6);
                cin >> precioventa;
                pa.color(15);
                p.setPrecioVenta(precioventa);
                p.modificarPrecioVenta(idp);
            }
            system("cls");
            p.buscar(idp);
            pa.gotoxy(35, 10);
            cout << "DESEA MODIFICAR LAS EXISTENCIAS DEL PRODUCTO [S/N] ";
            pa.color(6);
            cin >> respuesta;
            pa.color(15);
            if (respuesta == 'S' || respuesta == 's') {
                int existencia;
                pa.gotoxy(35, 11);
                cout << "INGRESE NUEVO VALOR DE EXISTENCIAS ";
                pa.color(6);
                cin >> existencia;
                pa.color(15);
                p.setExistencia(existencia);
                p.modificarExistencia(idp);
            }
            system("cls");
            p.buscar(idp);
            pa.gotoxy(35, 10);
        }
    }
    else {
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }
}
void eliminarProducto(){
    Producto p = Producto();
    bool existe;
    int idp;
    char respuesta;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << " INGRESE EL ID DEL PRODUCTO A ELIMINAR ";
    pa.gotoxy(39, 6);
    pa.color(6);
    cin >> idp;
    pa.color(15);
    existe = p.existeProducto(idp);
    if (existe == true) {
        p.buscar(idp);
        pa.gotoxy(35, 9);
        cout << "SEGURO QUE QUIERES ELIMINAR ESTE REGISTRO [S/N] ";
        pa.color(6);
        cin >> respuesta;
        pa.color(15);
        pa.gotoxy(35, 10);
        if (respuesta == 'S' || respuesta == 's') {
            p.eliminar(idp);
        }
        else {
            pa.gotoxy(35, 11);
            cout << "SE HA DETENIDO LA ELIMINACION" << endl;
        }
    }
    else {
        pa.gotoxy(35, 8);
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }
}

void ingresarCompra() {
    Compra c = Compra();
    Compra_Detalle cd = Compra_Detalle();
    Proveedor p = Proveedor();
    Producto pr = Producto();
    Pantalla pa = Pantalla();
    c.nocompra();
    string  f_o,proveedor,idcompra;
    int  idc, id_producto, idproveedor, cant;
    float precio_costo;
    bool existe;
    char respuesta;
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << " INGRESE EL LOS DATOS QUE SE SOLICITAN ";
    pa.color(15);
    do {
        p.mostrar();
        cout << "INGRESE EL ID DEL PROVEEDOR DE LOS PROVEEDORES SIGUIENTES    \b\b\b";
        pa.color(6);
        cin >> idproveedor;
        existe = p.existeproveedor(idproveedor);
        pa.color(15);
    } while (existe==false);
    system("cls");
    pa.gotoxy(2, 2);
    proveedor = p.getProveedor();
    c.setIdProveedor(idproveedor);
    cout << "PROVEEDOR: ";
    pa.gotoxy(40, 2);
    cout << "INGRESE LA FECHA DE ORDEN [ANIO-MES-DIA]" << endl;
    pa.color(6);
    pa.gotoxy(2, 3);
    cout << idproveedor;
    pa.gotoxy(40, 3);
    cin.ignore();
    getline(cin, f_o);
    pa.color(15);
    c.setFechaOrden(f_o);
    c.ingresar();
    idcompra = c.idcompra();
    idc = stoi(idcompra);
    cd.setIdCompra(idc);
    do {
        system("cls");
        c.buscar(idc);
        cd.mostrar(idc);
        pa.gotoxy(20, 10);
        pa.color(15);
        cout << "AGREGUE ID DE UN PRODUCTO ";
        pa.color(6);
        cin >> id_producto;
        pa.color(15);
        bool existeproducto = pr.existeProducto(id_producto);
        if (existeproducto == true) {
            pa.gotoxy(20, 10);
            pr.verProducto(id_producto);
            pa.gotoxy(20, 11);
            cout << "AGREGUE CANTIDAD: ";
            pa.color(6);
            cin >> cant;
            pa.color(15);
             pa.gotoxy(20, 12);
             cout << "AGREGUE PRECIO COSTO ";
                pa.color(6);
                cin >> precio_costo;
                pa.color(15);
                cd = Compra_Detalle(idc, id_producto, cant, precio_costo);
                pa.gotoxy(20, 13);
                cd.ingresar();
                c.buscar(idc);
                cd.mostrar(idc);
        }
        else {
            pa.gotoxy(20, 10);
            cout << "NO EXISTE ESTE PRODUCTO                    ";
            Sleep(1500);
        }
        pa.gotoxy(20, 10);
        system("cls");
        c.buscar(idc);
        cd.mostrar(idc);
        pa.gotoxy(20, 10);
        cout << "DESEA AGREGAR OTRO PRODUCTO [S/N] ";
        pa.color(6);
        cin >> respuesta;
        pa.color(15);
    } while (respuesta == 'S' || respuesta == 's');
    system("cls");
    c.buscar(idc);
    cd.mostrar(idc);
    pa.color(10);
    pa.gotoxy(20, 10);
    cout << " DESEA IMPRIMIR LA FACTURA [S/N] : ";
    cin >> respuesta;
    pa.color(15);
    if (respuesta == 'S' || respuesta == 's') {
        pa.gotoxy(20, 10);
        imprimirfc(idc);
    }

}

void imprimirfc(int idc) {
    
        Pantalla pa = Pantalla();
        pa.color(10);
        pa.gotoxy(38, 11);
        Compra c = Compra();
        c.imprimirFactura(idc);
        tifstream in(TEXT("facturac.txt"));
        PrintFile(in);
        in.close();
        pa.color(15);
        pa.gotoxy(38, 12);

}

void MostrarCompras() {
    Compra c = Compra();
    c.mostrar();

}

void BuscarCompras() {
    Compra c = Compra();
    Pantalla pa = Pantalla();
    Compra_Detalle cd = Compra_Detalle();
    bool existe;
    char respuesta;
    int idcompra, idcd, opcion;
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "  INGRESE LA INFORMACION PARA BUSCAR   ";
    pa.color(15);
    pa.gotoxy(38, 6);
    cout << "INGRESE EL NUMERO DE ORDEN ";
    pa.color(6);
    cin >> opcion;
    pa.color(15);
    existe = c.ExisteCompra(opcion);
    if (existe == true) {
        string idc = c.retIdCompra(opcion);
        if (idc != "ERROR") {
            idcompra = stoi(idc);
            c.buscar(idcompra);
            cd.setIdCompra(idcompra);
            cd.mostrar(idcompra);
            pa.color(10);
            pa.gotoxy(20, 10);
            cout << " DESEA IMPRIMIR LA FACTURA [S/N] : ";
            cin >> respuesta;
            pa.color(15);
            if (respuesta == 'S' || respuesta == 's') {
                pa.gotoxy(20, 10);
                imprimirfc(idcompra);
            }

        }
        else {
            cout << "NO SE ENCONTRO DICHO REGISTRO";
        }
    }
    else {
        pa.gotoxy(28, 10);
        cout << "NO SE ENCONTRO ESTE REGISTRO";
        pa.gotoxy(28, 11);
    }
}

void ModificarCompras() {
    Compra c = Compra();
    Compra_Detalle cd = Compra_Detalle();
    Proveedor p = Proveedor();
    Producto pr = Producto();
    Pantalla pa = Pantalla();
    string  f_o;
    char respuesta;
    int idcd, id_c, id_producto, idproveedor, idcompra, no_or_c, cant, opcion;
    float precio_costo;
    bool existe;
    pa.color(15);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << " INGRESE LA INFORMACION PARA MODIFICAR ";
    pa.color(15);
    pa.gotoxy(38, 6);
    cout << "INGRESE EL NUMERO DE ORDEN ";
    pa.color(6);
    cin >> no_or_c;
    existe = c.ExisteCompra(no_or_c);
    pa.color(15);
    if (existe == true) {
        system("cls");
        string idc = c.retIdCompra(no_or_c);
        if (idc != "ERROR") {
            idcompra = stoi(idc);
            c.buscar(idcompra);
            cd.setIdCompra(idcompra);
            cd.mostrar(idcompra);
            pa.gotoxy(40, 9);
            cout << "SEGURO QUE QUIERE EDITAR ESTE REGISTRO [S/N] ";
                pa.color(6);
                cin >> respuesta;
                pa.color(15);
                pa.gotoxy(40, 10);
                if (respuesta == 's' || respuesta == 'S') {
                    system("cls");
                    c.buscar(idcompra);
                    cd.mostrar(idcompra);
                    pa.gotoxy(40, 9);
                    cout << "[1] EDITAR ENCABEZADO ";
                    pa.gotoxy(40, 10);
                    cout << "[2] EDITAR PRODUCTOS ";
                    pa.gotoxy(40, 11);
                    cout << " INGRESE UNA OPCION ";
                    pa.color(6);
                    cin >> opcion;
                    pa.color(15);
                    system("cls");
                    pa.gotoxy(40, 9);
                    if (opcion == 1) {
                        do {
                            p.mostrar();
                            cout << "INGRESE EL ID DEL PROVEEDOR DE LOS PROVEEDORES SIGUIENTES    \b\b\b";
                            pa.color(6);
                            cin >> idproveedor;
                            existe = p.existeproveedor(idproveedor);
                            pa.color(15);
                        } while (existe == false);
                        system("cls");
                        c.setIdProveedor(idproveedor);
                        pa.gotoxy(2, 2);
                        cout << "PROVEEDOR: ";
                        pa.gotoxy(40, 2);
                        cout << "INGRESE LA FECHA DE ORDEN [ANIO-MES-DIA]" << endl;
                        pa.color(6);
                        pa.gotoxy(2, 3);
                        cout << idproveedor;
                        pa.gotoxy(40, 3);
                        cin.ignore();
                        getline(cin, f_o);
                        pa.color(15);
                        c.setFechaOrden(f_o);
                        c.modificar(idcompra);
                        system("cls");
                        c.buscar(idcompra);
                        cd.mostrar(idcompra);
                        pa.gotoxy(40, 10);
                    }
                    if (opcion == 2) {
                        c.buscar(idcompra);
                        cd.mostrar(idcompra);
                        pa.gotoxy(40, 9);
                        cout << "[1] MODIFICAR REGISTROS ";
                        pa.gotoxy(40, 10);
                        cout << "[2] AGREGAR MAS REGISTROS ";
                        pa.gotoxy(40, 11);
                        cout << " INGRESE UNA OPCION ";
                        pa.color(6);
                        cin >> opcion;
                        pa.color(15);
                        system("cls");
                        if (opcion == 1) {
                            system("cls");
                            c.buscar(idcompra);
                            cd.mostrar(idcompra);
                            pa.color(15);
                            pa.gotoxy(40, 10);
                            cout << "INGRESE ID DEL DETALLE A MODIFICAR ";
                            pa.color(6);
                            cin >> idcd;
                            pa.color(15);
                            existe = cd.ExisteComp_det(idcd);
                            if (existe == true) {
                                cd.buscar(idcd);
                                pa.gotoxy(40, 12);
                                cout << "ES ESTE EL DETALLE A EDITAR [S/N] ";
                                pa.color(6);
                                cin >> respuesta;
                                pa.color(15);
                                if (respuesta == 's' || respuesta == 'S') {
                                    system("cls");
                                    c.buscar(idcompra);
                                    cd.mostrar(idcompra);
                                    pa.gotoxy(20, 10);
                                    pa.color(15);
                                    cout << "AGREGUE ID DE UN PRODUCTO ";
                                    pa.color(6);
                                    cin >> id_producto;
                                    pa.color(15);
                                    bool existeproducto = pr.existeProducto(id_producto);
                                    if (existeproducto == true) {
                                        pa.gotoxy(20, 10);
                                        pr.verProducto(id_producto);
                                        pa.gotoxy(20, 11);
                                        cout << "AGREGUE CANTIDAD: ";
                                        pa.color(6);
                                        cin >> cant;
                                        pa.color(15);
                                        pa.gotoxy(20, 12);
                                        cout << "AGREGUE PRECIO COSTO ";
                                        pa.color(6);
                                        cin >> precio_costo;
                                        pa.color(15);
                                        cd.setIdProducto(id_producto);
                                        cd.setCantidad(cant);
                                        cd.setPrecioCostoUnitario(precio_costo);
                                        pa.gotoxy(20, 13);
                                        cd.modificar(idcd);
                                        c.buscar(idcompra);
                                        cd.mostrar(idcompra);
                                    }
                                    else {
                                        pa.gotoxy(20, 10);
                                        cout << "NO EXISTE ESTE PRODUCTO                    ";
                                        Sleep(1500);
                                    }
                                }
                            }
                            else
                            {
                                cout << "NO SE HALLO EL DETALLE ";
                            }
                        }
                        if (opcion == 2) {
                            system("cls");
                            c.buscar(idcompra);
                            cd.mostrar(idcompra);
                            pa.gotoxy(20, 10);
                            pa.color(15);
                            cout << "AGREGUE ID DE UN PRODUCTO ";
                            pa.color(6);
                            cin >> id_producto;
                            pa.color(15);
                            bool existeproducto = pr.existeProducto(id_producto);
                            if (existeproducto == true) {
                                pa.gotoxy(20, 10);
                                pr.verProducto(id_producto);
                                pa.gotoxy(20, 11);
                                cout << "AGREGUE CANTIDAD: ";
                                pa.color(6);
                                cin >> cant;
                                pa.color(15);
                                pa.gotoxy(20, 12);
                                cout << "AGREGUE PRECIO COSTO ";
                                pa.color(6);
                                cin >> precio_costo;
                                pa.color(15);
                                cd.setIdProducto(id_producto);
                                cd.setCantidad(cant);
                                cd.setPrecioCostoUnitario(precio_costo);
                                pa.gotoxy(20, 13);
                                cd.setIdCompra(idcompra);
                                cd.ingresar();
                                c.buscar(idcompra);
                                cd.mostrar(idcompra);
                            }
                            else {
                                pa.gotoxy(20, 10);
                                cout << "NO EXISTE ESTE PRODUCTO                    ";
                                Sleep(1500);
                            }
                        }
                    }

                }
                else {
                    cout<< "SE HA DETENIDO LA MODIFICACION ";
                }
        }
        else {
            cout << "NO SE ENCONTRO DICHO REGISTRO";
        }
    }
}


void eliminarCompras() {
    Compra c = Compra();
    Compra_Detalle cd = Compra_Detalle();
    Proveedor p = Proveedor();
    Producto pr = Producto();
    Pantalla pa = Pantalla();
    string  f_o;
    char respuesta;
    int idcd, id_c, id_producto, idproveedor, idcompra, no_or_c, cant, opcion;
    float precio_costo;
    bool existe;
    pa.color(15);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "   INGRESE LA INFORMACION PARA BORRAR  ";
    pa.color(15);
    pa.gotoxy(38, 6);
    cout << "INGRESE EL NUMERO DE ORDEN ";
    pa.color(6);
    cin >> no_or_c;
    existe = c.ExisteCompra(no_or_c);
    pa.color(15);
    if (existe == true) {
        system("cls");
        string idc = c.retIdCompra(no_or_c);
        if (idc != "ERROR") {
            idcompra = stoi(idc);
            c.buscar(idcompra);
            cd.setIdCompra(idcompra);
            cd.mostrar(idcompra);
            pa.gotoxy(40, 9);
            cout << "SEGURO QUE QUIERE ELIMINAR ALGO ESTE REGISTRO [S/N] ";
            pa.color(6);
            cin >> respuesta;
            pa.color(15);
            pa.gotoxy(40, 10);
            if (respuesta == 's' || respuesta == 'S') {
                system("cls");
                c.buscar(idcompra);
                cd.mostrar(idcompra);
                pa.gotoxy(40, 9);
                cout << "[1] ELIMINACION COMPLETA ";
                pa.gotoxy(40, 10);
                cout << "[2] ELIMINACION DE PRODUCTOS ";
                pa.gotoxy(40, 11);
                cout << " INGRESE UNA OPCION ";
                pa.color(6);
                cin >> opcion;
                pa.color(15);
                system("cls");
                pa.gotoxy(40, 9);
                if (opcion == 1) {
                    system("cls");
                    c.buscar(idcompra);
                    cd.mostrar(idcompra);
                    pa.gotoxy(40, 10);
                    pa.color(15);
                    cout << " SEGURO QUE QUIERES ELIMINAR ESTE REGISTRO [S/N] ";
                    pa.color(6);
                    cin >> respuesta;
                    pa.color(15);
                    if (respuesta == 'S' || respuesta == 's') {
                        cd.eliminarTodo(idcompra);
                        c.eliminar(idcompra);
                        pa.gotoxy(40, 12);
                        cout << "ELIMINACION CONCLUIDA " << endl;
                        pa.gotoxy(40, 13);
                    }
                }
                if (opcion == 2) {
                    system("cls");
                    c.buscar(idcompra);
                    cd.mostrar(idcompra);
                    pa.gotoxy(40, 9);
                    cout << " INGRESE ID DE COMPRA DETALLE A ELIMINAR ";
                    int idcd;
                    pa.color(6);
                    cin >> idcd;
                    pa.color(15);
                    pa.gotoxy(40, 10);
                    existe = cd.ExisteComp_det(idcd);
                    if (existe == true) {
                        cd.buscar(idcd);
                        pa.gotoxy(40, 12);
                        cout << "SEGURO QUE QUIERE ELIMINAR ESTE DETALLE [S/N] ";
                        pa.color(6);
                        cin >> respuesta;
                        pa.color(15);
                        if (respuesta == 'S' || respuesta == 's') {
                            cd.eliminar(idcd);
                            system("cls");
                            c.buscar(idcompra);
                            cd.mostrar(idcompra);
                            pa.gotoxy(40, 12);
                            cout << "ELIMINACION CORRECTA";
                            Sleep(1500);
                        }

                    }
                    else {
                        cout << "NO EXISTE ESTE ID ";
                    }
                }

            }
            else {
                cout << "SE HA DETENIDO LA MODIFICACION ";
            }
        }
    }
    else {
            cout << "NO SE ENCONTRO DICHO REGISTRO";
        }
}

void IngresarProveedor() {
    Proveedor p = Proveedor();
    Pantalla pa = Pantalla();
    string prov, nit, dir;
    int idproveedor, tel;

    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << " INGRESE EL LOS DATOS QUE SE SOLICITAN ";
    pa.gotoxy(12, 5);
    pa.color(15);
    cout << "INGRESE NOMBRE DEL PROVEEDOR: " << endl;
    pa.gotoxy(60, 5);
    cout << "INGRESE EL NIT  " << endl;
    pa.gotoxy(12, 8);
    cout << "INGRESE LA DIRECCION DEL PROVEEDOR : " << endl;
    pa.gotoxy(60, 8);
    cout << "INGRESE EL TELEFONO DEL PROVEEDOR: " << endl;
    pa.color(6);
    pa.gotoxy(12, 6);
    cin.ignore();
    getline(cin, prov);
    bool existenit;
    do {
        pa.gotoxy(59, 6);
        pa.color(15);
        cout << "       ";
        pa.color(6);
        pa.gotoxy(60, 6);
        getline(cin, nit);
        int n = stoi(nit);
        existenit = p.existeNit(n);
        if (existenit == true) {
            pa.gotoxy(60, 5);
            cout << "INGRESE NIT NO REGISTRADO  " << endl;
        }
    } while (existenit == true);
    pa.color(6);
    pa.gotoxy(12, 9);
    getline(cin, dir);
    pa.gotoxy(60, 9);
    cin.ignore();
    cin >> tel;
    pa.color(15);
    p = Proveedor(prov, nit, dir, tel);
    pa.gotoxy(40, 10);
    p.ingresar();
    pa.gotoxy(40, 11);
}

void MostrarProveedor() {
    Proveedor p = Proveedor();
    cout << "PROVEEDORES EXISTENTES: " << endl;
    p.mostrar();
}

void BuscarProveedor() {
    Proveedor p = Proveedor();
    int idproveedor;
    bool existe;
    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "  INGRESE LA INFORMACION PARA BUSCAR   ";
    pa.color(15);
    pa.gotoxy(38, 6);
    cout << "INGRESE EL PROVEEDOR A BUSCAR: ";
    pa.color(6);
    cin >> idproveedor;
    pa.color(15);
    existe = p.existeproveedor(idproveedor);
    if (existe == true) {
        system("cls");
        p.buscar(idproveedor);
    }

}

void ModificarProveedor() {
    Proveedor p = Proveedor();
    string prov, nit, dir;
    int idproveedor, tel;
    bool existe;
    char respuesta;

    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << " INGRESE LA INFORMACION PARA MODIFICAR ";
    pa.color(15);
    pa.gotoxy(38, 6);
    cout << "INGRESE EL ID DEL PROVEEDOR: ";
    pa.color(6);
    cin >> idproveedor;
    pa.color(15);
    pa.gotoxy(40, 10);
    existe = p.existeproveedor(idproveedor);
    if (existe == true) {
        system("cls");
        p.buscar(idproveedor);
        pa.gotoxy(40, 10);
        cout << "SEGURO QUE QUIERE MODIFICAR ESTE REGISTRO [S/N] " ;
        pa.color(6);
        cin >> respuesta;
        pa.color(15);
        pa.gotoxy(40, 11);
        if ((respuesta == 's') || (respuesta == 'S')) {
            pa.gotoxy(40, 11);
            cout << "DESEA MODIFICAR EL NOMBRE DEL PROVEEDOR ";
            pa.color(6);
            cin >> respuesta;
            pa.color(15);
            if ((respuesta == 's') || (respuesta == 'S')) {
                pa.gotoxy(40, 12);
                cout << "INGRESE EL NUEVO NOMBRE DEL PROVEEDOR " ;
                pa.gotoxy(40, 13);
                cin.ignore();
                pa.color(6);
                getline(cin, prov);
                pa.color(15);
                p.setNombres(prov);
                p.modificarProveedor(idproveedor);
            }
            system("cls");
            p.buscar(idproveedor);
            pa.gotoxy(40, 11);
            cout << "DESEA MODIFICAR EL NIT DEL PROVEEDOR " ;
            pa.color(6);
            cin >> respuesta;
            pa.color(15);
            if ((respuesta == 's') || (respuesta == 'S')) {
                pa.gotoxy(40, 12);
                cout << "INGRESE EL NUEVO NIT DEL PROVEEDOR ";
                pa.color(6);
                bool existenit;
                cin.ignore();
                int n;
                do {
                    pa.gotoxy(38, 13);
                    cout << "         ";
                    pa.gotoxy(40, 13);
                    cin >> n;
                    existenit = p.existeNit(n);
                    nit = to_string(n);
                } while (existenit == true);
                pa.color(15);
                p.setNit(nit);
                p.modificarNit(idproveedor);
                
            }
            system("cls");
            p.buscar(idproveedor);
            pa.gotoxy(40, 11);
            cout << "DESEA MODIFICAR LA DIRECCION " ;
            pa.color(6);
            cin >> respuesta;
            pa.color(15);
            if ((respuesta == 's') || (respuesta == 'S')) {
                pa.gotoxy(40, 12);
                cout << "INGRESE LA NUEVA DIRECCION DEL PROVEEDOR " << endl;
                pa.gotoxy(40, 13);
                pa.color(6);
                cin.ignore();
                getline(cin, dir);
                p.setDireccion(dir);
                p.modificarDireccion(idproveedor);
            }
            system("cls");
            p.buscar(idproveedor);
            pa.gotoxy(40, 11);
            cout << "DESEA MODIFICAR EL TELEFONO " ;
            pa.color(6);
            cin >> respuesta;
            pa.color(15);
            if ((respuesta == 's') || (respuesta == 'S')) {
                pa.gotoxy(40, 12);
                cout << "INGRESE EL NUEVO TELEFONO DEL PROVEEDOR " << endl;
                pa.gotoxy(40, 13);
                pa.color(6);
                cin >> tel;
                pa.color(15);
                p.setTelefono(tel);
                p.modificarTelefono(idproveedor);
            }
        }
        else
        {
            cout << "SE HA INTERRUMPIDO LA MODIFICACION" << endl;
        }
    }
    else {
        cout << "EL ID QUE INGRESO NO ESTA REGISTRADO EN LA BASE DE DATOS" << endl;
    }


}

void EliminarProveedor() {
    Proveedor p = Proveedor();
    int idproveedor;
    char respuesta;
    bool existe;

    Pantalla pa = Pantalla();
    pa.color(8);
    pa.dibujarCuadro(37, 5, 77, 7);
    pa.color(240);
    pa.dibujarCuadro(37, 1, 77, 3);
    pa.gotoxy(38, 2);
    cout << "  INGRESE LA INFORMACION PARA BORRAR   ";
    pa.color(15);
    pa.gotoxy(38, 6);
    cout << "INGRESE EL ID DEL PROVEEDOR: ";
    pa.color(6);
    cin >> idproveedor;
    pa.color(15);
    pa.gotoxy(27, 10);
    existe = p.existeproveedor(idproveedor);
    if (existe == true) {
        system("cls");
        p.buscar(idproveedor);
        cout << "RECUERDE QUE NO PUEDE ELIMINAR PROVEEDORES SI SE HAN ASIGNADO A OTRAS TABLAS" << endl;
        pa.gotoxy(40, 11);
        cout << "SEGURO QUE QUIERE ELIMINAR ESTE REGISTRO [S/N] ";
        pa.color(6);
        cin >> respuesta;
        pa.color(15);
        pa.gotoxy(40, 12);
        if ((respuesta == 's') || (respuesta == 'S')) {
            p.eliminar(idproveedor);
        }
        else
        {
            cout << "SE HA INTERRUMPIDO LA ELIMINACION" << endl;
        }
    }
    else {
        cout << "NO SE HA ENCONTRADO EL ID EN LA BASE DE DATOS" << endl;
    }
    pa.gotoxy(40, 13);
}


void Outtextxy(HDC hdc, int x, int y, tstring Msg)
{
    TextOut(hdc, x, y, Msg.c_str(), static_cast<int>(Msg.length()));
}
void ShowError(tstring strMsg)
{
    MessageBox(NULL, strMsg.c_str(), TEXT("GENERACION FACTURA"), MB_ICONERROR);
    exit(1);
}
void ShowInformation(tstring strText)
{
    MessageBox(NULL, strText.c_str(), TEXT("GENERACION FACTURA"), MB_ICONINFORMATION);
}
void PrintFile(tifstream& f)
{
    PRINTDLG pd;
    DOCINFO di;
    tstring strLine;
    int y = 300;

    memset(&pd, 0, sizeof(PRINTDLG));
    memset(&di, 0, sizeof(DOCINFO));

    di.cbSize = sizeof(DOCINFO);
    di.lpszDocName = TEXT("Imprimiendo");

    pd.lStructSize = sizeof(PRINTDLG);
    pd.Flags = PD_PAGENUMS | PD_RETURNDC;
    pd.nFromPage = 1;
    pd.nToPage = 1;
    pd.nMinPage = 1;
    pd.nMaxPage = 0xFFFF;


    if (f.fail())
        ShowError(TEXT("Error el archivo no se pudo abrir "));

    if (PrintDlg(&pd)) {
        if (pd.hDC) {
            if (StartDoc(pd.hDC, &di) != SP_ERROR) {
                cout << "Imprimiendo... Espere un momento              ";
                StartPage(pd.hDC);
                while (!f.eof()) {
                    getline(f, strLine);
                    Outtextxy(pd.hDC, 500, y, strLine.c_str());
                    y += 100;
                }
                EndPage(pd.hDC);
                EndDoc(pd.hDC);

            }
            else
                ShowError(TEXT("Error: No se pudo comenzar a imprimir."));

        }
        else
            ShowError(TEXT("Error: No se pudo crear el contexto de dispositivo"));

    }
    else
        ShowInformation(TEXT("SE CANCELO IMPRESION DE FACTURA"));

    ShowInformation(TEXT("FINALIZADO PORFAVOR RETIRE SU FACTURA"));
}

void cinta_transportadora() {

    string data = "1";


    char* charArray = new char[data.size() + 1];
    copy(data.begin(), data.end(), charArray);
    charArray[data.size()] = '\n';

    arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
    arduino.readSerialPort(output, MAX_DATA_LENGTH);

    cout << ">> " << output << endl;

    delete[] charArray;
    system("cls");
    //ystem("pause");
}

void apagar_cinta() {

    string data = "2";


    char* charArray = new char[data.size() + 1];
    copy(data.begin(), data.end(), charArray);
    charArray[data.size()] = '\n';

    arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
    arduino.readSerialPort(output, MAX_DATA_LENGTH);

    cout << ">> " << output << endl;

    delete[] charArray;
    system("cls");
    //system("pause");
}

void caja_registradora() {
    string data = "3";


    char* charArray = new char[data.size() + 1];
    copy(data.begin(), data.end(), charArray);
    charArray[data.size()] = '\n';

    arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
    arduino.readSerialPort(output, MAX_DATA_LENGTH);

    cout << ">> " << output << endl;

    delete[] charArray;
    system("cls");
    //system("pause");
}
void apagar() {
    string data = "4";


    char* charArray = new char[data.size() + 1];
    copy(data.begin(), data.end(), charArray);
    charArray[data.size()] = '\n';

    arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
    arduino.readSerialPort(output, MAX_DATA_LENGTH);

    cout << ">> " << output << endl;

    delete[] charArray;
    system("cls");
    //system("pause");

}

void salir() {
    string data = "5";


    char* charArray = new char[data.size() + 1];
    copy(data.begin(), data.end(), charArray);
    charArray[data.size()] = '\n';

    arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
    arduino.readSerialPort(output, MAX_DATA_LENGTH);

    cout << ">> " << output << endl;

    delete[] charArray;
    system("cls");
    //system("pause");

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
