The asm is small and clear here :
The prog takes two arguments.
The first when is atoied and if its > 9, the prog exit.
The the second is memcpyied. (size is arg1 * 4)
Then the first argument is checked again. If it's not equal to 0x574f4c46, the prog exit.
Otherwise it make a call to exec.

Since memcpy take a unsigned it as arg, we can put a bigger number that is still < 10 buy giving atoi a negative value.
Since it will get multiplied by 4, it still needs to be > 1073741823.75
The orginal buffer is 40 so memcpy with a size 56 is engouh to overide the value return by atoi wich is stored at $esp+0x3c
So :
```
./bonus1 -1073741810 $(python -c 'print 13*"FLOW"')
```
