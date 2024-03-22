#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <string>
using namespace std;

class Cliente {
    private:
        int idCliente;
        string nombre, apellido;

    public:
        Cliente(int idCl, string n, string a);
        ~Cliente();
        int getIdCliente();
        string getNombre();
        string getApellido();
};

#endif // CLIENTE_H_INCLUDED

