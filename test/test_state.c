#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "state.h"

static void should_init_a_state(void **state)
{
    State *s;

    s = state_new();
    assert_non_null(s);
    assert_int_equal(state_get(s), 0);
    state_free(s);
}

static void should_set_state(void **state)
{
    State *s;
    int e;

    s = state_new();
    assert_non_null(s);

    e = state_set(s, 5);
    assert_int_equal(e, 0);
    assert_int_equal(state_get(s), 5);

    e = state_set(s, 42);
    assert_int_equal(e, -1);
    assert_int_equal(state_get(s), 5);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(should_init_a_state),
        cmocka_unit_test(should_set_state)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}