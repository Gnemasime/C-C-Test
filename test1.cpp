#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    vector<string> currentLine;
    int currentLength = 0;

    for (const string& word : words) {
        if (currentLength + word.length() + currentLine.size() > maxWidth) {
            int spaces = maxWidth - currentLength;
            int gaps = currentLine.size() - 1;
            if (gaps > 0) {
                int extraSpaces = spaces % gaps;
                int spacePerGap = spaces / gaps;

                string line;
                for (int i = 0; i < currentLine.size(); ++i) {
                    line += currentLine[i];
                    if (i < gaps) {
                        int currentGap = spacePerGap + (i < extraSpaces ? 1 : 0);
                        line.append(currentGap, ' ');
                    }
                }
                result.push_back(line);
            } else {
                string line = currentLine[0];
                line.append(spaces, ' ');
                result.push_back(line);
            }
            currentLine.clear();
            currentLength = 0;
        }
        currentLine.push_back(word);
        currentLength += word.length();
    }

    // Left justify the last line
    string lastLine;
    for (int i = 0; i < currentLine.size(); ++i) {
        lastLine += currentLine[i];
        if (i < currentLine.size() - 1) {
            lastLine += " ";
        }
    }
    lastLine.append(maxWidth - lastLine.length(), ' ');
    result.push_back(lastLine);

    return result;
}

int main() {
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 10;

    vector<string> result = fullJustify(words, maxWidth);

    for (const string& line : result) {
        cout << line << endl;
    }

    return 0;
}
