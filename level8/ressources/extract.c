
undefined4 main(void)

{
  char *ret_fgets;
  int i;
  uint len_str;
  bool input_inf_auth;
  undefined int_zero_2;
  undefined c_cmp2;
  undefined c_cmp;
  bool ret_fgets_flag;
  byte int_zero;
  byte input_buffer [5];
  char small_buff [2];
  char acStack_89 [125];
  char c;
  byte *input_buffer2;
  byte *str_cmp_to;
  
  int_zero = 0;
  do {
    printf("%p, %p \n",auth,service);
    ret_fgets = fgets((char *)input_buffer,0x80,stdin);
    input_inf_auth = false;
    ret_fgets_flag = ret_fgets == (char *)0x0;
    if (ret_fgets_flag) {
      return 0;
    }
    i = 5;
    input_buffer2 = input_buffer;
    str_cmp_to = (byte *)"auth ";
    do { //STRCMP
      if (i == 0) break;
      i = i + -1;
      input_inf_auth = *input_buffer2 < *str_cmp_to;
      ret_fgets_flag = *input_buffer2 == *str_cmp_to;
      input_buffer2 = input_buffer2 + (uint)int_zero * -2 + 1;
      str_cmp_to = str_cmp_to + (uint)int_zero * -2 + 1;
    } while (ret_fgets_flag);
    int_zero_2 = 0;
    c_cmp = (!input_inf_auth && !ret_fgets_flag) == input_inf_auth;
    if ((bool)c_cmp) {
      auth = (undefined4 *)malloc(4);
      *auth = 0;
      len_str = 0xffffffff;
      ret_fgets = small_buff;
      do { //STRLEN
        if (len_str == 0) break;
        len_str = len_str - 1;
        c = *ret_fgets;
        ret_fgets = ret_fgets + (uint)int_zero * -2 + 1;
      } while (c != '\0');
      len_str = ~len_str - 1;
      int_zero_2 = len_str < 0x1e;
      c_cmp = len_str == 0x1e;
      if (len_str < 0x1f) {
        strcpy((char *)auth,small_buff);
      }
	  //So we check with strcmp for "auth ", and then strcmp the rest to $auth
    }
    i = 5;
    input_buffer2 = input_buffer;
    str_cmp_to = (byte *)"reset";
    do { //STRCMP
      if (i == 0) break;
      i = i + -1;
      int_zero_2 = *input_buffer2 < *str_cmp_to;
      c_cmp = *input_buffer2 == *str_cmp_to;
      input_buffer2 = input_buffer2 + (uint)int_zero * -2 + 1;
      str_cmp_to = str_cmp_to + (uint)int_zero * -2 + 1;
    } while ((bool)c_cmp);
    c_cmp2 = 0;
    int_zero_2 = (!(bool)int_zero_2 && !(bool)c_cmp) == (bool)int_zero_2;
    if ((bool)int_zero_2) {
      free(auth);
    }
	// when reset inputed, we free auth
    i = 6;
    input_buffer2 = input_buffer;
    str_cmp_to = (byte *)"service";
    do { //STRCMP
      if (i == 0) break;
      i = i + -1;
      c_cmp2 = *input_buffer2 < *str_cmp_to;
      int_zero_2 = *input_buffer2 == *str_cmp_to;
      input_buffer2 = input_buffer2 + (uint)int_zero * -2 + 1;
      str_cmp_to = str_cmp_to + (uint)int_zero * -2 + 1;
    } while ((bool)int_zero_2);
    c_cmp = 0;
    int_zero_2 = (!(bool)c_cmp2 && !(bool)int_zero_2) == (bool)c_cmp2;
    if ((bool)int_zero_2) {
      c_cmp = (byte *)0xfffffff8 < input_buffer;
      int_zero_2 = acStack_89 == (char *)0x0;
      service = strdup(acStack_89); //cpy in service data after it
    }
    i = 5;
    input_buffer2 = input_buffer;
    str_cmp_to = (byte *)"login";
    do {
      if (i == 0) break;
      i = i + -1;
      c_cmp = *input_buffer2 < *str_cmp_to;
      int_zero_2 = *input_buffer2 == *str_cmp_to;
      input_buffer2 = input_buffer2 + (uint)int_zero * -2 + 1;
      str_cmp_to = str_cmp_to + (uint)int_zero * -2 + 1;
    } while ((bool)int_zero_2);
    if ((!(bool)c_cmp && !(bool)int_zero_2) == (bool)c_cmp) {
      if (auth[8] == 0) {
        fwrite("Password:\n",1,10,stdout);
      }
      else {
        system("/bin/sh");
      }
    }
  } while( true );
}
