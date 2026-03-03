/*
 * 7_SEGMENT.h
 *
 *  Created on: Aug 28, 2025
 *      Author: Dorgham
 */

#ifndef HAL_7_SEGMENT_7_SEGMENT_H_
#define HAL_7_SEGMENT_7_SEGMENT_H_

#include "../../LIB/STD_TYPES.h"

void H7SEGMENT_vInit(void);
void H7SEGMENT_vPrintNumber(u8 number);
void H7SEGMENT_vDisable(void);

#endif /* HAL_7_SEGMENT_7_SEGMENT_H_ */
