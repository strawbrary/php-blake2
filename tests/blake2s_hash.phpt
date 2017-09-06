--TEST--
Verify BLAKE2s output
--SKIPIF--
<?php if (!extension_loaded("blake2")) print "skip"; ?>
--FILE--
<?php
echo blake2s('').PHP_EOL;
echo blake2s('Hello world').PHP_EOL;
echo blake2s('Hello world', 20, 'foobar').PHP_EOL;
?>
--EXPECT--
69217a3079908094e11121d042354a7c1f55b6482ca1a51e1b250dfd1ed0eef9
619a15b0f4dd21ef4bd626a9146af64561caf1325b21bccf755e4d7fbc31a65f
766745fb94ffb0512e0a544a17860f3f2484c4af