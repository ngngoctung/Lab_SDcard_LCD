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
/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
void bsp_sd_card_mount(void);
void bsp_sd_card_unmount(void);
void bsp_sd_card_read_file_txt(char *name, char* buf); // Read file txt on SD card

#endif // __BSP_SD_CARD_H

/* End of file -------------------------------------------------------- */
