#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdint.h>

#include "base_62.h"

static void should_encode_to_base_62(void **state){
    char k[11];
    uint64_t n = 0x16B5C9428C1B05;

    base_62_encode(n, k);

    assert_string_equal(k,"thatscool");
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(should_encode_to_base_62)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}