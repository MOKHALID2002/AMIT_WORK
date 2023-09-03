/*
Name    : Mohammed Khalid Mohammed
Date    : 1/9/2022
Version : 1.0
SWC     : BIT_MATH 
*/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT_NUM)     REG|=(1<<BIT_NUM)
#define CLEAR_BIT(REG,BIT_NUM)   REG&=(~(1<<BIT_NUM))
#define TOGGLE_BIT(REG,BIT_NUM)  REG^=(1<<BIT_NUM)
#define READ_BIT(REG,BIT_NUM)    ((REG>>BIT_NUM)&1)

#endif