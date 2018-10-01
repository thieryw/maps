#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll_map.h"
#include "dll.h"



void map_dll_append(map_dll_t **pl, map_dll_elem_t e){

   map_dll_elem_t *pe = malloc(sizeof(map_dll_elem_t));

   *pe = (map_dll_elem_t){.value = e.value, .key = e.key};

   dll_append(pl, pe);
}

static char * free_value(map_dll_elem_t * pvalue)
{
    free(pvalue->key);
}

void map_dll_free(map_dll_t **pl)
{
    dll_free(pl, free_value);
}


void map_dll_delete(map_dll_t **pl, map_dll_t *e)
{
    dll_delete(pl, e, free_value);
}

void map_dll_concat(map_dll_t **pl1, map_dll_t *l2)
{
    dll_concat(pl1, l2);
}

static char * map_value_to_string(map_dll_elem_t *pvalue)
{
    char *out; 
    out = malloc(sizeof(char) * (strlen(pvalue->key) + 16));
    sprintf(out,"%s->%d",pvalue->key,pvalue->value);
    return out;
}

char * map_dll_to_string(map_dll_t *l)
{
    char *out = dll_to_string(l,map_value_to_string);
    return out;
}

void map_dll_print(map_dll_t *l)
{
    dll_print(l,map_value_to_string);
}