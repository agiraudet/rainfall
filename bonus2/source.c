int main(int argc, char **argv)
{
  int ret;
  int i;
  char *c_ptr;
  char *str;
  char buf_a [10];
  char buf_b [36];
  char *lang;
  
  if (argc == 3) {
    c_ptr = buf;
    for (i = 19; i != 0; i--) {
      *c_ptr = 0;
      c_ptr++;
    }
    strncpy(buf_a, argv[1], 40);
    strncpy(buf_b, argv[2], 32);
    lang = getenv("LANG");
    if (lang != 0) {
      i = memcmp(lang, &DAT_0804873d, 2);
      if (i == 0) {
        language = 1;
      }
      else {
        i = memcmp(lang, &DAT_08048740, 2);
        if (i == 0) {
          language = 2;
        }
      }
    }
    c_ptr = buf;
    str = (char *)&stack0xffffff50;
    for (i = 19; i != 0; i--) {
      *str = *c_ptr;
      c_ptr++;
      str++;
    }
    ret = greetuser();
  }
  else {
    ret = 1;
  }
  return ret;
}
