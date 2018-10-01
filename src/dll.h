#ifndef DLL_H
#define DLL_H

struct dll_s
{
    void * pvalue;
    struct dll_s *next;
    struct dll_s *prec;
};

typedef struct dll_s dll_t;

/** value must be allocated with malloc, will be free internally */
void dll_append(dll_t **pl, void * pvalue);
/** 
 * free_value should only free the pointers that could be hold within the value.
 * If not applicable provide NULL as free_value.
*/
void dll_free(dll_t **pl, void (*free_value)(void *pvalue));
void dll_delete(dll_t **pl, dll_t *e, void (*free_value)(void *pvalue));

/** 
 * return a string representing the list.
 * Need to be feed!
 */
char *dll_to_string(dll_t *l, char * (*value_to_string)(void *));

void dll_print(dll_t *l, char * (*value_to_string)(void *)); 
/** l will be concatenated at the end of pl */ 
 void dll_concat(dll_t **pl1, dll_t *l2);

#endif