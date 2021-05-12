#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <mysql.h>
using namespace std;
class Producto
{
private:
	string producto, descripcion, imagen, fecha_ingreso;
	int id_marca, existencia;
	float precio_costo, precio_venta;
public:
	Producto() {
	}
	Producto(string pr, int idm, string desc, string img, float pc, float pv, int ex, string fi ) {
		producto = pr;
		id_marca = idm;
		descripcion = desc;
		imagen = img;
		precio_costo = pc;
		precio_venta = pv;
		existencia = ex;
		fecha_ingreso = fi;
	}
	void setProducto(string pr) { producto = pr; }
	void setIdMarca(int idm) { id_marca = idm; }
	void setDescripcion(string desc) { descripcion = desc; }
	void setImagen(string img) { imagen = img; }
	void setPrecioCosto(float pc) { precio_costo = pc; }
	void setPrecioVenta(float pv) { precio_venta = pv; }
	void setExistencia(int ex) { existencia = ex; }
	void setFechaIngreso(string fi) { fecha_ingreso = fi; }

	string getProducto() { return producto; }
	int getIdMarca() { return id_marca; }
	string getDescripcion() { return descripcion; }
	string getImagen() { return imagen; }
	float getPrecioCosto() { return precio_costo; }
	float getPrecioVenta() { return precio_venta; }
	int getExistencia() { return existencia; }
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
			string consulta = "SELECT p.idProducto,m.marca,p.producto,p.descripcion,p.imagen,p.precio_costo,p.precio_venta,p.existencia,p.fecha_ingreso FROM productos as p inner join marcas as m on p.idmarca = m.idmarca; ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id | productos | marca | descripcion | imagen | precio costo | precio venta | existencia | fecha ingreso" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << fila[6] << " | " << fila[7] << " | " << fila[8] << endl;
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

