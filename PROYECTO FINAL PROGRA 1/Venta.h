#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <mysql.h>
#include <string>
#include "Pantalla.h"
#include <fstream>

using namespace std;
class Venta
{
private:
	char serie;
	int no_factura,id_empleado;
	string fecha_factura, fecha_ingreso, id_cliente;
public:
	Venta() {
	}
	Venta(int nf, char s, string ff, string idc, int ide, string fi) {
		no_factura = nf;
		serie = s;
		fecha_factura = ff;
		id_cliente = idc;
		id_empleado = ide;
		fecha_ingreso = fi;
	}
	void setNoFactura(int nf) { no_factura = nf; }
	void setSerie(char s) { serie = s; }
	void setFechaFactura(string ff) { fecha_factura = ff; }
	void setIdCliente(string idc) { id_cliente = idc;}
	void setIdEmpleado(int ide) { id_empleado = ide; }
	void setFechaIngreso(string fi) { fecha_ingreso = fi; }

	int getNoFactura() { return no_factura; }
	char getSerie() { return serie; }
	string getFechaFactura() { return fecha_factura; }
	string getidCliente() { return id_cliente; }
	int getIdEmpleado() { return id_empleado; }
	string getFechaIngreso() { return fecha_ingreso; }

	void ingresar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string nf = to_string(no_factura);
		string id_e = to_string(id_empleado);
		if (cn.getConectar()) {
			string insertar = "INSERT INTO ventas (nofactura, serie, fechafactura, idCliente, idEmpleado, fechaingreso) VALUES ('"+nf+"', '"+serie+"', now(), "+id_cliente+",'"+id_e+"' , now());";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "\t\t\t\t\tIngreso Exitoso ..." << endl;
			}
			else {
				cout << "\t\t\t\t\txxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << "\t\t\t\t\tERROR AL CONECTAR CON LA BASE DE DATOS";
		}
		cn.cerrar_conexion();
	}
	void mostrar() {
		Pantalla pa = Pantalla();
		int q_estado;
		int q_estado2;
		string id_v;
		float cant, precio, total=0;
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
			string consulta = "SELECT v.idVenta,v.nofactura,v.serie,v.fechafactura,concat(c.nombres,' ',c.apellidos) cliente,c.nit,concat(e.nombres,' ',e.apellidos) empleado,p.puesto,v.fechaingreso from ventas as v inner join clientes as c on v.idCliente=c.idCliente inner join empleados as e on v.idEmpleado=e.idEmpleado inner join puestos as p on e.idPuesto=p.id_puesto order by v.idVenta;";
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
					cout << "FACTURA NO:";
					pa.gotoxy(20, y);
					cout << "ID";
					pa.color(248);
					pa.gotoxy(24, y);
					cout << fila[0];
					pa.gotoxy(84, y);
					cout << fila[1];
					y++;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					pa.color(240);
					pa.gotoxy(70, y);
					cout << "SERIE: ";
					pa.gotoxy(20, y);
					cout << "FECHA:";
					pa.color(248);
					pa.gotoxy(84, y);
					cout << fila[2];
					pa.gotoxy(30, y);
					cout << fila[3];
					y++;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					pa.color(240);
					pa.gotoxy(20, y);
					cout << "                      ATIENDE:                                         ";
					pa.color(248);
					pa.gotoxy(50, y);
					cout << fila[6] << " - " << fila[7];
					y++;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					pa.color(240);
					pa.gotoxy(20, y);
					cout << "CLIENTE:";
					pa.gotoxy(70, y);
					cout << "NIT: ";
					pa.color(248);
					pa.gotoxy(30, y);
					cout << fila[4];
					pa.gotoxy(84, y);
					cout << fila[5];
					y++;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					y++;
					pa.gotoxy(7, y);
					cout << "                                                                                              ";
					id_v = fila[0];
					string consulta2 = "SELECT vd.idventas_detalle,p.producto,m.marca,p.descripcion,vd.cantidad,vd.precio_unitario FROM ventas_detalle as vd inner join ventas as v on vd.idVenta=v.idVenta inner join productos as p on vd.idProducto=p.idProducto inner join marcas as m on p.idMarca=m.idMarca where vd.idVenta=" + id_v + " order by vd.idVenta ;";
					const char* c2 = consulta2.c_str();
					q_estado2 = mysql_query(cn.getConectar(), c2);
					if (!q_estado2) {
						total = 0;
						resultado2 = mysql_store_result(cn.getConectar());
						pa.color(128);
						pa.gotoxy(8, y); cout << "ID                                                                                            ";
						pa.gotoxy(11, y); cout << div << " PRODUCTO ";
						pa.gotoxy(31, y); cout << div << " MARCA ";
						pa.gotoxy(41, y); cout << div << " DESCRIPCION ";
						pa.gotoxy(71, y); cout << div << " CANTIDAD ";
						pa.gotoxy(85, y); cout << div << "PRECIO UNITARIO";
						y++;
						while (fila2 = mysql_fetch_row(resultado2)) {
							pa.color(240);
							pa.gotoxy(8, y); cout << "                                                                                             ";
							pa.gotoxy(8, y);  cout << fila2[0];
							pa.gotoxy(11, y); cout << div << " " << fila2[1];
							pa.gotoxy(31, y); cout << div << " " << fila2[2];
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
					}

				}
			}
			else {
				cout << "ERROR AL MOSTRAR EL LISTADO";
			}
		}
		else {
			cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
		}
			cn.cerrar_conexion();
	}
	void buscar() {
		int q_estado;
		string n_f = to_string(no_factura);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		Pantalla pa = Pantalla();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT v.idVenta, v.nofactura, v.serie, v.fechafactura, concat(c.nombres, ' ', c.apellidos) cliente, c.nit, concat(e.nombres, ' ', e.apellidos) empleado, p.puesto, v.fechaingreso from ventas as v inner join clientes as c on v.idCliente = c.idCliente inner join empleados as e on v.idEmpleado = e.idEmpleado inner join puestos as p on e.idPuesto = p.id_puesto where v.nofactura = " + n_f + " and v.serie = '" + serie + "';";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				system("cls");
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					pa.color(240);
					pa.dibujarCuadro(19, 1, 91, 6);
					pa.gotoxy(70, 2);
					cout << "FACTURA NO:          ";
					pa.gotoxy(70, 3);
					cout << "SERIE:               ";
					pa.gotoxy(20, 2);
					cout << "ID                                                ";
					pa.gotoxy(20, 3);
					cout << "FECHA:                                            ";
					pa.gotoxy(20,4);
					cout << "                      ATIENDE:                                         ";
					pa.gotoxy(20, 5);
					cout << "CLIENTE:                                          ";
					pa.gotoxy(70, 5);
					cout << "NIT:                 ";
					pa.color(248);
					pa.gotoxy(84, 2);
					cout << fila[1];
					pa.gotoxy(84, 3);
					cout << fila[2];
					pa.gotoxy(24, 2);
					cout << fila[0];
					pa.gotoxy(30, 3);
					cout << fila[3];
					pa.gotoxy(50, 4);
					cout <<fila[6] << " - " << fila[7];
					pa.gotoxy(30, 5);
					cout << fila[4];
					pa.gotoxy(84, 5);
					cout << fila[5];
					cout << endl << endl;
					
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

	void modificarNoFactura(string idv) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string n_f = to_string(no_factura);
		if (cn.getConectar()) {
			string consulta = "UPDATE ventas SET nofactura = '" + n_f + "' WHERE (idVenta='" + idv + "');";
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
	void modificarSerie(string idv) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string sr = to_string(serie);
		if (cn.getConectar()) {
			string consulta = "UPDATE ventas SET  serie = '" + sr + "'  WHERE (idVenta='" + idv + "');";
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
	void modificarFechaFactura(string idv) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "UPDATE ventas SET  fechafactura = " + fecha_factura + " WHERE (idVenta='" + idv + "');";
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
	void modificarIdCliente(string idv) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "UPDATE ventas SET idCliente = '"+id_cliente+"' WHERE (idVenta = '"+idv+"');";
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
	void modificarIdEmpleado(string idv) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string id_e = to_string(id_empleado);
		if (cn.getConectar()) {
			string consulta = "UPDATE ventas SET idEmpleado = '" + id_e + "' WHERE (idVenta='" + idv + "');";
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


	void eliminar(string idv) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "DELETE FROM ventas WHERE idVenta="+idv+";";
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
	bool existeVenta() {
		int q_estado;
		string n_f = to_string(no_factura);
		ConexionBD cn = ConexionBD();
		int f = 0;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT v.idVenta, v.nofactura, v.serie, v.fechafactura, concat(c.nombres, ' ', c.apellidos) cliente, c.nit, concat(e.nombres, ' ', e.apellidos) empleado, p.puesto, v.fechaingreso from ventas as v inner join clientes as c on v.idCliente = c.idCliente inner join empleados as e on v.idEmpleado = e.idEmpleado inner join puestos as p on e.idPuesto = p.id_puesto where v.nofactura = " + n_f + " and v.serie = '" + serie + "';";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				
				while (fila = mysql_fetch_row(resultado)) {
					f++;
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
		if (f == 1) {
			return true;
		}
		else {
			return false;
		}

	}

	string asignardatos() {
		int q_estado;
		string error = "ERROR";
		string n_f = to_string(no_factura);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select idVenta from ventas where nofactura=" + n_f + " and serie = '" + serie + "';";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					return fila[0];
					fecha_factura = fila[1];
					id_cliente = fila[2];
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

	string obteneridemp() {
		int q_estado;
		string error = "ERROR";
		string n_f = to_string(no_factura);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select idEmpleado from ventas where nofactura=" + n_f + " and serie = '" + serie + "';";
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

	void setfactura() {
		int q_estado;
		string n_f;
		string ser;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT nofactura, serie  from ventas ORDER BY idVenta DESC LIMIT 1";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					n_f = fila[0];
					ser = fila[1];
					int x = stoi(n_f);
					no_factura = x + 1;
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

	
	void imprimirFactura(string id_v) {
		int q_estado;
		int q_estado2;
		string n_f = to_string(no_factura);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		MYSQL_ROW fila2;
		MYSQL_RES* resultado2;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT v.idVenta, v.nofactura, v.serie, v.fechafactura, concat(c.nombres, ' ', c.apellidos) cliente, c.nit, concat(e.nombres, ' ', e.apellidos) empleado, p.puesto, v.fechaingreso from ventas as v inner join clientes as c on v.idCliente = c.idCliente inner join empleados as e on v.idEmpleado = e.idEmpleado inner join puestos as p on e.idPuesto = p.id_puesto where v.idVenta=" + id_v + ";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				ofstream fout("factura.txt");
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					fout << "   ID "<<fila[0]<< "      FACTURA NO: " << fila[1] << "   SERIE: " << fila[2]<<"    FECHA: "<<fila[3]<<endl;
					fout << "   CIENTE:  " << fila[4] << "                          NIT: " << fila[5] << endl;
					fout << "   ATIENDE: " << fila[6] << " [ " << fila[7] << " ]" << endl<<endl;

					string id_v = fila[0];
					string consulta2 = "SELECT vd.idventas_detalle,p.producto,m.marca,p.descripcion,vd.cantidad,vd.precio_unitario FROM ventas_detalle as vd inner join ventas as v on vd.idVenta=v.idVenta inner join productos as p on vd.idProducto=p.idProducto inner join marcas as m on p.idMarca=m.idMarca where vd.idVenta=" + id_v + " order by vd.idVenta ;";
					const char* c2 = consulta2.c_str();
					q_estado2 = mysql_query(cn.getConectar(), c2);
					if (!q_estado2) {
						resultado2 = mysql_store_result(cn.getConectar());
						fout << "   [ID]                      --PRODUCTOS--     " << endl;
						string dato, dato2;
						float cant, precio, total = 0;
						while (fila2 = mysql_fetch_row(resultado2)) {
							fout <<"   "<< fila2[0] << "    | " << fila2[4] << "  " << fila2[1] << " \tMARCA  " << fila2[2] << " C/U Q " << fila2[5] << endl;
							fout << "          " << fila2[3] << endl;
							dato = fila2[5];
							dato2 = fila2[4];
							cant = stoi(dato2);
							precio = stoi(dato);
							total = total + (precio * cant);
						}
						fout << endl << "                              TOTAL Q.  " << total;
					}

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
};


