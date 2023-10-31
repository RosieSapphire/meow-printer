#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <unistd.h>

#include "term.h"
#include "datatypes.h"

static sint32 meows;
static sint32 is_colorful;
static uint8 col_num;

static const char *colors[5] = {
	TERM_RED,
	TERM_YELLOW,
	TERM_GREEN,
	TERM_BLUE,
	TERM_MAGENTA,
};

void print_meows(const uint32 i, const char *col)
{
	uint32 j;
	sint32 octaves[3];
	uint32 octave_sum;

	octaves[0] = (sint32)((sin(i * 0.236f) + 1.0f) * 18.6f);
	octaves[1] = (sint32)((cos(i * 0.077f) + 1.0f) * 12.3f);
	octaves[2] = (sint32)((sin(i * 0.034f) + 1.0f) * 8.9f);
	octave_sum = octaves[0] + octaves[1] + octaves[2];

	for (j = 0; j < octave_sum; j++)
		putchar(' ');

	printf("%sMeow qwq\n%s", col, TERM_NORMAL);
	usleep(15000);
}

static void _print_meows_infinite(void)
{
	uint32 i = 0;

	while (1)
	{
		print_meows(i, is_colorful ? colors[col_num] : TERM_NORMAL);
		col_num++;
		col_num %= 5;
		i++;
	}
}

static void _print_meows_finite(void)
{
	uint32 i = 0;

	for (i = 0; i < meows; i++)
	{
		print_meows(i, is_colorful ? colors[col_num] : TERM_NORMAL);
		col_num++;
		col_num %= 5;
	}
}

int main(void)
{
	printf("How many meows would you like? (0 for continuous): ");
	scanf("%d", &meows);

	printf("Would you like it to be colorful? (0 = no, 1 = yes): ");
	scanf("%d", &is_colorful);
	putchar('\n');

	if (!meows)
		_print_meows_infinite();
	else
		_print_meows_finite();

	return (0);
}
