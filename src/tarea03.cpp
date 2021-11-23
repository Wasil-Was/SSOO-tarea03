#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void signalController(int signum){		//Funcion para administrar las señales de detencion
	switch(signum){
		case SIGUSR1:
			exit(EXIT_SUCCESS);
			break;
		case SIGUSR2:
			exit(EXIT_SUCCESS);
			break;
		case SIGTERM:
			std::cout << "Acción denegada.\n";
			break;
		case SIGPIPE:
			std::cout << "Acción denegada.\n";
			break;
		case SIGBUS:
			std::cout << "Acción denegada.\n";
			break;
		case SIGQUIT:
			std::cout << "Acción denegada.\n";
			break;
		case SIGINT:
			std::cout << "Acción denegada.\n";
			break;
		case SIGTSTP:
			std::cout << "Acción denegada.\n";
			break;
		default:
			break;
	}
}

int main(int argc, char** argv){
	//Registra la señal y la función de administración
	signal(SIGUSR1,signalController);
	signal(SIGUSR2,signalController);
	signal(SIGTERM,signalController);
	signal(SIGPIPE,signalController);
	signal(SIGBUS,signalController);
	signal(SIGQUIT,signalController);
	signal(SIGINT,signalController);
	signal(SIGTSTP,signalController);
	int result = fork();	//Fork
	int serie = 1;
	uint32_t v1 = 0, v2 = 1, n;
	for (int i = 0; i < 50; i++){
		if(result > 0){		//Codigo Padre
			std::this_thread::sleep_for(std::chrono::milliseconds(800));
			//Calculo Fibonacci
			std::cout << "Valor Fibonacci: "<< v1 <<" - PID = "<< getpid() << "\n";
			n = v1 + v2;
			v1 = v2;
			v2 = n;
		}
		else if(result == 0) {		//Codigo Hijo
			std::this_thread::sleep_for(std::chrono::milliseconds(1200));
			//Calculo Numeros Impares
			std::cout << "Valor Impar: "<< serie <<" - PID = "<< getpid() << "\n";
			serie = serie + 2;
		}
		else if (result == -1) {
			perror("Fallo en fork");
			exit(EXIT_FAILURE);
		}
	}
}
