/*
 * SPI_Interface.h
 *
 * Created: 8/1/2022 9:04:13 AM
 *  Author: Osama
 */ 


#ifndef		SPI_INTERFACE_H
#define		SPI_INTERFACE_H

void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);
u8 SPI_u8SendReceive(u8 Copy_u8Data);
void SPI_send(u8 Copy_Data);
u8 SPI_u8Receive(u8 *pdata);


#endif
