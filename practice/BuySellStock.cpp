#include <vector>
#include <iostream>

using namespace std;

/*****************************************
Problem type: One-pass array / greedy
Idea: Track the cheapest price seen so far and the best profit.
******************************************/

class Stock{
public:
  int maxProfit(const std::vector<int>& prices){
    if(prices.empty()) return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int price : prices){
      minPrice = min(minPrice, price);
      int profit = price- minPrice;

      maxProfit = max(maxProfit, profit);
      // cout<< maxProfit<< endl;
    }
    return maxProfit;
  }
};

int main() {
  Stock S;

  {vector<int> prices = {7,1,5,3,6,4};
  cout << "maxProfit: "<<S.maxProfit(prices) << endl;}

  {vector<int> prices = {};
cout << "maxProfit: "<<S.maxProfit(prices) << endl;}
  {vector<int> prices = {1};
cout << "maxProfit: "<<S.maxProfit(prices) << endl;}
  {vector<int> prices = {3,1};
cout << "maxProfit: "<<S.maxProfit(prices) << endl;}
  {vector<int> prices = {3,2,6,1,8};
cout << "maxProfit: "<<S.maxProfit(prices) << endl;}}
