#include<iostream> 
#include <string>
#include<string.h>
#include <limits>
#include <conio.h>
#include <mbstring.h>
#include <fstream>


using namespace std;

int a;
bool b = 1, si = 1;


struct Usuario
{
	string comp;
	string nomusu;
	string contrasena, sucursalusu;
	int Tipousu;
	Usuario* sig;
};

Usuario* iniciousu, * auxusu = nullptr;
Usuario* nodousu = new Usuario;

string Ncomp, Nusu;
bool arre = 1;
int contador = 0, detener, Tusu;

void usuarios();
void registrarusuario(Usuario*nuevo);
void modificarusu(string Nbuscar);
void eliminarusu(string Eliminarusu);
void mostrarListausuario();
void escribirbinariousu();
void leerbinarioUsu();

struct Cliente
{
	string compcli;
	string correo;
	string sucursalcli;
	int Telefono, puntoscli=0;
	Cliente* sigcli;
};

Cliente* iniciocli, * auxcli = nullptr;
Cliente* nodocli = new Cliente;

int BTel;
string Mcorr;

void Clientes();
void registrarclientes(Cliente* nuevocli);
void modificarcli(string Modc);
void eliminarcli(int borrartel);
void mostrarlistacli();
void escribirbinariocli();
void leerbinariocli();

struct Promociones
{
	string compprom;	
	int estatus, puntos, descuento;	
	Promociones* sigpro;
};

Promociones* iniciopro, * auxpro = nullptr;
Promociones* nodopro = new Promociones;

string Mnom, Bnom;

void Promocion();
void registrarpromo(Promociones* nuevopro);
void modificarpromo(string Mpromo);
void eliminarpromo(string Bpromo);
void mostrarlistapromo();
void escribirbinariopromo();
void leerbinariopromo();

struct Sucursales
{
	string compsuc, direccion;

    Sucursales* sigsuc;
};

Sucursales* iniciosuc, * auxsuc = nullptr;
Sucursales* nodosuc = new Sucursales;

string Msuc, Bsuc;

void sucursales();
void registrarsuc(Sucursales* nuevosuc);
void modificarsuc(string Msucu);
void eliminarsuc(string Bsucu);
void mostrarlistasuc();
void escribirbinariosucu();
void leerbinariosucu();

