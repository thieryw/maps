#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "map.h"
#include "words.h"

void start_tests(void);




int main(int argc, char argv[])
{
    if (argc == 1)
    {
        map_t map = get_map_from_str(" jslkdj ., sfdj :sdf :ee :e, sdf k jai jai uu uu uu uu...?");

        //map = get_map_from_str("j'ai envie ..? de , faire faire caca caca caca dans dans les toilettes toilettes toilettes .");


        map_print(map);

        map_t m_u_v = get_map_of_most_used_words(map);
        map_print(m_u_v);

        
    }
    else
    {
        start_tests();
        return 0;
    }
}

void test_1(void)
{
    map_t map = map_create();
    map_set(map, "hello", 12);

    assert(map_size(map) == 1);

    assert(map_get(map, "hello") == 12);

    map_free(map);

    printf("PASS 1\n");
}

void test_2(void)
{
    map_t map = map_create();
    map_set(map, "hello", 12);
    map_set(map, "goodbye", 13);
    map_set(map, "yes", 14);
    map_set(map, "no", 15);

    assert(map_size(map) == 4);
    assert(map_get(map, "hello") == 12);
    assert(map_get(map, "goodbye") == 13);
    assert(map_get(map, "yes") == 14);
    assert(map_get(map, "no") == 15);

    printf("PASS 2\n");
    map_free(map);
}

void test_3(void)
{
    map_t map = map_create();
    map_set(map, "hello", 12);
    map_set(map, "goodbye", 13);
    map_set(map, "yes", 14);

    assert(map_get(map, "yes") == 14);

    map_set(map, "yes", 15);

    assert(map_get(map, "yes") == 15);

    printf("PASS 3\n");

    map_free(map);
}

void test_4(void)
{
    map_t map = map_create();
    map_set(map, "hello", 12);
    map_set(map, "goodbye", 13);
    map_set(map, "yes", 14);

    char *str_1 = map_get_key(map, 0);
    char *str_2 = map_get_key(map, 1);
    char *str_3 = map_get_key(map, 2);

    assert(!strcmp(str_1, "hello"));
    assert(!strcmp(str_2, "goodbye"));
    assert(!strcmp(str_3, "yes"));
    map_free(map);

    free(str_1);
    free(str_2);
    free(str_3);

    printf("PASS 4\n");
}

void test_5(void)
{

    map_t map = map_create();
    map_set(map, "hello", 12);
    map_set(map, "goodbye", 13);
    map_set(map, "dd", 14);
    map_set(map, "nn", 14);
    map_set(map, "yes", 14);

    assert(map_has(map, "hello"));
    assert(map_has(map, "dd"));
    assert(map_has(map, "nn"));
    assert(map_has(map, "yes"));
    assert(!map_has(map, "bfg"));
    assert(!map_has(map, "ffffffff"));

    printf("PASS 5\n");

    map_free(map);
}

void test_6(void)
{
    map_t map = map_create();
    map_set(map, "hello", 12);
    map_set(map, "goodbye", 13);
    map_set(map, "dd", 14);
    map_set(map, "nn", 14);
    map_set(map, "yes", 14);

    map_delete(map, "hello");

    char *str = map_get_key(map, 0);

    assert(!strcmp(str, "goodbye"));

    map_free(map);
    free(str);

    printf("PASS 6\n");
}

void test_7(void)
{
    map_t map = map_create();
    map_set(map, "hello", 12);
    map_set(map, "goodbye", 13);
    map_set(map, "dd", 14);
    map_set(map, "nn", 14);
    map_set(map, "yes", 14);

    char *str = map_to_string(map);
    char moddel[] = "hello->12 goodbye->13 dd->14 nn->14 yes->14 ";

    assert(!strcmp(str, moddel));


    map_free(map);

    printf("PASS 7\n");
}

void test_8(void)
{
    char *str = "Maitre corbeau sur un arbre perche,tenait en son bec un fromage.";

    map_t map = get_map_from_str(str);
    map_print(map);

    char moddel[] = "Maitre->1 corbeau->1 sur->1 un->2 arbre->1 perche->1 tenait->1 en->1 son->1 bec->1 fromage->1 ";
    char *map_str = map_to_string(map);

    assert(!strcmp(map_str,moddel));

    map_free(map);

    free(map_str);

    printf("PASS 8\n");
}

void test_9(void)
{
    char *str = "avec nous nous j'ai envie de fair cacajjjjjjjjjjj dans les toillettes .";

    map_t map = get_map_from_str(str);

    map_print(map);

    map_t m_u_w = get_map_of_most_used_words(map);

    map_print(m_u_w);


}

void start_tests(void)
{
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();
    test_8();
    test_9();
}
