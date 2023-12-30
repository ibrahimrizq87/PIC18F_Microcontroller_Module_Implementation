/* 
 * File:   mcal_std_types.h
 * Author: Ibrahim BEMO
 *
 * Created on November 1, 2023, 5:43 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* Section : Includes */
#include"std_libraries.h"
#include"compiler.h"

/* Section: Data Type Declarations */
// ------------only ibrahime will understand these comments------------//
/* 
 * here we made the typedef thing because 
 * imagine you have a very large project and
 * you want to compile it in different 
 * compiler with different datatype size you then will 
 * change a lot of code so we did that to stander the size of the variable*/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;

typedef uint8 Std_ReturnType;

/* Section: Macro Declarations */
#define STD_HIGH       0x01
#define STD_LOW        0x00

#define STD_ON         0x01
#define STD_OFF        0x00


#define STD_ACTIVE     0x01
#define STD_IDLE       0x00

#define E_OK         (Std_ReturnType)0x01
#define E_NOT_OK     (Std_ReturnType)0x00

/* Section: Macro Functions Declarations */

/* Section: Function Declarations */


#endif	/* MCAL_STD_TYPES_H */

