#include<stdio.h>

#include<iostream>

#include<stdlib.h>

using namespace std;

int board[9];

int decision, turn=1;

int i,player,choice;

void user_turn();

void comp_turn();

void display_board();

int main(){

                             for (i=0;i<9;i++)

                             {

                                           board[i]=2;

                             }            

                             display_board();

              cout<<"Who wants to play first?\n";

              cout<<"Select 1 if you want to play first.\n";

              cout<<"3 will be displayed for user move\n";

              cout<<"Select 2 if you want computer to play first\n";

              cout<<"5 will be displayed for computer move\n";

              cin>>decision;

              switch(decision)

              {

                             case 1:

                                           cout<<"You chose to play first\n";

                                           display_board();

                                           user_turn();

                             case 2:

                                           cout<<"Computer plays first\n";

                                           display_board();

                                           comp_turn();

                             default:

                                           cout<<"Invalid option\n";          

                            

              }

}

void display_board()

{

              for(i=0;i<9;i++)

              {

                             if(board[i]==2)

                                           board[i]= 2;

                             else if(board[i]==3)

                                           board[i]=3;

                             else

                                           board[i]=5;                                    

              }

              cout<<board[0]<<"|"<<board[1]<<"|"<<board[2]<<endl;

              cout<<"_"<<" "<<"_"<<" "<<"_"<<" "<<endl;

              cout<<board[3]<<"|"<<board[4]<<"|"<<board[5]<<endl;

              cout<<"_"<<" "<<"_"<<" "<<"_"<<" "<<endl;

              cout<<board[6]<<"|"<<board[7]<<"|"<<board[8]<<endl;

              cout<<"_"<<" "<<"_"<<" "<<"_"<<" "<<endl;      

}

void check_win()

{

 

              if(board[0]==3 && board[1]==3 && board[2]==3)

              {

                             cout<<"user wins";

                             exit(0);

              }

              if(board[3]==3 && board[4]==3 && board[5]==3)

              {

                                           cout<<"user wins\n";

                                           exit(0);

              }

               if(board[6]==3 && board[7]==3 && board[8]==3)

              {

                                           cout<<"user wins\n";

                                           exit(0);

              }

               if(board[0]==3 && board[3]==3 && board[6]==3)

              {

                                           cout<<"user wins\n";

                                           exit(0);

              }

               if(board[1]==3 && board[4]==3 && board[7]==3)

              {

                                           cout<<"user wins\n";

                                           exit(0);

              }

               if(board[2]==3 && board[5]==3 && board[8]==3)

                             {

                                          

                             cout<<"user wins\n";

                             exit(0);

              }

               if(board[0]==3 && board[4]==3 && board[8]==3)

              {

             

                             cout<<"user wins\n";

                             exit(0);

              }

               

             

              if(board[2]==3 && board[4]==3 && board[6]==3)

              {

                             cout<<"user wins\n";

                                           exit(0);

              }

             

}

int possible_win(int player)

