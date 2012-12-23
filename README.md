PHP BLAKE2 Extension
============================
BLAKE2 is an improved version of BLAKE, one the finalists in the NIST SHA-3 competition. Like BLAKE or SHA-3, BLAKE2 offers the highest security, yet is fast as MD5 on 64-bit platforms and requires at least 33% less RAM than SHA-2 or SHA-3 on low-end systems. This implementation uses the BLAKE2b variant of the algorithm which is optimized for 64-bit systems. The algorithm was designed by Jean-Philippe Aumasson, Samuel Neves, Zooko Wilcox-O'Hearn, and Christian Winnerlein.

Installation
------------
1. git clone https://github.com/strawbrary/php-blake2
1. cd php-blake2
1. phpize
1. ./configure --enable-blake2
1. make && make install
1. Add the following line to your php.ini file

```
extension=blake2.so
```

You may need to restart your httpd to load the extension

Usage
----
```php
string blake2 ( string $str [, int $outputSize = 64, string $key, bool $rawOutput = false ] )
```

* $str: The string to hash
* $outputSize: The length of the output hash (can be between 1 and 64)
* $key: Turns the output into a keyed hash using the specified key
* $rawOutput: If set to true, then the hash is returned in raw binary format

* Return value: A hex string containing the BLAKE2 hash of the input string

Examples
--------
```php
echo blake2('');
```

786a02f742015903c6c6fd852552d272912f4740e15847618a86e217f71f5419d25e1031afee585313896444934eb04b903a685b1448b755d56f701afe9be2ce

```php
echo blake2('Hello world', 20);
```

5ad31b81fc4dde5554e36af1e884d83ff5b24eb0

```php
echo blake2('Hello world', 20, 'foobar');
```

5b4bbc84b59ab5d9146089b143fd52f38638dcac

More Info
---------
https://blake2.net/