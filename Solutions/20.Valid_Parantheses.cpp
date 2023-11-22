class Solution {
public:
    stack<int> st;
    bool isValid(string s) {
        std::stack<char> st;

    for (char current : s) {
        if (current == '(' || current == '[' || current == '{') {
            // Opening parenthesis found, push onto the stack
            st.push(current);
        } else {
            // Closing parenthesis found
            if (st.empty()) {
                // No matching opening parenthesis found
                return false;
            }

            char matchingOpening = st.top();
            st.pop();

            if ((current == ')' && matchingOpening == '(') ||
                (current == ']' && matchingOpening == '[') ||
                (current == '}' && matchingOpening == '{')) {
                // Matching pair found, continue checking other characters
                continue;
            } else {
                // Mismatched parentheses found
                return false;
            }
        }
    }

    // Check if there are remaining opening parentheses
    return st.empty();
        
    }
};