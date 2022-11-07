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
public: //atributos de la clase Usuario
    string nombre;
    string apellido;
    int identificador;

public:
    Usuario(string nombre, string apellido, int identificador){ //Constructor de la clase Usuario
        Usuario::nombre=nombre;
        Usuario::apellido=apellido;
        Usuario::identificador=identificador;
    }
    ~Usuario(){ //Destructor de Usuario
    }
    string imprimirUsuario(){
        return to_string(identificador) + " " + nombre + " " + apellido; //Devuelve un string con la informacion del usuario para luego mostrarlo por pantalla
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
                if (usuarios->size()==0){ //si no hay ningun usuario creado, al primero se le asigna el id0
                    usuarios->push_back(new Usuario(nombre, apellido, 0));
                }else {
                    for (int i = 0; i < usuarios->size(); ++i) {
                        contador++;
                        if (usuarios->at(i)->identificador != i) { // si hay un identificador sin asignar se le asigna al nuevo usuario
                            usuarios->push_back(new Usuario(nombre, apellido, i));
                            break;
                        } else if (contador >= usuarios->size()) { //si todos los identificadores estan asignados, se le da al usuario el ultimo
                            usuarios->push_back(new Usuario(nombre, apellido, contador));
                            break;
                        } else{
                        }
                    }
                }
                break;
            }
            case '2': {
                if (usuarios->size()>=1){ //requiere que haya al menos un usuario creado
                    cout << "----Usuarios----" << endl;
                    for (int i = 0; i < usuarios->size(); ++i) {
                        cout << usuarios->at(i)->imprimirUsuario() << endl; //Presentamos un listado de los usuarios disponibles
                    }
                    cout << "Indique el codigo del usuario: " << endl;
                    string stringCodigoAlumno;
                    cin >> stringCodigoAlumno;
                    int intCodigoAlumno;
                    int elemento=0;
                        intCodigoAlumno=stoi(stringCodigoAlumno);
                        for(int i=0;i<usuarios->size();i++){ //recorre el vector de usuarios
                            if(intCodigoAlumno==(usuarios->at(i)->identificador)) {
                                elemento=i; //si encontramos el identificador del usuario guardamos su posicion del vector para acceder luego
                            }
                        };
                    delete usuarios->at(elemento); //eliminamos el usuario del free store
                    usuarios->erase(usuarios->begin() + elemento); //eliminamos el usuario del vector para dejar el hueco limpio
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

