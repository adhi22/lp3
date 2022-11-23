#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    double r1 = p1.first / p1.second;
    double r2 = p2.first / p2.second;
    return r1 > r2;
}

double functionalKnapsack(vector<pair<int, int>> &arr, int wt)
{
    double ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].second <= wt)    // add item completely
        {
            wt -= arr[i].second;
            ans += arr[i].first;
        }
        else
        {
            ans += arr[i].first * (double(wt) / double(arr[i].second));
            break;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    // {value, weight}
    vector<pair<int, int>> arr = {{60, 10}, {100, 20}, {120, 30}};
    sort(arr.begin(), arr.end(), comp);     // sort according to the max ratio of val:wt
    // for(auto itr : arr) {
    //     cout << itr.first << " " << itr.second << "\n";
    // }
    int maxWt = 50;
    cout << functionalKnapsack(arr, maxWt);
    return 0;
}