void main()
{
	b = 1;
	while (b)
	{

		system("cls");
		system("color 0D");

		cout << "\n\t Welcome to Voodoo" << endl;

		cout << "\n\t====Menu Principal====" << endl;
		cout << "\n\t1. Usuario" << endl;
		cout << "\n\t2. Clientes" << endl;
		cout << "\n\t3. Promociones" << endl;
		cout << "\n\t4. Sucursales" << endl;
		cout << "\n\t5. Salir" << endl;		
		cout << "\n  Ingrese un digito para continuar...";


		while (si)
		{
			cin >> a;
			if (!cin.good())
			{
				cout << "\nERROR intenta con otro digito de preferencia un entero....\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
				break;
		}



		switch (a)
		{
		case 1:

			usuarios();
			break;

		case 2:

			Clientes();
			break;

		case 3:

			Promocion();
			break;

		case 4:

			sucursales();
			break;

		case 5:

			escribirbinariocli();
			escribirbinariousu();
			b = 0;
			break;


		default:
			cout << "Error... el digito no es valido vuelvelo a intentar...";
			break;
		}




	}
	system("pause>null");
}

void usuarios()
{
	leerbinarioUsu();

	bool U = 1;
	while (U)
	{
		system("cls");

		cout << "\n\t:::::Menu de usuario:::::" << endl;
		cout << "\n\t1. Ingresar un usuario" << endl;
		cout << "\n\t2. Modificar" << endl;
		cout << "\n\t3. Eliminar" << endl;
		cout << "\n\t4. Mostrar Lista" << endl;
		cout << "\n\t5. Salir" << endl;
		cout << "\n  Ingrese un digito para continuar...";

		while (si)
		{
			cin >> a;
			if (!cin.good())
			{
				cout << "\nERROR intenta con otro digito de preferencia un entero....\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
				break;
		}

		switch (a)
		{

		case 1:

			arre = 1;

			while (arre)
			{

				cout << "\nIngrese nombre completo" << endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(cin, nodousu->comp);

				cout << "\nIngrese su nombre de usuario" << endl;
				getline(cin, nodousu->nomusu);

				cout << "\nIngrese una contrasena" << endl;
				getline(cin, nodousu->contrasena);

				cout << "\n\t selecciona el tipo de usuario: " << endl;
				cout << "\n\t1. Administrador" << endl;
				cout << "\n\t2. Cajero" << endl;
								
				while (si)
				{
					cin >> nodousu->Tipousu;
					if (!cin.good())
					{
						cout << "\nERROR intenta con otro digito de preferencia un entero....\n";
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}					
					else
						break;
				}				
				cout << "Ingresa la sucursal: " << endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(cin, nodousu->sucursalusu);

				arre = 0;

			}
			nodousu->sig = nullptr;
			registrarusuario(nodousu);


			break;


		case 2:
			cout << "Ingresa el nombre completo del usuario para modificar: " << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, Ncomp);				
			modificarusu(Ncomp);
		
			break;


		case 3:
			cout << "Ingresa el usuario para eliminar: " << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, Nusu);
			eliminarusu(Nusu);

			break;

		case 4:
			mostrarListausuario();
			break;

		case 5:



			U = 0;
			break;


		default:

			break;
		}




	}

}
void registrarusuario(Usuario*nuevo)
{
	if (iniciousu == nullptr)
	{
		iniciousu = new Usuario;
		
		(iniciousu->comp = nuevo->comp);
		(iniciousu->nomusu = nuevo->nomusu);
		(iniciousu->contrasena = nuevo->contrasena);
		iniciousu->Tipousu = nuevo->Tipousu;
		(iniciousu->sucursalusu = nuevo->sucursalusu);
		iniciousu->sig = nullptr;
	}
	else
	{
		if (auxusu == nullptr)
		{
			auxusu = iniciousu;

		}
		while (auxusu->sig!= nullptr)
		{
			auxusu = auxusu->sig;
		}

		auxusu->sig = new Usuario;
		auxusu = auxusu->sig;
		(auxusu->comp = nuevo->comp);
		(auxusu->nomusu = nuevo->nomusu);
		(auxusu->contrasena = nuevo->contrasena);
		auxusu->Tipousu = nuevo->Tipousu;
		(auxusu->sucursalusu = nuevo->sucursalusu);

		auxusu->sig = nullptr;
	}
	

}
void modificarusu(string Nbuscar)
{

	auxusu = iniciousu;

	if (auxusu == nullptr)
	{
		cout << "Aun no hay ningun usuario, ingrese un usuario..." << endl;
	}
	else
	{
		bool esigual = auxusu->comp == Nbuscar;


		while (auxusu !=nullptr && esigual == false)
		{
			auxusu = auxusu->sig;
		}

		if (auxusu == nullptr)
		{
			cout << "no se encontro ningun usuario con ese nombre..." << endl;
		}
		else
		{
			system("cls");

			cout << "====usuario encontrado====" << endl;
			cout << "nombre de usuario: " << auxusu->nomusu << endl;

			cout << "ingresa nuevo nombre completo: " << endl;
			getline(cin, auxusu->comp);
			cout << "\n";
			cout << "Nuevo nombre de usuario: " << endl;
			getline(cin, auxusu->nomusu);
			cout << "\n";
			cout << "Nueva contraseña: " << endl;
			getline(cin, auxusu->contrasena);
			cout << "\n";
			cout << "\n\t selecciona el nuevo tipo de usuario: " << endl;
			cout << "\n\t1. Administrador" << endl;
			cout << "\n\t2. Cajero" << endl;

			while (si)
			{
				cin >> auxusu->Tipousu;
				if (!cin.good())
				{
					cout << "\nERROR intenta con otro digito de preferencia un entero....\n";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else
					break;
			}
			cout << "\n";
			cout << "Nueva sucursal: " << endl;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, auxusu->sucursalusu);

			cout << "====Se modifico el usuario====" << endl;

		}
	}

	system("pasue>null");
}
void eliminarusu(string Eliminarusu)
{
	auxusu = iniciousu;
	Usuario* anteriorusu = nullptr;
	if (auxusu == nullptr)
	{
		cout << "Aun no hay ningun usuario, ingrese un usuario..." << endl;
	}
	else
	{

		bool isEqual = auxusu->nomusu == Eliminarusu;



		while (auxusu !=nullptr && isEqual == false)
		{
			anteriorusu = auxusu;
			auxusu = auxusu->sig;
		}
		if (auxusu == nullptr) {
			cout << "Usuario no encontrado" << endl;
		}
		else if (auxusu == iniciousu)
		{
			

			cout << "====Usuario encontrado==== " << endl;
			cout << "Nombre Usuario: " << auxusu->comp << endl;
			cout << "\n";

			iniciousu = iniciousu->sig;

			delete auxusu;

			auxusu = iniciousu;

			cout << "====Usuario eliminado====" << endl;
		}
		else {
			cout << "====Usuario encontrado==== " << endl;
			cout << "Nombre Usuasrio: " << auxusu->comp << endl;
			cout << "\n";

			anteriorusu->sig = auxusu->sig;

			delete auxusu;		

			auxusu = iniciousu;	

			cout << "====Usuario eliminada==== " << endl;

		}

	}
	system("pause>null");

}
void mostrarListausuario()
{
	system("cls");

	if (iniciousu == nullptr)
	{
		cout << "Aun no hay ningun usuario, ingrese un usuario..." << endl;
	}
	else
	{
		auxusu = iniciousu;

		while (auxusu != nullptr)
		{
			cout << "Nombre completo: " << auxusu->comp << endl;
			cout << "Nombre usuario: " << auxusu->nomusu << endl;
			cout << "Contrasena: " << auxusu->contrasena << endl;
			cout << "Tipo de usuario: " << auxusu->Tipousu << endl;
			cout << "Sucursal: " << auxusu->sucursalusu << endl;
			cout << "~~~~~~~~~~~~~~~~~" << endl;
			auxusu = auxusu->sig;
		}
	}
	system("pause>null");
}
void escribirbinariousu()
{
	auxusu = iniciousu;

	ofstream escrUsu;
	escrUsu.open("Usuarios.bin", ios::out | ios::binary | ios::trunc);

	if (escrUsu.is_open())
	{
		while (auxusu != nullptr)
		{
			escrUsu.write((char*)auxusu, sizeof(Usuario));
			auxusu = auxusu->sig;
		}

		escrUsu.close();
	}
	else
	{
		cout << "No se pudo abrir el archivo.";
		system("PAUSE");
	}

}
void leerbinarioUsu()
{
	ifstream leerUsu;
	leerUsu.open("Usuarios.bin", ios::in | ios::binary);


	if (leerUsu.is_open()) 
	{

		Usuario* usuLeido = new Usuario;

		while (!leerUsu.read((char*)usuLeido, sizeof(Usuario)).eof()) {

			if (iniciousu == nullptr) {
				iniciousu = usuLeido;
				iniciousu->sig = nullptr;
				auxusu = iniciousu;
			}
			else {
				auxusu->sig = usuLeido;
				auxusu = auxusu->sig;
				auxusu->sig = nullptr;
				
			}

			usuLeido = new Usuario;
		}
		leerUsu.close();
		delete usuLeido;
	}
	else {
		cout << "No es posible abrir el archivo.";
		system("PAUSE");
	}

}

