/*
 * main.c
 *
 *  Created on: 28 feb. 2019
 *      Author: utnso
 */

#include "tp0.h"
#include "utils.h"
#include <readline/readline.h>

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	logger = iniciar_logger();

	log_info(logger, "Soy un log!\n");

	config = leer_config();

	ip = config_get_string_value(config,"IP");
	puerto = config_get_string_value(config,"PUERTO");
	valor = config_get_string_value(config,"CLAVE");

	log_info(logger,"Lei la IP: %s\n",ip);
	log_info(logger,"Lei el puerto:%s\n",puerto);
	log_info(logger,"Lei la clave: %s\n",valor);

	leer_consola(logger);


	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	//antes de continuar, tenemos que asegurarnos que el servidor esté corriendo porque lo necesitaremos para lo que sigue.

	//crear conexion
	conexion = crear_conexion(ip,puerto);
	//enviar CLAVE al servidor
	enviar_mensaje(valor,conexion);

	terminar_programa(conexion, logger, config);
}

t_log* iniciar_logger(void)
{
	t_log *logger;
	logger = log_create("tp0.log","TP0",1,LOG_LEVEL_INFO);

	if(logger == NULL){
		printf("No se pudo iniciar el logger \n");
		exit(1);
	}
	return logger;
}

t_config* leer_config(void)
{
	t_config *config;
	config = config_create("./tp0.config");
	if(config == NULL){
		printf("No se pudo leer la config");
		exit(2);
	}
	return config;
}

void leer_consola(t_log* logger)
{
	char* leido;

	while(strncmp(leido, "",1)!=0){
		log_info(logger,leido);
		free(leido);
		leido = readline(">");
	}

	free(leido);

}

void paquete(int conexion)
{
	//Ahora toca lo divertido!

	char* leido;
	t_paquete* paquete;


}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{

	if(logger != NULL){
		log_destroy(logger);
	}

	if(config != NULL){
		config_destroy(config);
	}

	liberar_conexion(conexion);
}
