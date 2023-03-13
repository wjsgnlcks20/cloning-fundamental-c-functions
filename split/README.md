# split

DESCRIPTION

    The split() function breaks a string into smaller strings based on the characters contained in the charset string.
    Each resulting string in the array is null-terminated, as is the array itself.
    The elements in the array are allocated using malloc() and should be freed with the free() function, along with the array itself.

EXAMPLE

    split("this is a testZstring", " Z") returns a array of strings like { "this", "is", "a", "test", "string", 0 }

PROTOTYPE

    char	**split(char *str, char *charset)