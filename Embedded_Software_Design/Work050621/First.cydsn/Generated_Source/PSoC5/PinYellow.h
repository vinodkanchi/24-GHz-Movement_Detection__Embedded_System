/*******************************************************************************
* File Name: PinYellow.h  
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

#if !defined(CY_PINS_PinYellow_H) /* Pins PinYellow_H */
#define CY_PINS_PinYellow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PinYellow_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PinYellow__PORT == 15 && ((PinYellow__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PinYellow_Write(uint8 value);
void    PinYellow_SetDriveMode(uint8 mode);
uint8   PinYellow_ReadDataReg(void);
uint8   PinYellow_Read(void);
void    PinYellow_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinYellow_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PinYellow_SetDriveMode() function.
     *  @{
     */
        #define PinYellow_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PinYellow_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PinYellow_DM_RES_UP          PIN_DM_RES_UP
        #define PinYellow_DM_RES_DWN         PIN_DM_RES_DWN
        #define PinYellow_DM_OD_LO           PIN_DM_OD_LO
        #define PinYellow_DM_OD_HI           PIN_DM_OD_HI
        #define PinYellow_DM_STRONG          PIN_DM_STRONG
        #define PinYellow_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PinYellow_MASK               PinYellow__MASK
#define PinYellow_SHIFT              PinYellow__SHIFT
#define PinYellow_WIDTH              1u

/* Interrupt constants */
#if defined(PinYellow__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinYellow_SetInterruptMode() function.
     *  @{
     */
        #define PinYellow_INTR_NONE      (uint16)(0x0000u)
        #define PinYellow_INTR_RISING    (uint16)(0x0001u)
        #define PinYellow_INTR_FALLING   (uint16)(0x0002u)
        #define PinYellow_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PinYellow_INTR_MASK      (0x01u) 
#endif /* (PinYellow__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PinYellow_PS                     (* (reg8 *) PinYellow__PS)
/* Data Register */
#define PinYellow_DR                     (* (reg8 *) PinYellow__DR)
/* Port Number */
#define PinYellow_PRT_NUM                (* (reg8 *) PinYellow__PRT) 
/* Connect to Analog Globals */                                                  
#define PinYellow_AG                     (* (reg8 *) PinYellow__AG)                       
/* Analog MUX bux enable */
#define PinYellow_AMUX                   (* (reg8 *) PinYellow__AMUX) 
/* Bidirectional Enable */                                                        
#define PinYellow_BIE                    (* (reg8 *) PinYellow__BIE)
/* Bit-mask for Aliased Register Access */
#define PinYellow_BIT_MASK               (* (reg8 *) PinYellow__BIT_MASK)
/* Bypass Enable */
#define PinYellow_BYP                    (* (reg8 *) PinYellow__BYP)
/* Port wide control signals */                                                   
#define PinYellow_CTL                    (* (reg8 *) PinYellow__CTL)
/* Drive Modes */
#define PinYellow_DM0                    (* (reg8 *) PinYellow__DM0) 
#define PinYellow_DM1                    (* (reg8 *) PinYellow__DM1)
#define PinYellow_DM2                    (* (reg8 *) PinYellow__DM2) 
/* Input Buffer Disable Override */
#define PinYellow_INP_DIS                (* (reg8 *) PinYellow__INP_DIS)
/* LCD Common or Segment Drive */
#define PinYellow_LCD_COM_SEG            (* (reg8 *) PinYellow__LCD_COM_SEG)
/* Enable Segment LCD */
#define PinYellow_LCD_EN                 (* (reg8 *) PinYellow__LCD_EN)
/* Slew Rate Control */
#define PinYellow_SLW                    (* (reg8 *) PinYellow__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PinYellow_PRTDSI__CAPS_SEL       (* (reg8 *) PinYellow__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PinYellow_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PinYellow__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PinYellow_PRTDSI__OE_SEL0        (* (reg8 *) PinYellow__PRTDSI__OE_SEL0) 
#define PinYellow_PRTDSI__OE_SEL1        (* (reg8 *) PinYellow__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PinYellow_PRTDSI__OUT_SEL0       (* (reg8 *) PinYellow__PRTDSI__OUT_SEL0) 
#define PinYellow_PRTDSI__OUT_SEL1       (* (reg8 *) PinYellow__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PinYellow_PRTDSI__SYNC_OUT       (* (reg8 *) PinYellow__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PinYellow__SIO_CFG)
    #define PinYellow_SIO_HYST_EN        (* (reg8 *) PinYellow__SIO_HYST_EN)
    #define PinYellow_SIO_REG_HIFREQ     (* (reg8 *) PinYellow__SIO_REG_HIFREQ)
    #define PinYellow_SIO_CFG            (* (reg8 *) PinYellow__SIO_CFG)
    #define PinYellow_SIO_DIFF           (* (reg8 *) PinYellow__SIO_DIFF)
#endif /* (PinYellow__SIO_CFG) */

/* Interrupt Registers */
#if defined(PinYellow__INTSTAT)
    #define PinYellow_INTSTAT            (* (reg8 *) PinYellow__INTSTAT)
    #define PinYellow_SNAP               (* (reg8 *) PinYellow__SNAP)
    
	#define PinYellow_0_INTTYPE_REG 		(* (reg8 *) PinYellow__0__INTTYPE)
#endif /* (PinYellow__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PinYellow_H */


/* [] END OF FILE */
