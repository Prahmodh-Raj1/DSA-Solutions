//Prob link: https://leetcode.com/problems/design-a-text-editor/submissions/
//TC: O(N) SC: O(N)
class TextEditor {
private:
    string before,after; //before is the main string and after is the temporary string for cursor movement functions
public:
    TextEditor() {
        
    }
    
    void addText(string text) {
        before.insert(end(before),begin(text),end(text));
    }
    
    int deleteText(int k) {
        k = min(k,(int)before.size());
        before.resize(before.size()-k);
        return k;
    }
    
    string cursorLeft(int k) {
        while(k-- && !before.empty()){
            after.push_back(before.back()); //after stores the last k characters from the back of before
            before.pop_back();
        }
        return before.substr(before.size() - min((int)before.size(),10));
    }
    
    string cursorRight(int k) {
        while(k-- && !after.empty()){
            before.push_back(after.back()); //while moving the cursor to the right, we need to use up the characters from after in the reverse order
            after.pop_back();
        }
        return before.substr(before.size() - min((int)before.size(),10));
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
