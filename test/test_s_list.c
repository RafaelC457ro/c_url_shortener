#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "s_list.h"

static void should_init_a_list(void **state)
{
    StringList *s = s_list_init();
    assert_non_null(s);
    assert_int_equal(s->size, S_LIST_INIT_SIZE);
    assert_int_equal(s->len, -1);
    s_list_free(s);
}

static void should_add_string_to_list(void **state)
{
    StringList *s = s_list_init();
    char *st = "String 1";
    int index;

    assert_non_null(s);
    
    index = s_list_append(s, st);
    assert_int_equal(index, 0);
    
    s_list_free(s);
}

static void should_get_string_from_list(void **state)
{
    StringList *s = s_list_init();
    char *st_one = "String 1";
    char *st_two = "String 2";
    char *stc_one;
    char *stc_two;
    int index_one, index_two;

    assert_non_null(s);
    
    index_one = s_list_append(s, st_one);
    index_two = s_list_append(s, st_two);
    s_list_get(s, index_one, &stc_one);
    s_list_get(s, index_two, &stc_two);

    assert_string_equal(st_one, stc_one);
    assert_string_equal(st_two, stc_two);
    
    s_list_free(s);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(should_init_a_list),
        cmocka_unit_test(should_add_string_to_list),
        cmocka_unit_test(should_get_string_from_list)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}