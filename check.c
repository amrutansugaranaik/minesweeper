//The logics to check whether game is over or not
//Approach - since only 10 bombs are there, count number of buttons not pressed, if 10, it is the end and the player wins
//This approach is slow but for 64X64 board, not a serious performance problem (IMO)

#include "minesweeper.h"

void check()
{
	int count = 0;
	for(int i = 0; i < grid_row; i++)
		for(int j = 0; j < grid_col; j++)
		{
			if(gtk_widget_get_sensitive(button[i][j]))
				count++;
		}
	if(count == 10)
	{
		printf("Game Over\n");
		win_exit();
		gtk_widget_destroy(window);
	}
}
