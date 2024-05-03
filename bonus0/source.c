void p(char *srt1,char *str2)
{
  char *nl;
  char buff [4104];
  
  puts(str2);
  read(0,buff,4096);
  nl = strchr(buff,10);
  *nl = '\0';
  strncpy(srt1,buff,20);
  return;
}

void pp(char *str)
{
  uint i;
  char *str_ptr;
  char buf_inp_a[20];
  char buf_inp_b[20];
  char c;
  
  p(buf_inp_a, " - \n");
  p(buf_inp_b, " - \n");
  strcpy(str, buf_inp_a);
  i = 0xffffffff;
  str_ptr = str;
  do {
    if (i == 0) break;
	i--;
    c = *str_ptr;
	str_ptr++;
  } while (c != '\0');
  str[~i - 1] = ' ';
  strcat(str, buf_inp_b);
  return;
}

int main(void)
{
  char buf [54];
  
  pp(buf);
  puts(buf);
  return 0;
}
