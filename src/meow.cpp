#include "meow.h"

#include <iostream>
#include <unistd.h>
#include <cmath>

void meow::get_meow_count() {
    unsigned int meows;
    std::cout << "How many meows would you like? (0 for continuous): ";
    std::cin >> meows;

    bool colorful;
    std::cout << "Would you like it to be colorful? (0 = no, 1 = yes): ";
    std::cin >> colorful;

    putchar('\n');

    if(meows == 0) {
        for (int i = 0;; i++) {
            print_meow(i, colorful ? term::color(1 + (i % 4)) : term::color::NORMAL);
        }
    } else {
        for (int i = 0; i < meows; i++) {
            const auto col = term::color(1 + rand() % 4);
            print_meow(i, colorful ? term::color(1 + (i % 4)) : term::color::NORMAL);
        } 
    }
}

void meow::print_meow(const unsigned int &index, const term::color& col) {
    const int octaves[3] = {
        static_cast<int>((sinf(index * 0.236f) + 1.0f) * 18.6f),
        static_cast<int>((cosf(index * 0.077f) + 1.0f) * 12.3f),
        static_cast<int>((sinf(index * 0.034f) + 1.0f) * 8.9f),
    }; const int octaves_added = octaves[0] + octaves[1] + octaves[2];

    for (int i = 0; i < octaves_added; i++) {
        putchar(' ');
    }

    switch(col) {
        case term::color::RED:
            printf("%sMeow qwq\n%s", TERM_RED, TERM_NORMAL);
            break;

        case term::color::YELLOW:
            printf("%sMeow qwq\n%s", TERM_YELLOW, TERM_NORMAL);
            break;

        case term::color::GREEN:
            printf("%sMeow qwq\n%s", TERM_GREEN, TERM_NORMAL);
            break;

        case term::color::BLUE:
            printf("%sMeow qwq\n%s", TERM_BLUE, TERM_NORMAL);
            break;

        default:
            printf("Meow qwq\n");
            break;
    }
    usleep(15000);
}
