/*
 * cursor.h
 *
 *  Created on: 28 May 2023
 *      Author: dominikpapp
 *  Provides basic manipulation of cursor
 */

#ifndef CURSOR_H_
#define CURSOR_H_

#include "segmentlcd_individual.h"
#include <stdbool.h>

// enum to be used with SegmentLCD_LowerCharSegments_TypeDef
enum SegmentLCD_LowerCharSegments_TypeDef_Bits{
    bitA = 1 << 0,  // Bit position 0
    bitB = 1 << 1,  // Bit position 1
    bitC = 1 << 2,  // Bit position 2
    bitD = 1 << 3,  // Bit position 3
    bitE = 1 << 4,  // Bit position 4
    bitF = 1 << 5,  // Bit position 5
    bitG = 1 << 6,  // Bit position 6
    bitH = 1 << 7,  // Bit position 7
    bitJ = 1 << 8,  // Bit position 8
    bitK = 1 << 9,  // Bit position 9
    bitM = 1 << 10, // Bit position 10
    bitN = 1 << 11, // Bit position 11
    bitP = 1 << 12, // Bit position 12
    bitQ = 1 << 13  // Bit position 13
};


void init_cursor(SegmentLCD_LowerCharSegments_TypeDef CURSOR_POS[SEGMENT_LCD_NUM_OF_LOWER_CHARS]);
uint8_t getCursorPos(const SegmentLCD_LowerCharSegments_TypeDef CURSOR_POS[SEGMENT_LCD_NUM_OF_LOWER_CHARS]);
void moveUp(SegmentLCD_LowerCharSegments_TypeDef CURSOR_POS[SEGMENT_LCD_NUM_OF_LOWER_CHARS]);
void moveDown(SegmentLCD_LowerCharSegments_TypeDef CURSOR_POS[SEGMENT_LCD_NUM_OF_LOWER_CHARS]);
void moveLeft(SegmentLCD_LowerCharSegments_TypeDef CURSOR_POS[SEGMENT_LCD_NUM_OF_LOWER_CHARS]);
void moveRight(SegmentLCD_LowerCharSegments_TypeDef CURSOR_POS[SEGMENT_LCD_NUM_OF_LOWER_CHARS]);

#endif /* CURSOR_H_ */
