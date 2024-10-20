#include <bits/stdc++.h>
using namespace std;
struct student
{
    string firstname, lastname;
    double gpa;
    bool operator < (student s)
    {
        if (gpa != s.gpa) return gpa < s.gpa;
        if (lastname != s.lastname) return lastname < s.lastname;
        return firstname < s.firstname;
    }
} S[100500];

double get_grade(string g)
{
    if (g == "A+") return 4;
    if (g == "A") return 3.75;
    if (g == "B+") return 3.5;
    if (g == "B") return 3;
    if (g == "C+") return 2.5;
    if (g == "C") return 2;
    if (g == "D+") return 1.5;
    if (g == "D") return 1;
    return 0;

}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> S[i].lastname >> S[i].firstname;
        int m;
        cin >> m;
        double total = 0;
        int sum = 0;
        for (int j = 1; j <= m; j++)
        {
            string g;
            int c;
            cin >> g >> c;
            total += c * get_grade(g);
            sum += c;
        }
        S[i].gpa = total / sum;
    }
    sort(S + 1, S + n + 1);

    cout << setprecision(3) << fixed;
    for (int i = 1; i <= n; i++)
    {
        cout << S[i].lastname << " " << S[i].firstname << " " << S[i].gpa << endl;
    }
}
