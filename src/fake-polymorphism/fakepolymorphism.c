#include "fakepolymorphism.h"

#include <stdio.h>
#include <stdlib.h>

void printDog(AnimalObject o) {
    Dog dog = o.dog;
    printf("What the dog is doing? His name is %s\n", dog.name);
}

void printCat(AnimalObject o) {
    Cat cat = o.cat;
    printf("A short Munchkin cat. His name is %s\n", cat.name);
}

Animal* makeDog(const char* name) {
    Animal* dog = malloc(sizeof(Animal));
    if (!dog) return NULL;

    *dog = (Animal){.object.dog.name = name, .print = printDog};

    return dog;
}

Animal* makeCat(const char* name) {
    Animal* cat = malloc(sizeof(Animal));
    if (!cat) return NULL;

    *cat = (Animal){.object.cat.name = name, .print = printCat};

    return cat;
}
