class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food):w(width), h(height), food_index(0) {
        foods = food;
        q.push_back(make_pair(0,0));
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto head = q.front(), tail = q.back();
        q.pop_back();
        hist.erase(tail);
        int x = head.first, y = head.second;
        
        if (direction == "U") x--;
        else if (direction == "L") y--;
        else if (direction == "R") y++;
        else if (direction == "D") x++;
        
        if (x < 0 || x >= h || y < 0 || y >= w || hist.count(make_pair(x,y))) return -1;
        
        q.push_front(make_pair(x,y));
        hist.insert(make_pair(x,y));
        
        if (food_index >= foods.size()) return q.size()-1;
        
        if (x == foods[food_index].first && y == foods[food_index].second) {
            food_index++;
            q.push_back(tail);
            hist.insert(tail);
        }
        return q.size()-1;
    }

private:
    int w, h, food_index;
    vector<pair<int, int>> foods;
    deque<pair<int, int>> q;
    set<pair<int, int>> hist;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
