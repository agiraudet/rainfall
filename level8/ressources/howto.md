This is about understanding the program.
I check the C code reconstruction with ghidra (check extract.c)
Works like that:
The prog takes a command (checked with strcmp), and act based on that:
`auth ` -> write the data following the command to $auth after a malloc
`reset` -> free $auth
`service` -> write data following the command in $service
`login` -> prompt "password" if auth[32] == 0, else open a shell
the printf show us the adress allocated for $auth and $service after we used them.
We notice they are next to each other, with 16 bytes in between
Typing auth, we see address 0x804a008, so the code will check if the 32th byte after that is null.
But the code for the auth strcmp show us that it will write a most 30 bytes:
```
      if (len_str < 0x1f) { // 0x1f = 31
        strcpy((char *)auth,small_buff);
      }
```
But since service gets allocated right after some padding and $auth, but before auth[32] (aka 0x804A028), we can write a string long enough to go to that address
0x804A028 - 0x804a018 = 0x10 (16)

So:
```
level8@RainFall:~$ ./level8 
(nil), (nil) 
auth 
0x804a008, (nil) 
service0123456701234567
0x804a008, 0x804a018 
login
$ whoami
level9
```
