// 359. Logger Rate Limiter
// https://leetcode.com/problems/logger-rate-limiter/

/*
Design a logger system that receive stream of messages along with its timestamps, each message should be printed if and only if it is not printed in the last 10 seconds.

Given a message and a timestamp (in seconds granularity), return true if the message should be printed in the given timestamp, otherwise returns false.

It is possible that several messages arrive roughly at the same time.

Example:

Logger logger = new Logger();

// logging string "foo" at timestamp 1
logger.shouldPrintMessage(1, "foo"); returns true; 

// logging string "bar" at timestamp 2
logger.shouldPrintMessage(2,"bar"); returns true;

// logging string "foo" at timestamp 3
logger.shouldPrintMessage(3,"foo"); returns false;

// logging string "bar" at timestamp 8
logger.shouldPrintMessage(8,"bar"); returns false;

// logging string "foo" at timestamp 10
logger.shouldPrintMessage(10,"foo"); returns false;

// logging string "foo" at timestamp 11
logger.shouldPrintMessage(11,"foo"); returns true;
*/

#include <bits/stdc++.h>
using namespace std;

class Logger {
public:
	/** Initialize your data structure here. */
	Logger() {
		this->h.clear();
	}

	/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
	If this method returns false, the message will not be printed.
	The timestamp is in seconds granularity. */
	bool shouldPrintMessage(int timestamp, string message) {
		if (!h.count(message) or h[message] + 10 <= timestamp) {
			h[message] = timestamp;
			return true;
		}
		return false;
	}
private:
	unordered_map<string, int> h;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */

int main(void) {
	Logger logger;
	bool answer, result;

	result = logger.shouldPrintMessage(1, "foo");
	answer = true;
	assert(answer == result);

	result = logger.shouldPrintMessage(2, "bar");
	answer = true;
	assert(answer == result);

	result = logger.shouldPrintMessage(3, "foo");
	answer = false;
	assert(answer == result);

	result = logger.shouldPrintMessage(8, "bar");
	answer = false;
	assert(answer == result);

	result = logger.shouldPrintMessage(10, "foo");
	answer = false;
	assert(answer == result);

	result = logger.shouldPrintMessage(11, "foo");
	answer = true;
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}