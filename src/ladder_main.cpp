#include "ladder.h"

using namespace std;
#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder_main() {
    set<string> word_list;

    load_words(word_list, "./src/words.txt");
    my_assert(is_adjacent("cat", "cot"));
    my_assert(!is_adjacent("bag", "dog"));

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    // auto ladder = generate_word_ladder("cat", "dog", word_list);
    // for (string& word: ladder) cout << word << " ";
    // cout << "passed" << endl;
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);

    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);

    auto ladder = generate_word_ladder("work", "play", word_list);
    for (string& word: ladder) cout << word << " ";

    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);

    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);

}

int main(){
    verify_word_ladder_main();
    return 0;
}