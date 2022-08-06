#include "ejercicios.h"
#include "auxiliares.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

/******++++**************************** EJERCICIO tiempoTotal ***********+++***********************/
tiempo tiempoTotal(viaje v) {
    tiempo max = obtenerTiempo(v[0]) ;
    tiempo min = obtenerTiempo(v[0]) ;
    for (int i = 0; i < v.size(); i++){
        if (min >= obtenerTiempo(v[i])){
            min = obtenerTiempo(v[i]);
        }
        if (max <= obtenerTiempo(v[i])){
            max = obtenerTiempo(v[i]);
        }
    }
    tiempo t = max - min;
    return t;
}

// Podemos decir que tiempoTotal es O(n) (suponiendo n = v.size()) pues tenemos solo un ciclo for que recorre toda la
// funcion (v.size()).

/************++*********************** EJERCICIO distanciaTotal ************++*********************/

distancia distanciaTotal(viaje v) {
    distancia d = 0;
    viaje vOrdenado = selectionSort(v); // O(n^2)
    for (int i = 0; i < v.size() - 1; i++){ // O(n)
        d = d + distEnKM(obtenerPosicion(vOrdenado[i]), obtenerPosicion(vOrdenado[i+1]));
    }
    return d;
}

// Podemos decir que distanciaTotal es O(n^2) (suponiendo n = v.size()) pues
// --> selectionSort es O(n^2): Tiene un solo ciclo for que recorre n veces el seleccionarMinimo.
// Para cada iteración, seleccionarMinimo itera n veces.
// --> Por lo tanto es O(n * n) = O(n^2)
// En cambio en distanciaTotal, tenemos un for que itera n veces, por lo tanto: O(n^2 + n) = O(n^2).

/*****************************+***** EJERCICIO excesoDeVelocidad **********************************/


double velocidad (tuple<tiempo, gps> p1, tuple<tiempo, gps> p2) {
    return (distEnKM(obtenerPosicion(p2),obtenerPosicion(p1))) / ((obtenerTiempo(p2) - (obtenerTiempo(p1))) / 3600);
}

bool superoVelocidad (tuple<tiempo, gps> p1, tuple<tiempo, gps> p2){
    bool res;
    if (velocidad(p1, p2) > 80.0) {
        res = true;
    } else {
        res = false;
    }
    return res;
}

bool excesoDeVelocidad(viaje v) {
    bool resp = false;
    viaje vOrdenado = selectionSort(v);
    for (int i = 1; i < v.size(); i++){

        if (superoVelocidad(vOrdenado[i-1], vOrdenado[i])) {
            resp = true;
        }
    }
    return resp;
}

/************************************ EJERCICIO recorridoNoCubierto *******************************/

vector<gps> recorridoNoCubierto(viaje v, recorrido r, distancia u) {
    recorrido resp;
    for (int i = 0; i < r.size(); i++){
        int cubierto = 0;
        for (int j = 0; j < v.size(); j++){
            if ((distEnKM(r[i], obtenerPosicion(v[j]))) < u){
                cubierto ++;
            }
        }
        if (cubierto == 0){
            resp.push_back(r[i]);
        }
    }
    return resp;
}

//Llamamos m = r.size(), n = v.size().
// El 1er "for" itera m veces el 2do "for". Este ultimo itera n veces.
// Lo que nos da un O(n * m).

/***************************************** EJERCICIO flota ***************************************/
bool viajeEnFranjaHoraria (viaje v, tiempo t0, tiempo tf){
    bool res;
    tiempo max = obtenerTiempo(v[0]) ;
    tiempo min = obtenerTiempo(v[0]) ;
    for (int i = 0; i < v.size(); i++){
        if (min >= obtenerTiempo(v[i])){
            min = obtenerTiempo(v[i]);
        }
        if (max <= obtenerTiempo(v[i])){
            max = obtenerTiempo(v[i]);
        }
    }
    if (max < t0 || min > tf){
        res = false;
    } else {
        res = true;
    }
    return res;
}



int flota(vector<viaje> f, tiempo t0, tiempo tf) {
    int resp = 0;
    for (int i = 0; i < f.size(); i++){
        if (viajeEnFranjaHoraria(f[i], t0, tf)){
            resp ++;
        }
    }
    return resp;
}

/************************************** EJERCICIO construirGrilla *******************************/

grilla construirGrilla(gps esq1, gps esq2, int n, int m) {
    grilla resp = {};
    double altoCelda = (obtenerLatitud(esq1) - obtenerLatitud(esq2)) / n;
    double anchoCelda = (obtenerLongitud(esq2) - obtenerLongitud(esq1)) / m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            nombre nombreCelda = make_tuple(i+1, j+1);
            gps gps0 = make_tuple(obtenerLatitud(esq1) - altoCelda * (get<0>(nombreCelda) - 1),
                                  obtenerLongitud(esq1) + anchoCelda * (get<1>(nombreCelda) - 1));
            gps gps1 = make_tuple(obtenerLatitud(gps0) - altoCelda,obtenerLongitud(gps0) + anchoCelda);
            tuple<gps, gps, nombre> celda = (make_tuple(gps0, gps1, nombreCelda));
            resp.push_back(celda);
        }

    }
    return resp;
}

