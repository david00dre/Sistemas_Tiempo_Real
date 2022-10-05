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


/*
**********************************************************
********************** Clase mutex_t *********************
**********************************************************
*/

//Implementación del constructor sin parámetros. Este método reservará memoria para los atributos de la clase e inicializará los atributos de creación del mutex

	//Reserva de memoria para el manejador del mutex de la clase
	
	//Reserva de memoria para los atributos de creación del mutex
	
	//Inicialización de los atributos de creación del mutex
	
//fin del constructor


//Implementación del destructor sin parámetros. Este método liberará la memoria de los atributos de la clase y destruirá el mutex y los atributos de creación del mutex

	//Destrucción del mutex
	
	//Liberación de memoria para el manejador del mutex de la clase
	
	//Destrucción de los atributos de creación del mutex
	
	//Liberación de memoria para los atributos de creación del mutex
	
//fin del destructor


//Implementación del método Inicializar sin parámetros. Este método se encargará de inicializar el mutex usando los atributos de creación del mutex

	/*Inicializar el mutex asociado a la clase usando como parámetros el manejador del mutex y los atributos de creación del mutex.
	Debe retornar el valor que devuelva la función pthread_mutex_init*/
	
//Fin de Inicializar


//Implementación del método Lock sin parámetros. Este método se encargará de acceder al mutex asociado a la clase usando el manejador del mutex de la clase

	//Acceder al mutex con el manejador de la clase. Debe retornar el valor devuelto por dicha función.
	
//Fin de Lock


//Implementación del método Unlock sin parámetros. Este método se encargará de liberar el mutex asociado a la clase usando el manejador del mutex de la clase

	//Liberar el mutex asociado a la clase usando como parámetro el manejador del mutex. Debe retornar el valor devuelto por dicha función.
	
//Fin de Unlock


//Implementación del método ObtenerManejador sin parámetros. Este método se encargará devolver el manejador del mutex de la clase

	//Devolver el manejador del mutex de la clase
	
//Fin de ObtenerManejador


/*
**********************************************************
*************** Clase variable_condicion_t ***************
**********************************************************
*/

//Implementación del constructor sin parámetros. Este método reservará memoria para los atributos de la clase e inicializará los atributos de creación de la variable de condición

	//Reserva de memoria para el manejador de la variable de condición de la clase
	
	//Reserva de memoria para los atributos de creación de la variable de condición
	
	//Inicialización de los atributos de creación de la variable de condición
	
//Fin del constructor


/*Implementación del destructor sin parámetros. Este método destruirá la variable de condición y los atributos de creación de la variable de condición
y liberará la memoria de los atributos de la clase*/

	//Destrucción de la variable de condición
	
	//Liberación de memoria para el manejador de la variable de condición de la clase
	
	//Destrucción de los atributos de creación de la variable de condición
	
	//Liberación de memoria para los atributos de creación de la variable de condición
	
//Fin del destructor


//Implementación del método Inicializar sin parámetros. Este método se encargará de inicializar la variable de condición usando los atributos de creación la variable de condición

	/*Inicializar la variable de condición usando los atributos de clase manejador y atributos de creación la variable de condición.
	Debe retornar el valor que devuelva dicha función*/
	
//Fin de Inicializar


/*Implementación del método Inicializar con un parámetro de tipo puntero a pthread_mutex_t. Este método se encargará de asociar el mutex recibido por parámetro a la clase
(usar el método AsociarManejadorMutex) así como de inicializar la variable de condición usando los atributos de creación la variable de condición*/

	//Llamar a AsociarManejadorMutex con el parámetro de entrada.
	
	/*Inicializar la variable de condición usando los atributos de clase manejador y atributos de creación la variable de condición.
	Debe retornar el valor que devuelva dicha función*/
	
//Fin de inicializar


/*Implementación del método AsociarManejadorMutex con un parámetro de tipo puntero a pthread_mutex_t. Este método se encargará de asignar el parámetro de entrada al
atributo de la clase que va a almacenar el mutex asociado. No es necesario reservar memoria para dicho atributo ya que, aunque es un puntero, también lo es el
parámetro de entrada. Al ser ambas variables punteros, el mutex asociado y el parámetro de entrada acabarán apuntando a la misma dirección de memoria.*/

	//Asignar el parámetro de entrada al parámetro que almacenará el mutex asociado.
	
//Fin de AsociarManejadorMutex


//Implementación del método Wait sin parámetros. Este método se encargará de bloquear el hilo invocante en la variable de condición de la clase.

	/*Llamar a la función de bloqueo en una variable de condición con los atributos de la clase manejador de la variable de condición y mutex asociado.
	El método retornará el valor que devuelva dicha función.*/
	
//Fin de Wait


/*Implementación del método TimedWait con un parámetro de tipo struct timespec. Este método se encargará de bloquear el hilo en la variable de condición de la clase
como máximo hasta el instante indicado por el parámetro de entrada.*/

	/*Llamar a la función de bloqueo en una variable de cindición con límite temporal con los atributos de la clase manejador de la variable de condición, el mutex asociado
	junto con el paránetro de entrada. El método retornará el valor que devuelva dicha función.*/
	
//Fin de TimedWait


//Implementación del método Signal sin parámetros. Este método se encargará de liberar (al menos) un hilo bloqueado en la variable de condición de la clase.

	/*Llamar a la función de liberación de (al menos) un hilo bloqueado en la variable de condición con el atributo de la clase manejador de la variable.
	El método retornará el valor que devuelva dicha función.*/
	
//Fin de Signal


//Implementación del método Broadcast sin parámetros. Este método se encargará de liberar todos los hilos bloqueados en la variable de condición de la clase.

	/*Llamar a la de liberación de todos los hilos bloqueados en cla variable de condición de la clase con el atributo de la clase manejador de la variable de condición.
	El método retornará el valor que devuelva dicha función.*/
	
//Fin de Broadcast

