#include "game.h"
#include <stdbool.h>
#include <stdio.h>

bool	get_args(t_game *game, char **argv){
	game->width = atoi(argv[1]);
	game->height = atoi(argv[2]);
	game->iterations = atoi(argv[3]);

	if (game->width <= 0 || game->height <= 0 || game->iterations < 0)
		return false;
	return true;
}

void	process_input(t_game *game){
	char	c;
	int		x = 0;
	int		y = 0;

	while (read(STDIN_FILENO, &c, 1) > 0){
		switch(c){
			case '\n': return;
			case 'x': {
				game->writing = !game->writing;
				if (game->writing)
					game->board[y][x] = true;
				continue;
			}
			case 'w': {if (y > 0) y--; break;}
			case 's': {if (y < game->height - 1) y++; break;}
			case 'a': {if (x > 0) x--; break;}
			case 'd': {if (x < game->width - 1) x++; break;}
		}
		if (game->writing)
			game->board[y][x] = true;
	}
	return ;
}

void	print_board(int width, int height, bool **board){
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			if (board[i][j])
				putchar(ALIVE);
			else
				putchar(DEAD);
		}
		putchar('\n');
	}
}

bool **init_board(int width, int height){
    bool **board = calloc(height, sizeof(bool *));
    for (int i = 0; i < height; i++)
        board[i] = calloc(width, sizeof(bool));
    return board;
}

void
free_board(int width, int height, bool **board){
	for (int i = 0; i < height; i++)
		free(board[i]);
	free(board);
}

int
count_neighbours(bool **board, int x, int y, int width, int height){
    int count = 0;

    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0)
                continue;

            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < height && ny >= 0 && ny < width) {
                if (board[nx][ny])
                    count++;
            }
        }
    }

    return count;
}

bool
**solve_game(int width, int height, bool **board){
	bool **new_board = init_board(width, height);

	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			int count = count_neighbours(board, i, j, width, height);
			if (board[i][j])
				new_board[i][j] = (count == 2 || count == 3);
			else
				new_board[i][j] = (count == 3);
		}
	}
	free_board(width, height, board);
	return new_board;
}

int main(int argc, char **argv){
	if (argc != 4) return 1;

	t_game	game = {0};

	if (get_args(&game, argv) == false) return 1;
	game.board = init_board(game.width, game.height);
	process_input(&game);
	for (int i = 0; i < game.iterations; i++){
		bool **new_board = solve_game(game.width, game.height, game.board);
		game.board = new_board;
	}
	print_board(game.width, game.height, game.board);
	free_board(game.width, game.height, game.board);
}
