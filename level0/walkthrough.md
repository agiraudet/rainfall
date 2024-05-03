Running level0 give a segfault. bt in gdb tells us it come from atoi. 
So we try with a number, and the program runs. But we need to get the right number.
In gdb, we find the call to atoi, and look for the next comparaison :
```
   0x08048ed4 <+20>:	call   0x8049710 <atoi>
=> 0x08048ed9 <+25>:	cmp    $0x1a7,%eax
```
Putting a breakpoint, we set eax to 0x1a7:
```
b *0x08048ed9
c
set $eax = 0x1a7
```

We see that is open a shell. No we just need to do it outside of gdb, to have the good uid.
0x1a7 = 423 in dec, so :
```
./level0 423
cat /home/user/level1/.pass
```
