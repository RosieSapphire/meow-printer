#ifndef MEOW_H
#define MEOW_H

#include "term.h"

namespace meow {
    void get_meow_count();
    void print_meow(const unsigned int &index, const term::color& col);
}

#endif
