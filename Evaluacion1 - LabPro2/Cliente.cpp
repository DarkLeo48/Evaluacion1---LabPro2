#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente(int idCl, string n, string a) : idCliente(idCl), nombre(n), apellido(a){

}

Cliente::~Cliente() {

}

int Cliente::getIdCliente(){
    return idCliente;
}

string Cliente::getNombre(){
    return nombre;
}

string Cliente::getApellido(){
    return apellido;
}
