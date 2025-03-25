class Solution {
    #define pii pair<int,int>

    bool countLineIntersections(vector<pii>& coordinates){
        int lines = 0;
        int overlap = 0;
        for(int i=0;i<coordinates.size();++i){
            if(coordinates[i].second==0)    overlap--;
            else                            overlap++;
            if(overlap==0)
                lines++;
        }
        return lines>=3;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pii> y,x;
        for(auto& rectangle: rectangles){
            y.push_back(make_pair(rectangle[1],1));
            y.push_back(make_pair(rectangle[3],0));
            x.push_back(make_pair(rectangle[0],1));
            x.push_back(make_pair(rectangle[2],0));
        }
        sort(y.begin(),y.end());
        sort(x.begin(),x.end());

    
        return (countLineIntersections(y) or countLineIntersections(x));
    }
};