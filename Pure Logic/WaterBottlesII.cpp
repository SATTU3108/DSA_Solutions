/*
You are given two integers numBottles and numExchange.

numBottles represents the number of full water bottles that you initially have. In one operation, you can perform one of the following operations:

Drink any number of full water bottles turning them into empty bottles.
Exchange numExchange empty bottles with one full water bottle. Then, increase numExchange by one.
Note that you cannot exchange multiple batches of empty bottles for the same value of numExchange. For example, if numBottles == 3 and numExchange == 1, you cannot exchange 3 empty water bottles for 3 full bottles.

Return the maximum number of water bottles you can drink.
*/

int maxBottlesDrunk(int numBottles, int numExchange) {
    int full=numBottles,empty=0,exchange=numExchange;
    int ans=0;
    while (full>0) {
        ans+=full;
        empty+=full;
        full=0;
        if (empty>=exchange) {
            empty-=exchange;
            full=1;
            exchange++;
        }
        else break;
    }
    return ans;
}
