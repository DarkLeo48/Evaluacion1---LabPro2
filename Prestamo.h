#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED
#include <string.h>
#include "Cliente.h"
#include "Pago.h"
#define DIM 5

class Prestamo {
    private:
        int numeroPrestamo, contPagos;
        Cliente *cliente;
        Fecha *fechaAprobacion;
        float montoAprobado, saldoPendiente;
        Pago *lstPagos[DIM];

    public:
        Prestamo();
        Prestamo(int noPres, Cliente *cl, Fecha *fecApro, float montoApro);
        ~Prestamo();

        int getNumeroPrestamo();
        void setNumeroPrestamo(int noPres);

        Cliente *getCliente();
        void setCliente(Cliente *cl);

        void setFechaAprobacion(Fecha *fecApro);
        Fecha *getFechaAprobacion();

        void setMontoAprobado(float montApro);
        float getMontoAprobado();

        bool HacerPago(Pago *pg);

        Pago **getLstPagos();

        float getSaldoPendiente();

        int getContPagos();
};

#endif // PRESTAMO_H_INCLUDED