void Clientes()
{
	leerbinariocli();

	bool U = 1;
	while (U)
	{
		system("cls");

		cout << "\n\t:::::Menu de clientes:::::" << endl;
		cout << "\n\t1. Ingresar un clientes" << endl;
		cout << "\n\t2. Modificar" << endl;
		cout << "\n\t3. Eliminar" << endl;
		cout << "\n\t4. Mostrar Lista" << endl;
		cout << "\n\t5. Salir" << endl;
		cout << "\n  Ingrese un digito para continuar...";

		while (si)
		{
			cin >> a;
			if (!cin.good())
			{
				cout << "\nERROR intenta con otro digito de preferencia un entero....\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
				break;
		}

		switch (a)
		{

		case 1:

			arre = 1;

			while (arre)
			{

				cout << "\nIngrese nombre completo" << endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(cin, nodocli->compcli);

				cout << "\nIngrese su numero de telefono" << endl;
			    cin >> nodocli->Telefono;

				cout << "\nIngrese su correo electronico" << endl;
				getline(cin, nodocli->correo);
				
				cout << "Ingresa la sucursal: " << endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(cin, nodocli->sucursalcli);

				cout << "Cantidad de puntos para promociones: "<< nodocli->puntoscli <<endl;

				arre = 0;

			}
			nodocli->sigcli = nullptr;
			registrarclientes(nodocli);


			break;


		case 2:
			cout << "Ingresa el correo electronico del cliente para modificar: " << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, Mcorr);
			modificarcli(Mcorr);

			break;


		case 3:
			cout << "Ingresa el telefono del cliente para eliminar: " << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> BTel;
			eliminarcli(BTel);

			break;

		case 4:
			mostrarlistacli();
			break;

		case 5:



			U = 0;
			break;


		default:

			break;
		}




	}

}
void registrarclientes(Cliente* nuevocli)
{
	if (iniciocli == nullptr)
	{
		iniciocli = new Cliente;

		(iniciocli->compcli = nuevocli->compcli);
		iniciocli->Telefono = nuevocli->Telefono;
        (iniciocli->correo = nuevocli->correo);
		(iniciocli->sucursalcli = nuevocli->sucursalcli);
		iniciocli->puntoscli = nuevocli->puntoscli;
		iniciocli->sigcli = nullptr;
	}
	else
	{
		if (auxcli == nullptr)
		{
			auxcli = iniciocli;

		}
		while (auxcli->sigcli != nullptr)
		{
			auxcli = auxcli->sigcli;
		}

		auxcli->sigcli = new Cliente;
		auxcli = auxcli->sigcli;
		(auxcli->compcli = nuevocli->compcli);
		auxcli->Telefono = nuevocli->Telefono;
		(auxcli->correo = nuevocli->correo);		
		(auxcli->sucursalcli = nuevocli->sucursalcli);
		auxcli->puntoscli = nuevocli->puntoscli;

		auxcli->sigcli = nullptr;
	}

}
void modificarcli(string Modc)
{

	auxcli = iniciocli;

	if (auxcli == nullptr)
	{
		cout << "Aun no hay ningun Cliente registrado, ingrese un cliente..." << endl;
	}
	else
	{
		bool esigualcli = auxcli->correo == Modc;


		while (auxcli != nullptr && esigualcli == false)
		{
			auxcli = auxcli->sigcli;
		}

		if (auxcli == nullptr)
		{
			cout << "no se encontro ningun cliente con ese correo..." << endl;
		}
		else
		{
			system("cls");

			cout << "====Cliente encontrado====" << endl;
			cout << "nombre del Cliente: " << auxcli->compcli << endl;
	
			cout << "Nuevo nombre: " << endl;
			getline(cin, auxcli->compcli);

			cout << "ingresa nuevo telefono: " << endl;
			cin >> auxcli->Telefono;
			cout << "\n";
			cout << "Nuevo nombre de correo: " << endl;
			getline(cin, auxcli->correo);
			cout << "\n";	
			cout << "Nueva sucursal: " << endl;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, auxcli->sucursalcli);
	 
			cout << "====Se modifico el cliente====" << endl;

		}
	}

	system("pasue>null");


}
void eliminarcli(int borrartel)
{
	auxcli = iniciocli;
	Cliente* anteriorcli = nullptr;
	if (auxcli == nullptr)
	{
		cout << "Aun no hay ningun Cliente registrado, ingrese un cliente..." << endl;
	}
	else
	{

		bool isEqualcli = auxcli->Telefono == borrartel;



		while (auxcli != nullptr && isEqualcli == false)
		{
			anteriorcli = auxcli;
			auxcli = auxcli->sigcli;
		}
		if (auxcli == nullptr) {
			cout << "Cliente no encontrado" << endl;
		}
		else if (auxcli == iniciocli)
		{


			cout << "====Cliente encontrado==== " << endl;
			cout << "Nombre Cliente: " << auxcli->compcli << endl;
			cout << "\n";

			iniciocli = iniciocli->sigcli;

			delete auxcli;

			auxcli = iniciocli;

			cout << "====Cliente eliminado====" << endl;
		}
		else {
			cout << "====Cliente encontrado==== " << endl;
			cout << "Nombre Cliente: " << auxcli->compcli << endl;
			cout << "\n";

			anteriorcli->sigcli = auxcli->sigcli;

			delete auxcli;

			auxcli = iniciocli;

			cout << "====Cliente eliminada==== " << endl;

		}

	}
	system("pause>null");

}
void mostrarlistacli()
{

	system("cls");

	if (iniciocli == nullptr)
	{
		cout << "Aun no hay ningun cliente registrado, ingrese un cliente..." << endl;
	}
	else
	{
		auxcli = iniciocli;

		while (auxcli != nullptr)
		{
			cout << "Nombre completo: " << auxcli->compcli << endl;
			cout << "Numero de Telefoono" << auxcli->Telefono << endl;
			cout << "Correo: " << auxcli->correo << endl;
			cout << "Sucursal: " << auxcli->sucursalcli << endl;
			cout << "Puntos para promociones: " << auxcli->puntoscli << endl;
			cout << "~~~~~~~~~~~~~~~~~" << endl;
			auxcli = auxcli->sigcli;
		}
	}
	system("pause>null");

}
void escribirbinariocli()
{
	auxcli = iniciocli;

	ofstream escrcli;
	escrcli.open("Cliente.bin", ios::out | ios::binary | ios::trunc);

	if (escrcli.is_open())
	{
		while (auxcli != nullptr)
		{
			escrcli.write((char*)auxcli, sizeof(Cliente));
			auxcli = auxcli->sigcli;
		}

		escrcli.close();
	}
	else
	{
		cout << "No se pudo abrir el archivo.";
		system("PAUSE");
	}
}
void leerbinariocli()
{
	ifstream leercli;
	leercli.open("Clientes.bin", ios::in | ios::binary);


	if (leercli.is_open())
	{

		Cliente* cliLeido = new Cliente;

		while (!leercli.read((char*)cliLeido, sizeof(Cliente)).eof()) {

			if (iniciocli == nullptr) {
				iniciocli = cliLeido;
				iniciocli->sigcli = nullptr;
				auxcli = iniciocli;
			}
			else {
				auxcli->sigcli = cliLeido;
				auxcli = auxcli->sigcli;
				auxcli->sigcli = nullptr;

			}

			cliLeido = new Cliente;
		}
		leercli.close();
		delete cliLeido;
	}
	else {
		cout << "No es posible abrir el archivo.";
		system("PAUSE");
	}

}

