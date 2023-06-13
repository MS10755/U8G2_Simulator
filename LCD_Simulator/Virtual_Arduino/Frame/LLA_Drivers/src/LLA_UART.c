/*
 * @Description: 
 * @Autor: Juan
 * @Date: 2022-04-01 14:49:54
 * @LastEditors: Juan
 * @LastEditTime: 2022-04-01 15:36:32
 */
#include "LLA_Drivers.h"

/************************ LLA Interface headers includes ****************************/
/* Chip SDK headers includes */


/************************ User type define ****************************/

/************************ User user variables ****************************/


/************************ LLA common micro define ****************************/


/************************ LLA common variables ****************************/
int LLA_UART_Printf(UART_name_t name,const char *__restrict __format, ...){


	return 0;
}



/************************ LLA common function ****************************/


/************************ LLA Interface function ****************************/


/**
 * @description: 
 * @param {UART_name_t} name
 * @param {uint32_t} baudRate
 * @param {UART_config_t} config
 * @return {*}
 * @author: Your name
 */
void LLA_UART_Init(UART_name_t name,uint32_t baudRate,UART_config_t config){

	
}

/**
 * @description: 
 * @param {UART_name_t} name
 * @return {*}
 * @author: Your name
 */
void LLA_UART_DeInit(UART_name_t name){
	
}


/**
 * @description: 
 * @param {UART_name_t} name
 * @param {uint8_t} data
 * @return {*}
 * @author: Your name
 */
void LLA_UART_Write(UART_name_t name,uint8_t data){
	putchar(data);
}


/**
 * @description: 
 * @param {UART_name_t} name
 * @param {uint8_t} *data
 * @param {uint16_t} len
 * @return {*}
 * @author: Your name
 */
void LLA_UART_WriteBuffer(UART_name_t name,uint8_t *data,uint16_t len){
	
}

/************************ Your Interrupt handling function ****************************/
