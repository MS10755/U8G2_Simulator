/*
 * @Description: 
 * @Autor: Juan
 * @Date: 2022-04-01 14:49:54
 * @LastEditors: Juan
 * @LastEditTime: 2022-04-01 15:25:18
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
/**
 * @description: 
 * @param {BaseIO_name_t} dataPin
 * @param {BaseIO_name_t} clockPin
 * @param {LLA_BitOrder_t} bitOrder
 * @return {*}
 * @author: Juan
 */
uint8_t LLA_AdvanceIO_ShiftIn(BaseIO_name_t dataPin, BaseIO_name_t clockPin, LLA_BitOrder_t bitOrder) {
	
	return 0;
}

/**
 * @description: 
 * @param {BaseIO_name_t} dataPin
 * @param {BaseIO_name_t} clockPin
 * @param {LLA_BitOrder_t} bitOrder
 * @param {uint8_t} val
 * @return {*}
 * @author: Juan
 */
void LLA_AdvanceIO_ShiftOut(BaseIO_name_t dataPin, BaseIO_name_t clockPin, LLA_BitOrder_t bitOrder, uint8_t val)
{

}

/************************ LLA Interface function ****************************/

/**
 * @description: 
 * @param {BaseIO_name_t} name: 
 * @param {AdvanceIO_PWC_t} pwc
 * @param {BaseIO_status_t} idle_status
 * @param {uint32_t} time_out
 * @return {*}
 * @author: Your name
 */
uint32_t LLA_AdvanceIO_PluseMeasure(BaseIO_name_t name,AdvanceIO_PWC_t pwc,BaseIO_status_t idle_status,uint32_t time_out){
	
	
	return 0;
}



/************************ Your Interrupt handling function ****************************/
