#include "term.h"

#include <termios.h>
#include <sys/ioctl.h>

vec2<int> term::get_size() {
    struct winsize size;
    ioctl(1, TIOCGWINSZ, &size);
    return {size.ws_col, size.ws_row};
}