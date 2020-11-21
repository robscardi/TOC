

#ifndef _PIECES_H
#define _PIECES_H



#include "main.h"

#define _DIM 4

#define _DIMSQR 2

#define _DIMLINE 4

#define _L_SIDE 3

#define _S_SIDE 4

#define _T_SIDE 3



typedef struct{
    int x;
    int y;
}pos;

typedef unsigned char Piece[_DIM][_DIM];



const Piece Square = {{' ',' ',' ',' '},
                      {' ',' ',' ',' '},
                      {' ',' ','#','#'},
                      {' ',' ','#','#'}};

const Piece Line_col = {{' ','#',' ',' '},
                        {' ','#',' ',' '},
                        {' ','#',' ',' '},
                        {' ','#',' ',' '}};

const Piece Line_row = {{' ',' ',' ',' '},
                        {' ',' ',' ',' '},
                        {'#','#','#','#'},
                        {' ',' ',' ',' '}};

const Piece L_Left_Zero = {{'#',' ',' ',' '},
                           {'#',' ',' ',' '},
                           {'#','#',' ',' '},
                           {' ',' ',' ',' '}};

const Piece L_Left_PIHALF = {{' ',' ',' ',' '},
                             {'#','#','#',' '},
                             {'#',' ',' ',' '},
                             {' ',' ',' ',' '}};

const Piece L_Left_PI = {{'#','#',' ',' '},
                         {' ','#',' ',' '},
                         {' ','#',' ',' '},
                         {' ','#',' ',' '}};

const Piece L_Left_PITHREEHALF = {{' ',' ','#',' '},
                                  {'#','#','#',' '},
                                  {' ',' ',' ',' '},
                                  {' ',' ',' ',' '}};

const Piece L_Right_Zero = {{' ','#',' ',' '},
                            {' ','#',' ',' '},
                            {'#','#',' ',' '},
                            {' ',' ',' ',' '}};

const Piece L_Right_PIHALF = {{'#',' ',' ',' '},
                              {'#','#','#',' '},
                              {' ',' ',' ',' '},
                              {' ',' ',' ',' '}};

const Piece L_Right_PI = {{' ','#','#',' '},
                          {' ','#',' ',' '},
                          {' ','#',' ',' '},
                          {' ','#',' ',' '}};

const Piece L_Right_PITHREEHALF = {{' ',' ',' ',' '},
                                   {'#','#','#',' '},
                                   {' ',' ','#',' '},
                                   {' ',' ',' ',' '}};

const Piece S_Left_row =  {{' ',' ',' ',' '},
                           {' ','#','#',' '},
                           {'#','#',' ',' '},
                           {' ',' ',' ',' '}};

const Piece S_Left_col =  {{' ','#',' ',' '},
                           {' ','#','#',' '},
                           {' ',' ','#',' '},
                           {' ',' ',' ',' '}};

const Piece S_Right_row =  {{' ',' ',' ',' '},
                           {' ','#','#',' '},
                           {'#','#',' ',' '},
                           {' ',' ',' ',' '}};

const Piece S_Right_col =  {{' ',' ','#',' '},
                            {' ','#','#',' '},
                            {' ','#',' ',' '},
                            {' ',' ',' ',' '}};

const Piece T_ZERO =   {{' ','#',' ',' '},
                        {'#','#','#',' '},
                        {' ',' ',' ',' '},
                        {' ',' ',' ',' '}};

const Piece T_PIHALF =   {{' ','#',' ',' '},
                          {' ','#','#',' '},
                          {' ','#',' ',' '},
                          {' ',' ',' ',' '}};

const Piece T_PI =   {{' ',' ',' ',' '},
                      {'#','#','#',' '},
                      {' ','#',' ',' '},
                      {' ',' ',' ',' '}};

const Piece T_PITHREEHALF =   {{' ','#',' ',' '},
                               {'#','#',' ',' '},
                               {' ','#',' ',' '},
                               {' ',' ',' ',' '}};





bool_t init_controll_collision(Tab t, char p[][_DIM], pos pos )
{
    bool_t res;
    int i;
    int j;
    int num;
    res = true;
    for ( i = 0; i < _DIM; i++)
    {
        for (j = 0; j < _DIM; j++)
        {
            num = t.matrix[i + pos.y][j +pos.x] + p[i][j];
            
            if (num != _BLOCK + _VOID_CH && num!= _VOID_CH * 2 )
            {
                res = false;
            }
        }
    }
    return res;

}

#endif

