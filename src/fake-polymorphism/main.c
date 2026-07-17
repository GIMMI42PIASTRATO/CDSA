#include <stdio.h>

#include "fakepolymorphism.h"

#define ANIMALS_LEN 2

int main(void) {
    Animal* animals[ANIMALS_LEN];

    animals[0] = makeDog("Luna");
    animals[1] = makeCat("Stella");

    for (size_t i = 0; i < ANIMALS_LEN; i++) {
        animals[i]->print(animals[i]->object);
    }

    return 0;
}
