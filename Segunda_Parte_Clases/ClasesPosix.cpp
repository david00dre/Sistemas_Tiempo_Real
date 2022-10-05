#include "ClasesPosix.h"
#include "Identificador.h"
#include <stdio.h>

Identificador_t Identificador;

/*
**********************************************************
********************** Clase hilo_t **********************
**********************************************************
*/

// AQUÍ IRÁ LA IMPLEMENTACIÓN DE LA CLASE hilo_t DEFINIDA EN LA PRÁCTICA P0_1
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

/*
**********************************************************
********************** Clase mutex_t *********************
**********************************************************
*/

//Implementación del constructor sin parámetros. Este método reservará memoria para los atributos de la clase e inicializará los atributos de creación del mutex
mutex_t::mutex_t(){

	//Reserva de memoria para el manejador del mutex de la clase
	mutex = new pthread_mutex_t;
	//Reserva de memoria para los atributos de creación del mutex
	attr = new pthread_mutexattr_t;
	//Inicialización de los atributos de creación del mutex
	pthread_mutexattr_init(attr);
//fin del constructor
}

//Implementación del destructor sin parámetros. Este método liberará la memoria de los atributos de la clase y destruirá el mutex y los atributos de creación del mutex
mutex_t::~mutex_t(){
	//Destrucción del mutex
	pthread_mutex_destroy(mutex);
	//Liberación de memoria para el manejador del mutex de la clase
	delete mutex;
	//Destrucción de los atributos de creación del mutex
	pthread_mutexattr_destroy(attr);
	//Liberación de memoria para los atributos de creación del mutex
	delete attr;
//fin del destructor
}

//Implementación del método Inicializar sin parámetros. Este método se encargará de inicializar el mutex usando los atributos de creación del mutex
int mutex_t::Inicializar(){
	/*Inicializar el mutex asociado a la clase usando como parámetros el manejador del mutex y los atributos de creación del mutex.
	Debe retornar el valor que devuelva la función pthread_mutex_init*/
	return pthread_mutex_init(mutex, attr);
	
//Fin de Inicializar
}

//Implementación del método Lock sin parámetros. Este método se encargará de acceder al mutex asociado a la clase usando el manejador del mutex de la clase
int mutex_t::Lock(){
	//Acceder al mutex con el manejador de la clase. Debe retornar el valor devuelto por dicha función.
	return pthread_mutex_lock(mutex);
	
//Fin de Lock
}

//Implementación del método Unlock sin parámetros. Este método se encargará de liberar el mutex asociado a la clase usando el manejador del mutex de la clase
int mutex_t::Unlock(){

	//Liberar el mutex asociado a la clase usando como parámetro el manejador del mutex. Debe retornar el valor devuelto por dicha función.
	return pthread_mutex_unlock(mutex);
	
//Fin de Unlock
}

//Implementación del método ObtenerManejador sin parámetros. Este método se encargará devolver el manejador del mutex de la clase
pthread_mutex_t* mutex_t::ObtenerManejador(){
	//Devolver el manejador del mutex de la clase
	return mutex;
//Fin de ObtenerManejador
}

/*
**********************************************************
*************** Clase variable_condicion_t ***************
**********************************************************
*/

//Implementación del constructor sin parámetros. Este método reservará memoria para los atributos de la clase e inicializará los atributos de creación de la variable de condición
variable_condicion_t::variable_condicion_t(){
	//Reserva de memoria para el manejador de la variable de condición de la clase
	cond = new pthread_cond_t;
	//Reserva de memoria para los atributos de creación de la variable de condición
	attr = new pthread_condattr_t;
	//Inicialización de los atributos de creación de la variable de condición
	pthread_condattr_init(attr);
//Fin del constructor
}

/*Implementación del destructor sin parámetros. Este método destruirá la variable de condición y los atributos de creación de la variable de condición
y liberará la memoria de los atributos de la clase*/
variable_condicion_t::~variable_condicion_t(){
	//Destrucción de la variable de condición
	pthread_cond_destroy(cond);
	//Liberación de memoria para el manejador de la variable de condición de la clase
	delete cond;
	//Destrucción de los atributos de creación de la variable de condición
	pthread_condattr_destroy(attr);
	//Liberación de memoria para los atributos de creación de la variable de condición
	delete attr;
//Fin del destructor
}