void Promocion()
{

	bool U = 1;
	while (U)
	{
		system("cls");

		cout << "\n\t:::::Menu de Promociones:::::" << endl;
		cout << "\n\t1. Ingresar una Promocion" << endl;
		cout << "\n\t2. Modificar" << endl;
		cout << "\n\t3. Eliminar" << endl;
		cout << "\n\t4. Mostrar Lista" << endl;
		cout << "\n\t5. Salir" << endl;
		cout << "\n  Ingrese un digito para continuar...";

		while (si)
		{
			cin >> a;
			if (!cin.good())
			{
				cout << "\nERROR intenta con otro digito de preferencia un entero....\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
				break;
		}

		switch (a)
		{

		case 1:

			arre = 1;

			while (arre)
			{

				cout << "\nIngrese nombre de la promocion" << endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(cin, nodopro->compprom);

				cout << "\nIngrese el numero de puntos requeridos: " << endl;
				cin >> nodopro->puntos;

				cout << "\nIngrese el porcentaje de descuento" << endl;
				cin >> nodopro->descuento;

				cout << "\n\t selecciona el estatus de la promocion: " << endl;
				cout << "\n\t1. Activo" << endl;
				cout << "\n\t2. Inactivo" << endl;

				while (si)
				{
					cin >> nodopro->estatus;
					if (!cin.good())
					{
						cout << "\nERROR intenta con otro digito de preferencia un entero....\n";
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					else
						break;
				}

		

				arre = 0;

			}
			nodopro->sigpro = nullptr;
			registrarpromo(nodopro);


			break;


		case 2:
			cout << "Ingresa el nombre de la promocion a modificar: " << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, Mnom);
			modificarpromo(Mnom);

			break;


		case 3:
			cout << "Ingresa el nombre de la promocion a modificar: " << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, Bnom);
			eliminarpromo(Bnom);

			break;

		case 4:
			mostrarlistapromo();
			break;

		case 5:



			U = 0;
			break;


		default:

			break;
		}




	}


}
void registrarpromo(Promociones* nuevopro)
{
	if (iniciopro == nullptr)
	{
		iniciopro = new Promociones;

		(iniciopro->compprom = nuevopro->compprom);
		iniciopro->puntos = nuevopro->puntos;
		iniciopro->descuento = nuevopro->descuento;
		iniciopro->estatus = nuevopro->estatus;
		iniciopro->sigpro = nullptr;
	}
	else
	{
		if (auxpro == nullptr)
		{
			auxpro = iniciopro;

		}
		while (auxpro->sigpro != nullptr)
		{
			auxpro = auxpro->sigpro;
		}

		auxpro->sigpro = new Promociones;
		auxpro = auxpro->sigpro;
		(auxpro->compprom = nuevopro->compprom);
		auxpro->puntos = nuevopro->puntos;
		auxpro->descuento = nuevopro->descuento;
		auxpro->estatus = nuevopro->estatus;

		auxpro->sigpro = nullptr;
	}
}
void modificarpromo(string Mpromo)
{

	auxpro = iniciopro;

	if (auxpro == nullptr)
	{
		cout << "Aun no hay ninguna promocion registrada, ingrese una promocion..." << endl;
	}
	else
	{
		bool esigualpro = auxpro->compprom == Mnom;


		while (auxpro != nullptr && esigualpro == false)
		{
			auxpro = auxpro->sigpro;
		}

		if (auxpro == nullptr)
		{
			cout << "no se encontro ninguna promocion con ese nombre..." << endl;
		}
		else
		{
			system("cls");

			cout << "====Promocion encontrada====" << endl;
			cout << "nombre de la promo: " << auxpro->compprom << endl;

			cout << "Nuevo nombre de promocion: " << endl;
			getline(cin, auxpro->compprom);

			cout << "ingresa los nuevos puntos: " << endl;
			cin >> auxpro->puntos;
			cout << "\n";
			cout << "Nuevo porcentaje de descuento: " << endl;
			cin >> auxpro->descuento;
			cout << "\n";
			cout << "Nuevo estatus 1 activo y 2 inactivo: " << endl;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> auxpro->estatus;

			cout << "====Se modifico la promocion====" << endl;

		}
	}

	system("pasue>null");


}
void eliminarpromo(string Bpromo)
{

	auxpro = iniciopro;
	Promociones* anteriorpro= nullptr;
	if (auxpro == nullptr)
	{
		cout << "Aun no hay ninguna promocion registrada, ingrese una promocion..." << endl;
	}
	else
	{

		bool isEqualpro = auxpro->compprom == Bpromo;



		while (auxpro != nullptr && isEqualpro == false)
		{
			anteriorpro = auxpro;
			auxpro = auxpro->sigpro;
		}
		if (auxpro == nullptr) {
			cout << "Promocion no encontrada" << endl;
		}
		else if (auxpro == iniciopro)
		{


			cout << "====Promocion encontrada==== " << endl;
			cout << "Nombre de la promocion: " << auxpro->compprom << endl;
			cout << "\n";

			iniciopro = iniciopro->sigpro;

			delete auxpro;

			auxpro = iniciopro;

			cout << "====Promocion eliminada====" << endl;
		}
		else {
			cout << "====Promocion encontrada==== " << endl;
			cout << "Nombre de la promocion: " << auxpro->compprom << endl;
			cout << "\n";

			anteriorpro->sigpro = auxpro->sigpro;

			delete auxpro;

			auxpro = iniciopro;

			cout << "====Promocion eliminada==== " << endl;

		}

	}
	system("pause>null");

}
void mostrarlistapromo()
{

	system("cls");

	if (iniciopro == nullptr)
	{
		cout << "Aun no hay ninguna promocion registrada, ingrese una promocion..." << endl;
	}
	else
	{
		auxpro = iniciopro;

		while (auxpro != nullptr)
		{
			cout << "Nombre completo: " << auxpro->compprom << endl;
			cout << "Numero de Telefoono" << auxpro->puntos << endl;
			cout << "Porcentaje de descuento" << auxpro->descuento << endl;
			cout << "Tipo de estatus" << auxpro->estatus << endl;
			cout << "~~~~~~~~~~~~~~~~~" << endl;
			auxpro = auxpro->sigpro;
		}
	}
	system("pause>null");

}
void escribirbinariopromo()
{

	auxpro = iniciopro;

	ofstream escrpro;
	escrpro.open("Promocion.bin", ios::out | ios::binary | ios::trunc);

	if (escrpro.is_open())
	{
		while (auxpro != nullptr)
		{
			escrpro.write((char*)auxcli, sizeof(Promociones));
			auxpro = auxpro->sigpro;
		}

		escrpro.close();
	}
	else
	{
		cout << "No se pudo abrir el archivo.";
		system("PAUSE");
	}

}
void leerbinariopromo()
{

	ifstream leerpro;
	leerpro.open("Promocion.bin", ios::in | ios::binary);


	if (leerpro.is_open())
	{

		Promociones* proLeido = new Promociones;

		while (!leerpro.read((char*)proLeido, sizeof(Promociones)).eof()) {

			if (iniciopro == nullptr) {
				iniciopro = proLeido;
				iniciopro->sigpro = nullptr;
				auxpro = iniciopro;
			}
			else {
				auxpro->sigpro = proLeido;
				auxpro = auxpro->sigpro;
				auxpro->sigpro = nullptr;

			}

			proLeido = new Promociones;
		}
		leerpro.close();
		delete proLeido;
	}
	else {
		cout << "No es posible abrir el archivo.";
		system("PAUSE");
	}


}

