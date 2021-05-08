#pragma once
#include "Persona.h"
#include "ConexionBD.h"
#include <iostream>
#include <mysql.h>
using namespace std;
class Cliente : Persona
{
	//atributos
private: string nit,fecha_ingreso;
	   //constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, int gen, int tel, string n,string fi) :Persona(nom, ape, gen, tel) {
		nit = n;
		fecha_ingreso = fi;
	}
	//METODOS
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setApellidos(string ape) { apellidos = ape; }

	void setGenero(int gen) { genero = gen; }

	void setTelefono(int tel) { telefono = tel; }
	void setNombre(int nom) { nombres = nom; }
	void setFechaingreso(string fi) { fecha_ingreso = fi; }

	//get (mostrar)

	string getNit() { return nit; }

	string getNombres() { return nombres; }

	string getApellidos() { return apellidos; }

	int getGenero() { return genero; }

	int getTelefono() { return telefono; }
	
	string getFechaingreso() { return fecha_ingreso; }


	//metodo
	void mostrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id, nombres ,apellidos, nit, genero, telefono,correo electronico,fecha ingreso" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << fila[1] << " |" << fila[2] << "\t|" << fila[3] << "\t| "<<fila[4] << " \t|" << fila[5] << "\t|" << fila[6] << "|" << fila[7] << endl;
				}
			}
			else {
				cout << "ERROR EN LA CONECCION CON LA BASE DE DATOS";
			}
			cn.cerrar_conexion();
		}
	}
};
