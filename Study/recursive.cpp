#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int num_events;
    cin >> num_events;

    // Use an unordered_map to store team names and their goal counts
    unordered_map<string, int> team_goals;

    // Read team names and update goal counts
    for (int i = 0; i < num_events; ++i)
    {
        string team_name;
        cin >> team_name;
        team_goals[team_name]++;
    }

    // Find the team with the most goals (winner)
    string winner_team;
    int max_goals = 0;
    for (const auto &[team, goals] : team_goals)
    {
        if (goals > max_goals)
        {
            winner_team = team;
            max_goals = goals;
        }
    }

    cout << winner_team << endl;

    return 0;
}

// #include <stdio.h>

// int recurse(int n, int a, int b, int c)
// {
//     if (n <= 3)
//     {
//         return (n == 1) ? a : (n == 2) ? b : c;
//     }

//     int sum = a + b + c;
//     return recurse(n - 1, b, c, sum);
// }

// int main()
// {
//     int n, a, b, c;
//     scanf("%d", &n);
//     scanf("%d %d %d", &a, &b, &c);
//     int nthTerm = recurse(n, a, b, c);
//     printf("%d", nthTerm);

//     return 0;
// }
