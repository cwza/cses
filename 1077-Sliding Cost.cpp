#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

/*
Almost same as 1076-Sliding Median, but store additional curLessSum and curLargerSum
*/

set<pi, greater<pi>> lessHeap; // as Max Heap {(value, index)}
set<pi> largerHeap; // as Min Heap
ll curLessSum = 0;
ll curLargerSum = 0;

int getMedian() {
    return (*lessHeap.begin()).first;
}

void balance() {
    if(largerHeap.size() > lessHeap.size()) {
        lessHeap.insert(*largerHeap.begin());
        curLessSum += (*largerHeap.begin()).first;
        curLargerSum -= (*largerHeap.begin()).first;
        largerHeap.erase(largerHeap.begin());
    }
    if(lessHeap.size() >= largerHeap.size()+2) {
        largerHeap.insert(*lessHeap.begin());
        curLargerSum += (*lessHeap.begin()).first;
        curLessSum -= (*lessHeap.begin()).first;
        lessHeap.erase(lessHeap.begin());
    }
}

void add(pi newElem) {
    if(lessHeap.size()==0 || newElem <= *lessHeap.begin()) {
        lessHeap.insert(newElem);
        curLessSum += newElem.first;
    }
    else {
        largerHeap.insert(newElem);
        curLargerSum += newElem.first;
    }
    balance();
}

void remove(pi remElem) {
    if(remElem <= *lessHeap.begin()) {
        curLessSum -= remElem.first;
        lessHeap.erase(remElem);
    }
    else {
        curLargerSum -= remElem.first;
        largerHeap.erase(remElem);
    }
    balance();
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vi arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    for(int i = 0; i < n; ++i) {
        auto newElem = make_pair(arr[i], i);
        add(newElem);
        if(i == k-1) {
            int median = getMedian();
            cout << median*lessHeap.size()-curLessSum + curLargerSum-median*largerHeap.size() << " ";
        }
        if(i >= k) {
            auto remElem = make_pair(arr[i-k], i-k);
            remove(remElem);
            int median = getMedian();
            cout << median*lessHeap.size()-curLessSum + curLargerSum-median*largerHeap.size() << " ";
        }
    }
}