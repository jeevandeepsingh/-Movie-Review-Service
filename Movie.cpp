#include<bits/stdc++.h>
using namespace std;

class Movie
{
    private :

    string movie_name;
    int no_of_viewer_review;
    int no_of_critic_review;
    int value_of_viewer_review;
    int value_of_critic_review;
    int year;
    vector<string> genres;
    
    public : 

    Movie(string movie_name,int year,vector<string>& genres)
    {
        this->movie_name = movie_name;
        this->year = year;
        this->genres = genres;
        no_of_viewer_review = no_of_critic_review = value_of_critic_review = value_of_viewer_review = 0;
    }

    void set_viewer_review_value(int value)
    {
        value_of_viewer_review += value;
        no_of_viewer_review++;
    }

    void set_critic_review_value(int value)
    {
        value_of_critic_review += (2*value);
        no_of_critic_review ++;
    }

    int get_no_viewer_review()
    {
        return    no_of_viewer_review;
    }

    int get_no_critic_review()
    {
        return    no_of_critic_review;
    }

    int get_viewer_review_value()
    {
        return    value_of_viewer_review;
    }

    int get_critic_review_value()
    {
        return    value_of_critic_review;
    }

};