uint m = 0x804988c

void v(void)

{
  char buf [520];
  
  fgets(buf,512,stdin);
  printf(buf);
  if (m == 0x40) {
    fwrite("Wait what?!\n",1,12,stdout);
    system("/bin/sh");
  }
  return;
}

void main(void)
{
  v();
  return;
}
