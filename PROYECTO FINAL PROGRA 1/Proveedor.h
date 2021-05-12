#pragma once
#include "Persona.h"
#include "Persona.h"
#include "ConexionBD.h"
#include <iostream>
#include <mysql.h>
class Proveedor : Persona
{
private:
	string nit, direccion;
public:
	Proveedor() {
	}
	Proveedor(string nom, string n, string dir, int tel) :Persona(nom, NULL ,NULL, tel) {
		nit = n;
		direccion = dir;
	}
	void setNit(string n) { nit = n; }
	void setTelefono(int tel) { telefono = tel; }
	void setNombres(int nom) { nombres = nom; }
	void setDireccion(string dir) { direccion = dir; }

	string getNit() { return nit; }
	string getNombres() { return nombres; }
	int getTelefono() { return telefono; }
	string getDireccion() { return direccion; }

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
			string consulta = "select * from proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id| PROVEEDOR | nit | DIRECCION | TELEFONO" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] <<" | "<< fila[1] << " |" << fila[2] << "|" << fila[3] << "| " << fila[4]  << endl;
				}
			}
			else {
				cout << "ERROR EN LA CONECCION CON LA BASE DE DATOS";
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

