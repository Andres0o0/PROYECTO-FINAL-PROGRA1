#pragma once
#include "Persona.h"
#include "ConexionBD.h"
#include <iostream>
#include <mysql.h>
using namespace std;
class Empleado : Persona
{
private:
	string direccion, dpi, fecha_nacimiento, fecha_inicio_lab, fecha_ingreso;
	int id_puesto;
public:
	Empleado() {
	}
	Empleado(string nom, string ape, string dir, int tel, string DPI, int gen, string fn, int idp, string fil, string fi) :Persona(nom, ape, gen, tel) {
		direccion = dir;
		dpi = DPI;
		fecha_nacimiento = fn;
		id_puesto = idp;
		fecha_inicio_lab = fil;
		fecha_ingreso = fi;
	}
	void setNombreS(string nom) { nombres = nom; }
	void setApellidoS(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setDpi(int DPI) { dpi = DPI; }
	void setGenero(int gen) { genero = gen; }
	void setFechaNacimiento(string fn) { fecha_nacimiento = fn; }
	void setFechaInicioLabores(string fil) { fecha_inicio_lab = fil; }
	void setFechaIngreso(string fi) { fecha_ingreso = fi; }

	string getNombreS() { return nombres; }
	string getApellidoS() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getDpi() { return dpi; }
	int getGenero() {return genero ; }
	string getFechaNacimiento() { return fecha_nacimiento ; }
	string getFechaInicioLabores() { return fecha_inicio_lab ; }
	string getFechaIngreso() { return fecha_ingreso ; }

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
			string consulta = "select e.idEmpleado,e.nombres,e.apellidos,e.direccion,e.telefono,e.DPI,e.genero,e.fecha_nacimento,p.puesto,e.fecha_inicio_labores,e.fechaingreso from empleados as e inner join puestos as p on e.idPuesto = p.id_puesto; ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id | nombres | apellidos | direccion | telefono | dpi | genero | fecha nacimiento | puesto | inicio de labores | fecha de ingreso" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << fila[6] << " | " << fila[7] << " | " << fila[8] << " | " << fila[9] << " | " << fila[10] << endl;
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


