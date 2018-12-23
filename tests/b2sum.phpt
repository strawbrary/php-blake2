--TEST--
Verify the b2sum is an alias to blake2_file and have the same output
--SKIPIF--
<?php if (!extension_loaded("blake2")) print "skip"; ?>
--FILE--
<?php
echo b2sum('tests/sample.txt').PHP_EOL;
?>
--EXPECT--
a61b779ff667fbcc4775cbb02cd0763b9b5312fe6359a44a003f582ce6897c81a38a876122ce91dfec547d582fe269f6ea9bd291b60bccf95006dac10a4316f2