void sucursales()
{
	bool U = 1;
	while (U)
	{
		system("cls");

		cout << "\n\t:::::Menu de Sucursales:::::" << endl;
		cout << "\n\t1. Ingresar una sucursal" << endl;
		cout << "\n\t2. Modificar" << endl;
		cout << "\n\t3. Eliminar" << endl;
		cout << "\n\t4. Mostrar Lista" << endl;
		cout << "\n\t5. Salir" << endl;
		cout << "\n  Ingrese un digito para continuar...";

		while (si)
		{
			cin >> a;
			if (!cin.good())
			{
				cout << "\nERROR intenta con otro digito de preferencia un entero....\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
				break;
		}

		switch (a)
		{

		case 1:

			arre = 1;

			while (arre)
			{

				cout << "\nIngrese nombre de la sucursal" << endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(cin, nodosuc->compsuc);

				cout << "\nIngrese nombre de la sucursal" << endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				getline(cin, nodosuc->direccion);



				arre = 0;

			}
			nodosuc->sigsuc = nullptr;
			registrarsuc(nodosuc);


			break;


		case 2:
			cout << "Ingresa el nombre de la sucursal a modificar: " << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, Msuc);
			modificarsuc(Msuc);

			break;


		case 3:
			cout << "Ingresa el nombre de la sucursal a modificar: " << endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, Bsuc);
			eliminarsuc(Bsuc);

			break;

		case 4:
			mostrarlistasuc();
			break;

		case 5:



			U = 0;
			break;


		default:

			break;
		}




	}
}
void registrarsuc(Sucursales* nuevosuc)
{
	if (iniciosuc == nullptr)
	{
		iniciosuc = new Sucursales;

		(iniciosuc->compsuc = nuevosuc->compsuc);
		(iniciosuc->direccion = nuevosuc->direccion);		
		iniciosuc->sigsuc = nullptr;
	}
	else
	{
		if (auxsuc == nullptr)
		{
			auxsuc = iniciosuc;

		}
		while (auxsuc->sigsuc != nullptr)
		{
			auxsuc = auxsuc->sigsuc;
		}

		auxsuc->sigsuc = new Sucursales;
		auxsuc = auxsuc->sigsuc;
		(auxsuc->compsuc = nuevosuc->compsuc);
		(auxsuc->direccion = nuevosuc->direccion);
		auxsuc->sigsuc = nullptr;
	}
}
void modificarsuc(string Msucu) 
{
	auxsuc = iniciosuc;

	if (auxsuc == nullptr)
	{
		cout << "Aun no hay ninguna sucursal registrada, ingrese una sucursal..." << endl;
	}
	else
	{
		bool esigualsuc = auxsuc->compsuc == Msucu;


		while (auxsuc != nullptr && esigualsuc == false)
		{
			auxsuc = auxsuc->sigsuc;
		}

		if (auxsuc == nullptr)
		{
			cout << "no se encontro ninguna Sucursal con ese nombre..." << endl;
		}
		else
		{
			system("cls");

			cout << "====Sucursal encontrada====" << endl;
			cout << "nombre de la sucursal: " << auxsuc->compsuc << endl;

			cout << "Nuevo nombre de sucursal: " << endl;
			getline(cin, auxsuc->compsuc);

			cout << "Nueva direccion de sucursal: " << endl;
			getline(cin, auxsuc->direccion);

			cout << "====Se modifico la sucursal====" << endl;

		}
	}

	system("pasue>null");
}
void eliminarsuc(string Bsucu)
{
	auxsuc = iniciosuc;
	Sucursales* anteriorsuc = nullptr;
	if (auxsuc == nullptr)
	{
		cout << "Aun no hay ninguna sucursal registrada, ingrese una sucursal..." << endl;
	}
	else
	{

		bool isEqualsuc = auxsuc->compsuc == Bsucu;



		while (auxsuc != nullptr && isEqualsuc == false)
		{
			anteriorsuc = auxsuc;
			auxsuc = auxsuc->sigsuc;
		}
		if (auxsuc == nullptr)
		{
			cout << "Sucursal no encontrada" << endl;
		}
		else if (auxsuc == iniciosuc)
		{


			cout << "====Sucursal encontrada==== " << endl;
			cout << "Nombre de la sucursal: " << auxsuc->compsuc << endl;
			cout << "\n";

			iniciosuc = iniciosuc->sigsuc;

			delete auxsuc;

			auxsuc = iniciosuc;

			cout << "====Sucursales eliminada====" << endl;
		}
		else {
			cout << "====Sucursales encontrada==== " << endl;
			cout << "Nombre de la sucursal: " << auxsuc->compsuc << endl;
			cout << "\n";

			anteriorsuc->sigsuc = auxsuc->sigsuc;

			delete auxsuc;

			auxsuc= iniciosuc;

			cout << "====Sucursal eliminada==== " << endl;

		}

	}
	system("pause>null");
}
void mostrarlistasuc()
{
	system("cls");

	if (iniciosuc == nullptr)
	{
		cout << "Aun no hay ninguna sucursal registrada, ingrese una sucursal..." << endl;
	}
	else
	{
		auxsuc = iniciosuc;

		while (auxsuc != nullptr)
		{
			cout << "Nombre completo: " << auxsuc->compsuc << endl;
			cout << "Nombre completo: " << auxsuc->direccion << endl;
			cout << "~~~~~~~~~~~~~~~~~" << endl;
			auxsuc = auxsuc->sigsuc;
		}
	}
	system("pause>null");
}
void escribirbinariosucu()
{
	auxsuc = iniciosuc;

	ofstream escrsuc;
	escrsuc.open("Sucursal.bin", ios::out | ios::binary | ios::trunc);

	if (escrsuc.is_open())
	{
		while (auxsuc != nullptr)
		{
			escrsuc.write((char*)auxsuc, sizeof(Sucursales));
			auxsuc = auxsuc->sigsuc;
		}

		escrsuc.close();
	}
	else
	{
		cout << "No se pudo abrir el archivo.";
		system("PAUSE");
	}
}
void leerbinariosucu()
{
	ifstream leersuc;
	leersuc.open("Sucursal.bin", ios::in | ios::binary);


	if (leersuc.is_open())
	{

		Sucursales* sucLeido = new Sucursales;

		while (!leersuc.read((char*)sucLeido, sizeof(Sucursales)).eof()) {

			if (iniciosuc == nullptr) {
				iniciosuc = sucLeido;
				iniciosuc->sigsuc = nullptr;
				auxsuc = iniciosuc;
			}
			else {
				auxsuc->sigsuc = sucLeido;
				auxsuc = auxsuc->sigsuc;
				auxsuc->sigsuc = nullptr;

			}

			sucLeido = new Sucursales;
		}
		leersuc.close();
		delete sucLeido;
	}
	else {
		cout << "No es posible abrir el archivo.";
		system("PAUSE");
	}
}