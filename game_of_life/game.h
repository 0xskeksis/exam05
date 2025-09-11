#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define DEAD ' '
#define ALIVE 'O'

typedef struct	s_game{
	bool **board;
	int	width;
	int	height;
	int	iterations;
	bool	writing;
}t_game;
