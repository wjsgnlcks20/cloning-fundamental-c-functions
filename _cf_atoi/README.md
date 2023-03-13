# atoi

### from : man atoi

NAME

     atoi, atoi_l – convert ASCII string to integer

LIBRARY

     Standard C Library (libc, -lc)

SYNOPSIS

     #include <stdlib.h>

     int
     atoi(const char *str);

     #include <xlocale.h>

     int
     atoi_l(const char *str, locale_t loc);
     atoi_l(const char *str, locale_t loc);

DESCRIPTION

     The atoi() function converts the initial portion of the string pointed to by str to
     int representation.

     It is equivalent to:

           (int)strtol(str, (char **)NULL, 10);

     While the atoi() function uses the current locale, the atoi_l() function may be
     passed a locale directly. See xlocale(3) for more information.

IMPLEMENTATION NOTES

     The atoi() and atoi_l() functions are thread-safe and async-cancel-safe.

     The strtol() and strtol_l() functions are recommended instead of atoi() and atoi_l()
     functions, especially in new code.

ERRORS

     The function atoi() need not affect the value of errno on an error.

------

# isspace

### from : man isspace

NAME

     isspace – white-space character test

LIBRARY

     Standard C Library (libc, -lc)

SYNOPSIS

     #include <ctype.h>

     int
     isspace(int c);

DESCRIPTION

     The isspace() function tests for the white-space characters.  For any locale, this
     includes the following standard characters:

     ``\t''``\n''``\v''``\f''``\r''`` ''

     In the "C" locale, isspace() successful test is limited to these characters only.
     The value of the argument must be representable as an unsigned char or the value of
     EOF.

RETURN VALUES

     The isspace() function returns zero if the character tests false and returns non-zero
     if the character tests true.
