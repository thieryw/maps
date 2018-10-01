#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "map.h"
#include "dll_map.h"
#include "dll.h"



map_t map_create(){

    map_t map = malloc( sizeof(struct map_s) );

    *map = (struct map_s){ .size=0, .list = NULL };
    
    return map;

}

void map_free(map_t map){

    


    map_dll_free( &(map->list) );

    free(map);

}

void map_set(map_t map, char key[], int value)
{
    if (map->list == NULL)
    {
        map->size = 1;


        map_dll_elem_t e; 

        e.value = value;
        e.key = malloc(sizeof(char) * (strlen(key) + 1));

        sprintf(e.key,"%s",key);


        map_dll_append(&(map->list), e);


        return;
    }

    for (map_dll_t *e = map->list; 1; e = e->next)
    {
        if (!strcmp(e->pvalue->key, key))
        {
            e->pvalue->value = value;
            break;
        }

        if (e->next == map->list)
        {
            map->size = map->size + 1;

             map_dll_elem_t _e;

             _e.value = value; 
             _e.key = malloc(sizeof(char) * (strlen(key) + 1));

            sprintf(_e.key, "%s", key);


            map_dll_append(&(map->list), _e);

            break;
        }
    }
}

int map_get(map_t map, char key[])
{
    for(map_dll_t *e = map->list; 1; e = e->next)
    {
        if(!strcmp(e->pvalue->key, key))
        {
            return e->pvalue->value;
        }

        if(e->next == map->list)
        {
            assert(0 && "must be in map!\n");
        }
    }
}
int map_size(map_t map)
{
    return map->size;
}

char *map_get_key(map_t map, int index)
{
    map_dll_t *e = map->list;

    int _map_size = map_size(map);

    if(index > _map_size || index < 0)
    {
        char *out = malloc(sizeof(char));
        out[0] = '\0';
        return out;
    }




    for(int i = 0; i < map_size(map); i++)
    {
        if(i == index)
        {
            char *out = malloc(sizeof(char) * (strlen(e->pvalue->key) + 1));
            sprintf(out,"%s",e->pvalue->key);
            return out;
        }
        
        e = e->next;
    }
}

uint8_t map_has(map_t map, char key[])
{
    if(map->list == NULL)
    {
        return 0;
    }

    for(map_dll_t *e = map->list; 1; e = e->next)
    {
        if(!strcmp(e->pvalue->key,key))
        {
            return 1;
        }

        if(e->next == map->list)
        {
            return 0;
        }
    }
}

void map_delete(map_t map, char key[])
{
    for(map_dll_t *e = map->list; 1; e = e->next)
    {
        if(!strcmp(e->pvalue->key,key))
        {
            map_dll_delete(&(map->list),e);
            break;
        }

        if(e->next == map->list)
        {
            break;
        }
    }
    map->size = map->size - 1;
}

void map_print(map_t map)
{
    char *str = map_dll_to_string(map->list);

    printf("%s\n",str);

    free(str);
}

char * map_to_string(map_t map)
{
    char *out = map_dll_to_string(map->list);
    return out;
}






