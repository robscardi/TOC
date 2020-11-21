#ifndef _MAIN_H
#define _MAIN_H

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define _UNIX

#ifdef _WINDOWS /* Should move to Cmake file [WiP]*/

#define _CLEAR "cls"
#endif

#ifdef _UNIX

#define _CLEAR "clear"
#endif



#define _BLOCK 35
#define _TITLE "-----------The Tetris Game!-----------"

#define _UP_BORDER '_'
#define _SIDE_BORDER '|' 
#define _VOID_CH ' '

#define _WELCOME_MESS "---------PRESS ENTER TO START---------"

#define _TIMEFRAME 0.5

#define false 0
#define true 1

#define _TITLEPRINT() printf("%s \n", _TITLE)
#define _CLEAR_FRAME() system(_CLEAR), _TITLEPRINT()



typedef int bool_t;

enum angle{
    _ZERO = 0,
    _PIHALF = 1,
    _PI = 2,
    _PITHREEHALF = 3
};






#endif
