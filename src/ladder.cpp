#include "ladder.h"

void error(string word1, string word2, string msg){
    cout << word1 << ' ' << word2 << ' ' << msg << endl;
}
bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dist(m, vector(n, 0));
 
    for (int i = 0; i < m; ++i) dist[i][0] = i;
 
    for (int i = 0; i < n; ++i) dist[0][i] = i;

    for (int j = 0; j < n; ++j){
        for (int i = 0; i < m; ++i){
            int substitutionCost = 1;
            if (str1[i] == str2[j]) int substitutionCost = 0;
        
            dist[i][j] = min(min(dist[i-1][j] + 1,                   // deletion
                                dist[i][j-1] + 1),                 // insertion
                                dist[i-1][j-1] + substitutionCost); // substitution
        }
    }
    return dist[m][n] <= d;
}
bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});

    set<string> visited;

    visited.insert(begin_word);

    while (!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();

        for (string word: word_list){
            if (is_adjacent(last_word, word)){
                if (visited.find(word) != visited.end()){
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);

                    if (word == end_word) return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }

    return {};
}
void load_words(set<string> & word_list, const string& file_name){
    fstream cin(file_name);
    string word;
    while (cin >> word){
        word_list.insert(word);
    }
}
void print_word_ladder(const vector<string>& ladder){
    for (const string& word: ladder) cout << word << endl;
}
