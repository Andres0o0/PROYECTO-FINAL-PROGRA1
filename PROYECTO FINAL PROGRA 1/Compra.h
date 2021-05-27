#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <mysql.h>
#include <string>
#include "Pantalla.h"
#include <fstream>
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
		string no_orden = to_string(no_orden_compra);
		string idp = to_string(id_proveedor);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "INSERT INTO compras (no_orden_compra, idproveedor, fecha_orden, fechaingreso) VALUES ('" + no_orden + "', '" + idp + "', '" + fecha_orden + "', now());";
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
	void mostrar() {
		Pantalla pa = Pantalla();
		int q_estado;
		int q_estado2;
		string id_c;
		float cant, precio, total = 0;
		string dato = "0";
		string dato2 = "0";
		char div = 186;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		MYSQL_ROW fila2;
		MYSQL_RES* resultado2;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			int y = 5;
			int y1;
			//alterar esta consulta para mostrar solo los datos de ventas y usar esta para un voidfactura
			string consulta = "Select c.idcompra,c.no_orden_compra,p.proveedor,c.fecha_orden,c.fechaingreso from compras as c inner join proveedores as p on c.idproveedor=p.idproveedor;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					pa.color(240);
					//pa.dibujarCuadro(19, 1, 91, 6);
					y1 = y - 1;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					pa.gotoxy(70, y);
					cout << "NO ORDEN DE COMPRA:";
					pa.gotoxy(20, y);
					cout << "ID";
					pa.color(248);
					pa.gotoxy(24, y);
					cout << fila[0];
					pa.gotoxy(90, y);
					cout << fila[1];
					y++;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					pa.color(240);
					pa.gotoxy(20, y);
					cout << "FECHA:";
					pa.color(248);
					pa.gotoxy(30, y);
					cout << fila[3];
					y++;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					pa.color(240);
					pa.gotoxy(20, y);
					cout << "                   PROVEEDOR:                                         ";
					pa.color(248);
					pa.gotoxy(50, y);
					cout << fila[2];
					y++;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					pa.color(240);
					pa.gotoxy(20, y);
					cout << "FECHA INGRESO:";
		     		pa.color(248);
					pa.gotoxy(35, y);
					cout << fila[4];
					y++;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					y++;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					id_c = fila[0];
					string consulta2 = "SELECT cd.idcompras_detalle,c.no_orden_compra,p.producto,p.descripcion,cd.cantidad,cd.precio_costo_unitario FROM compras_detalle as cd inner join compras as c on cd.idcompra=c.idcompra inner join productos as p on cd.idproducto=p.idProducto where c.idcompra=" + id_c + " ;";
					const char* c2 = consulta2.c_str();
					q_estado2 = mysql_query(cn.getConectar(), c2);
					if (!q_estado2) {
						total = 0;
						resultado2 = mysql_store_result(cn.getConectar());
						pa.color(128);
						pa.gotoxy(8, y); cout << "ID                                                                                            ";
						pa.gotoxy(11, y); cout << div << "NO ORDEN ";
						pa.gotoxy(21, y); cout << div << " PRODUCTO ";
						pa.gotoxy(41, y); cout << div << " DESCRIPCION ";
						pa.gotoxy(71, y); cout << div << " CANTIDAD ";
						pa.gotoxy(85, y); cout << div << "PRECIO COSTO U";
						y++;
						while (fila2 = mysql_fetch_row(resultado2)) {
							pa.color(240);
							pa.gotoxy(8, y); cout << "                                                                                             ";
							pa.gotoxy(8, y);  cout << fila2[0];
							pa.gotoxy(11, y); cout << div << " " << fila2[1];
							pa.gotoxy(21, y); cout << div << " " << fila2[2];
							pa.gotoxy(41, y); cout << div << " " << fila2[3];
							pa.gotoxy(71, y); cout << div << " " << fila2[4];
							pa.gotoxy(85, y); cout << div << " " << "Q " << fila2[5];
							dato = fila2[5];
							dato2 = fila2[4];
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
						pa.dibujarCuadro(7, y1, 101, y);
						y++;
						y++;
						pa.color(15);
					}

				}
			}
			else {
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}

			cn.cerrar_conexion();
		}
	}
	void buscar(int idc) {
		Pantalla pa = Pantalla();
		int q_estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		ConexionBD cn = ConexionBD();
		string idco = to_string(idc);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			//alterar esta consulta para mostrar solo los datos de ventas y usar esta para un voidfactura
			string consulta = "Select c.idcompra,c.no_orden_compra,p.proveedor,c.fecha_orden,c.fechaingreso from compras as c inner join proveedores as p on c.idproveedor=p.idproveedor where c.idcompra = " + idco + ";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					pa.color(240);
					//pa.dibujarCuadro(19, 1, 91, 6);
					int y = 2;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					pa.gotoxy(70, y);
					cout << "NO ORDEN DE COMPRA:";
					pa.gotoxy(20, y);
					cout << "ID";
					pa.color(248);
					pa.gotoxy(24, y);
					cout << fila[0];
					pa.gotoxy(90, y);
					cout << fila[1];
					y++;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					pa.color(240);
					pa.gotoxy(20, y);
					cout << "FECHA:";
					pa.color(248);
					pa.gotoxy(30, y);
					cout << fila[3];
					y++;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					pa.color(240);
					pa.gotoxy(20, y);
					cout << "                   PROVEEDOR:                                         ";
					pa.color(248);
					pa.gotoxy(50, y);
					cout << fila[2];
					y++;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					pa.color(240);
					pa.gotoxy(37, y);
					cout << "FECHA INGRESO:";
					pa.color(248);
					pa.gotoxy(52, y);
					cout << fila[4];
					y++;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					y++;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					pa.dibujarCuadro(7, 1, 101, y);
					pa.color(15);
				}
			}
			else {
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}

			cn.cerrar_conexion();
		}
	}

	string retIdCompra(int idc) {
		int q_estado;
		MYSQL_ROW fila;
		int f = 0;
		MYSQL_RES* resultado;
		string error = "ERROR";
		ConexionBD cn = ConexionBD();
		string idco = to_string(idc);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			//alterar esta consulta para mostrar solo los datos de ventas y usar esta para un voidfactura
			string consulta = "SELECT idcompra FROM compras where no_orden_compra="+idco+" ;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					return fila[0];
				}
			}
			else {
				return error;
			}

			cn.cerrar_conexion();
		}
		else {
			return error;
		}
	}

	void modificar(int idc) {
		int q_estado;
		string no_orden = to_string(no_orden_compra);
		string idp = to_string(id_proveedor);
		string idco = to_string(idc);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "UPDATE compras SET  idproveedor = '" + idp + "', fecha_orden = '" + fecha_orden + "', fechaingreso = now() where idcompra = '" + idco + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "ACTUALIZACION EXITOSA ..." << endl;
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

	void eliminar(int idc) {
		int q_estado;
		string idco = to_string(idc);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "DELETE FROM compras WHERE idcompra = '" + idco + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "Eliminado ..." << endl;
			}
			else {
				cout << " xxx Error al eliminar  xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}

	bool ExisteCompra(int idc) {
		int q_estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		int f = 0;
		ConexionBD cn = ConexionBD();
		string idco = to_string(idc);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			//alterar esta consulta para mostrar solo los datos de ventas y usar esta para un voidfactura
			string consulta = "Select c.idcompra,c.no_orden_compra,p.proveedor,c.fecha_orden,c.fechaingreso from compras as c inner join proveedores as p on c.idproveedor=p.idproveedor where c.no_orden_compra = " + idco + ";";
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

	void nocompra() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		string n_o;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT no_orden_compra from compras ORDER BY idcompra DESC LIMIT 1";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					n_o = fila[0];
					int x = stoi(n_o);
					no_orden_compra = x + 1;
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

	string idcompra() {
		int q_estado;
		string error = "ERROR";
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT idcompra from compras ORDER BY idcompra DESC LIMIT 1";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					return fila[0];
				}
			}
			else {
				return error;

			}
		}
		else {
			return error;
		}
		cn.cerrar_conexion();


	}
	
	void imprimirFactura(int idc) {
		
		int q_estado;
		int q_estado2;
		string id_c;
		float cant, precio, total = 0;
		string dato = "0";
		string dato2 = "0";
		char div = 186;
		string idco = to_string(idc);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		MYSQL_ROW fila2;
		MYSQL_RES* resultado2;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			int y = 5;
			int y1;
			//alterar esta consulta para mostrar solo los datos de ventas y usar esta para un voidfactura
			string consulta = "Select c.idcompra,c.no_orden_compra,p.proveedor,c.fecha_orden,c.fechaingreso from compras as c inner join proveedores as p on c.idproveedor=p.idproveedor where c.idcompra = " + idco + ";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				ofstream fout("facturac.txt");
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					fout << "ID " << fila[0] << "       NO ORDEN: " << fila[1]<<endl;
					fout << "PROVEEDOR: " << fila[2]<<endl;
					fout << "FECHA  ORDEN: " << fila[3] << endl;
					fout << "FECHA INGRESO " << fila[4] << endl<<endl;
					id_c = fila[0];
					string consulta2 = "SELECT cd.idcompras_detalle,p.producto,m.marca,p.descripcion,cd.cantidad,cd.precio_costo_unitario FROM compras_detalle as cd inner join compras as c on cd.idcompra=c.idcompra inner join productos as p on cd.idproducto=p.idProducto inner join marcas as m on p.idmarca=m.idmarca where c.idcompra=" + id_c + " ;";
					const char* c2 = consulta2.c_str();
					q_estado2 = mysql_query(cn.getConectar(), c2);
					if (!q_estado2) {
						total = 0;
						resultado2 = mysql_store_result(cn.getConectar());
						fout << "ID   \t" << "|           PRODUCTOS          "<<endl;
						while (fila2 = mysql_fetch_row(resultado2)) {
							fout << fila2[0] << "      \t|" << fila2[4] << "   " << fila2[1] << "       \t  MARCA    " << fila2[2] << "     Q. " << fila2[5] << " c/u" << endl;
							fout << "      \t|" << fila2[3] << endl;
							dato = fila2[5];
							dato2 = fila2[4];
							cant = stoi(dato2);
							precio = stoi(dato);
							total = total + (precio * cant);
						}
						
						fout <<"\n  TOTAL A PAGAR ES   Q  " << total;
					}

				}
			}
			else {
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}

			cn.cerrar_conexion();
		}
	}
};