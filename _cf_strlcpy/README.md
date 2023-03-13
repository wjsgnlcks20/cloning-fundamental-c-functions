# strlcpy

### from : man strlcat

name

     strlcpy, strlcat – size-bounded string copying and concatenation

library

     standard c library (libc, -lc)

synopsis

     #include <string.h>

     size_t
     strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);

     size_t
     strlcat(char * restrict dst, const char * restrict src, size_t dstsize);

description

     the strlcpy() and strlcat() functions copy and concatenate strings with the same
     input parameters and output result as snprintf(3).  they are designed to be safer,
     more consistent, and less error prone replacements for the easily misused functions
     strncpy(3) and strncat(3).

     strlcpy() and strlcat() take the full size of the destination buffer and guarantee
     nul-termination if there is room.  note that room for the nul should be included in
     dstsize.  also note that strlcpy() and strlcat() only operate on true ''c'' strings.
     this means that for strlcpy() src must be nul-terminated and for strlcat() both src
     and dst() must be nul-terminated.

     strlcpy() copies up to dstsize - 1 characters from the string src to dst, nul-
     terminating the result if dstsize is not 0.

     strlcat() appends string src to the end of dst.  it will append at most dstsize -
     strlen(dst) - 1 characters.  it will then nul-terminate, unless dstsize is 0 or the
     original dst string was longer than dstsize (in practice this should not happen as it
     means that either dstsize is incorrect or that dst is not a proper string).

     if the src and dst strings overlap, the behavior is undefined.

return values

     besides quibbles over the return type (size_t versus int) and signal handler safety
     (snprintf(3) is not entirely safe on some systems), the following two are equivalent:

           n = strlcpy(dst, src, len);
           n = snprintf(dst, len, "%s", src);

     like snprintf(3), the strlcpy() and strlcat() functions return the total length of
     the string they tried to create.  for strlcpy() that means the length of src.  for
     strlcat() that means the initial length of dst plus the length of src.

     if the return value is >= dstsize, the output string has been truncated.  it is the
     caller's responsibility to handle this.

examples

     the following code fragment illustrates the simple case:

           char *s, *p, buf[bufsiz];

           ...

           (void)strlcpy(buf, s, sizeof(buf));
           (void)strlcat(buf, p, sizeof(buf));

     to detect truncation, perhaps while building a pathname, something like the following
     might be used:

           char *dir, *file, pname[maxpathlen];

           ...

           if (strlcpy(pname, dir, sizeof(pname)) >= sizeof(pname))
                   goto toolong;
           if (strlcat(pname, file, sizeof(pname)) >= sizeof(pname))
                   goto toolong;

     since it is known how many characters were copied the first time, things can be sped
     up a bit by using a copy instead of an append:

           char *dir, *file, pname[maxpathlen];
           size_t n;

           ...

           n = strlcpy(pname, dir, sizeof(pname));
           if (n >= sizeof(pname))
                   goto toolong;
           if (strlcpy(pname + n, file, sizeof(pname) - n) >= sizeof(pname) - n)
                   goto toolong;

     however, one may question the validity of such optimizations, as they defeat the
     whole purpose of strlcpy() and strlcat().  as a matter of fact, the first version of
     this manual page got it wrong.
