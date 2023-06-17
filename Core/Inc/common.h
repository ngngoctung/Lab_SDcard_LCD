/**
 * @file       <common>.h
 * @date       2023-06-17
 *             
 * @brief      <Display information on LCD>
 *             
 * @note       None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __COMMON_H
#define __COMMON_H

/* Includes ----------------------------------------------------------- */
#include "bsp_display.h"
#include "bsp_sd_card.h"
#include "stdbool.h"
/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
typedef enum 
{
  STATE_MENU, 
  STATE_DISPLAY_FILE, 
  STATE_MAX
}
system_state_t;
/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
extern system_state_t sys_state;
extern bool detect_state_change;
extern bool is_list_file_display;
extern uint8_t index_file_to_read;
extern uint8_t num_max_of_file;
/* Public function prototypes ----------------------------------------- */
void system_init(void);
void system_proccess(void);
#endif // __COMMON_H

/* End of file -------------------------------------------------------- */
