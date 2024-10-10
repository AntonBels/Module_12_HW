#include <string>
#include <iostream>

int subStrRepeatsNum(std::string subStr, std::string txt) // return count
{
    int M = subStr.size();
    int N = txt.size();
    int i = 0;
    int count = 0;

    while (i <= N - M)
    {
        int j;

        for (j = 0; j < M; j++)
            if (txt[i + j] != subStr[j])
                break;

        if (j == M)
        {
            //cout << "Pattern found at index " << i << " M = " << M << endl;
            i = i + M;
            count++;
        }
        else if (j == 0)
            i = i + 1;
        else
            i = i + j;
    }

    return count;
}

void IsKPeriodic(std::string str, int k)
{
    int N = str.size();

    std::string subStr;
    int repeatsNum = 0;
    // match index with number of string. Start from i = 1 to find substriing with minimum length
    for (int i = 1; i <= N; i++)
    {
        // choose substring with length i, starting from the beginning
        subStr = str.substr(0, i);

        // in case of length of substring match with k
        if (k == subStr.size())
        {
            // find number of re-entires of substring
            repeatsNum = subStrRepeatsNum(subStr, str);

            // if re-interes of substring is not equal to null substring is equl to text then k is true
            if (repeatsNum > 0 && repeatsNum * subStr.size() == N)
            {
                std::cout << "The string '" << str << "' is periodic with base k = " << k << std::endl;
                return;
            }
        }
    }

    std::cout << "The string '" << str << "' is NOT a periodic with base k = " << k << std::endl;
}

int main()
{
    std::string str = "abcabcabcabc";
    IsKPeriodic(str, 3);

    std::string str1 = "aaaaaaaa";
    IsKPeriodic(str1, 4);

    std::string str2 = "abcde";
    IsKPeriodic(str2, 5);

    std::string str3 = "bbb";
    IsKPeriodic(str3, 1);

    std::string str4 = "abcd";
    IsKPeriodic(str4, 2);

    return 0;
}