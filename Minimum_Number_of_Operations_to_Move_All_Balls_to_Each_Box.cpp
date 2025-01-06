class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> box(boxes.size());
        for(int i = 0; i<boxes.size(); i++){
            box[i] = boxes[i] - '0';
        }
        vector<int> answer(boxes.size());
        for(int i =0; i<boxes.size(); i++){
            int count = 0;
            for(int j = 0; j<boxes.size(); j++){
                if(box[j] == 1){
                    count+= abs(j - i);
                }
            }
            answer[i] = count;
        }

        return answer;
    }
};