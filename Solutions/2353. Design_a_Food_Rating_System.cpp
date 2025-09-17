class FoodRatings {
public:
    unordered_map<string, int> rating_mp; // Maps food -> rating
    unordered_map<string, string> cuisine_mp; // Maps  food -> cuisine
    unordered_map<string, set<pair<int,string>>> cuisine_food_rating; //Maps Cuisine -> {rating, food}  
    //We have used <int,string> format as we want to sort the foods according to their ratings so that we get the highest
    //And also if two ratingg are the same the set will then sort according the to the string lexicographically smaller


    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;i++){
            string cuisine = cuisines[i];
            string food = foods[i];
            int rating = ratings[i];
            
            rating_mp[food] = rating;
            cuisine_mp[food] = cuisine;
            cuisine_food_rating[cuisine].insert({-rating, food}); //We are inserting -rating so that the highest rating is at the top as set normally sorts in ascending order. also if two ratings will become same then it will be sorted on basis of the string and the lexicographically smaller will be a the top, so we won't need to write another check for that so inserting -rating solves two problems


        }
    }
    
    void changeRating(string food, int newRating) {
    //First we need to find the cuisine the given food belongs as it will be used later to update the changed rating
        string cuisine = cuisine_mp[food];
    //Then we need to find the rating of the foood that will be changed as it'll be used to update the changed rating
        int oldRating = rating_mp[food];
    //Now we update newRating of the food in the rating_mp,so in future if it's again changes then it's easier to track
        rating_mp[food] = newRating;
    //Now We will first delete the oldrating of the food from the map with cuisines their food and ratings, so we can update it correctly if we didn't so the set will just add as new wnetry without delelting the older one
        cuisine_food_rating[cuisine].erase({-oldRating,food}); // Again we only insert negative values to be consistent thtough the code

        //Now we will update the new Rating
        cuisine_food_rating[cuisine].insert({-newRating,food});

    }
    
    string highestRated(string cuisine) {
        return begin(cuisine_food_rating[cuisine])->second;
        //The cuisine_food_rating[cuisine] returs a set of foods and ratings that belong to the given cuisine
        //Since rating were inserted as -rating so the highest is at the top of the set
        // hence we use begin , it points to the top of the stack
        //Since begin is a pointr and it points to the address of the value not the value itself so we use "->"
        // "->" will gices us the pair<int, string> at top of stack , we only need the food so we use second 
    }
};

/*

Explanation of the code flow (simple, step-by-step)

### What the class stores (why each is needed):

    rating_mp — food -> rating
    Why: when a food’s rating changes we must know its old rating quickly.

    cuisine_mp — food -> cuisine
    Why: when a food’s rating changes we must know which cuisine’s collection to update.

    cuisine_food_rating — cuisine -> set<pair<int,string>> storing {-rating, food}
    Why: for each cuisine we keep foods sorted so we can instantly get the top food. We store negative rating so the    highest rating becomes first in the set (because set sorts ascending). If ratings tie, set breaks ties by food name automatically (lexicographic).



###  Constructor (FoodRatings(...)) — what it does:
    For each index i:

        Read food = foods[i], cuisine = cuisines[i], rating = ratings[i].

        rating_mp[food] = rating; — remember the rating.

        cuisine_mp[food] = cuisine; — remember the cuisine.

        cuisine_food_rating[cuisine].insert({-rating, food}); — insert a pair so the cuisine’s set stays sorted (highest 
        rating at begin()).


### changeRating(food, newRating) — what it does:

        cuisine = cuisine_mp[food]; — find which cuisine to update.

        oldRating = rating_mp[food]; — find old rating.

        rating_mp[food] = newRating; — update stored rating.

        cuisine_food_rating[cuisine].erase({-oldRating, food}); — remove old pair from the cuisine’s set.

        cuisine_food_rating[cuisine].insert({-newRating, food}); — insert new pair so order is correct.


### highestRated(cuisine) — what it does:

        Return begin(cuisine_food_rating[cuisine])->second;
        begin(...) gives the first element in the set — which is the pair {-rating, food} with the highest rating 
         (because  we stored negative ratings). .second returns the food string.

 */



 /*
 
 1. Start
   You create FoodRatings with three lists: foods, cuisines, ratings.

2. Initialization (for each food):
   2.1 Store its rating:    rating_mp[food] = rating.
   2.2 Store its cuisine:    cuisine_mp[food] = cuisine.
   2.3 Insert into cuisine set:
       cuisine_food_rating[cuisine].insert({-rating, food})
       - We store -rating so the highest rating appears first in the set.
       - The set is therefore always sorted with the top food at begin().

3. When a rating changes (changeRating(food, newRating)):
   3.1 Find cuisine:        cuisine = cuisine_mp[food].
   3.2 Find old rating:     oldRating = rating_mp[food].
   3.3 Update stored rating:rating_mp[food] = newRating.
   3.4 Replace entry in the cuisine set:
       - Remove old pair:  cuisine_food_rating[cuisine].erase({-oldRating, food}).
       - Insert new pair:  cuisine_food_rating[cuisine].insert({-newRating, food}).

4. When asked for the best food of a cuisine (highestRated(cuisine)):
   - Return the food at the front of that cuisine’s set:
     begin(cuisine_food_rating[cuisine])->second

5. Important implementation detail (must remember)
   The erase call must match the exact pair you inserted earlier.
   If you use the wrong sign or wrong order (e.g. forgetting the minus),
   the old entry will not be removed and duplicates will remain (bug).
 
 
 
 */