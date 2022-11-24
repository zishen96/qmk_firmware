/* 
Copyright 2022 Owlab

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4F53  //0x4F53 for owlab
#define PRODUCT_ID      0x4348  //0x4348 CH for Chalice Hotswap
#define DEVICE_VER      0x0001 
#define MANUFACTURER    Owlab 
#define PRODUCT         Chalice Hotswap


/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { A2, A3, A4, A5 }
#define MATRIX_COL_PINS { A7, B0, B1, B2, B10, B11, B12, B13, B14, B15, A8, B6 }
/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define USB_POLLING_INTERVAL_MS 1

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
#define TAP_CODE_DELAY 10 

/* NKRO */
#ifdef NKRO_ENABLE
#    define FORCE_NKRO
#endif


