undefined4 main(int argc, int argv)

{
  undefined4 ret;
  int i;
  undefined4 *c_ptr;
  byte zero;
  undefined4 buf[16];
  undefined alsozero;
  char file_buf[66];
  FILE *file_fd;

  zero = 0;
  file_fd = fopen("/home/user/end/.pass", "r");
  c_ptr = buf;
  for (i = 33; i != 0; i = i + -1) {
    *c_ptr = 0;
    c_ptr = c_ptr + (uint)zero * -2 + 1;
  }
  if ((file_fd == (FILE *)0x0) || (argc != 2)) {
    ret = 0xffffffff;
  } else {
    fread(buf, 1, 66, file_fd);
    alsozero = 0;
    i = atoi(*(char **)(argv + 4));
    *(undefined *)((int)buf + i) = 0;
    fread(file_buf, 1, 65, file_fd);
    fclose(file_fd);
    i = strcmp((char *)buf, *(char **)(argv + 4));
    if (i == 0) {
      execl("/bin/sh", "sh", 0);
    } else {
      puts(file_buf);
    }
    ret = 0;
  }
  return ret;
}
