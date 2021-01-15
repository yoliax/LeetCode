//给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
//
//注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
//
//
//示例 1：
//
//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"
//示例 2：
//
//输入：s = "a", t = "a"
//输出："a"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string minWindow(string s, string t) {
    vector<int> chars(128, 0);
    vector<bool> flag(128, false);
    for (int i = 0; i < t.size(); i++) {
        flag[t[i]] = true;
        ++chars[t[i]];
    }
    int cnt = 0, l = 0, min_l = 0, min_size = s.size() + 1;
    for (int r = 0; r < s.size(); r++) {
        if (flag[s[r]]) {
            if (--chars[s[r]] >= 0) {
                ++cnt;
            }
            while (cnt == t.size()) {
                if (r - l + 1 < min_size) {
                    min_l = l;
                    min_size = r - l + 1;
                }
                if (flag[s[l]] && ++chars[s[l]] > 0) {
                    --cnt;
                }
                ++l;
            }
        }
    }
    return min_size > s.size() ? "" : s.substr(min_l, min_size);
}

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string res = minWindow(s, t);
    cout << res << endl;

}