class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(), deck.end());
    
    queue<int> reveal_order;
    for (int i = 0; i < deck.size(); ++i) {
        reveal_order.push(i);
    }
    
    vector<int> result(deck.size());
    
    for (int card : deck) {
        result[reveal_order.front()] = card;
        reveal_order.pop();
        if (!reveal_order.empty()) {
            reveal_order.push(reveal_order.front());
            reveal_order.pop();
        }
    }
    
    return result;
    }
};