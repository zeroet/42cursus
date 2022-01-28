#include <iostream>

#include <string>

using namespace std;

 

int main(void)

{

     string s = "hello";

     string s2 = "hello";

     string s3;

 

     if(s == s2)

     {

           cout<<"서로 같아요"<<endl;

     }

     else

     {

           cout<<"서고 달라요."<<endl;

     }

 

     s3 = s;

     cout<<"s3 is"<<endl;

 

     return 0;

}
