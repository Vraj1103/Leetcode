class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        if(hand.size()%g!=0)return false;
        map<int,int>mp;
        for(int i:hand){
            mp[i]++;
        }

        while(mp.size()){
            int a = mp.begin()->first;
            for(int i = 0;i<g;i++){
                int x = a+i;
                if(mp.find(x)!=mp.end()){
                    mp[x]--;
                    if(!mp[x])mp.erase(x);
                }
                else return false;
            }
        }
        return true;
    }
};