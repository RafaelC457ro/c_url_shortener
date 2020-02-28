#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "hash_list.h"

static void should_init_a_hash_list(void **state) {
    HashList *h = hash_list_init();
    assert_non_null(h);
    assert_int_equal(h->size, HASH_LIST_INIT_SIZE);
    assert_int_equal(h->length, 0);
    hash_list_free(h);
}

static void should_append_a_string_with_a_key(void **state) {
    HashList *h = hash_list_init();
    char *key = "key";
    char *st = "String 1";

    hash_list_append(h, key, st);

    assert_int_equal(h->length, 1);
    assert_string_equal(h->keys[0], key);
    assert_string_equal(h->data[0], st);

    hash_list_free(h);
}

static void should_get_strings_with_a_key(void **state) {
    HashList *h = hash_list_init();
    char *key_one = "key_1";
    char *key_two = "key_2";
    char *st_one = "String 1";
    char *st_two = "String 2";

    char *stc_one;
    char *stc_two;

    hash_list_append(h, key_one, st_one);
    hash_list_append(h, key_two, st_two);

    hash_list_get(h, key_one, &stc_one);
    hash_list_get(h, key_two, &stc_two);

    // assert_string_equal(st_one, stc_one);
    // assert_string_equal(st_two, stc_two);

    hash_list_free(h);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(should_init_a_hash_list),
        cmocka_unit_test(should_append_a_string_with_a_key),
        cmocka_unit_test(should_get_strings_with_a_key)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}