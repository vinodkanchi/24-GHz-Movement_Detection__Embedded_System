/*******************************************************************************
* File Name: PinGreen.h  
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

#if !defined(CY_PINS_PinGreen_H) /* Pins PinGreen_H */
#define CY_PINS_PinGreen_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PinGreen_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PinGreen__PORT == 15 && ((PinGreen__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PinGreen_Write(uint8 value);
void    PinGreen_SetDriveMode(uint8 mode);
uint8   PinGreen_ReadDataReg(void);
uint8   PinGreen_Read(void);
void    PinGreen_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinGreen_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PinGreen_SetDriveMode() function.
     *  @{
     */
        #define PinGreen_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PinGreen_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PinGreen_DM_RES_UP          PIN_DM_RES_UP
        #define PinGreen_DM_RES_DWN         PIN_DM_RES_DWN
        #define PinGreen_DM_OD_LO           PIN_DM_OD_LO
        #define PinGreen_DM_OD_HI           PIN_DM_OD_HI
        #define PinGreen_DM_STRONG          PIN_DM_STRONG
        #define PinGreen_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PinGreen_MASK               PinGreen__MASK
#define PinGreen_SHIFT              PinGreen__SHIFT
#define PinGreen_WIDTH              1u

/* Interrupt constants */
#if defined(PinGreen__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinGreen_SetInterruptMode() function.
     *  @{
     */
        #define PinGreen_INTR_NONE      (uint16)(0x0000u)
        #define PinGreen_INTR_RISING    (uint16)(0x0001u)
        #define PinGreen_INTR_FALLING   (uint16)(0x0002u)
        #define PinGreen_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PinGreen_INTR_MASK      (0x01u) 
#endif /* (PinGreen__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PinGreen_PS                     (* (reg8 *) PinGreen__PS)
/* Data Register */
#define PinGreen_DR                     (* (reg8 *) PinGreen__DR)
/* Port Number */
#define PinGreen_PRT_NUM                (* (reg8 *) PinGreen__PRT) 
/* Connect to Analog Globals */                                                  
#define PinGreen_AG                     (* (reg8 *) PinGreen__AG)                       
/* Analog MUX bux enable */
#define PinGreen_AMUX                   (* (reg8 *) PinGreen__AMUX) 
/* Bidirectional Enable */                                                        
#define PinGreen_BIE                    (* (reg8 *) PinGreen__BIE)
/* Bit-mask for Aliased Register Access */
#define PinGreen_BIT_MASK               (* (reg8 *) PinGreen__BIT_MASK)
/* Bypass Enable */
#define PinGreen_BYP                    (* (reg8 *) PinGreen__BYP)
/* Port wide control signals */                                                   
#define PinGreen_CTL                    (* (reg8 *) PinGreen__CTL)
/* Drive Modes */
#define PinGreen_DM0                    (* (reg8 *) PinGreen__DM0) 
#define PinGreen_DM1                    (* (reg8 *) PinGreen__DM1)
#define PinGreen_DM2                    (* (reg8 *) PinGreen__DM2) 
/* Input Buffer Disable Override */
#define PinGreen_INP_DIS                (* (reg8 *) PinGreen__INP_DIS)
/* LCD Common or Segment Drive */
#define PinGreen_LCD_COM_SEG            (* (reg8 *) PinGreen__LCD_COM_SEG)
/* Enable Segment LCD */
#define PinGreen_LCD_EN                 (* (reg8 *) PinGreen__LCD_EN)
/* Slew Rate Control */
#define PinGreen_SLW                    (* (reg8 *) PinGreen__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PinGreen_PRTDSI__CAPS_SEL       (* (reg8 *) PinGreen__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PinGreen_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PinGreen__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PinGreen_PRTDSI__OE_SEL0        (* (reg8 *) PinGreen__PRTDSI__OE_SEL0) 
#define PinGreen_PRTDSI__OE_SEL1        (* (reg8 *) PinGreen__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PinGreen_PRTDSI__OUT_SEL0       (* (reg8 *) PinGreen__PRTDSI__OUT_SEL0) 
#define PinGreen_PRTDSI__OUT_SEL1       (* (reg8 *) PinGreen__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PinGreen_PRTDSI__SYNC_OUT       (* (reg8 *) PinGreen__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PinGreen__SIO_CFG)
    #define PinGreen_SIO_HYST_EN        (* (reg8 *) PinGreen__SIO_HYST_EN)
    #define PinGreen_SIO_REG_HIFREQ     (* (reg8 *) PinGreen__SIO_REG_HIFREQ)
    #define PinGreen_SIO_CFG            (* (reg8 *) PinGreen__SIO_CFG)
    #define PinGreen_SIO_DIFF           (* (reg8 *) PinGreen__SIO_DIFF)
#endif /* (PinGreen__SIO_CFG) */

/* Interrupt Registers */
#if defined(PinGreen__INTSTAT)
    #define PinGreen_INTSTAT            (* (reg8 *) PinGreen__INTSTAT)
    #define PinGreen_SNAP               (* (reg8 *) PinGreen__SNAP)
    
	#define PinGreen_0_INTTYPE_REG 		(* (reg8 *) PinGreen__0__INTTYPE)
#endif /* (PinGreen__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PinGreen_H */


/* [] END OF FILE */
