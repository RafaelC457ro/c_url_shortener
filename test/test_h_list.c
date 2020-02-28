#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "hash_list.h"

static void should_init_a_hash_list(void **state) {
    HashList *h = hash_list_init();
    assert_non_null(h);
    assert_int_equal(h->size, HASH_LIST_INIT_SIZE);
    assert_int_equal(h->length, -1);
    hash_list_free(h);
}

static void should_init_append_a_string_wiht_a_key(void **state) {
    HashList *h = hash_list_init();
    char *key = "key";
    char *st = "String 1";

    hash_list_append(h, key, st);

    hash_list_free(h);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(should_init_a_hash_list),
        cmocka_unit_test(should_init_append_a_string_wiht_a_key)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}