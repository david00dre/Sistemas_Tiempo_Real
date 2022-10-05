//Incluir la librería de utilización de hilos posix
#include <pthread.h>

/*
**********************************************************
********************** Clase hilo_t **********************
**********************************************************
*/

// AQUÍ IRÁ LA DEFINICIÓN DE LA CLASE hilo_t DEFINIDA EN LA PRÁCTICA P0_1


/*
**********************************************************
********************** Clase mutex_t *********************
**********************************************************
*/

//Definir la clase mutex_t
class mutex_t {
	//Parte privada
	private:
		//Definir un atributo de clase de tipo puntero a pthread_mutex_t. Este atributo será el manejador del mutex asociado a la clase
		
		//Definir un atributo de clase de tipo puntero a pthread_mutexattr_t para guardar los atributos de creación del mutex
		
	//Parte pública
	public:
		//Definir el constructor sin parámetros.
		
		//Definir el destructor sin parámetros.
		
		//Definir el método Inicializar sin parámetros y que retorne un entero.
		
		//Definir el método Lock sin parámetros y que retorna un entero.
		
		//Definir el método Unlock sin parámetros y que retorna un entero.
		
		//Definir el método ObtenerManejador sin parámetros y que retorna un puntero a pthread_mutex_t
		
};

/*
**********************************************************
*************** Clase variable_condicion_t ***************
**********************************************************
*/

//Definir la clase variable_condicion_t
class variable_condicion_t {
	//Parte privada
	private:
		//Definir un atributo de clase de tipo puntero a pthread_cond_t. Este atributo será el manejador de la variable de condición asociada a la clase.
		
		//Definir un atributo de clase de tipo puntero a pthread_mutexattr_t para guardar los atributos de creación de la variable de condición.
		
		//Definir un atributo de clase de tipo puntero a pthread_mutex_t para guardar el mutex al que se asociará la variable de condición.
		
	//Parte pública
	public:
		//Definir el constructor sin parámetros.
		
		//Definir el destructor sin parámetros.
		
		//Definir el método Inicializar sin parámetros y que retorne un entero.
		
		//Definir el método Inicializar con un parámetro de tipo puntero a pthread_mutex_t y que retorne un entero.
		
		//Definir el método AsociarManejadorMutex con un parámetro de tipo puntero a pthread_mutex_t y que no retorne nada.
		
		//Definir el método Wait sin parámetros y que retorna un entero.
		
		//Definir el método TimedWait con un parámetro de tipo struct timespec y que retorna un entero.
		
		//Definir el método Signal sin parámetros y que retorna un entero.
		
		//Definir el método Broadcast sin parámetros y que retorna un entero.
		
};