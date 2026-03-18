// Last updated: 3/18/2026, 3:02:05 PM
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;

        while (i < words.size()) {
            int len = words[i].size();
            int j = i + 1;

            while (j < words.size() && len + 1 + words[j].size() <= maxWidth) {
                len += 1 + words[j].size();
                j++;
            }

            int wordCount = j - i;
            int letters = 0;

            for (int k = i; k < j; k++)
                letters += words[k].size();

            string line = "";

            if (j == words.size() || wordCount == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) line += " ";
                }
                while (line.size() < maxWidth)
                    line += " ";
            }
            else {
                int spaces = maxWidth - letters;
                int gap = wordCount - 1;
                int each = spaces / gap;
                int extra = spaces % gap;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) {
                        int spaceCount = each;
                        if (extra > 0) {
                            spaceCount++;
                            extra--;
                        }
                        line += string(spaceCount, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }
        return result;
    }
};
