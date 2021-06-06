#pragma once
#include "Persona.h"
#include "Persona.h"
#include "ConexionBD.h"
#include <iostream>
#include <mysql.h>
#include <string>
#include "Pantalla.h"
class Proveedor
{
private:
	string proveedor, nit, direccion;
	int telefono;
public:
	Proveedor() {
	}
	Proveedor(string prov, string n, string dir, int tel) {
		proveedor = prov;
		nit = n;
		direccion = dir;
		telefono = tel;
	}
	void setNit(string n) { nit = n; }
	void setTelefono(int tel) { telefono = tel; }
	void setNombres(string prov) { proveedor = prov; }
	void setDireccion(string dir) { direccion = dir; }

	string getNit() { return nit; }
	string getProveedor() { return proveedor; }
	int getTelefono() { return telefono; }
	string getDireccion() { return direccion; }

	void ingresar() {
		int q_estado;
		string tel = to_string(telefono);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insertar = "INSERT INTO proveedores(proveedor, nit, direccion, telefono) VALUES ('" + proveedor + "', '" + nit + "', '" + direccion + "', '" + tel + "');";
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
		Pantalla pa = Pantalla();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				int y = 6;
				char div = 186;
				pa.color(96);
				resultado = mysql_store_result(cn.getConectar());
				pa.gotoxy(28, 2); cout << "ID                                                            ";
				pa.gotoxy(31, 2); cout << div << " PROVEEDOR ";
				pa.gotoxy(51, 2); cout << div << " NIT ";
				pa.gotoxy(61, 2); cout << div << " DIRECCION ";
				pa.gotoxy(81, 2); cout << div << " TELEFONO  ";

				pa.dibujarCuadro(27, 1, 93, 3);

				while (fila = mysql_fetch_row(resultado)) {
					pa.color(6);
					pa.gotoxy(28, y);  cout << fila[0];
					pa.gotoxy(31, y); cout << div << " " << fila[1];
					pa.gotoxy(51, y); cout << div << " " << fila[2];
					pa.gotoxy(61, y); cout << div << " " << fila[3];
					pa.gotoxy(81, y); cout << div << " " << fila[4];
					y++;
				}
				pa.dibujarCuadro(27, 5, 93, y);
				cout << endl;
				pa.color(15);
				y++;
				pa.gotoxy(27, y);
			}
			else {
				cout << "ERROR EN LA CONECCION CON LA BASE DE DATOS";
			}
			cn.cerrar_conexion();
		}
	}
	void buscar(int idp) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		Pantalla pa = Pantalla();
		string idpro = to_string(idp);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from proveedores where idproveedor = '" + idpro + "' ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				int y = 6;
				char div = 186;
				pa.color(96);
				resultado = mysql_store_result(cn.getConectar());
				pa.gotoxy(28, 2); cout << "ID                                                            ";
				pa.gotoxy(31, 2); cout << div << " PROVEEDOR ";
				pa.gotoxy(51, 2); cout << div << " NIT ";
				pa.gotoxy(61, 2); cout << div << " DIRECCION ";
				pa.gotoxy(81, 2); cout << div << " TELEFONO  ";

				pa.dibujarCuadro(27, 1, 93, 3);

				while (fila = mysql_fetch_row(resultado)) {
					pa.color(6);
					pa.gotoxy(28, y);  cout << fila[0];
					pa.gotoxy(31, y); cout << div << " " << fila[1];
					pa.gotoxy(51, y); cout << div << " " << fila[2];
					pa.gotoxy(61, y); cout << div << " " << fila[3];
					pa.gotoxy(81, y); cout << div << " " << fila[4];
					y++;
				}
				pa.dibujarCuadro(27, 5, 93, y);
				cout << endl;
				pa.color(15);
				y++;
				pa.gotoxy(27, y);
			}
			else {
				cout << "ERROR EN LA CONECCION CON LA BASE DE DATOS";
			}
			cn.cerrar_conexion();
		}
	}


	void modificarTelefono(int idp) {
		int q_estado;
		string idpr = to_string(idp);
		string tel = to_string(telefono);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "UPDATE proveedores SET  telefono = '" + tel + "' WHERE (idproveedor = '" + idpr + "');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "INGRESO EXITOSO" << endl;
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

	void modificarProveedor(int idp) {
		int q_estado;
		string idpr = to_string(idp);
		string tel = to_string(telefono);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "UPDATE proveedores SET proveedor= '" + proveedor + "' WHERE (idproveedor = '" + idpr + "');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "INGRESO EXITOSO" << endl;
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

	void modificarNit(int idp) {
		int q_estado;
		string idpr = to_string(idp);
		string tel = to_string(telefono);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "UPDATE proveedores SET nit = '" + nit + "' WHERE (idproveedor = '" + idpr + "');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "INGRESO EXITOSO" << endl;
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

	void modificarDireccion(int idp) {
		int q_estado;
		string idpr = to_string(idp);
		string tel = to_string(telefono);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "UPDATE proveedores SET  direccion = '" + direccion + "' WHERE (idproveedor = '" + idpr + "');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "INGRESO EXITOSO" << endl;
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

	void eliminar(int idp) {
		int q_estado;
		string idpr = to_string(idp);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "Delete from proveedores where (idproveedor = '" + idpr + "');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "ELIMINACION EXITOSA" << endl;
			}
			else {
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}
		}

		cn.cerrar_conexion();
	}


	bool existeproveedor(int idp) {
		int q_estado;
		int f = 0;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string idpro = to_string(idp);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from proveedores where idproveedor = '" + idpro + "' ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					f++;
					
				}
			}
			else {
				cout << "ERROR EN LA CONEXION CON LA BASE DE DATOS";
			}
		}
		
		if (f == 1) {
			return true;
			proveedor = fila[1];
		}
		else {
			return false;
		}
		cn.cerrar_conexion();
	}

	bool existeNit(int idp) {
		int q_estado;
		int f = 0;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string idpro = to_string(idp);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from proveedores where nit = '" + idpro + "' ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					f++;
				}
			}
			else {
				cout << "ERROR EN LA CONECCION CON LA BASE DE DATOS";
			}
			cn.cerrar_conexion();
		}
		if (f == 1) {
			return true;
		}
		else {
			return false;
		}
	}
};