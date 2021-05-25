#pragma once
#include "Persona.h"
#include "ConexionBD.h"
#include <iostream>
#include <mysql.h>
#include <string>
#include "Pantalla.h"
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
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setDpi(int DPI) { dpi = DPI; }
	void setGenero(int gen) { genero = gen; }
	void setFechaNacimiento(string fn) { fecha_nacimiento = fn; }
	void setIdPuesto(int idp) { id_puesto = idp; }
	void setFechaInicioLabores(string fil) { fecha_inicio_lab = fil; }
	void setFechaIngreso(string fi) { fecha_ingreso = fi; }

	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getDpi() { return dpi; }
	int getGenero() {return genero ; }
	string getFechaNacimiento() { return fecha_nacimiento ; }
	int getIdPuesto() { return id_puesto; }
	string getFechaInicioLabores() { return fecha_inicio_lab ; }
	string getFechaIngreso() { return fecha_ingreso ; }

	void ingresar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string t = to_string(telefono);
		string g = to_string(genero);
		string ip = to_string(id_puesto);
		if (cn.getConectar()) {
			string  consulta = "INSERT INTO empleados (nombres, apellidos, direccion, telefono, DPI, genero,fecha_nacimento, idPuesto, fecha_inicio_labores, fechaingreso) VALUES ('"+nombres+"', '"+apellidos+"', '"+direccion+"', '"+t+"', '"+dpi+"', "+g+", '"+fecha_nacimiento+"', '"+ip+"', '"+fecha_inicio_lab+"', now());";
			const char* i = consulta.c_str();
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
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	void mostrar() {
		Pantalla pa = Pantalla();
		int q_estado;
		string g="A";
		int conversion;
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
				int y1 = 6;
				char div = 186;
				pa.color(96);
				pa.gotoxy(1, 2);
				cout << "                                                                                                              ";
				pa.dibujarCuadro(0, 1, 119, 3);
				pa.gotoxy(1, 2);
				cout << "ID  ";
				pa.gotoxy(5, 2);
				cout << div << " NOMBRES";
				pa.gotoxy(19, 2);
				cout << div << " APELLIDOS";
				pa.gotoxy(39, 2);
				cout << div << " DIRECCION";
				pa.gotoxy(65, 2);
				cout << div << " TELEFONO";
				pa.gotoxy(75, 2);
				cout << div << " DPI  ";
				pa.gotoxy(82, 2);
				cout << div << "GEN ";
				pa.gotoxy(87, 2);
				cout << div << " PUESTO ";
				pa.gotoxy(97, 2);
				cout << div << "F. NAC  ";
				pa.gotoxy(108, 2);
				cout << div << "INICIO L  ";
				while (fila = mysql_fetch_row(resultado)) {
					g = fila[6];
					char mf = g[0];
					conversion = mf;
					if (conversion == 1) {
						mf = 'F';
					}
					else {
						mf = 'M';
					}
					pa.color(6);
					pa.gotoxy(1, y1);
					cout << fila[0];
					pa.gotoxy(5, y1);
					cout << div << fila[1];
					pa.gotoxy(19, y1);
					cout << div << fila[2];
					pa.gotoxy(39, y1);
					cout << div << fila[3];
					pa.gotoxy(65, y1);
					cout << div << fila[4];
					pa.gotoxy(75, y1);
					cout << div << fila[5];
					pa.gotoxy(82, y1);
					cout << div << mf;
					pa.gotoxy(87, y1);
					cout << div << fila[8];
					pa.gotoxy(97, y1);
					cout << div << fila[7];
					pa.gotoxy(108, y1);
					cout << div << fila[9];
					y1++;
				}
				pa.dibujarCuadro(0, 5, 119, y1);
				pa.color(15);
				y1++;
				pa.gotoxy(0, y1);
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
	void buscar(int ide) {

		Pantalla pa = Pantalla();
		int q_estado;
			MYSQL_ROW fila;
		MYSQL_RES* resultado;
		int conversion;
		string g = "A";
		string dato = to_string(ide);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select e.idEmpleado,e.nombres,e.apellidos,e.direccion,e.telefono,e.DPI,e.genero,e.fecha_nacimento,p.puesto,e.fecha_inicio_labores,e.fechaingreso from empleados as e inner join puestos as p on e.idPuesto = p.id_puesto where e.idEmpleado ="+dato+" ; ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				int y1 = 6;
				char div = 186;
				pa.color(96);
				pa.gotoxy(1, 2);
				cout << "                                                                                                              ";
				pa.dibujarCuadro(0, 1, 119, 3);
				pa.gotoxy(1, 2);
				cout << "ID  ";
				pa.gotoxy(5, 2);
				cout << div << " NOMBRES";
				pa.gotoxy(19, 2);
				cout << div << " APELLIDOS";
				pa.gotoxy(39, 2);
				cout << div << " DIRECCION";
				pa.gotoxy(65, 2);
				cout << div << " TELEFONO";
				pa.gotoxy(75, 2);
				cout << div << " DPI  ";
				pa.gotoxy(82, 2);
				cout << div << "GEN ";
				pa.gotoxy(87, 2);
				cout << div << " PUESTO ";
				pa.gotoxy(97, 2);
				cout << div << " F. NAC";
				pa.gotoxy(108, 2);
				cout << div << "INICIO L  ";
				while (fila = mysql_fetch_row(resultado)) {
					g = fila[6];
					char mf = g[0];
					conversion = mf;
					if (conversion == 1) {
						mf = 'F';
					}
					else {
						mf = 'M';
					}
					pa.color(6);
					pa.gotoxy(1, y1);
					cout <<fila[0];
					pa.gotoxy(5, y1);
					cout << div <<fila[1];
					pa.gotoxy(19, y1);
					cout << div <<fila[2];
					pa.gotoxy(39, y1);
					cout << div <<fila[3];
					pa.gotoxy(65, y1);
					cout << div <<fila[4];
					pa.gotoxy(75, y1);
					cout << div <<fila[5];
					pa.gotoxy(82, y1);
					cout << div <<mf;
					pa.gotoxy(87, y1);
					cout << div <<fila[8];
					pa.gotoxy(97, y1);
					cout << div <<fila[7];
					pa.gotoxy(108, y1);
					cout << div <<fila[9];
					y1++;
				}
				pa.dibujarCuadro(0, 5, 119, y1);
				pa.color(15);
				y1++;
				pa.gotoxy(0, y1);
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
	void modificar(int idEmpleado) {
		int q_estado;
		string ide = to_string(idEmpleado);
		string t = to_string(telefono);
		string g = to_string(genero);
		string ip = to_string(id_puesto);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  consultar = "UPDATE empleados SET nombres = '"+nombres+"', apellidos = '"+apellidos+"', direccion = '"+direccion+"', telefono = '"+t+"', DPI = '"+dpi+"', genero = "+g+", fecha_nacimento = '"+fecha_nacimiento+"', idPuesto = '"+ip+"', fecha_inicio_labores = '"+fecha_inicio_lab+"', fechaingreso = now() WHERE (idEmpleado = '"+ide+"');";
			const char* i = consultar.c_str();
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
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	void eliminar(int idEmpleado) {
		int q_estado;
		string ide = to_string(idEmpleado);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  consultar = "DELETE FROM empleados WHERE idEmpleado=" + ide + ";";
			const char* i = consultar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Eliminar xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}

	bool existeEmpleado(int ide) {
		int q_estado;
		int f = 0;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string dato = to_string(ide);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select e.idEmpleado,e.nombres,e.apellidos,e.direccion,e.telefono,e.DPI,e.genero,e.fecha_nacimento,p.puesto,e.fecha_inicio_labores,e.fechaingreso from empleados as e inner join puestos as p on e.idPuesto = p.id_puesto where e.idEmpleado =" + dato + " ; ";
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

	void asignardatos(int idEmpleado) {
		int q_estado;
		string error = "ERROR";
		string id = to_string(idEmpleado);
		string t;
		string g;
		string idp;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT * FROM empleados where idEmpleado="+id+";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					nombres = fila[1];
					apellidos = fila[2];
					direccion = fila[3];
					

				}
			}
			else {
				cout << "ERROR DE CONEXION" << endl;
			}

		}
		else {
			cout << "ERROR DE CONEXION" << endl;
		}
		cn.cerrar_conexion();
	}
};


