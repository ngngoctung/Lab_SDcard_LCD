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
#include "common.h"

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

void bsp_display_text_line(const char *buffer, uint8_t line)
{
  uint8_t row = line * 10;
  ST7789_WriteString(10, row, buffer, Font_7x10, BLACK, WHITE);
}

void bsp_display_list_file(manage_file_t list_file[])
{
  for(uint8_t i = 0; i < 10; i++)
  {
    if(list_file[i].id != 0)
    {
      bsp_display_text_line(list_file[i].name, list_file[i].id);
    }
    else
    {
      break;
    }
  }
}

void bsp_display_index_choose_file(void)
{
  char buffer[100];
  sprintf(buffer, "%d", index_file_to_read);
  bsp_display_text_line(buffer, 21);
}

/* End of file -------------------------------------------------------- */
