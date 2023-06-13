#include "LLA_Drivers.h"

/************************ LLA Interface headers includes ****************************/
/* Chip SDK headers includes */
#include<Windows.h>

/************************ LLA Interface micro define ****************************/


/************************ LLA common micro define ****************************/




/************************ LLA common variables ****************************/
LARGE_INTEGER mcu_start_time;
LARGE_INTEGER f;	//¼ÆÊ±Æ÷ÆµÂÊ


/************************ LLA common function ****************************/

/**
 * @description: 
 * @param {uint32_t} pre_ms
 * @return {*}
 * @author: Your name
 */
uint32_t LLA_SYS_Time_ConsumeMillis(uint32_t pre_ms){
	uint32_t current_ms = LLA_SYS_Time_Millis();
	return current_ms>=pre_ms? (current_ms-pre_ms): (UINT32_MAX+current_ms-pre_ms);
}

/**
 * @description: 
 * @param {uint32_t} pre_us
 * @return {*}
 * @author: Your name
 */
uint32_t LLA_SYS_Time_ConsumeMicros(uint32_t pre_us){
	uint32_t current_us = LLA_SYS_Time_Micros();
	return current_us>=pre_us? (current_us-pre_us): (UINT32_MAX+current_us-pre_us);
}


/************************ LLA Interface function ****************************/
/**
  * @brief	:	Init System time clock. (you can use SystemTick or other Hardware timer on your chip.)
  * @param	: 
  * @param	: 
  * @retval	:	
  */
void LLA_SYS_Time_Init(){
	QueryPerformanceFrequency(&f);
	QueryPerformanceCounter(&mcu_start_time);
}


/**
  * @brief	:	Get System time in millisecond since system time clock initiation.
  * @param	: 
  * @param	: 
  * @retval	:	
  */
uint32_t LLA_SYS_Time_Millis(){
	return LLA_SYS_Time_Micros()/1000;
}


/**
  * @brief	:	Get System time in microsecond since system time clock initiation.
  * @param	: 
  * @param	: 
  * @retval	:	
  */
uint32_t LLA_SYS_Time_Micros(void)
{
	LARGE_INTEGER time_now;
	QueryPerformanceCounter(&time_now);
	
   return  (time_now.QuadPart - mcu_start_time.QuadPart) / (double)f.QuadPart * 1000000;
}


/**
  * @brief	:	delay a few millisecond.
  * @param	: 
  * @param	: 
  * @retval	:	
  */
void LLA_SYS_Time_DelayMS(uint32_t ms){
	uint32_t start_ms = LLA_SYS_Time_Millis();
	while (LLA_SYS_Time_ConsumeMillis(start_ms) < ms);
}



/**
  * @brief	:	delay a few microsecond.
  * @param	: 
  * @param	: 
  * @retval	:	
  */
void LLA_SYS_Time_DelayUS(uint32_t us){
	uint32_t start_us = LLA_SYS_Time_Micros();
	while (LLA_SYS_Time_ConsumeMicros(start_us) < us);
}

