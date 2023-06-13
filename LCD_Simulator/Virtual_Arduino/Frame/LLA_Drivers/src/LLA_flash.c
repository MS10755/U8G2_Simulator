/*
 * @Description: 
 * @Autor: Juan
 * @Date: 2022-04-01 14:49:54
 * @LastEditors: Juan
 * @LastEditTime: 2022-04-01 15:29:54
 */
#include "LLA_Drivers.h"

/************************ LLA Interface headers includes ****************************/
/* Chip SDK headers includes */



/************************ User type define ****************************/


/************************ User user variables ****************************/


/************************ User micro define ****************************/



/************************ User static function ****************************/


/************************ LLA common micro define ****************************/

/************************ LLA common variables ****************************/


/************************ LLA common function ****************************/


/************************ LLA Interface function ****************************/

/**
 * @description: 
 * @param {*}
 * @return {*}
 * @author: Your name
 */
void LLA_Flash_Init(){
}

/**
 * @description: 
 * @param {uint32_t} offset
 * @param {uint32_t} len
 * @return {*}
 * @author: Your name
 */
uint8_t LLA_Flash_Erase(uint32_t offset,uint32_t len){
	
	return 0;
}

/**
 * @description: 
 * @param {uint32_t} offset
 * @param {uint8_t} *data
 * @param {uint32_t} len
 * @return {*}
 * @author: Your name
 */
uint8_t LLA_Flash_WriteBytes(uint32_t offset,uint8_t *data,uint32_t len){
	
	return 0;
}

/**
 * @description: 
 * @param {uint32_t} offset
 * @param {uint8_t} *data
 * @param {uint32_t} len
 * @return {*}
 * @author: Your name
 */
void LLA_Flash_ReadBytes(uint32_t offset,uint8_t *data,uint32_t len){
	
}

/**
 * @description: 
 * @param {*}
 * @return {*}
 * @author: Your name
 */
uint32_t LLA_Flash_GetSize(){
	return 0;
}
/************************ Your Interrupt handling function ****************************/


