#include <bits/stdc++.h>
using namespace std;

/*The Tower of Hanoi is a mathematical puzzle with three poles and stacked disks of different sizes.
The goal is to move all disks from the source pole to the destination pole using an auxiliary pole, following two rules:

Only one disk can be moved at a time.
A larger disk cannot be placed on a smaller one.
*/

char rod[]={'S','A','D'};
vector<stack<int>> stacks(3);
void moveDisk(int a,int b) {
    if (stacks[b].empty() || (!stacks[a].empty() && stacks[a].top()<stacks[b].top())) {
        cout<<"Move disk "<<stacks[a].top()<<" from rod "<<rod[a]<<" to rod "<<rod[b]<<endl;
        stacks[b].push(stacks[a].top());
        stacks[a].pop();
    }
    else moveDisk(b,a);
}
void towerOfHanoi(int n) {
    cout<<"Tower of Hanoi for "<<n<<" disks"<<endl;
    int src=0,aux=1,dest=2;
    for (int i=n;i>0;i--) stacks[src].push(i);
    int totalMoves=(1<<n)-1;
    if (n%2==0) swap(aux,dest);
    for (int i=1;i<=totalMoves;i++) {
        if (i%3==1) moveDisk(src,dest);
        else if (i%3==2) moveDisk(src,aux);
        else moveDisk(aux,dest);
    }
}
//time:O(2^n),space:O(n)