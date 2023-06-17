/**
 * @file       <bsp_display>.c
 * @date       2023-06-17
 *             
 * @brief      <Display information on LCD>
 *             
 * @note       None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp_display.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
void bsp_display_text(const char *buffer)
{
  uint16_t x = 10;
  uint16_t y = 10;

  for (int i = 0; buffer[i] != '\0'; i++)
  {
    if (buffer[i] == '\n' || buffer[i] == '\r')
    {
      y += 10;  // New lines
      x = 10;   // Reset to head of lines
    }
    else
    {
      ST7789_WriteChar(x, y, buffer[i], Font_7x10, BLACK, WHITE);
      x += 7;  // Increase position of clolumn in 1 char
    }
  }
}

/* End of file -------------------------------------------------------- */
