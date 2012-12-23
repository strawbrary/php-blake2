--TEST--
Verify BLAKE2 error output
--SKIPIF--
<?php if (!extension_loaded("blake2")) print "skip"; ?>
--FILE--
<?php
blake2('Hello world', 0);
blake2('Hello world', 65);
blake2('Hello world', 64, 'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa');
blake2('Hello world', 65, 'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa');
?>
--EXPECTF--
Warning: BLAKE2 output length is too short in %s on line %d

Warning: BLAKE2 output length is too long in %s on line %d

Warning: BLAKE2 key length is too long in %s on line %d

Warning: BLAKE2 output length is too long in %s on line %d

Warning: BLAKE2 key length is too long in %s on line %d
