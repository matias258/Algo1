#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(test7, unSalto){
gps p= puntoGps(0,0);
grilla g1 = construirGrilla(puntoGps(30,0), puntoGps(0,30), 3, 3);


gps p1 = puntoGps( 23, 1);
gps p2 = puntoGps(2,27);
gps p3 = puntoGps(5,15);

viaje v = {medicion(1, p1),
           medicion(2, p2),
           medicion(3, p3)};

EXPECT_EQ(cantidadDeSaltos(g1,v),1);
}


TEST(test7, dobleSaltoDiagonal){
    gps p= puntoGps(0,0);
    grilla g1 = construirGrilla(puntoGps(30,0), puntoGps(0,30), 3, 3);


    gps p1 = puntoGps( 23, 1);
    gps p2 = puntoGps(19, 11);
    gps p3 = puntoGps(2,27);
    gps p4 = puntoGps(5,15);

    viaje v = {medicion(1, p1),
               medicion(2, p2),
               medicion(3, p3),
               medicion(4, p4)};

    EXPECT_EQ(cantidadDeSaltos(g1,v),2);
}
