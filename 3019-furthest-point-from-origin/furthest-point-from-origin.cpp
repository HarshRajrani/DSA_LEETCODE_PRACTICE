class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {

        int n = moves.size();

        int countR = 0;
        int countL = 0;
        int t = 0;

        for (int i = 0; i < n; i++) {
            if (moves[i] == 'L')
                countL++;
            else if (moves[i] == 'R')
                countR++;
            else
                t++;
        }

        return countL >= countR ? abs(countL + t - countR)
                                : countR + t - countL;
    }
};