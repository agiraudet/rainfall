void n(void)
{
  system("/bin/cat /home/user/level7/.pass");
  return;
}

void m(void *param_1,int param_2,char *param_3,int param_4,int param_5)
{
  puts("Nope");
  return;
}

void main(int argc, char **argv)
{
  char *dst;
  void *fct_ptr;
  
  dst = (char *)malloc(64);
  fct_ptr = (void *)malloc(4);
  *fct_ptr = m;
  strcpy(dst, argv[1]);
  (*fct_ptr)();
  return;
}
