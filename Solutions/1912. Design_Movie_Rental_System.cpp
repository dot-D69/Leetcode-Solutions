class MovieRentingSystem {
public:
    typedef pair<int,int> P;
    unordered_map<int,set<P>> availmp; // movie -> {price,shop}
    unordered_map<int,set<P>> shopmp; //  movie ->{shop,price}
    set<tuple<int,int,int>> rentedMovies;// {price,shop,moviei}

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &entry: entries){
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            availmp[movie].insert({price,shop}); //Log(n)
            shopmp[movie].insert({shop,price}); //Log (n)
        }

    }
    
    vector<int> search(int movie) {
        vector<int> res;
        int count =0;
        if(availmp.count(movie)){  //O(1)
            for(auto &[price,shop]:availmp[movie]){ //O(5)
                res.push_back(shop);
                count++;
                if(count==5) break;
            }
        }
        return res;  
    }
    
    void rent(int shop, int movie) {
        auto it = shopmp[movie].lower_bound({shop,INT_MIN}); //Log (n)
        int price = it->second;
        
        availmp[movie].erase({price,shop}); //Log (n)

        rentedMovies.insert({price,shop,movie}); //Log (n)
    }
    
    void drop(int shop, int movie) {
        auto it = shopmp[movie].lower_bound({shop,INT_MIN});//Log (n)
        int price = it->second;

        availmp[movie].insert({price,shop});//Log (n)

        rentedMovies.erase({price,shop,movie});//Log (n)

    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count = 0;
        for(auto &[price,shop,movie]:rentedMovies){ //O(5)
            res.push_back({shop,movie});
            count++;
            if(count == 5) break;
        }
        return res;
    }
};


/**

What Data Strucutre to use?

Search(movie): Cheapest 5 shops having this movie as unrented , sorted by price first and if same price then    sorted by shop

    movie ->{(price1,shop1),{price 2 ,shop 2}}
    So we can use an unordered_map to map movies to thier price and shop
    The price and shop are stored together as pair , so we may use a pair
    and since we want them to be sorted ascending order, we may use an ordered Data Strucuture
    Like an ordered_set which wil sort them according to price first and shop second
    So we will use unordered_map<movie,set<pair<int,int>>> Avail


report () : Cheapest 5 rented movies sorted by price first -> then shop -> then movie

    So we need a data structure that can sotre these three price , shop and movie
    And store them in a sorted order acc to price then shop the movie
    To store the 3 values we can use a tuple : tuple<int,int,int>
    And Since we want them to be sorted as the first value first then the scond then the thirsd
    So we will use an: ordered_set set<tuple<int,int,int>> rentedMovies


rent(movie, shop): rent an unrednted copy of movie form the shop

    We already have a DS that stores movie and their associated prices and shop in a sorted order
     i.e Movie ->({price1,shop1},{price2,shop2}) This is our available map
     With this we can find the movie easily in o(1) time , but to find the shop for the movie we will have traverse the set , and in finding that it will cause a O(n) time, which will give TLE sinc the constraint is high

    Also once we have found our movide and shop we need to delete it form the available map ,since the movie from the shop willber rented and hence no longer available

    So to eliminate the O(n) searching time we need a DS that saves us: We will need a DS such that for a given movie we have the shop in an sorted order, so that we can find the shop using Binary Search in O(log n ) time

    So we may use a map such that movie ->set({shop,price})
    unordered_map<int,set<pair<int,int>> shopmp;

    now you may be womderiong why don't we just store shop when we just need to find that :
    That’s a problem because:
    To remove from avail[movie], you must erase {price, shop} — but you don’t know price.
    → You’d have to look up price in some other DS (like a separate map<pair<shop,movie>, price>).

    To insert into rentedMovies, you need (price, shop, movie) — again you need the price.

    So just storing shop makes rent() incomplete — you’ll still need another lookup every time.



------------------------------------------------------------------------------------------------

################# Implementation of each function ######################


Now for
### MovieRentingSystem(int n, vector<vector<int>>& entries)

    First we will parse the input vector and get [shop,movie,price]
    then we ca insert it into our Avail Map as
    avail[movie].insert({price,shop});

#### For Search(int movie):

    we have to return a vector , so we take a res vector (vector<int> res)
    We also have to maintain a count,since the max we can return is 5 shops (count =0)

    Now first we will checlk if the movie is available  (if(avail.count(moive)))
    If the movie is available then we need to find all the prices and shops it is availale in
    Like a movie maybe available at different shops for different or same price
    (for(auto &[price,shop]:avail[movie])) : This will return the price and shop of the movie in sorted order
    We insert the result into our res vector (res.push_back(shop)) [since we onl;y have to return shop]
    And we increse the count evertime a price and shop is found
    If the count ==5 , we break out of the loop




### For report():

    We need to return a vector so we malke a res vector (vector<int> res)
    Also we will need a counter ,as we have to return the top 5 movies ( so count =0)
    Now from the rendtedMovies set we need to get the price shop and movie , it will return in sorted order only
    for(auto &[price,shop,movie]:rentedMovies) : returns the price shop and movie
    in our res vecotr we will store the shop and the movie only since we have to return that only
    (res.puhs_back({shop,movie}));
    After every addition to the res we will increase our count (count++)
    If count >=5 (So we will break out of the loop since we only need to return atmost5 movies)





### For void rent(int shop, int movie):

    We need to find the movie in the given shop
    we will use our shopmp to find that
    Now if we do shopmp[movie]: this returns us a set of pair of shop and prices set({s1,p1},{s2,p2})

    To find the given shop we can use Binary Search, lower bound ( as it returns the first element greater than equal to the given element) and since it will return the first element that is greate than equal to shop : we will always get the  shop mentioned (as given iun qu4estion there is always a shop for the given movie)

    shopmp[movie].lower_bound(shop); //This won't work as the set is in pair so we need to apply Bs to the Pair only

    shopmp[movie].lower_bound({shop,INT_MIN}) : since we don't know the price ,so we will pass an INT_MIN as all prices will be greater than this , and since lower_obund only will find the greater than equal to so for shop it will fidn the shop>=given shop , and for price any price<=INT_MIN so a pair which mathces both is our answer since first shop willbe found and then price will ultimately be greater than INT_MIN;

    so auto it = shopmp[movie].lower_bound({shop,INT_MIN}) ; //This gives us and iterator

    Now we need to remove the movie from pour avail map , since it's been rented

    our avail map was like movie ->{price,shop}

    int  price = it->second;
    int shop = it->first;
    
    This gets us the price and shop that the movie is in ,Now we just need to remove it:

    avail[movie].erase({price,shop});



#### For void drop(int shop, int movie)

        We have to add this movie back to our avail map since after dropping , it again became available
        But to add to avail we need movie , price and shop (We dont have the price)
        We already made a map that maps movie to their shops and price (shopmp)

        To find the shop same as we did in the rent method we will do that only

        auto it = shopmp[movie].lower_bound({shop,INT_MIN}) ;
        int  price = it->second;

        We have our movie, our shop and our price , Now we just need to add it to the avail map

        avail[movie].insert({price,shop});

        Also we need to remove it from the rentedMovies DS since it won't be rented anyLonger
        rentedMovies.erase({price,shop,movie})

 */
