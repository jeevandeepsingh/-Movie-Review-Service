#include<bits/stdc++.h>
using namespace std;

class Release
{
    private :
    
    unordered_map<int,vector<string>> movie_release_year;

    public : 

    void set_release_year(int year,string movie)
    {
        movie_release_year[year].push_back(movie);
    }

    vector<string> get_movies_released_on_year(int year)
    {
        return movie_release_year[year];
    }
};