{

              int possible_win=-1;

              if(player==3)

              {

             

                             if(board[0]*board[1]*board[2]==18)

                             {

                                           if(board[0]==2)

                                                          possible_win=0;

                                           if(board[1]==2)

                                                          possible_win=1;

                                           if(board[2]==2)

                                                          possible_win=2;

                             }

             

                             if(board[3]*board[4]*board[5]==18)

                             {

                                           if(board[3]==2)

                                                          possible_win=3;

                                           else if(board[4]==2)

                                                          possible_win =4;

                                           else

                                           {

                                           if(board[5]==2)

                                                          possible_win =5;            

                                           }

                             }

                             if(board[6]*board[7]*board[8]==18)

                             {

                                           if(board[6]==2)

                                                          possible_win=6;

                                           else if(board[7]==2)

                                                          possible_win =7;

                                           else

                                           {

                                           if(board[8]==2)

                                                          possible_win =8;            

                                           }

                             }

                             if(board[0]*board[3]*board[6]==18)

                             {

                                           if(board[0]==2)

                                                          possible_win=0;

                                           else if(board[3]==2)

                                                          possible_win =3;

                                           else

                                           {

                                           if(board[6]==2)

                                                          possible_win =6;            

                                           }

                             }

                             if(board[1]*board[4]*board[7]==18)

                             {

                                           if(board[1]==2)

                                                          possible_win=1;

                                           else if(board[4]==2)

                                                          possible_win =4;

                                           else

                                           {

                                           if(board[7]==2)

                                                          possible_win =7;

                                           }

                             }

                              if(board[2]*board[5]*board[8]==18)

                             {

                                           if(board[2]==2)

                                                          possible_win=2;

                                           else if(board[5]==2)

                                                          possible_win =5;

                                           else

                                           {

                                                          if(board[8]==2)

                                                          possible_win =8;

                                           }

                             }

                             if(board[0]*board[4]*board[8]==18)

                             {

                                           if(board[0]==2)

                                                          possible_win=0;

                                           else if(board[4]==2)

                                                          possible_win =4;

                                           else

                                           {

                                                          if(board[8]==2)

                                                          possible_win =8;

                                           }

                             }

                             if(board[2]*board[4]*board[6]==18)

                             {

                                           if(board[2]==2)

                                                          possible_win=2;

                                           else if(board[4]==2)

                                                          possible_win =4;

                                           else

                                           {

                                                          if(board[6]==2)

                                          

                                                          possible_win =6;

                                           }

                             }

              }

              if (player==5)

              {

 

                            if(board[0]*board[1]*board[2]==50)

                             {

                                           if(board[0]==2)

                                                          possible_win=0;

                                           else if(board[1]==2)

                                                          possible_win=1;

                                           else

                                           {

                                                          if(board[2]==2)

                                                          possible_win=2;

                                           }

                             }

                              if(board[3]*board[4]*board[5]==50)

                             {

                                           if(board[3]==2)

                                                          possible_win=3;

                                           else if(board[4]==2)

                                                          possible_win =4;

                                           else

                                           {

                                           if(board[5]==2)

                                                          possible_win =5;

                                           }

                             }

                              if(board[6]*board[7]*board[8]==50)

                             {

                                           if(board[6]==2)

                                                          possible_win=6;

                                           else if(board[7]==2)

                                                          possible_win =7;

                                           else

                                           {

                                                          if(board[8]==2)

                                                          possible_win =8;            

                                           }

                             }

                              if(board[0]*board[3]*board[6]==50)

                             {

                                           if(board[0]==2)

                                                          possible_win=0;

                                           else if(board[3]==2)

                                                          possible_win =3;

                                           else

                                           {

                                                          if(board[6]==2)

                                                          possible_win =6;            

                                           }

                             }

                              if(board[1]*board[4]*board[7]==50)

                             {

                                           if(board[1]==2)

                                                          possible_win=1;

                                           else if(board[4]==2)

                                                          possible_win =4;

                                           else

                                           {

                                                          if(board[7]==2)

                                                          possible_win =7;

                                           }

                             }

                              if(board[2]*board[5]*board[8]==50)

                             {

                                           if(board[2]==2)

                                                          possible_win=2;

                                           else if(board[5]==2)

                                                          possible_win =5;

                                           else

                                           {

                                                          if(board[8]==2)

                                                          possible_win =8;

                                           }

                             }

                              if(board[0]*board[4]*board[8]==50)

                             {

                                           if(board[0]==2)

                                                          possible_win=0;

                                           else if(board[4]==2)

                                                          possible_win =4;

                                           else

                                           {

                                                         if(board[8]==2)

                                                          possible_win =8;

                                           }

                             }

                              if(board[2]*board[4]*board[6]==50)

                             {

                                           if(board[2]==2)

                                                          possible_win=2;

                                           else if(board[4]==2)

                                                          possible_win =4;

                                           else

                                           {

                                                          if(board[6]==2)

                                                          possible_win =6;                          

                                           }

                             }

 

              }

                            

             

              return possible_win;

}

 

void user_turn(){

              cout<<"turn is"<<turn<<endl;

              cout<<"user turn\n";

              cout<<"enter your choice\n";

              cin>>choice;

              if (board[choice]==2)

              {

                             board[choice]=3;

                             display_board();

                             check_win();

                                           if(turn==9)

                                           {

                                           cout<<"game draw\n";

                                           }

                                           else

                                                          turn++;

                                                          comp_turn();

              }

              else

                             cout<<"place not empty\n";

                             user_turn();

}

