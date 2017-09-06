PHP_ARG_ENABLE(blake2,
[Whether to enable BLAKE2 support],
[--enable-blake2           Enable BLAKE2 Extension])

if test "$PHP_BLAKE2" != "no"; then
    PHP_NEW_EXTENSION(blake2, php_blake2.c blake2b-ref.c blake2s-ref.c, $ext_shared)
fi