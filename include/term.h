#ifndef TERM_H
#define TERM_H

#include <stdio.h>

#define TERM_NORMAL  "\x1B[0m"
#define TERM_RED     "\x1B[1;31m"
#define TERM_GREEN   "\x1B[1;32m"
#define TERM_YELLOW  "\x1B[1;33m"
#define TERM_BLUE    "\x1B[1;34m"
#define TERM_MAGENTA "\x1B[1;35m"
#define TERM_CYAN    "\x1B[1;36m"
#define TERM_WHITE   "\x1B[1;37m"

#define TERM_BG_NORMAL  "\x1B[40m"
#define TERM_BG_RED     "\x1B[41m"
#define TERM_BG_GREEN   "\x1B[42m"
#define TERM_BG_YELLOW  "\x1B[43m"
#define TERM_BG_BLUE    "\x1B[44m"
#define TERM_BG_MAGENTA "\x1B[45m"
#define TERM_BG_CYAN    "\x1B[46m"
#define TERM_BG_WHITE   "\x1B[47m"

#define TERM_MOVE_CURSOR(VEC) printf("\033[%d;%dH", VEC.y, VEC.x)

#endif
