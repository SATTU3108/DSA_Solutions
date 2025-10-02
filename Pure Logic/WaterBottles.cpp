/*
There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.
*/

int numWaterBottles(int numBottles, int numExchange) {
    int full=numBottles,empty=0,exchange=numExchange;
    int ans=0;
    while (full>0) {
        ans+=full;
        empty+=full;
        full=0;
        if (empty>=exchange) {
            empty-=exchange;
            full=1;
        }
        else break;
    }
    return ans;
}
