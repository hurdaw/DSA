#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define numberOfCards 3
int main()
{
    ifstream fileIn;
    fileIn.open("Input_2.txt", ios_base::in);
    // khởi tạo danh sách người chơi
    vector<string> playerList;
    playerList.push_back("Thang");
    playerList.push_back("Trung");
    playerList.push_back("Tri");
    playerList.push_back("Quy");
    playerList.push_back("Bao");
    int numberOfMems = playerList.size();
    vector<vector<string>> input;
    for (int i = 0; i < numberOfMems; i++)
    {
        vector<string> v;
        for (int j = 0; j < numberOfCards; j++)
        {
            string x;
            fileIn >> x;
            v.push_back(x);
        }
        input.push_back(v);
    }
    fileIn.close();
    // kiểm tra ai thắng trong trường hợp đặc biệt
    vector<string> listOfWiners;
    for (int i = 0; i < numberOfMems; i++)
    {
        int cnt = 0;
        for (int j = 0; j < numberOfCards; j++)
        {
            if (input[i][j] == "J" || input[i][j] == "Q" || input[i][j] == "K")
            {
                cnt++;
            }
        }
        if (cnt >= 3)
        {
            listOfWiners.push_back(playerList[i]);
        }
    }
    // trường hợp bình thường
    vector<int> scoreOfPlayer;
    int max = 0;
    for (int i = 0; i < numberOfMems; i++)
    {
        int score = 0;
        for (int j = 0; j < numberOfCards; j++)
        {
            if (input[i][j] == "A")
                score++;
            else if (input[i][j][0] >= '2' || input[i][j][0] <= '9')
                score += atoi(input[i][j].c_str());
        }
        score %= 10;
        scoreOfPlayer.push_back(score);
        if (score > max)
            max = score;
    }
    for (int i = 0; i < numberOfMems; i++)
    {
        if (scoreOfPlayer[i] == max)
        {
            listOfWiners.push_back(playerList[i]);
        }
    }
    for (int i = 0; i < listOfWiners.size(); i++)
    {
        cout << listOfWiners[i] << " " << endl;
    }
}