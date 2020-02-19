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
    int index = -1;

    assert_non_null(s);
    
    index = s_list_append(s, st);
    assert_int_equal(index, 0);
    
    s_list_free(s);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(should_init_a_list),
        cmocka_unit_test(should_add_string_to_list)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}