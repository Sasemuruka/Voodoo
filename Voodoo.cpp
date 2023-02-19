#include<iostream> 
#include <string>
#include<string.h>
#include <limits>
#include <conio.h>
#include <mbstring.h>


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



string Ncomp, Nusu;
bool arre = 1;
int contador = 0, detener, Tusu;

void usuarios();
void registrarusuario(Usuario*nuevo);
void modificarusu(string Nbuscar);
void eliminarusu(string Eliminarusu);
void mostrarListausuario();


Usuario* iniciousu, * auxusu = nullptr;
Usuario* nodousu = new Usuario;



void main()
{
	while (b)
	{


		system("color 0D");

		cout << "\n\t Welcome to Voodoo" << endl;

		cout << "\n\t====Menu Principal====" << endl;
		cout << "\n\t1. Usuario" << endl;
		cout << "\n\t2. Clientes" << endl;
		cout << "\n\t3. Promociones" << endl;
		cout << "\n\t4. Sucursales" << endl;
		cout << "\n\t5. Salir" << endl;
		cout << "\n\t6. Limpiar pantalla" << endl;
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



		default:
			cout << "Error... el digito no es valido vuelvelo a intentar...";
			break;
		}




	}
	system("pause>null");
}

void usuarios()
{
	bool U = 1;
	while (U)
	{
		cout << "\n\t:::::Menu de usuario:::::" << endl;
		cout << "\n\t1. Ingresar un usuario" << endl;
		cout << "\n\t2. Modificar" << endl;
		cout << "\n\t3. Eliminar" << endl;

		cout << "\n\t4. Salir" << endl;
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

				cout << "selecciona 1 para agregar otro usuario o 2 para volver al menu de busqueda: " << endl;

				cin >> detener;

				if (detener == 1)
				{
					arre = 1;
				}

				if (detener == 2)
				{

					arre = 0;
				}

				contador++;

			}
			nodousu->sig = nullptr;
			registrarusuario(nodousu);


			break;


		case 2:
			cout << "Ingresa el nombre completo del usuario para modificar: " << endl;
			getline(cin, Ncomp);
			
			cin.ignore();
			modificarusu(Ncomp);
			cin.ignore();
			break;


		case 3:
			cout << "Ingresa el usuario para eliminar: " << endl;
			getline(cin, Nusu);
			eliminarusu(Nusu);

			break;

		case 4:
			mostrarListausuario();
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
		while (auxusu !=nullptr && Nbuscar != auxusu->comp)
		{
			auxusu = auxusu->sig;
		}

		if (auxusu == nullptr)
		{
			cout << "no se encontro ningun usuario con ese nombre..." << endl;
		}
		else
		{
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
			getline(cin, auxusu->sucursalusu);

			cout << "====Se modifico el usuario====" << endl;

		}
	}
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
		while (auxusu !=nullptr && auxusu->nomusu == Eliminarusu !=0  )
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
			cout << "Nombre Producto: " << auxusu->comp << endl;
			cout << "\n";

			iniciousu = iniciousu->sig;

			delete auxusu;

			auxusu = iniciousu;

			cout << "====Usuario eliminado====" << endl;
		}
		else {
			cout << "====Producto encontrado==== " << endl;
			cout << "Nombre Producto: " << auxusu->comp << endl;
			cout << "\n";

			anteriorusu->sig = auxusu->sig;

			delete auxusu;		

			auxusu = iniciousu;	

			cout << "====producto eliminada==== " << endl;

		}

	}


}
void mostrarListausuario()
{
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
			cout << "Contraseña: " << auxusu->contrasena << endl;
			cout << "Tipo de usuario: " << auxusu->Tipousu << endl;
			cout << "Sucursal: " << auxusu->sucursalusu << endl;
			cout << "~~~~~~~~~~~~~~~~~" << endl;
			auxusu = auxusu->sig;
		}
	}

}
