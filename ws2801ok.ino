//create arrays
int RED[63];
int GREEN[63];
int BLUE[63];
//
//pin map
int clockpin = 2;
int datapin = 3;
//
//setup code
void setup()
{
  pinMode(clockpin, OUTPUT);
  pinMode(datapin, OUTPUT);
  for (int i=0;i<63;i++)
  {
    BLUE[i]=0;
    RED[i]=0;
    GREEN[i]=0;
  }
}
//
void updatestring()
{
  for(int i=0;i<63;i++)
  {
    shiftOut(datapin, clockpin, MSBFIRST, BLUE[i]);
    shiftOut(datapin, clockpin, MSBFIRST, RED[i]);
    shiftOut(datapin, clockpin, MSBFIRST, GREEN[i]);
  }
}
//
void loop()
{
    for(int i=0;i<30;i++)
    {    
      BLUE[i]=255;
      RED[i]=190;
      GREEN[i]=55;
      updatestring();
      //BLUE[i]=0;
      //RED[i]=0;
      //GREEN[i]=0;
      delay(1);
    }

    for(int i=29;i>=0;i--)
    {
      BLUE[i]=0;
      RED[i]=0;
      GREEN[i]=0;
      updatestring();
      BLUE[i]=0;
      RED[i]=0;
      GREEN[i]=0;
      delay(1);
    }

    for(int i=62;i>=30;i--)
    {
      BLUE[i]=155;
      RED[i]=55;
      GREEN[i]=255;
      updatestring();
      //BLUE[i]=0;
      //RED[i]=0;
      //GREEN[i]=0;
      delay(1);
    }

    for(int i=30;i<63;i++)
    {
      BLUE[i]=0;
      RED[i]=0;
      GREEN[i]=0;
      updatestring();
      //BLUE[i]=0;
      //RED[i]=0;
      //GREEN[i]=0;
      delay(1);
    }
}
