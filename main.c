


#include "table.h"
#include "main.h"

void draw_table(Tab* );
void draw_next_piece();
void draw_frame();


int main()
{
    
    
    
    Tab Tabellone;
    char c;
    c = 0;
    printf("%s \n", _TITLE);
    printf("%s \n", _WELCOME_MESS);
    scanf ("%c", &c);
    if(c)
    {

        system("clear");
        printf("%s \n", _TITLE);
   
        init_tab(&Tabellone);

        draw_table(&Tabellone);
    
    }
    
    /*unsigned char b = 35;
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%c", b);
    }*/
    return 0;
}


void draw_table(Tab* T)
{
    int i;
    int j;
    for (i = 0; i<_ROW; i++)
    {
        for(j = 0; j < _COLUMN; j++)
        {
            printf("%c", T->matrix[i][j]);
        }
        printf("\n");
    }
}