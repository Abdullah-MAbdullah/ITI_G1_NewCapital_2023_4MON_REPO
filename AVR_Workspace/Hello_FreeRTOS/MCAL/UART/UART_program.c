/*********************************************
 * Author:          Abdullah M. Abdullah
 * Creation Data:   17 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         17 APR, 2023    Abdullah M. Abdullah          Initial Creation
 *********************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void UART_voidInit(void)
{
	// Result = 0000 1101 0011 1110
	// UBRRL = (u8)Result;
	// UBRRH = Result >> 8;


	u8 Local_u8UCSRCTemp = 0;
	/* UART Parameters:
        - Asynchronous Mode
        - Enable Tx & Rx Circuits
        - Data Size = 8-bit
        - Parity = Disbaled
        - Stop bits = 1-bit
        - Baudrate = 9600bps  
        - Disbale Double Speed Mode 
	 */
	/*Set The USART Mode To Be Asynchronous Mode*/
	CLR_BIT(Local_u8UCSRCTemp, UCSRC_UMSEL);

	/*Enable The Tx & Rx Circuits*/
	SET_BIT(UCSRB, UCSRB_TXEN);
	SET_BIT(UCSRB, UCSRB_RXEN);

	/*Set The Data Size Bits To Be 8-bit*/
	SET_BIT(Local_u8UCSRCTemp, UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCTemp, UCSRC_UCSZ1);
	CLR_BIT(UCSRB, UCSRB_UCSZ2);

	/*Disable The Parity Mode*/
	CLR_BIT(Local_u8UCSRCTemp, UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRCTemp, UCSRC_UPM1);

	/*Stop Bit = 1-bit*/
	CLR_BIT(Local_u8UCSRCTemp, UCSRC_USBS);

	/*Set The USART Register Select Bit To Write On UCSRC*/
	SET_BIT(Local_u8UCSRCTemp, UCSRC_URSEL);
	/*Assign The Variable Value To The Register*/
	UCSRC = Local_u8UCSRCTemp;

	/*Set The Baudrate To Be 9600bps*/
	CLR_BIT(UCSRA, UCSRA_U2X);
	UBRRL = 51;
	/*Clear The USART Register Select Bit To Write On UBRRH*/
	CLR_BIT(UBRRH, UBRRH_URSEL);
	UBRRH = 0;

}

void UART_voidTransmitDataSynchronous(u8 Copy_u8Data)
{
	/*Polling (Busy Wait) On The UDR Empty Flag*/
	while(GET_BIT(UCSRA, UCSRA_UDRE) == 0);
	/*Copy The Data To The UDR Register*/
	UDR = Copy_u8Data;
	/*Polling (Busy Wait) On The TXC Flag*/
	while(GET_BIT(UCSRA, UCSRA_TXC) == 0);
	/* Clear The Flag */
	SET_BIT(UCSRA, UCSRA_TXC);
}

void UART_voidReceiveDataSynchronous(u8 * Copy_pu8ReceivedData)
{
	/*Polling (Busy Wait) On The Receive Complete Flag*/
	while(GET_BIT(UCSRA, UCSRA_RXC) == 0);
	/*Get The Received Data And Assign It To The Passed Variable*/
	*Copy_pu8ReceivedData = UDR;
}


void UART_voidSendString(u8 * Copy_pu8StringArray)
{
	u8 Local_u8LoopCounter = 0 ;
	/*Loop On The String till the null terminator*/
	while(Copy_pu8StringArray[Local_u8LoopCounter] != '\0')
	{
		/*Send The Array Element*/
		UART_voidTransmitDataSynchronous(Copy_pu8StringArray[Local_u8LoopCounter]);
		Local_u8LoopCounter++;
	}
}

void UART_voidSendNumber(u32 Copy_u32Number)
{
	u8 Local_u8ArrayNumber[10];
	s8 Local_s8LoopCounter = 0;
	while(Copy_u32Number != 0)
	{
		Local_u8ArrayNumber[Local_s8LoopCounter] = Copy_u32Number % 10;
		Copy_u32Number /= 10;
		Local_s8LoopCounter++;
	}
	Local_s8LoopCounter--;
	while(Local_s8LoopCounter >= 0)
	{
		UART_voidTransmitDataSynchronous(Local_u8ArrayNumber[Local_s8LoopCounter] + '0');
		Local_s8LoopCounter--;
	}
}
