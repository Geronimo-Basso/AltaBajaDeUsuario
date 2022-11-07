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
    }
    string imprimirUsuario(){
        return identificador + " " + nombre + " " + apellido + " ";
    }
};


int main()
{
    vector<Usuario*> *usuarios=new vector<Usuario*>;
    bool condicion=true;
    char opcionMenu;
    while(condicion){
        cout << "-----Bienvenido a nuestro sistema de altas y bajas de usuario-----" << endl;
        cout << "1. Dar de alta un usuario" << "\n" << "2. Dar de baja un usuario" << "\n" << "3. Finalizar programa" <<endl;
        cin >> opcionMenu;
        switch (opcionMenu) {
            case '1': {
                string nombre, apellido;
                cout << "Introduzca el nombre del usuario: " << endl;
                cin >> nombre;
                cout << "Introduzca el apellido del usuario: " << endl;
                cin >> apellido;
                int contador = 0;
                if (usuarios->size()==0){
                    usuarios->push_back(new Usuario(nombre, apellido, 0));
                }else {
                    for (int i = 0; i < usuarios->size(); ++i) {
                        contador++;
                        if (usuarios->at(i)->identificador != i) {
                            usuarios->push_back(new Usuario(nombre, apellido, i));
                            break;
                        } else if (contador >= usuarios->size()) {
                            usuarios->push_back(new Usuario(nombre, apellido, contador));
                            break;
                        } else{
                        }
                    }
                }
                break;
            }
            case '2': {
                if (usuarios->size()>=1){
                    for (int i = 0; i < usuarios->size(); ++i) {
                        cout << "Alumno " << i << "-" << usuarios->at(i)->imprimirUsuario() << endl; //Presentamos un listado de los profesores disponibles
                    }
                    cout << "Indique el alumno que desea borrar: " << endl;
                    int alumn1;
                    cin >> alumn1;
                    //usuarios->erase(alumn1);
                    delete usuarios->at(alumn1);
                }else{
                    cout << "Deben de existir al menos un alumno" << endl;
                }
                break;
            }
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

