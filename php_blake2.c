#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "ext/hash/php_hash.h"
#include "blake2.h"
#include "php_blake2.h"

#define PHP_BLAKE2_NAME "BLAKE2"
#define PHP_BLAKE2_VERSION "0.1.0"

zend_function_entry blake2_functions[] = {
    PHP_FE(blake2, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry blake2_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_BLAKE2_NAME,
    blake2_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_BLAKE2_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_BLAKE2
ZEND_GET_MODULE(blake2)
#endif

PHP_FUNCTION(blake2)
{
#if ZEND_MODULE_API_NO >= 20151012
    zend_long hashByteLength = BLAKE2B_OUTBYTES;
    size_t dataByteLength;
    size_t keyLength = 0;
#else
    long hashByteLength = BLAKE2B_OUTBYTES;
    int dataByteLength;
    int keyLength = 0;
#endif
    unsigned char *data;
    unsigned char *key;
    zend_bool rawOutput = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|lsb", &data, &dataByteLength, &hashByteLength, &key, &keyLength, &rawOutput) == FAILURE) {
        return;
    }

    zend_bool hasError = 0;

    if (hashByteLength < 1) {
        hasError = 1;
        zend_error(E_WARNING, "BLAKE2 output length is too short");
    } else if (hashByteLength > BLAKE2B_OUTBYTES) {
        hasError = 1;
        zend_error(E_WARNING, "BLAKE2 output length is too long");
    }

    if (keyLength > BLAKE2B_KEYBYTES) {
        hasError = 1;
        zend_error(E_WARNING, "BLAKE2 key length is too long");
    }

    if (hasError) {
        RETURN_FALSE;
    }

    char hashOutput[hashByteLength];

    int result = blake2b(hashOutput, data, key, hashByteLength, dataByteLength, keyLength);

    if (result != 0) {
        zend_error(E_WARNING, "Error generating BLAKE2 hash");
        RETURN_FALSE;
    }

    if (rawOutput) {
#if ZEND_MODULE_API_NO >= 20151012
        RETURN_STRINGL(hashOutput, hashByteLength);
#else
        RETURN_STRINGL(hashOutput, hashByteLength, 1);
#endif
    } else {
        char hex[hashByteLength * 2 + 1];
        php_hash_bin2hex(hex, (unsigned char *) hashOutput, hashByteLength);
        hex[hashByteLength * 2] = '\0';

#if ZEND_MODULE_API_NO >= 20151012
        RETURN_STRING(hex);
#else
        RETURN_STRING(hex, 1);
#endif
    }
}
