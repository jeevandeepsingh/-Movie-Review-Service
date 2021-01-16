#include<bits/stdc++.h>
using namespace std;

class Person
{
    private :

    string name;
    int no_of_review;
    unordered_map<string,bool>  is_movie_reviewed;
    
    public :

    Person(string name)
    {
        this->name  = name;
        no_of_review = 0;
    }


    void movie_reviewed(string movie_name)
    {
        is_movie_reviewed[movie_name] = true;
        no_of_review++;
    }
    
    bool is_reviewed(string movie_name)
    {
        if(is_movie_reviewed[movie_name] == true)
        {
            return false;
        }
        return true;
    }
    
    bool is_critic()
    {
        if(no_of_review >= 3)       return true;
        else                        return false;    
    }

};