#include <iostream>
#include <cstdlib>
#include <stdlib.h> 
#include <sstream>
#include <math.h> 

using namespace std;

class FibLFSR {
public:
    //int output;
    int reg;
    int * LSFR;
    
    

FibLFSR(std::string seed)
{
     srand (time(NULL));
    //int random; 
    //std::cout << "Enter string to be inputted into LSFR register: \n";
    //std::cin >> seed;

    std::stringstream geek(seed); 
    reg = seed.size();
    LSFR = new int [reg];
    int ctr=0;

    for(int i=15; i >= 0; i--)
    {
        LSFR[i]=seed[ctr]-'0';
        ctr++;
    }

/*  A test to make sure my ints were being entered into the array properly 

    for (int i=0; i<16; i++)
    {
        std::cout << "Array Num: [" << i << "] = " << LSFR[i] << "\n";
    }
    
   */
    

}; // constructor to create LFSR with // the given initial seed and tap
     int step(){

         int tap, left;
         int output;

         tap = LSFR[13];
         left = LSFR[15];
         
    
         if(tap == 0 && left == 0)
         {
             output = 0;
         }
         else if(tap == 1 && left == 1)
         {
             output = 0;
         }
         else if(tap == 0 && left == 1)
         {
             output = 1;
         }
         else if(tap == 1 && left == 0)
         {
             output = 1;
         }
         

         
       
        //goes through array and shifts values to the left besides the value in [0]
       for(int i=reg; i >= 1 ; i--)
        {
            LSFR[i] = LSFR[i-1];
            //std::cout << "Index: " << i << " Value: " << LSFR[i] << "\n";
        }
        
        //replaces the last element in array with the output 
         LSFR[0] = output; 

        // prints out the new bit code
         for(int i=15; i >= 0; i--)
         {
             std::cout << LSFR[i];
         }
         std::cout << " " << output << "\n";
    
    return 0;
     };         
     
       // simulate one step and return the
                           // new bit as 0 or 1
     int generate(int k)
     {
         int total=0;
         int z=0;

         while(k!=0)
         {
            if(LSFR[z] == 1)
            {
                total += pow(2, z);
            }
            z++;
            k--;
         }

         for(int i=15; i >= 0; i--)
         {
             std::cout << LSFR[i];
         }

         std::cout << " " << total << "\n";

         return 0;
     };  // simulate k steps and return
private: 

};


int main() {

    std::cout << "Starting LSFR:\n";
    FibLFSR f1("1011011000110110");
    std::cout << "\nRunning Step:\n";
    f1.step();
    f1.step();
    f1.step();
    f1.step();
    f1.step();
    f1.generate(5);

}
/*

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main


BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);
}
*/