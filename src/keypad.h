#ifndef _KEYPAD_H_
#define _KEYPAD_H_

#ifdef _KEYPAD_C_
#define _EXTERN
#else
#define _EXTERN extern
#endif

_EXTERN char getKey();

#endif