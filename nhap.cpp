#include <bits/stdc++.h>
using namespace std;
string mergeAlternately(string word1, string word2)
{
    string result, w1, w2;
    int lengthOfstrings = word1.length() + word2.length();
    int minLength = max(word1.length(), word2.length());
    // for (int i = 0; i < minLength; i++)
    // {
    //     result.push_back(word1[i]);
    //     result.push_back(word2[i]);
    // }
    // for (int i = minLength; i < lengthOfstrings; i++)
    // {

    //     if (word2.length() > minLength)
    //     {
    //         result.push_back(' ');
    //         result.push_back(word2[i]);
    //     }
    //     else if (word1.length() > minLength)
    //     {
    //         result.push_back(word1[i]);
    //         result.push_back(' ');
    //     }
    // }
    int i = 0, j = 0;
    while (i < word1.length()||j<word2.length())
    {
        if(i<word1.length()){
            result.push_back(word1[i++]);
        }else if(j<word2.length()){
            result.push_back(word2[j++]);
        }
    }
    return result;
}
int main()
{
    string s1 = {"ab"}, s2 = {"pqrs"};
    string result = mergeAlternately(s1, s2);
    for (int i = 0; i < result.length(); i++)
    {
        cout << result[i];
    }
}