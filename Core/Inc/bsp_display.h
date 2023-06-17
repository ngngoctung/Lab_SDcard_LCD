/**
 * @file       <bsp_display>.h
 * @date       2023-06-17
 *             
 * @brief      <Display information on LCD>
 *             
 * @note       None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_DISPLAY_H
#define __BSP_DISPLAY_H

/* Includes ----------------------------------------------------------- */
#include "st7789.h"
/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
void bsp_display_text(const char *buffer); // Display text infor from buffer

// Display text from buffer in line
// line (1, 2, 3,...)
void bsp_display_text_line(const char *buffer, uint8_t line); 

#endif // __BSP_DISPLAY_H

/* End of file -------------------------------------------------------- */
