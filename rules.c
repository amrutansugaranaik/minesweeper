#include <gtk/gtk.h>
#include "minesweeper.h"
void close_rules_window(GtkWidget *window, GdkEvent *event, gpointer pointer)
{
	gtk_widget_destroy(window);
}
void rules_game()
{
	//TOTAL WINDOW
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//gtk_window_set_gravity(GTK_WINDOW(window), GDK_GRAVITY_CENTER);
	gtk_window_move(GTK_WINDOW(window), 300, 300);
	gtk_window_set_title(GTK_WINDOW(window), "MineSweeper By Amrutansu");
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(close_rules_window), NULL);
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);
	gtk_window_set_resizable(GTK_WINDOW(window), 0);
	
	
	
	//EVERYTHING IS INSIDE THIS FRAME THAT ONLY PRINTS AUTHOR'S NAME
	GtkWidget *frame = gtk_frame_new("Amrutansu Garanaik");
	gtk_frame_set_label_align(GTK_FRAME(frame), 0.95, 0.5);
	gtk_container_add(GTK_CONTAINER(window), frame);
	gtk_widget_show(frame);
	
	GtkWidget *label;
	char text[] = "\n\tThis is an interesting puzzle\n\n \
			Here are the rules :-\n \
			\t1) The game consists of 8X8 covered boxes.\n \
			\t2) Under these, 10 boxes have bombs \n \
			\t3) You have to click on the boxes to uncover them \n \
			\t4) You are not supposed to click any of the box covering the bombs \n \
			\t5) Also you have to click all the other boxes.\n \
			\t6) So the game ends when all boxes are uncovered and bombs are left untouched \t \n \
			\t7) To help you, you can right click on the boxes to put a ? mark on it \n \
			\t8) Also, when you uncover a box, it displays the \n \
			\t   number of bombs present around it.\n \
			\n\tPlay the game and you will understand :)\n";
	label = gtk_label_new("");
	gtk_label_set_text(GTK_LABEL(label), text);
	gtk_container_add(GTK_CONTAINER(frame), label);
	gtk_widget_show(label);
	
	
	gtk_widget_show(window);
	
}
