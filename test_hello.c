/*
 * Minimal test framework: no dependencies, just assert-like checks.
 * Run via `make test`.
 */
#include <stdio.h>
#include <string.h>

#include "hello.h"

static int checks_run = 0;
static int checks_failed = 0;

#define CHECK(cond, msg)                                              \
    do {                                                              \
        checks_run++;                                                 \
        if (!(cond)) {                                                \
            checks_failed++;                                          \
            (void)fprintf(stderr, "FAIL: %s (line %d)\n", msg, __LINE__); \
        }                                                             \
    } while (0)

#define CHECK_STR_EQ(actual, expected)                                \
    do {                                                              \
        const char *a_ = (actual);                                    \
        const char *e_ = (expected);                                  \
        checks_run++;                                                 \
        if (a_ == NULL || strcmp(a_, e_) != 0) {                      \
            checks_failed++;                                          \
            (void)fprintf(stderr, "FAIL: got \"%s\", want \"%s\" (line %d)\n", \
                          a_ ? a_ : "(null)", e_, __LINE__);          \
        }                                                             \
    } while (0)

static void test_default_greeting(void)
{
    CHECK_STR_EQ(hello_greet(NULL), "Hello world!");
    CHECK_STR_EQ(hello_greet(""), "Hello world!");
}

static void test_named_greeting(void)
{
    CHECK_STR_EQ(hello_greet("Fernando"), "Hello Fernando!");
    CHECK_STR_EQ(hello_greet("C"), "Hello C!");
}

static void test_no_buffer_overflow(void)
{
    /* A long name must be truncated safely, never overflow the 128-byte buffer. */
    char big[300];
    memset(big, 'x', sizeof(big) - 1);
    big[sizeof(big) - 1] = '\0';
    const char *greeting = hello_greet(big);
    CHECK(greeting != NULL, "greeting is NULL");
    CHECK(strlen(greeting) < 128, "greeting exceeds buffer size");
    CHECK(strncmp(greeting, "Hello ", 6) == 0, "greeting lost its prefix");
}

int main(void)
{
    test_default_greeting();
    test_named_greeting();
    test_no_buffer_overflow();

    (void)printf("%d checks, %d failed\n", checks_run, checks_failed);
    return checks_failed == 0 ? 0 : 1;
}
