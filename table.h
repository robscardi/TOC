
#ifndef _TABLE_H
#define _TABLE_H


#include "main.h"

#define _ROW 31
#define _COLUMN 31

typedef struct {
    char matrix[_ROW][_COLUMN];
}Tab;


void reset_matrix(Tab *c, int ROW, int COL, char ch)
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

#endif