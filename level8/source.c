int main(void)
{
  char *ret_fgets;
  int i;
  uint len_str;
  bool input_inf_auth;
  bool c_cmp2;
  bool c_cmp;
  bool ret_fgets_flag;
  bool check_flag;
  char input_buffer[5];
  char small_buff [2];
  char acStack_89 [125];
  char c;
  char *input_buffer2;
  char *str_cmp_to;
  
  do {
    printf("%p, %p \n", auth, service);
    ret_fgets = fgets(input_buffer, 0x80, stdin);
    input_inf_auth = false;
    ret_fgets_flag = ret_fgets == 0;
    if (ret_fgets_flag) {
      return 0;
    }
    i = 5;
    input_buffer2 = input_buffer;
    str_cmp_to = (char *)"auth ";
    do { //STRCMP
      if (i == 0) break;
      i--;
      input_inf_auth = *input_buffer2 < *str_cmp_to;
      ret_fgets_flag = *input_buffer2 == *str_cmp_to;
      input_buffer2++;
      str_cmp_to++;
    } while (ret_fgets_flag);
    c_cmp = (!input_inf_auth && !ret_fgets_flag) == input_inf_auth;
    if ((bool)c_cmp) {
      auth = (char *)malloc(4);
      *auth = 0;
      len_str = 0;
      ret_fgets = small_buff;
      do { //STRLEN
        if (len_str == 0) break;
        len_str--;
        c = *ret_fgets;
        ret_fgets++;
      } while (c != '\0');
      len_str++;
      check_flag = len_str < 30;
      c_cmp = len_str == 30;
      if (len_str < 0x31) {
        strcpy(auth, small_buff);
      }
	  //So we check with strcmp for "auth ", and then strcmp the rest to $auth
    }
    i = 5;
    input_buffer2 = input_buffer;
    str_cmp_to = (char *)"reset";
    do { //STRCMP
      if (i == 0) break;
      i--;
      check_flag = *input_buffer2 < *str_cmp_to;
      c_cmp = *input_buffer2 == *str_cmp_to;
      input_buffer2++;
      str_cmp_to++;
    } while ((bool)c_cmp);
    c_cmp2 = 0;
    check_flag = (!(bool)check_flag && !(bool)c_cmp) == (bool)check_flag;
    if ((bool)check_flag) {
      free(auth);
    }
	// when reset inputed, we free auth
    i = 6;
    input_buffer2 = input_buffer;
    str_cmp_to = (char *)"service";
    do { //STRCMP
      if (i == 0) break;
      i--;
      c_cmp2 = *input_buffer2 < *str_cmp_to;
      check_flag = *input_buffer2 == *str_cmp_to;
      input_buffer2++;
      str_cmp_to++;
    } while ((bool)check_flag);
    c_cmp = 0;
    check_flag = (!(bool)c_cmp2 && !(bool)check_flag) == (bool)c_cmp2;
    if ((bool)check_flag) {
      c_cmp = (byte *)0xfffffff8 < input_buffer;
      check_flag = acStack_89 == 0;
      service = strdup(acStack_89); //cpy in service data after it
    }
    i = 5;
    input_buffer2 = input_buffer;
    str_cmp_to = (char *)"login";
    do {
      if (i == 0) break;
      i--;
      c_cmp = *input_buffer2 < *str_cmp_to;
      check_flag = *input_buffer2 == *str_cmp_to;
      input_buffer2++;
      str_cmp_to++;
    } while ((bool)check_flag);
    if ((!(bool)c_cmp && !(bool)check_flag) == (bool)c_cmp) {
      if (auth[8] == 0) {
        fwrite("Password:\n", 1, 10, stdout);
      }
      else {
        system("/bin/sh");
      }
    }
  } while( true );
}
