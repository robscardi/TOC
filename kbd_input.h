

#ifndef _KBD_INPUT_H
#define _KBD_INPUT_H

#include <stdio.h>
#include "main.h"

#define _UP 'w'
#define _DOWN 's'
#define _LEFT 'a'
#define _RIGHT 'd'




#include <fcntl.h>
#include <unistd.h>
#include <termios.h>


void get_default(struct termios* def){
    tcgetattr(STDIN_FILENO, def);
}

void set_term(struct termios* def){
    tcsetattr(STDIN_FILENO, TCSANOW, def);
}

void set_STDIN(){
    int FD;

    FD = fcntl(STDIN_FILENO, F_GETFL, 0);

    FD |= O_NONBLOCK;

    fcntl(STDIN_FILENO, F_SETFL, FD);
}



char get_input(struct termios* terminal)
{
    char buffer[256];

    int FD;
    int c;





    


    c = read(STDIN_FILENO, buffer, 1);



    return c;
    


}




#endif