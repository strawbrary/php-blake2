#ifndef PHP_BLAKE2_H
#define PHP_BLAKE2_H

PHP_FUNCTION(blake2);
PHP_FUNCTION(blake2s);
PHP_FUNCTION(blake2_file);

extern zend_module_entry blake2_module_entry;
#define phpext_blake2_ptr &blake2_module_entry

#endif
