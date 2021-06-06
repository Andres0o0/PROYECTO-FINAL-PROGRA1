#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <mysql.h>
#include <string>
#include "Pantalla.h"
using namespace std;
class Compra_Detalle
{
private:
	int id_compra, id_producto, cantidad;
	float precio_costo_unitario;
public:
	Compra_Detalle() {
	}
	Compra_Detalle(int idc, int idp, int cant, float pcu) {
		id_compra = idc;
		id_producto = idp;
		cantidad = cant;
		precio_costo_unitario = pcu;
	}
	void setIdCompra(int idc) { id_compra = idc; }
	void setIdProducto(int idp) { id_producto = idp; }
	void setCantidad(int cant) { cantidad = cant; }
	void setPrecioCostoUnitario(float pcu) { precio_costo_unitario = pcu; }

	int getIdCompra() { return id_compra; }
	int getIdProducto() { return id_producto; }
	int getCantidad() { return cantidad; }
	float getPrecioCostoUnitario() { return precio_costo_unitario; }

	void ingresar() {
		int q_estado;
		string idc = to_string(id_compra);
		string idp = to_string(id_producto);
		string cant = to_string(cantidad);
		string pcu = to_string(precio_costo_unitario);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "INSERT INTO compras_detalle (idcompra, idproducto, cantidad, precio_costo_unitario) VALUES ('" + idc + "', '" + idp + "', '" + cant + "', '" + pcu + "');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "INGRESO EXITOSO..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;

		}
		cn.cerrar_conexion();
	}
	void mostrar(int idc) {
		int q_estado;
		MYSQL_ROW fila;
		Pantalla pa = Pantalla();
		float total, precio, cant;
		string dato = "0";
		string dato2 = "0";
		char div = 186;
		MYSQL_RES* resultado;
		string idcompra = to_string(idc);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT cd.idcompras_detalle,c.no_orden_compra,p.producto,p.descripcion,cd.cantidad,cd.precio_costo_unitario FROM compras_detalle as cd inner join compras as c on cd.idcompra=c.idcompra inner join productos as p on cd.idproducto=p.idProducto  where cd.idcompra = '" + idcompra + "' ;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				if (!q_estado) {
					resultado = mysql_store_result(cn.getConectar());
					total = 0;
					int y = 15;
					pa.color(128);
					pa.gotoxy(8, y); cout << "ID                                                                                            ";
					pa.gotoxy(11, y); cout << div << "NO ORDEN ";
					pa.gotoxy(21, y); cout << div << " PRODUCTO ";
					pa.gotoxy(41, y); cout << div << " DESCRIPCION ";
					pa.gotoxy(71, y); cout << div << " CANTIDAD ";
					pa.gotoxy(85, y); cout << div << "PRECIO COSTO U";
					y++;
					while (fila = mysql_fetch_row(resultado)) {
						pa.color(240);
						pa.gotoxy(8, y); cout << "                                                                                             ";
						pa.gotoxy(8, y);  cout << fila[0];
						pa.gotoxy(11, y); cout << div << " " << fila[1];
						pa.gotoxy(21, y); cout << div << " " << fila[2];
						pa.gotoxy(41, y); cout << div << " " << fila[3];
						pa.gotoxy(71, y); cout << div << " " << fila[4];
						pa.gotoxy(85, y); cout << div << " " << "Q " << fila[5];
						dato = fila[5];
						dato2 = fila[4];
						cant = stoi(dato2);
						precio = stoi(dato);
						total = total + (precio * cant);
						y++;
					}
					pa.color(112);
					pa.gotoxy(8, y); cout << "                                                                                             ";
					pa.gotoxy(13, y);
					cout << "TOTAL A PAGAR ES ";
					pa.gotoxy(87, y); cout << "Q " << total;
					y++;
					total = 0;
					pa.color(240);
					pa.dibujarCuadro(7, 14, 101, y);
					y++;
					y++;
					pa.color(15);
				}
				else {
					cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
				}
				cn.cerrar_conexion();
			}
		}
	}
	void buscar(int idcd) {
		int q_estado;
		MYSQL_ROW fila;
		Pantalla pa = Pantalla();
		float total, precio,cant;
		string dato = "0";
		string dato2 = "0";
		char div = 186;
		MYSQL_RES* resultado;
		string idcompra_d = to_string(idcd);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT cd.idcompras_detalle,c.no_orden_compra,p.producto,p.descripcion,cd.cantidad,cd.precio_costo_unitario FROM compras_detalle as cd inner join compras as c on cd.idcompra=c.idcompra inner join productos as p on cd.idproducto=p.idProducto  where cd.idcompras_detalle = '" + idcompra_d + "';";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				total = 0;
				int y = 9;
				pa.color(128);
				pa.gotoxy(8, y); cout << "ID                                                                                            ";
				pa.gotoxy(11, y); cout << div << "NO ORDEN ";
				pa.gotoxy(21, y); cout << div << " PRODUCTO ";
				pa.gotoxy(41, y); cout << div << " DESCRIPCION ";
				pa.gotoxy(71, y); cout << div << " CANTIDAD ";
				pa.gotoxy(85, y); cout << div << "PRECIO COSTO U";
				y++;
				while (fila = mysql_fetch_row(resultado)) {
					pa.color(240);
					pa.gotoxy(8, y); cout << "                                                                                             ";
					pa.gotoxy(8, y);  cout << fila[0];
					pa.gotoxy(11, y); cout << div << " " << fila[1];
					pa.gotoxy(21, y); cout << div << " " << fila[2];
					pa.gotoxy(41, y); cout << div << " " << fila[3];
					pa.gotoxy(71, y); cout << div << " " << fila[4];
					pa.gotoxy(85, y); cout << div << " " << "Q " << fila[5];
					
					y++;
				}
				pa.color(15);
			}
			else {
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}
			cn.cerrar_conexion();
		}
	}
	void modificar(int idcd) {
		int q_estado;
		string idcompra_d = to_string(idcd);
		string idc = to_string(id_compra);
		string idp = to_string(id_producto);
		string cant = to_string(cantidad);
		string pcu = to_string(precio_costo_unitario);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "UPDATE compras_detalle SET  idproducto= '" + idp + "', cantidad= '" + cant + "', precio_costo_unitario = '" + pcu + "' where idcompras_detalle = '" + idcompra_d + "'";
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
	void eliminar(int idcd) {
		int q_estado;
		string idc_d = to_string(idcd);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "DELETE FROM compras_detalle WHERE idcompras_detalle = '" + idc_d + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "ELIMINADO EXITOSO..." << endl;
			}
			else {
				cout << " xxx ERROR AL ELIMINAR xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminarTodo(int idcd) {
		int q_estado;
		string idc_d = to_string(idcd);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "DELETE FROM compras_detalle WHERE idcompra = '" + idc_d + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "ELIMINADO EXITOSO..." << endl;
			}
			else {
				cout << " xxx ERROR AL ELIMINAR xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}

	bool ExisteComp_det(int idcd) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		int f = 0;
		string idcompra_d = to_string(idcd);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT cd.idcompras_detalle,c.no_orden_compra,p.producto,p.descripcion,cd.cantidad,cd.precio_costo_unitario FROM compras_detalle as cd inner join compras as c on cd.idcompra=c.idcompra inner join productos as p on cd.idproducto=p.idProducto  where cd.idcompras_detalle = '" + idcompra_d + "';";
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

			cn.cerrar_conexion();
			if (f == 1) {
				return true;
			}
			else {
				return false;
			}
		}
	}
};

