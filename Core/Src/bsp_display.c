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
#include "system.h"

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

void bsp_display_text_line(const char *buffer, uint8_t line, uint8_t column)
{
  uint8_t row = line * 10;
  ST7789_WriteString(column, row, buffer, Font_7x10, BLACK, WHITE);
}

void bsp_display_list_file(manage_file_t list_file[])
{
  bsp_display_text_line("### LIST OF FILE ON SD CARD ###", 1, 10);

  for (uint8_t i = 0; i < 10; i++)
  {
    if (list_file[i].id != 0)
    {
      // Display index and name of files in list_file
      char buffer[100];
      sprintf(buffer, "%d.", list_file[i].id);
      bsp_display_text_line(buffer, list_file[i].id + 2, 10);
      bsp_display_text_line(list_file[i].name, list_file[i].id + 2, 31);
    }
    else
    {
      break;
    }
  }

  bsp_display_text_line("###### END OF LIST FILE #######", 14, 10);
}

void bsp_display_index_choose_file(void)
{
  char buffer[100];
  sprintf(buffer, "%d ", index_file_to_read);
  ST7789_WriteString(105, 230, buffer, Font_11x18, BLUE, WHITE);
}

void bsp_display_clear(void)
{
  ST7789_Fill_Color(WHITE);
}

void bsp_display_title_choose_file(void)
{
   ST7789_WriteString(40, 200, "CHOOSE FILE:", Font_11x18, BLACK, WHITE);
}

/* End of file -------------------------------------------------------- */
