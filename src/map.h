#ifndef MAP_H
#define MAP_H
#include <stdint.h>
#include "dll_map.h"

struct map_s {
    int size;
    map_dll_t *list;
};

typedef struct map_s* map_t;

map_t map_create();

void map_free(map_t map);

void map_set(map_t map, char key[], int value);

int map_get(map_t map, char key[]);

int map_size(map_t map);

char * map_get_key(map_t map, int index);

uint8_t map_has(map_t map, char key[]);

void map_delete(map_t map, char key[]);

void map_print(map_t map);

char * map_to_string(map_t map);

#endif