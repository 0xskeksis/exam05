#include "game.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool
process_char(t_game *game, char c){
	static int x = 0;
	static int y = 0;


	if (c == '\n')
		return false;
	switch (c){
		case 'x':{
			game->writing = !game->writing;
			if (game->writing)
				game->board[y][x] = true;
			return true;
		}
		case 'w':{if (y > 0) y--; break;}
		case 's':{if (y < game->height) y++; break;}
		case 'a':{if (x > 0) x--; break;}
		case 'd':{if (x < game->width) x++; break;}
	}
	if (game->writing)
		game->board[y][x] = true;
	return true;
}

bool
read_input(t_game *game){
	char	c;

	while (read(STDIN_FILENO, &c, 1) > 0){
		if (!process_char(game, c))
			return true;
	}
	return true;
}

void
init_board(t_game *game){
	game->board = calloc(sizeof(bool *), game->height);
	for (int i =0; i < game->height; i++){
		game->board[i] = calloc(sizeof(bool), game->width);
	}
}

bool
get_args(t_game *game, char **argv){
	game->width = atoi(argv[1]);
	game->height = atoi(argv[2]);
	game->iterations = atoi(argv[3]);

	if (game->width <= 0 || game->height <= 0 || game->iterations < 0)
		return false;
	return true;
}

void
print_board(t_game *game){
	for (int i = 0; i < game->height; i++){
		for (int j = 0; j < game->width; j++){
			if (game->board[i][j] == true)
				putchar(ALIVE);
			else
				putchar(DEAD);
		}
		putchar('\n');
	}
}

void
free_board(t_game *game, bool **board){
	for (int i = 0; i < game->height; i++){
		free(board[i]);
	}
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

void
solve_game(t_game *game){
	bool **new_board;

	new_board = malloc(sizeof(bool *) * (game->height));
	for (int i = 0; i < game->height; i++)
		new_board[i] = malloc(sizeof(bool) * game->width);

	for (int i = 0; i < game->height; i++){
		for (int j = 0; j < game->width; j++){
			int count = count_neighbours(game->board, i, j, game->width, game->height);
			if (game->board[i][j])
				new_board[i][j] = (count == 2 || count == 3);
			else
				new_board[i][j] = (count == 3);
		}
	}
	free_board(game, game->board);
	game->board = new_board;
}

int	main(int argc, char **argv){
	if (argc != 4)
		return (1);

	t_game game = {0};

	if (!get_args(&game, argv))
		return (1);
	init_board(&game);
	read_input(&game);
	if (game.iterations == 0){
		print_board(&game);
		free_board(&game, game.board);
		return (0);
	}
	for (int i = 0; i != game.iterations; i++){
		solve_game(&game);
	}
	print_board(&game);
	free_board(&game, game.board);
}
