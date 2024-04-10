class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int>result(deck.size());
        int deckIndex = 0;
        int resIndex = 0;
        bool skip = false;

        sort(deck.begin(),deck.end());
        while(deckIndex<deck.size()){
            if(result[resIndex]==0){
                if(!skip){
                    result[resIndex] = deck[deckIndex++];
                }
                skip = !skip;
            }
            resIndex = (resIndex + 1)%(deck.size());
        }
    return result;
    }
};