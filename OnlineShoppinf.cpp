#include <bits/stdc++.h> #include #include #include

using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) { return a.second > b.second; }

int main() { int n; cin >> n;

vector<int> tokens(n);
for (int i = 0; i < n; ++i) {
    cin >> tokens[i];
}

vector<int> claim(n);
for (int i = 0; i < n; ++i) {
    cin >> claim[i];
}

int k;
cin >> k;

cin.ignore(); 

map<string, int> items;
string item;
int cost;
while (getline(cin, item, ':')) {
    cin >> cost;
    items[item] = cost;
    cin.ignore(); 
}

int maxTokens = 0;

int sum = 0;
for (int i = 0; i < n; i++) {
    if (claim[i] == 1)
        sum += tokens[i];
}

int maxi = 0;
for (int i = 0; i < n; i++) {
    int ans = 0;
    for (int j = i; j < i + k; j++) {
        if (claim[j] == 0)
            ans += tokens[j];
    }
    maxi = max(ans, maxi);
}
maxi += sum;


vector<pair<string, int>> itemsVector(items.begin(), items.end());

int a = 0;
for (auto &it : itemsVector) {
    if (it.second <= maxi) {
        a = max(a, it.second);
    }
}


sort(itemsVector.begin(), itemsVector.end(), cmp);
vector v; sort(v.begin(), v.end()); int value; for(auto it: itemsVector){ if(it.second==a)v.push_back(it.first); } for(auto s: v)cout<<s<<" "; return 0; }
