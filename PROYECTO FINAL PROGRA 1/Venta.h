#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <mysql.h>
#include <string>
using namespace std;
class Venta
{
private:
	char serie;
	int no_factura,id_cliente,id_empleado;
	string fecha_factura, fecha_ingreso;
public:
	Venta() {
	}
	Venta(int nf, char s, string ff, int idc, int ide, string fi) {
		no_factura = nf;
		serie = s;
		fecha_factura = ff;
		id_cliente = idc;
		id_empleado = ide;
		fecha_ingreso = fi;
	}
	void setNoFactura(int nf) { no_factura = nf; }
	void setSerie(char s) { serie = s; }
	void setFechaFactura(string ff) { fecha_factura = ff; }
	void setIdCliente(int idc) { id_cliente = idc;}
	void setIdEmpleado(int ide) { id_empleado = ide; }
	void setFechaIngreso(string fi) { fecha_ingreso = fi; }

	int getNoFactura() { return no_factura; }
	char getSerie() { return serie; }
	string getFechaFactura() { return fecha_factura; }
	int getidCliente() { return id_cliente; }
	int getIdEmpleado() { return id_empleado; }
	string getFechaIngreso() { return fecha_ingreso; }

	void ingresar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string nf = to_string(no_factura);
		string id_c = to_string(id_cliente);
		string id_e = to_string(id_empleado);
		if (cn.getConectar()) {
			string insertar = "INSERT INTO ventas (nofactura, serie, fechafactura, idCliente, idEmpleado, fechaingreso) VALUES ('"+nf+"', '"+serie+"', now(), '"+id_c+"','"+id_e+"' , now());";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
		}
		cn.cerrar_conexion();
	}
	void mostrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			//CONSULTA POR MEDIO DE NIT: SELECT * from ventas as v inner join clientes as c on v.idCliente=c.idCliente where c.nit= 8991 ;

			//alterar esta consulta para mostrar solo los datos de ventas y usar esta para un voidfactura
			string consulta = "SELECT v.idVenta,v.nofactura,v.serie,v.fechafactura,concat(c.nombres,' ',c.apellidos) cliente,c.nit,concat(e.nombres,' ',e.apellidos) empleado,p.puesto,v.fechaingreso from ventas as v inner join clientes as c on v.idCliente=c.idCliente inner join empleados as e on v.idEmpleado=e.idEmpleado inner join puestos as p on e.idPuesto=p.id_puesto;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id | FACTURA | SERIE | FECHA |CLIENTE | NIT | EMPLEADO | PUESTO | FECHA INGRESO" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << fila[6] << " | " << fila[7] << " | " << fila[8] << endl;
				}
			}
			else {
				cout << "ERROR AL MOSTRAR EL LISTADO";
			}
		}
		else {
			cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
		}
			cn.cerrar_conexion();
	}
	void buscar() {
		int q_estado;
		string n_f = to_string(no_factura);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT v.idVenta, v.nofactura, v.serie, v.fechafactura, concat(c.nombres, ' ', c.apellidos) cliente, c.nit, concat(e.nombres, ' ', e.apellidos) empleado, p.puesto, v.fechaingreso from ventas as v inner join clientes as c on v.idCliente = c.idCliente inner join empleados as e on v.idEmpleado = e.idEmpleado inner join puestos as p on e.idPuesto = p.id_puesto where v.nofactura = " + n_f + " and v.serie = '" + serie + "';";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id | FACTURA | SERIE | FECHA |CLIENTE | NIT | EMPLEADO | PUESTO | FECHA INGRESO" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << fila[6] << " | " << fila[7] << " | " << fila[8] << endl;
				}
			}
			else {
				cout << "ERROR AL BUSCAR LA INFORMACION";
			}
		}
		else {
			cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
		}
			cn.cerrar_conexion();
		
	}
	void modificar(int nof,char s) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string no_f = to_string(nof);
		string sr = to_string(s);
		string n_f = to_string(no_factura);
		string id_c = to_string(id_cliente);
		string id_e = to_string(id_empleado);
		if (cn.getConectar()) {
			string consulta = "UPDATE ventas SET nofactura = '"+n_f+"', serie = '"+serie+"', fechafactura = '"+fecha_factura+"', idCliente = '"+id_c+"', fechaingreso = "+fecha_ingreso+" WHERE (nofactura = " + no_f + " and serie = '" + sr+");";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "actualizacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Actualizar  xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	void eliminar(int nof, char s) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		string no_f = to_string(nof);
		string sr = to_string(s);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "DELETE FROM ventas WHERE nofactura = " + no_f + " and serie = '" + sr + ";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Eliminar  xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}
};