/************************************* EJERCICIO cantidadDeSaltos ******************************/

bool seCorresponde (celda c, gps p){
    bool estaEntreLasLatitudes = obtenerLatitud(get<1>(c)) < obtenerLatitud(p) &&
            obtenerLatitud(p) <= obtenerLatitud(get<0>(c));
    bool estaEntreLasLongitudes = obtenerLongitud(get<0>(c)) <= obtenerLongitud(p) &&
            obtenerLongitud(p) < obtenerLongitud(get<1>(c));
    return estaEntreLasLatitudes && estaEntreLasLongitudes;
}
// seCorresponde nos dice si un punto gps está dentro de una celda.

nombre nombreGPS (grilla g, gps p) {
    nombre res;
    for (int i = 0; i < g.size(); i++) {
        if (seCorresponde(g[i], p)) {
            res = get<2>(g[i]);
        }
    }
    return res;
}
//nombreGPS nos devuelve el nombre de la celda en la que está el punto p.

bool esSalto(nombre a, nombre b){
    double res = sqrt(pow(get<0>(a)-get<0>(b),2)+pow(get<1>(a)-get<1>(b),2));
    return res > 1 ;
}

int cantidadDeSaltos(grilla g, viaje v) {
    int cantDeSaltos = 0;
    viaje vOrdenado = selectionSort(v);
    for (int i = 0; i < v.size() - 1; i++){
        if (esSalto(nombreGPS(g, get<1>(vOrdenado[i])), nombreGPS(g, get<1>(vOrdenado[i+1])))){
            cantDeSaltos++;
        }
    }
    return cantDeSaltos;
}



/************************************* EJERCICIO corregirViaje ******************************/


bool esError (tiempo t, vector<tiempo> errores){
    bool error = false;
    for (int i = 0; i < errores.size(); ++i) {
        if (errores[i] == t){
            error = true;
        }
    }
    return error;
}

viaje dosMasCercanosYCorrectos (viaje v, vector<tiempo> errores, tuple<tiempo,gps> p){ //tuple de??
    int masCercano = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (fabs(obtenerTiempo(p) - obtenerTiempo(v[i])) < fabs(obtenerTiempo(p) - obtenerTiempo(v[masCercano]))
            && obtenerPosicion(v[i]) != obtenerPosicion(p) && !esError(obtenerTiempo(v[i]), errores)){
            masCercano = i;
        }
    }
    int segundoMasCercano = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (fabs(obtenerTiempo(p) - obtenerTiempo(v[i])) < fabs(obtenerTiempo(p) - obtenerTiempo(v[segundoMasCercano]))
            && obtenerPosicion(v[i]) != obtenerPosicion(p) && !esError(obtenerTiempo(v[i]), errores) && i != masCercano){
            segundoMasCercano= i;
        }
    }
    viaje res;
    res.push_back(v[masCercano]);
    res.push_back(v[segundoMasCercano]);
    return res;
}

double nuevaLatitud (tuple<tiempo,gps> p1, tuple<tiempo,gps> p2){
    double velocidad = (get<0>(obtenerPosicion(p1)) - get<0>(obtenerPosicion(p2))) / ((obtenerTiempo(p1) - obtenerTiempo(p2)));
    return velocidad;
}

double nuevaLongitud (tuple<tiempo,gps> p1, tuple<tiempo,gps> p2){
    double velocidad = (get<1>(obtenerPosicion(p1)) - get<1>(obtenerPosicion(p2))) / ((obtenerTiempo(p1) - obtenerTiempo(p2)));
    return velocidad;
}

tuple<tiempo,gps> nuevoPunto (tuple<tiempo,gps> p, viaje v){
    int indiceMenor;
    int indiceMayor;
    if (get<0>(v[1]) < get<0>(v[0])){
        indiceMenor = 1;
        indiceMayor = 0;
    } else {
        indiceMenor = 0;
        indiceMayor = 1;
    }
    double latitud = obtenerLatitud(obtenerPosicion(v[indiceMenor]))
                     + nuevaLatitud(v[indiceMenor], v[indiceMayor]) * (obtenerTiempo(p) - obtenerTiempo(v[indiceMenor]));
    double longitud = obtenerLongitud(obtenerPosicion(v[indiceMenor]))
                      + nuevaLongitud(v[indiceMenor], v[indiceMayor]) * (obtenerTiempo(p) - obtenerTiempo(v[indiceMenor]));
    return make_tuple(obtenerTiempo(p), puntoGps(latitud, longitud));
}

void corregirViaje(viaje& v, vector<tiempo> errores){
    for (int i = 0; i < v.size(); i++){
        if (esError(get<0>(v[i]), errores)){
            v[i] = nuevoPunto(v[i], dosMasCercanosYCorrectos(v, errores, v[i]));
        }
    }

 }


