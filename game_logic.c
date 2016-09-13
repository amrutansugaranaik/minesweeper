#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "minesweeper.h"
void game_logic_initialize()
{
	int total = grid_row * grid_col;
	total *= 2;
	total /= 3;
	int bomb = 10;
	
	for(int i = 0; i < grid_row; i++)
		for(int j = 0; j < grid_col; j++)
			grid[i][j] = 0, visit[i][j] = 0;
	
	while(1)
	{
		int r = rand() % grid_row;
		int c = rand() % grid_col;
		if(grid[r][c] == 0)
		{
			grid[r][c] = -1;
			bomb--;
		}
		if(!bomb)
			break;
	}
	for(int i = 0; i < grid_row; i++)
		for(int j = 0; j < grid_col; j++)
		{
			if(grid[i][j] == -1)	//bomb
				continue;
			int count = 0;
			int r, c;
			
			r = i-1;
			c = j-1;
			
			if(r >= 0 && c >= 0 && r < grid_row && c < grid_col)
				if(grid[r][c] == -1)
					count++;
			
			r = i-1;
			c = j;
			
			if(r >= 0 && c >= 0 && r < grid_row && c < grid_col)
				if(grid[r][c] == -1)
					count++;
			
			r = i-1;
			c = j+1;
			
			if(r >= 0 && c >= 0 && r < grid_row && c < grid_col)
				if(grid[r][c] == -1)
					count++;
			
			r = i;
			c = j-1;
			
			if(r >= 0 && c >= 0 && r < grid_row && c < grid_col)
				if(grid[r][c] == -1)
					count++;
					
			r = i;
			c = j+1;
			
			if(r >= 0 && c >= 0 && r < grid_row && c < grid_col)
				if(grid[r][c] == -1)
					count++;
					
			r = i+1;
			c = j-1;
			
			if(r >= 0 && c >= 0 && r < grid_row && c < grid_col)
				if(grid[r][c] == -1)
					count++;
					
			r = i+1;
			c = j;
			
			if(r >= 0 && c >= 0 && r < grid_row && c < grid_col)
				if(grid[r][c] == -1)
					count++;
					
			r = i+1;
			c = j+1;
			
			if(r >= 0 && c >= 0 && r < grid_row && c < grid_col)
				if(grid[r][c] == -1)
					count++;
			grid[i][j] = count;
			
		}
}
char val_char[2];
void dfs(int row, int col)
{
	if(row > 0)
	{
		if(visit[row-1][col] == 0)
		{
			//if(grid[row-1][col] == 0)
				gtk_widget_set_sensitive(button[row-1][col], 0);
			
			val_char[0] = grid[row-1][col] + '0';
			val_char[1] = '\0';
			
			gtk_button_set_label(GTK_BUTTON(button[row-1][col]), val_char);
			visit[row-1][col] == 1;
			if(grid[row-1][col] == 0)
				dfs(row-1, col);
		}
	}
	if(row < grid_row-1)
	{
		if(visit[row+1][col] == 0)
		{
			//if(grid[row+1][col] == 0)
				gtk_widget_set_sensitive(button[row+1][col], 0);
				
			val_char[0] = grid[row+1][col] + '0';
			val_char[1] = '\0';	
			
			gtk_button_set_label(GTK_BUTTON(button[row+1][col]), val_char);	
			visit[row+1][col] = 1;
			if(grid[row+1][col] == 0)
				dfs(row+1, col);
		}
	}
	if(col > 0)
	{
		if( visit[row][col-1] == 0)
		{
			//if(grid[row][col-1] == 0)
				gtk_widget_set_sensitive(button[row][col-1], 0);
			
			val_char[0] = grid[row][col-1] + '0';
			val_char[1] = '\0';
			
			gtk_button_set_label(GTK_BUTTON(button[row][col-1]), val_char);	
			visit[row][col-1] = 1;
			if(grid[row][col-1] == 0)
				dfs(row, col-1);
		}
	}
	if(col < grid_col-1)
	{
		if( visit[row][col+1])
		{
			//if(grid[row][col+1] == 0)
				gtk_widget_set_sensitive(button[row][col+1], 0);
				
			val_char[0] = grid[row][col+1] + '0';
			val_char[1] = '\0';	
				
			gtk_button_set_label(GTK_BUTTON(button[row][col+1]), val_char);	
			visit[row][col+1] = 1;
			if(grid[row][col+1] == 0 )
				dfs(row, col+1);
		}
	}
}
