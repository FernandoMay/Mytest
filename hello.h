#ifndef HELLO_H
#define HELLO_H

/* Returns a greeting for the given name.
 * Pass NULL or "" for the default greeting.
 * The returned string is a static buffer valid until the next call. */
const char *hello_greet(const char *name);

#endif /* HELLO_H */
