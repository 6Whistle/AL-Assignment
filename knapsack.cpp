#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;
 
int main(void){
    //n = number of items, w = being able to carry(pound)
    int n, w;

    //Get n and w from user
    //input format : (n : int) (w : int)
    cout << "n W : ";
    cin >> n >> w;
    //Check n and w are correct value(0 <= n <= 5, 0 <= W <= 5)
    if(n < 0 || n > 5 || w < 0 || w > 5)  return -1;

    //Items' Data vector
    //Each item data consist of pair(item's value, item's weight) 
    vector<pair<int, int> > item(n);
    
    //Get items' Data from user
    //input format : (v : int) (w : int)
    //repeat n times
    for(int i = 0; i < n; i++){
        cout << "item " << i + 1 << "'s v w : ";
        cin >> item[i].first >> item[i].second;
        //Check v and w are correct value(1 <= v <= 50, 1 <= w <= 5)
        if(item[i].first < 1 || item[i].first > 50 || item[i].second < 1 || item[i].second > 5)     return -1;
    }
    
    //Table for Dynamic Programming
    //row : n + 1, cal : w + 1
    //initialized with 0 
    vector<vector<int> > table(n+1, vector<int>(w+1, 0));

    //Dynamic Programming(Bottom-up)
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < w+1; j++){
            //if i w > 0 and w_i > w, c[i, w] = c[i-1, w]
            if(item[i-1].second > j)    table[i][j] = table[i-1][j];
            //if i w > 0 and w_i <= w, c[i, w] = max(v_i + c[i-1, w - w_i], c[i-1, w])
            else    table[i][j] = max(item[i-1].first + table[i-1][j - item[i-1].second], table[i-1][j]);
        }
    }

    //Print Table
    cout << "\nTable : " << endl;
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < w+1; j++)    cout << setw(4) << left << table[i][j];
        cout << endl;
    }

    //Print Value
    cout << "\nValue : " << table[n][w] << endl;

    //Optimal Solution Vector
    //Data will be sorted by decending order
    vector<int> opt;

    //Find Optimal Solution
    //Repeat until i or j pointer can't move before
    for(int i = n, j = w; i != 0 && j != 0; i--){
        //if current item was added, add item at opt
        if(table[i][j] != table[i-1][j]){
            opt.push_back(i-1);
            j -= item[i-1].second;
        }
    }
    
    //Print Optimal Solution by ascending order
    cout << "\noptimal solution : ";
    while(!opt.empty()){
        cout << opt.back() + 1 << " ";
        opt.pop_back();
    }
    cout << endl;

}