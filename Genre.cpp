#include<bits/stdc++.h>
using namespace std;

class Genre
{
    private :
    
    unordered_map<string,vector<string>> movie_genre;

    public : 

    void set_movie_genre(string genre,string movie)
    {
        movie_genre[genre].push_back(movie);
    }

    vector<string> get_movies_of_genre(string genre)
    {
        return movie_genre[genre];
    }
};  