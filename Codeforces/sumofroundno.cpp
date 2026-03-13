#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int a;
        cin >> a;
            int power = 1;
            vector<int> ans;
            while (a != 0)
            {
                int last = a % 10;
                int num = last * power;
                power = power * 10;
                if (num != 0)
                {
                    ans.push_back(num);
                }
                a = a / 10;
            }

            cout << ans.size() << endl;
            for (int x : ans)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    

    return 0;
}