/**
 * @brief This module contains functions for configuring the Alternative Function Input/Output (AFIO) peripheral.
 *
 * @author Mohamed Ali Bayoumi
 * @date 27 OCT 2023
 * @version V01
 *
 * This module provides functions for configuring the remap and event output options of certain GPIO pins using the AFIO
 * peripheral. It is designed to be used with ARM Cortex-M processors, and may not be compatible with other architectures.
 *
 * @note This module is intended for use with the STM32F10x microcontroller series, but may be adapted for use with
 * other compatible processors.
 */
/**************************************** LIB ******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**************************************** MCAL *****************************************************/
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"
/*====================================================   Start_FUNCTION   ====================================================*/
Std_ReturnType MCAL_AFIO_SetEXTIConfigration(u8 Copy_Line , u8 Copy_PortMap)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;
    if (Copy_Line > 15 || Copy_PortMap > 2)
    {
        return Local_FunctionStatus;
    }
    u8 Local_RegIndex = Copy_Line/4;

    Copy_Line %= 4;

    AFIO->EXTICR[Local_RegIndex] &= ~((0x0f) <<  (Copy_Line * 4) );

    AFIO->EXTICR[Local_RegIndex] |= ((Copy_PortMap) <<  (Copy_Line * 4) );
    
    Local_FunctionStatus= E_OK;
    
    return Local_FunctionStatus;
}
/*====================================================   END_FUNCTION   ====================================================*/
