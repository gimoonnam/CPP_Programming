
#include <iostream>
#include <array>

/************************** TESTS **************************/
/**   find the number of island from the 2D array below   **/

const std::array<std::array<int, 4>, 4> TEST1 = {{
    {1, 0, 0, 1},
    {0, 1, 0, 1},
    {0, 0, 1, 1},
    {1, 0, 1, 1},
}};

template <size_t width, size_t height>
bool isValid(std::array<std::array<int, width>,height> &grid, int i, int j)
{
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return false;
    return true;
}

template <size_t width, size_t height>
void dfs(std::array<std::array<int, width>,height> &grid, int i, int j)
{
    if(!isValid(grid, i, j))
        return;
    
    if(grid[i][j] == 1)
        {
        grid[i][j] = 0;
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        }
}



template <size_t width, size_t height>
int NumIslands(std::array<std::array<int, width>, height> map) {
    int ret = 0;
    
    if(map.size() == 0)
        return 0;
    for(int i = 0; i < map.size(); i++)
        {
        for(int j = 0; j < map[0].size(); j++)
            {
            if(map[i][j] == 1)
                {
                ret++;
                dfs(map, i, j);
                }
            }
        }
    return ret;
}





int main(int argc, const char * argv[]) {
    printf("Result for TEST1 should be 4, is %d\n", NumIslands(TEST1));
    return 0;
}


