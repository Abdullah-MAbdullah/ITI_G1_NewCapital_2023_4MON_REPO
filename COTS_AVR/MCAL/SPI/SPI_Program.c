
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SPI_Interface.h"
#include "SPI_private.h"
#include "SPI_Config.h"


void SPI_voidMasterInit(void)
{
	/* Set the micro to be master */
	SET_BIT(SPCR , SPCR_MSTR);

	/* Set MSB to be sent first */
	CLR_BIT(SPCR , SPCR_DORD);

	/* Set leading edge to rising and trailing edge to falling */
	CLR_BIT(SPCR , SPCR_CPOL);

	/* sample at leading edge */
	CLR_BIT(SPCR , SPCR_CPHA);


	/* prescaler , divide by 16 */
	SET_BIT(SPCR , SPCR_SPR0);
	CLR_BIT(SPCR, SPCR_SPR1);
	CLR_BIT(SPSR , SPSR_SPI2X);

	/* Enable SPI */
	SET_BIT(SPCR , SPCR_SPE);

}
void SPI_voidSlaveInit(void)
{
	/* Set the micro to be slave */
	CLR_BIT(SPCR , SPCR_MSTR);

	/* Set MSB to be sent first */
	CLR_BIT(SPCR , SPCR_DORD);

	/* Set leading edge to rising and trailing edge to falling */
	CLR_BIT(SPCR , SPCR_CPOL);

	/* sample at leading edge */
	CLR_BIT(SPCR , SPCR_CPHA);

	/* Enable SPI */
	SET_BIT(SPCR , SPCR_SPE);
}
u8 SPI_u8SendReceive(u8 Copy_u8Data)
{
	/* set data in SPDR to send */
	SPDR = Copy_u8Data;

	/* polling (Busy wait) until transimission completed */
	while(GET_BIT(SPSR , SPSR_SPIF) == 0);

	/* Clear the flag */
	//SET_BIT(SPSR , SPSR_SPIF);

	/* Get exchanged data */
	return SPDR;
}

void SPI_send(u8 Copy_Data){
	SPDR = Copy_Data;
}

u8 SPI_u8Receive(u8 *pdata)
{
	if(GET_BIT(SPSR , SPSR_SPIF) == 1){
		*pdata =  SPDR;
		return 1;
	}

	return 0;

}
