#include <iostream>

 std::string addingZeroesToResult(std::string result){
     if(result.size() < 16){
       int i = 16 - result.size();
     for ( ; i>0 ; i--){
       result = "0"+ result;
     }
   }
   return result;
 }
 std::string toBinary(unsigned short num){
   std::string result = "";
   while(num>0){
     result = std::to_string(num % 2) + result;
     num = num/2;
   }

   result = addingZeroesToResult(result);
   return result;
 };
int main() {
  int userInput;
  std::cout<<"enter a number between 0 and 65535"<<std::endl;
  std::cin>>userInput;
  if(userInput > 65535 || userInput < 0){
    std::cout<<"the input number is invalid";
    return 0;
  }
  unsigned short value = (unsigned short)userInput;
  std::cout<<value<< " => \""<<toBinary(value)<<"\""<<std::endl;
  return 1;
}
