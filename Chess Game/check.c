#include "main.h"


int check_for_check(GameState *gamestate)
{
    for(int i=1;i<=8;i++)
    {
       for(int j=1;j<=8;j++)
       {
           int temp_index=get_index(gamestate,i,j);
           if(temp_index!=-1 && gamestate->pieces[temp_index].live == 1)
           {
               if((temp_index>=0 && temp_index<=7)||(temp_index>=16 && temp_index<=23))   //PAWNS
               {
                   if(gamestate->pieces[temp_index].color==0)
                   {
                       if((get_index(gamestate,i-1,j+1)==31)||(get_index(gamestate,i+1,j+1)==31))
                       {
                           return 1;
                       }
                   }
                   else
                   {
                      if((get_index(gamestate,i-1,j-1)==15)||(get_index(gamestate,i+1,j-1)==15))
                       {
                           return 2;
                       }
                   }
               }
               if((temp_index>=10 && temp_index<=11)||(temp_index>=26 && temp_index<=27)) //KNIGHT
               {
                   if(gamestate->pieces[temp_index].color==0)
                   {
                       if((get_index(gamestate,i-1,j-2)==31)||(get_index(gamestate,i+1,j-2)==31))
                       {
                           return 1;
                       }
                       else if((get_index(gamestate,i-2,j-1)==31)||(get_index(gamestate,i-2,j+1)==31))
                       {
                           return 1;
                       }
                       else if((get_index(gamestate,i-1,j+2)==31)||(get_index(gamestate,i+1,j+2)==31))
                       {
                           return 1;
                       }
                       else if((get_index(gamestate,i+2,j+1)==31)||(get_index(gamestate,i+2,j-1)==31))
                       {
                           return 1;
                       }
                   }
                   else
                   {
                       if((get_index(gamestate,i-1,j-2)==15)||(get_index(gamestate,i+1,j-2)==15))
                       {
                           return 2;
                       }
                       else if((get_index(gamestate,i-2,j-1)==15)||(get_index(gamestate,i-2,j+1)==15))
                       {
                           return 2;
                       }
                       else if((get_index(gamestate,i-1,j+2)==15)||(get_index(gamestate,i+1,j+2)==15))
                       {
                           return 2;
                       }
                       else if((get_index(gamestate,i+2,j+1)==15)||(get_index(gamestate,i+2,j-1)==15))
                       {
                           return 2;
                       }
                    }
               }
               if((temp_index>=8 && temp_index<=9)||(temp_index>=24 && temp_index<=25))   //BISHOP
               {
                   int k,l,flag=0;
                   if(gamestate->pieces[temp_index].color==0)
                   {
                       for(k=i+1,l=j+1;k<=8 && l<=8;k++,l++)
                       {
                           if(get_index(gamestate,k,l)==31 && !flag)
                           {
                               return 1;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                               flag=1;
                           }
                       }
                       flag=0;

                       for(k=i+1,l=j-1;k<=8 && l>=1;k++,l--)
                       {
                           if(get_index(gamestate,k,l)==31 && !flag)
                           {
                               return 1;
                           }
                            if(get_index(gamestate,k,l)!=-1)
                           {
                               flag=1;
                           }
                       }
                       flag=0;

                       for(k=i-1,l=j+1;k>=1 && l<=8;k--,l++)
                       {
                           if(get_index(gamestate,k,l)==31 && !flag)
                           {
                               return 1;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                               flag=1;
                           }
                       }
                       flag=0;

                       for(k=i-1,l=j-1;k>=1 && l>=1;k--,l--)
                       {
                           if(get_index(gamestate,k,l)==31 && !flag)
                           {
                               return 1;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                               flag=1;
                           }

                       }
                       flag=0;
                   }
                   else
                   {
                       for(k=i+1,l=j+1;k<=8 && l<=8;k++,l++)
                       {
                           if(get_index(gamestate,k,l)==15 && !flag)
                           {
                                return 2;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i+1,l=j-1;k<=8 && l>=1;k++,l--)
                       {
                           if(get_index(gamestate,k,l)==15 && !flag)
                           {
                                return 2;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i-1,l=j+1;k>=1 && l<=8;k--,l++)
                       {
                           if(get_index(gamestate,k,l)==15 && !flag)
                           {
                                return 2;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i-1,l=j-1;k>=1 && l>=1;k--,l--)
                       {

                           if(get_index(gamestate,k,l)==15 && !flag)
                           {
                                return 2;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }

                       }
                       flag=0;
                   }
               }
               if((temp_index>=12 && temp_index<=13)||(temp_index>=28 && temp_index<=29)) //ROOK
               {
                   int k,l,flag=0;
                   if(gamestate->pieces[temp_index].color==0)
                   {
                       for(k=i,l=j+1;l<=8;l++)
                       {
                           if(get_index(gamestate,k,l)==31 && !flag)
                           {
                                return 1;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i,l=j-1;l>=1;l--)
                       {

                           if(get_index(gamestate,k,l)==31 && !flag)
                           {
                                return 1;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i-1,l=j;k>=1;k--)
                       {
                           if(get_index(gamestate,k,l)==31 && !flag)
                           {
                                return 1;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i+1,l=j;k<=8;k++)
                       {

                           if(get_index(gamestate,k,l)==31 && !flag)
                           {
                                return 1;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }

                       }
                       flag=0;
                   }
                   else
                   {
                       for(k=i,l=j+1;l<=8;l++)
                       {
                           if(get_index(gamestate,k,l)==15 && !flag)
                           {
                                return 2;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i,l=j-1;l>=1;l--)
                       {
                           if(get_index(gamestate,k,l)==15 && !flag)
                           {
                                return 2;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i-1,l=j;k>=1;k--)
                       {
                           if(get_index(gamestate,k,l)==15 && !flag)
                           {
                                return 2;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i+1,l=j;k<=8;k++)
                       {

                           if(get_index(gamestate,k,l)==15 && !flag)
                           {
                                return 2;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }

                       }
                       flag=0;
                   }
               }
               if((temp_index==14)||(temp_index==30))                                     //QUEEN
               {
                   int k,l,flag=0;
                   if(gamestate->pieces[temp_index].color==0)
                   {
                       for(k=i,l=j+1;l<=8;l++)
                       {
                           if(get_index(gamestate,k,l)==31 && !flag)
                           {
                                return 1;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i,l=j-1;l>=1;l--)
                       {
                           if(get_index(gamestate,k,l)==31 && !flag)
                           {
                                return 1;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i-1,l=j;k>=1;k--)
                       {
                           if(get_index(gamestate,k,l)==31 && !flag)
                           {
                                return 1;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i+1,l=j;k<=8;k++)
                       {

                           if(get_index(gamestate,k,l)==31 && !flag)
                           {
                                return 1;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }

                       }
                       flag=0;
                       for(k=i+1,l=j+1;k<=8 && l<=8;k++,l++)
                       {

                           if(get_index(gamestate,k,l)==31 && !flag)
                           {
                               return 1;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }

                       }
                       flag=0;
                       for(k=i+1,l=j-1;k<=8 && l>=1;k++,l--)
                       {

                           if(get_index(gamestate,k,l)==31 && !flag)
                           {
                                return 1;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }

                       }
                       flag=0;
                       for(k=i-1,l=j+1;k>=1 && l<=8;k--,l++)
                       {
                           if(get_index(gamestate,k,l)==31 && !flag)
                           {
                               return 1;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }

                       }
                       flag=0;
                       for(k=i-1,l=j-1;k>=1 && l>=1;k--,l--)
                       {

                           if(get_index(gamestate,k,l)==31 && !flag)
                           {
                                return 1;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }

                       }
                       flag=0;
                   }
                   else
                   {
                       for(k=i,l=j+1;l<=8;l++)
                       {
                           if(get_index(gamestate,k,l)==15 && !flag)
                           {
                               return 2;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i,l=j-1;l>=1;l--)
                       {
                           if(get_index(gamestate,k,l)==15 && !flag)
                           {
                                return 2;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i-1,l=j;k>=1;k--)
                       {
                           if(get_index(gamestate,k,l)==15 && !flag)
                           {
                                return 2;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i+1,l=j;k<=8;k++)
                       {
                           if(get_index(gamestate,k,l)==15 && !flag)
                           {
                               return 2;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i+1,l=j+1;k<=8 && l<=8;k++,l++)
                       {
                           if(get_index(gamestate,k,l)==15 && !flag)
                           {
                                return 2;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i+1,l=j-1;k<=8 && l>=1;k++,l--)
                       {
                           if(get_index(gamestate,k,l)==15 && !flag)
                           {
                                return 2;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i-1,l=j+1;k>=1 && l<=8;k--,l++)
                       {
                           if(get_index(gamestate,k,l)==15 && !flag)
                           {
                               return 2;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }
                       flag=0;
                       for(k=i-1,l=j-1;k>=1 && l>=1;k--,l--)
                       {
                           if(get_index(gamestate,k,l)==15 && !flag)
                           {
                                return 2;
                           }
                           if(get_index(gamestate,k,l)!=-1)
                           {
                                flag=1;
                           }
                       }flag=0;
                   }
               }
           }
       }
    }
    return 0;
}
