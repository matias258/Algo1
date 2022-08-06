#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

vector<viaje> g = {{
                           medicion(1.5,puntoGps(2.5, 2.89996)),
                           medicion(1.9,puntoGps(2.5, 2.89997)),
                           medicion(1.7,puntoGps(2.5, 2.89998))},
                   {
                           medicion(2.5,puntoGps(2.5, 2.89996)),
                           medicion(2.6,puntoGps(2.5, 2.89997)),
                           medicion(2.7,puntoGps(2.5, 2.89998))},
                   {
                           medicion(0.5,puntoGps(2.5, 2.89996)),
                           medicion(0.6,puntoGps(2.5, 2.89997)),
                           medicion(0.7,puntoGps(2.5, 2.89998))},
};

TEST(test4, todosAntesDeFranja){
    EXPECT_EQ(flota(g,3.0,5.0),0);
}

TEST(test4, AlgunosAdentro){
    EXPECT_EQ(flota(g, 1.8,2.55),2);
}

TEST(test4, todosAdentro){
    EXPECT_EQ(flota(g, 0.5, 2.7), 3);
}