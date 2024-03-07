#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define numberOfCards 3

int main()
{
    // nhập từ file
    // khởi tạo đối tượng file
    ifstream f;
    f.open("Input11.txt", ios_base::in);
    // khởi tạo danh sách người chơi
    vector<string> listOfPlayers;
    listOfPlayers.push_back("Thang");
    listOfPlayers.push_back("Trung");
    listOfPlayers.push_back("Tri");
    listOfPlayers.push_back("Quy");
    listOfPlayers.push_back("Bao");
    listOfPlayers.push_back("Giang");
    int numberOfPlayer = listOfPlayers.size();
    // nhập người chơi từ file
    // khởi tạo vector lồng nhau để chứa Input đầu vào
    vector<vector<string>> Input;
    for (int i = 0; i < numberOfPlayer; i++)
    {
        vector<string> v;
        for (int j = 0; j < numberOfCards; j++)
        {
            string x;
            f >> x;
            v.push_back(x);
        }
        Input.push_back(v);
    }
    f.close();
    // kiểm tra trong trường hợp đặc biệt
    // cả 3 lá phải là những lá đặc biệt
    vector<string> listOfWinner;
    for (int i = 0; i < numberOfPlayer; i++)
    {
        int cnt = 0;
        for (int j = 0; j < numberOfCards; j++)
        {
            if (Input[i][j] == "J" || Input[i][j] == "Q" || Input[i][j] == "K")
            {
                cnt++;
            }
        }
        if (cnt >= numberOfCards)
        {
            listOfWinner.push_back(listOfPlayers[i]);
        }
    }
    // trường hợp tính điểm
    if (listOfWinner.size() == 0)
    {
        vector<int> scoreOfPlayer;
        int max = 0;
        for (int i = 0; i < numberOfPlayer; i++)
        {
            int score = 0;
            for (int j = 0; j < numberOfCards; j++)
            {
                if (Input[i][j] == "A")
                    score++;
                else if (Input[i][j][0] >= '2' || Input[i][j][0] <= '9')
                    score += atoi(Input[i][j].c_str());
            }
            score %= 10;
            scoreOfPlayer.push_back(score);
            if (score > max)
                max = score;
        }
        // lặp lần nữa để xác định ai có điểm lớn nhất
        for (int i = 0; i < numberOfPlayer; i++)
        {
            if (scoreOfPlayer[i] == max)
                listOfWinner.push_back(listOfPlayers[i]);
        }
    }
    for (int i = 0; i < listOfWinner.size() - 1; i++)
    {
        cout << listOfWinner[i] << endl;
    }
    cout << listOfWinner[listOfWinner.size() - 1];
}
