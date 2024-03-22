#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), anio(a){

}

Fecha::~Fecha(){

}

void Fecha::MostrarFecha(){
    cout << dia << "/" << mes << "/" << anio << endl;
}
