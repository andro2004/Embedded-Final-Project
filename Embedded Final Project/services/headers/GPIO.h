#ifndef GPIO
#define GPIO
#define SET_REG(reg,val) reg|=val
#define CLEAR_REG(reg,val) reg&=~val
#define SET_BIT(reg,bit) reg|=(1<<bit)
#define CLEAR_BIT(reg,bit) reg&=~(1<<bit)
#define GET_BIT(reg,bit) (reg&=(1<<bit))>>bit
#endif
