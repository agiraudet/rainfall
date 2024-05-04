char c[256];

void m(void *param_1,int param_2,char *param_3,int param_4,int param_5)
{
  time_t tVar1;

  tVar1 = time((time_t *)0x0);
  printf("%s - %d\n", c, tVar1);
  return;
}

int main(int argc, char  **argv)
{
  char *input_a;
  void *buf;
  char *input_b;
  FILE *file_stream;
  
  input_a = (char *)malloc(8);
  *input_a = 1;
  buf = malloc(8);
  input_a[1] = buf;
  input_b = (char *)malloc(8);
  *input_b = 2;
  buf = malloc(8);
  input_b[1] = buf;
  strcpy((char *)input_a[1], argv[1]);
  strcpy((char *)input_b[1], argv[2]);
  file_stream = fopen("/home/user/level8/.pass","r");
  fgets(c, 68, file_stream);
  puts("~~");
  return 0;
}
