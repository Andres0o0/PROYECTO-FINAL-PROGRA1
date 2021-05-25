#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <mysql.h>
#include <string>
#include "Pantalla.h"
using namespace std;
class Venta_Detalle
{
private:
	int id_venta, id_producto;
	string cantidad;
	float precio_unitario;
public:
	Venta_Detalle() {
	}
	Venta_Detalle(int idv, int idp, string cant, float pu) {
		id_venta = idv;
		id_producto = idp;
		cantidad = cant;
		precio_unitario = pu;
	}
	void setIdVenta(int idv) { id_venta = idv; }
	void setIdProducto(int idp) { id_producto = idp; }
	void setCantidad(string cant) { cantidad = cant; }
	void setPrecioUnitario(float pu) { precio_unitario = pu; }

	int getIdVenta() { return id_venta; }
	int getIdProducto() { return id_producto; }
	string getCantidad() { return cantidad; }
	float getPrecioUnitario() { return precio_unitario; }
	void ingresar() {
		int q_estado;
		string id_v = to_string(id_venta);
		string id_p = to_string(id_producto);
		string p_u = to_string(precio_unitario);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insertar = "INSERT INTO ventas_detalle (idVenta, idProducto, cantidad, precio_unitario) VALUES ('" + id_v + "', '" + id_p + "', '" + cantidad + "', '" + p_u + "');";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
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

	void buscar() {
		int q_estado;
		float total = 0;
		float precio;
		float cant;
		string dato = "0";
		string dato2 = "0";
		string id_v = to_string(id_venta);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		Pantalla pa = Pantalla();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			int y = 15;
			string consulta = "SELECT vd.idventas_detalle,p.producto,m.marca,p.descripcion,vd.cantidad,vd.precio_unitario FROM ventas_detalle as vd inner join ventas as v on vd.idVenta=v.idVenta inner join productos as p on vd.idProducto=p.idProducto inner join marcas as m on p.idMarca=m.idMarca where vd.idVenta=" + id_v + "  order by vd.idventas_detalle;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				char div = 186;
				resultado = mysql_store_result(cn.getConectar());
				pa.color(128);
				pa.gotoxy(8, y); cout << "ID                                                                                            ";
				pa.gotoxy(11, y); cout << div << " PRODUCTO ";
				pa.gotoxy(31, y); cout <<div<< " MARCA ";
				pa.gotoxy(41, y); cout << div << " DESCRIPCION ";
				pa.gotoxy(71, y); cout << div << " CANTIDAD ";
				pa.gotoxy(85, y); cout << div << "PRECIO UNITARIO";
				y++;
				while (fila = mysql_fetch_row(resultado)) {
					pa.color(240);
					pa.gotoxy(8, y); cout << "                                                                                             ";
					pa.gotoxy(8, y);  cout	<<fila[0];
					pa.gotoxy(11, y); cout << div << " " << fila[1];
					pa.gotoxy(31, y); cout << div << " " << fila[2];
					pa.gotoxy(41, y); cout << div << " " << fila[3];
					pa.gotoxy(71, y); cout << div << " " << fila[4];
					pa.gotoxy(85, y); cout << div << " " <<"Q "<< fila[5];
					dato = fila[5];
					dato2 = fila[4];
					cant = stoi(dato2);
					precio = stoi(dato);
					total = total + (precio*cant);
					y++;
				}
				pa.color(112);
				pa.gotoxy(8, y); cout << "                                                                                             ";
				pa.gotoxy(13, y);
				cout << "TOTAL A PAGAR ES ";
				pa.gotoxy(87, y);cout <<"Q "<< total;
				y++;
				pa.color(240);
				pa.dibujarCuadro(7, 14, 101, y);
				cout << endl;
				pa.color(15);
			}
			else {
				pa.color(15);
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}
		}
		else {
			pa.color(15);
			cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
		}
		cn.cerrar_conexion();
	}

	void buscarEspecifico(int id_vd) {
		int q_estado;
		Pantalla pa = Pantalla();
		string id_ventadetalle = to_string(id_vd);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT vd.idventas_detalle,p.producto,m.marca,p.descripcion,vd.cantidad,vd.precio_unitario FROM ventas_detalle as vd inner join ventas as v on vd.idVenta=v.idVenta inner join productos as p on vd.idProducto=p.idProducto inner join marcas as m on p.idMarca=m.idMarca where vd.idventas_detalle =" + id_ventadetalle + ";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				char div = 186;
				resultado = mysql_store_result(cn.getConectar());
				pa.color(79);
				pa.gotoxy(8, 9); cout << "ID                                                                                            ";
				pa.gotoxy(11, 9); cout << div << " PRODUCTO ";
				pa.gotoxy(31, 9); cout << div << " MARCA ";
				pa.gotoxy(41, 9); cout << div << " DESCRIPCION ";
				pa.gotoxy(71, 9); cout << div << " CANTIDAD ";
				pa.gotoxy(85, 9); cout << div << "PRECIO UNITARIO";
				while (fila = mysql_fetch_row(resultado)) {
					pa.color(64);
					pa.gotoxy(8, 10); cout << "                                                                                             ";
					pa.gotoxy(8, 10);  cout << fila[0];
					pa.gotoxy(11, 10); cout << div << " " << fila[1];
					pa.gotoxy(31, 10); cout << div << " " << fila[2];
					pa.gotoxy(41, 10); cout << div << " " << fila[3];
					pa.gotoxy(71, 10); cout << div << " " << fila[4];
					pa.gotoxy(85, 10); cout << div << " " << "Q " << fila[5];
				}
				
				cout << endl;
				pa.color(15);
			}
			else {
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}
		}
		else {
			cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
		}
		cn.cerrar_conexion();
	}

	void modificar(int idve) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		string id_p = to_string(id_producto);
		string p_u = to_string(precio_unitario);
		string id_ve = to_string(idve);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "UPDATE ventas_detalle SET  `idProducto` = '" + id_p + "', `cantidad` = '" + cantidad + "', `precio_unitario` = '" + p_u + "' WHERE (idventas_detalle=" + id_ve + ");";
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
	void eliminar(int idve) {
		int q_estado;
		string id_ve = to_string(idve);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "DELETE FROM ventas_detalle WHERE idVenta=" + id_ve + ";";
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

	void eliminarEspecifico(int idve) {
		int q_estado;
		string id_ve = to_string(idve);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "DELETE FROM ventas_detalle WHERE idventas_detalle=" + id_ve + ";";
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
	bool existeVD(int idve) {
		int q_estado;
		int f=0;
		string id_ve = to_string(idve);
		string id_v = to_string(id_venta);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT vd.idventas_detalle,v.nofactura,v.serie,v.fechafactura,p.producto,m.marca,p.descripcion,p.imagen,vd.cantidad,vd.precio_unitario FROM ventas_detalle as vd inner join ventas as v on vd.idVenta=v.idVenta inner join productos as p on vd.idProducto=p.idProducto inner join marcas as m on p.idMarca=m.idMarca where  vd.idventas_detalle=" + id_ve + "  and vd.idVenta="+id_v+";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					f++;
				}
			}
			else {
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}
		}
		else {
			cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
		}
		cn.cerrar_conexion();
		if (f == 1) {
			return true;
		}
		else {
			return false;
		}
	}

};

