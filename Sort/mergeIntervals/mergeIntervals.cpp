
//Merge Intervals

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

//先将输入的Interval按照start元素进行排序，然后依次将元素放入result向量
//总共分为三种情况，第一种：result[result.size() - 1].end比intervals[i].start小，则将intervals[i]放入result
//第二种：result[result.size() - 1].end比intervals[i].start大，result[result.size() - 1].end比intervals[i].end小，则更新result[result.size() - 1].end为intervals[i].end
//第三种：result[result.size() - 1].end比intervals[i].end大，则舍弃掉这个Interval元素，接着向下进行遍历
vector<Interval> merge(vector<Interval>& intervals) {
	int length = intervals.size();
	vector<Interval> result;
	if(length <= 0)
		return result;
	sort(intervals.begin(), intervals.end(), cmp);
	result.push_back(intervals[0]);
	for(int i = 1; i < length; i++) {
		int tmp = result.size();
		if(result[tmp - 1].end < intervals[i].start) {
			result.push_back(intervals[i]);
		} else if(result[tmp - 1].end >= intervals[i].start && result[tmp - 1].end < intervals[i].end) {
			result[tmp - 1].end = intervals[i].end;
		} else {
			//do nothing
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
	intervals.push_back(*(new Interval(1, 3)));
	intervals.push_back(*(new Interval(8, 10)));
	intervals.push_back(*(new Interval(2, 6)));
	intervals.push_back(*(new Interval(15, 18)));
	vector<Interval> result = merge(intervals);
	printInterval(result);
	return 0;
}

