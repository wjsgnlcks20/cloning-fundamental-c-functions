# putchar

### from : man putchar

NAME

     fputc, putc, putc_unlocked, putchar, putchar_unlocked, putw – output a character or
     word to a stream

LIBRARY

     Standard C Library (libc, -lc)

SYNOPSIS

     #include <stdio.h>

     int
     fputc(int c, FILE *stream);

     int
     putc(int c, FILE *stream);

     int
     putc_unlocked(int c, FILE *stream);

     int
     putchar(int c);

     int
     putchar_unlocked(int c);

     int
     putw(int w, FILE *stream);
     int
     putw(int w, FILE *stream);

DESCRIPTION

     The fputc() function writes the character c (converted to an ``unsigned char'') to
     the output stream pointed to by stream.

     The putc() macro acts essentially identically to fputc(), but is a macro that expands
     in-line.  It may evaluate stream more than once, so arguments given to putc() should
     not be expressions with potential side effects.

     The putchar() function is identical to putc() with an output stream of stdout.

     The putw() function writes the specified int to the named output stream.

     The putc_unlocked() and putchar_unlocked() functions are equivalent to putc() and
     putchar() respectively, except that the caller is responsible for locking the stream
     with flockfile(3) before calling them.  These functions may be used to avoid the
     overhead of locking the stream for each character, and to avoid output being
     interspersed from multiple threads writing to the same stream.

RETURN VALUES

     The functions, fputc(), putc(), putchar(), putc_unlocked(), and putchar_unlocked()
     return the character written.  If an error occurs, the value EOF is returned.  The
     putw() function returns 0 on success; EOF is returned if a write error occurs, or if
     an attempt is made to write a read-only stream.