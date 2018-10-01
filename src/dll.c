#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"
 
void dll_append(dll_t **pl, void * pvalue)
{
    dll_t *e = malloc(sizeof(dll_t));
 
    if (*pl == NULL)
    {
 
        *e = (dll_t){.next = e, .prec = e, .pvalue = pvalue };
 
        *pl = e;
 
    }
    else
    {
 
        *e = (dll_t){.next = *pl, .prec = (*pl)->prec, .pvalue = pvalue};
 
        (*pl)->prec->next = e;
 
        (*pl)->prec = e;
    }
}

void dll_free(dll_t **pl, void (*free_value)(void *pvalue)){

    while ((*pl) != NULL)
    {
        dll_delete(pl, *pl, free_value);
    }
}

void dll_delete(dll_t **pl, dll_t *e, void (*free_value)(void *pvalue))
{

    if (e == *pl)
    {

        if ((*pl)->next == *pl)
        {
            *pl = NULL;
        }
        else
        {
            *pl = (*pl)->next;
        }
    }

    e->prec->next = e->next;
    e->next->prec = e->prec;

    if (e->pvalue != NULL)
    {

        if( free_value != NULL ){

            free_value(e->pvalue);

        }

        free(e->pvalue);

        e->pvalue = NULL;

    }

    free(e);
}

char *dll_to_string(dll_t *l, char *(*value_to_string)(void *))
{

    char *str = malloc(sizeof(char) * 1);

    str[0] = '\0';

    if (l == NULL)
    {
        return str;
    }

    for (dll_t *e = l; 1; e = e->next)
    {

        char *value_str = value_to_string(e->pvalue);

        char *new_str = malloc(sizeof(char) * (strlen(str) + strlen(value_str) + 1));

        sprintf(new_str, "%s%s ", str, value_str);

        free(value_str);
        free(str);

        str = new_str;

        if (e->next == l)
        {
            break;
        }
    }

    return str;
}

void dll_print( dll_t *l, char *(*value_to_string)(void *))
{

    char *str = dll_to_string(l, value_to_string);

    printf("%s\n", str);

    free(str);
}

void dll_concat( dll_t **pl1,  dll_t *l2)
{
    if (*pl1 == NULL)
    {
        *pl1 = l2;
        return;
    }

    if (l2 == NULL)
    {
        return;
    }

    (*pl1)->prec->next = l2;
    l2->prec->next = (*pl1);

     dll_t *e = l2->prec;

    l2->prec = (*pl1)->prec;
    (*pl1)->prec = e;
}