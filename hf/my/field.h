/*
 * field.h
 *
 *  Created on: 28 May 2023
 *      Author: dominikpapp
 *  Provides logical operators for FIELD handling
 */

#ifndef FIELD_H_
#define FIELD_H_

#include "cursor.h"
#include "segmentlcd_individual.h"

void FieldPlusCursor(SegmentLCD_LowerCharSegments_TypeDef field[SEGMENT_LCD_NUM_OF_LOWER_CHARS], SegmentLCD_LowerCharSegments_TypeDef cursor_pos[SEGMENT_LCD_NUM_OF_LOWER_CHARS]);
void FieldMinusCursor(SegmentLCD_LowerCharSegments_TypeDef field[SEGMENT_LCD_NUM_OF_LOWER_CHARS], SegmentLCD_LowerCharSegments_TypeDef cursor_pos[SEGMENT_LCD_NUM_OF_LOWER_CHARS]);
void FieldPlusHit(SegmentLCD_LowerCharSegments_TypeDef FIELD[SEGMENT_LCD_NUM_OF_LOWER_CHARS], SegmentLCD_LowerCharSegments_TypeDef HIT[SEGMENT_LCD_NUM_OF_LOWER_CHARS]);

#endif /* FIELD_H_ */
