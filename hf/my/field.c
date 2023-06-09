/*
 * FIELD.c
 *
 *  Created on: 28 May 2023
 *      Author: dominikpapp
 */
#include <my/field.h>

// Sets CURSOR_POS's position in FIELD. G and M segments are handled as one segment
void FieldPlusCursor(SegmentLCD_LowerCharSegments_TypeDef FIELD[SEGMENT_LCD_NUM_OF_LOWER_CHARS], SegmentLCD_LowerCharSegments_TypeDef CURSOR_POS[SEGMENT_LCD_NUM_OF_LOWER_CHARS]){
  uint8_t pos = getCursorPos(CURSOR_POS);
  if(CURSOR_POS[pos].g || CURSOR_POS[pos].m)
    FIELD[pos].raw |= bitG | bitM;
  else
    FIELD[pos].raw |= CURSOR_POS[pos].raw;
}

// Removes CURSOR_POS's position from FIELD. G and M segments are handled as one segment
void FieldMinusCursor(SegmentLCD_LowerCharSegments_TypeDef FIELD[SEGMENT_LCD_NUM_OF_LOWER_CHARS], SegmentLCD_LowerCharSegments_TypeDef CURSOR_POS[SEGMENT_LCD_NUM_OF_LOWER_CHARS]){
  uint8_t pos = getCursorPos(CURSOR_POS);
  if(CURSOR_POS[pos].g || CURSOR_POS[pos].m)
    FIELD[pos].raw &= ~(bitG | bitM);
  else
    FIELD[pos].raw &= ~CURSOR_POS[pos].raw;
}

// Sets all bits if HIT in FIELD, logical OR.
void FieldPlusHit(SegmentLCD_LowerCharSegments_TypeDef FIELD[SEGMENT_LCD_NUM_OF_LOWER_CHARS], SegmentLCD_LowerCharSegments_TypeDef HIT[SEGMENT_LCD_NUM_OF_LOWER_CHARS]){
  for(int i = 0; i < SEGMENT_LCD_NUM_OF_LOWER_CHARS; i ++)
    FIELD[i].raw |= HIT[i].raw;
}
