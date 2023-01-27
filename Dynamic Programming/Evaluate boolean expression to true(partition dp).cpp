//TC:O(N^3) SC:O(N^2)

#define mod 1000000007
vector<vector<vector<long long int >>> memo;

int findWays(string &exp, int i, int j, int isTrue) {
    
    // Corner Cases.
    if (i > j) {
        return 0;
    }

    // If the length of expression is 1, we need to evaluate its value.
    if (i == j) {
        if (isTrue) {
            return exp[i] == 'T' ? 1 : 0;
        } else {
            return exp[i] == 'F' ? 1 : 0;
        }
    }

    if (memo[i][j][isTrue] != -1) {
        return memo[i][j][isTrue];
    }

    long long int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2) {
        if (memo[i][k - 1][1] == -1) {
            memo[i][k - 1][1] = (findWays(exp, i, k - 1, 1)) % mod;
        }

        if (memo[i][k - 1][0] == -1) {
            memo[i][k - 1][0] = (findWays(exp, i, k - 1, 0)) %  mod;
        }

        if (memo[k + 1][j][1] == -1) {
            memo[k + 1][j][1] = (findWays(exp, k + 1, j, 1)) % mod;
        }

        if (memo[k + 1][j][0] == -1) {
            memo[k + 1][j][0] = (findWays(exp, k + 1, j, 0)) % mod;
        }

        // The number of ways expression left to 'K' will be true.
        long long int leftTrue = memo[i][k - 1][1];

        // The number of ways expression left to 'K' will be false.
        long long int leftFalse = memo[i][k - 1][0];

        // The number of ways expression right to 'K' will be true.
        long long int rightTrue = memo[k + 1][j][1];

        // The number of ways expression right to 'K' will be false.
        long long int rightFalse = memo[k + 1][j][0];

        if (exp[k] == '|') {
            // T | T = T, T | F = T, F | T = T, F | F = F. 
            if (isTrue) {
                ans += leftTrue * rightTrue + leftTrue *     

                rightFalse + leftFalse * rightTrue;
                ans = ans % mod;
            } else {
                ans += leftFalse * rightFalse;
                ans = ans % mod;
            }
        } 
        else if (exp[k] == '&') {
            // T & T = T, T & F = F, F & T = F, F | F = F.
            if (isTrue) {
                ans += leftTrue * rightTrue;
                ans = ans % mod;

            } else {
                ans += leftTrue * rightFalse + leftFalse *

                rightTrue + leftFalse * rightFalse;
                ans = ans % mod;
            }
        } 
        else {
            // T ^ T = F, T ^ F = T, F ^ T = T, F ^ F = F.
            if (isTrue) {
                ans += leftTrue * rightFalse + leftFalse * rightTrue;
                ans = ans % mod;
            } else {
                ans += leftTrue * rightTrue + leftFalse * rightFalse;
                ans = ans % mod;
            }
        }
    }
    
    return memo[i][j][isTrue] = ans;
}

int evaluateExp(string &exp) {
    int n = exp.length();
    memo = vector<vector<vector<long long int>>> (n, vector<vector<long long int>>(n, vector<long long int>(2, -1)));
    
    // We need to evaluate the whole expression for true.
    return findWays(exp, 0, n - 1, 1);
}
int evaluate(string& s){
   vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));

    for (int i = 0; i < n; i++)
    {
        dp[i][i][true] = s[i] == 'T';
        dp[i][i][false] = s[i] == 'F';
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++) // since i<j & i==j are base cases.
        {
            for (int isTrue = 0; isTrue < 2; isTrue++)
            {
                ll ways = 0;

                for (int k = i + 1; k < j; k = k + 2)
                {

                    ll LT, LF, RT, RF;

                    LT = dp[i][k - 1][true];
                    LF = dp[i][k - 1][false];
                    RT = dp[k + 1][j][true];
                    RF = dp[k + 1][j][false];

                    if (s[k] == '^')
                    {
                        if (isTrue)
                        {
                            ways = (ways + (LT * RF) % mod + (LF * RT) % mod) % mod;
                        }

                        else
                        {
                            ways = (ways + (LT * RT) % mod + (LF * RF) % mod) % mod;
                        }
                    }
                    else if (s[k] == '&')
                    {
                        if (isTrue)
                        {
                            ways = (ways + (LT * RT) % mod) % mod;
                        }
                        else
                        {
                            ways = (ways + (LT * RF) % mod + (LF * RT) % mod + (LF * RF) % mod) % mod;
                        }
                    }
                    else if (s[k] == '|')
                    {
                        if (isTrue)
                        {
                            ways = (ways + (LT * RT) % mod + (LT * RF) % mod + (LF * RT) % mod) % mod;
                        }
                        else
                        {
                            ways = (ways + (LF * RF) % mod) % mod;
                        }
                    }
                }

                dp[i][j][isTrue] = ways;
            }
        }
    }

    return dp[0][n - 1][true];
}
