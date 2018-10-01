#ifndef WORDS_H
#define WORDS_H
#include "map.h"
#include "dll.h"

struct map_elem_s
{
    int n;
    dll_t *str;
};

typedef struct map_elem_s map_elem_t;


map_t get_map_from_str(char str[]);

map_t get_map_of_most_used_words(map_t map);








#endif