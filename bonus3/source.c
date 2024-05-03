int main(int argc, char **argv)
{
  int ret;
  int i;
  char *c_ptr;
  char buf[16];
  char file_buf[66];
  FILE *file_fd;

  file_fd = fopen("/home/user/end/.pass", "r");
  c_ptr = buf;
  for (i = 33; i != 0; i--) {
    *c_ptr = 0;
    c_ptr++
  }
  if ((file_fd == (FILE *)0x0) || (argc != 2)) {
    ret = 0xffffffff;
  } else {
    fread(buf, 1, 66, file_fd);
    i = atoi(argv[1]);
    buf[i] = 0;
    fread(file_buf, 1, 65, file_fd);
    fclose(file_fd);
    i = strcmp(buf, argv[1]);
    if (i == 0) {
      execl("/bin/sh", "sh", 0);
    } else {
      puts(file_buf);
    }
    ret = 0;
  }
  return ret;
}
