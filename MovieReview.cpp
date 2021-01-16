#include<bits/stdc++.h>
using namespace std;

#include "Movie.cpp"
#include "Person.cpp"
#include "Genre.cpp"
#include "Release.cpp"
#include "Operation.cpp"


int main()
{
    
    Operation o;

    //Add Movies
    vector<string> d1{"Action","Comedy"};       o.AddMovie("Don",2006,d1);
    vector<string> d2{"Drama"};                 o.AddMovie("Tiger",2008,d2);
    vector<string> d3{"Comedy"};                o.AddMovie("Padmaavat",2006,d3);
    vector<string> d4{"Drama"};                 o.AddMovie("Lunchbox",2021,d4);
    vector<string> d5{"Drama"};                 o.AddMovie("Guru",2006,d5);
    vector<string> d6{"Romance"};               o.AddMovie("Metro",2006,d6);

    //Add Users
    o.AddUser("SRK");
    o.AddUser("Salman");
    o.AddUser("Deepika");

    //ADD Review
    o.AddReview("SRK", "Don", 2);
    o.AddReview("SRK", "Padmaavat", 8);
    o.AddReview("Salman", "Don", 5);
    o.AddReview("Deepika", "Don", 9);

    //Discover your treasures hidden within!
    o.AddReview("Deepika", "Guru", 6);
    o.AddReview("SRK", "Don", 10);
    o.AddReview("Deepika", "Lunchbox", 5);
    o.AddReview("Deepika", "Mass", 5);
    o.AddReview("SRK", "Tiger", 5);
    o.AddReview("SRK", "Metro", 7);

    cout << "\n-------------------------------------------------------------------------------------------------\n";
    
    //List top 1 movie by review score in “2006” year
    //a. Top in Year “2006”:
    o.Top_Movie_Of_Year(2006);
    
    cout << "\n-------------------------------------------------------------------------------------------------\n";
    //b. Top in Year “2006” by “critics_preferred”:
    o.Top_Movie_Of_Year_Critic_Preferred(2006);

    cout << "\n-------------------------------------------------------------------------------------------------\n";
    //List top 1 movie by review score in “Drama” genre
    o.Top_Movie_Genre_Preferred("Drama");

    cout << "\n-------------------------------------------------------------------------------------------------\n";
    //List top movie by average review score in “2006” year:
    o.Average_Review_Score_In_Year(2006);
    
    cout << "\n-------------------------------------------------------------------------------------------------\n";
    //List top n movies by total review score by ‘viewer’ in a particular year of release.
    o.Top_N_Movie_Of_Year_Viewer_Preferred(2006,2);

    cout << "\n-------------------------------------------------------------------------------------------------\n";
    //List top n movies by total review score by ‘viewer’ in a particular genre.
    o.Top_N_Movie_Of_Year_By_Viewer_Genre_Preferred(2006,"Drama",1);

    cout << "\n-------------------------------------------------------------------------------------------------\n";
    //List top n movies by total review score by ‘critics’ in a particular year of release.
    o.Top_N_Movie_Of_Year_Critic_Preferred(2006,1);

    cout << "\n-------------------------------------------------------------------------------------------------\n";
    //List top n movies by total review score by ‘critics’ in a particular genre.
    o.Top_N_Movie_Of_Year_By_Critic_Genre_Preferred(2006,"Romance",1);

    cout << "\n-------------------------------------------------------------------------------------------------\n";
    //Average review score in a particular genre.
    o.Average_Review_Score_In_Genre("Drama");

    cout << "\n-------------------------------------------------------------------------------------------------\n";
    //Average review score for a particular movie.
    o.Average_Review_Score_Of_Movie("Metro");

    return 0;
}