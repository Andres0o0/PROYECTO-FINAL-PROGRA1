#include<iostream>
#include<string>
#include<stdlib.h>
#include"SerialPort.h"

using namespace std;

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];

char commport[] = "\\\\.\\COM4";
char* port = commport;
SerialPort arduino(port);
void cinta_transportadora();
void apagar_cinta();
void caja_registradora();
void apagar();
void salir();
int main() {
	if (arduino.isConnected()) {
		int op;
		do {
			cout << "\n\n\n\n\n\n\n\n\n\n                                                Conexion Exitosa" << endl << endl;
			cout << "                                            ----------Opciones---------" << endl;
			cout << "                                          (1) Encender Cinta trasnportadora." << endl;
			cout << "                                          (2) apagar cinta transportadora." << endl;
			cout << "                                          (3) Abrir caja registradora." << endl;
			cout << "                                          (4) Cerrar caja registradora." << endl;
			cout << "                                          (5) SALIR";
			cout << "  \n                                        Ingrese la opcion que desea realizar: ";
			cin >> op;
			switch (op)
			{
			case 1:
				cinta_transportadora();
				break;
			case 2:
				apagar_cinta();
				break;
			case 3:
				caja_registradora();
				break;
			case 4:
				apagar();
				break;
			case 5:
				salir();
				break;
			default:
				break;
			}
		} while (op != 5);
	}
	else {
		cout << "Error de Conexion" << endl << endl;
	}
}
void cinta_transportadora() {

	string data = "1";


	char* charArray = new char[data.size() + 1];
	copy(data.begin(), data.end(), charArray);
	charArray[data.size()] = '\n';

	arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
	arduino.readSerialPort(output, MAX_DATA_LENGTH);

	cout << ">> " << output << endl;

	delete[] charArray;
	system("cls");
	//ystem("pause");
}

void apagar_cinta() {        

	string data = "2";


	char* charArray = new char[data.size() + 1];
	copy(data.begin(), data.end(), charArray);
	charArray[data.size()] = '\n';

	arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
	arduino.readSerialPort(output, MAX_DATA_LENGTH);

	cout << ">> " << output << endl;

	delete[] charArray;
	system("cls"); 
	//system("pause");
}

void caja_registradora() {
	string data = "3";


	char* charArray = new char[data.size() + 1];
	copy(data.begin(), data.end(), charArray);
	charArray[data.size()] = '\n';

	arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
	arduino.readSerialPort(output, MAX_DATA_LENGTH);

	cout << ">> " << output << endl;

	delete[] charArray;
	system("cls");
	//system("pause");
}
void apagar() {
	string data = "4";


	char* charArray = new char[data.size() + 1];
	copy(data.begin(), data.end(), charArray);
	charArray[data.size()] = '\n';

	arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
	arduino.readSerialPort(output, MAX_DATA_LENGTH);

	cout << ">> " << output << endl;

	delete[] charArray;
	system("cls");
	//system("pause");

}

void salir() {
	string data = "5";


	char* charArray = new char[data.size() + 1];
	copy(data.begin(), data.end(), charArray);
	charArray[data.size()] = '\n';

	arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
	arduino.readSerialPort(output, MAX_DATA_LENGTH);

	cout << ">> " << output << endl;

	delete[] charArray;
	system("cls");
	//system("pause");

}