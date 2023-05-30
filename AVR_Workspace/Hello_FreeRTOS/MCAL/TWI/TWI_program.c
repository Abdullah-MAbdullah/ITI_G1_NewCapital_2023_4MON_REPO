/*********************************************
 * Author:          Abdullah M. Abdullah
 * Creation Data:   19 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         19 APR, 2023    Abdullah M. Abdullah          Initial Creation
 *********************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"

void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
	/*Enable The Acknowledge*/
	SET_BIT(TWCR, TWCR_TWEA);
	if (Copy_u8SlaveAddress != 0x00)
	{
		TWAR = Copy_u8SlaveAddress << 1;
	}
	else
	{
		TWAR = 0x00 << 1;
	}

	/*Set Data Bit Rate = 100KHz */
	CLR_BIT(TWSR, TWSR_TWPS0);
	CLR_BIT(TWSR, TWSR_TWPS1);
	TWBR = 2;

	/*Enable The TWI*/
	SET_BIT(TWCR, TWCR_TWEN);
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	/*Enable The Acknowledge*/
	SET_BIT(TWCR, TWCR_TWEA);
	/*Set The Slave Address*/
	TWAR = Copy_u8SlaveAddress << 1;
	/*Enable The TWI*/
	SET_BIT(TWCR, TWCR_TWEN);
}

ERR_t TWI_ERRSendStartCondition(void)
{
	ERR_t Error_Status = NoError;
	/*Set The Start Condition Bit*/
	SET_BIT(TWCR, TWCR_TWSTA);
	/*Set The Flag To Take The Action*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*Polling (busy Wait) For The Flag To Be Raised*/
	while (GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Check For The Status Code*/
	if ((TWSR & STATUS_BIT_MASK) != START_ACK)
	{
		/*Return Error*/
		Error_Status = StartConditionError;
	}
	return Error_Status;
}

ERR_t TWI_ERRSendRepeatedStartCondition(void)
{
	ERR_t Error_Status = NoError;
	/*Set The Start Condition Bit*/
	SET_BIT(TWCR, TWCR_TWSTA);
	/*Set The Flag To Take The Action*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*Polling (busy Wait) For The Flag To Be Raised*/
	while (GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Check For The Status Code*/
	if ((TWSR & STATUS_BIT_MASK) != REP_START_ACK)
	{
		/*Return Error*/
		Error_Status = RepeatedStartConditionError;
	}
	return Error_Status;
}

ERR_t TWI_ERRSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	ERR_t Error_Status = NoError;
	/*Set The Slave Address In The TWDR*/
	TWDR = Copy_u8SlaveAddress << 1;
	/*Clear The 0th bit in the TWDR -> Write Request*/
	CLR_BIT(TWDR, TWDR_TWD0);
	/*Clear The Start Condition Bit*/
	CLR_BIT(TWCR, TWCR_TWSTA);
	/*Set The Flag To Take The Action*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*Polling (busy Wait) For The Flag To Be Raised*/
	while (GET_BIT(TWCR, TWCR_TWINT) == 0)
		;
	/*Check For The Status Code*/
	if ((TWSR & STATUS_BIT_MASK) != SLAVE_ADD_AND_WR_ACK)
	{
		/*Return Error*/
		Error_Status = SlaveAddressWithWriteRequestError;
	}
	return Error_Status;
}

void TWI_voidSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	ERR_t Error_Status = NoError;
	/*Set The Slave Address In The TWDR*/
	TWDR = Copy_u8SlaveAddress << 1;
	/*Clear The 0th bit in the TWDR -> Read Request*/
	SET_BIT(TWDR, TWDR_TWD0);
	/*Clear The Start Condition Bit*/
	CLR_BIT(TWCR, TWCR_TWSTA);
	/*Set The Flag To Take The Action*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*Polling (busy Wait) For The Flag To Be Raised*/
	while (GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Check For The Status Code*/
	if ((TWSR & STATUS_BIT_MASK) != SLAVE_ADD_AND_RD_ACK)
	{
		/*Return Error*/
		Error_Status = SlaveAddressWithReadRequestError;
	}
	return Error_Status;
}

ERR_t TWI_ERRSendDataPacket(u8 Copy_u8DataPacket)
{
	ERR_t Error_Status = NoError;
	/*Set The Data Packet In The TWDR Register*/
	TWDR = Copy_u8DataPacket;
	/*Set The Flag To Take The Action*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*Polling (busy Wait) For The Flag To Be Raised*/
	while (GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Check For The Status Code*/
	if ((TWSR & STATUS_BIT_MASK) != MSTR_WR_BYTE_ACK)
	{
		/*Return Error*/
		Error_Status = SendDataPacketError;
	}
	return Error_Status;
}

ERR_t TWI_ERRReceiveDataPacket(u8 *Copy_pu8DataPacket)
{
	ERR_t Error_Status = NoError;
	/*Set The Flag To Make The Slave Send Its Data*/
	SET_BIT(TWCR, TWCR_TWINT);
	/*Polling (busy Wait) For The Flag To Be Raised*/
	while (GET_BIT(TWCR, TWCR_TWINT) == 0);
	/*Check For The Status Code*/
	if ((TWSR & STATUS_BIT_MASK) != MSTR_RD_BYTE_WITH_ACK)
	{
		/*Return Error*/
		Error_Status = MasterReadDataPacketError;
	}
	else
	{
		/*Read The Received Data From TWDR*/
		*Copy_pu8DataPacket = TWDR;
	}
	return Error_Status;
}

void TWI_voidSendStopCondition(void)
{
	/*Set The Stop Condition Bit*/
	SET_BIT(TWCR, TWCR_TWSTO);
	/*Set The Flag To Make The Slave Send Its Data*/
	SET_BIT(TWCR, TWCR_TWINT);
}
