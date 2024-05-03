int main(undefined4 argc,int argv)
{
  int n;
  char *str;
  __uid_t id;
  __gid_t gid;
  
  n = atoi(argv[1]);
  if (n == 423) {
    str = strdup("/bin/sh");
    gid = getegid();
    id = geteuid();
    setresgid(gid,gid,gid);
    setresuid(id,id,id);
    execv("/bin/sh",&str);
  }
  else {
    fwrite("No !\n",1,5,(FILE *)stderr);
  }
  return 0;
}
