/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
 */

// @lc code=start
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int size = grid.size();
        int dp[size][size];
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if(i == 0 && j == 0)
                    continue;
                if(grid[i][j] == -1)
                    continue;
                if(i == 0 && grid[i][j-1] == -1)
                    grid[i][j] = -1;
                else if(j == 0 && grid[i-1][j] == -1)
                    grid[i][j] = -1;
                else if( j > 0 && i > 0 && grid[i][j-1] == -1 && grid[i-1][j] == -1)
                    grid[i][j] = -1;
            }
        }
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                dp[i][j] = grid[i][j];
        if(grid[size-1][size-1]== -1)
            return 0;
        vector<vector<pair<int,int>>> backward(size,  vector<pair<int,int>>(size, make_pair(0,0)));
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if(dp[i][j] == -1)
                    continue;
                if(i == 0 && j == 0)
                    continue;
                if(i == 0)
                {
                    backward[i][j].first = i;
                    backward[i][j].second = j - 1;
                    dp[i][j] = dp[i][j-1]+grid[i][j];

                }
                else if(j == 0)
                {
                    backward[i][j].first = i - 1;
                    backward[i][j].second = j;
                    dp[i][j] = dp[i-1][j]+grid[i][j];

                }
                else if( j > 0 && i > 0)
                {
                    if(dp[i-1][j] >= dp[i][j-1])
                    {
                        backward[i][j].first = i-1;
                        backward[i][j].second = j;
                        dp[i][j] = dp[i-1][j]+grid[i][j];
                    }
                    else
                    {
                        backward[i][j].first = i;
                        backward[i][j].second = j-1;
                        dp[i][j] = dp[i][j-1]+grid[i][j];
                    }
                }
            }
        }
        grid[size-1][size-1] = dp[size-1][size-1];
        int y = backward[size-1][size-1].first;
        int x = backward[size-1][size-1].second;
        for (int i = 0; i < size ;i++)
        {
            for(int j = 0; j < size;j++)
                cout<<backward[i][j].first<<","<<backward[i][j].second<<" ";
            cout<<endl;
        }
        while(!(y==0&&x==0))
        {
            cout<<y<<" "<<x<<endl;
            grid[y][x] = 0;
            y = backward[y][x].first;
            x = backward[y][x].second;

        }

        for (auto &x : grid)
        {
            for (auto &y : x)
                cout<<y<<" ";
            cout<<endl;
        }
        grid[0][0]=0;
        for (int i = size-1; i >= 0; i--)
        {
            for (int j = size-1; j >= 0; j--)
            {
                if(i == size-1 && j == size-1)
                    continue;
                if(grid[i][j] == -1)
                    continue;
                if(i ==size-1 && grid[i][j+1] == -1)
                    grid[i][j] = -1;
                else if(j == size-1 && grid[i+1][j] == -1)
                    grid[i][j] = -1;
                else if( j < size-1 && i < size-1 && grid[i][j+1] == -1 && grid[i+1][j] == -1)
                    grid[i][j] = -1;
            }
        }
        for (int i = size-1; i >= 0; i--)
        {
            for (int j = size-1; j >= 0; j--)
            {
                if(dp[i][j] == -1)
                    continue;
                if(i == size-1 && j == size-1)
                    continue;
                if(i == size-1)
                    dp[i][j] = dp[i][j+1]+grid[i][j];
                else if(j == size-1)
                    dp[i][j] = dp[i+1][j]+grid[i][j];
                else if( j <size-1 && i <size-1)
                {
                    if(dp[i+1][j] >= dp[i][j+1])
                        dp[i][j] = dp[i+1][j]+grid[i][j];
                    else
                        dp[i][j] = dp[i][j+1]+grid[i][j];
                }
            }
        }

        // for (auto &x : dp)
        // {
        //     for (auto &y : x)
        //         cout<<y<<" ";
        //     cout<<endl;
        // }

        return dp[0][0];

    }
};
// @lc code=end

