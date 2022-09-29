#include "ClasesPosix.h"
#include "Identificador.h"
#include <stdio.h>

Identificador_t Identificador;

/*
**********************************************************
********************** Clase hilo_t **********************
**********************************************************
*/

//Implementación del constructor sin parámetros. Este método reservará memoria para los atributos de la clase e inicializará los atributos de creación del hilo
hilo_t:: hilo_t() {

    //Guardar el resultado de Identificador.ObtenerId() en el atributo de clase que almacena el identificador del hilo
    Id = Identificador.ObtenerId();

    //Reserva de memoria para el manejador del hilo
    Manejador = new pthread_t ;

    //Reserva de memoria para los atributos de creación del hilo
    Atributos = new pthread_attr_t;

    //Inicialización de los atributos de creación del hilo
    pthread_attr_init(Atributos);

    //Inicialización de la función del hilo a NULL
    Funcion =NULL;

    //Inicialización de los datos de la función del hilo a NULL
    Dato=NULL;

//fin del constructor
}


//Implementación del destructor sin parámetros. Este método destruirá los atributos de creación del hilo y liberará la memoria de los atributos de la clase
hilo_t::~hilo_t() {

    //Liberación la memoria del manejador del hilo
    delete Manejador;

    //Destrucción de los atributos de creación del hilo
    pthread_attr_destroy(Atributos);

    //Liberación de memoria de los atributos de creación del hilo
    delete Atributos;

//Fin del destructor
}

//Implementación del método Lanzar. Este método se encargará de lanzar un hilo usando la función y los datos almacenados en la clase
int hilo_t::Lanzar() {

    //Si la función asociada existe (no es NULL)
    if ((Funcion!=NULL)) {

        /*Crear un hilo usando como parámetros el manejador del hilo, los atributos de creación del hilo, la función del hilo y los datos del hilo.
        Se devolverá el resultado de la llamada a pthread_create*/
        return pthread_create(Manejador,Atributos , Funcion, Dato);
    }

    //Si la función asociada no existe


    //Devolver -1
    return -1;

//Fin de Lanzar
}

//Implementación del método AsignarFuncion. Asignará el parámetro recibido al atributo que almacena la función del hilo
void hilo_t::AsignarFuncion(void *(*funcion)(void *)) {
    //Asignar el parámetro del método al atributo de la clase que almacena la función asociada
    Funcion = funcion;

//Fin de AsignarFuncion
}

//Implementación del método AsignarDato. Asignará el parámetro recibido al atributo que almacena los datos que se usarán con la función del hilo
void hilo_t::AsignarDato(void *dato) {
    //Asignar el parámetro del método al atributo de la clase que almacena el parámetro que se usará con la función asociada
    Dato = dato;

//fin de AsignarDato
}

//Implementación del método AsignarFuncionYDato. Este método llamará a los métodos AsignarFuncion y AsignarDato con cada uno de sus parámetros
void hilo_t::AsignarFuncionYDato(void *(*funcion)(void *), void *dato) {
    //Llamar a AsignarFuncion
    AsignarFuncion(funcion);

    AsignarDato(dato);

//Fin de AsignarFuncionYDato
}

//Implementación del método Join sin parámetros. Este método esperará por el hilo indicado por el manejador de la clase y retornará el valor devuelto por dicho hilo.
void *hilo_t::Join() {
    //Definir una variable de tipo puntero a void (debe ser puntero a void para permitir que se pueda devolver cualquier tipo de dato). No hay que reservar memoria.
    void *valor;

    /*Esperar por el hilo asociado a la clase usando como parámetros el valor del manejador del hilo (como es un puntero, hay que poner el carácter '*' delante del nombre para acceder a su valor)
    y la dirección de memoria de la variable definida en la línea anterior (poner el carácter '&' antes del nombre de la variable para acceder a su dirección de memoria).*/
    pthread_join(*Manejador, &valor);

    //Devolver la variable definida en la primera línea del método.
    return valor;

//Fin de Join
}

//Implementación de método ObtenerManejador sin parámetros. Este método devolverá el valor del manejador del hilo asociado a la clase.
pthread_t hilo_t::ObtenerManejador() {
    //Devolver el valor del manejador del hilo (como es un puntero, hay que poner el carácter '*' delante del nombre para acceder a su valor)
    return *Manejador;

//Fin de ObtenerManejador
}

//Implementación de método ObtenerIdentificaror sin parámetros. Este método devolverá el valor del identificador del hilo asociado a la clase.
int hilo_t::ObtenerIdentificador() {
    //Devolver el identificador del hilo
    return Id;
//Fin de ObtenerIdentificaror
}
