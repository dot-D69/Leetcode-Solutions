class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s); // stringstream  is an api that splits the string automatically
        vector<string> res;
        string store_word;

        while (ss >> store_word) // ss>>word is used to extract word from the stream into the String store_word
        {
            res.push_back(store_word); // push_back is used to add the word to the vector
        }

        reverse(res.begin(), res.end()); // reverse is used to reverse the vectori.e reverse the order of the words

        string Reversed;
        bool isFirstWord = true;
        for (auto w : res) // for each loop is used to iterate through the vector
            if (!isFirstWord)
            {
                Reversed += " "; // add space before adding the word to the Reversed string
            }
        Reversed += w; // append the word to the Reversed string
        isFirstWord = false;
    }

    return Reversed;
}
}
;

// The approach to the question is simple 
// 1. we first split the string
// 2. then reverse the order of the splitted string
// 3. then join the splitted string wiih a space in between them


/*
1. we first use stringstream (Syntax:stringstream  obj_name(string_name);
2. In this method, we will first create a stringstream object which will take the string and split it into words automatically.
3. To read those words we will create a variable word and we will read all the words till my stringstream object exhaust.
4. The while loop (ss>>word) iterates till the stringstream object is not exhausted. and the << operator is used to extract word from the stream into the String word.
5. Now we will push_back the word into the vector res.
6. Now we will reverse the vector res using reverse(res.begin(),res.end());

7.bool isFirstWord = true;: This line initializes a boolean variable to true. This variable is used as a flag to determine whether the current word being processed is the first word in the words vector.
8. Then we use for each loop to iterate through the vector.
9. It checks if the condition is true but since we set the flag to rue the conditon becomes false ans hence for the first word no space is added before appending it to the String
10. then we set the flag to false and henceforth for every word a space is added before appending it to the String
11. that is now after the first word before adding thee firstword it adds a space and then adds the word to the string
12. because we set the flag to flase so when we check the cindtion it becomes true and hence a space is added before adding the word to the string
*/