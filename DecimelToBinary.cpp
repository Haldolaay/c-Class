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
// another approach
#include <iostream>
// int powerResult(int num, int power){
//   int result = num;
//   for(int i = power; i>1 ; i--){
//     result *= num;
//   }
//   return result;
// }
int main() {
    // method is num - (2 * (num/2))
    int number;
    std::cout << "Enter an integer [0 to 65535]:" << std::endl;
    std::cin >> number;
    std::string result = "";
    int reminder;
    int power = 2;
    std::string divisionResult = "";
    for (int i = 15; i >= 0; i--) {
        for (int k = i; k > 1; k--) {
            power *= power;
        }
        int comparisionNumber = power - 1;
        // std::cout<<comparisionNumber<<std::endl;
        if (comparisionNumber > number) {
            result += "0";
            // std::cout<<result<<std::endl;
        }
        else {
            reminder = number - (2 * (number / 2));
            // std::cout<<reminder<<std::endl;
            number = number / 2;
            if (reminder > 0) {
                divisionResult += "1";

            }
            else {
                divisionResult += "0";
            }

        }
        power = 2;
    }

    for (int j = divisionResult.size(); j >= 0; j--) {
        result += divisionResult[j];
    }

    std::cout << result << std::endl;
}
