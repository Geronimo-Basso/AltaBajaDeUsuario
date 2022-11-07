/*
Ejercicio 4: Implementar en C++ un sistema sencillo de altas y bajas de usuarios.
En dicho sistema de altas y bajas debe poder crearse un objeto “usuario” con nombre, apellidos y número de usuario, correspondiente al número de usuarios dados de alta.
Importante remarcar que los ID de usuarios no se sustituyen. Si se han creado 3 usuarios y se da de baja el tercero, el nuevo usuario tendrá el id 3.
Para dar de baja un usuario, debe eliminarse usando el destructor del objeto usuario, mostrando por pantalla que usuarios han sido destruido.
 */
#include <iostream>
#include <vector>
using namespace std;

class Usuario{
public:
    string nombre;
    string apellido;
    int identificador;
public:
    Usuario(string nombre, string apellido, int identificador){
        Usuario::nombre=nombre;
        Usuario::apellido=apellido;
        Usuario::identificador=identificador;
    }
    ~Usuario(){
        cout << "\n-------- Usuario " << nombre << " ha salido de el sistema--------\n";
    }
};

class Sistema{
public:
    vector <Usuario> vec;
};

int main()
{
    Sistema sis;
    bool condicion=true;
    char opcionMenu;
    while(condicion){
        cout << "Bienvenido a nuestro sistema de altas y bajas de usuario" << endl;
        cout << "1. Dar de alta un usuario" << "\n" << "2. Dar de baja un usuario" << "\n" << "3. Finalizar programa" <<endl;
        cin >> opcionMenu;
        switch (opcionMenu) {
            case '1':
                string nombre;
                string apellido;
                cout << "Introduzca el nombre del usuario: " << endl;
                cin >> nombre;
                cout << "Introduzca el apellido del usuario: " << endl;
                cin >> apellido;
                sis.vec.push_back(Usuario(nombre,apellido,0));
                break;
            case '2':
                break;
            case '3':
                condicion=false;
                break;
                default:
                cout << "Error en el valor ingresado, intente otra vez";
                break;
        }
    }

    return 0;
}

