/*
 * File_Handling_RTOS.c
 *
 *  Created on: 14-May-2020
 *      Author: Controllerstech
 */

#include "stm32f4xx_hal.h"

#include <File_Handling.h>
#include "bsp_display.h"

/* =============================>>>>>>>> NO CHANGES AFTER THIS LINE
 * =====================================>>>>>>> */

FATFS   fs;       // file system
FIL     fil;      // File
FILINFO fno;
FRESULT fresult;  // result
UINT    br, bw;   // File read/write count

/**** capacity related *****/
FATFS   *pfs;
DWORD    fre_clust;
uint32_t total, free_space;

void Mount_SD(const TCHAR *path)
{
  fresult = f_mount(&fs, path, 1);
  if (fresult != FR_OK)
  {
    // TO DO
  }
  else
  {
    // TO DO
  }
}

void Unmount_SD(const TCHAR *path)
{
  fresult = f_mount(NULL, path, 1);
  if (fresult == FR_OK)
  {
    // TO DO
  }
  else
  {
    // TO DO
  }
}

/* Start node to be scanned (***also used as work area***) */
FRESULT Scan_SD(char *pat)
{
  DIR   dir;
  UINT  i;
  char *path = malloc(20 * sizeof(char));
  sprintf(path, "%s", pat);
  uint8_t index = 1;

  fresult = f_opendir(&dir, path); /* Open the directory */
  if (fresult == FR_OK)
  {
    for (;;)
    {
      fresult = f_readdir(&dir, &fno); /* Read a directory item */
      if (fresult != FR_OK || fno.fname[0] == 0)
        break;                         /* Break on error or end of dir */
      if (fno.fattrib & AM_DIR)        /* It is a directory */
      {
        if (!(strcmp("SYSTEM~1", fno.fname)))
          continue;
        i = strlen(path);
        sprintf(&path[i], "/%s", fno.fname);
        fresult = Scan_SD(path); /* Enter the directory */
        if (fresult != FR_OK)
          break;
        path[i] = 0;
      }
      else
      { /* It is a file. */
        bsp_display_text_line(fno.fname, index);
        index++;
      }
    }
    f_closedir(&dir);
  }
  free(path);
  return fresult;
}

/* Only supports removing files from home directory */
FRESULT Format_SD(void)
{
  DIR   dir;
  char *path = malloc(20 * sizeof(char));
  sprintf(path, "%s", "/");

  fresult = f_opendir(&dir, path); /* Open the directory */
  if (fresult == FR_OK)
  {
    for (;;)
    {
      fresult = f_readdir(&dir, &fno); /* Read a directory item */
      if (fresult != FR_OK || fno.fname[0] == 0)
        break;                         /* Break on error or end of dir */
      if (fno.fattrib & AM_DIR)        /* It is a directory */
      {
        if (!(strcmp("SYSTEM~1", fno.fname)))
          continue;
        fresult = f_unlink(fno.fname);
        if (fresult == FR_DENIED)
          continue;
      }
      else
      { /* It is a file. */
        fresult = f_unlink(fno.fname);
      }
    }
    f_closedir(&dir);
  }
  free(path);
  return fresult;
}

FRESULT Write_File(char *name, char *data)
{
  /**** check whether the file exists or not ****/
  fresult = f_stat(name, &fno);
  if (fresult != FR_OK)
  {
    return fresult;
  }
  else
  {
    /* Create a file with read write access and open it */
    fresult = f_open(&fil, name, FA_OPEN_EXISTING | FA_WRITE);
    if (fresult != FR_OK)
    {
      return fresult;
    }
    else
    {
      fresult = f_write(&fil, data, strlen(data), &bw);
      if (fresult != FR_OK)
      {
        // TO DO
      }

      /* Close file */
      fresult = f_close(&fil);
      if (fresult != FR_OK)
      {
        // TO DO
      }
      else
      {
        // TO DO
      }
    }
    return fresult;
  }
}

FRESULT Read_File(char *name, char *buf)
{
  /**** check whether the file exists or not ****/
  fresult = f_stat(name, &fno);
  if (fresult != FR_OK)
  {
    return fresult;
  }

  else
  {
    /* Open file to read */
    fresult = f_open(&fil, name, FA_READ);

    if (fresult != FR_OK)
    {
      return fresult;
    }

    /* Read data from the file
     * see the function details for the arguments */

    // char *buffer = malloc(sizeof(f_size(&fil)));
    fresult = f_read(&fil, buf, f_size(&fil), &br);
    if (fresult != FR_OK)
    {
      // TO DO
    }

    else
    {
      /* Close file */
      fresult = f_close(&fil);
      if (fresult != FR_OK)
      {
        // TO DO
      }
      else
      {
        // TO DO
      }
    }
    return fresult;
  }
}

FRESULT Create_File(char *name)
{
  fresult = f_stat(name, &fno);
  if (fresult == FR_OK)
  {
    return fresult;
  }
  else
  {
    fresult = f_open(&fil, name, FA_CREATE_ALWAYS | FA_READ | FA_WRITE);
    if (fresult != FR_OK)
    {
      return fresult;
    }
    else
    {
      // TO DO
    }

    fresult = f_close(&fil);
    if (fresult != FR_OK)
    {
      // TO DO
    }
    else
    {
      // TO DO
    }
  }
  return fresult;
}

FRESULT Update_File(char *name, char *data)
{
  /**** check whether the file exists or not ****/
  fresult = f_stat(name, &fno);
  if (fresult != FR_OK)
  {
    return fresult;
  }

  else
  {
    /* Create a file with read write access and open it */
    fresult = f_open(&fil, name, FA_OPEN_APPEND | FA_WRITE);
    if (fresult != FR_OK)
    {
      // TO DO
      return fresult;
    }

    /* Writing text */
    fresult = f_write(&fil, data, strlen(data), &bw);
    if (fresult != FR_OK)
    {
      // TO DO
    }

    else
    {
      // TO DO
    }

    /* Close file */
    fresult = f_close(&fil);
    if (fresult != FR_OK)
    {
      // TO DO
    }
    else
    {
      // TO DO
    }
  }
  return fresult;
}

FRESULT Remove_File(char *name)
{
  /**** check whether the file exists or not ****/
  fresult = f_stat(name, &fno);
  if (fresult != FR_OK)
  {
    // TO DO
    return fresult;
  }

  else
  {
    fresult = f_unlink(name);
    if (fresult == FR_OK)
    {
      // TO DO
    }

    else
    {
      // TO DO
    }
  }
  return fresult;
}

FRESULT Create_Dir(char *name)
{
  fresult = f_mkdir(name);
  if (fresult == FR_OK)
  {
    // TO DO
  }
  else
  {
    // TO DO
  }
  return fresult;
}

void Check_SD_Space(void)
{
  /* Check free space */
  f_getfree("", &fre_clust, &pfs);

  total      = (uint32_t) ((pfs->n_fatent - 2) * pfs->csize * 0.5);
  free_space = (uint32_t) (fre_clust * pfs->csize * 0.5);
}
