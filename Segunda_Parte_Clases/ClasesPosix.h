//Incluir la librería de utilización de hilos posix
#include <pthread.h>

/*
**********************************************************
********************** Clase hilo_t **********************
**********************************************************
*/

// AQUÍ IRÁ LA DEFINICIÓN DE LA CLASE hilo_t DEFINIDA EN LA PRÁCTICA P0_1
class hilo_t
{
	//Parte privada
	private:
		//Definir un atributo de clase de tipo entero para almacenar el identificador del hilo
        int Id;
		
		//Definir un atributo de clase de tipo puntero a pthread_t. Este atributo será el manejador del hilo asociado a la clase
		pthread_t *Manejador;

		//Definir un atributo de clase de tipo puntero a pthread_attr_t para guardar los atributos de creación del hilo
		pthread_attr_t *Atributos;

		/*Definir un atributo de clase para almacenar la función asignada al hilo. La definición debe cumplir el formato de *(*Atributo)(void *),
		donde Atributo es el nombre que se le dará al atributo de la clase (se recomienda usar nombres descriptivos y no dejar Atributo como nombre)*/
        void *(*Funcion)(void *);
		
		//Definir un atributo de clase de tipo puntero a void para almacenar los datos enviados a la función
        void *Dato;
		
	//Parte pública
	public:
		//Definir el constructor sin parámetros.
        hilo_t();
		
		//Definir el destructor sin parámetros.
        ~hilo_t();

		//Definir el método Lanzar sin parámetros y que retorna un entero
		int Lanzar();

		/*Definir el método AsignarFuncion con un parámetro que será la función que utilice el hilo. La definición debe cumplir el formato *(*Atributo)(void *),
		donde Atributo es el nombre que se le dará al atributo de la función (se recomienda usar nombres descriptivos y no dejar Atributo como nombre).
		La función no devuelve ningún dato. */
        void AsignarFuncion(void *(*funcion)(void *));
		
		/*Definir el método AsignarDato con un parámetro de tipo puntero a void que será el dato que se usará con la función que utilice el hilo.
		La función no devuelve ningún dato. */
        void AsignarDato(void *dato );
		
		/*Definir el método AsignarFuncionYDato con dos parámetros, uno con la función que usará el hilo y el otro con el dato que usará dicha función
		(misma definición que en los métodos AsignarFuncion y AsignarDato). La función no devuelve ningún dato.*/
        void AsignarFuncionYDato(void *(*funcion)(void *), void *dato);
		
		//Definir el método Join sin parámetros y que devuelva un puntero a void.
        void* Join();
		
		//Definir el método ObtenerManejador sin parámetros y que devuelva el manejador del hilo (pthread_t), no el puntero al manejador.
        pthread_t ObtenerManejador();
		
		//Definir el método ObtenerIdentificador sin parámetros y que devuelva el identificador del hilo (int).
        int ObtenerIdentificador();
		
};

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
		pthread_mutex_t* mutex;
		
		//Definir un atributo de clase de tipo puntero a pthread_mutexattr_t para guardar los atributos de creación del mutex
		pthread_mutexattr_t* attr;
		
	//Parte pública
	public:
		//Definir el constructor sin parámetros.
		mutex_t();
		
		//Definir el destructor sin parámetros.
		~mutex_t();
		
		//Definir el método Inicializar sin parámetros y que retorne un entero.
		int Inicializar();
		
		//Definir el método Lock sin parámetros y que retorna un entero.
		int Lock();
		
		//Definir el método Unlock sin parámetros y que retorna un entero.
		int Unlock();
		
		//Definir el método ObtenerManejador sin parámetros y que retorna un puntero a pthread_mutex_t
		pthread_mutex_t* ObtenerManejador();
		
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
		pthread_cond_t* cond;
		
		//Definir un atributo de clase de tipo puntero a pthread_mutexattr_t para guardar los atributos de creación de la variable de condición.
		pthread_condattr_t* attr;
		
		//Definir un atributo de clase de tipo puntero a pthread_mutex_t para guardar el mutex al que se asociará la variable de condición.
		pthread_mutex_t* mutex;
		
	//Parte pública
	public:
		//Definir el constructor sin parámetros.
		variable_condicion_t();
		
		//Definir el destructor sin parámetros.
		~variable_condicion_t();
		
		//Definir el método Inicializar sin parámetros y que retorne un entero.
		int Inicializar();
		
		//Definir el método Inicializar con un parámetro de tipo puntero a pthread_mutex_t y que retorne un entero.
		int Inicializar(pthread_mutex_t* m);
		
		//Definir el método AsociarManejadorMutex con un parámetro de tipo puntero a pthread_mutex_t y que no retorne nada.
		void AsociarManejadorMutex(pthread_mutex_t* m);
		
		//Definir el método Wait sin parámetros y que retorna un entero.
		int Wait();
		
		//Definir el método TimedWait con un parámetro de tipo struct timespec y que retorna un entero.
		int TimedWait(struct timespec abstime);

		//Definir el método Signal sin parámetros y que retorna un entero.
		int Signal();
		
		//Definir el método Broadcast sin parámetros y que retorna un entero.
		int Broadcast();
		
};