//Implementación del método Inicializar sin parámetros. Este método se encargará de inicializar la variable de condición usando los atributos de creación la variable de condición
int variable_condicion_t::Inicializar(){
	/*Inicializar la variable de condición usando los atributos de clase manejador y atributos de creación la variable de condición.
	Debe retornar el valor que devuelva dicha función*/
	return pthread_cond_init(cond, attr);
	
//Fin de Inicializar
}

/*Implementación del método Inicializar con un parámetro de tipo puntero a pthread_mutex_t. Este método se encargará de asociar el mutex recibido por parámetro a la clase
(usar el método AsociarManejadorMutex) así como de inicializar la variable de condición usando los atributos de creación la variable de condición*/
int variable_condicion_t::Inicializar(pthread_mutex_t* m){
	//Llamar a AsociarManejadorMutex con el parámetro de entrada.
	AsociarManejadorMutex(m);
	/*Inicializar la variable de condición usando los atributos de clase manejador y atributos de creación la variable de condición.
	Debe retornar el valor que devuelva dicha función*/
	return Inicializar();
//Fin de inicializar
}

/*Implementación del método AsociarManejadorMutex con un parámetro de tipo puntero a pthread_mutex_t. Este método se encargará de asignar el parámetro de entrada al
atributo de la clase que va a almacenar el mutex asociado. No es necesario reservar memoria para dicho atributo ya que, aunque es un puntero, también lo es el
parámetro de entrada. Al ser ambas variables punteros, el mutex asociado y el parámetro de entrada acabarán apuntando a la misma dirección de memoria.*/
void variable_condicion_t::AsociarManejadorMutex(pthread_mutex_t* m){
	//Asignar el parámetro de entrada al parámetro que almacenará el mutex asociado.
	mutex = m;
//Fin de AsociarManejadorMutex
}

//Implementación del método Wait sin parámetros. Este método se encargará de bloquear el hilo invocante en la variable de condición de la clase.
int variable_condicion_t::Wait(){
	/*Llamar a la función de bloqueo en una variable de condición con los atributos de la clase manejador de la variable de condición y mutex asociado.
	El método retornará el valor que devuelva dicha función.*/
	return pthread_cond_wait(cond, mutex);
//Fin de Wait
}

/*Implementación del método TimedWait con un parámetro de tipo struct timespec. Este método se encargará de bloquear el hilo en la variable de condición de la clase
como máximo hasta el instante indicado por el parámetro de entrada.*/
int variable_condicion_t::TimedWait(struct timespec abstime){
	/*Llamar a la función de bloqueo en una variable de cindición con límite temporal con los atributos de la clase manejador de la variable de condición, el mutex asociado
	junto con el paránetro de entrada. El método retornará el valor que devuelva dicha función.*/
	return pthread_cond_timedwait(cond, mutex, &abstime);
//Fin de TimedWait
}

//Implementación del método Signal sin parámetros. Este método se encargará de liberar (al menos) un hilo bloqueado en la variable de condición de la clase.
int variable_condicion_t::Signal(){
	/*Llamar a la función de liberación de (al menos) un hilo bloqueado en la variable de condición con el atributo de la clase manejador de la variable.
	El método retornará el valor que devuelva dicha función.*/
	return pthread_cond_signal(cond);
//Fin de Signal
}

//Implementación del método Broadcast sin parámetros. Este método se encargará de liberar todos los hilos bloqueados en la variable de condición de la clase.
int variable_condicion_t::Broadcast(){
	/*Llamar a la de liberación de todos los hilos bloqueados en cla variable de condición de la clase con el atributo de la clase manejador de la variable de condición.
	El método retornará el valor que devuelva dicha función.*/
	return pthread_cond_broadcast(cond);
//Fin de Broadcast
}
