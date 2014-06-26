#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> CountandSay(const int n) {
    vector<string> res;
    if ( n <= 0 ) {
        return res;
    }
    res.emplace_back("1");
    for ( int i = 1; i < n; i ++ ) {
        string s;
        string orgs = res.back();
        int count = 1;
        for ( int j = 1; j < orgs.size(); j ++ ) {
            if ( orgs[j] != orgs[j-1] ) {
                s += to_string(count) + orgs[j-1];
                count = 1; 
            } else {
                count ++;
            }
        }
        s += to_string(count) + orgs[orgs.size()-1];    
        res.emplace_back(s);
    }
    return res;
}

int main() {
    vector<string> result = CountandSay(8);
    for ( auto &s : result ) {
        cout << s << endl;
    }
    return 0;
}

