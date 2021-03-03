#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef set<pi>::iterator si;

///////////////////   Balanced Binary Search Tree   ///////////////////
// set<pi> s; // {(value, index)}
// si mIter;

// int getMedian() {
//     return (*mIter).first;
// }

// void add(pi newElem) {
//     auto [iter, _] = s.insert(newElem);
//     if(s.size() == 1) {
//         mIter = iter;
//         return;
//     }
//     if(s.size()%2) {
//         if(newElem > *mIter) mIter++;
//     } else {
//         if(newElem < *mIter) mIter--;
//     }
// }

// void remove(pi remElem) {
//     if(s.size()%2) {
//         if(remElem >= *mIter) mIter--;
//     } else {
//         if(remElem <= *mIter) mIter++;
//     }
//     s.erase(remElem);
// }

// int main() {
//     ios::sync_with_stdio(0); 
//     cin.tie(0);

//     int n, k;
//     cin >> n >> k;
//     vi arr(n);
//     for(int i = 0; i < n; ++i) cin >> arr[i];

//     for(int i = 0; i < n; ++i) {
//         auto newElem = make_pair(arr[i], i);
//         add(newElem);
//         if(i == k-1) cout << getMedian() << " ";
//         if(i >= k) {
//             auto remElem = make_pair(arr[i-k], i-k);
//             remove(remElem);
//             cout << getMedian() << " ";
//         }
//     }
// }

//////////////////   Less Heap + Larger Heap    ///////////////////
set<pi, greater<pi>> lessHeap; // as Max Heap {(value, index)}
set<pi> largerHeap; // as Min Heap

int getMedian() {
    return (*lessHeap.begin()).first;
}

void balance() {
    if(largerHeap.size() > lessHeap.size()) {
        lessHeap.insert(*largerHeap.begin());
        largerHeap.erase(largerHeap.begin());
    }
    if(lessHeap.size() >= largerHeap.size()+2) {
        largerHeap.insert(*lessHeap.begin());
        lessHeap.erase(lessHeap.begin());
    }
}

void add(pi newElem) {
    if(lessHeap.size()==0 || newElem <= *lessHeap.begin()) lessHeap.insert(newElem);
    else largerHeap.insert(newElem);
    balance();
}

void remove(pi remElem) {
    if(remElem <= *lessHeap.begin()) lessHeap.erase(remElem);
    else largerHeap.erase(remElem);
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
        if(i == k-1) cout << getMedian() << " ";
        if(i >= k) {
            auto remElem = make_pair(arr[i-k], i-k);
            remove(remElem);
            cout << getMedian() << " ";
        }
    }
}