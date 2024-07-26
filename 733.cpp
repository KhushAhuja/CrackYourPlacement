class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size(), cols = image[0].size();
        int targetColor = image[sr][sc];
        if (targetColor == newColor) return image;

        stack<pair<int, int>> pixels;
        pixels.push(make_pair(sr, sc));
        while (!pixels.empty()) {
            auto curr = pixels.top();
            pixels.pop();
            int i = curr.first, j = curr.second;
            if (i < 0 || i >= rows || j < 0 || j >= cols || image[i][j] != targetColor) continue;
            image[i][j] = newColor;
            pixels.push(make_pair(i - 1, j));
            pixels.push(make_pair(i + 1, j));
            pixels.push(make_pair(i, j - 1));
            pixels.push(make_pair(i, j + 1));
        }

        return image;
    }
};