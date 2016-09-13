#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "minesweeper.h"

struct cordinate id[20][20];	//max size grid

void close_game_window(GtkWidget *window, GdkEvent *event, gpointer pointer)
{
	//gtk_main_quit();
	gtk_widget_destroy(window);
}

void button_press(GtkWidget *button, GdkEvent *event, gpointer pointer)
{
	//if(((GdkEventButton *)event)->x == 1)
	
	struct cordinate *but = (struct cordinate *) pointer;
	//printf("%d  %d\n", but->row, but->col);
	int val = grid[but->row][but->col];
	char val_char[2];
	val_char[0] = val + '0';
	val_char[1] = '\0';
	
	if(((GdkEventButton *)event)->button == 3)	//right click
	{
		val_char[0] = '?';
		gtk_button_set_label(GTK_BUTTON(button), val_char);
	}
	else
	{
	
		if(val == -1)
			val_char[0] = 'X';
	
	
		gtk_button_set_label(GTK_BUTTON(button), val_char);
		gtk_widget_set_sensitive(button, 0);
		if(val == 0)
			dfs(but->row, but->col);
		if(val == -1)
		{
			loose_exit();
			gtk_widget_destroy(window);	//Game exit condition
			
		}
		else
			check();	//To know whether game is over or not
		
	}
	
}
void game_screen()
{
	//INITIALIZE THE GAME
	grid_row = 8;
	grid_col = 8;
	game_logic_initialize();
	

	//TOTAL WINDOW
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//gtk_window_set_gravity(GTK_WINDOW(window), GDK_GRAVITY_CENTER);
	//gtk_window_move(GTK_WINDOW(window), 300, 300);
	gtk_window_set_title(GTK_WINDOW(window), "MineSweeper By Amrutansu");
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(close_game_window), NULL);
	gtk_window_set_default_size(GTK_WINDOW(window), 900, 900);
	//gtk_window_set_resizable(GTK_WINDOW(window), 0);
	
	//EVERYTHING IS INSIDE THIS FRAME THAT ONLY PRINTS AUTHOR'S NAME
	GtkWidget *frame = gtk_frame_new("Amrutansu Garanaik");
	gtk_frame_set_label_align(GTK_FRAME(frame), 0.95, 0.5);
	gtk_container_add(GTK_CONTAINER(window), frame);
	gtk_container_set_border_width(GTK_CONTAINER(frame), 10);
	
	
	/**********************************************************************/
	
	GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	for(int i = 0; i < grid_row; i++)
	{
		GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
		gtk_box_set_homogeneous(GTK_BOX(hbox), 1);
		for(int j = 0; j < grid_col; j++)
		{
			button[i][j] = gtk_button_new_with_label(" ");
			id[i][j].row = i;
			id[i][j].col = j;
			
			g_signal_connect(G_OBJECT(button[i][j]), "button_press_event", G_CALLBACK(button_press),(gpointer) &id[i][j]);
			
			gtk_box_pack_start(GTK_BOX(hbox), button[i][j], 0, 1, 0);
			gtk_widget_show(button[i][j]);
		}
		gtk_widget_show(hbox);
		gtk_box_pack_start(GTK_BOX(vbox), hbox, 0, 1, 0);
	}
	gtk_box_set_homogeneous(GTK_BOX(vbox), 1);
	
	/**************************************************************************/
	
	gtk_container_add(GTK_CONTAINER(frame), vbox);
	gtk_widget_show(vbox);
	gtk_widget_show(frame);
	gtk_widget_show(window);
}
