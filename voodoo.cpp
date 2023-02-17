#include<iostream> 
#include <string>
#include<string.h>
#include <limits>
#include <conio.h>
#include <fstream>

using namespace std;

int a;
bool b = 1, si = 1;


struct Usuario
{
	string comp[50], nomusu[50], contraseña[10];
	Usuario* sig;
};







void usuarios();

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

						
			cout << "\nIngrese nombre completo" << endl;		
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin,nodousu->comp[50]);
						
			cout << "\nIngrese su nombre de usuario" << endl;		
			getline(cin,nodousu->nomusu[50]);
			
			cout << "\nIngrese una contrasena" << endl;
			getline(cin,nodousu->contraseña[10]);



			break;


		default:
			break;
		}




	}

}