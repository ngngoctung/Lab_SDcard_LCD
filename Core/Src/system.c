/**
 * @file       <system>.c
 * @date       2023-06-17
 *             
 * @brief      <Common>
 *             
 * @note       None
 */

/* Includes ----------------------------------------------------------- */
#include "system.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
system_state_t sys_state;
bool detect_state_change;
uint8_t index_file_to_read;
uint8_t num_max_of_file;
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
void system_init(void)
{
  //Init LCD
  HAL_GPIO_WritePin(BLK_PORT, BLK_PIN, GPIO_PIN_SET);
  ST7789_Init();

  //Mount sd card and scan to list_file
  bsp_sd_card_mount();
  bsp_sd_card_scan_file();
  bsp_display_list_file(list_file);

  // Init system variable
  detect_state_change = true;
  sys_state = STATE_MENU;
  index_file_to_read = 1;
}

void system_proccess(void)
{
    if(detect_state_change)
    {
      // Process based on the current system state
      switch (sys_state)
      {
      case STATE_MENU:
      {
        //Display MENU for choose file
        bsp_display_clear();
        bsp_display_list_file(list_file);
        bsp_display_title_choose_file();
        bsp_display_index_choose_file();
        break;
      }
      case STATE_DISPLAY_FILE:
      {
        for (uint8_t i = 0; i < 10; i++)
        {
          // Check if the file ID is 0, indicating the end of the list
          if (list_file[i].id == 0)
          {
            break;
          }

          if (list_file[i].id == index_file_to_read)
          {
            // Display the text from the file
            bsp_display_clear();
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

void system_reset(void)
{
  bsp_sd_card_unmount();
  NVIC_SystemReset();
}
/* End of file -------------------------------------------------------- */
