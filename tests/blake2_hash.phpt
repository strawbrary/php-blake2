--TEST--
Verify BLAKE2 output
--SKIPIF--
<?php if (!extension_loaded("blake2")) print "skip"; ?>
--FILE--
<?php
echo blake2('').PHP_EOL;
echo blake2('Hello world').PHP_EOL;
echo blake2('Hello world', 20, 'foobar').PHP_EOL;
?>
--EXPECT--
786a02f742015903c6c6fd852552d272912f4740e15847618a86e217f71f5419d25e1031afee585313896444934eb04b903a685b1448b755d56f701afe9be2ce
6ff843ba685842aa82031d3f53c48b66326df7639a63d128974c5c14f31a0f33343a8c65551134ed1ae0f2b0dd2bb495dc81039e3eeb0aa1bb0388bbeac29183
5b4bbc84b59ab5d9146089b143fd52f38638dcac