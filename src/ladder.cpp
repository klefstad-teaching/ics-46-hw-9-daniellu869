#include "ladder.h"

void error(string word1, string word2, string msg){
    cout << word1 << ' ' << word2 << ' ' << msg << endl;
}
bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int m = str1.size();
    int n = str2.size();
    if (abs(m-n) > 1) return false;
    int dist = 0;
    if (m-n == 0) {
        for (int i = 0; i < m; ++i) {
            if (str1[i] != str2[i]) ++dist;
            if (dist > 1) return false;
        }
        return true;
    }
    else if (m-n > 0) {
        for (int i = 0; i < n; ++i) {
            if (str1[i + dist] != str2[i]) {
                ++dist;
                --i;
                if (dist > 1) return false;
            }
        }
        return dist < 2;
    }
    for (int i = 0; i < n; ++i){
        if (str1[i] != str2[i + dist]) {
            ++dist;
            --i;
            if (dist > 1) return false;
        }
    }
    return true;
}
bool is_adjacent(const string& word1, const string& word2){
    // cout << "called" << endl;
    return edit_distance_within(word1, word2, 1);
}
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});

    set<string> visited;

    visited.insert(begin_word);

    while (!ladder_queue.empty()){
        // cout << "in while" << endl;
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();

        for (string word: word_list){
            // cout << "in for loop" << endl;
            if (is_adjacent(last_word, word)){
                if (visited.find(word) == visited.end()){
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
    if (!ladder.size()) {
        cout << "No word ladder found" << endl;
        return;
    }
    cout << "Word ladder found: ";
    for (const string& word: ladder) cout << word << ' ';
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);

}