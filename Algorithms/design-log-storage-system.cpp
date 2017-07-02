// 635. Design Log Storage System
// https://leetcode.com/problems/design-log-storage-system/

/*
You are given several logs that each log contains a unique id and timestamp. Timestamp is a string that has the following format: Year:Month:Day:Hour:Minute:Second, for example, 2017:01:01:23:59:59. All domains are zero-padded decimal numbers.

Design a log storage system to implement the following functions:

void Put(int id, string timestamp): Given a log's unique id and timestamp, store the log in your storage system.


int[] Retrieve(String start, String end, String granularity): Return the id of logs whose timestamps are within the range from start to end. Start and end all have the same format as timestamp. However, granularity means the time level for consideration. For example, start = "2017:01:01:23:59:59", end = "2017:01:02:23:59:59", granularity = "Day", it means that we need to find the logs within the range from Jan. 1st 2017 to Jan. 2nd 2017.

Example 1:
put(1, "2017:01:01:23:59:59");
put(2, "2017:01:01:22:59:59");
put(3, "2016:01:01:00:00:00");
retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year"); // return [1,2,3], because you need to return all logs within 2016 and 2017.
retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour"); // return [1,2], because you need to return all logs start from 2016:01:01:01 to 2017:01:01:23, where log 3 is left outside the range.
Note:
There will be at most 300 operations of Put or Retrieve.
Year ranges from [2000,2017]. Hour ranges from [00,23].
Output for Retrieve has no order required.
*/

class LogSystem {
public:
	LogSystem() {
		h.clear();
	}

	void put(int id, string timestamp) {
		h[timestamp] = id;
	}

	vector<int> retrieve(string s, string e, string gra) {
		vector<int> result;
		for (const auto & i : h) {
			if (f(s, i.first, gra) and f(i.first, e, gra)) {
				result.push_back(i.second);
			}
		}
		return result;
	}
private:
	unordered_map<string, int> h;
	bool f(string t1, string t2, string gra) {
		array<string, 6> tm1, tm2;
		tm1[0] = t1.substr(0, 4);
		tm1[1] = t1.substr(5, 2);
		tm1[2] = t1.substr(8, 2);
		tm1[3] = t1.substr(11, 2);
		tm1[4] = t1.substr(14, 2);
		tm1[5] = t1.substr(17, 2);
		tm2[0] = t2.substr(0, 4);
		tm2[1] = t2.substr(5, 2);
		tm2[2] = t2.substr(8, 2);
		tm2[3] = t2.substr(11, 2);
		tm2[4] = t2.substr(14, 2);
		tm2[5] = t2.substr(17, 2);
		if (gra == "Year") {
			return tm1[0] <= tm2[0];
		}
		if (gra == "Month") {
			return tm1[0] < tm2[0] or (tm1[0] == tm2[0] and tm1[1] <= tm2[1]);
		}
		if (gra == "Day") {
			return tm1[0] < tm2[0] or (tm1[0] == tm2[0] and tm1[1] < tm2[1]) or (tm1[0] == tm2[0] and tm1[1] == tm2[1] and tm1[2] <= tm2[2]);
		}
		if (gra == "Hour") {
			return tm1[0] < tm2[0] or (tm1[0] == tm2[0] and tm1[1] < tm2[1]) or (tm1[0] == tm2[0] and tm1[1] == tm2[1] and tm1[2] < tm2[2]) or (tm1[0] == tm2[0] and tm1[1] == tm2[1] and tm1[2] == tm2[2] and tm1[3] <= tm2[3]);
		}
		if (gra == "Minute") {
			return tm1[0] < tm2[0] or (tm1[0] == tm2[0] and tm1[1] < tm2[1]) or (tm1[0] == tm2[0] and tm1[1] == tm2[1] and tm1[2] < tm2[2]) or (tm1[0] == tm2[0] and tm1[1] == tm2[1] and tm1[2] == tm2[2] and tm1[3] < tm2[3]) or (tm1[0] == tm2[0] and tm1[1] == tm2[1] and tm1[2] == tm2[2] and tm1[3] == tm2[3] and tm1[4] <= tm2[4]);
		}
		if (gra == "Second") {
			return tm1[0] < tm2[0] or (tm1[0] == tm2[0] and tm1[1] < tm2[1]) or (tm1[0] == tm2[0] and tm1[1] == tm2[1] and tm1[2] < tm2[2]) or (tm1[0] == tm2[0] and tm1[1] == tm2[1] and tm1[2] == tm2[2] and tm1[3] < tm2[3]) or (tm1[0] == tm2[0] and tm1[1] == tm2[1] and tm1[2] == tm2[2] and tm1[3] == tm2[3] and tm1[4] < tm2[4]) or (tm1[0] == tm2[0] and tm1[1] == tm2[1] and tm1[2] == tm2[2] and tm1[3] == tm2[3] and tm1[4] == tm2[4] and tm1[5] <= tm2[5]);
		}
		return true;
	}
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */