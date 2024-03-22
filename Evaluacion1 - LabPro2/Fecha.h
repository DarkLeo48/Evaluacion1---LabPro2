#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha {
    private:
        int dia, mes, anio;
    public:
        Fecha(int d, int m, int a);
        ~Fecha();
        void MostrarFecha();
};

#endif // FECHA_H_INCLUDED
