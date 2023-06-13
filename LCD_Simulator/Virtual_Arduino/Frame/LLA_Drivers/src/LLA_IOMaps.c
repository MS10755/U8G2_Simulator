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
IOMAP_NameMask_t LLA_IOMaps_NameMask(BaseIO_name_t name){
	return (IOMAP_NameMask_t) 0;
}

IOMAP_Port_t LLA_IOMaps_NameToPort(BaseIO_name_t name){
	IOMAP_Port_t p;
	p.IDR = 0;
	p.ODR = 0;
	return p;
}

/************************ Your Interrupt handling function ****************************/