void comp_turn()

{

              cout<<"Computer turn\n";

              cout<<"turn is "<<turn<<"\n";

              switch(turn)

              {

                             case 1:

                                           board[0]=5;

                                           display_board();

                                           turn++;

                                           user_turn();

             

                             case 2:

                                           if(board[4]==2)

                                           {

                                                                        board[4]=5;

                                                          display_board();

                                                          turn++;

                                                          user_turn();

                                           }

                                           else

                                           {

                                                          board[0]=5;

                                                          display_board();

                                                          turn++;

                                                          user_turn();

                                           }

 

                             case 3:

                                           if(board[8]==2)

                                           {

                                                                        board[8]=5;

                                                          display_board();

                                                          turn++;

                                                          user_turn();

                                           }

                                           else

                                           {

                                                          board[2]=5;

                                                          display_board();

                                                          turn++;

                                                          user_turn();

                                           }

 

                             case 4: 

                                           if(possible_win(3)>=0)

                                           {

                                                          board[possible_win(3)]=5;

                                                          display_board();

                                                          turn++;

                                                          user_turn();

                                           }

                                           else

                                           {

                                                          if(board[1]==3 &&board[7]==3)

                                                          {

                                                         

                                                                        board[6]=5;

                                                                        display_board();

                                                                        turn++;

                                                                        user_turn;

                                                          }

                                                          else

                                                          {

                                                                        if(board[2]==3 && board[7]==3)

                                                                        {

                                                                        board[8]=5;

                                                                        display_board();

                                                                        turn++;

                                                                        user_turn;                       

                                                                        }

                                                                        else if(board[0]==2 && board[5]==2)

                                                                        {

                                                                        board[2]=5;

                                                                        display_board();

                                                                        turn++;

                                                                        user_turn;         

                                                                        }

                                                                        else if(board[2]==3 && board[3]==3)

                                                                        {

                                                                        board[0]=5;

                                                                        display_board();

                                                                        turn++;

                                                                        user_turn;         

                                                                        }

                                                                        else if(board[6]==3 && board[5]==3)

                                                                        {

                                                                        board[8]=5;

                                                                        display_board();

                                                                        turn++;

                                                                        user_turn;         

                                                                        }

                                                                        else if(board[6]==3 && board[1]==3)

                                                                        {

                                                                        board[0]=5;

                                                                        display_board();

                                                                        turn++;

                                                                        user_turn;         

                                                                        }

                                                                        else if(board[8]==3 && board[3]==3)

                                                                        {

                                                                        board[6]=5;

                                                                        display_board();

                                                                        turn++;

                                                                        user_turn;         

                                                                        }

                                                                        else if(board[8]==3 && board[1]==3)

                                                                        {

                                                                        board[2]=5;

                                                                        display_board();

                                                                        turn++;

                                                                        user_turn;         

                                                                        }

                                                                       

                                                                        else

                                                                        {

                                                                                      if(board[4]==2)

                                                                                      {

                                                                                                     board[4]=5;

                                                                                                     display_board();

                                                                                                     turn++;

                                                                                                     user_turn;

                                                                                      }

                                                                       

                                                                                      else

                                                                                      {

                                                                                                     if(board[2]==2)

                                                                                                     {

                                                                                                                                 board[2]=5;

                                                                                                                   display_board();

                                                                                                                   turn++;

                                                                                                                   user_turn();

                                                                                                     }

                                                                                                     else

                                                                                                     {

                                                                                                                   board[6]=5;

                                                                                                                   display_board();

                                                                                                                   turn++;

                                                                                                                   user_turn();

                                                                                                     }

                                                                                      }

                                                                        }

                                                          }

                                           }

             

                             case 5:

                                           if (possible_win(5)>=0)

                                           {

                                                          if(board[possible_win(5)]==2)

                                                         

                                                          {

                                                          board[possible_win(5)]=5;

                                                          display_board();

                                                          cout<<"cpu wins\n";

                                                          break;

                                                          }

                                           }

                                           else

                                                          if (possible_win(3)>=0)

                                                          {

                                                                        board[possible_win(3)]=5;

                                                                        display_board();

                                                                        turn++;

                                                                        user_turn();

                                                          }

                                                          else

                                                          {

                                                                        if(board[6]==2)

                                                                        {

                                                                                                     board[6]=5;

                                                                                      display_board();

                                                                                      turn++;

                                                                                      user_turn();

                                                                        }

                                                                        else

                                                                        {            

                                                                                      if(board[2]==2)

                                                                                      board[2]=5;

                                                                                      display_board();

                                                                                      turn++;

                                                                                      user_turn();

                                                                        }

                                                          }

                                                                                     

                             case 6:

                                           if(possible_win(5)>=0)

                                           {

                                                          board[possible_win(5)]=5;

                                                          display_board();

                                                          cout<<"cpu wins\n";

                                                          exit(0);

                                           }

                                           else

                                           {            

 

                                                          if(possible_win(3)>=0)

                                                          {

                                                                        board[possible_win(3)]=5;

                                                                        display_board();

                                                                        turn++;

                                                                        user_turn();

 

                                                          }

                                                          else{

 

                                                                        if(board[4]==2)

                                                                        {

                                                                                      board[4]=5;

                                                                                      display_board();

                                                                                      turn++;

                                                                                      user_turn();

                                                                        }

                                                                        else

                                                                        {            

                                                                                      if(board[1]==2)

                                                                                      {

                                                                                                     board[1]=5;

                                                                                                     display_board();

                                                                                                     turn++;

                                                                                                     user_turn();

                                                                                      }

                                                                                      else

                                                                                      {

                                                                                                     if(board[3]==2)

                                                                                                     {

                                                                                                                   board[3]=5;

                                                                                                                   display_board();

                                                                                                                   turn++;

                                                                                                                   user_turn();

                                                                                                     }

                                                                                                     else

                                                                                                     {            

                                                                                                                   board[5]=5;

                                                                                                                   display_board();

                                                                                                                   turn++;

                                                                                                                   user_turn();

                                                                                                     }

                                                                                       }

                                                                        }

 

                                                          }

 

                                                         

                                           }

                            

                             case 7:

                                           if(possible_win(5)>=0)

                                           {

                                          

                                                          board[possible_win(5)]=5;

                                                          display_board();

                                                          cout<<"cpu wins\n";

                                                          exit(0);

                                           }

                                           else

                                           {            

                                                          if(possible_win(3)>=0)

                                                          {

                                                                        board[possible_win(3)]=5;

                                                                        display_board();

                                                                        turn++;

                                                                        user_turn();

                                                          }

                                                          else

                                                          {

                                                                        for(i=0;i<9;i++)

                                                                        {

                                                                                      if (board[1]==2)

                                                                                      {            

                                                                                                     board[i]=5;

                                                                                                     display_board();

                                                                                                     turn++;

                                                                                                     user_turn();

                                                                                       }

                                                                        }            

                                                         }

                                           }

                            

                             case 8:

                                           if(possible_win(5)>=0)

                                           {

                                                                        board[possible_win(5)]=5;

                                                          display_board();

                                                          cout<<"cpu wins\n";

                                                          exit(0);

                                           }

                                           else

                                           {            

                                                          if(possible_win(3)>=0)

                                                          {

                                                                        board[possible_win(3)]=5;

                                                                        display_board();

                                                                        turn++;

                                                                        user_turn();

                                                          }

                                                          else

                                                          {             for(i=0;i<9;i++)

                                                                        {

                                                                                      board[i]=5;

                                                                                      display_board();

                                                                                      turn++;

                                                                                      user_turn();

                                                                        }            

                                                          }

                                           }

 

                             case 9:

                                            if(possible_win(5)>=0)

                                            {

                                                          board[possible_win(5)]=5;

                                                           display_board();

                                                           cout<<"cpu wins\n";

                                                           exit(0);

                                           }

                                           else

                                           {

                                                          for(i=0;i<9;i++)

                                                         {

                                                                        if(board[i]==2)

                                                                                       board[i]=5;

                                                                                       display_board();

                                                                                       cout<<"game draw\n";

                                                                                       exit(0);

                                                          }                                                       

                                           }

                                          

              }

 

}