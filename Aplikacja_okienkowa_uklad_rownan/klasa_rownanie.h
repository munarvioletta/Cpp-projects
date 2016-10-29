class Rownanie
  {
   float a,b,c,d,e,f; //

   void liczenie_wyznacznikow()  //
    {
      W=a*d-c*b;
      Wx=d*e-f*b;
      Wy=a*f-e*c;

    }
  public:
  
  float W,Wx,Wy;
  AnsiString y,x;

   void wczytywanie_danych(float a1, float b1,float c1,float d1,float e1,float f1)
     {
      a=a1;
      b=b1;
      c=c1;
      d=d1;
      e=e1;
      f=f1;
     }

   void wyswietl_wynik()
     {
        liczenie_wyznacznikow();

      if(W!=0)
        {
         x=FloatToStr(Wx/W);
         y=FloatToStr(Wy/W);

         }

     else if(W==0 &&(Wx!=0 || Wy!=0))
         {
       x="Uklad rownan jest sprzeczny!";
       y="Uklad rownan jest sprzeczny!";

         }
       else if(W==0&&(Wx==0 && Wy==0))
        {
      x="Uklad ma nieskonczenie wiele rozwiazan";
      y="Uklad ma nieskonczenie wiele rozwiazan";
        }

     }

  };
