#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;



TEST(test2, viajeDesordenado){
    gps p1 = puntoGps(-15, -16);
    gps p2 = desviarPunto(p1, 2000, 0);
    gps p3 = desviarPunto(p2, 2000, 0);
    gps p4 = desviarPunto(p3, 2000, 0);

    viaje v = {medicion(1.6, p2),
               medicion(1.5, p1),
               medicion(1.7, p3),
               medicion( 1.8, p4)};

    EXPECT_NEAR(distanciaTotal(v), 6.0, 0.01);
}

