#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <mysql.h>
#include <string>
#include "Pantalla.h"
using namespace std;
class Puesto
{
private: 
	string puesto;
public:
	Puesto() {
	}
	Puesto(string pu) {
		puesto = pu;
	}
	//METODOS
	void setPuesto(string pu) { puesto = pu; }
	string getPuesto() { return puesto; }

	void ingresar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insertar = "INSERT INTO puestos(puesto) VALUES ('"+puesto+"');";
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
			string consulta = "select * from puestos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				int y1 = 8;
				resultado = mysql_store_result(cn.getConectar());
				Pantalla pa = Pantalla();
				char div = 186;
				pa.color(96);
				pa.dibujarCuadro(37, 1, 77, 3);
				pa.gotoxy(38, 2);
				cout << "ID PUESTO "<<div<<"    NOMBRE DE LOS PUESTOS   " << endl;
				while (fila = mysql_fetch_row(resultado)) {
					pa.color(6);
					pa.gotoxy(39, y1);
					cout << fila[0];
					pa.gotoxy(50,y1);
					cout<<fila[1];
					pa.color(15);
					pa.gotoxy(48, y1);
					cout << div;
					y1++;
				}
				pa.color(15);
				pa.dibujarCuadro(37, 5, 77, y1);
				cout << endl;
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
		void buscar(int idPuesto) {
			int q_estado;
			string idp = to_string(idPuesto);
			ConexionBD cn = ConexionBD();
			MYSQL_ROW fila;
			MYSQL_RES* resultado;
			cn.abrir_conexion();
			if (cn.getConectar()) {
				string consulta = "select * from puestos where id_puesto= "+idp+";";
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getConectar(), c);
				if (!q_estado) {
					resultado = mysql_store_result(cn.getConectar());
					int y1 = 14;
					Pantalla pa = Pantalla();
					char div = 186;
					pa.color(96);
					pa.dibujarCuadro(37, 9, 77, 11);
					pa.gotoxy(38, 10);
					cout << "ID PUESTO " << div << "    NOMBRE DE LOS PUESTOS   ";
					while (fila = mysql_fetch_row(resultado)) {
						pa.color(6);
						pa.gotoxy(39, y1);
						cout << fila[0];
						pa.gotoxy(50, y1);
						cout << fila[1];
						pa.color(15);
						pa.gotoxy(48, y1);
						cout << div;
						y1++;
					}
					pa.color(15);
					pa.dibujarCuadro(37, 13, 77, y1);
					cout << endl;
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
		void modificar(int idPuesto) {
			int q_estado;
			Pantalla pa = Pantalla();
			string idp = to_string(idPuesto);
			ConexionBD cn = ConexionBD();
			cn.abrir_conexion();
			if (cn.getConectar()) {
				string consulta = "UPDATE puestos SET puesto = '"+puesto+"' WHERE (id_puesto = '"+idp+"');";
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getConectar(), c);
				if (!q_estado) {
					pa.color(15);
					pa.gotoxy(39, 3);
					cout << " INGRESO EXISTOSO ";
					}
				else {
					pa.gotoxy(39, 3);
					cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
				}
			}
			else {
				pa.gotoxy(39, 3);
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}
			cn.cerrar_conexion();
		}
		void eliminar(int idPuesto) {
			int q_estado;
			Pantalla pa = Pantalla();
			string idp = to_string(idPuesto);
			ConexionBD cn = ConexionBD();
			cn.abrir_conexion();
			pa.gotoxy(39, 21);
			if (cn.getConectar()) {
				string consulta = "Delete from puestos where (id_puesto = '" + idp + "');";
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getConectar(), c);
				if (!q_estado) {
					cout << "ELIMINACION EXITOSA" << endl;
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

		bool existepuesto(int id_p) {
			int q_estado;
			int f = 0;
			string idp = to_string(id_p);
			ConexionBD cn = ConexionBD();
			MYSQL_ROW fila;
			MYSQL_RES* resultado;
			cn.abrir_conexion();
			if (cn.getConectar()) {
				string consulta = "select * from puestos where (id_puesto = '" + idp + "');";
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

