/**
 * @file       <bsp_sd_card>.h
 * @date       2023-06-17
 *             
 * @brief      <Handle file on SD card>
 *             
 * @note       None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_SD_CARD_H
#define __BSP_SD_CARD_H

/* Includes ----------------------------------------------------------- */
#include "File_Handling.h"
/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
typedef struct
{
  uint8_t id;   /**< Index of file */
  char name[100]; /**< Name file */
}
manage_file_t;
/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
extern manage_file_t list_file[10];
/* Public function prototypes ----------------------------------------- */
void bsp_sd_card_mount(void);
void bsp_sd_card_unmount(void);
void bsp_sd_card_read_file_txt(char *name, char* buf); // Read file txt on SD card
void bsp_sd_card_scan_file(void);

#endif // __BSP_SD_CARD_H

/* End of file -------------------------------------------------------- */
