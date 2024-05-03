We cannot use the same overflow as before, because of the address that start with a 0xb check.
So no stack
There is a malloc on the heap for the strdup()
ltrace show return address of 0x804a008
so we build the payload for that.
So our shellcode + padding will occupy the full allowed buffer of 80, and we add to it the return address
```
python /tmp/shellcode.py > /tmp/payload
cat /tmp/payload - | ./level2
cat /home/user/level3/.pass
```
