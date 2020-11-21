


#include "table.h"
#include "main.h"
#include "pieces.h"
#include "kbd_input.h"

void draw_table(Tab ); /*draw the frame on the command line*/
void count_frame(double , time_t);  /*block the frame until a certain time is met*/
void spawn_piece(pos*); /*spawn the piece on the table*/
/*inline void invert_tab_test(Tab*, Tab* ); test function with inline, strange error from the compiler on declaration,
maybe related to the standard, should use gnu89*/
void invert_tab_ptr(Tab**, Tab** ); /* invert the pointers to the tab*/





int main()
{
    
    /* test code*/

    Tab TabA;
    
    Tab TabB;

    /*Tab Pause_Tab;*/

    Tab *curr_T;
    Tab *next_T;

    
    Piece *curr_p;

    pos pos;
    


    time_t begin;

    
    char c;

    

    fpos_t pos_str;

    bool_t collision;

    struct termios def_terminal;
    struct termios terminal;

    pos.x = _COLUMN/2;
    pos.y = 1;

    get_default(&def_terminal);
    get_default(&terminal);

    
    c = 0;

    printf("%s \n", _TITLE);
    printf("%s \n", _WELCOME_MESS);
    scanf ("%c", &c);

    /* test code*/


    init_tab(&TabA);        
    
    curr_T = &TabA;
    next_T = &TabB;

    do{     
        _CLEAR_FRAME();
        begin = time(NULL);


        draw_table(*curr_T);

        /* takes input*/

        pos.y -= 1;


        collision = write_table(next_T, curr_T, curr_p, pos);

        if(collision){
            pos.x = _COLUMN/2;
            pos.y = 1;
            spawn_piece(&pos);
            
        }



        count_frame(_TIMEFRAME, begin);

    }while ( c != 'q');     /*[WiP]*/   





    set_term(&def_terminal);
    
    return 0;
}


bool_t write_table(Tab* next, Tab* curr, char p[][_DIM], pos pos)
{
    int i;
    int j;
    
    if(init_controll_collision(*curr, p ,pos))
    {
        init_tab(next);

        for ( i = 0; i < _DIM; i++)
        {
            for (j = 0; j < _DIM; j++)
            {
                (*curr).matrix[pos.y+i][pos.x+j] = p[i][j];
                
            }
        }
        assign_Tab(next, curr);
        invert_tab_ptr(&next, &curr);
        return false;   
    }
    else return true;

}

void spawn_piece(pos * pos){
    pos->x = _COLUMN/2;
    pos->y = 1;

}


void draw_table(Tab T)
{
    int i;
    int j;
    for (i = 0; i<_ROW; i++)
    {
        for(j = 0; j < _COLUMN; j++)
        {
            printf("%c", T.matrix[i][j]);
        }
        printf("\n");
    }
}

void count_frame(double t, time_t begin){

    
    time_t end;
    do{
        end = time(NULL);

    }while ( difftime(end, begin) < t);

}

/*inline void invert_tab_test(Tab* curr, Tab* next)  /*dont know if it works, strange "expected ; before void" error message
{
    Tab* temp;
    temp = curr;
    curr = next;
    next = temp;

}*/

void invert_tab_ptr(Tab** next, Tab** curr)
{
    Tab* temp;
    temp = *curr;
    *curr = *next;
    *next = temp;
}

