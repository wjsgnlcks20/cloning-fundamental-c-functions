# strcat

### from : man strcat

NAME

     strcat, strncat – concatenate strings

LIBRARY

     Standard C Library (libc, -lc)

SYNOPSIS

     #include <string.h>

     char *
     strcat(char *restrict s1, const char *restrict s2);

     char *
     strncat(char *restrict s1, const char *restrict s2, size_t n);

ADMONISHMENT

             YOU SHOULD ALMOST CERTAINLY USE strlcat() INSTEAD.

                     See "Security Considerations" below.

DESCRIPTION

     The strcat() and strncat() functions append a copy of the null-terminated string s2
     to the end of the null-terminated string s1, then add a terminating ‘\0’.  The string
     s1 must have sufficient space to hold the result.

     The strncat() function appends not more than n characters from s2, and then adds a
     terminating ‘\0’.

     The source and destination strings should not overlap, as the behavior is undefined.

RETURN VALUES

     The strcat() and strncat() functions return the pointer s1.

SECURITY CONSIDERATIONS

     The strcat() function is easily misused in a manner which enables malicious users to
     arbitrarily change a running program's functionality through a buffer overflow
     attack.  (See the FSA.)

     Avoid using strcat().  Instead, use strncat() or strlcat() and ensure that no more
     characters are copied to the destination buffer than it can hold.

     Note that strncat() can also be problematic.  It may be a security concern for a
     string to be truncated at all.  Since the truncated string will not be as long as the
     original, it may refer to a completely different resource and usage of the truncated
     resource could result in very incorrect behavior.  Example:

     void
     foo(const char *arbitrary_string)
     {
             char onstack[8] = "";

     #if defined(BAD)
             /*
              * This first strcat is bad behavior.  Do not use strcat!
              */
             (void)strcat(onstack, arbitrary_string);        /* BAD! */
     #elif defined(BETTER)
             /*
              * The following two lines demonstrate better use of
              * strncat().
              */
             (void)strncat(onstack, arbitrary_string,
                 sizeof(onstack) - strlen(onstack) - 1);
     #elif defined(BEST)
             /*
              * These lines are even more robust due to testing for
              * truncation.
              */
             if (strlen(arbitrary_string) + 1 >
                 sizeof(onstack) - strlen(onstack))
                     err(1, "onstack would be truncated");
             (void)strncat(onstack, arbitrary_string,
                 sizeof(onstack) - strlen(onstack) - 1);
     #endif
     }
