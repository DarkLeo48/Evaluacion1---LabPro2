#include <iostream>

using namespace std;
#include <stdlib.h>
#include "Cliente.h"
#include "Fecha.h"
#include "Pago.h"
#include "Prestamo.h"
#define TAM 5

Cliente *agregarCliente(){
    int idCl;
    string n,a;
    Cliente *cl;
    cout << "Digite el id del cliente: ";
    cin >> idCl;
    cout << "Digite el nombre del cliente: ";
    cin >> n;
    cout << "Digite el apellido del cliente: ";
    cin >> a;
    cl = new Cliente(idCl, n, a);
    return cl;
}

Prestamo *agregarPrestamo(Cliente *cl){
    int noPres;
    int d, m, a;
    Fecha *fechApro=NULL;
    float montApro;
    Prestamo *pres;
    cout << "Digite el numero del prestamo: ";
    cin >> noPres;
    cout << "Digite la fecha de aprobacion (dd/mm/aa) : \n";
    cin >> d;
    cin >> m;
    cin >> a;
    fechApro = new Fecha(d, m, a);
    cout << "Digite el monto aprobado \n: ";
    cin >> montApro;
    pres = new Prestamo(noPres, cl, fechApro, montApro);
    return pres;
}

Cliente *buscarCliente(Cliente *lst[], int cont, int db){
    bool encontrado = false;
    int contador = 0;
    Cliente *cl = NULL;
    while(contador < cont && !encontrado){
        if(lst[contador] -> getIdCliente() == db){
            encontrado = true;
            cl = lst[contador];
          }else{
              contador++;
          }
    }
    return cl;
}

Prestamo *buscarPrestamo(Prestamo *lst[], int cont, int db){
    bool encontrado = false;
    int contador = 0;
    Prestamo *pres = NULL;
    while(contador < cont && !encontrado){
        if(lst[contador] -> getNumeroPrestamo() == db){
            encontrado = true;
            pres = lst[contador];
          }else{
              contador++;
          }
    }
    return pres;
}

void registrarPago(Prestamo *pres){
    int d, m, a;
    Fecha *fecPag;
    float montPag;
    Pago *pg;
    cout << "Digite la fecha de pago (dd/mm/aa) : \n";
    cin >> d;
    cin >> m;
    cin >> a;
    cout << "Digite el monto del pago: ";
    cin >> montPag;
    fecPag = new Fecha(d, m, a);
    pg = new Pago(fecPag, montPag);
    pres -> HacerPago(pg);
}

void verDetalles(Prestamo *pres){
    cout << "El numero: " << pres -> getNumeroPrestamo() << endl;
    cout << "Cliente: " << pres -> getCliente() -> getNombre() << " " << pres -> getCliente() -> getApellido() << endl;
    cout << "Fecha de aprobacion: ";
    pres -> getFechaAprobacion() -> MostrarFecha();
    cout << "\nMonto Aprobado: " << pres -> getMontoAprobado() << endl;
    cout << "Saldo Pendiente: " << pres -> getSaldoPendiente() << endl;
    if(pres -> getContPagos() == 0){
        cout << "No tiene pagos registrados\n";
    }else{
        Pago **lista = pres -> getLstPagos();
        cout << "No\tFecha\tMonto\n";
        for(int i = 0; i < pres -> getContPagos(); i++){
            cout << (i + 1) << "\t";
            lista[i] -> getFechaPago() -> MostrarFecha();
            cout << "\t" << lista[i] -> getMontoPago() << endl;
        }
    }
}

int menu(){
    int op;
    cout << "MENU DE OPCIONES\n";
    cout << "1. Agregar clientes a la lista\n";
    cout << "2. Agregar prestamos a la lista\n";
    cout << "3. Hacer pagos de prestamos\n";
    cout << "4. Mostrar lista de clientes\n";
    cout << "5. Mostrar lista de prestamos\n";
    cout << "6. Mostrar detalles prestamo\n";
    cout << "7. Salir\n";
    cout << "Digite la opcion : ";
    cin >> op;
    return op;
}

int main()
{
    Cliente *lstCliente[TAM];
    Prestamo *lstPrestamo[TAM];
    Cliente *cl = NULL;
    Prestamo *pres = NULL;
    int opc, contCln = 0, contPres = 0, idCl, idPres;

    do{
       system("cls");
       opc = menu();
       switch(opc){
            case 1:

                ///Agregar clientes a la lista
                if(contCln < TAM){
                    lstCliente[contCln] = agregarCliente();
                    contCln++;
                    cout << "El cliente se agrego con exito\n";
                }else{
                    cout << "La lista de clientes esta llena\n";
                }

                break;

            case 2:

                ///Agregar prestamos a la lista
                if(contPres < TAM){
                    cout << "Digite el id del cliente: ";
                    cin >> idCl;
                    cl = buscarCliente(lstCliente, contCln, idCl);
                    if(cl){
                        lstPrestamo[contPres] = agregarPrestamo(cl);
                        contPres++;
                        cout << "El prestmo se agrego con exito";
                    }else{
                        cout << "El cliente no existe, no se pudo agregar el prestamo";
                    }
                }else{
                    cout << "La lista esta llena\n";
                }

                break;

            case 3:

                ///Hacer pago de prestamos
                cout << "Digite el numero de prestamo";
                cin >> idPres;
                pres = buscarPrestamo(lstPrestamo, contPres, idPres);
                if(pres){
                    registrarPago(pres);
                    cout << "El pago se registro con exito";
                }else{
                    cout << "El prestamo no existe, no se pudo registrar el pago";
                }

                break;

            case 4:

                ///Mostrar lista de clientes
                if(contCln == 0){
                    cout << "L lista esta vacia";
                }else{
                    cout << "Id\tNombre\tApellido\n";
                    for(int i = 0; i < contCln; i++){
                        cout << lstCliente[i] -> getIdCliente() << "\t";
                        cout << lstCliente[i] -> getNombre() << "\t";
                        cout << lstCliente[i] -> getApellido() << "\n";
                    }
                }

                break;

            case 5:

                ///Mostrar lista de prestamos
                if(contCln == 0){
                    cout << "La lista esta vacia";
                }else{
                    cout << "No\tCliente\tFecha\tMonto\tSaldo\n";
                    for(int i = 0; i < contPres; i++){
                        cout << lstPrestamo[i] -> getNumeroPrestamo() << "\t";
                        cout << lstPrestamo[i] -> getCliente() -> getNombre() << " " << lstPrestamo[i] -> getCliente() -> getApellido() << "\t";
                        lstPrestamo[i] -> getFechaAprobacion() -> MostrarFecha();
                        cout << "\t" << lstPrestamo[i] -> getMontoAprobado() << "\t";
                        cout << lstPrestamo[i] -> getSaldoPendiente() << endl;
                    }
                }

                break;

            case 6:

                ///Mostrar detalles prestamos
                cout << "Digite el numero de prestamo";
                cin >> idPres;
                pres = buscarPrestamo(lstPrestamo, contPres, idPres);
                if(pres){
                    verDetalles(pres);
                }else{
                    cout << "El prestamo no existe, no se puede visualizar los detalles";
                }

                break;

            case 7:
                cout << "Saliendo del programa\n";
                break;

            default:
                cout << "Error, opcion no esta definida\n";
                break;
       }
        system("pause");

    }while(opc != 7);

    return 0;
}
