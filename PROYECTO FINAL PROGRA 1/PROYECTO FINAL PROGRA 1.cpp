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
#include <string>
using namespace std;

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

void ingresarMarca();
void buscarMarca();
void modificarMarca();
void eliminarMarca();

void ingresarProducto();
void buscarProducto();
void modificarProducto();
void eliminarProducto();

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
     menu();
}
void menu() {
    int opcion;
    do {
        system("cls");
        cout << "----------------" << endl;
        cout << "PROYECTO FINAL PROGRAMACION 1" << endl;
        cout << " [1]  ACCEDER A LOS PUESTOS" << endl;
        cout << " [2]  ACCEDER A LOS EMPLEADOS" << endl;
        cout << " [3]  ACCEDER A LOS CLIENTES" << endl;
        cout << " [4]  ACCEDER A LOS PROVEEDORES(pendiete)" << endl;
        cout << " [5]  ACCEDER A LAS MARCAS" << endl;
        cout << " [6]  ACCEDER A LOS PRODUCTOS" << endl;
        cout << " [7]  ACCEDER A LAS VENTAS" << endl;
        cout << " [8]  ACCEDER A LAS COMPRAS (pendiente)" << endl;
        cout << " [9]  SALIR" << endl;
        cin >> opcion;
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
    do {
        system("cls");
        cout << "TABLA DE REGISTRO DE PUESTOS" << endl;
        cout << "QUE DESEA REALIZAR" << endl;
        cout << "[1] INGRESAR REGISTROS" << endl;
        cout << "[2] BUSCAR REGISTRO" << endl;
        cout << "[3] MOSTRAR EL LISTADO" << endl;
        cout << "[4] MODIFICAR UN REGISTRO" << endl;
        cout << "[5] ELIMINAR UN REGISTRO" << endl;
        cout << "[6] REGRESAR" << endl;
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
    do {
        system("cls");
        cout << "TABLA DE REGISTRO DE EMPLEADOS" << endl;
        cout << "QUE DESEA REALIZAR" << endl;
        cout << "[1] INGRESAR REGISTROS" << endl;
        cout << "[2] BUSCAR REGISTRO" << endl;
        cout << "[3] MOSTRAR EL LISTADO" << endl;
        cout << "[4] MODIFICAR UN REGISTRO" << endl;
        cout << "[5] ELIMINAR UN REGISTRO" << endl;
        cout << "[6] REGRESAR" << endl;
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
    do {
        system("cls");
        cout << "TABLA DE REGISTRO DE CLIENTES" << endl;
        cout << "QUE DESEA REALIZAR" << endl;
        cout << "[1] INGRESAR REGISTROS" << endl;
        cout << "[2] BUSCAR REGISTRO" << endl;
        cout << "[3] MOSTRAR EL LISTADO" << endl;
        cout << "[4] MODIFICAR UN REGISTRO" << endl;
        cout << "[5] ELIMINAR UN REGISTRO" << endl;
        cout << "[6] REGRESAR" << endl;
        cin >> opc;
        switch (opc) {
        case 1:
            system("cls");
            cout << "INGRESE NIT DEL CLIENTE ";
            cin>>nit;
            bool existe;
            c.setNit(nit);
            existe = c.existexnit();
            if (existe == false) {
                ingresarCliente(nit);
            }
            else {
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
    do {
        system("cls");
        cout << "TABLA DE REGISTRO DE PROVEEDORES" << endl;
        cout << "QUE DESEA REALIZAR" << endl;
        cout << "[1] INGRESAR REGISTROS" << endl;
        cout << "[2] BUSCAR REGISTRO" << endl;
        cout << "[3] MOSTRAR EL LISTADO" << endl;
        cout << "[4] MODIFICAR UN REGISTRO" << endl;
        cout << "[5] ELIMINAR UN REGISTRO" << endl;
        cout << "[6] REGRESAR" << endl;
        cin >> opc;
        switch (opc) {
        case 1:

            break;
        case 2:

            break;
        case 3:
            pv.mostrar();
            break;
        case 4:

            break;
        case 5:

            break;
        }
    } while (opc != 6);
}
void marcas(){
    int opc;
    Marca m = Marca();
    do {
        system("cls");
        cout << "TABLA DE REGISTRO DE MARCAS" << endl;
        cout << "QUE DESEA REALIZAR" << endl;
        cout << "[1] INGRESAR REGISTROS" << endl;
        cout << "[2] BUSCAR REGISTRO" << endl;
        cout << "[3] MOSTRAR EL LISTADO" << endl;
        cout << "[4] MODIFICAR UN REGISTRO" << endl;
        cout << "[5] ELIMINAR UN REGISTRO" << endl;
        cout << "[6] REGRESAR" << endl;
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
    do {
        system("cls");
        cout << "TABLA DE REGISTRO DE PRODUCTOS" << endl;
        cout << "QUE DESEA REALIZAR" << endl;
        cout << "[1] INGRESAR REGISTROS" << endl;
        cout << "[2] BUSCAR REGISTRO" << endl;
        cout << "[3] MOSTRAR EL LISTADO" << endl;
        cout << "[4] MODIFICAR UN REGISTRO" << endl;
        cout << "[5] ELIMINAR UN REGISTRO" << endl;
        cout << "[6] REGRESAR" << endl;
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
    do {
        system("cls");
        cout << "TABLA DE REGISTRO DE VENTAS" << endl;
        cout << "QUE DESEA REALIZAR" << endl;
        cout << "[1] INGRESAR REGISTROS" << endl;
        cout << "[2] BUSCAR REGISTRO" << endl;
        cout << "[3] MOSTRAR EL LISTADO" << endl;
        cout << "[4] MODIFICAR UN REGISTRO" << endl;
        cout << "[5] ELIMINAR UN REGISTRO" << endl;
        cout << "[6] REGRESAR" << endl;
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
    do {
        system("cls");
        cout << "TABLA DE REGISTRO DE COMPRAS" << endl;
        cout << "QUE DESEA REALIZAR" << endl;
        cout << "[1] INGRESAR REGISTROS" << endl;
        cout << "[2] BUSCAR REGISTRO" << endl;
        cout << "[3] MOSTRAR EL LISTADO" << endl;
        cout << "[4] MODIFICAR UN REGISTRO" << endl;
        cout << "[5] ELIMINAR UN REGISTRO" << endl;
        cout << "[6] REGRESAR" << endl;
        cin >> opc;
        switch (opc) {
        case 1:

            break;
        case 2:

            break;
        case 3:
            cp.mostrar();
            break;
        case 4:

            break;
        case 5:

            break;
        }
    } while (opc != 6);
}

void ingresarPuesto() {
    string puesto;
    cout << "INGRESE NOMBRE DEL PUESTO ";
    cin.ignore();
    getline(cin, puesto);
    Puesto p = Puesto(puesto);
    p.ingresar();
}
void buscarPuesto() {
    int idp;
    bool existe;
    cout << "INGRESE EL ID DEL PUESTO A BUSCAR ";
    cin >> idp;
    Puesto p = Puesto();
    existe = p.existepuesto(idp);
    if (existe == true) {
        p.buscar(idp);
    }
    else {
        cout << "NO SE ENCONTRO EL ID EN LA BASE DE DATOS" << endl;
    }
}
void modificarPuesto() {
    int idp;
    string puesto;
    char respuesta;
    bool existe;
    cout << "INGRESE EL ID DEL PUESTO ";
    cin >> idp;
    Puesto p = Puesto();
    existe = p.existepuesto(idp);
    if (existe == true) {
        p.buscar(idp);
        cout << "SEGURO QUE QUIERE MODIFICAR ESTE REGISTRO [S/N]" << endl;
        cin >> respuesta;
        if ((respuesta == 's') || (respuesta == 'S')) {
            cout << "INGRESE EL NUEVO NOMBRE DEL PUESTO " << endl;
            cin.ignore();
            getline(cin, puesto);
            p = Puesto(puesto);
            p.modificar(idp);
        }
        else
        {
            cout << "SE HA INTERRUMPIDO LA MODIFICACION" << endl;
        }
    }
    else {
        cout << "EL ID QUE INGRESO NO ESTA REGISTRADO EN LA BASE DE DATOS"<<endl;
    }
}
void eliminarPuesto() {
    int idp;
    string puesto;
    char respuesta;
    bool existe;
    cout << "INGRESE EL ID DEL PUESTO ";
    cin >> idp;
    Puesto p = Puesto();
    existe = p.existepuesto(idp);
    if (existe == true) {
        p.buscar(idp);
        cout << "RECUERDE QUE NO PUEDE ELIMINAR UN PUESTO SI HAY EMPLEADOS ASIGNADOS A ESTE" << endl;
        cout << "SEGURO QUE QUIERE ELIMINAR ESTE REGISTRO [S/N]" << endl;
        cin >> respuesta;
        if ((respuesta == 's') || (respuesta == 'S')) {
            p.eliminar(idp);
        }
        else
        {
            cout << "SE HA INTERRUMPIDO LA ELIMINACION" << endl;
        }
    }
    else {
        cout << "NO SE HA ENCONTRADO EL ID EN LA BASE DE DATOS" << endl;
    }
}

void ingresarEmpleado() {
    Puesto pu = Puesto();
    string nombres, apellidos,direccion, dpi, fecha_nacimiento, fecha_inicio_lab,mf;
    int id_puesto,telefono,genero=-1;
    bool existe;
    cout << "INGRESE LOS DATOS QUE SE LE SOLICITA " << endl;
    cout << "INGRESE NOMBRES ";
    cin.ignore();
    getline(cin, nombres);
    cout << "INGRESE APELLIDOS ";
    getline(cin, apellidos);
    cout << "INGRESE LA DIRECCION DE DOMICILIO ";
    getline(cin, direccion);
    cout << "INGRESE TELEFONO ";
    cin >> telefono;
    cout << "INGRESE SU DPI ";
    cin.ignore();
    getline(cin, dpi);
    cout << "INGRESE SU GENERO [M/F] ";
    do {
        cin >> mf;
        if (mf == "M" || mf == "m") {
            genero = 0;
        }
        else {
            if (mf == "F" || mf == "f") {
                genero = 1;
            }
            else {
                cout << "PORFAVOR INGRESE UNA OPCION VALIDA " << endl;
                cout << "INGRESE SU GENERO [M/F] ";
            }
        }
    } while (genero != 0 && genero != 1);
    cout << "INGRESE LA FECHA DE NACIMIENTO [AÑO-MES-DIA] ";
    cin.ignore();
    getline(cin, fecha_nacimiento);
    cout << "ASIGNE EL PUESTO POR MEDIO DEL ID " << endl;
    do {
        pu.mostrar();
        cout << endl << "ASIGNE UN VALOR VALIDO ---> ";
        cin >> id_puesto;
        existe = pu.existepuesto(id_puesto);
    }while (existe == false);
    cout << "INGRESE LA FECHA DE INICIO DE LABORES [AÑO-MES-DIA] ";
    cin.ignore();
    getline(cin, fecha_inicio_lab);
    Empleado e = Empleado(nombres,apellidos,direccion,telefono,dpi,genero,fecha_nacimiento,id_puesto,fecha_inicio_lab,"");
    e.ingresar();
}
void buscarEmpleado() {
    Empleado e = Empleado();
    bool existe;
    int ide;
    cout << "INGRESE EL ID DEL EMPLEADO A BUSCAR ";
    cin >> ide;
    existe = e.existeEmpleado(ide);
    if (existe == true) {
        e.buscar(ide);
    }
    else {
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }
}
void modificarEmpleado() {
    Empleado e = Empleado();
    Puesto pu = Puesto();
    string nombres, apellidos, direccion, dpi, fecha_nacimiento, fecha_inicio_lab, mf;
    int id_puesto, telefono, genero = -1;
    bool existeE,existe;
    int ide;
    char respuesta;
    cout << "INGRESE EL ID DEL EMPLEADO A MODIFICAR ";
    cin >> ide;
    existeE = e.existeEmpleado(ide);
    if (existeE == true) {
        e.buscar(ide);
        cout << "SEGURO QUE QUIERE MODIFICAR ESTE REGISTRO [S/N]";
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            cout << "INGRESE NOMBRES ";
            cin.ignore();
            getline(cin, nombres);

            cout << "INGRESE APELLIDOS ";
            getline(cin, apellidos);

            cout << "INGRESE LA DIRECCION DE DOMICILIO ";
            getline(cin, direccion);

            cout << "INGRESE TELEFONO ";
            cin >> telefono;

            cout << "INGRESE SU DPI ";
            cin.ignore();
            getline(cin, dpi);

            cout << "INGRESE SU GENERO [M/F] ";
            do {
                cin >> mf;
                if (mf == "M" || mf == "m") {
                    genero = 0;
                }
                else {
                    if (mf == "F" || mf == "f") {
                        genero = 1;
                    }
                    else {
                        cout << "PORFAVOR INGRESE UNA OPCION VALIDA " << endl;
                        cout << "INGRESE SU GENERO [M/F] ";
                    }
                }
            } while (genero != 0 && genero != 1);

            cout << "INGRESE LA FECHA DE NACIMIENTO [AÑO-MES-DIA] ";
            cin.ignore();
            getline(cin, fecha_nacimiento);

            cout << "ASIGNE EL PUESTO POR MEDIO DEL ID " << endl;
            do {
                pu.mostrar();
                cout << endl << "ASIGNE UN VALOR VALIDO ---> ";
                cin >> id_puesto;
                existe = pu.existepuesto(id_puesto);
            } while (existe == false);

            cout << "INGRESE LA FECHA DE INICIO DE LABORES [AÑO-MES-DIA] ";
            cin.ignore();
            getline(cin, fecha_inicio_lab);
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
    cout << "SI YA SE HA GENERADO OPERACIONES CON ESTE EMPLEADO NO PODRA SER ELIMINADA DEL REGISTRO" << endl;
    cout << "INGRESE EL ID DEL EMPLEADO A BUSCAR ";
    cin >> ide;
    existe = e.existeEmpleado(ide);
    if (existe == true) {
        e.buscar(ide);
        cout << "SEGURO QUE QUIERES ELIMINAR ESTE REGISTRO [S/N] ";
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            e.eliminar(ide);
        }
        else {
            cout << "SE HA DETENIDO LA ELIMINACION" << endl;
        }
    }
    else {
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }

}

void ingresarCliente(string nit){
    Cliente c = Cliente();
    string correo_electronico, nombres, apellidos,mf;
    int telefono, genero =-1;
    cout << "INGRESE LOS DATOS QUE SE LE SOLICITA " << endl;
    cout << "INGRESE NOMBRES ";
    cin.ignore();
    getline(cin, nombres);
    cout << "INGRESE APELLIDOS ";
    getline(cin, apellidos);
    cout << "INGRESE TELEFONO ";
    cin >> telefono;
    cout << "INGRESE SU GENERO [M/F] ";
    do {
        cin >> mf;
        if (mf == "M" || mf == "m") {
            genero = 0;
        }
        else {
            if (mf == "F" || mf == "f") {
                genero = 1;
            }
            else {
                cout << "PORFAVOR INGRESE UNA OPCION VALIDA " << endl;
                cout << "INGRESE SU GENERO [M/F] ";
            }
        }
    } while (genero != 0 && genero != 1);
    cout << "INGRESE SU CORREO ELECTRONICO ";
    cin.ignore();
    getline(cin, correo_electronico);
    c = Cliente(nombres, apellidos, genero, telefono, nit, "", correo_electronico);
    c.ingresar();
}
void buscarCliente() {
    Cliente c = Cliente();
    bool existe;
    int idc, opcion;
    cout << "BUSCAR CLIENTE POR MEDIO DE: " << endl;
    cout << "[1] ID CLIENTE" << endl;
    cout << "[2] NIT" << endl;
    cin >> opcion;
    if (opcion == 1)
    {
        cout << "INGRESE ID DEL CLIENTE ";
        cin >> idc;
        existe = c.existexid(idc);
        if (existe == true) {
            c.buscar(idc);
        }
        else {
            cout << "ESTE ID NO ESTA EN LA BASE DE DATOS" << endl;
        }
    }
    if (opcion == 2) {
        string nit;
        cout << "INGRESE NIT DEL CLIENTE ";
        cin >> nit;
        c.setNit(nit);
        existe = c.existexnit();
        if (existe == true) {
            string idc = c.asignardatos();
            int idcliente = stoi(idc);
            c.buscar(idcliente);
        }
        else {
            cout << "ESTE NIT NO ESTA EN LA BASE DE DATOS" << endl;
        }
    }
    if (opcion != 2 && opcion != 1) {
        cout << "ESCOJA UNA ACCION CORRECTA" << endl;
    }
}
void modificarCliente(){
    Cliente c = Cliente();
    char respuesta;
    string correo_electronico, nombres, apellidos, mf,nit;
    int telefono,idc, genero = -1;
    bool existe;
    cout << "INGRESE ID DEL REGISTRO A MODIFICAR ";
    cin >> idc;
    existe = c.existexid(idc);
    if (existe == true) {
        c.buscar(idc);
        cout << "SEGURO QUE QUIERES MODIFICAR ESTE REGISTRO [S/N] ";
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            cout << "INGRESE LOS DATOS QUE SE LE SOLICITA " << endl;
            cout << "INGRESE NIT ";
            cin.ignore();
            getline(cin, nit);
            cout << "INGRESE NOMBRES ";
            getline(cin, nombres);
            cout << "INGRESE APELLIDOS ";
            getline(cin, apellidos);
            cout << "INGRESE TELEFONO ";
            cin >> telefono;
            cout << "INGRESE SU GENERO [M/F] ";
            do {
                cin >> mf;
                if (mf == "M" || mf == "m") {
                    genero = 0;
                }
                else {
                    if (mf == "F" || mf == "f") {
                        genero = 1;
                    }
                    else {
                        cout << "PORFAVOR INGRESE UNA OPCION VALIDA " << endl;
                        cout << "INGRESE SU GENERO [M/F] ";
                    }
                }
            } while (genero != 0 && genero != 1);
            cout << "INGRESE SU CORREO ELECTRONICO ";
            cin.ignore();
            getline(cin, correo_electronico);
            c = Cliente(nombres, apellidos, genero, telefono, nit, "", correo_electronico);
            c.modificar(idc);
        }
        else {
            cout << "HA DETENIDO LA MODIFICACION DE FORMA EXISTOSA " << endl;
        }
    }
    else {
        cout << "ESTE ID NO ESTA EN LA BASE DE DATOS" << endl;
    }

    
}
void eliminarCliente(){
    Cliente c = Cliente();
    bool existe;
    int idc;
    char respuesta;
    cout << "SI YA SE HA GENERADO UNA VENTA CON ESTE CLIENTE NO PODRA SER ELIMINADA DEL REGISTRO" << endl;
    cout << "INGRESE EL ID DEL CLIENTE A ELIMINAR ";
    cin >> idc;
    existe = c.existexid(idc);
    if (existe == true) {
        c.buscar(idc);
        cout << "SEGURO QUE QUIERES ELIMINAR ESTE REGISTRO [S/N] ";
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            c.eliminar(idc);
        }
        else {
            cout << "SE HA DETENIDO LA ELIMINACION" << endl;
        }
    }
    else {
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }
}

void ingresarVenta(){
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
    

    cout << "GENERANDO UNA NUEVA FACTURA DE VENTA" << endl;
    cout << "INGRESE ID DEL EMPLEADO QUE ATIENDE ";
    cin >> id_empleado;
    existe = e.existeEmpleado(id_empleado);
    if (existe == true) {
        e.asignardatos(id_empleado);
        string ne = e.getNombres(); //revisar si estos datos no los muestra luego
        string ae = e.getApellidos();
        string nit;
        cout << "BIENVENIDO(A) DE NUEVO " << ne << "   " << ae << endl;
        cout << "DESEA AGREGAR NIT O GENERAR COMO CONSUMIDOR FINAL" << endl;
        cout << "[1] NIT" << endl;
        cout << "[2] CF" << endl;
        cin >> opcion;
        if (opcion == 1) {
            int i = 0;
            cout << "PORFAVOR INGRESE SU NIT ";
            cin >> nit;
            do {
                c.setNit(nit);
                existe = c.existexnit();
                if (existe == false) {
                    cout << "REDIRIGIENDO AL REGISTRO DE CLIENTES..." << endl;
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
               c.buscarXnit();
           }
            
        }
        else {
            id_cliente = "10";
        }
        cout << "INGRESE NUMERO DE FACTURA ";
        cin >> no_factura;
        cout << "INGRESE SERIE ";
        cin >> serie;
        v.setNoFactura(no_factura);
        v.setSerie(serie);
        string idventa;
        existe=v.existeVenta();
        if (existe == false) {
            v = Venta(no_factura, serie, "", id_cliente, id_empleado, "");
            v.ingresar();
            idventa = v.asignardatos();
            if (idventa != "ERROR") {
                do {
                    id_venta = stoi(idventa);
                    cout << "AÑADA ID DE UN PRODUCTO "; 
                    cin >> id_producto;
                    cout << "AÑADA CANTIDAD: ";
                    cin >> cantidad;
                    int cant = stoi(cantidad);

                    string precioventa;
                    precioventa = p.returnPV(id_producto);
                    if (precioventa == "ERROR") {
                        cout << "ERROR AL HALLAR EL PRECIO DEL PRODUCTO INGRESELO MANUALMENTE ";
                        cin >> precio_unitario;
                    }
                    else {
                        cout << "EL PRECIO ES " << precioventa << endl;
                        precio_unitario = stoi(precioventa);
                    }
                    vd = Venta_Detalle(id_venta, id_producto, cantidad, precio_unitario);
                    vd.ingresar();
                    subtotal = cant * precio_unitario;
                    total = total + subtotal;
                    cout << "DESEA AGREGAR OTRO PRODUCTO [S/N] ";
                    cin >> respuesta;
                } while (respuesta == 'S' || respuesta == 's');
                cout << "       EL TOTAL ES Q" << total;
            }
            else
            {
                cout << "SE GENERO UN ERROR DE IMPREVISTO" << endl;
            }
        }
        else {
            cout << "ESTA FACTURA YA EXISTE" << endl;;
        }

    }
    else {
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }

}
void buscarVenta(){
    Venta v = Venta();
    Venta_Detalle vd = Venta_Detalle();
    int factura;
    char serie;
    string id_venta;
    bool existe;
    cout << "INGRESE LA SIGUIENTE INFORMACION PARA BUSCAR " << endl;
    cout << "INGRESE EL NUMERO DE FACTURA ";
    cin >> factura;
    cout << "INGRESE LA SERIE ";
    cin >> serie;
    v.setNoFactura(factura);
    v.setSerie(serie);
    existe = v.existeVenta();
    if (existe == true) {
        v.buscar();
        id_venta=v.asignardatos();
        if (id_venta != "ERROR") {
            int idv = stoi(id_venta);
            vd.setIdVenta(idv);
            vd.buscar();
        }
        else {
            cout << "ERROR AL GENERAR LA FACTURA"<<endl;
        }
    }
    else {
        cout << "ESTA FACTURA NO ESTA EN LA BASE DE DATOS" << endl;
    }

}
void mostrarVenta(){
    cout << "LISTADO DE VENTAS REALIZADAS " << endl;
    Venta v = Venta();
    v.mostrar();
}
void modificarVenta(){
    Venta v = Venta();
    Venta_Detalle vd = Venta_Detalle();
    Producto p = Producto();
    int  idvd, idproducto, factura;
    float precio;
    char serie,respuesta;
    string id_venta, cantidad, fechafactura;
    bool existe;
    cout << "INGRESE LA SIGUIENTE INFORMACION PARA LA BUSQUEDA " << endl;
    cout << "INGRESE EL NUMERO DE FACTURA ";
    cin >> factura;
    cout << "INGRESE LA SERIE ";
    cin >> serie;
    v.setNoFactura(factura);
    v.setSerie(serie);
    existe = v.existeVenta();
    if (existe == true) {
        v.buscar();
        id_venta = v.asignardatos();
        if (id_venta != "ERROR") {
            int idv = stoi(id_venta);
            vd.setIdVenta(idv);
            vd.buscar();
            int i = 0;
            cout << "SEGURO QUIERES MODIFICAR ESTA FACTURA [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                do {
                    i = 0;
                    char r, ser;
                    int fact;
                    cout << "DESEA ALTERAR EL NO DE FACTURA [S/N]" << endl;
                    cin >> r;
                    if (r == 'S' || r == 's') {
                        cout << "INGRESE NO DE FACTURA ";
                        cin >> fact;
                        cout << "DESEA ALTERAR LA SERIE DE LA FACTURA [S/N]" << endl;
                        cin >> r;
                        if (r == 'S' || r == 's') {
                            cout << "INGRESE SERIE  " << endl;
                            cin >> ser;
                            v.setNoFactura(fact);
                            v.setSerie(ser);
                            existe = v.existeVenta();
                        }
                        else {
                            v.setNoFactura(fact);
                            v.setSerie(serie);
                            existe = v.existeVenta();
                        }

                        if (existe == true) {
                            i = 1;
                            cout << "YA EXISTE EN LA BASE DE DATOS" << endl;
                        }
                        else {
                            i = 0;
                            v.modificarSerie(id_venta);
                            v.modificarNoFactura(id_venta);
                        }
                    }
                    else {
                        cout << "DESEA ALTERAR LA SERIE [S/N] " << endl;
                        cin >> r;
                        if (r == 'S' || r == 's') {
                            cout << "INGRESE SERIE  " << endl;
                            cin >> ser;
                            v.setSerie(ser);
                            v.setNoFactura(factura);
                            existe = v.existeVenta();
                            if (existe == true) {
                                i = 1;
                                cout << "YA EXISTE EN LA BASE DE DATOS" << endl;
                            }
                            else {
                                i = 0;
                                v.modificarSerie(id_venta);
                            }
                        }

                    }
                } while (i == 1);

                cout << "DESEA ALTERAR LA FECHA DE LA FACTURA [S/N] ";
                cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    int res;
                    cout << "[1] DESEA INGRESAR MANUALMENTE" << endl;
                    cout << "[2] DESEA INGRESAR LA FECHA ACTUAL" << endl;
                    cin >> res;
                    if (res == 1) {
                        string ff;
                        cout << "INGRESE FECHA DE FACTURA [ANIO-MES-DIA] ";
                        cin >> ff;
                        fechafactura = "'" + ff + "'";
                    }
                    else {
                        fechafactura = "now()";

                    }
                    v.setFechaFactura(fechafactura);
                    v.modificarFechaFactura(id_venta);
                }
                cout << "DESEA MODIFICAR EL ID DEL CLIENTE [S/N]" << endl;
                cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    bool existecliente;
                    Cliente c = Cliente();
                    int idc;
                    do {
                        cout << "INGRESE ID DEL CLIENTE ";
                        cin >> idc;
                        existecliente = c.existexid(idc);
                        if (existecliente == true) {
                            string id_cliente;
                            id_cliente = to_string(idc);
                            v.setIdCliente(id_cliente);
                            v.modificarIdCliente(id_venta);
                        }
                    } while (existecliente == false);
                }
                cout << "DESEA MODIFICAR AL EMPLEADO [S/N] " << endl;
                cin >> respuesta;
                int ide;
                bool existeempleado;
                Empleado e = Empleado();
                if (respuesta == 'S' || respuesta == 's') {
                    do {
                        cout << "IGRESE EL ID DEL EMPLEADO ";
                        cin >> ide;
                        existeempleado = e.existeEmpleado(ide);
                        if (existeempleado == true) {
                            v.setIdEmpleado(ide);
                            v.modificarIdEmpleado(id_venta);
                        }
                    } while (existeempleado == false);
                }
                cout << "----------------------------------------" << endl << endl;
                cout << "DESEA AGREGAR PRODUCTOS O MODIFICAR LOS YA REGISTRADOS EN LA VENTA [S/N] ";
                cin >> respuesta;
                do {
                    int r;
                    cout << "[1] MODIFICAR UN PRODUCTO " << endl;
                    cout << "[2] INGRESAR OTRO PRODUCTO" << endl;
                    int res;
                    cin >> res;
                    bool existevd;
                    bool existeP;
                    if (res == 1) {
                        cout << "INGRESE ID DEL DETALLE A MODIFICAR ";
                        cin >> idvd;
                        existevd = vd.existeVD(idvd);
                        if (existevd == true) {
                            vd.buscarEspecifico(idvd);
                            cout << "INGRESE ID DEL PRODUCTO " << endl;
                            cin >> idproducto;
                            existeP = p.existeProducto(idproducto);
                            if (existeP == true) {
                                cout << "INGRESE CANTIDAD " << endl;
                                cin >> cantidad;
                                string precioventa;
                                precioventa=p.returnPV(idproducto);
                                if (precioventa == "ERROR") {
                                    cout << "ERROR AL HALLAR EL PRECIO DEL PRODUCTO INGRESELO MANUALMENTE ";
                                    cin >> precio;
                                }
                                else {
                                    cout << "EL PRECIO UNITARIO ES " << precioventa << endl;
                                    precio = stoi(precioventa);
                                }
                                vd.setIdProducto(idproducto);
                                vd.setCantidad(cantidad);
                                vd.setPrecioUnitario(precio);
                                vd.modificar(idvd);
                            }
                            else {
                                cout << "ID DEL PRODUCTO NO VALIDO" << endl;
                            }
                        }
                        else {
                            cout << "ESTE ID POR VENTA DETALLE NO EXISTE " << endl;
                        }
                    }
                    if (res == 2) {
                        cout << "INGRESE ID DEL PRODUCTO " << endl;
                        cin >> idproducto;
                        existeP = p.existeProducto(idproducto);
                        if (existeP == true) {
                            cout << "INGRESE CANTIDAD " << endl;
                            cin >> cantidad;
                            string precioventa;
                            precioventa = p.returnPV(idproducto);
                            if (precioventa == "ERROR") {
                                cout << "ERROR AL HALLAR EL PRECIO DEL PRODUCTO INGRESELO MANUALMENTE ";
                                cin >> precio;
                            }
                            else {
                                cout << "EL PRECIO UNITARIO ES " << precioventa << endl;
                                precio = stoi(precioventa);
                            }
                            int idv = stoi(id_venta);
                            vd.setIdVenta(idv);
                            vd.setIdProducto(idproducto);
                            vd.setCantidad(cantidad);
                            vd.setPrecioUnitario(precio);
                            vd.ingresar();
                        }
                        else {
                            cout<<"ESTE PRODUCTO NO EXISTE EN LA BASE DE DATOS "<<endl;
                        }

                    }
                    system("pause");
                    system("cls");
                    v.buscar();
                    id_venta = v.asignardatos();
                    if (id_venta != "ERROR") {
                        int idv = stoi(id_venta);
                        vd.setIdVenta(idv);
                        vd.buscar();
                    }
                    else {
                        cout << "ERROR AL GENERAR LA FACTURA" << endl;
                    }
                    cout << "DESEA AÑADIR PRODUCTOS O MODIFICAR LOS YA REGISTRADOS EN LA VENTA [S/N] ";
                    cin >> respuesta;
                } while (respuesta == 'S' || respuesta == 's');
            }
        else {
                cout << "MODIFICACION DETENIDA" << endl;
        }
        }
        else {
            cout << "ERROR AL GENERAR LA FACTURA" << endl;
        }
    }
    else {
        cout << "ESTA FACTURA NO ESTA EN LA BASE DE DATOS" << endl;
    }



}
void eliminarVenta(){
    Venta v = Venta();
    Venta_Detalle vd = Venta_Detalle();
    int factura,opcion,idvd;
    char serie,respuesta;
    string id_venta;
    bool existe,existevd;
    cout << "INGRESE LA SIGUIENTE INFORMACION PARA BUSCAR Y BORRAR " << endl;
    cout << "INGRESE EL NUMERO DE FACTURA ";
    cin >> factura;
    cout << "INGRESE LA SERIE ";
    cin >> serie;
    v.setNoFactura(factura);
    v.setSerie(serie);
    existe = v.existeVenta();
    if (existe == true) {
        v.buscar();
        id_venta = v.asignardatos();
        if (id_venta != "ERROR") {
            int idv = stoi(id_venta);
            vd.setIdVenta(idv);
            vd.buscar();
            cout << "[1] BORRAR FACTURA POR COMPLETO " << endl;
            cout << "[2] BORRAR PRODUCTOS DE LA FACTURA" << endl;
            cin >> opcion;
            cout << "SEGURO DE ELIMINAR MEDIANTE ESTA OPCION [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                if (opcion == 1) {
                    int ivd = stoi(id_venta);
                    vd.eliminar(idv);
                    v.eliminar(id_venta);
                }
                if (opcion == 2) {
                    cout << "INGRESE ID DEL DETALLE A ELIMINAR ";
                    cin >> idvd;
                    existevd = vd.existeVD(idvd);
                    if (existevd == true) {
                        vd.buscarEspecifico(idvd);
                        cout << "SEGURO DE ELIMINAR ESTE DATO [S/N] ";
                        cin >> respuesta;
                        if (respuesta == 'S' || respuesta == 's') {
                            vd.eliminarEspecifico(idvd);
                        }
                        else {
                            cout << "SE HA DETENDIO LA ELIMINACION " << endl;
                        }
                    }
                    else {
                        cout << "NO SE ENCONTRO DICHO REGISTRO " << endl;
                    }
                }
            }
        }
        else {
            cout << "ERROR AL GENERAR LA FACTURA" << endl;
        }
    }
    else {
        cout << "ESTA FACTURA NO ESTA EN LA BASE DE DATOS" << endl;
    }
}

void ingresarMarca(){
    string marca;
    cout << "INGRESE NOMBRE DE LA MARCA ";
    cin.ignore();
    getline(cin, marca);
    Marca m = Marca(marca);
    m.ingresar();
}
void buscarMarca(){
    int idm;
    bool existe;
    cout << "INGRESE EL ID DE LA MARCA A BUSCAR ";
    cin >> idm;
    Marca m = Marca();
    existe = m.existemarca(idm);
    if (existe == true) {
        m.buscar(idm);
    }
    else {
        cout << "NO SE ENCONTRO EL ID EN LA BASE DE DATOS" << endl;
    }
}
void modificarMarca(){
    int idm;
    string marca;
    char respuesta;
    bool existe;
    cout << "INGRESE EL ID DE LA MARCA ";
    cin >> idm;
    Marca m = Marca();
    existe = m.existemarca(idm);
    if (existe == true) {
        m.buscar(idm);
        cout << "SEGURO QUE QUIERE MODIFICAR ESTE REGISTRO [S/N] " << endl;
        cin >> respuesta;
        if ((respuesta == 's') || (respuesta == 'S')) {
            cout << "INGRESE EL NUEVO NOMBRE DE LA MARCA " << endl;
            cin.ignore();
            getline(cin, marca);
            m = Marca(marca);
            m.modificar(idm);
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
void eliminarMarca(){
    int idm;
    string marca;
    char respuesta;
    bool existe;
    cout << "INGRESE EL ID DE LA MARCA ";
    cin >> idm;
    Marca m = Marca();
    existe = m.existemarca(idm);
    if (existe == true) {
        m.buscar(idm);
        cout << "RECUERDE QUE NO PUEDE ELIMINAR UNA MARCA SI HAY PRODUCTOS ASIGNADOS A ESTE" << endl;
        cout << "SEGURO QUE QUIERE ELIMINAR ESTE REGISTRO [S/N]" << endl;
        cin >> respuesta;
        if ((respuesta == 's') || (respuesta == 'S')) {
            m.eliminar(idm);
        }
        else
        {
            cout << "SE HA INTERRUMPIDO LA ELIMINACION" << endl;
        }
    }
    else {
        cout << "NO SE HA ENCONTRADO EL ID EN LA BASE DE DATOS" << endl;
    }
}

void ingresarProducto(){
    Producto p = Producto();
    Marca m = Marca();
    string producto, descripcion, imagen;
    int id_marca, existencia;
    float p_c, p_v;
    int idm;
    bool existe;
    cout << "INGRESE LOS DATOS QUE SE LE SOLICITA " << endl;
    cout << "INGRESE  PRODUCTO :" << endl;
    cin.ignore();
    getline(cin, producto);
    cout << "ASIGNE LA MARCA POR MEDIO DEL ID " << endl;
    do {
        m.mostrar();
        cout << endl << "ASIGNE UN VALOR VALIDO ---> ";
        cin >> id_marca;
        existe = m.existemarca(id_marca);
    } while (existe == false);

    cout << "INGRESE LA DESCRIPCION: " << endl;
    cin.ignore();
    getline(cin, descripcion);
    cout << "INGRESE LA IMAGEN (ejemplo.png): " << endl;
    getline(cin, imagen);
    cout << "INGRESE EL PRECIO COSTO: " << endl;
    cin >> p_c;
    cout << "INGRESE SU PRECIO VENTA: " << endl;
    cin >> p_v;
    cout << "INGRESE LAS EXISTENCIAS: " << endl;
    cin >> existencia;
    p = Producto(producto, id_marca, descripcion, imagen, p_c, p_v, existencia, "");
    p.ingresar();
}
void buscarProducto(){
    Producto p = Producto();
    bool existe;
    int idp;
    cout << "INGRESE EL ID DEL PRODUCTO A BUSCAR ";
    cin >> idp;
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
    cout << "INGRESE EL ID DEL PRODUCTO A MODIFICAR ";
    cin >> idp;
    existe = p.existeProducto(idp);
    if (existe == true) {
        p.buscar(idp);
        char respuesta;
        cout << "SEGURO QUE QUIERES MODIFICAR ESTE REGISTRO [S/N] ";
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            cout << "DESEA MODIFICAR EL NOMBRE DEL PRODUCTO [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                string producto;
                cout << "INGRESE NUEVO PRODUCTO ";
                cin >> producto;
                p.setProducto(producto);
                p.modificarProducto(idp);
            }

            cout << "DESEA MODIFICAR EL EL ID DE LA MARCA [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                int idMarca;
                Marca m = Marca();
                bool exM;
                do {
                    cout << "INGRESE NUEVO ID DE MARCA EXISTENTE ";
                    cin >> idMarca;
                    exM = m.existemarca(idMarca);
                    if (exM == true) {
                        p.setIdMarca(idMarca);
                        p.modificarIdMarca(idp);
                    }
                    else {
                        cout << "NO SE ENCONTRO DICHO ID VUELVA A PROBAR";
                        cout << "DESEA VER LAS MARCAS DISPONIBLES [S/N] ";
                        cin >> respuesta;
                        if (respuesta == 'S' || respuesta == 's') {
                            m.mostrar();
                        }
                    }
                } while (exM == false);
            }
            cout << "DESEA MODIFICAR LA DESCRIPCION DEL PRODUCTO [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                string descripcion;
                cout << "INGRESE NUEVA DESCRIPCION ";
                cin >> descripcion;
                p.setDescripcion(descripcion);
                p.modificarDescripcion(idp);
            }
            cout << "DESEA MODIFICAR IMAGEN DEL PRODUCTO [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                string imagen;
                cout << "INGRESE NUEVA IMAGEN ";
                cin >> imagen;
                p.setImagen(imagen);
                p.modificarImagen(idp);
            }
            cout << "DESEA MODIFICAR EL PRECIO DE COSTO DEL PRODUCTO [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                float preciocosto;
                cout << "INGRESE NUEVO PRECIO DE COSTO ";
                cin >> preciocosto;
                p.setPrecioCosto(preciocosto);
                p.modificarPrecioCosto(idp);
            }
            cout << "DESEA MODIFICAR EL PRECIO DE VENTA DEL PRODUCTO [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                float precioventa;
                cout << "INGRESE NUEVO PRECIO DE VENTA ";
                cin >> precioventa;
                p.setPrecioVenta(precioventa);
                p.modificarPrecioVenta(idp);
            }
            cout << "DESEA MODIFICAR LAS EXISTENCIAS DEL PRODUCTO [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                int existencia;
                cout << "INGRESE NUEVO VALOR DE EXISTENCIAS ";
                cin >> existencia;
                p.setExistencia(existencia);
                p.modificarExistencia(idp);
            }

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
    cout << "INGRESE EL ID DEL PRODUCTO A ELIMINAR ";
    cin >> idp;
    existe = p.existeProducto(idp);
    if (existe == true) {
        p.buscar(idp);
        cout << "SEGURO QUE QUIERES ELIMINAR ESTE REGISTRO [S/N] ";
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            p.eliminar(idp);
        }
        else {
            cout << "SE HA DETENIDO LA ELIMINACION" << endl;
        }
    }
    else {
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
