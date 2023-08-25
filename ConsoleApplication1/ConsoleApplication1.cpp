
#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    if(s.length() % 2 != 0)
        return false;
    int sum = 0;
    for (char a : s)
    {
        if (sum < 0)
            return false;
        sum = a == '(' ? sum + 1 : sum - 1;
    }
    return sum == 0;
}
//
// int main(int argc, char* argv[])
// {
//     string s = "())(";
//     solution(s);
//     return 0;
// }
