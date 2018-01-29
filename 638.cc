#include <iostream>
#include <limits>
#include <numeric>
#include <vector>
using std::cout;
using std::endl;
using std::inner_product;
using std::min;
using std::numeric_limits;
using std::vector;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return shoppingOffers(price, special, needs, special.size());
    }
private:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, size_t sz) {
        if (sz == 0)
            return inner_product(price.cbegin(), price.cend(), needs.cbegin(), 0);
        vector<int> &offer = special[sz - 1];
        int numOffers = numeric_limits<int>::max();
        for (size_t i = 0; i < needs.size(); ++i) {
            if (offer[i] > 0)
                numOffers = min(numOffers, needs[i] / offer[i]);
        }
        vector<int> needs_(needs.cbegin(), needs.cend());
        int lowest = numeric_limits<int>::max();
        for (int n = 0; n <= numOffers; ++n) {
            lowest = min(lowest, offer.back() * n + shoppingOffers(price, special, needs_, sz - 1));
            for (size_t i = 0; i < needs.size(); ++i)
                needs_[i] -= offer[i];
        }
        return lowest;
    }
};

int main() {
    vector<int> price1 = {2, 5};
    vector<vector<int>> special1 = {{3, 0, 5}, {1, 2, 10}};
    vector<int> needs1 = {3, 2};
    cout << Solution().shoppingOffers(price1, special1, needs1) << endl;
    vector<int> price2 = {2, 3, 4};
    vector<vector<int>> special2 = {{1, 1, 0, 4}, {2, 2, 1, 9}};
    vector<int> needs2 = {1, 2, 1};
    cout << Solution().shoppingOffers(price2, special2, needs2) << endl;
    return 0;
}
