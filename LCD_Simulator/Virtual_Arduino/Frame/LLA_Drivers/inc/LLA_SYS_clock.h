/*
 * @Description: LLA_SYS_clock module headers, DO NOT EDIT!!!
 * @Autor: Juan
 * @Date: 2022-04-01 14:49:54
 * @LastEditors: Juan
 * @LastEditTime: 2022-04-01 15:13:16
 */
#ifndef __LLA_SYS_CLOCK_H__
#define __LLA_SYS_CLOCK_H__


/* std lib includes */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



#ifdef __cplusplus
extern "C" {
#endif

void LLA_SYS_clock_Init(void);
void LLA_SYS_clock_Update(void);
uint32_t LLA_SYS_clock_Get(void);

#ifdef __cplusplus
}
#endif


#endif
