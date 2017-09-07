--TEST--
Verify the blake2b is an alias to blake2 and have the same output
--SKIPIF--
<?php if (!extension_loaded("blake2")) print "skip"; ?>
--FILE--
<?php
$string = blake2('Hello World');

if (!strcmp($string, blake2b('Hello World'))) {
	echo $string . PHP_EOL;
}

?>
--EXPECT--
4386a08a265111c9896f56456e2cb61a64239115c4784cf438e36cc851221972da3fb0115f73cd02486254001f878ab1fd126aac69844ef1c1ca152379d0a9bd
