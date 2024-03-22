#include "Pago.h"
#include <iostream>
using namespace std;

Pago::Pago(Fecha *fecPag, float montPag) : fechaPago(fecPag), montoPago(montPag){

}

Fecha *Pago::getFechaPago(){
    return fechaPago;
}

Pago::~Pago(){

}

float Pago::getMontoPago(){
    return montoPago;
}
