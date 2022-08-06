#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

template<typename T>
bool included(T elem, vector<T> container){
    for (int i = 0; i < container.size(); ++i) {
        if (container[i] == elem){return true;}
    }
    return false;
}

using namespace std;

const gps M = puntoGps(10, 12);


const recorrido J = {M,
                     desviarPunto(M, 100000000, 0),
                     desviarPunto(M, 2000000, 0),
                     desviarPunto(M, 300000, 0),
                     desviarPunto(M, 4000, 0),
                     desviarPunto(M, 5000, 0),
                     desviarPunto(M, 6000, 0),
                     desviarPunto(M, 70000, 0),
                     desviarPunto(M, 80000, 0),
                     desviarPunto(M, 90000, 0),
};


const viaje G = {
        medicion(0, puntoGps(1, 0)),
        medicion(5, puntoGps(2, 0)),
        medicion(10, puntoGps(3, 0)),
        medicion(15, puntoGps(4, 0)),
        medicion(20, puntoGps(5, 0)),
        medicion(25, puntoGps(6, 0))};


TEST(test5, ningunoCubierto){
    EXPECT_EQ(recorridoNoCubierto(G, J, 1).size(), 10);
    EXPECT_EQ(recorridoNoCubierto(G, J, 1), J);
}