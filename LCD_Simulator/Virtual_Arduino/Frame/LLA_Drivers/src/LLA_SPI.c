/*
 * @Description: 
 * @Autor: Juan
 * @Date: 2022-04-01 14:49:54
 * @LastEditors: Juan
 * @LastEditTime: 2022-04-01 15:32:14
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
 * @param {LLA_SPI_t} spi
 * @param {uint32_t} clock
 * @param {LLA_SPI_Mode_t} mode
 * @param {LLA_SPI_CS_t} cs_mode
 * @return {*}
 * @author: Your name
 */
void LLA_SPI_Init(LLA_SPI_t spi,uint32_t clock,LLA_SPI_Mode_t mode,LLA_SPI_CS_t cs_mode){
	
	
}

/**
 * @description: 
 * @param {LLA_SPI_t} spi
 * @return {*}
 * @author: Your name
 */
void LLA_SPI_DeInit(LLA_SPI_t spi){
	
}

/**
 * @description: 
 * @param {LLA_SPI_t} spi
 * @param {uint8_t *} data
 * @param {uint32_t} len
 * @return {*}
 * @author: Your name
 */
void LLA_SPI_WriteBytes(LLA_SPI_t spi,uint8_t * data,uint32_t len){
	
}


/**
 * @description: 
 * @param {LLA_SPI_t} spi
 * @param {uint8_t *} buf
 * @param {uint32_t} len
 * @return {*}
 * @author: Your name
 */
void LLA_SPI_ReadBytes(LLA_SPI_t spi,uint8_t * buf,uint32_t len){

}

/************************ Your Interrupt handling function ****************************/


