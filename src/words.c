#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "map.h"
#include "words.h"
#include "dll.h"







static int is_not_punctuation_or_space(char c)
{
    return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}


map_t get_map_from_str(char str[])
{

    map_t map_out = map_create();

    char *_str = malloc(sizeof(char) * 100);
    int j = 0;

    for(int i = 0; 1 ; i++)
    {
        if(is_not_punctuation_or_space(str[i]))
        {
            _str[j] = str[i];
        }
        else
        {
            if(_str[0] != '\0')
            {
                if(map_has(map_out,_str))
                {
                    map_set(map_out,_str,map_get(map_out,_str)+1);
                }
                else
                {
                    map_set(map_out, _str, 1);
                }
            }
            _str = NULL;
            free(_str);
            _str = malloc(sizeof(char) * 100);
            j = -1;
        }
        j++;

        if(str[i] == '\0')
        {
            break;
            free(_str);
        }
    }

    return map_out;
}

/*returns a struct with the most used word
(words if there are several with same number of use counts),
 and the number of occurrences of that word.
 arg n represents value under witch search will be made.*/
static map_elem_t _get_most_used_word(map_t map, int n)
{
    map_elem_t out = {.n = 0, .str = NULL};
    out.n = map_get(map, map_get_key(map, 0));
    dll_append(&(out.str), map_get_key(map, 0));
    int _n = INT_MAX;

    if (n != 0)
    {
        _n = n;
    }

    for (int i = 1; i < map_size(map); i++)
    {
        int val = map_get(map,map_get_key(map,i));
        if(val > out.n && val < _n)
        {
            dll_free(&(out.str),NULL);
            out.str = NULL;
            dll_append(&(out.str),map_get_key(map,i));
            out.n = val;
        }

        if(val == out.n)
        {
            dll_append(&(out.str),map_get_key(map,i));
        }
    }

    

    return out;
}

map_t get_map_of_most_used_words(map_t map)
{
    map_t out = map_create();
    int i = 15;
    if (map_size(map) < i)
    {
        i = map_size(map);
    }

    int value = 0;

    for (int j = 0; j != i; j++)
    {
        map_elem_t map_e = _get_most_used_word(map, value);
        value = map_e.n;

        for (dll_t *e = map_e.str; 1; e = e->next)
        {
            map_set(out, e->pvalue, map_e.n);

            if (e->next == map_e.str)
            {
                break;
            }
        }

        dll_free(&(map_e.str), NULL);
    }

    return out;
}
