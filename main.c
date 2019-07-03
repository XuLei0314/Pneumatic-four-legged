#include "main.h"

extern uint8_t auto_send[50];
tSendTXoneData SendData = {0};
extern uint16_t count;
	 
u8 SV5_State = 0x0000;
u8 SV6_State = 0x0000;
u8 SV7_State = 0x0000;
u8 SV8_State = 0x0000;

int main(void)
{	
	u16 t;  
	count=0;
	delay_init();	    	 //延时函数初始化	  
	LED_Init();		  	//初始化与LED连接的硬件接口
	TIM3_Int_Init(20000-1,72-1); //10Khz的计数频率，计数到5000为500ms
	NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	usart2_init(115200);//串口1初始化
	POWER_Init();
	while(1)
	{ 
//		SV5_State = 0x0001;
//		SV6_State = 0x0001;
//			SV7_State = 0x0001;
//			SV8_State = 0x0001;
		//1234前后 5678抬落
		//下面进气往前 开关后  下吸气抬上吸气落
		//方法二
//		  delay_ms(2000);
//			SV5_State = 0x0001;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;
//		  delay_ms(4000);
//			SV5_State = 0x0000;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;
//		  delay_ms(4000);
//			SV5_State = 0x0001;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;
//			delay_ms(4000);
//			SV1_ON;
//  		SV2_OFF;
//			SV3_OFF;
//			SV4_OFF;
//			delay_ms(4000);
//			SV5_State = 0x0000;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;	
//方法1
//		if(count==50)
//		{
//			SV5_State = 0x0001;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;
//		}
//		if(count==100)
//		{
//			SV5_State = 0x0000;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;
//		}1 3 抬前走   落 24起 前走   13 气缸后走 24 落 24还在前  13 抬前走  24 气缸后走
//第二次失败
//		if(count==20)//20
//		{
//			SV5_State = 0x0001;
//			SV6_State = 0x0000;
//			SV7_State = 0x0001;
//			SV8_State = 0x0000;

//		}
//		if(count==60)//60
//		{
//			SV1_ON;
//			SV2_OFF;
//			SV3_ON;
//			SV4_OFF;                                             
//		}
//		if(count==70)//70
//		{
//			SV5_State = 0x0000;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;			
//		}
//		if(count==110)//110
//		{
//			SV5_State = 0x0000                                                                                                 ;
//			SV6_State = 0x0001;
//			SV7_State = 0x0000;
//			SV8_State = 0x0001;	          			
//		}
//		if(count==120)//120
//		{
//			SV1_OFF;
//			SV2_ON;
//			SV3_OFF;
//			SV4_ON; 
//		}
//		if(count==160)//160
//		{
//			SV5_State = 0x0000;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;
//			
//		}
//		if(count==170)
//		{
//			SV5_State = 0x0001;
//			SV6_State = 0x0000;
//			SV7_State = 0x0001;
//			SV8_State = 0x0000;		
//		}
//		if(count==200)//200
//		{
//			SV1_OFF;
//			SV2_OFF;
//			SV3_OFF;
//			SV4_OFF; 
//		}
//		if(count==240)
//		{
//			count=20;
//		}
//    if(count==20)
//		{
//				SV5_State = 0x0001;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;
//		}
//		if(count==40)
//		{
//			SV1_ON;
//			SV2_OFF;
//			SV3_OFF;
//			SV4_OFF;   
//		}
//		if(count==80)
//		{
//				SV5_State = 0x0000;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;
//		}
//	 if(count==120)
//		{
//			SV5_State = 0x000;
//			SV6_State = 0x0000;
//			SV7_State = 0x0001;
//			SV8_State = 0x0000;
//		}
//		 if(count==140)
//		{
//		  SV1_ON;
//			SV2_OFF;
//			SV3_ON;
//			SV4_OFF;   
//		}
//		    if(count==180)
//		{
//				SV5_State = 0x0000;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;
//		}
//			 if(count==220)
//		{
//			SV5_State = 0x0000;
//			SV6_State = 0x0001;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;
//		}
//		 if(count==240)
//		{
//		  SV1_ON;
//			SV2_ON;
//			SV3_ON;
//			SV4_OFF;   
//		}
//		    if(count==280)
//		{
//				SV5_State = 0x0000;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;
//		}
//			 if(count==320)
//		{
//			SV5_State = 0x0000;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0001;
//		}
//		 if(count==360)
//		{
////			SV1_OFF;
////			SV2_OFF;
////			SV3_OFF;
////			SV4_OFF; 
//		  SV1_ON;
//			SV2_ON;
//			SV3_ON;
//			SV4_ON;   
//		}
//		    if(count==400)
//		{
//				SV5_State = 0x0000;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;
//		}
//		if(count==440)
//		{
//					  SV1_OFF;
//			SV2_OFF;
//			SV3_OFF;
//			SV4_OFF;   
//		}
//		if(count==480)
//		{
//			count=0;
//		}
//		
		if(count==20)
		{
				SV5_State = 0x0001;
			SV6_State = 0x0000;
			SV7_State = 0x0001;
			SV8_State = 0x0000;
		}
		if(count==40)
		{
			SV1_ON;
			SV2_OFF;
			SV3_ON;
			SV4_OFF;   
		}
		if(count==80)
		{
				SV5_State = 0x0000;
			SV6_State = 0x0000;
			SV7_State = 0x0000;
			SV8_State = 0x0000;
		}
	 if(count==120)
		{
			SV5_State = 0x0000;
			SV6_State = 0x0001;
			SV7_State = 0x0000;
			SV8_State = 0x0001;
		}
		 if(count==140)
		{
		  SV1_ON;
			SV2_ON;
			SV3_ON;
			SV4_ON;   
		}
		    if(count==180)
		{
				SV5_State = 0x0000;
			SV6_State = 0x0000;
			SV7_State = 0x0000;
			SV8_State = 0x0000;
		}
			 if(count==220)
		{
		  SV1_OFF;
			SV2_OFF;
			SV3_OFF;
			SV4_OFF; 
//			SV5_State = 0x0000;
//			SV6_State = 0x0001;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;
		}
		 if(count==260)
		{
		  count=20;   
		}
//		    if(count==280)
//		{
//				SV5_State = 0x0000;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;
//		}
//			 if(count==320)
//		{
//			SV5_State = 0x0000;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0001;
//		}
//		 if(count==360)
//		{
////			SV1_OFF;
////			SV2_OFF;
////			SV3_OFF;
////			SV4_OFF; 
//		  SV1_ON;
//			SV2_ON;
//			SV3_ON;
//			SV4_ON;   
//		}
//		    if(count==400)
//		{
//				SV5_State = 0x0000;
//			SV6_State = 0x0000;
//			SV7_State = 0x0000;
//			SV8_State = 0x0000;
//		}
//		if(count==440)
//		{
//					  SV1_OFF;
//			SV2_OFF;
//			SV3_OFF;
//			SV4_OFF;   
//		}
//		if(count==480)
//		{
//			count=0;
//		}
//		
		
		
		SendData.sof = 0xA5;//0xA5
		SendData.temp1_1 = SV5_State;
		SendData.temp2_1 = SV6_State;
		SendData.temp3_1 = SV7_State;
		SendData.temp4_1 = SV8_State;
		SendData.temp5_1 = 0x0000;
		SendData.temp6_1 = 0x0000;
		SendData.temp7_1 = 0x0000;
		SendData.temp8_1 = 0x0000;
		SendData.end = 0xFE;//FE
		memcpy(auto_send, &SendData, sizeof(tSendTXoneData));
		for(t=0;t<sizeof(tSendTXoneData);t++)
		{
			GREEN_ON;
			USART_SendData(USART2,auto_send[t]);
			while( USART_GetFlagStatus(USART2,USART_FLAG_TC)!= SET);
		}
		GREEN_OFF;
	}
}
