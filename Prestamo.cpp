#include "Prestamo.h"
#include <iostream>
using namespace std;

Prestamo::Prestamo() : numeroPrestamo(0), contPagos(0), montoAprobado(0), saldoPendiente(0) {

}

Prestamo::Prestamo(int noPres, Cliente *cl, Fecha *fecApro, float montApro) : numeroPrestamo(noPres), cliente(cl), fechaAprobacion(fecApro), montoAprobado(montApro), saldoPendiente(montApro),
                   contPagos(0){

}

Prestamo::~Prestamo() {

}

int Prestamo::getNumeroPrestamo() {
    return numeroPrestamo;
}

void Prestamo::setNumeroPrestamo(int noPres) {
    numeroPrestamo = noPres;
}

Cliente *Prestamo::getCliente() {
    return cliente;
}

void Prestamo::setCliente(Cliente *cl) {
    cliente = cl;
}

void Prestamo::setFechaAprobacion(Fecha *fecApro) {
    fechaAprobacion = fecApro;
}

Fecha *Prestamo::getFechaAprobacion() {
    return fechaAprobacion;
}

void Prestamo::setMontoAprobado(float montApro) {
    montoAprobado = montApro;
}

float Prestamo::getMontoAprobado() {
    return montoAprobado;
}

bool Prestamo::HacerPago(Pago *pg) {
    bool retorno = false;
    if(this -> contPagos < DIM){
        this -> lstPagos[this -> contPagos] - pg;
        this -> contPagos++;
        this -> saldoPendiente -= pg -> getMontoPago();
        retorno = true;
    }
    return retorno;
}

Pago **Prestamo::getLstPagos() {
    return lstPagos;
}

float Prestamo::getSaldoPendiente() {
    return saldoPendiente;
}

int Prestamo::getContPagos() {
    return contPagos;
}
