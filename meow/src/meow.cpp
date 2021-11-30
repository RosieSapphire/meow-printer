#include "meow.h"

#include <iostream>
#include <unistd.h>
#include <cmath>

void meow::get_meow_count() {
    unsigned int meows;
    std::cout << "How many meows would you like?: ";
    std::cin >> meows;

    for (unsigned int i = 0; i < meows; i++) {
        print_meow(i);
    }
}

void meow::print_meow(const unsigned int &index) {
    const int octaves[3] = {
        static_cast<int>((sinf(index * 0.236f) + 1.0f) * 18.6f),
        static_cast<int>((cosf(index * 0.077f) + 1.0f) * 12.3f),
        static_cast<int>((sinf(index * 0.034f) + 1.0f) * 8.9f),
    }; const int octaves_added = octaves[0] + octaves[1] + octaves[2];

    for (int i = 0; i < octaves_added; i++) {
        std::cout << ' ';
    }

    std::cout << "Meow qwq" << std::endl;
    usleep(15000);
}