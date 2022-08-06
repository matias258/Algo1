#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(test8, DoscercanosALaDerecha){
    viaje v = {medicion(T0+0, puntoGps(1.000000, 1.000000)),
               medicion(T0+1, puntoGps(2.000000, 2.0000000)),
               medicion(T0+2, puntoGps(3.000000, 3.0000000)),
               medicion(T0+6, puntoGps(0.0, 0.0)),
               medicion(T0+7, puntoGps(5.000000, 5.000000)),
               medicion(T0+8, puntoGps(6.000000, 6.000000))};

    viaje res = {medicion(T0+0, puntoGps(1.000000, 1.000000)),
                 medicion(T0+1, puntoGps(2.000000, 2.000000)),
                 medicion(T0+2, puntoGps(3.000000, 3.000000)),
                 medicion(T0+6, puntoGps(4.000000, 4.000000)),
                 medicion(T0+7, puntoGps(5.000000, 5.000000)),
                 medicion(T0+8, puntoGps(6.000000, 6.000000))};
    vector<tiempo> errores = {T0+6};

    corregirViaje(v, errores);
    EXPECT_EQ(v.size(),res.size());

    for (int i = 0; i < res.size(); ++i) {
        EXPECT_NEAR(obtenerLatitud(obtenerPosicion(v[i])),
                    obtenerLatitud(obtenerPosicion(res[i])), 0.00001);
        EXPECT_NEAR(obtenerLongitud(obtenerPosicion(v[i])),
                    obtenerLongitud(obtenerPosicion(res[i])), 0.00001);
        EXPECT_EQ(obtenerTiempo(v[i]),obtenerTiempo(res[i]));
    }
}

TEST(test8, DosErroresSeguidos){
    viaje v = {medicion(T0+0, puntoGps(1.000000, 1.000000)),
               medicion(T0+1, puntoGps(2.000000, 2.0000000)),
               medicion(T0+2, puntoGps(3.000000, 3.0000000)),
               medicion(T0+6, puntoGps(0.000000, 0.000000)),
               medicion(T0+7, puntoGps(1.000000, 1.000000)),
               medicion(T0+8, puntoGps(6.000000, 6.000000)),
               medicion(T0+20, puntoGps(6.000000, 6.000000))};

    viaje res = {medicion(T0+0, puntoGps(1.000000, 1.000000)),
                 medicion(T0+1, puntoGps(2.000000, 2.000000)),
                 medicion(T0+2, puntoGps(3.000000, 3.000000)),
                 medicion(T0+6, puntoGps(5.000000, 5.000000)),
                 medicion(T0+7, puntoGps(5.500000, 5.500000)),
                 medicion(T0+8, puntoGps(6.000000, 6.000000)),
                 medicion(T0+20, puntoGps(6.000000, 6.000000))};
    vector<tiempo> errores = {T0+6, T0+7};

    corregirViaje(v, errores);
    EXPECT_EQ(v.size(),res.size());

    for (int i = 0; i < res.size(); ++i) {
        EXPECT_NEAR(obtenerLatitud(obtenerPosicion(v[i])),
                    obtenerLatitud(obtenerPosicion(res[i])), 0.00001);
        EXPECT_NEAR(obtenerLongitud(obtenerPosicion(v[i])),
                    obtenerLongitud(obtenerPosicion(res[i])), 0.00001);
        EXPECT_EQ(obtenerTiempo(v[i]),obtenerTiempo(res[i]));
    }
}