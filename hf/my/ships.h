/*
 * ships.h
 *
 *  Created on: 28 May 2023
 *      Author: dominikpapp
 *  Provides handling of ships
 */

#ifndef SHIPS_H_
#define SHIPS_H_

#include "segmentlcd_individual.h"
#include <stdbool.h>
#include "cursor.h"

#define SAVED_MAP_NUMBERS 16
// Predetermined ship layouts
extern bool game_levels[SAVED_MAP_NUMBERS - 1][SEGMENT_LCD_NUM_OF_LOWER_CHARS][14];


bool shoot(SegmentLCD_LowerCharSegments_TypeDef MAP[SEGMENT_LCD_NUM_OF_LOWER_CHARS], SegmentLCD_LowerCharSegments_TypeDef CURSOR_POS[SEGMENT_LCD_NUM_OF_LOWER_CHARS]);
void hit(SegmentLCD_LowerCharSegments_TypeDef HIT[SEGMENT_LCD_NUM_OF_LOWER_CHARS], SegmentLCD_LowerCharSegments_TypeDef CURSOR_POS[SEGMENT_LCD_NUM_OF_LOWER_CHARS]);
bool isHit(SegmentLCD_LowerCharSegments_TypeDef HIT[SEGMENT_LCD_NUM_OF_LOWER_CHARS], SegmentLCD_LowerCharSegments_TypeDef CURSOR_POS[SEGMENT_LCD_NUM_OF_LOWER_CHARS]);

#endif /* SHIPS_H_ */
