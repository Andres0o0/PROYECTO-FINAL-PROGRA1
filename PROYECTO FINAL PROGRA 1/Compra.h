#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <mysql.h>
using namespace std;
class Compra
{
private:
	string fecha_orden, fecha_ingreso;
	int no_orden_compra, id_proveedor;
public:
	Compra() {
	}
	Compra(int noc, int idp, string fo, string fi) {
		no_orden_compra = noc;
		id_proveedor = idp;
		fecha_orden = fo;
		fecha_ingreso = fi;
	}
	void setNoOrdenCompra(int noc) { no_orden_compra = noc; }
	void setIdProveedor(int idp) { id_proveedor = idp; }
	void setFechaOrden(string fo) { fecha_orden = fo; }
	void setFechaIngreso(string fi) { fecha_ingreso = fi; }

	int getNoOrdenCompra() { return no_orden_compra; }
	int getIdProveedor() { return id_proveedor; }
	string getFechaOrden() { return fecha_orden; }
	string getFechaIngreso() { return fecha_ingreso; }
	void ingresar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		cn.cerrar_conexion();
	}
	void mostrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			//alterar esta consulta para mostrar solo los datos de ventas y usar esta para un voidfactura
			string consulta = "Select c.idcompra,c.no_orden_compra,p.proveedor,c.fecha_orden,c.fechaingreso from compras as c inner join proveedores as p on c.idproveedor=p.idproveedor;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id | NO ORDEN DE COMPRA | PROVEEDOR | FECHA DE ORDEN |FECHA DE INGRESO" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4]  << endl;
				}
			}
			else {
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}

			cn.cerrar_conexion();
		}
	}
	void buscar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		cn.cerrar_conexion();
	}
	void modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		cn.cerrar_conexion();
	}
	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		cn.cerrar_conexion();
	}
};

