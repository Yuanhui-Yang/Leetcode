// 353. Design Snake Game
// https://leetcode.com/problems/design-snake-game/
#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
using namespace std;
class SnakeGame {
public:
	/** Initialize your data structure here.
	@param width - screen width
	@param height - screen height 
	@param food - A list of food positions
	E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
	SnakeGame(int width, int height, vector<pair<int, int>> food) {
		this->current = 0;
		this->width = width;
		this->height = height;
		this->food = food;
		this->snake.clear();
		this->snake.push_back(make_pair(0, 0));
	}

	/** Moves the snake.
	@param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
	@return The game's score after the move. Return -1 if game over. 
	Game over when snake crosses the screen boundary or bites its body. */
	int move(string direction) {
		int snake_length = this->snake.size();
		if (snake_length > this->width * this->height) return -1;
		const int food_size = food.size();
		pair<int, int> snake_head = this->snake.front();
		int snake_head_x = snake_head.first;
		int snake_head_y = snake_head.second;
		int new_snake_head_x = (direction == "U") ? snake_head_x - 1 : (direction == "D") ? snake_head_x + 1 : snake_head_x;
		int new_snake_head_y = (direction == "L") ? snake_head_y - 1 : (direction == "R") ? snake_head_y + 1 : snake_head_y;
		if (new_snake_head_x < 0 || new_snake_head_x >= this->height) return -1;
		if (new_snake_head_y < 0 || new_snake_head_y >= this->width) return -1;	
		pair<int, int> new_snake_head = make_pair(new_snake_head_x, new_snake_head_y);
		if (this->current < food_size && new_snake_head == food[this->current]) this->current++;
		else this->snake.pop_back();	
		if (find(begin(this->snake), end(this->snake), new_snake_head) != end(this->snake)) return -1;
		this->snake.push_front(new_snake_head);
		return this->current;
	}

private:
	int current;
	int width;
	int height;
	vector<pair<int, int>> food;
	list<pair<int, int>> snake;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */

int main(void) {
	vector<pair<int, int>> food;

	// food = {{1, 2}, {0, 1}};
	SnakeGame snakeGame(3, 2, food);
	// assert(0 == snakeGame.move("R"));
	// assert(0 == snakeGame.move("D"));
	// assert(1 == snakeGame.move("R"));
	// assert(1 == snakeGame.move("U"));
	// assert(2 == snakeGame.move("L"));
	// assert(-1 == snakeGame.move("U"));

	food = {{1, 1}, {1, 0}, {0, 0}};
	snakeGame = SnakeGame(2, 2, food);
	assert(0 == snakeGame.move("R"));
	assert(1 == snakeGame.move("D"));
	assert(2 == snakeGame.move("L"));
	assert(3 == snakeGame.move("U"));
	assert(3 == snakeGame.move("R"));
	assert(3 == snakeGame.move("D"));
	assert(3 == snakeGame.move("L"));
	assert(-1 == snakeGame.move("L"));

	cout << "\nPassed All\n";
	return 0;
}