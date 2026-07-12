class Solution {
public:
    int convert(string &t){
        int hr = stoi(t.substr(0,2));
        int mn = stoi(t.substr(3,2));
        int sc = stoi(t.substr(6,2));
        return hr * 3600 + mn * 60 + sc ; 
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        return convert(endTime) - convert(startTime);
    }
};