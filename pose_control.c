#include "pose_control.h"
#include "delay.h"
#include "pca9685.h"
/**************************************************************
                                   C1
                                   |
                                   |  
                                   |
										  L3      ———————————     R3
											|												|
											|												|
											|												|
											|												|				
											L2                      R2
											|                       |
											|                       |
											|                       |
											L1                      R1
											|                       |
									---------                ---------
将六个舵机重命名
*****************************************************************/

void L1(int angle,u8 time)
{
	
		u8 i;
	if(angle<0)
	{
	angle=-angle;
		for(i=0;i<angle;i++)
	{
	TIM_SetCompare3(TIM3,150-i);//init 150; B0
		delay_ms(time);
	}
	}else{
	if(angle>0)
		{
	for(i=0;i<angle;i++)
	{
	TIM_SetCompare3(TIM3,150+i);//init 150; B0
		delay_ms(time);
	}
}
}
	if(angle==0)
	TIM_SetCompare3(TIM3,150);//init 150; B0
	
	  

}
void L2(int angle,u8 time)
{
	u8 i;
	if(angle<0)
	{
	angle=-angle;
		for(i=0;i<angle;i++)
	{
	TIM_SetCompare3(TIM2,140-i);//init 140; A2
		delay_ms(time);
	}
	}else{
	if(angle>0)
		{
	for(i=0;i<angle;i++)
	{
	TIM_SetCompare3(TIM2,140+i);//init 140; A2
		delay_ms(time);
	}
}
		
}
	if(angle==0)
	TIM_SetCompare3(TIM2,140);//init 140; A2

	
}
void L3(int angle,u8 time)
{
		u8 i;
	if(angle<0)
	{
	angle=-angle;
		for(i=0;i<angle;i++)
	{
	TIM_SetCompare4(TIM4,150-i);//init 150; B9
		delay_ms(time);
	}
	}else{
	if(angle>0)
		{
	for(i=0;i<angle;i++)
	{
	TIM_SetCompare4(TIM4,150+i);//init 150; B9
		delay_ms(time);
	}
}
}
	if(angle==0)
	TIM_SetCompare4(TIM4,150);//init 150; B9
		}
/*
函数功能：调整多集角度及速度
入口参数：angle 用来调整角度可输入正负来改变方向，范围-90到90，推荐+-20以内;
					time  用来调整到达设定角度所需时间即速度，数值越大越慢（推荐值100）
*/
void R1(int angle,u8 time)
{
	u8 i;
	
	if(angle<0)
	{
	angle=-angle;
		for(i=0;i<angle;i++)
	{

		TIM_SetCompare1(TIM4,150-i);//init 150; B6
		
		delay_ms(time);
	}
	}else{
	if(angle>0)
		{
	for(i=0;i<angle;i++)
	{
	TIM_SetCompare1(TIM4,150+i);//init 150; B6
		delay_ms(time);
	}
}
}
	if(angle==0)
	TIM_SetCompare1(TIM4,150);//init 150; B6
}
/*
函数功能：调整多集角度及速度
入口参数：angle 用来调整角度可输入正负来改变方向，范围-90到90，推荐+-20以内;
					time  用来调整到达设定角度所需时间即速度，数值越大越慢（推荐值100）
*/
////////////////////////////////////////////////
void R2(int angle,u8 time)
{
		u8 i;

	if(angle<0)
	{
	angle=-angle;
		for(i=0;i<angle;i++)
	{
	TIM_SetCompare2(TIM4,140-i);//init 140; B7
		delay_ms(time);
	}
	}else{
	if(angle>0)
		{
	for(i=0;i<angle;i++)
	{
	TIM_SetCompare2(TIM4,140+i);//init 140; B7
		delay_ms(time);
	}
}
		
}
	if(angle==0)
	TIM_SetCompare2(TIM4,140);//init 140; B7

}
void R3(int angle,u8 time)
{
	u8 i;
	if(angle<0)
	{
	angle=-angle;
		for(i=0;i<angle;i++)
	{
	TIM_SetCompare3(TIM4,150-i);//init 150; B8
		delay_ms(time);
	}
	}else{
	if(angle>0)
		{
	for(i=0;i<angle;i++)
	{
	TIM_SetCompare3(TIM4,150+i);//init 150; B8
		delay_ms(time);
	}
}
		
}
	if(angle==0)
	TIM_SetCompare3(TIM4,150);//init 150; B8
	 
	 
}
//void C1(u32 angle)
//{
//	// TIM_SetCompare4(TIM3,angle);//init 150; B1
//	PCA9685_setpwm(0,0,angle);//L2 
//}
void L11(u32 angle)
{
	 //TIM_SetCompare3(TIM3,angle);//init 150; B1
	 PCA9685_setpwm(3,0,angle);//L2
}
void L21(u32 angle)
{
	// TIM_SetCompare3(TIM2,angle);//init 150; B1
	PCA9685_setpwm(1,0,angle);//L2
	 
}
void L31(u32 angle)
{
	 //TIM_SetCompare4(TIM4,angle);//init 150; B1
	 PCA9685_setpwm(5,0,angle);//L2
}
void R11(u32 angle)
{
	 //TIM_SetCompare1(TIM4,angle);//init 150; B1
	 PCA9685_setpwm(4,0,angle);//L2
}
void R21(u32 angle)
{
	 //TIM_SetCompare3(TIM4,angle);//init 150; B1
	 PCA9685_setpwm(2,0,angle);//L2
}
void R31(u32 angle)
{
	 //TIM_SetCompare3(TIM4,angle);//init 150; B1
	 PCA9685_setpwm(6,0,angle);//L2
}

void init_pose()
{
	 PCA9685_setpwm(0,0,145);
	 PCA9685_setpwm(1,0,290);//L2
	 PCA9685_setpwm(2,0,290);//R2
	 PCA9685_setpwm(3,0,300);//L1
	 PCA9685_setpwm(4,0,300);//R1
	 PCA9685_setpwm(5,0,290);//L3
	 PCA9685_setpwm(6,0,290);//L3
}
void liandong1()
{

	//////抬左脚
		u8 i;
	for(i=0;i<40;i++)
	{
		R11(300-i);
		L11(300-i);//260
		L21(290-i);//250
		R31(290+i);//330
		delay_ms(10);
	}

	
}
void plain_go()
{	u8 i;
	for(i=0;i<40;i++)
	{
		R11(260+i);
		L11(260+i);//300
		delay_ms(10);
	}
	for(i=0;i<40;i++)
	{
	
		R21(290-i);//250
		delay_ms(10);
	}
	for(i=0;i<40;i++)
	{
		R11(300+i);
		L11(300+i);//340
		L21(250+i);//290
		R31(330-i);//290
		delay_ms(10);
	}
	for(i=0;i<40;i++)
	{
		L31(290+i);//330
		delay_ms(10);
	}
	/////////////////////
	/////////////////////
	for(i=0;i<40;i++)
	{
		R11(340-i);
		L11(340-i);//300
	  delay_ms(10);
	}
	for(i=0;i<40;i++)
	{
	
		L21(290-i);//250
		delay_ms(10);
	}
		for(i=0;i<40;i++)
	{
		R11(300-i);
		L11(300-i);//260
		R31(290+i);//330
		R21(250+i);//290
		L31(330-i);//290
		delay_ms(10);
	}
	////////////////
	///////////////
	
	}


