#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 1000010;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

int idx, flag;
vector<char> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '[') idx = 0;
        else if(s[i] == ']') idx = ans.size();
        else if(s[i] == '{') idx = max(0, idx - 1);
        else if(s[i] == '}') idx = min((int)ans.size(), idx + 1);
        else if(s[i] == '-') flag ^= 1;
        else if(s[i] == '=')
        {
            if(ans.size())
            {
                ans.erase(ans.begin() + idx - 1);
                --idx;
            }
        }
        else
        {
            if(idx == ans.size() - 1) ans.push_back(s[i]);
            else if(flag) ans[idx] = s[i];
            else ans.insert(ans.begin() + idx, s[i]);
            ++idx;
        }
    }
    for(auto x: ans) cout << x;
    return 0;
}