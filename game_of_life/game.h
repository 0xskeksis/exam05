#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define ALIVE 'O'
#define DEAD ' '

typedef struct s_game{
	int	width;
	int	height;
	int iterations;
	bool	**board;
	bool	writing;
}t_game;
