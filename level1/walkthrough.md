Simple buffer overflow, follow this tuto:
https://0xrick.github.io/binary-exploitation/bof5/

By inputing a string longer that the buffer, we can over the stack.
If we overide eip (instruction pointer), we can point at our input string, and if it contains instructions,
they will get executed.
The instruction here are execve("/bin/sh/")

```
python -c /tmp/shellcode.py | ./level1
```
