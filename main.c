#include <gtk/gtk.h>
#include "minesweeper.h"
int main(int argc, char **argv)
{
	gtk_init(&argc, &argv);
	home_screen();
	gtk_main();
}
