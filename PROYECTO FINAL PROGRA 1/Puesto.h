#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <mysql.h>
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
				resultado = mysql_store_result(cn.getConectar());
				cout << "id, PUESTOS" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  " << fila[1] << endl;
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

