/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1) return intervals;
        std::sort(intervals.begin(), intervals.end(), lessThan);
        std::vector<Interval> ret;
        ret.push_back(Interval(intervals[0].start, intervals[0].end));
        int tail = 0;
        for(int i = 1; i<intervals.size(); i++) {
            if(intervals[i].start <= ret[tail].end) {
                ret[tail].end = std::max<int>(intervals[i].end, ret[tail].end);
            } else {
                ret.push_back(Interval(intervals[i].start, intervals[i].end));
                tail++;
            }
        }
        return ret;
    }
    
private:
    static bool lessThan(Interval &a, Interval &b) {
        return a.start <= b.start;
    }
};
