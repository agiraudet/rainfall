void main(int argc,int argv)
{
  N *this;
  void *this_00;
  
  if (argc < 2) {
    exit(1);
  }
  this = (N *)operator.new(108);
  N::N(this,5);
  this_00 = (void *)operator.new(108);
  N::N((N *)this_00,6);
  N::setAnnotation(this,argv[1]);
  (*this_00)(this_00,this);
  return;
}
