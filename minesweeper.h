#include <gtk/gtk.h>
#include "name.h"
struct cordinate
{
	int row;
	int col;
};

//Number of rows and columns in game
int grid_row;
int grid_col;
int visit[15][15];

//Same window will be reused as we need to close one and reopen another for each screen
GtkWidget *window;
GtkWidget *button[15][15];

void dfs(int , int );
void game_screen();
void home_screen();
void game_logic_initialize();
void check();
void win_exit();
void loose_exit();
void rules_game();

int argc2;
char **argv2;

int grid[20][20];
