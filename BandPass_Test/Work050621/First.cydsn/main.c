/* ===============================================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ===============================================================
 * ===============================================================
 * Name                 : Vinod Kumar Kanchi
 * Matriculation Number : 769596
 * Major                : Communication
 * Email Id             : vinod.k.kanchi@stud.h-da.de
 * ===============================================================*/

#include "project.h"

uint16_t SampledArray[1024];                    //To store the sampled data into an array.

uint8_t character;                              //A global variable to check the character received or sent to and from MATLAB.
uint8_t SamplingState;                          //A global variable to check if sampling is done correctly.

typedef enum
{   IS_Idle,
    IS_Sampling,
    IS_UART_Transfer,
}System_state;                                  //To define the different states.

System_state state = IS_Idle;                   //Initialize the state to idle.

void ISR_button(void)
{
    state= IS_Sampling;
    Pin_PushButton_ClearInterrupt();            
}                                               //An interrupt routine to detect the button press and to clear the interrupt OF THE Pin.

void UART_INT(void)
{
    character= UART_GetChar();
    isr_UART_ClearPending();
}                                               //An interrupt routine to detect the character and to clear the interrupt in the UART.

CY_ISR_PROTO(isr_ADC);

CY_ISR(isr_ADC)
{
    isr_ADC_ClearPending();
    
}                                               //An interrupt routine to clear the interrupt of ADC.
 

void statechange(void);
int main(void)
{
    
    CyGlobalIntEnable;                          /* Enable global interrupts. */
   
    isr_ADC_StartEx(isr_ADC);
    isr_PushButton_StartEx(ISR_button);
    isr_UART_StartEx(UART_INT);                 //Starts all the interrupts.
    
    
    
    for(;;)
    {
        statechange();
    }

}



void statechange()
{
    switch(state)
            {
                case IS_Idle:
                       
                    WaveDAC8_Start();
                    ADC_DelSig_Start(); 
                    UART_Start();                               //Starts all the devices.
                
                    SamplingState = 0;                          //Set the sampling state to 0 initially.
                    PinYellow_Write(0);
                    PinRed_Write(1);
                    PinGreen_Write(0);
                                                                //Make Red LED glow and other LED's Off to indicate idle state.
                    break;
                            
                case IS_Sampling:
                                                                 
                    PinYellow_Write(1);
                    PinRed_Write(0);
                    PinGreen_Write(0);                          //Make Yellow LED glow and other LED's Off to indicate Sampling state.
                    if(SamplingState ==0)                       //If sampling state is 0 and push button is pressed starts converting.
                    {
                        ADC_DelSig_StartConvert();              //ADC Starts conversion.
                        for(uint16_t i=0; i<1024; i++)
                        {
                            ADC_DelSig_IsEndConversion(ADC_DelSig_WAIT_FOR_RESULT);
                            SampledArray[i] = ADC_DelSig_GetResult16();
                            
                        }                                       /*A loop of 1024 to stop the conversion and sampling at each point
                                                                and store the value in an array.*/
                        SamplingState = 1;                      //To indicate sampling is done for once.
                    }

                    if(character=='s' && SamplingState==1)
                    {
                        state = IS_UART_Transfer;
                        SamplingState = 0;
                        character = 0;
                     }                                      /*If character is 's' and sampling state is 1, then change the state to transfer,
                                                                and reset sampling state and character to 0 for once*/
                        break;
                        
                case IS_UART_Transfer:
                            
                      for(uint16_t i=0;i<1024;i++)
                         {
                            UART_PutChar(SampledArray[i]);
                            UART_PutChar(SampledArray[i]>>8);
                         }                              /*Loop to transfer data to MATLAB, 8 bits at a time and then right shift 
                                                            8 times to get the next 8 bits.*/  
            
                        PinGreen_Write(1);
                        PinRed_Write(0);
                        PinYellow_Write(0);             //Make Green LED glow and other LED's Off to indicate Transfer state.
                                            
                        if(character == 'o')
                        {
                             state=IS_Sampling;         //If MATLAB sends character 'o' then move back to sampling state.
                        }
                    break;
        }   
}

/*End of File*/