/**
 * @file       <bsp_sd_card>.c
 * @date       2023-06-17
 *             
 * @brief      <Handle file on SD card>
 *             
 * @note       None
 */

/* Includes ----------------------------------------------------------- */
#include "bsp_sd_card.h"

/* Private defines ---------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
/* Function definitions ----------------------------------------------- */
void bsp_sd_card_mount(void)
{
  Mount_SD("");
}

void bsp_sd_card_unmount(void)
{
  Unmount_SD("");
}

void bsp_sd_card_read_file_txt(char *name, char *buf)
{
  Read_File(name, buf);
}

void bsp_sd_card_scan_file(void)
{
  Scan_SD("");
}
/* End of file -------------------------------------------------------- */
