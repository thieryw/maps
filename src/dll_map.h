#ifndef DLL_MAP_H
#define DLL_MAP_H


struct map_dll_elem_s
{
    char *key;
    int value;
};

typedef struct map_dll_elem_s map_dll_elem_t;


struct map_dll_s
{
    map_dll_elem_t *pvalue;
    struct map_dll_s *next;
    struct map_dll_s *prec;
}; 

typedef struct map_dll_s map_dll_t;


void map_dll_append(map_dll_t **pl, map_dll_elem_t e);
void map_dll_free(map_dll_t **pl);
void map_dll_delete(map_dll_t **pl, map_dll_t *e);
void map_dll_concat(map_dll_t **pl1, map_dll_t *l2);
char * map_dll_to_string(map_dll_t *l);
void map_dll_print(map_dll_t *l);

#endif