
//Insert Interval

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval a, Interval b) {
	return a.start < b.start;
}

//这一题跟merge intervals那题很像，将新插入newInterval的intervals数组排序以后，在合并结果时，这两题
//都采用了相同的方法，挨个合并
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	int length = intervals.size();
	vector<Interval> result;
	if(length <= 0) {
		result.push_back(newInterval);
		return result;
	}
	intervals.push_back(newInterval);
	sort(intervals.begin(), intervals.end(), cmp);
	result.push_back(intervals[0]);
	for(int i = 1; i < intervals.size(); i++) {
		int index = result.size();
		if(result[index - 1].end < intervals[i].start) {
			result.push_back(intervals[i]);
		} else if(result[index - 1].end >= intervals[i].start && result[index - 1].end < intervals[i].end) {
			result[index - 1].end = intervals[i].end;
		} else {
			//
		}
	}
	return result;
}

void printInterval(vector<Interval>& intervals) {
	int length = intervals.size();
	for(int i = 0; i < length; i++) {
		cout<<intervals[i].start<<" "<<intervals[i].end<<endl;
	}
}

int main() {
	vector<Interval> intervals;
	intervals.push_back(*(new Interval(1, 2)));
	intervals.push_back(*(new Interval(3, 5)));
	intervals.push_back(*(new Interval(6, 7)));
	intervals.push_back(*(new Interval(8, 10)));
	intervals.push_back(*(new Interval(12, 16)));
	// intervals.push_back(*(new Interval(2, 6)));
	// intervals.push_back(*(new Interval(15, 18)));
	vector<Interval> result = insert(intervals, *(new Interval(4, 9)));
	printInterval(result);
	return 0;
}