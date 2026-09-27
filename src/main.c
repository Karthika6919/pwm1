#include "sdk_project_config.h"
int main(void){
	CLOCK_DRV_Init(&clockMan1_InitConfig0);
	PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0,g_pin_mux_InitConfigArr0);
	PWM_Init(&pwm_pal_1_instance,&pwm_pal_1_configs);
	int brightness = 0;

	while(1){

		 if (PINS_DRV_ReadPins(PTC)&(1<<12)){
		brightness++;

	switch(brightness){

	case 1:
			PWM_UpdateDuty(&pwm_pal_1_instance,0u,250);
			break;
	case 2:
			PWM_UpdateDuty(&pwm_pal_1_instance,0u,500);
			break;
	case 3:
			PWM_UpdateDuty(&pwm_pal_1_instance,0u,750);
			break;

	case 4:
			PWM_UpdateDuty(&pwm_pal_1_instance,0u,1000);
			break;
	case 5:
			PWM_UpdateDuty(&pwm_pal_1_instance,0u,1000);
			break;
	case 6:
			PWM_UpdateDuty(&pwm_pal_1_instance,0u,750);
			break;
	case 7:
			PWM_UpdateDuty(&pwm_pal_1_instance,0u,500);
			break;
	case 8:
			PWM_UpdateDuty(&pwm_pal_1_instance,0u,250);
			break;
	case 9:
			PWM_UpdateDuty(&pwm_pal_1_instance,0u,0);
			break;
	default:
		PWM_UpdateDuty(&pwm_pal_1_instance,0u,0);
		brightness=0;
		break;
	}
	OSIF_TimeDelay(1000);}
	while (PINS_DRV_ReadPins(PTC)&(1<<12));
	}


}
