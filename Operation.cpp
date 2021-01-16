#include<bits/stdc++.h>
using namespace std;


class Operation
{
    private :

    Genre g;
    Release r;
    unordered_map<string,bool> is_valid_movie;
    unordered_map<string,Movie*> Movies;
    unordered_map<string,Person*> Users;

    public : 

    void AddMovie(string movie_name,int year,vector<string> &genres)
    {
        Movie* m = new Movie(movie_name,year,genres);
        
        is_valid_movie[movie_name] = true;
        Movies[movie_name] = m;
        r.set_release_year(year,movie_name);

        for(auto i : genres)
        {
            g.set_movie_genre(i,movie_name);
        }
    }

    void AddUser(string name)
    {
        Person* p = new Person(name);
        Users[name] = p;
    }

    void AddReview(string name, string movie_name, int rating)
    {
        if(is_valid_movie[movie_name] == false)                   cout << movie_name <<" - Exception movie yet to be released\n" ;
        else if(Users[name]->is_reviewed(movie_name) == false)    cout << movie_name <<" - Exception multiple reviews not allowed\n";
        else
        {
            if(Users[name]->is_critic())
            {
                Movies[movie_name]->set_critic_review_value(rating);    
            }
            else
            {
                Movies[movie_name]->set_viewer_review_value(rating);
            }

            Users[name]->movie_reviewed(movie_name);
        }
    }

    void Top_Movie_Of_Year(int year)
    {
        vector<string> movies = r.get_movies_released_on_year(year);

        pair<int,string> pl;
        pl.first = 0,pl.second = "";

        for(auto i : movies)
        {
            int val = Movies[i]->get_critic_review_value() + Movies[i]->get_viewer_review_value();
            if(val > pl.first)
            {
                pl.first = val;
                pl.second = i;
            }
        }

        if(pl.first == 0)
        {
            cout << "No Movie Release in this year\n";
        }
        else
        {
            cout << pl.second << " - " << pl.first << " Ratings\n";
        }
    }

    void Top_Movie_Of_Year_Critic_Preferred(int year)
    {
        vector<string> movies = r.get_movies_released_on_year(year);

        pair<int,string> pl;
        pl.first = 0,pl.second = "";

        for(auto i : movies)
        {
            int val = Movies[i]->get_critic_review_value();
            if(val > pl.first)
            {
                pl.first = val;
                pl.second = i;
            }
        }

        if(pl.first == 0)
        {
            cout << "No Movie Release in this year critic Preferred\n";
        }
        else
        {
            cout << pl.second << " - " << pl.first << " Ratings\n";
        }
    }

    void Top_Movie_Genre_Preferred(string genre)
    {

        pair<int,string> pl;
        pl.first = 0,pl.second = "";

        for(auto i : g.get_movies_of_genre(genre))
        {
            int val = Movies[i]->get_critic_review_value() + Movies[i]->get_viewer_review_value();
            if(val > pl.first)
            {
                pl.first = val;
                pl.second = i;
            }
        }

        if(pl.first == 0)
        {
            cout << "No Movie Release in this year\n";
        }
        else
        {
            cout << pl.second << " - " << pl.first << " Ratings\n";
        }
    }

    void Average_Review_Score_In_Year(int year)
    {
        vector<string> movies = r.get_movies_released_on_year(year);

        double p1,p2;
        for(auto i : movies)
        {
            p1 += Movies[i]->get_critic_review_value() + Movies[i]->get_viewer_review_value();
            p2 += Movies[i]->get_no_critic_review() + Movies[i]->get_no_viewer_review();
        }

        double val = double((p1*1.0)/p2);

        cout << val << " Ratings\n";
    }

    void Top_N_Movie_Of_Year_Viewer_Preferred(int year,int N)
    {
        vector<string> movies = r.get_movies_released_on_year(year);
        priority_queue<pair<int,string>> pq;

        for(auto i : movies)
        {
            int val = Movies[i]->get_viewer_review_value();
            if(val > 0)     pq.push(make_pair(val,i));
        }

        if(pq.empty())
        {
            cout << "No Movie Release in this year\n";
        }
        else
        {
            while(N--)
            {
                cout << pq.top().second << " " << pq.top().first << " Rating\n";
                pq.pop();
            }
        }
    }

    void Top_N_Movie_Of_Year_By_Viewer_Genre_Preferred(int year, string genre, int N)
    {
        vector<string> movies1 = r.get_movies_released_on_year(year);
        vector<string> movies;

        unordered_map<string,bool> find;
        for(auto i : movies1)
        {
            find[i] = true;
        }

        vector<string> movies2 = g.get_movies_of_genre(genre);
        for(auto i : movies2)
        {
            if(find[i] == true)
            {
                movies.push_back(i);
            }
        }
        

        priority_queue<pair<int,string>> pq;

        for(auto i : movies)
        {
            int val = Movies[i]->get_viewer_review_value();
            if(val > 0)     pq.push(make_pair(val,i));
        }

        if(pq.empty())
        {
            cout << "No Movie Release in this year\n";
        }
        else
        {
            while(N--)
            {
                cout << pq.top().second << " " << pq.top().first << " Rating\n";
                pq.pop();
            }
        }   
    }

    void Top_N_Movie_Of_Year_Critic_Preferred(int year, int N)
    {
        vector<string> movies = r.get_movies_released_on_year(year);
        priority_queue<pair<int,string>> pq;

        for(auto i : movies)
        {
            int val = Movies[i]->get_critic_review_value();
            if(val > 0)     pq.push(make_pair(val,i));
        }

        if(pq.empty())
        {
            cout << "No Movie Release in this year\n";
        }
        else
        {
            while(N--)
            {
                cout << pq.top().second << " " << pq.top().first << " Rating\n";
                pq.pop();
            }
        }   
    }

    void Top_N_Movie_Of_Year_By_Critic_Genre_Preferred(int year, string genre, int N)
    {
        vector<string> movies1 = r.get_movies_released_on_year(year);
        vector<string> movies;

        unordered_map<string,bool> find;
        for(auto i : movies1)
        {
            find[i] = true;
        }

        vector<string> movies2 = g.get_movies_of_genre(genre);
        for(auto i : movies2)
        {
            if(find[i] == true)
            {
                movies.push_back(i);
            }
        }
        

        priority_queue<pair<int,string>> pq;

        for(auto i : movies)
        {
            int val = Movies[i]->get_critic_review_value();
            if(val > 0)    pq.push(make_pair(val,i));
        }

        if(pq.empty())
        {
            cout << "No Movie Release in this year\n";
        }
        else
        {
            while(N--)
            {
                cout << pq.top().second << " " << pq.top().first << " Rating\n";
                pq.pop();
            }
        }   
    }

    void Average_Review_Score_In_Genre(string genre)
    {
        vector<string> movies = g.get_movies_of_genre(genre);

        double p1,p2;
        for(auto i : movies)
        {
            p1 += Movies[i]->get_critic_review_value() + Movies[i]->get_viewer_review_value();
            p2 += Movies[i]->get_no_critic_review() + Movies[i]->get_no_viewer_review();
        }

        double val = double((p1*1.0)/p2);

        cout << val << " Ratings\n";
    }

    void Average_Review_Score_Of_Movie(string movie)
    {
        double p1,p2;
        p1 = Movies[movie]->get_critic_review_value() + Movies[movie]->get_viewer_review_value();
        p2 = Movies[movie]->get_no_critic_review() + Movies[movie]->get_no_viewer_review();

        double val = double((p1*1.0)/p2);

        cout << val << " Ratings\n";
    }
};
