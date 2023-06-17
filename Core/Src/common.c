/**
 * @file       <common>.c
 * @date       2023-06-17
 *             
 * @brief      <Common>
 *             
 * @note       None
 */

/* Includes ----------------------------------------------------------- */
#include "common.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
system_state_t sys_state;
bool detect_state_change;
bool is_list_file_display;
uint8_t index_file_to_read;
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
void system_init(void)
{
  HAL_GPIO_WritePin(BLK_PORT, BLK_PIN, GPIO_PIN_SET);
  ST7789_Init();

  bsp_sd_card_mount();
  bsp_sd_card_scan_file();
  detect_state_change = true;
  sys_state = STATE_MENU;
  bsp_display_list_file(list_file);
  is_list_file_display = true;
  index_file_to_read = 1;
}

void system_proccess(void)
{
    if(detect_state_change)
    {
      switch (sys_state)
      {
      case STATE_MENU:
      {
        ST7789_Fill_Color(WHITE);
        bsp_display_list_file(list_file);
        break;
      }
      case STATE_DISPLAY_FILE:
      {
        for (uint8_t i = 0; i < 10; i++)
        {
          if (list_file[i].id == 0)
          {
            break;
          }
          if (list_file[i].id == index_file_to_read)
          {
            ST7789_Fill_Color(WHITE);
            char *buf = calloc(1000 * sizeof(char), ' ');
            bsp_sd_card_read_file_txt(list_file[i].name, buf);
            bsp_display_text(buf);
            free(buf);
          }
        }
        break;
      }
      default: break;
      }
      detect_state_change = false;
    }
}
/* End of file -------------------------------------------------------- */
