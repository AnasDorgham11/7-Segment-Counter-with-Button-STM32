#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/RCC/RCC_prv.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/GPIO/GPIO_prv.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "HAL/7_SEGMENT/7_SEGMENT_int.h"
#include "MCAL/SYSTICK/SYSTICK_int.h"

int count = 0;

int main(void)
{
	MRCC_vInit();
	MRCC_vEnableClk(RCC_AHB1, GPIOBEN);

	GPIOx_PinConfig_t Button =
	{
			.Port = GPIO_PORTB,
			.Pin = GPIO_PIN8,
			.Mode = GPIO_MODE_INPUT,
			.Speed = GPIO_SPEED_HIGH,
			.PullType = GPIO_PULL_UP
	};

	H7SEGMENT_vInit();
	H7SEGMENT_vPrintNumber(0);
	MGPIO_vPinInit(&Button);

	while(1)
	{
		if (MGPIO_u8GetPinValue(GPIO_PORTB, GPIO_PIN8) == 0)
		{
			count++;
			if (count == 10){
				count = 0;
			}
			H7SEGMENT_vPrintNumber(count);
			MSYSTICK_vSetDelay_ms(20);
			while(MGPIO_u8GetPinValue(GPIO_PORTB, GPIO_PIN8) == 0);
			MSYSTICK_vSetDelay_ms(20);
		}
	}
	return 0;
}
