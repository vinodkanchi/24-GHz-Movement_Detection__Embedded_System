/*******************************************************************************
* File Name: PinRed.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PinRed_H) /* Pins PinRed_H */
#define CY_PINS_PinRed_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PinRed_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PinRed__PORT == 15 && ((PinRed__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PinRed_Write(uint8 value);
void    PinRed_SetDriveMode(uint8 mode);
uint8   PinRed_ReadDataReg(void);
uint8   PinRed_Read(void);
void    PinRed_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinRed_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PinRed_SetDriveMode() function.
     *  @{
     */
        #define PinRed_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PinRed_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PinRed_DM_RES_UP          PIN_DM_RES_UP
        #define PinRed_DM_RES_DWN         PIN_DM_RES_DWN
        #define PinRed_DM_OD_LO           PIN_DM_OD_LO
        #define PinRed_DM_OD_HI           PIN_DM_OD_HI
        #define PinRed_DM_STRONG          PIN_DM_STRONG
        #define PinRed_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PinRed_MASK               PinRed__MASK
#define PinRed_SHIFT              PinRed__SHIFT
#define PinRed_WIDTH              1u

/* Interrupt constants */
#if defined(PinRed__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinRed_SetInterruptMode() function.
     *  @{
     */
        #define PinRed_INTR_NONE      (uint16)(0x0000u)
        #define PinRed_INTR_RISING    (uint16)(0x0001u)
        #define PinRed_INTR_FALLING   (uint16)(0x0002u)
        #define PinRed_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PinRed_INTR_MASK      (0x01u) 
#endif /* (PinRed__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PinRed_PS                     (* (reg8 *) PinRed__PS)
/* Data Register */
#define PinRed_DR                     (* (reg8 *) PinRed__DR)
/* Port Number */
#define PinRed_PRT_NUM                (* (reg8 *) PinRed__PRT) 
/* Connect to Analog Globals */                                                  
#define PinRed_AG                     (* (reg8 *) PinRed__AG)                       
/* Analog MUX bux enable */
#define PinRed_AMUX                   (* (reg8 *) PinRed__AMUX) 
/* Bidirectional Enable */                                                        
#define PinRed_BIE                    (* (reg8 *) PinRed__BIE)
/* Bit-mask for Aliased Register Access */
#define PinRed_BIT_MASK               (* (reg8 *) PinRed__BIT_MASK)
/* Bypass Enable */
#define PinRed_BYP                    (* (reg8 *) PinRed__BYP)
/* Port wide control signals */                                                   
#define PinRed_CTL                    (* (reg8 *) PinRed__CTL)
/* Drive Modes */
#define PinRed_DM0                    (* (reg8 *) PinRed__DM0) 
#define PinRed_DM1                    (* (reg8 *) PinRed__DM1)
#define PinRed_DM2                    (* (reg8 *) PinRed__DM2) 
/* Input Buffer Disable Override */
#define PinRed_INP_DIS                (* (reg8 *) PinRed__INP_DIS)
/* LCD Common or Segment Drive */
#define PinRed_LCD_COM_SEG            (* (reg8 *) PinRed__LCD_COM_SEG)
/* Enable Segment LCD */
#define PinRed_LCD_EN                 (* (reg8 *) PinRed__LCD_EN)
/* Slew Rate Control */
#define PinRed_SLW                    (* (reg8 *) PinRed__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PinRed_PRTDSI__CAPS_SEL       (* (reg8 *) PinRed__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PinRed_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PinRed__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PinRed_PRTDSI__OE_SEL0        (* (reg8 *) PinRed__PRTDSI__OE_SEL0) 
#define PinRed_PRTDSI__OE_SEL1        (* (reg8 *) PinRed__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PinRed_PRTDSI__OUT_SEL0       (* (reg8 *) PinRed__PRTDSI__OUT_SEL0) 
#define PinRed_PRTDSI__OUT_SEL1       (* (reg8 *) PinRed__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PinRed_PRTDSI__SYNC_OUT       (* (reg8 *) PinRed__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PinRed__SIO_CFG)
    #define PinRed_SIO_HYST_EN        (* (reg8 *) PinRed__SIO_HYST_EN)
    #define PinRed_SIO_REG_HIFREQ     (* (reg8 *) PinRed__SIO_REG_HIFREQ)
    #define PinRed_SIO_CFG            (* (reg8 *) PinRed__SIO_CFG)
    #define PinRed_SIO_DIFF           (* (reg8 *) PinRed__SIO_DIFF)
#endif /* (PinRed__SIO_CFG) */

/* Interrupt Registers */
#if defined(PinRed__INTSTAT)
    #define PinRed_INTSTAT            (* (reg8 *) PinRed__INTSTAT)
    #define PinRed_SNAP               (* (reg8 *) PinRed__SNAP)
    
	#define PinRed_0_INTTYPE_REG 		(* (reg8 *) PinRed__0__INTTYPE)
#endif /* (PinRed__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PinRed_H */


/* [] END OF FILE */
