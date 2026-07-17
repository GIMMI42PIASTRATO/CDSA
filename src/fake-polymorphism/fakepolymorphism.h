#ifndef POLYMORPHISM_H
#define POLYMORPHISM_H

typedef struct {
    const char* name;
} Dog;

typedef struct {
    const char* name;
} Cat;

typedef union {
    Dog dog;
    Cat cat;
} AnimalObject;

typedef struct {
    AnimalObject object;
    void (*print)(AnimalObject o);
} Animal;

Animal* makeDog(const char* name);
Animal* makeCat(const char* name);
#endif
