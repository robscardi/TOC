
#ifndef _TABLE_H
#define _TABLE_H


#include "main.h"

#define _ROW 31
#define _COLUMN 40

typedef struct {
    char matrix[_ROW][_COLUMN];
}Tab;

void reset_matrix(Tab* c, int ROW, int COL, char ch)
{
    int i;
    int j;
    for ( i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            c->matrix[i][j] = ch;
        }
    }
}

void init_pause(Tab* pause)
{
    FILE* fp;
    
    int i;
    int j;
    char c;

    fp = fopen("Pause.txt", "r");

    reset_matrix(pause, _ROW, _COLUMN, _VOID_CH);

    if(fp != NULL) 
    {
        for ( i = 20; i < 18; i++)
        {
            for(j = 0; j < _COLUMN; j++)
            {
                c = getc(fp);

                if( c == _BLOCK)
                {
                pause->matrix[i][j] = c;
                }
                if ( c == EOF)
                {
                    exit;
                }

            }
        }
    }
    fclose(fp);

}




void init_tab(Tab* a)
{
    int i;
    
    reset_matrix(a, _ROW, _COLUMN, _VOID_CH);

    for(i = 0; i < _COLUMN; i++)
    {
        a->matrix[0][i] = _UP_BORDER;
        a->matrix[_ROW-1][i] = _UP_BORDER;
    }

    for(i = 1; i < _ROW; i++)
    {
        a->matrix[i][0] = _SIDE_BORDER;
        a->matrix[i][_COLUMN - 1] = _SIDE_BORDER;
    }

}

void assign_Tab(Tab* first, Tab* second)
{
    int i;
    int j;
    for (i = 0; i < _ROW; i++)
    {
        for ( j = 0; j < _COLUMN; j++)
        {
            first->matrix[i][j] = second->matrix[i][j];
        }
    }
}

#endif