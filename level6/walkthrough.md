level6 segfault if no argument given. If there is an argument, it seems to check it.
ltrace tells us there is 2 malloc calls, for 4 and 64 bytes, that we can see from main().
Function n(), with a call to system(), is never called.
Function m(), with a call to puts(), is the same.
We spot a call to strcpy() in main(), thats not secure...
Some ptr operation are performed on the ret value of strcpy, then this ptr is called as a fct.
It is 08048468, aka m() by default, we need to change it to 08048454, aka o()
Since the ptr is store in the 4bytes malloc'ed space, out of bound on our buffer overwrite it.
```
./level6 $(python -c 'print "a" * 72 + "\x54\x84\x04\x08"')
```
