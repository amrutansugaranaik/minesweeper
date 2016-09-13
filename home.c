#include <gtk/gtk.h>
#include "minesweeper.h"
void close_window(GtkWidget *window, GdkEvent *event, gpointer pointer)
{
	gtk_main_quit();
}
void return_dimension(GtkWidget *button, GdkEvent *event, gpointer pointer)
{
	game_screen();	
}
void home_screen()
{
	//TOTAL WINDOW
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//gtk_window_set_gravity(GTK_WINDOW(window), GDK_GRAVITY_CENTER);
	gtk_window_move(GTK_WINDOW(window), 300, 300);
	gtk_window_set_title(GTK_WINDOW(window), "MineSweeper By Amrutansu");
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(close_window), NULL);
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);
	gtk_window_set_resizable(GTK_WINDOW(window), 0);
	
	
	
	//EVERYTHING IS INSIDE THIS FRAME THAT ONLY PRINTS AUTHOR'S NAME
	GtkWidget *frame = gtk_frame_new("Amrutansu Garanaik");
	gtk_frame_set_label_align(GTK_FRAME(frame), 0.95, 0.5);
	gtk_container_add(GTK_CONTAINER(window), frame);
	gtk_widget_show(frame);
	
	
	
	//AN IMAGE TO DISPLAY THE NAME OF THE GAME 
	//GtkWidget *image = gtk_image_new_from_file("name.jpg");
	GdkPixbuf *pixbuf = gdk_pixbuf_new_from_inline(-1, myimage_inline, FALSE, NULL);
	GtkWidget *image = gtk_image_new_from_pixbuf(pixbuf);
	gtk_widget_show(image);
	
	
	
	//A FRAME TO INPUT DIMENSIONS
	GtkWidget *frame2 = gtk_frame_new("Dimensions : 8 X 8 grid, 10 bombs");	
	gtk_frame_set_label_align(GTK_FRAME(frame2), 0.5, 0.5);
	gtk_widget_show(frame2);
	gtk_container_set_border_width(GTK_CONTAINER(frame2), 10);
	//gtk_container_add(GTK_CONTAINER(frame), frame2);
	
	
	
	
	//TWO BUTTONS FOR START GAME AND RULES DISPLAY
	GtkWidget *button1, *button2;
	button1 = gtk_button_new_with_label("START");
	button2 = gtk_button_new_with_label("RULES");
	g_signal_connect(G_OBJECT(button1), "clicked", G_CALLBACK(return_dimension), NULL);
	g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(rules_game), NULL);
	gtk_widget_show(button1);
	gtk_widget_show(button2);
	
	
	
	//A BOX TO STORE IMAGE, DIMENSIONS AND BUTTONS
	GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 9);
	gtk_container_set_border_width(GTK_CONTAINER(box), 10);
	gtk_box_pack_start(GTK_BOX(box), image, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(box), frame2, 1, 1, 0);
	gtk_box_pack_start(GTK_BOX(box), button1, 0, 0, 0);
	gtk_box_pack_start(GTK_BOX(box), button2, 0, 0, 0);
	
	
	
	gtk_container_add(GTK_CONTAINER(frame), box);
	//gtk_box_set_homogeneous(GTK_BOX(box), 1);
	gtk_widget_show(box);
	
	gtk_widget_show(window);
	
}
